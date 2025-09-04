/*
 *
 *    Copyright (c) 2021-2022 Project CHIP Authors
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
 *          Provides an implementation of the DiagnosticDataProvider object
 *          for Linux platform.
 */

#include <platform/internal/CHIPDeviceLayerInternal.h>

#include <app/data-model/List.h>
#include <lib/support/CHIPMem.h>
#include <lib/support/CHIPMemString.h>
#include <lib/support/logging/CHIPLogging.h>
#include <platform/DiagnosticDataProvider.h>
#include <platform/Linux/ConnectivityUtils.h>
#include <platform/Linux/DiagnosticDataProviderImpl.h>

#include <arpa/inet.h>
#include <dirent.h>
#include <ifaddrs.h>
#include <linux/ethtool.h>
#include <linux/if_link.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <malloc.h>
#include <net/if.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

using namespace ::chip;
using namespace ::chip::app;
using namespace ::chip::TLV;
using namespace ::chip::DeviceLayer;
using namespace ::chip::DeviceLayer::Internal;
using namespace ::chip::app::Clusters::GeneralDiagnostics;

namespace {

enum class EthernetStatsCountType
{
    kEthPacketRxCount,
    kEthPacketTxCount,
    kEthTxErrCount,
    kEthCollisionCount,
    kEthOverrunCount
};

enum class WiFiStatsCountType
{
    kWiFiUnicastPacketRxCount,
    kWiFiUnicastPacketTxCount,
    kWiFiMulticastPacketRxCount,
    kWiFiMulticastPacketTxCount,
    kWiFiOverrunCount
};

} // namespace

namespace chip {
namespace DeviceLayer {

DiagnosticDataProviderImpl & DiagnosticDataProviderImpl::GetDefaultInstance()
{
    static DiagnosticDataProviderImpl sInstance;
    return sInstance;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetCurrentHeapFree(uint64_t & currentHeapFree)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetCurrentHeapUsed(uint64_t & currentHeapUsed)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetCurrentHeapHighWatermark(uint64_t & currentHeapHighWatermark)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::ResetWatermarks()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetThreadMetrics(ThreadMetrics ** threadMetricsOut)
{
        return CHIP_ERROR_NOT_IMPLEMENTED;
}

void DiagnosticDataProviderImpl::ReleaseThreadMetrics(ThreadMetrics * threadMetrics)
{
    while (threadMetrics)
    {
        ThreadMetrics * del = threadMetrics;
        threadMetrics       = threadMetrics->Next;
        delete del;
    }
}

CHIP_ERROR DiagnosticDataProviderImpl::GetRebootCount(uint16_t & rebootCount)
{
    uint32_t count = 0;

    CHIP_ERROR err = ConfigurationMgr().GetRebootCount(count);

    if (err == CHIP_NO_ERROR)
    {
        VerifyOrReturnError(count <= UINT16_MAX, CHIP_ERROR_INVALID_INTEGER_VALUE);
        rebootCount = static_cast<uint16_t>(count);
    }

    return err;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetUpTime(uint64_t & upTime)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetTotalOperationalHours(uint32_t & totalOperationalHours)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetBootReason(BootReasonType & bootReason)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetActiveHardwareFaults(GeneralFaults<kMaxHardwareFaults> & hardwareFaults)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetActiveRadioFaults(GeneralFaults<kMaxRadioFaults> & radioFaults)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetActiveNetworkFaults(GeneralFaults<kMaxNetworkFaults> & networkFaults)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetNetworkInterfaces(NetworkInterface ** netifpp)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

void DiagnosticDataProviderImpl::ReleaseNetworkInterfaces(NetworkInterface * netifp)
{
    return;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetEthPHYRate(app::Clusters::EthernetNetworkDiagnostics::PHYRateEnum & pHYRate)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetEthFullDuplex(bool & fullDuplex)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetEthTimeSinceReset(uint64_t & timeSinceReset)
{
        return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetEthPacketRxCount(uint64_t & packetRxCount)
{
        return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetEthPacketTxCount(uint64_t & packetTxCount)
{
       return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetEthTxErrCount(uint64_t & txErrCount)
{
        return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetEthCollisionCount(uint64_t & collisionCount)
{
       return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetEthOverrunCount(uint64_t & overrunCount)
{
       return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::ResetEthNetworkDiagnosticsCounts()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

#if CHIP_DEVICE_CONFIG_ENABLE_WIFI
CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiChannelNumber(uint16_t & channelNumber)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiRssi(int8_t & rssi)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiBeaconLostCount(uint32_t & beaconLostCount)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiCurrentMaxRate(uint64_t & currentMaxRate)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiPacketMulticastRxCount(uint32_t & packetMulticastRxCount)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiPacketMulticastTxCount(uint32_t & packetMulticastTxCount)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiPacketUnicastRxCount(uint32_t & packetUnicastRxCount)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiPacketUnicastTxCount(uint32_t & packetUnicastTxCount)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiOverrunCount(uint64_t & overrunCount)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiBeaconRxCount(uint32_t & beaconRxCount)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::ResetWiFiNetworkDiagnosticsCounts()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}
#endif // CHIP_DEVICE_CONFIG_ENABLE_WIFI

#if CHIP_DEVICE_CONFIG_ENABLE_WPA
CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiVersion(app::Clusters::WiFiNetworkDiagnostics::WiFiVersionEnum & wiFiVersion)
{
        return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiBssId(MutableByteSpan & value)
{
       return CHIP_ERROR_NOT_IMPLEMENTED;;
}

CHIP_ERROR DiagnosticDataProviderImpl::GetWiFiSecurityType(app::Clusters::WiFiNetworkDiagnostics::SecurityTypeEnum & securityType)
{
       return CHIP_ERROR_NOT_IMPLEMENTED;
}
#endif // CHIP_DEVICE_CONFIG_ENABLE_WPA

DiagnosticDataProvider & GetDiagnosticDataProviderImpl()
{
    return DiagnosticDataProviderImpl::GetDefaultInstance();
}

} // namespace DeviceLayer
} // namespace chip
