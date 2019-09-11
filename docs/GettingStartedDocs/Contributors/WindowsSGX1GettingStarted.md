# Getting Started with Open Enclave on Windows for systems with support for SGX1

## Platform requirements

Intel® X86-64bit architecture with SGX1

A version of Windows OS with native support for SGX features:
- For server: Windows Server 2016
- For client: Windows 10 64-bit version 1709 or newer
- To check your Windows version, run winver on the command line.

## Install Git and Clone the Open Enclave SDK repo

Download and install Git for Windows from [here](https://git-scm.com/download/win)

Clone the Open Enclave SDK

```powershell
git clone https://github.com/openenclave/openenclave.git
```

This creates a source tree under the directory called openenclave.

## Install project prerequisites

First, change directory into the openenclave repository:

```powershell
cd openenclave
```

To deploy all the prerequisities for building Open Enclave, you can run the following from powershell. Note that the Data Center Attestation Primitives Client is not used for attestation on systems which have support for SGX1 without support for Flexible Launch Control (FLC).

```powershell
cd scripts
.\install-windows-prereqs.ps1 -InstallPath PATH_TO_OE_REPO -LaunchConfiguration SGX1 -DCAPClientType None
```

As an example, if you cloned Open Enclave SDK repo into C:\openenclave, you would run the following:

```powershell
cd scripts
.\install-windows-prereqs.ps1 -InstallPath C:\openenclave -LaunchConfiguration SGX1 -DCAPClientType None
```

If you prefer to manually install prerequisites, please refer to this [document](WindowsManualInstallPrereqs.md).

## Building on Windows using Developer Command Prompt

1. Launch the [x64 Native Tools Command Prompt for VS 2017](
https://docs.microsoft.com/en-us/dotnet/framework/tools/developer-command-prompt-for-vs)
Normally this is accessible under the `Visual Studio 2017` folder in the Start Menu.

2. At the x64 Native Tools command prompt, use cmake and ninja to build the debug version:

   ```cmd
   cd C:\openenclave
   mkdir build\x64-Debug
   cd build\x64-Debug
   cmake -G Ninja -DBUILD_ENCLAVES=1 ..\.
   ninja
   ```

   Similarly, build the release version with:

    ```cmd
   cd C:\openenclave
   mkdir build\x64-Release
   cd build\x64-Release
   cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DBUILD_ENCLAVES=1 ..\..
   ninja
   ```

## Run unittests

After building, run all unit test cases using `ctest` to confirm the SDK is built and working as expected. In this example, we are testing the debug build.

Run the following command from the build directory:

```cmd
ctest
```

You will see test logs similar to the following:

```cmd
  Test project C:/openenclave/build/x64-Debug
        Start   1: tests/lockless_queue
  1/107 Test   #1: tests/lockless_queue ..................................   Passed    3.49 sec
        Start   2: tests/mem
  2/107 Test   #2: tests/mem .............................................   Passed    0.01 sec
  ...
  ....
100% tests passed, 0 tests failed out of 107
```

A clean pass of the above unit tests is an indication that your Open Enclave setup was successful.

You can start playing with the Open Enclave samples after following the instructions in the "Install" section below to configure samples for building,

For more information refer to the [Advanced Test Info](AdvancedTestInfo.md) document.

## Installing the SDK on local machine

To install the SDK on the local machine use the following:

```cmd
cd build\x64-Debug
ninja install
```

This installs the SDK in c:\opt\openenclave.

## Known Issues

Samples have not yet been ported to Windows.

Not all tests currently run on Windows. See tests\MakeLists.txt for a list of supported tests.
