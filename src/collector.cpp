//
// Created by win on 2022/10/31.
//

#include <cuda.h>
#include <dlfcn.h>
#include <cstring>
#include <iostream>
#include <string>

extern "C" {
void *__libc_dlsym(void *map, const char *name);
}
extern "C" {
void *__libc_dlopen_mode(const char *name, int mode);
}

#define STRINGIFY(x) #x
#define CUDA_SYMBOL_STRING(x) STRINGIFY(x)

typedef void *(*fnDlsym)(void *, const char *);

static void *real_dlsym(void *handle, const char *symbol) {
  static fnDlsym internal_dlsym =
          (fnDlsym)__libc_dlsym(__libc_dlopen_mode("libdl.so.2", RTLD_LAZY), "dlsym");
  return (*internal_dlsym)(handle, symbol);
}

void info(std::string info) {
  printf("Info: %s\n", info.c_str());
}

void fatal(std::string fatal) {
  printf("Fatal: %s\n", fatal.c_str());
  exit(-1);
}

void *dlsym(void *handle, const char *symbol) {

  if (strncmp(symbol, "cu", 2) != 0) {
    return (real_dlsym(handle, symbol));
  }

  if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDriverGetVersion)) == 0) {
    return (void *) (&cuDriverGetVersion);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuInit)) == 0) {
    return (void *) (&cuInit);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchKernel)) == 0) {
    return (void *) (&cuLaunchKernel);
  } else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAlloc)) == 0) {
    return (void *) (&cuMemAlloc);
  }

  return (real_dlsym(handle, symbol));
}


#define CU_HOOK_GENERATE_INTERCEPT(func_name, params, ...)                                  \
  CUresult CUDAAPI func_name params {                                                       \
    static void *real_func = (void *)real_dlsym(RTLD_NEXT, CUDA_SYMBOL_STRING(func_name));  \
    std::string func_name_str = std::string(CUDA_SYMBOL_STRING(func_name));                 \
    info("loaded cuda function " + func_name_str + ".");                                    \
    CUresult result = ((CUresult CUDAAPI(*) params)real_func)(__VA_ARGS__);                 \
    return (result);                                                                        \
  }

CU_HOOK_GENERATE_INTERCEPT(cuLaunchKernel, (CUfunction f, unsigned int gridDimX, unsigned int gridDimY,
             unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY,
             unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream,
             void **kernelParams, void **extra),
             f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes,
             hStream, kernelParams, extra)

CU_HOOK_GENERATE_INTERCEPT(cuDriverGetVersion, (int *driverVersion), driverVersion)

CU_HOOK_GENERATE_INTERCEPT(cuInit, (unsigned int Flags), Flags)
