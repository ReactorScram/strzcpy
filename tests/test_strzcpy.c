// SPDX-License-Identifier: GPL-2.0-only

#include <stdio.h>

#include "../src/strzcpy.h"

static void print_result(const size_t result) {
    printf("result = %zu\n", result);
}

int main(void) {
    char dst[12];
    const size_t dst_sz = sizeof(dst);
    size_t result = 0;

    // If `src` is short, we copy the whole thing

    result = strxcpy(dst, "short", dst_sz);
    if(result != 5) {
        print_result(result);
        printf("%s:%d\n", __FILE__, __LINE__);
        return 1;
    }
    if(dst[5] != '\0') {
        printf("%s:%d\n", __FILE__, __LINE__);
        return 1;
    }

    // If `src` is barely long enough, we copy it

    result = strxcpy(dst, "Hello world", dst_sz);
    if(result != 11) {
        print_result(result);
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

    result = strxcpy(dst, "Hello world!", dst_sz);
    if(result != 0) {
        print_result(result);
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
