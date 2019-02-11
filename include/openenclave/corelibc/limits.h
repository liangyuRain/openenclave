// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef _OE_LIMITS_H
#define _OE_LIMITS_H

#include <openenclave/bits/types.h>

#if defined(OE_NEED_STDC_NAMES)

#define SCHAR_MIN OE_SCHAR_MIN
#define SCHAR_MAX OE_SCHAR_MAX
#define UCHAR_MAX OE_UCHAR_MAX
#define CHAR_MIN OE_CHAR_MIN
#define CHAR_MAX OE_CHAR_MAX
#define CHAR_BIT OE_CHAR_BIT
#define SHRT_MIN OE_SHRT_MIN
#define SHRT_MAX OE_SHRT_MAX
#define USHRT_MAX OE_USHRT_MAX
#define INT_MIN OE_INT_MIN
#define INT_MAX OE_INT_MAX
#define UINT_MAX OE_UINT_MAX
#define LONG_MAX OE_LONG_MAX
#define LONG_MIN OE_LONG_MIN
#define ULONG_MAX OE_ULONG_MAX
#define LLONG_MAX OE_LLONG_MAX
#define LLONG_MIN OE_LLONG_MIN
#define ULLONG_MAX OE_ULLONG_MAX

#endif /* defined(OE_NEED_STDC_NAMES) */

#if defined(OE_REMOVE_STDC_DEFINES)

#undef SCHAR_MIN
#undef SCHAR_MAX
#undef UCHAR_MAX
#undef CHAR_MIN
#undef CHAR_MAX
#undef CHAR_BIT
#undef SHRT_MIN
#undef SHRT_MAX
#undef USHRT_MAX
#undef INT_MIN
#undef INT_MAX
#undef UINT_MAX
#undef LONG_MAX
#undef LONG_MIN
#undef ULONG_MAX
#undef LLONG_MAX
#undef LLONG_MIN
#undef ULLONG_MAX

#endif /* defined(OE_REMOVE_STDC_DEFINES) */

#endif /* _OE_LIMITS_H */
