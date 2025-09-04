/*
 *
 *    Copyright (c) 2020-2022 Project CHIP Authors
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
 *         This file implements a class for managing client application
 *         user-editable settings on Linux platform.
 *
 */

#include <errno.h>
#include <fstream>
#include <inttypes.h>
#include <libgen.h>
#include <string>
#include <unistd.h>

#include <lib/support/Base64.h>
#include <lib/support/CHIPMem.h>
#include <lib/support/CodeUtils.h>
#include <lib/support/ScopedBuffer.h>
#include <lib/support/logging/CHIPLogging.h>
#include <platform/Linux/CHIPLinuxStorage.h>
#include <platform/internal/CHIPDeviceLayerInternal.h>

namespace chip {
namespace DeviceLayer {
namespace Internal {

ChipLinuxStorage::ChipLinuxStorage()
{
    mDirty = false;
}

ChipLinuxStorage::~ChipLinuxStorage() {}

CHIP_ERROR ChipLinuxStorage::Init(const char * configFile)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::ReadValue(const char * key, bool & val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::ReadValue(const char * key, uint16_t & val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::ReadValue(const char * key, uint32_t & val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::ReadValue(const char * key, uint64_t & val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::ReadValueStr(const char * key, char * buf, size_t bufSize, size_t & outLen)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::ReadValueBin(const char * key, uint8_t * buf, size_t bufSize, size_t & outLen)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::WriteValue(const char * key, bool val)
{
    CHIP_ERROR retval = CHIP_NO_ERROR;

    if (val)
    {
        retval = WriteValue(key, static_cast<uint32_t>(1));
    }
    else
    {
        retval = WriteValue(key, static_cast<uint32_t>(0));
    }

    return retval;
}

CHIP_ERROR ChipLinuxStorage::WriteValue(const char * key, uint16_t val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::WriteValue(const char * key, uint32_t val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::WriteValue(const char * key, uint64_t val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::WriteValueStr(const char * key, const char * val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}


CHIP_ERROR ChipLinuxStorage::WriteValueBin(const char * key, const uint8_t * data, size_t dataLen)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::ClearValue(const char * key)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

CHIP_ERROR ChipLinuxStorage::ClearAll()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

bool ChipLinuxStorage::HasValue(const char * key)
{
    return false;
}

CHIP_ERROR ChipLinuxStorage::Commit()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;

}

} // namespace Internal
} // namespace DeviceLayer
} // namespace chip
