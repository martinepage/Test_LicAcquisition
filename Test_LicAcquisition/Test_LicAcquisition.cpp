// Test_LicAcquisition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
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

	struct FeatureStruct
	{
		FeatureType featureType;
		string name;
		int initialCount;
		int increment;
		int delay;
	};

private:
	string _productName;
	string _Version;
	string _DeviceID;
	list<FeatureStruct> _featureList;
	NativeExport_CppCliWrapper_LicApi *m_pLicensing = nullptr;
	ClientInputParameters *m_pClientInputParameters = nullptr;
	const LicAcquisitionFeatureStatusType *m_pFeatureListStatus = nullptr;

	
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

		idx2 = featureData.find_first_of(',', idx1);
		string delay = featureData.substr(idx1, idx2 - idx1);
		f.delay = stoi(delay);

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
				bool status = m_pLicensing->AddFeatureLicenseRequestInfo((LPCWSTR)(*itr).name.c_str(), (LPCWSTR)count_buf);
			}
			return true;
		}
		return false;
	}

	void Exec()
	{
		for (int i = 0; i <= 1000; i++)
		{
			cout << "Task Output\n";
			Sleep(1000);
		}

	}

};

int main(int argc, const char *argv[])
{
	int errCode = 0;
	DoAcquisitionRun acqRun;
	
	bool status = acqRun.ParseArguments(argc, argv);
	auto future = std::async(std::launch::async, &DoAcquisitionRun::Exec, &acqRun);
	for (int i = 0; i < 100; i++)
	{
		cout << "Main Thread\n";
		Sleep(1000);
	}
	future.get(); 
	 
	char ch;
	cin >> &ch;


}
