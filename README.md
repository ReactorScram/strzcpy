# strzcpy

strzcpy is the last word in C string handling.

```
/// strzcpy safely copies all of `src` to `dst`, or calls `exit()`.
size_t strzcpy(char *dst, const char *src, size_t dst_sz);
```

If the source is bigger than the destination, we crash the entire process.

strzcpy cannot be misused, only misunderstood.

(strfcpy and strxcpy are offered as alternatives that don't crash on error.)

## Build and test

```
sudo apt-get install cmake gcc
cmake -B build .
cmake --build build && build/strzcpy_tests
```

## Licensing and copyright

strzcpy is GPLv2-only. Any copyleft project under GPLv2, GPLv3, AGPLv3, should be compatible. The choice of GPLv2-only is intended to keep strzcpy compatible with a broad range of copyleft projects, including older projects like the Linux kernel. We are not using "or later" at this time because that would incentivize a takeover of the FSF.

There is no Contributor Licensing Agreement. You should not give other people the power to re-license your contributions.

You may only train AIs / LLMs on strzcpy if the training data, training scripts, and trained weights are released as free and open-source. This is in the spirit of "share-alike" or "copyleft" licensing.

If you want to use strzcpy for a non-copyleft project, open an issue with your business email and we can negotiate a price.

Copyright 2026 "ReactorScram".
