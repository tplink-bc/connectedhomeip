/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *          Provides an implementation of the Configuration key-value store object
 *          using IniPP on Linux platform.
 *
 */

#include <fstream>
#include <string>
#include <unistd.h>

#include <lib/support/Base64.h>
#include <lib/support/CHIPMem.h>
#include <lib/support/CodeUtils.h>
#include <lib/support/IniEscaping.h>
#include <lib/support/TemporaryFileStream.h>
#include <lib/support/logging/CHIPLogging.h>
#include <platform/OpenWRT/CHIPLinuxStorageIni.h>
#include <platform/internal/CHIPDeviceLayerInternal.h>

using namespace chip::IniEscaping;

namespace chip {
namespace DeviceLayer {
namespace Internal {

CHIP_ERROR ChipLinuxStorageIni::Init()
{
    return RemoveAll();
}

CHIP_ERROR ChipLinuxStorageIni::GetDefaultSection(std::map<std::string, std::string> & section)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorageIni::AddConfig(const std::string & configFile)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

// Updating a file atomically and durably on Linux requires:
// 1. Writing to a temporary file
// 2. Sync'ing the temp file to commit updated data
// 3. Using rename() to overwrite the existing file
CHIP_ERROR ChipLinuxStorageIni::CommitConfig(const std::string & configFile)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorageIni::GetUInt16Value(const char * key, uint16_t & val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorageIni::GetUIntValue(const char * key, uint32_t & val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorageIni::GetUInt64Value(const char * key, uint64_t & val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorageIni::GetStringValue(const char * key, char * buf, size_t bufSize, size_t & outLen)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorageIni::GetBinaryBlobDataAndLengths(const char * key,
                                                            chip::Platform::ScopedMemoryBuffer<char> & encodedData,
                                                            size_t & encodedDataLen, size_t & decodedDataLen)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorageIni::GetBinaryBlobValue(const char * key, uint8_t * decodedData, size_t bufSize, size_t & decodedDataLen)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

bool ChipLinuxStorageIni::HasValue(const char * key)
{
    return false;
}

CHIP_ERROR ChipLinuxStorageIni::AddEntry(const char * key, const char * value)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorageIni::RemoveEntry(const char * key)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorageIni::RemoveAll()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

} // namespace Internal
} // namespace DeviceLayer
} // namespace chip
