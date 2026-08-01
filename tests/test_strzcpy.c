// SPDX-License-Identifier: GPL-2.0-only

#include <stdio.h>

#include "../src/strzcpy.h"

const size_t DST_SZ = 12;

int main(void) {
    char dst[DST_SZ];
    size_t result = 0;

    // If `src` is short, we copy the whole thing

    result = strxcpy(dst, "short", DST_SZ);
    if(result != 5) {
        printf("result = %ld\n", result);
        printf("%s:%d\n", __FILE__, __LINE__);
        return 1;
    }
    if(dst[5] != '\0') {
        printf("%s:%d\n", __FILE__, __LINE__);
        return 1;
    }

    // If `src` is barely long enough, we copy it

    result = strxcpy(dst, "Hello world", DST_SZ);
    if(result != 11) {
        printf("result = %ld\n", result);
        printf("%s:%d\n", __FILE__, __LINE__);
        return 1;
    }
    if(dst[11] != '\0') {
        printf("%s:%d\n", __FILE__, __LINE__);
        return 1;
    }

    // If `src` is 1 byte too long, we zero out the first byte of `dst`,
    // preventing any partial use of `src` from leaking into other code.
    // So `dst` is always null-terminated, and `src` is never truncated,
    // though sometimes `dst` is an empty string.

    result = strxcpy(dst, "Hello world!", DST_SZ);
    if(result != 0) {
        printf("result = %ld\n", result);
        printf("%s:%d\n", __FILE__, __LINE__);
        return 1;
    }
    if(dst[0] != '\0') {
        printf("%s:%d\n", __FILE__, __LINE__);
        return 1;
    }

    printf("Remember to take your mnestics.\n");
    return 0;
}
