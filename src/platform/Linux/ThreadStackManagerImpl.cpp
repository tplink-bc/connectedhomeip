/*
 *
 *    Copyright (c) 2020-2022 Project CHIP Authors
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
#include <platform/internal/DeviceNetworkInfo.h>

#include <lib/support/CodeUtils.h>
#include <lib/support/logging/CHIPLogging.h>
#include <platform/GLibTypeDeleter.h>
#include <platform/Linuxx/NetworkCommissioningDriver.h>
#include <platform/PlatformManager.h>
#include <platform/ThreadStackManager.h>

#include <app-common/zap-generated/ids/Attributes.h>

using namespace ::chip::app;
using namespace ::chip::app::Clusters;
using namespace chip::DeviceLayer::NetworkCommissioning;

namespace chip {
namespace DeviceLayer {

ThreadStackManagerImpl ThreadStackManagerImpl::sInstance;

constexpr char ThreadStackManagerImpl::kDBusOpenThreadService[];
constexpr char ThreadStackManagerImpl::kDBusOpenThreadObjectPath[];

constexpr char ThreadStackManagerImpl::kOpenthreadDeviceRoleDisabled[];
constexpr char ThreadStackManagerImpl::kOpenthreadDeviceRoleDetached[];
constexpr char ThreadStackManagerImpl::kOpenthreadDeviceRoleChild[];
constexpr char ThreadStackManagerImpl::kOpenthreadDeviceRoleRouter[];
constexpr char ThreadStackManagerImpl::kOpenthreadDeviceRoleLeader[];

constexpr char ThreadStackManagerImpl::kPropertyDeviceRole[];

namespace {

struct SetActiveDatasetContext
{
    OpenthreadBorderRouter * proxy;
    ByteSpan netInfo;
};

CHIP_ERROR GLibMatterContextSetActiveDataset(SetActiveDatasetContext * context)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

} // namespace

ThreadStackManagerImpl::ThreadStackManagerImpl() : mAttached(false) {}

CHIP_ERROR ThreadStackManagerImpl::GLibMatterContextInitThreadStack(ThreadStackManagerImpl * self)
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ThreadStackManagerImpl::_InitThreadStack()
{
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

void ThreadStackManagerImpl::OnDbusPropertiesChanged(OpenthreadBorderRouter * proxy, GVariant * changed_properties,
                                                     const gchar * const * invalidated_properties, gpointer user_data)
{
    return;
}

void ThreadStackManagerImpl::ThreadDeviceRoleChangedHandler(const gchar * role)
{
    return;
}

void ThreadStackManagerImpl::_ProcessThreadActivity() {}

bool ThreadStackManagerImpl::_HaveRouteToAddress(const Inet::IPAddress & destAddr)
{

    return false;
}

void ThreadStackManagerImpl::_OnPlatformEvent(const ChipDeviceEvent * event)
{
    (void) event;
    // The otbr-agent processes the Thread state handling by itself so there
    // isn't much to do in the Chip stack.
}

CHIP_ERROR ThreadStackManagerImpl::_SetThreadProvision(ByteSpan netInfo)
{
    return CHIPP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ThreadStackManagerImpl::_GetThreadProvision(Thread::OperationalDataset & dataset)
{
    return CHIPP_ERROR_NOT_IMPLEMENTED;
}

bool ThreadStackManagerImpl::_IsThreadProvisioned()
{
    return false;
}

void ThreadStackManagerImpl::_ErasePersistentInfo()
{
    return;
}

bool ThreadStackManagerImpl::_IsThreadEnabled()
{
    return false;
}

bool ThreadStackManagerImpl::_IsThreadAttached() const
{
    return mAttached;
}

CHIP_ERROR ThreadStackManagerImpl::GLibMatterContextCallAttach(ThreadStackManagerImpl * self)
{
    return CHIPP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ThreadStackManagerImpl::_SetThreadEnabled(bool val)
{
    return CHIPP_ERROR_NOT_IMPLEMENTED;
}

void ThreadStackManagerImpl::_OnThreadBrAttachFinished(GObject * source_object, GAsyncResult * res, gpointer user_data)
{
    return;
}

ConnectivityManager::ThreadDeviceType ThreadStackManagerImpl::_GetThreadDeviceType()
{

    return ConnectivityManager::ThreadDeviceType::kThreadDeviceType_NotSupported;
}

CHIP_ERROR ThreadStackManagerImpl::_SetThreadDeviceType(ConnectivityManager::ThreadDeviceType deviceType)
{
    return CHIPP_ERROR_NOT_IMPLEMENTED;
}

#if CHIP_CONFIG_ENABLE_ICD_SERVER
CHIP_ERROR ThreadStackManagerImpl::_SetPollingInterval(System::Clock::Milliseconds32 pollingInterval)
{
    (void) pollingInterval;
    ChipLogError(DeviceLayer, "Set ICD Polling on linux");
    return CHIP_ERROR_NOT_IMPLEMENTED;
}
#endif /* CHIP_CONFIG_ENABLE_ICD_SERVER */

bool ThreadStackManagerImpl::_HaveMeshConnectivity()
{
    // TODO: Remove Weave legacy APIs
    // For a leader with a child, the child is considered to have mesh connectivity
    // and the leader is not, which is a very confusing definition.
    // This API is Weave legacy and should be removed.

    ChipLogError(DeviceLayer, "HaveMeshConnectivity has confusing behavior and shouldn't be called");
    return false;
}

CHIP_ERROR ThreadStackManagerImpl::_GetAndLogThreadStatsCounters()
{
    // TODO: Remove Weave legacy APIs
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ThreadStackManagerImpl::_GetAndLogThreadTopologyMinimal()
{
    // TODO: Remove Weave legacy APIs
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ThreadStackManagerImpl::_GetAndLogThreadTopologyFull()
{
    // TODO: Remove Weave legacy APIs
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ThreadStackManagerImpl::_GetPrimary802154MACAddress(uint8_t * buf)
{
    return CHIPP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ThreadStackManagerImpl::_GetExternalIPv6Address(chip::Inet::IPAddress & addr)
{
    // TODO: Remove Weave legacy APIs
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ThreadStackManagerImpl::_GetThreadVersion(uint16_t & version)
{
    // TODO https://github.com/project-chip/connectedhomeip/issues/30602
    // Needs to be implemented with DBUS io.openthread.BorderRouter Thread API
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ThreadStackManagerImpl::_GetPollPeriod(uint32_t & buf)
{
    // TODO: Remove Weave legacy APIs
    return CHIP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ThreadStackManagerImpl::GLibMatterContextCallScan(ThreadStackManagerImpl * self)
{
    return CHIPP_ERROR_NOT_IMPLEMENTED;
}

CHIP_ERROR ThreadStackManagerImpl::_StartThreadScan(ThreadDriver::ScanCallback * callback)
{
    return CHIPP_ERROR_NOT_IMPLEMENTED;
}

void ThreadStackManagerImpl::_OnNetworkScanFinished(GObject * source_object, GAsyncResult * res, gpointer user_data)
{
    return;
}

void ThreadStackManagerImpl::_OnNetworkScanFinished(GAsyncResult * res)
{
    return;
}

void ThreadStackManagerImpl::_ResetThreadNetworkDiagnosticsCounts() {}

CHIP_ERROR
ThreadStackManagerImpl::_AttachToThreadNetwork(const Thread::OperationalDataset & dataset,
                                               NetworkCommissioning::Internal::WirelessDriver::ConnectCallback * callback)
{
    return CHIPP_ERROR_NOT_IMPLEMENTED;
}

void ThreadStackManagerImpl::_UpdateNetworkStatus()
{
    return;
}

ThreadStackManager & ThreadStackMgr()
{
    return chip::DeviceLayer::ThreadStackManagerImpl::sInstance;
}

ThreadStackManagerImpl & ThreadStackMgrImpl()
{
    return chip::DeviceLayer::ThreadStackManagerImpl::sInstance;
}

} // namespace DeviceLayer
} // namespace chip
