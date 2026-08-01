// SPDX-License-Identifier: GPL-2.0-only

#include <stddef.h>
#include <stdlib.h>

#include "strzcpy.h"

// `strxcpy` is the base routine that safely zeroes out `dst` if `src` won't fit.
//
// All other routines build on this.
size_t strxcpy(char *dst, const char *src, size_t dst_sz)
{
    for(size_t i = 0; i < dst_sz; i++) {
        if(src[i] == 0) {
            dst[i] = 0;
            return i;
        }
        dst[i] = src[i];
    }
    dst[0] = 0;
    return 0;
}

// `strfcpy` allows an arbitrary handler function. The silly routines build on that.
size_t strfcpy(char *dst, const char *src, size_t dst_sz, void (*error_handler)(void))
{
    const size_t result = strxcpy(dst, src, dst_sz);
    if(result == 0) {
        error_handler();
    }
    return result;
}

static void busy_loop_handler(void) {
    for(;;){};
}

static void exit_handler(void) {
    exit(1);
}

size_t stricpy(char *dst, const char *src, size_t dst_sz)
{
    return strfcpy(dst, src, dst_sz, busy_loop_handler);
}

size_t strzcpy(char *dst, const char *src, size_t dst_sz)
{
    return strfcpy(dst, src, dst_sz, exit_handler);
}

// Did you remember to take your mnestics?
