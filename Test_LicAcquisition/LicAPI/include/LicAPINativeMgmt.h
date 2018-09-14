// ------------------------------------------------------------------------------------------------------------
// <copyright company="Schneider Electric Software, LLC" file="LicAPINativeMgmt.h">
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
#ifndef LICAPINATIVEMGMT_H
#define LICAPINATIVEMGMT_H
#pragma once
#include <string>

//----------------------------------------------------------------------------------------------
// Structure   : URIParams
// Extends : none
//
// 4-byte structure packing for all consumers.
// std::wstring ProductName: Product name.
// std::wstring connectionLicenseId: Feature Name.
// std::wstring version: version.
// std::wstring serverName: Server Name.
// std::wstring portNumber: Port Number.
//----------------------------------------------------------------------------------------------
#pragma pack( push, 4 )
struct URIParams
{
    std::wstring productName;
    std::wstring connectionLicenseId;
    std::wstring version;
    std::wstring serverName;
    std::wstring portNumber;
};

//-----------------------------------------------------------------------------------
// Class   : LicAPINativeMgmt
// Extends : none
//
// This class represents the common licensing subsystem and is exported
// by LICAPINATIVEMANAGEMENT_EXPORTS.
// Consumers have to import this in to their projects to communicate with
// Licensing sub system.
//
// This class encapsulates REST interface of common licensisng.
//------------------------------------------------------------------------------------
// Common licensing module exports this class
#ifdef LICAPINATIVEMANAGEMENT_EXPORTS
class _declspec(dllexport) LicAPINativeMgmt{
#else
// Consumers of class must import
class _declspec(dllimport) LicAPINativeMgmt{
#endif

public:
    /// <summary>
    /// Gets server name, port number and serverId.
    /// </summary>
    /// <param name="prmHostName">Primary Host Name</param>
    /// <param name="prmServerId">Primary Host Id</param>
    /// <param name="bkpHostName">BackUp Host Name</param>
    /// <param name="bkpServerId">BackUp Server ID</param>
    /// <param name="portNumber">Port Number</param>
    /// <returns>1 if successful otherwise -1 and sets error code</returns>
    static int GetLicenseServerConfiguration(std::wstring& prmHostName, std::wstring& prmHostId, std::wstring& bkpHostName, std::wstring& bkpHostId, std::wstring& portNumber);
    /// <summary>
    /// Sets desired server name, port number and serverId.
    /// </summary>
    /// <param name="prmHostName">Primary Host Name </param>
    /// <param name="prmServerId">Primary Host Id</param>
    /// <param name="bkpHostName">BackUp Host Name</param>
    /// <param name="bkpServerId">BackUp Host Id</param>
    /// <param name="portNumber">Port Number</param>
    /// <returns>1 if successful otherwise -1 and sets error code</returns>
    static int SetLicenseServerConfiguration(const std::wstring& prmHostName, const std::wstring& prmHostId, const std::wstring& bkpHostName, const std::wstring& bkpHostId, const std::wstring& portNumber);
    /// <summary>
    /// Gets total license count.
    /// </summary>
    /// <param name="URIParams">URI parameters </param>
    /// <param name="componentName">Feature Name</param>
    /// <returns>total license count for a product for a specific version is successful, otherwise -1 and sets error code</returns>
    /// <remarks>when no server name or port number provided, configured primary/backup server name and port number would be tried to fetch count value</remarks>
    static long GetTotalLicenseCount(const URIParams& uriParams, std::wstring& componentName);
    /// <summary>
    /// Gets in use license count.
    /// </summary>
    /// <param name="URIParams">URI parameters </param>
    /// <param name="componentName">Feature Name</param>
    /// <returns>total in use license count for a product for a specific version if successful, otherwise -1 and sets error code</returns>
    /// <remarks>when no server name or port number provided, configured primary/backup server name and port number would be tried to fetch count value</remarks>
    static long GetInUseLicenseCount(const URIParams& uriParams, std::wstring& componentName);
    /// <summary>
    /// Gets last error code.
    /// </summary>
    /// <returns>last occured error code</returns>
    static int GetLastError();
    // Defaults
    LicAPINativeMgmt() = delete;
    LicAPINativeMgmt(const LicAPINativeMgmt&) = delete;
    LicAPINativeMgmt(const LicAPINativeMgmt&&) = delete;
    LicAPINativeMgmt(const LicAPINativeMgmt*) = delete;
    LicAPINativeMgmt& operator=(const LicAPINativeMgmt&) = delete;
    LicAPINativeMgmt& operator=(const LicAPINativeMgmt&&) = delete;
    LicAPINativeMgmt(LicAPINativeMgmt&&) = delete;
    ~LicAPINativeMgmt() = default;
};
#pragma pack( pop )
#endif //LICAPINATIVEMGMT_H