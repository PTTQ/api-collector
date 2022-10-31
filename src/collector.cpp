//
// Created by win on 2022/10/31.
//

#include <cuda.h>
#include <dlfcn.h>
#include <unordered_map>
#include <string>
#include <iostream>

#define CU_LIB_NAME "libcuda.so"

#define STRINGI(x) #x
#define CUDA_SYMBOL_STRING(x) STRINGI(x)

void info(std::string info) {
  printf("Info: %s\n", info.c_str());
}

void fatal(std::string fatal) {
  printf("Fatal: %s\n", fatal.c_str());
  exit(-1);
}

#define CU_INTERCEPT(func_name, params, ...)                                                \
  CUresult CUDAAPI func_name params {                                                       \
    void *table = dlopen(CU_LIB_NAME, RTLD_NOW | RTLD_NODELETE);                            \
    if (table == nullptr) {                                                                 \
      fatal("failed to open cuda library table.");                                          \
    }                                                                                       \
    info("opened cuda library table.");                                                     \
                                                                                            \
    std::string func_name_str = std::string(CUDA_SYMBOL_STRING(func_name));                 \
    void *func_ptr = dlsym(table, func_name_str.c_str());                                   \
    if (func_ptr == nullptr) {                                                              \
      fatal("failed to load cuda function " + func_name_str + ".");                         \
    }                                                                                       \
    info("loaded cuda function " + func_name_str + ".");                                    \
                                                                                            \
    CUresult result = ((CUresult CUDAAPI(*) params)func_ptr)(__VA_ARGS__);                  \
    return (result);                                                                        \
  }

CU_INTERCEPT(cuLaunchKernel, (CUfunction f, unsigned int gridDimX, unsigned int gridDimY,
             unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY,
             unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream,
             void **kernelParams, void **extra),
             f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes,
             hStream, kernelParams, extra)

CU_INTERCEPT(cuDriverGetVersion, (int *driverVersion), driverVersion)

CU_INTERCEPT(cuInit, (unsigned int Flags), Flags)
