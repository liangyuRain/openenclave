// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include <openenclave/corelibc/stdio.h>
#include <openenclave/corelibc/sys/socket.h>
#include <openenclave/enclave.h>
#include <openenclave/internal/tests.h>
#include "../client.h"
#include "../server.h"

static void _init(void)
{
    static bool _initialized = false;

    if (!_initialized)
    {
        OE_TEST(oe_load_module_host_socket_interface() == OE_OK);
        _initialized = true;
    }
}

extern "C" void run_enclave_server(uint16_t port, size_t num_clients)
{
    _init();
    run_server(port, num_clients);
}

extern "C" void run_enclave_client(uint16_t port)
{
    _init();
    run_client(port);
}

OE_SET_ENCLAVE_SGX(
    1,    /* ProductID */
    1,    /* SecurityVersion */
    true, /* AllowDebug */
    1024, /* HeapPageCount */
    1024, /* StackPageCount */
    32);  /* TCSCount */
