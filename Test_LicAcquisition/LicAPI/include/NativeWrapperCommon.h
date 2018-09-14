// ------------------------------------------------------------------------------------------------------------
// <copyright company="Schneider Electric Software, LLC" file="NativeWrapperCommon.h">
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
#ifndef NATIVEWRAPPERCOMMON_H
#define NATIVEWRAPPERCOMMON_H
#pragma once
#include <windows.h>

//----------------------------------------------------------------------------------------------
// Default buffers
//----------------------------------------------------------------------------------------------
const size_t FEATURE_LENGTH = 256;
const size_t MESSAGE_LENGTH = 512;

//----------------------------------------------------------------------------------------------
// Forward declarations
//----------------------------------------------------------------------------------------------
class CliWrapper;

//----------------------------------------------------------------------------------------------
// Structure   : ClientInputParameters
// Extends : none
//
// 4-byte structure packing for all consumers.
// LPCWSTR ProductName :Product name
// LPCWSTR ProductVersion :Product version
// Consumers have to allocate memory for structure member pointers.
//----------------------------------------------------------------------------------------------
#pragma pack( push, 4 )
struct ClientInputParameters
{
    LPCWSTR ProductName;
    LPCWSTR ProductVersion;
};

//---------------------------------------------------
// Structure   : LicAcquisitionFeatureStatusType
// Extends : none
//
// This structure represents license feature status.
//---------------------------------------------------
struct LicAcquisitionFeatureStatusType
{
    wchar_t FeatureName[FEATURE_LENGTH];
    bool FeatureStatus;
};

//----------------------------------------------------
// Structure   : LicAcquisitionFeatureAvaliableStatus
// Extends : none
//
// This structure represents license avialable status.
//----------------------------------------------------
struct LicAcquisitionFeatureAvailableStatus
{
    wchar_t FeatureName[FEATURE_LENGTH];
    long long FeatureCount;
};

//-------------------------------------------------------
// Structure   : ExpirationDateTime
// Extends : none
//
// This structure represents license expiration datetime.
//-------------------------------------------------------
struct LicExpirationDateTime
{
    int Year;
    int Month;
    int Day;
    int Hour;
    int Minute;
    int Second;
    long long Ticks;
};

//------------------------------------------------------
// Structure   : LicAcquisitionExpirationDetails
// Extends : none
//
// This structure represents license expiration details.
//------------------------------------------------------
struct LicAcquisitionExpirationDetails
{
    wchar_t ComponentName[MESSAGE_LENGTH];
    LicExpirationDateTime ExpirationDateTime;
    bool IsPermanent;
};

//-------------------------------------------------------------------------------------------------
// Structure   : LicAcquisitionExpirationStatus
// Extends : none
//
// This structure represents license expiration status.
// Possible status: NotOK, OK, Expired.
//--------------------------------------------------------------------------------------------------
struct LicAcquisitionExpirationStatus
{
    wchar_t ComponentName[MESSAGE_LENGTH];
    wchar_t ExpirationStatus[FEATURE_LENGTH];
};

//-------------------------------------------------------------------------------------------------
// Enumeration   : LicensePropertyStatus
// Extends : none
//
// This enumeration represents license property status type.
//--------------------------------------------------------------------------------------------------
enum LicensePropertyStatus
{
    INVALID = -1,

    NO_LICENSES,

    NO_PROPLIST,

    IN_PROGRESS,

    LIST_AVAILABLE
};

//-------------------------------------------------------------------------------------------------
// Enumeration   : SELicensePropertyValuePair
// Extends : none
//
// This structure represents license property and value map.
//--------------------------------------------------------------------------------------------------
struct SELicensePropertyValuePair
{
    wchar_t Property[MESSAGE_LENGTH];
    wchar_t Value[FEATURE_LENGTH];
};
#pragma pack( pop )
#endif //NATIVEWRAPPERCOMMON_H