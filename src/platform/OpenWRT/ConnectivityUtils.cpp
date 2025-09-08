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
 *          Utilities for accessing parameters of the network interface and the wireless
 *          statistics(extracted from /proc/net/wireless) on Linux platforms.
 */

#include <platform/OpenWRT/ConnectivityUtils.h>
#include <platform/internal/CHIPDeviceLayerInternal.h>

#include <arpa/inet.h>
#include <ifaddrs.h>
#include <linux/ethtool.h>
#include <linux/if_link.h>
#include <linux/sockios.h>
#include <linux/wireless.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <lib/core/CHIPEncoding.h>
#include <lib/support/CHIPMemString.h>
#include <lib/support/CodeUtils.h>

using namespace ::chip::app::Clusters::GeneralDiagnostics;

namespace chip {
namespace DeviceLayer {
namespace Internal {

uint16_t ConnectivityUtils::Map2400MHz(const uint8_t inChannel)
{
    return 0;
}

uint16_t ConnectivityUtils::Map5000MHz(const uint8_t inChannel)
{
    uint16_t frequency = 0;

    switch (inChannel)
    {
    case 183:
        frequency = 4915;
        break;
    case 184:
        frequency = 4920;
        break;
    case 185:
        frequency = 4925;
        break;
    case 187:
        frequency = 4935;
        break;
    case 188:
        frequency = 4940;
        break;
    case 189:
        frequency = 4945;
        break;
    case 192:
        frequency = 4960;
        break;
    case 196:
        frequency = 4980;
        break;
    case 7:
        frequency = 5035;
        break;
    case 8:
        frequency = 5040;
        break;
    case 9:
        frequency = 5045;
        break;
    case 11:
        frequency = 5055;
        break;
    case 12:
        frequency = 5060;
        break;
    case 16:
        frequency = 5080;
        break;
    case 34:
        frequency = 5170;
        break;
    case 36:
        frequency = 5180;
        break;
    case 38:
        frequency = 5190;
        break;
    case 40:
        frequency = 5200;
        break;
    case 42:
        frequency = 5210;
        break;
    case 44:
        frequency = 5220;
        break;
    case 46:
        frequency = 5230;
        break;
    case 48:
        frequency = 5240;
        break;
    case 52:
        frequency = 5260;
        break;
    case 56:
        frequency = 5280;
        break;
    case 60:
        frequency = 5300;
        break;
    case 64:
        frequency = 5320;
        break;
    case 100:
        frequency = 5500;
        break;
    case 104:
        frequency = 5520;
        break;
    case 108:
        frequency = 5540;
        break;
    case 112:
        frequency = 5560;
        break;
    case 116:
        frequency = 5580;
        break;
    case 120:
        frequency = 5600;
        break;
    case 124:
        frequency = 5620;
        break;
    case 128:
        frequency = 5640;
        break;
    case 132:
        frequency = 5660;
        break;
    case 136:
        frequency = 5680;
        break;
    case 140:
        frequency = 5700;
        break;
    case 149:
        frequency = 5745;
        break;
    case 153:
        frequency = 5765;
        break;
    case 157:
        frequency = 5785;
        break;
    case 161:
        frequency = 5805;
        break;
    case 165:
        frequency = 5825;
        break;
    }

    return frequency;
}

uint16_t ConnectivityUtils::MapChannelToFrequency(const uint16_t inBand, const uint8_t inChannel)
{
    uint16_t frequency = 0;


    return frequency;
}

uint8_t ConnectivityUtils::MapFrequencyToChannel(const uint16_t frequency)
{

    return 0;
}

double ConnectivityUtils::ConvertFrequenceToFloat(const iw_freq * in)
{
    return 0;
}

InterfaceTypeEnum ConnectivityUtils::GetInterfaceConnectionType(const char * ifname)
{
    InterfaceTypeEnum ret = InterfaceTypeEnum::kUnspecified;


    return ret;
}

CHIP_ERROR ConnectivityUtils::GetInterfaceHardwareAddrs(const char * ifname, uint8_t * buf, size_t bufSize)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetInterfaceIPv4Addrs(const char * ifname, uint8_t & size, NetworkInterface * ifp)
{
   return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetInterfaceIPv6Addrs(const char * ifname, uint8_t & size, NetworkInterface * ifp)
{
   return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetWiFiInterfaceName(char * ifname, size_t bufSize)
{
   return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetWiFiParameter(int skfd,            /* Socket to the kernel */
                                               const char * ifname, /* Device name */
                                               int request,         /* WE ID */
                                               struct iwreq * pwrq) /* Fixed part of the request */
{
   return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetWiFiStats(int skfd, const char * ifname, struct iw_statistics * stats)
{
   return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetWiFiChannelNumber(const char * ifname, uint16_t & channelNumber)
{
   return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetWiFiRssi(const char * ifname, int8_t & rssi)
{
   return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetWiFiBeaconLostCount(const char * ifname, uint32_t & beaconLostCount)
{
   return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetWiFiCurrentMaxRate(const char * ifname, uint64_t & currentMaxRate)
{
   return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetEthInterfaceName(char * ifname, size_t bufSize)
{
   return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetEthPHYRate(const char * ifname, app::Clusters::EthernetNetworkDiagnostics::PHYRateEnum & pHYRate)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ConnectivityUtils::GetEthFullDuplex(const char * ifname, bool & fullDuplex)
{
   return CHIP_ERROR_NOT_IMPLEMENTED;
}

} // namespace Internal
} // namespace DeviceLayer
} // namespace chip
