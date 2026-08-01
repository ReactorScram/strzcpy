// SPDX-License-Identifier: GPL-2.0-only

#pragma once

#include <stddef.h>

/// strxcpy safely copies all of `src` to `dst`, or sets `dst` to `\0`.
///
/// Args:
/// - `dst` - A mutable char buffer
/// - `src` - A const char buffer
/// - `dst_sz` - The number of bytes in `dst`
size_t strxcpy(char *dst, const char *src, size_t dst_sz);

/// strfcpy safely copies all of `src` to `dst`, or calls a handler function
size_t strfcpy(char *dst, const char *src, size_t dst_sz, void (*error_handler)(void));

/// stricpy safely copies all of `src` to `dst`, or enters a busy loop.
///
/// (For embedded use)
size_t stricpy(char *dst, const char *src, size_t dst_sz);

/// strzcpy safely copies all of `src` to `dst`, or calls `exit()`.
size_t strzcpy(char *dst, const char *src, size_t dst_sz);
