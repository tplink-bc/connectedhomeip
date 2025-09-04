/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2018 Nest Labs, Inc.
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
 *          Provides the implementation of the Device Layer ConfigurationManager object
 *          for Linux platforms.
 */


#include <app-common/zap-generated/cluster-objects.h>
#include <ifaddrs.h>
#include <lib/core/CHIPVendorIdentifiers.hpp>
#include <lib/support/CodeUtils.h>
#include <lib/support/logging/CHIPLogging.h>
#include <netpacket/packet.h>
#include <platform/CHIPDeviceConfig.h>
#include <platform/ConfigurationManager.h>
#include <platform/DiagnosticDataProvider.h>
#include <platform/internal/GenericConfigurationManagerImpl.ipp>

#include <algorithm>

namespace chip {
namespace DeviceLayer {

using namespace ::chip::DeviceLayer::Internal;

ConfigurationManagerImpl & ConfigurationManagerImpl::GetDefaultInstance()
{
    static ConfigurationManagerImpl sInstance;
    return sInstance;
}

CHIP_ERROR ConfigurationManagerImpl::Init()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::GetPrimaryWiFiMACAddress(uint8_t * buf)
{
 return CHIP_ERROR_NOT_IMPLEMENTED;
}

bool ConfigurationManagerImpl::CanFactoryReset()
{
    return false;
}

void ConfigurationManagerImpl::InitiateFactoryReset()
{
    return;
}

CHIP_ERROR ConfigurationManagerImpl::ReadPersistedStorageValue(::chip::Platform::PersistedStorage::Key key, uint32_t & value)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::WritePersistedStorageValue(::chip::Platform::PersistedStorage::Key key, uint32_t value)
{
     return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::ReadConfigValue(Key key, bool & val)
{
     return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::ReadConfigValue(Key key, uint16_t & val)
{
     return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::ReadConfigValue(Key key, uint32_t & val)
{
     return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::ReadConfigValue(Key key, uint64_t & val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;;
}

CHIP_ERROR ConfigurationManagerImpl::ReadConfigValueStr(Key key, char * buf, size_t bufSize, size_t & outLen)
{
     return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::ReadConfigValueBin(Key key, uint8_t * buf, size_t bufSize, size_t & outLen)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::WriteConfigValue(Key key, bool val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::WriteConfigValue(Key key, uint16_t val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::WriteConfigValue(Key key, uint32_t val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::WriteConfigValue(Key key, uint64_t val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::WriteConfigValueStr(Key key, const char * str)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::WriteConfigValueStr(Key key, const char * str, size_t strLen)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::WriteConfigValueBin(Key key, const uint8_t * data, size_t dataLen)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

void ConfigurationManagerImpl::RunConfigUnitTest()
{
    return;
}

void ConfigurationManagerImpl::DoFactoryReset(intptr_t arg)
{
    return;
}

CHIP_ERROR ConfigurationManagerImpl::StoreVendorId(uint16_t vendorId)
{
 return CHIP_ERROR_NOT_IMPLEMENTED;}

CHIP_ERROR ConfigurationManagerImpl::StoreProductId(uint16_t productId)
{
 return CHIP_ERROR_NOT_IMPLEMENTED;}

CHIP_ERROR ConfigurationManagerImpl::GetRebootCount(uint32_t & rebootCount)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;}

CHIP_ERROR ConfigurationManagerImpl::StoreRebootCount(uint32_t rebootCount)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;}

CHIP_ERROR ConfigurationManagerImpl::GetTotalOperationalHours(uint32_t & totalOperationalHours)
{
 return CHIP_ERROR_NOT_IMPLEMENTED;}

CHIP_ERROR ConfigurationManagerImpl::StoreTotalOperationalHours(uint32_t totalOperationalHours)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}


CHIP_ERROR ConfigurationManagerImpl::GetBootReason(uint32_t & bootReason)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::StoreBootReason(uint32_t bootReason)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::GetRegulatoryLocation(uint8_t & location)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::GetLocationCapability(uint8_t & location)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::GetConfigurationVersion(uint32_t & configurationVersion)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConfigurationManagerImpl::StoreConfigurationVersion(uint32_t configurationVersion)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

ConfigurationManager & ConfigurationMgrImpl()
{
    return ConfigurationManagerImpl::GetDefaultInstance();
}

} // namespace DeviceLayer
} // namespace chip
