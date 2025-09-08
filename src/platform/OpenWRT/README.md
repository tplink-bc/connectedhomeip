# Overview of CHIP OpenWRT Adaption

The following is a quick overview of the OpenWRT adaptation of CHIP. Most of this
code will have parallels in any new adaptation.

(All file names are relative to `connectedhomeip/src/platform/OpenWRT...`).

`PlatformManagerImpl.h`<br>`PlatformManagerImpl.cpp`

-   Concrete implementation of PlatformManager interface
-   Provides initialization of the CHIP stack and core event loop for the chip
    task
-   Relies on GenericPlatformManagerImpl_POSIX<> class to provide most of the
    implementation

`ConfigurationManagerImpl.h`<br>`ConfigurationManagerImpl.cpp`

-   Concrete implementation of ConfigurationManager interface
-   Manages storage and retrieval of persistent configuration data
-   Relies on GenericConfigurationManagerImpl<> classes to implement most API
    functionality
-   Delegates low-level reading and writing of persistent values to PosixConfig
    class

`ConnectivityManagerImpl.h`<br>`/ConnectivityManagerImpl.cpp`

-   Concrete implementation of ConnectivityManager interface
-   Provides high-level APIs for managing device connectivity
-   Relies on various generic implementation classes to provide API
    functionality

`ThreadStackManagerImpl.h`<br>'ThreadStackManagerImpl.cpp`

-   Concrete implementation of ThreadStackManager interface
-   Supports Thread stack initialization and core event loop processing
-   Relies on GenericThreadStackManagerImpl_OpenThread/POSIX<> classes to
    implement most API functionality

`BLEManagerImpl.h`<br>`BLEManagerImpl.cpp`

-   Concrete implementation of the BLEManager interface
-   Maps CHIP's BLE interface abstractions (BleLayer, BlePlatformDelegate,
    BleApplicationDelegate) onto the platform's native BLE services
-   Implements chip-compatible BLE advertising.


`PosixConfig.cpp`

-   Implements low-level read/write of persistent configuration values
-   Class API specifically designed to work in conjunction with the
    GenericConfigurationManagerImpl<> class.
