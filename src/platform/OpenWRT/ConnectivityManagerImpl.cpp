/*
 *
 *    Copyright (c) 2020-2022 Project CHIP Authors
 *    Copyright (c) 2019 Nest Labs, Inc.
 *    Copyright (c) 2025 NXP
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

#include <platform/internal/CHIPDeviceLayerInternal.h>
#include <platform/OpenWRT/ConnectivityManagerImpl.h>
#include <platform/CommissionableDataProvider.h>
#include <platform/ConnectivityManager.h>
#include <platform/DeviceControlServer.h>
#include <platform/DeviceInstanceInfoProvider.h>
#include <platform/DiagnosticDataProvider.h>
#include <platform/OpenWRT/ConnectivityUtils.h>
#include <platform/OpenWRT/DiagnosticDataProviderImpl.h>
#include <platform/OpenWRT/NetworkCommissioningDriver.h>
#include <platform/OpenWRT/WirelessDefs.h>

#include <algorithm>
#include <cstdlib>
#include <new>
#include <string>
#include <utility>
#include <vector>

#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <lib/support/BytesToHex.h>
#include <lib/support/CHIPMemString.h>
#include <lib/support/CodeUtils.h>
#include <lib/support/logging/CHIPLogging.h>

#include <platform/internal/GenericConnectivityManagerImpl_UDP.ipp>


using namespace ::chip;
using namespace ::chip::Credentials;
using namespace ::chip::DeviceLayer;
using namespace ::chip::DeviceLayer::Internal;
using namespace ::chip::app::Clusters::GeneralDiagnostics;
using namespace ::chip::app::Clusters::WiFiNetworkDiagnostics;

using namespace ::chip::DeviceLayer::NetworkCommissioning;

namespace chip {
namespace DeviceLayer {

ConnectivityManagerImpl ConnectivityManagerImpl::sInstance;

void ConnectivityManagerImpl::UpdateEthernetNetworkingStatus()
{
    return;
}

CHIP_ERROR ConnectivityManagerImpl::_Init()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

void ConnectivityManagerImpl::_OnPlatformEvent(const ChipDeviceEvent * event)
{
    return;
}

} // namespace DeviceLayer
} // namespace chip
