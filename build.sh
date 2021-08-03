#!/bin/bash

if [[ -z "$CLANG" ]]; then
    echo "Please CLANG environment variable"
    exit 1
fi

expected_version="Android (7155654, based on r399163b1) clang version 11.0.5 (https://android.googlesource.com/toolchain/llvm-project 87f1315dfbea7c137aa2e6d362dbb457e388158d)"
version=`"$CLANG" -v |& grep "$expected_version"`

if [[ -z "$version" ]]; then
    echo "Unexpected version of clang detected"
    echo "\$CLANG -v is expected to return following string"
    echo "$expected_version"
    exit 1
fi

make all