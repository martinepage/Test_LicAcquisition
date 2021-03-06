// Test_LicAcquisition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
#include <thread>
#include <future>
#include <ppltasks.h>
#include <ppl.h>
#include <NativeExport_CppCliWrapper_LicApi.h>


using namespace std;

 class DoAcquisitionRun
{
	 enum FeatureType
	 {
		 UNCOUNTED,
		 COUNTED,
		 INDEPENDENT
	};

	 enum FeatureStatus
	 {
		 ACQUIRED, NOTACQUIRED
	 };

	struct FeatureStruct
	{
		int maxCount;
		int currentCount;
		FeatureType featureType;
		FeatureStatus featureStatus;
		string name;
		int initialCount;
		int increment;
	};

private:
	string _productName;
	string _Version;
	string _DeviceID;
	int _RequestDelay;
	list<FeatureStruct> _featureList;
	NativeExport_CppCliWrapper_LicApi *m_pLicensing = nullptr;
	ClientInputParameters *m_pClientInputParameters = nullptr;
	const LicAcquisitionFeatureStatusType *m_pFeatureListStatus = nullptr;
	const LicAcquisitionFeatureAvailableStatus *m_pFeatureAvailableStatus;

	
public:
	DoAcquisitionRun()
	{
		
	}
	
	bool ParseFeatureData(const string featureData)
	{
		int idx1 = featureData.find_first_of(':');
		FeatureStruct f;
		f.featureType = FeatureType::COUNTED;
		f.name = featureData.substr(0,idx1);

		idx1++;
		int idx2 = featureData.find_first_of(',', idx1);
		string initialCount = featureData.substr(idx1, idx2 - idx1);
		f.initialCount = stoi(initialCount);
		idx1 = idx2 + 1;

		idx2 = featureData.find_first_of(',', idx1);
		string increment = featureData.substr(idx1, idx2 - idx1);
		f.increment = stoi(increment);
		idx1 = idx2 + 1;

		_featureList.push_back(f);

		return true;
	}

	bool ParseArguments(int argc, const char *argv[])
	{
		
		bool DoneParsing = false;
		bool error = false;
		int state = 0;
		int finalstate = 8;
		int argNum = 1;

		
		while (argv[argNum])
		{
			string option;
			option = argv[argNum];

			if (option.compare("-p") == 0)
			{
				argNum++;
				_productName = argv[argNum];
				
			}
			if (option.compare("-rd") == 0)
			{
				argNum++;
				string buf = argv[argNum];
				_RequestDelay = atoi(buf.c_str());
			}
			else if (option.compare("-fc") == 0)
			{
				argNum++;
				string featureData;
				featureData = argv[argNum];
				bool status = ParseFeatureData(featureData);
			}
			else if (option.compare("-f") == 0)
			{
				argNum++;
				FeatureStruct f;
				f.featureType = FeatureType::UNCOUNTED;
				f.name = argv[argNum];
				_featureList.push_back(f);
			}
			else if (option.compare("-v") == 0)
			{
				argNum++;
				_Version = argv[argNum];
			}
			else if (option.compare("-d") == 0)
			{
				argNum++;
				_DeviceID = argv[argNum];
			}

			argNum++;
		}

		return true;
	}

	bool RegisterLicensingSubsystem()
	{
		bool bStatus = false;
		if (m_pLicensing)
		{
			bStatus = m_pLicensing->ResetLicenseRequestInfo();
		}
		else
		{
			if (m_pLicensing = new NativeExport_CppCliWrapper_LicApi())
			{
				int errCode = 0;
				if (m_pLicensing->LoadLibraries(errCode))
				{
					if (m_pLicensing->CreateClientConnection())
					{
						return true;
					}
				}
			}
			return false;
		}
		return bStatus;

	}
	bool InitializeLicenseRequest()
	{
		m_pClientInputParameters = new ClientInputParameters();
		if (m_pClientInputParameters)
		{
			//Setup product level parameters
			m_pClientInputParameters->ProductName = (LPCWSTR) _productName.c_str();
			m_pClientInputParameters->ProductVersion = (LPCWSTR)_Version.c_str();
			//Create feature list
			list<FeatureStruct>::iterator itr;
			for (itr = _featureList.begin(); itr != _featureList.end(); ++itr)
			{
				char count_buf[10];
				_itoa_s((*itr).initialCount, count_buf, 10,10);
				bool status = m_pLicensing->AddFeatureLicenseRequestInfo((LPCWSTR)(*itr).name.c_str(), (LPCWSTR)"1");
			}
			return true;
		}
		return false;
	}

	void Exec()
	{
		int maxCount = 0;
		int returnCount = 0;
		bool status = m_pLicensing->AcquireLicense(*m_pClientInputParameters, (LPCWSTR)_DeviceID.c_str(), &m_pFeatureListStatus, returnCount);
		PrintRequestedFeatures(returnCount);
		if (status)
		{
			int availableCount = 0;
			status = m_pLicensing->GetFeatureCount(*m_pClientInputParameters, &m_pFeatureAvailableStatus, availableCount);
			if (status)
			{
				UpdateFeatureMaxCount(availableCount);
				bool done = false;
				while (!done)
				{
					PrepareNextRequest();
					m_pLicensing->ResetLicenseRequestInfo();
					delete m_pClientInputParameters;
					bool status = InitializeLicenseRequest();
					if (status)
					{
						status = m_pLicensing->AcquireLicense(*m_pClientInputParameters, (LPCWSTR)_DeviceID.c_str(), &m_pFeatureListStatus, returnCount);
						SynchronizeFeatureStatus(returnCount);
						DisplayRequestedFeatures2();
						Concurrency::wait(_RequestDelay * 1000);
					}

				}
			}
		}

	}

	void DisplayRequestedFeatures2()
	{
		list<FeatureStruct>::iterator itr;
		for (itr = _featureList.begin(); itr != _featureList.end(); ++itr)
		{
			printf(" Feature Name = %s, Current Count =%d, Max Count=%d\n", (*itr).name.c_str(), (*itr).currentCount, (*itr).maxCount);
		}
	}

	void  SynchronizeFeatureStatus(int count)
	{
		for (int i = 0; i < count; i++)
		{
			const wchar_t* featurename = m_pFeatureAvailableStatus[i].FeatureName;
			list<FeatureStruct>::iterator itr;
			for (itr = _featureList.begin(); itr != _featureList.end(); ++itr)
			{
				string fname = (char *)featurename;
				if ((*itr).name.compare(fname) == 0)
				{
					(*itr).currentCount = m_pFeatureAvailableStatus[i].FeatureCount;
				}
			}
		}
	}

	void PrepareNextRequest()
	{
		list<FeatureStruct>::iterator itr;
		for (itr = _featureList.begin(); itr != _featureList.end(); ++itr)
		{
			if ((*itr).featureType == DoAcquisitionRun::FeatureType::COUNTED)
			{
				(*itr).currentCount += (*itr).increment;
			}
		}
	}

	void UpdateFeatureMaxCount(int count)
	{
		for (int i = 0; i < count; i++)
		{
			const wchar_t* featurename = m_pFeatureAvailableStatus[i].FeatureName;
			int maxcnt = m_pFeatureAvailableStatus[i].FeatureCount;
			list<FeatureStruct>::iterator itr;
			for (itr = _featureList.begin(); itr != _featureList.end(); ++itr)
			{
				string fname = (char *)featurename;
				if ((*itr).name.compare(fname) == 0)
				{
					(*itr).maxCount = maxcnt;
				}
			}
		}
	}

	void PrintRequestedFeatures(int count)
	{
		
		for (int i = 0; i < count; i++)
		{
			if (m_pFeatureListStatus[count].FeatureStatus)
				printf("Feature = %s, FeatureStatus = Acquired\n", m_pFeatureListStatus[count].FeatureName);
			else
				printf("Feature = %s, FeatureStatus = Not Acquired\n", m_pFeatureListStatus[count].FeatureName);
		}
	}

};

int main(int argc, const char *argv[])
{
	int errCode = 0;
	DoAcquisitionRun acqRun;
	
	bool status = acqRun.ParseArguments(argc, argv);
	status = acqRun.InitializeLicenseRequest();
	auto future = std::async(std::launch::async, &DoAcquisitionRun::Exec, &acqRun);
	
	future.get(); 
	 
	char ch;
	cin >> &ch;


}
