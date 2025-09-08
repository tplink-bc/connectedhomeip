/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2018 Nest Labs, Inc.
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
 *          Provides an implementation of the PlatformManager object
 *          for OpenWRT platforms.
 */

#include <platform/internal/CHIPDeviceLayerInternal.h>

#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <net/if.h>
#include <netinet/in.h>
#include <unistd.h>

#include <mutex>

#include <app-common/zap-generated/ids/Events.h>
#include <lib/support/CHIPMem.h>
#include <lib/support/logging/CHIPLogging.h>
#include <platform/DeviceControlServer.h>
#include <platform/DeviceInstanceInfoProvider.h>
#include <platform/OpenWRT/DeviceInstanceInfoProviderImpl.h>
#include <platform/OpenWRT/DiagnosticDataProviderImpl.h>
#include <platform/PlatformManager.h>
#include <platform/internal/GenericPlatformManagerImpl_POSIX.ipp>

using namespace ::chip::app::Clusters;

namespace chip {
namespace DeviceLayer {

PlatformManagerImpl PlatformManagerImpl::sInstance;

namespace {

} // namespace

CHIP_ERROR PlatformManagerImpl::_InitChipStack()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

void PlatformManagerImpl::_Shutdown()
{
    return;
}

#if CHIP_DEVICE_CONFIG_WITH_GLIB_MAIN_LOOP
void PlatformManagerImpl::_GLibMatterContextInvokeSync(LambdaBridge && bridge)
{
    return;
}
#endif // CHIP_DEVICE_CONFIG_WITH_GLIB_MAIN_LOOP

} // namespace DeviceLayer
} // namespace chip
