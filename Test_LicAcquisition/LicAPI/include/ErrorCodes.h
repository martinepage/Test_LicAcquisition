// ------------------------------------------------------------------------------------------------------------
// <copyright company="Schneider Electric Software, LLC" file="ErrorCodes.h">
//   © 2016 Schneider Electric Software, LLC. All rights reserved.
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
#ifndef LICAPINATIVEMGMTERROR_H
#define LICAPINATIVEMGMTERROR_H
//----------------------------------------------------------------------------------------------
// Error Codes
//----------------------------------------------------------------------------------------------

// No error.
const int SELIC_NOERRO = 0;

// License is not found.
const int SELIC_NO_ACQUIRED_LICENSES = 101;

// User input is invalid.
const int SELIC_FAILED_TO_ADD_INPUTS = 102;

// User input is missing.
const int SELIC_MISSING_INPUT = 103;

// Failed to get feature count.
const int SELIC_FAILED_TO_GETFEATURECOUNT = 104;

// Failed to acquire license.
const int SELIC_FAILED_TO_ACQUIRE_LICENSE = 105;

// Failed to reset features.
const int SELIC_FAILED_TO_RESET = 106;

// Failed to release license.
const int SELIC_FAILED_TO_RELEASE_LICENSE = 107;

// Release list error.
const int SELIC_RELEASE_LIST_ERROR = 108;

// Failed to get class instance.
const int SELIC_FAILED_TO_CREATE_CLASSINSTANCE = 111;

// Product name not provided.
const int SELIC_MISSING_PRODUCTNAME = 112;

// Feature name not provided.
const int SELIC_MISSING_FEATURENAME = 113;

// Feature name duplicated.
const int SELIC_DUPLICATE_FEATURENAME = 114;

//  Feature count not provided or negative count provided.
const int SELIC_FEATURE_COUNT_INVALID_OUT_OF_RANGE = 115;

// The application has not been configured to connect to a license server.
const int SELIC_LS_HOST_NOT_CONFIGURED = 116;

// Failed to create trusted storage folder.
const int SELIC_FAILED_TO_CREATE_TS = 118;

// Server has acquired a group license. Please request for independent connection license.
const int SELIC_INVALID_REQUEST_FOR_GROUP_BASED_BE = 120;

// BackEnd application is not licensed, connection license can’t be served.
const int SELIC_BACKEND_NOT_LICENSED = 121;

// User name not provided to acquire and reserve license.
// User name must be less than or equal to 254 characters.
// User name has invalid characters, User name can contain alpha numeric characters and following special characters (. @ \ -).
const int SELIC_USER_NAME_MISSING_INVALID = 122;

// Failed to connect to license server.
const int SELIC_UNABLE_TO_COMMUNICATE_TO_SERVER = 125;

// The total number of licenses and/or features available are being used. Contact your administrator for detailed license usage.
const int SELIC_INSUFFICIENT_FEATURE_COUNT = 127;

// The requested  license(s) is not available or activated on the License server configured for the application.
//Make sure the required licenses have been activated before accessing the application.
const int SELIC_LICENSE_NOT_AVAILABLE = 128;

// Failed to get license status.
const int SELIC_FAILED_TO_GETLICENSESTATUS = 130;

// Failed to get license expiry information.
const int SELIC_FAILED_TO_GETLICENSEEXPIRYINFO = 131;

// Connection type not provided.
const int SELIC_MISSING_CONNECTIONTYPE = 132;

// Product version invalid.
const int SELIC_INVALID_PRODUCTVERSION = 133;

// Internal error: Flex Net error.
const int SELIC_INTERNAL_ERROR = 134;

// Device ID format error.
// device ID can't contain any of the following characters:
// \ / : * ? " < > |
const int SELIC_BAD_DEVICE_ID = 135;

// Failed to load licensing API DLL.
const int SELIC_FAILED_TO_LOAD_DLL = 301;

// Failed to get device ID.
const int SELIC_FAILED_TO_GET_DEVICE_ID = 401;

// LIC API Management Error Codes.
/////////////////////////////////////////////////////////////////////////////////////

// Error.
const int SEMGT_ERROR = -1;

// No Error.
const int SEMGT_NOERROR = 1;

// Invalid action.
const int SEMGT_INVALID_OPERATION = 2;

// Server details not available.
const int SEMGT_SERVER_DETAILS_NOT_AVAILABLE = 3;

// Server configfile not present.
const int SEMGT_SERVER_CONFIGFILE_NOT_FOUND = 4;

// Server config retrieval failed.
const int SEMGT_SERVER_CONFIGFILE_RETRIEVAL_FAILED = 5;

// Server node already configured.
const int SEMGT_SERVERNODE_ALREADY_CONFIGURED = 6;

// Server node config update failed.
const int SEMGT_SERVERNODE_CONFIG_UPDATE_FAILED = 7;

// User input is invalid.
const int SEMGT_INVALID_INPUT = 8;

// Failed to initialize COM library.
const int SEMGT_COM_INIT_FAILED = 9;

#endif //LICAPINATIVEMGMTERROR_H