--- src/3rdparty/chromium/v8/src/codegen/arm/cpu-arm.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/v8/src/codegen/arm/cpu-arm.cc
@@ -7,6 +7,9 @@
 #ifdef __QNXNTO__
 #include <sys/mman.h>  // for cache flushing.
 #undef MAP_TYPE        // NOLINT
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <machine/sysarch.h> // for cache flushing.
 #else
 #include <sys/syscall.h>  // for cache flushing.
 #endif
@@ -25,6 +28,9 @@ V8_NOINLINE void CpuFeatures::FlushICache(void* start,
 #if !defined(USE_SIMULATOR)
 #if V8_OS_QNX
   msync(start, size, MS_SYNC | MS_INVALIDATE_ICACHE);
+#elif defined(__FreeBSD__)
+  struct arm_sync_icache_args args = { .addr = (uintptr_t)start, .len = size };
+  sysarch(ARM_SYNC_ICACHE, (void *)&args);
 #else
   register uint32_t beg asm("r0") = reinterpret_cast<uint32_t>(start);
   register uint32_t end asm("r1") = beg + size;
