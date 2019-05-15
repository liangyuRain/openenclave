// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "../edltestutils.h"

#include <openenclave/host.h>
#include <openenclave/internal/tests.h>
#include <array>
#include "all_u.h"

static uint64_t data[8] = {0x1112131415161718,
                           0x2122232425262728,
                           0x3132333435363738,
                           0x4142434445464748,
                           0x5152535455565758,
                           0x6162636465666768,
                           0x7172737475767778,
                           0x8182838485868788};

template <typename T>
std::array<T, 2> init_structs()
{
    std::array<T, 2> s = {T{7ULL, 64ULL, data}, T{3ULL, 32ULL, &data[4]}};
    OE_TEST(s[0].ptr[0] == data[0]);
    OE_TEST(s[0].ptr[7] == data[7]);
    OE_TEST(s[1].ptr[0] == data[4]);
    OE_TEST(s[1].ptr[3] == data[7]);
    return s;
}

void test_deepcopy_edl_ecalls(oe_enclave_t* enclave)
{
    {
        // NOTE: These test backwards-compatibility and so should
        // succeed without deep copy support.
        auto s = init_structs<ShallowStruct>();
        OE_TEST(deepcopy_value(enclave, s[0], data) == OE_OK);
        OE_TEST(deepcopy_shallow(enclave, &s[0], data) == OE_OK);
    }

    // TODO: These should succeed only once deep copy is enabled, so
    // for now we ignore their failures.
    fprintf(stderr, "=== test_deepcopy_edl_ecalls ignoring failures...\n");

    {
        auto s = init_structs<CountStruct>();
        OE_TEST(deepcopy_count(enclave, &s[0]) == OE_OK);
    }

    {
        auto s = init_structs<CountParamStruct>();
        OE_TEST(deepcopy_countparam(enclave, &s[0]) == OE_OK);
    }

    {
        auto s = init_structs<SizeParamStruct>();
        OE_TEST(deepcopy_sizeparam(enclave, &s[0]) == OE_OK);
    }

    {
        auto s = init_structs<CountSizeParamStruct>();
        s[0].count = 8;
        s[0].size = 4;
        OE_TEST(deepcopy_countsizeparam(enclave, &s[0]) == OE_OK);
    }

    {
        auto s = init_structs<CountParamStruct>();
        OE_TEST(deepcopy_countparamarray(enclave, s.data()) == OE_OK);
    }

    {
        auto s = init_structs<SizeParamStruct>();
        OE_TEST(deepcopy_sizeparamarray(enclave, s.data()) == OE_OK);
    }

    printf("=== test_deepcopy_edl_ecalls failures ignored!\n");
}
