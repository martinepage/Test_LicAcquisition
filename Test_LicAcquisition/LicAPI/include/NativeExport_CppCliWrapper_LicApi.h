// ------------------------------------------------------------------------------------------------------------
// <copyright company="Schneider Electric Software, LLC" file="NativeExport_CppCliWrapper_LicApi.h">
//   Copyright (C) 2016 Schneider Electric Software, LLC. All rights reserved.
//
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
// </copyright>
// <summary>
//
// </summary>
// ------------------------------------------------------------------------------------------------------------

// Unauthorized use, duplication or distribution is strictly prohibited.
/////////////////////////////////////////////////////////////////////////////////////
#ifndef NATIVE_EXPORT_CPPCLI_WRAPPER_LICAPI_H
#define NATIVE_EXPORT_CPPCLI_WRAPPER_LICAPI_H
#pragma once
#include "NativeWrapperCommon.h"
#include "ErrorCodes.h"

//-----------------------------------------------------------------------------------
// Class   : NativeExport_CppCliWrapper_LicApi
// Extends : none
//
// This class represents the common licensing subsystem and is exported
// by common licensing module.
// Consumers have to import this in to their projects to communicate with
// Licensing sub system.
//
// This class encapsulates all the server licensing capabilities of common licensisng.
//------------------------------------------------------------------------------------
// Common licensing module exports this class
#ifdef __BUILDING_COMMON_LICENSING__
class _declspec(dllexport) NativeExport_CppCliWrapper_LicApi{
#else
// Consumers of class must import
class _declspec(dllimport) NativeExport_CppCliWrapper_LicApi{
#endif

public:
    /// <summary>
    ///     Default Constructor.
    /// </summary>
    NativeExport_CppCliWrapper_LicApi();
    /// <summary>
    ///     Default destructor.
    /// </summary>
    ~NativeExport_CppCliWrapper_LicApi();
    /// <summary>
    ///     Securely loads the licensing API DLL.
    /// </summary>
    /// <param name="errorCode">
    ///     Indicates error code.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool LoadLibraries(int& errorCode);
    /// <summary>
    ///     Securely creates the client connection.
    /// </summary>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool CreateClientConnection();
    /// <summary>
    ///     Appends a License Request record to the internal license request item list.  A license request record consists of
    ///     feature name, feature count and feature version.
    /// </summary>
    /// <param name="featureName">
    ///     Name of the feature.
    /// </param>
    /// <param name="featureCount">
    ///     Count of the feature.
    /// </param>
    /// <param name="featureVersion">
    ///     Version of the feature.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool AddFeatureLicenseRequestInfo(LPCWSTR featureName, LPCWSTR featureCount, LPCWSTR featureVersion);
    /// <summary>
    ///     Appends a License Request record to the internal license request item list.  The feature version will be defaulted to the
    ///     Product Version.
    /// </summary>
    /// <param name="featureName">
    ///     Name of the feature.
    /// </param>
    /// <param name="featureCount">
    ///     Count of the feature.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool AddFeatureLicenseRequestInfo(LPCWSTR featureName, LPCWSTR featureCount);
    /// <summary>
    ///     This method attempts to acquire the license populated in the License Request list.
    /// </summary>
    /// <param name="clientInputParameters">
    ///     Product name and product version.
    /// </param>
    /// <param name="pLicAcquisitionFeatureStatusTypeList">
    ///     Pointer to features collection. This is an output collection.
    /// </param>
    /// <param name="listSize">
    ///     Indicates the size of features collection.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool AcquireLicense(ClientInputParameters clientInputParameters, const LicAcquisitionFeatureStatusType** pLicAcquisitionFeatureStatusTypeList, int& listSize);
    /// <summary>
    ///     This method attempts to acquire the license populated in the License Request list using a custom licensing binding id.
    /// </summary>
    /// <param name="clientInputParameters">
    ///     Product name and product version.
    /// </param>
    /// <param name="alternateLicenseId">
    ///     Indicates the alternate license Id to be used by SE Licensing.
    /// </param>
    /// <param name="pLicAcquisitionFeatureStatusTypeList">
    ///     Pointer to features collection. This is an output collection.
    /// </param>
    /// <param name="listSize">
    ///     Indicates the size of features collection.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool AcquireLicense(ClientInputParameters clientInputParameters, LPCWSTR alternateLicenseId, const LicAcquisitionFeatureStatusType** pLicAcquisitionFeatureStatusTypeList, int& listSize);
    /// <summary>
    ///     Appends a License release record to the internal license request item list.  The feature version numbers are defaulted to the
    ///     Product version.
    /// </summary>
    /// <param name="featureName">
    ///     Name of the feature.
    /// </param>
    /// <param name="featureCount">
    ///     Count of the feature.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool AddFeatureLicenseReleaseInfo(LPCWSTR featureName, LPCWSTR featureCount);
    /// <summary>
    ///     The FeatureLicenseReleaseInfo list is a list of items to be released immediately back to the license server pool.
    ///     This method appends a License release record to the internal license request item list.  A license release record consists of a
    ///     feature name, feature count and feature version.
    /// </summary>
    /// <param name="featureName">
    ///     Name of the feature.
    /// </param>
    /// <param name="featureCount">
    ///     Count of the feature.
    /// </param>
    /// <param name="featureVersion">
    ///     Version of the feature.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool AddFeatureLicenseReleaseInfo(LPCWSTR featureName, LPCWSTR featureCount, LPCWSTR featureVersion);
    /// <summary>
    ///     This method releases back to the license server pool any acquired server license based on AddFeatureLicenseReleaseInfo call.
    /// </summary>
    /// <param name="clientInputParameters">
    ///     Product name and product version.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool ReleaseLicense(ClientInputParameters clientInputParameters);
    /// <summary>
    ///     Gets the requested features total count.
    /// </summary>
    /// <param name="clientInputParameters">
    ///     Product name and product version.
    /// </param>
    /// <param name="pLicAcquisitionFeatureAvailableStatusList">
    ///     Pointer to features collection. This is an output collection.
    /// </param>
    /// <param name="listSize">
    ///     Indicates the size of features collection.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool GetFeatureCount(ClientInputParameters clientInputParameters, const LicAcquisitionFeatureAvailableStatus** pLicAcquisitionFeatureAvailableStatusList, int& listSize);
    /// <summary>
    ///     This method attempts to get Feature status with respect to expiration within the associated Local License server.Possible status would be NotOK, OK, Expired.
    /// </summary>
    /// <param name="pLicAcquisitionExpirationStatusList">
    ///     Pointer to features collection. This is an output collection.
    /// </param>
    /// <param name="listSize">
    ///     Indicates the size of features collection.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool GetLicenseStatus(const LicAcquisitionExpirationStatus** pLicAcquisitionExpirationStatusList, int& listSize);
    /// <summary>
    ///     This method attempts to get Feature information with respect to expiration within the associated Local License server.
    /// </summary>
    /// <param name="pLicAcquisitionExpirationDetailsList">
    ///     Pointer to features collection. This is an output collection.
    /// </param>
    /// <param name="listSize">
    ///     Indicates the size of features collection.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool GetLicenseExpirationDetails(const LicAcquisitionExpirationDetails** pLicAcquisitionExpirationDetailsList, int& listSize);
    /// <summary>
    ///     Returns License Property status.
    /// </summary>
    /// <param name="pSELicensePropertyList">
    ///     Pointer to features collection. This is an output collection.
    /// </param>
    /// <param name="listSize">
    ///     Indicates the size of features collection.
    /// </param>
    /// <param name="runAsync">
    ///     Indicates the nature of the call.By default this would be blocked call.
    /// </param>
    /// <returns>
    ///     LicensePropertyStatus.
    /// </returns>
    LicensePropertyStatus GetSELicensePropertyList(const SELicensePropertyValuePair** pSELicensePropertyList, int& listSize, bool runAsync = false);
    /// <summary>
    ///     This method releases back to the license server pool all acquired server licenses.
    /// </summary>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool ReleaseLicenseAll();
    /// <summary>
    ///     This method clears the internal license request list which is populated with by the AddLicenseRequestInfo() Method.
    ///     You may use this method when you have already performed an acquisition and you desire to create a new request.
    /// </summary>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool ResetLicenseRequestInfo();
    /// <summary>
    ///     All methods return a boolean value where True indicates successful execution and False indicates an error occurred.
    ///     This method is called after an error has been detected in a method invocation.  It returns the detailed error code that caused the error state.
    ///     This method will return either SELIC_NOERRO if there has been no error detected, or the error code of the last detected error state.
    /// </summary>
    /// <returns>
    ///     error code.
    /// </returns>
    int GetLicenseAcquisitionError();
    /// <summary>
    ///     Disposes all output collections accumulated so far.
    /// </summary>
    void Dispose();

private:
    NativeExport_CppCliWrapper_LicApi(const NativeExport_CppCliWrapper_LicApi&);
    NativeExport_CppCliWrapper_LicApi& operator=(const NativeExport_CppCliWrapper_LicApi&);
    NativeExport_CppCliWrapper_LicApi(const NativeExport_CppCliWrapper_LicApi*);
    void FreeFeatureStatusTypeBuffers();
    void FreeFeatureStatusBuffers();
    void FreeExpirationStatusBuffers();
    void FreeExpirationDetailsBuffers();
    void FreePropertiesBuffers();
    void InitializeCLIWrapper();
    CliWrapper* _cliWrapper;
    LicAcquisitionFeatureStatusType* _pLicAcquisitionFeatureStatusType;
    LicAcquisitionFeatureAvailableStatus* _pLicAcquisitionFeatureStatus;
    LicAcquisitionExpirationStatus* _pLicAcquisitionExpirationStatus;
    LicAcquisitionExpirationDetails* _pLicAcquisitionExpirationDetails;
    SELicensePropertyValuePair* _pSELicensePropertyValuePair;
    LicensePropertyStatus* _pStatus;
    int _iCurrentFetaureCount;
    int _iPrevFeatureCount;
    int _iPrevGetFeatureCount;
    int _iPrevStatusCount;
    int _iPrevExpirationCount;
    int _iPrevPropertiesCount;
    LPCWSTR _lpstrAlternateID;
    bool _bUseAlternateID;
    bool _bAlternateIDInitialized;
};
#endif //NATIVE_EXPORT_CPPCLI_WRAPPER_LICAPI_H