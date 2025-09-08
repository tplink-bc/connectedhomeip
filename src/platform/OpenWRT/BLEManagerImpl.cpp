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

/**
 *    @file
 *          Provides an implementation of the BLEManager singleton object
 *          for Linux platforms.
 */

/**
 * Note: BLEManager requires ConnectivityManager to be defined beforehand,
 *       otherwise we will face circular dependency between them. */
#include <platform/ConnectivityManager.h>

/**
 * Note: Use public include for BLEManager which includes our local
 *       platform/<PLATFORM>/BLEManagerImpl.h after defining interface class. */
#include "platform/internal/BLEManager.h"

#include <type_traits>
#include <utility>

#include <ble/Ble.h>
#include <lib/support/CHIPMemString.h>
#include <lib/support/CodeUtils.h>
#include <lib/support/SafeInt.h>
#include <platform/CHIPDeviceLayer.h>
#include <platform/CommissionableDataProvider.h>

#include "bluez/BluezEndpoint.h"

#if !CHIP_DEVICE_CONFIG_SUPPORTS_CONCURRENT_CONNECTION
#include <platform/DeviceControlServer.h>
#endif

using namespace ::nl;
using namespace ::chip::Ble;

namespace chip {
namespace DeviceLayer {
namespace Internal {

namespace {

static constexpr System::Clock::Timeout kNewConnectionScanTimeout = System::Clock::Seconds16(20);
static constexpr System::Clock::Timeout kConnectTimeout           = System::Clock::Seconds16(20);
static constexpr System::Clock::Timeout kFastAdvertiseTimeout =
    System::Clock::Milliseconds32(CHIP_DEVICE_CONFIG_BLE_ADVERTISING_INTERVAL_CHANGE_TIME);
#if CHIP_DEVICE_CONFIG_EXT_ADVERTISING
// The CHIP_DEVICE_CONFIG_BLE_EXT_ADVERTISING_INTERVAL_CHANGE_TIME_MS specifies the transition time
// starting from advertisement commencement. Since the extended advertisement timer is started after
// the fast-to-slow transition, we have to subtract the time spent in fast advertising.
static constexpr System::Clock::Timeout kSlowAdvertiseTimeout = System::Clock::Milliseconds32(
    CHIP_DEVICE_CONFIG_BLE_EXT_ADVERTISING_INTERVAL_CHANGE_TIME_MS - CHIP_DEVICE_CONFIG_BLE_ADVERTISING_INTERVAL_CHANGE_TIME);
static_assert(CHIP_DEVICE_CONFIG_BLE_EXT_ADVERTISING_INTERVAL_CHANGE_TIME_MS >=
                  CHIP_DEVICE_CONFIG_BLE_ADVERTISING_INTERVAL_CHANGE_TIME,
              "The extended advertising interval change time must be greater than the fast advertising interval change time");
#endif

} // namespace

BLEManagerImpl BLEManagerImpl::sInstance;

CHIP_ERROR BLEManagerImpl::_Init()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

void BLEManagerImpl::_Shutdown()
{
    return;
}

CHIP_ERROR BLEManagerImpl::_SetAdvertisingEnabled(bool val)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR BLEManagerImpl::_SetAdvertisingMode(BLEAdvertisingMode mode)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR BLEManagerImpl::_GetDeviceName(char * buf, size_t bufSize)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR BLEManagerImpl::_SetDeviceName(const char * deviceName)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

uint16_t BLEManagerImpl::_NumConnections()
{
    uint16_t numCons = 0;
    return numCons;
}

CHIP_ERROR BLEManagerImpl::ConfigureBle(uint32_t aAdapterId, bool aIsCentral)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

void BLEManagerImpl::_OnPlatformEvent(const ChipDeviceEvent * event)
{
    return;
}

void BLEManagerImpl::HandlePlatformSpecificBLEEvent(const ChipDeviceEvent * apEvent)
{
    return;
}

uint16_t BLEManagerImpl::GetMTU(BLE_CONNECTION_OBJECT conId) const
{
    return 0;
}

CHIP_ERROR BLEManagerImpl::SubscribeCharacteristic(BLE_CONNECTION_OBJECT conId, const ChipBleUUID * svcId,
                                                   const ChipBleUUID * charId)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR BLEManagerImpl::UnsubscribeCharacteristic(BLE_CONNECTION_OBJECT conId, const ChipBleUUID * svcId,
                                                     const ChipBleUUID * charId)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR BLEManagerImpl::CloseConnection(BLE_CONNECTION_OBJECT conId)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR BLEManagerImpl::SendIndication(BLE_CONNECTION_OBJECT conId, const ChipBleUUID * svcId, const Ble::ChipBleUUID * charId,
                                          chip::System::PacketBufferHandle pBuf)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR BLEManagerImpl::SendWriteRequest(BLE_CONNECTION_OBJECT conId, const Ble::ChipBleUUID * svcId,
                                            const Ble::ChipBleUUID * charId, chip::System::PacketBufferHandle pBuf)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

void BLEManagerImpl::HandleNewConnection(BLE_CONNECTION_OBJECT conId)
{
    if (sInstance.mIsCentral)
    {
        ChipDeviceEvent event{ .Type     = DeviceEventType::kPlatformLinuxBLECentralConnected,
                               .Platform = { .BLECentralConnected = { .mConnection = conId } } };
        PlatformMgr().PostEventOrDie(&event);
    }
}

void BLEManagerImpl::HandleConnectFailed(CHIP_ERROR error)
{
    return;
}

void BLEManagerImpl::HandleWriteComplete(BLE_CONNECTION_OBJECT conId)
{
    return;
}

void BLEManagerImpl::HandleSubscribeOpComplete(BLE_CONNECTION_OBJECT conId, bool subscribed)
{
    return;
}

void BLEManagerImpl::HandleTXCharChanged(BLE_CONNECTION_OBJECT conId, const uint8_t * value, size_t len)
{
    return;
}

void BLEManagerImpl::HandleRXCharWrite(BLE_CONNECTION_OBJECT conId, const uint8_t * value, size_t len)
{
    return;
}

void BLEManagerImpl::HandleConnectionClosed(BLE_CONNECTION_OBJECT conId)
{
    return;
}

void BLEManagerImpl::HandleTXCharCCCDWrite(BLE_CONNECTION_OBJECT conId)
{
    return;
}

void BLEManagerImpl::HandleTXComplete(BLE_CONNECTION_OBJECT conId)
{
    return;
}

void BLEManagerImpl::DriveBLEState()
{
    return;
}

void BLEManagerImpl::NotifyChipConnectionClosed(BLE_CONNECTION_OBJECT conId)
{
    return;
}

void BLEManagerImpl::CheckNonConcurrentBleClosing()
{
    return;
}

BluezAdvertisement::AdvertisingIntervals BLEManagerImpl::GetAdvertisingIntervals() const
{
    if (mFlags.Has(Flags::kFastAdvertisingEnabled))
        return { CHIP_DEVICE_CONFIG_BLE_FAST_ADVERTISING_INTERVAL_MIN, CHIP_DEVICE_CONFIG_BLE_FAST_ADVERTISING_INTERVAL_MAX };
#if CHIP_DEVICE_CONFIG_EXT_ADVERTISING
    if (mFlags.Has(Flags::kExtAdvertisingEnabled))
        return { CHIP_DEVICE_CONFIG_BLE_EXT_ADVERTISING_INTERVAL_MIN, CHIP_DEVICE_CONFIG_BLE_EXT_ADVERTISING_INTERVAL_MAX };
#endif
    return { CHIP_DEVICE_CONFIG_BLE_SLOW_ADVERTISING_INTERVAL_MIN, CHIP_DEVICE_CONFIG_BLE_SLOW_ADVERTISING_INTERVAL_MAX };
}

void BLEManagerImpl::HandleAdvertisingTimer(chip::System::Layer *, void * appState)
{
    return;
}

void BLEManagerImpl::InitiateScan(BleScanState scanType)
{
    return;
}

void BLEManagerImpl::HandleScanTimer(chip::System::Layer *, void * appState)
{
    return;
}

void BLEManagerImpl::CleanScanConfig()
{
    return;
}

void BLEManagerImpl::NewConnection(BleLayer * bleLayer, void * appState, const SetupDiscriminator & connDiscriminator)
{
    return;
}

CHIP_ERROR BLEManagerImpl::CancelConnection()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

void BLEManagerImpl::NotifyBLEAdapterAdded(unsigned int aAdapterId, const char * aAdapterAddress)
{
    return;
}

void BLEManagerImpl::NotifyBLEAdapterRemoved(unsigned int aAdapterId, const char * aAdapterAddress)
{
    return;;
}

void BLEManagerImpl::NotifyBLEPeripheralRegisterAppComplete(CHIP_ERROR error)
{
    return;
}

void BLEManagerImpl::NotifyBLEPeripheralAdvStartComplete(CHIP_ERROR error)
{
    return;
}

void BLEManagerImpl::NotifyBLEPeripheralAdvStopComplete(CHIP_ERROR error)
{
    return;
}

void BLEManagerImpl::NotifyBLEPeripheralAdvReleased()
{
    return;
}

void BLEManagerImpl::HandleConnectTimer(chip::System::Layer *, void * appState)
{
    return;
}

void BLEManagerImpl::OnScanComplete()
{
    return;
}

void BLEManagerImpl::OnScanError(CHIP_ERROR err)
{
    return;
}

} // namespace Internal
} // namespace DeviceLayer
} // namespace chip
