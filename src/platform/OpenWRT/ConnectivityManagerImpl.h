/*
 *
 *    Copyright (c) 2020-2021 Project CHIP Authors
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

#pragma once

#include <platform/ConnectivityManager.h>
#include <platform/internal/GenericConnectivityManagerImpl.h>
#include <platform/internal/GenericConnectivityManagerImpl_UDP.h>
#if INET_CONFIG_ENABLE_TCP_ENDPOINT
#include <platform/internal/GenericConnectivityManagerImpl_TCP.h>
#endif
#include <platform/internal/GenericConnectivityManagerImpl_NoBLE.h>
#include <platform/internal/GenericConnectivityManagerImpl_NoThread.h>
#include <platform/internal/GenericConnectivityManagerImpl_NoWiFi.h>


#include <platform/OpenWRT/NetworkCommissioningDriver.h>
#include <platform/NetworkCommissioning.h>
#include <vector>

#include <platform/GLibTypeDeleter.h>


namespace chip {
namespace DeviceLayer {

/**
 * Concrete implementation of the ConnectivityManager singleton object for Linux platforms.
 */
class ConnectivityManagerImpl final : public ConnectivityManager,
                                      public Internal::GenericConnectivityManagerImpl_NoBLE<ConnectivityManagerImpl>,
                                      public Internal::GenericConnectivityManagerImpl_NoThread<ConnectivityManagerImpl>,
                                      public Internal::GenericConnectivityManagerImpl_NoWiFi<ConnectivityManagerImpl>,
                                      public Internal::GenericConnectivityManagerImpl_UDP<ConnectivityManagerImpl>,
                                      public Internal::GenericConnectivityManagerImpl<ConnectivityManagerImpl>,
#if INET_CONFIG_ENABLE_TCP_ENDPOINT
                                      public Internal::GenericConnectivityManagerImpl_TCP<ConnectivityManagerImpl>
#endif
{
    // Allow the ConnectivityManager interface class to delegate method calls to
    // the implementation methods provided by this class.
    friend class ConnectivityManager;

public:
    const char * GetEthernetIfName() { return (mEthIfName[0] == '\0') ? nullptr : mEthIfName; }
    void UpdateEthernetNetworkingStatus();
    #if CHIP_DEVICE_CONFIG_ENABLE_WIFIPAF
    OnConnectionCompleteFunct mOnPafSubscribeComplete;
    OnConnectionErrorFunct mOnPafSubscribeError;
    WiFiPAF::WiFiPAFEndPoint mWiFiPAFEndPoint;
    void * mAppState;
    uint16_t mApFreq;
    CHIP_ERROR _WiFiPAFPublish(WiFiPAFAdvertiseParam & args);
    CHIP_ERROR _WiFiPAFCancelPublish(uint32_t PublishId);
    bool _WiFiPAFResourceAvailable() { return mPafChannelAvailable; };
    // The resource checking is needed right before sending data packets that they are initialized and connected.
    bool mPafChannelAvailable = true;

    CHIP_ERROR _WiFiPAFSubscribe(const uint16_t & connDiscriminator, void * appState, OnConnectionCompleteFunct onSuccess,
                                 OnConnectionErrorFunct onError);
    CHIP_ERROR _WiFiPAFCancelSubscribe(uint32_t SubscribeId);
    CHIP_ERROR _WiFiPAFCancelIncompleteSubscribe();
    void OnDiscoveryResult(GVariant * obj);
    void OnReplied(GVariant * obj);
    void OnNanReceive(GVariant * obj);
    void OnNanPublishTerminated(guint public_id, gchar * reason);
    void OnNanSubscribeTerminated(guint subscribe_id, gchar * reason);
    CHIP_ERROR _WiFiPAFSend(const WiFiPAF::WiFiPAFSession & TxInfo, chip::System::PacketBufferHandle && msgBuf);
    void _WiFiPafSetApFreq(const uint16_t freq) { mApFreq = freq; }
    CHIP_ERROR _WiFiPAFShutdown(uint32_t id, WiFiPAF::WiFiPafRole role);
#endif
    void
    SetNetworkStatusChangeCallback(NetworkCommissioning::Internal::BaseDriver::NetworkStatusChangeCallback * statusChangeCallback)
    {
        mpStatusChangeCallback = statusChangeCallback;
    }


private:
    // ===== Members that implement the ConnectivityManager abstract interface.

    struct WiFiNetworkScanned
    {
        // The fields matches WiFiInterfaceScanResult::Type.
        uint8_t ssid[Internal::kMaxWiFiSSIDLength];
        uint8_t ssidLen;
        uint8_t bssid[6];
        int8_t rssi;
        uint16_t frequencyBand;
        uint8_t channel;
        uint8_t security;
    };

    CHIP_ERROR _Init();
    void _OnPlatformEvent(const ChipDeviceEvent * event);

    NetworkCommissioning::Internal::BaseDriver::NetworkStatusChangeCallback * mpStatusChangeCallback = nullptr;

    // ==================== ConnectivityManager Private Methods ====================

    // ===== Members for internal use by the following friends.

    friend ConnectivityManager & ConnectivityMgr();
    friend ConnectivityManagerImpl & ConnectivityMgrImpl();

    static ConnectivityManagerImpl sInstance;

    // ===== Private members reserved for use by this class only.

    char mEthIfName[Inet::InterfaceId::kMaxIfNameLength];


    NetworkCommissioning::WiFiDriver::ScanCallback * mpScanCallback;
    NetworkCommissioning::Internal::WirelessDriver::ConnectCallback * mpConnectCallback;
};



/**
 * Returns the public interface of the ConnectivityManager singleton object.
 *
 * chip applications should use this to access features of the ConnectivityManager object
 * that are common to all platforms.
 */
inline ConnectivityManager & ConnectivityMgr()
{
    return ConnectivityManagerImpl::sInstance;
}

/**
 * Returns the platform-specific implementation of the ConnectivityManager singleton object.
 *
 * chip applications can use this to gain access to features of the ConnectivityManager
 * that are specific to the ESP32 platform.
 */
inline ConnectivityManagerImpl & ConnectivityMgrImpl()
{
    return ConnectivityManagerImpl::sInstance;
}

} // namespace DeviceLayer
} // namespace chip
