// ------------------------------------------------------------------------------------------------------------
// <copyright company="Schneider Electric Software, LLC" file="NativeExport_CppCliWrapper_LicApiClient.h">
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
#ifndef NATIVE_EXPORT_CPPCLI_WRAPPER_LICAPICLIENT_H
#define NATIVE_EXPORT_CPPCLI_WRAPPER_LICAPICLIENT_H
#pragma once
#include "NativeWrapperCommon.h"
#include "ErrorCodes.h"

//------------------------------------------------------------------------------------
// Class   : NativeExport_CppCliWrapper_LicApiClient
// Extends : none
//
// This class represents the common licensing subsystem and is exported
// by common licensing module.
// Consumers have to import this in to their projects to communicate with
// Licensing sub system.
//
// This class encapsulates all the client licensing capabilities of common licensisng.
//------------------------------------------------------------------------------------

// Common licensing module exports this class
#ifdef __BUILDING_COMMON_LICENSING__
class _declspec(dllexport) NativeExport_CppCliWrapper_LicApiClient{
#else
// Consumers of class must import
class _declspec(dllimport) NativeExport_CppCliWrapper_LicApiClient{
#endif

public:
    /// <summary>
    ///     Default Constructor.
    /// </summary>
    NativeExport_CppCliWrapper_LicApiClient();
    /// <summary>
    ///     Default Destructor.
    /// </summary>
    ~NativeExport_CppCliWrapper_LicApiClient();
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
    ///     Appends a License Request record to the internal license request item list.  A license request record consists of a
    ///     product name, product version, connectionType (i.e. read or read/write), and the id of the device making the request.
    /// </summary>
    /// <param name="productName">
    ///     Name of the product.
    /// </param>
    /// <param name="version">
    ///     Version of the product.
    /// </param>
    /// <param name="connctionType">
    ///     Type of the client connection.
    /// </param>
    /// <param name="deviceid">
    ///     Device Id to be used for licensing.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool AddLicenseRequestInfo(LPCWSTR productName, LPCWSTR version, LPCWSTR connctionType, LPCWSTR deviceid);
    /// <summary>
    ///     Appends a License Request record to the internal license request item list.  A license request record consists of a
    ///     product name, product version, connectionType (i.e. read or read/write), and the id of the device making the request.
    /// </summary>
    /// <param name="productName">
    ///     Name of the product.
    /// </param>
    /// <param name="version">
    ///     Version of the product.
    /// </param>
    /// <param name="connctionType">
    ///     Type of the client connection.
    /// </param>
    /// <param name="deviceid">
    ///     Device Id to be used for licensing.
    /// </param>
    /// <param name="userName">
    ///     User name to be used for licensing.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool AddLicenseRequestInfo(LPCWSTR productName, LPCWSTR version, LPCWSTR connctionType, LPCWSTR deviceid, LPCWSTR userName);
    /// <summary>
    ///     This method attempts to acquire the license populated in the License Request list.
    /// </summary>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool AcquireLicense();
    /// <summary>
    ///     Acquires the client license followed by reservation.
    /// </summary>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool AcquireAndReserveLicense();
    /// <summary>
    ///     This method releases back to the license server pool any acquired client license.
    /// </summary>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool ReleaseLicense();
    /// <summary>
    ///     Gets licenses status of all the acquired licenses.Possible status would be NotOK, OK, Expired.
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
    ///     Gets license expiration details of the all acquired licenses.
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
    ///     Gets the current device Id which can then be used as the device id when performing a License request.
    /// </summary>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool GetDeviceIdentity(LPCWSTR* device_id);
    /// <summary>
    ///     This will clear the internal list which is populated after  AddLicenseRequestInfo call
    /// </summary>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool ResetLicenseRequestInfo();
    /// <summary>
    ///     Adds feature license release information.
    /// </summary>
    /// <param name="device_id">
    ///     Device ID to be used.
    /// </param>
    /// <param name="device_id_Type">
    ///     Type of the device Id. By default this is of type string.
    /// </param>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool AddReleaseAllRequestInfo(LPCWSTR device_id, LPCWSTR device_id_Type = L"string");
    /// <summary>
    ///     Releases all acquired client licenses.
    /// </summary>
    /// <returns>
    ///     true, if successful, false otherwise.
    /// </returns>
    bool ReleaseAllLicenses();
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
    NativeExport_CppCliWrapper_LicApiClient(const NativeExport_CppCliWrapper_LicApiClient&);
    NativeExport_CppCliWrapper_LicApiClient& operator=(const NativeExport_CppCliWrapper_LicApiClient&);
    NativeExport_CppCliWrapper_LicApiClient(const NativeExport_CppCliWrapper_LicApiClient*);
    void FreeExpirationStatusBuffers();
    void FreeExpirationDetailsBuffers();
    void FreeDeviceID();
    void InitializeCLIWrapper();
    CliWrapper* _cliWrapper;
    LicAcquisitionExpirationDetails* _pLicAcquisitionExpirationDetails;
    LicAcquisitionExpirationStatus* _pLicAcquisitionExpirationStatus;
    int _iCurrentFetaureCount;
    int _iPrevFeatureCount;
    int _iPrevExpirationCount;
    int _iPrevStatusCount;
    LPCWSTR _pDeviceID;
};
#endif //NATIVE_EXPORT_CPPCLI_WRAPPER_LICAPICLIENT_H