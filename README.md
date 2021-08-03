# What is it
This is a code example for issue:

# How to reproduce issue on Ubuntu 20.04.2 LTS

```bash
export CLANG=<path to NDK clang binary>  #e.g. /opt/android-ndk-r22b/toolchains/llvm/prebuilt/linux-x86_64/bin/clang
chmod +x ./build.sh && ./build.sh
```

# Notes
Folder `diagnostic_info` contains following information
 - `error.log` - output of compiler on my local machine
 - `test-*` - files which clang asked to attach to bug report 