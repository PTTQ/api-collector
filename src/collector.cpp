//
// Created by win on 2022/10/31.
//

#include <cuda.h>
#include <dlfcn.h>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

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

const std::string LOG_FILE_NAME = "records";

std::unordered_map<std::string, int> table;

void writeRecord(const std::string &record) {
  table[record]++;
  std::ofstream fs;
  fs.open(LOG_FILE_NAME, std::ios::out | std::ios::app);
  if (table[record] == 1) {
    fs << record << std::endl;
  }
  else if (table[record] == 10) {
    fs << record << std::endl;
  }
  else if (table[record] == 100) {
    fs << record << std::endl;
  }
  else if (table[record] == 1000) {
    fs << record << std::endl;
  }
  else if (table[record] == 10000) {
    fs << record << std::endl;
  }
  else if (table[record] == 100000) {
    fs << record << std::endl;
  }
  else if (table[record] == 1000000) {
    fs << record << std::endl;
  }
  else if (table[record] == 10000000) {
    fs << record << std::endl;
  }
  else if (table[record] == 100000000) {
    fs << record << std::endl;
  }
  fs.close();
}

void *dlsym(void *handle, const char *symbol) {

  if (strncmp(symbol, "cu", 2) != 0) {
    return (real_dlsym(handle, symbol));
  }

  if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGetErrorString)) == 0) {
    return (void *) (&cuGetErrorString);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGetErrorName)) == 0) {
    return (void *) (&cuGetErrorName);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuInit)) == 0) {
    return (void *) (&cuInit);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDriverGetVersion)) == 0) {
    return (void *) (&cuDriverGetVersion);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGet)) == 0) {
    return (void *) (&cuDeviceGet);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetCount)) == 0) {
    return (void *) (&cuDeviceGetCount);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetName)) == 0) {
    return (void *) (&cuDeviceGetName);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetUuid)) == 0) {
    return (void *) (&cuDeviceGetUuid);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetLuid)) == 0) {
    return (void *) (&cuDeviceGetLuid);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceTotalMem)) == 0) {
    return (void *) (&cuDeviceTotalMem);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetTexture1DLinearMaxWidth)) == 0) {
    return (void *) (&cuDeviceGetTexture1DLinearMaxWidth);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetAttribute)) == 0) {
    return (void *) (&cuDeviceGetAttribute);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetNvSciSyncAttributes)) == 0) {
    return (void *) (&cuDeviceGetNvSciSyncAttributes);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetProperties)) == 0) {
    return (void *) (&cuDeviceGetProperties);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceComputeCapability)) == 0) {
    return (void *) (&cuDeviceComputeCapability);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDevicePrimaryCtxRetain)) == 0) {
    return (void *) (&cuDevicePrimaryCtxRetain);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDevicePrimaryCtxRelease)) == 0) {
    return (void *) (&cuDevicePrimaryCtxRelease);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDevicePrimaryCtxSetFlags)) == 0) {
    return (void *) (&cuDevicePrimaryCtxSetFlags);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDevicePrimaryCtxGetState)) == 0) {
    return (void *) (&cuDevicePrimaryCtxGetState);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDevicePrimaryCtxReset)) == 0) {
    return (void *) (&cuDevicePrimaryCtxReset);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxCreate)) == 0) {
    return (void *) (&cuCtxCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxDestroy)) == 0) {
    return (void *) (&cuCtxDestroy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxPushCurrent)) == 0) {
    return (void *) (&cuCtxPushCurrent);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxPopCurrent)) == 0) {
    return (void *) (&cuCtxPopCurrent);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxSetCurrent)) == 0) {
    return (void *) (&cuCtxSetCurrent);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetCurrent)) == 0) {
    return (void *) (&cuCtxGetCurrent);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetDevice)) == 0) {
    return (void *) (&cuCtxGetDevice);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetFlags)) == 0) {
    return (void *) (&cuCtxGetFlags);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxSynchronize)) == 0) {
    return (void *) (&cuCtxSynchronize);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxSetLimit)) == 0) {
    return (void *) (&cuCtxSetLimit);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetLimit)) == 0) {
    return (void *) (&cuCtxGetLimit);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetCacheConfig)) == 0) {
    return (void *) (&cuCtxGetCacheConfig);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxSetCacheConfig)) == 0) {
    return (void *) (&cuCtxSetCacheConfig);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetSharedMemConfig)) == 0) {
    return (void *) (&cuCtxGetSharedMemConfig);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxSetSharedMemConfig)) == 0) {
    return (void *) (&cuCtxSetSharedMemConfig);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetApiVersion)) == 0) {
    return (void *) (&cuCtxGetApiVersion);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxGetStreamPriorityRange)) == 0) {
    return (void *) (&cuCtxGetStreamPriorityRange);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxResetPersistingL2Cache)) == 0) {
    return (void *) (&cuCtxResetPersistingL2Cache);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxAttach)) == 0) {
    return (void *) (&cuCtxAttach);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxDetach)) == 0) {
    return (void *) (&cuCtxDetach);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleLoad)) == 0) {
    return (void *) (&cuModuleLoad);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleLoadData)) == 0) {
    return (void *) (&cuModuleLoadData);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleLoadDataEx)) == 0) {
    return (void *) (&cuModuleLoadDataEx);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleLoadFatBinary)) == 0) {
    return (void *) (&cuModuleLoadFatBinary);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleUnload)) == 0) {
    return (void *) (&cuModuleUnload);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleGetFunction)) == 0) {
    return (void *) (&cuModuleGetFunction);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleGetGlobal)) == 0) {
    return (void *) (&cuModuleGetGlobal);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleGetTexRef)) == 0) {
    return (void *) (&cuModuleGetTexRef);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuModuleGetSurfRef)) == 0) {
    return (void *) (&cuModuleGetSurfRef);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLinkCreate)) == 0) {
    return (void *) (&cuLinkCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLinkAddData)) == 0) {
    return (void *) (&cuLinkAddData);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLinkAddFile)) == 0) {
    return (void *) (&cuLinkAddFile);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLinkComplete)) == 0) {
    return (void *) (&cuLinkComplete);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLinkDestroy)) == 0) {
    return (void *) (&cuLinkDestroy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetInfo)) == 0) {
    return (void *) (&cuMemGetInfo);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAlloc)) == 0) {
    return (void *) (&cuMemAlloc);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAllocPitch)) == 0) {
    return (void *) (&cuMemAllocPitch);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemFree)) == 0) {
    return (void *) (&cuMemFree);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetAddressRange)) == 0) {
    return (void *) (&cuMemGetAddressRange);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAllocHost)) == 0) {
    return (void *) (&cuMemAllocHost);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemFreeHost)) == 0) {
    return (void *) (&cuMemFreeHost);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemHostAlloc)) == 0) {
    return (void *) (&cuMemHostAlloc);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemHostGetDevicePointer)) == 0) {
    return (void *) (&cuMemHostGetDevicePointer);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemHostGetFlags)) == 0) {
    return (void *) (&cuMemHostGetFlags);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAllocManaged)) == 0) {
    return (void *) (&cuMemAllocManaged);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetByPCIBusId)) == 0) {
    return (void *) (&cuDeviceGetByPCIBusId);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetPCIBusId)) == 0) {
    return (void *) (&cuDeviceGetPCIBusId);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuIpcGetEventHandle)) == 0) {
    return (void *) (&cuIpcGetEventHandle);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuIpcOpenEventHandle)) == 0) {
    return (void *) (&cuIpcOpenEventHandle);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuIpcGetMemHandle)) == 0) {
    return (void *) (&cuIpcGetMemHandle);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuIpcOpenMemHandle)) == 0) {
    return (void *) (&cuIpcOpenMemHandle);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuIpcCloseMemHandle)) == 0) {
    return (void *) (&cuIpcCloseMemHandle);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemHostRegister)) == 0) {
    return (void *) (&cuMemHostRegister);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemHostUnregister)) == 0) {
    return (void *) (&cuMemHostUnregister);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy)) == 0) {
    return (void *) (&cuMemcpy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyPeer)) == 0) {
    return (void *) (&cuMemcpyPeer);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoD)) == 0) {
    return (void *) (&cuMemcpyHtoD);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyDtoH)) == 0) {
    return (void *) (&cuMemcpyDtoH);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyDtoD)) == 0) {
    return (void *) (&cuMemcpyDtoD);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyDtoA)) == 0) {
    return (void *) (&cuMemcpyDtoA);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoD)) == 0) {
    return (void *) (&cuMemcpyAtoD);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoA)) == 0) {
    return (void *) (&cuMemcpyHtoA);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoH)) == 0) {
    return (void *) (&cuMemcpyAtoH);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoA)) == 0) {
    return (void *) (&cuMemcpyAtoA);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy2D)) == 0) {
    return (void *) (&cuMemcpy2D);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy2DUnaligned)) == 0) {
    return (void *) (&cuMemcpy2DUnaligned);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy3D)) == 0) {
    return (void *) (&cuMemcpy3D);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy3DPeer)) == 0) {
    return (void *) (&cuMemcpy3DPeer);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAsync)) == 0) {
    return (void *) (&cuMemcpyAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyPeerAsync)) == 0) {
    return (void *) (&cuMemcpyPeerAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoDAsync)) == 0) {
    return (void *) (&cuMemcpyHtoDAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyDtoHAsync)) == 0) {
    return (void *) (&cuMemcpyDtoHAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyDtoDAsync)) == 0) {
    return (void *) (&cuMemcpyDtoDAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoAAsync)) == 0) {
    return (void *) (&cuMemcpyHtoAAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoHAsync)) == 0) {
    return (void *) (&cuMemcpyAtoHAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy2DAsync)) == 0) {
    return (void *) (&cuMemcpy2DAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy3DAsync)) == 0) {
    return (void *) (&cuMemcpy3DAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpy3DPeerAsync)) == 0) {
    return (void *) (&cuMemcpy3DPeerAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD8)) == 0) {
    return (void *) (&cuMemsetD8);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD16)) == 0) {
    return (void *) (&cuMemsetD16);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD32)) == 0) {
    return (void *) (&cuMemsetD32);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D8)) == 0) {
    return (void *) (&cuMemsetD2D8);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D16)) == 0) {
    return (void *) (&cuMemsetD2D16);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D32)) == 0) {
    return (void *) (&cuMemsetD2D32);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD8Async)) == 0) {
    return (void *) (&cuMemsetD8Async);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD16Async)) == 0) {
    return (void *) (&cuMemsetD16Async);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD32Async)) == 0) {
    return (void *) (&cuMemsetD32Async);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D8Async)) == 0) {
    return (void *) (&cuMemsetD2D8Async);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D16Async)) == 0) {
    return (void *) (&cuMemsetD2D16Async);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemsetD2D32Async)) == 0) {
    return (void *) (&cuMemsetD2D32Async);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArrayCreate)) == 0) {
    return (void *) (&cuArrayCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArrayGetDescriptor)) == 0) {
    return (void *) (&cuArrayGetDescriptor);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArrayGetSparseProperties)) == 0) {
    return (void *) (&cuArrayGetSparseProperties);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMipmappedArrayGetSparseProperties)) == 0) {
    return (void *) (&cuMipmappedArrayGetSparseProperties);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArrayDestroy)) == 0) {
    return (void *) (&cuArrayDestroy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArray3DCreate)) == 0) {
    return (void *) (&cuArray3DCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuArray3DGetDescriptor)) == 0) {
    return (void *) (&cuArray3DGetDescriptor);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMipmappedArrayCreate)) == 0) {
    return (void *) (&cuMipmappedArrayCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMipmappedArrayGetLevel)) == 0) {
    return (void *) (&cuMipmappedArrayGetLevel);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMipmappedArrayDestroy)) == 0) {
    return (void *) (&cuMipmappedArrayDestroy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAddressReserve)) == 0) {
    return (void *) (&cuMemAddressReserve);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAddressFree)) == 0) {
    return (void *) (&cuMemAddressFree);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemCreate)) == 0) {
    return (void *) (&cuMemCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemRelease)) == 0) {
    return (void *) (&cuMemRelease);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemMap)) == 0) {
    return (void *) (&cuMemMap);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemMapArrayAsync)) == 0) {
    return (void *) (&cuMemMapArrayAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemUnmap)) == 0) {
    return (void *) (&cuMemUnmap);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemSetAccess)) == 0) {
    return (void *) (&cuMemSetAccess);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetAccess)) == 0) {
    return (void *) (&cuMemGetAccess);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemExportToShareableHandle)) == 0) {
    return (void *) (&cuMemExportToShareableHandle);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemImportFromShareableHandle)) == 0) {
    return (void *) (&cuMemImportFromShareableHandle);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetAllocationGranularity)) == 0) {
    return (void *) (&cuMemGetAllocationGranularity);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetAllocationPropertiesFromHandle)) == 0) {
    return (void *) (&cuMemGetAllocationPropertiesFromHandle);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemRetainAllocationHandle)) == 0) {
    return (void *) (&cuMemRetainAllocationHandle);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuPointerGetAttribute)) == 0) {
    return (void *) (&cuPointerGetAttribute);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemPrefetchAsync)) == 0) {
    return (void *) (&cuMemPrefetchAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAdvise)) == 0) {
    return (void *) (&cuMemAdvise);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemRangeGetAttribute)) == 0) {
    return (void *) (&cuMemRangeGetAttribute);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemRangeGetAttributes)) == 0) {
    return (void *) (&cuMemRangeGetAttributes);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuPointerSetAttribute)) == 0) {
    return (void *) (&cuPointerSetAttribute);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuPointerGetAttributes)) == 0) {
    return (void *) (&cuPointerGetAttributes);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamCreate)) == 0) {
    return (void *) (&cuStreamCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamCreateWithPriority)) == 0) {
    return (void *) (&cuStreamCreateWithPriority);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamGetPriority)) == 0) {
    return (void *) (&cuStreamGetPriority);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamGetFlags)) == 0) {
    return (void *) (&cuStreamGetFlags);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamGetCtx)) == 0) {
    return (void *) (&cuStreamGetCtx);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamWaitEvent)) == 0) {
    return (void *) (&cuStreamWaitEvent);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamAddCallback)) == 0) {
    return (void *) (&cuStreamAddCallback);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamBeginCapture)) == 0) {
    return (void *) (&cuStreamBeginCapture);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuThreadExchangeStreamCaptureMode)) == 0) {
    return (void *) (&cuThreadExchangeStreamCaptureMode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamEndCapture)) == 0) {
    return (void *) (&cuStreamEndCapture);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamIsCapturing)) == 0) {
    return (void *) (&cuStreamIsCapturing);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamGetCaptureInfo)) == 0) {
    return (void *) (&cuStreamGetCaptureInfo);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamAttachMemAsync)) == 0) {
    return (void *) (&cuStreamAttachMemAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamQuery)) == 0) {
    return (void *) (&cuStreamQuery);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamSynchronize)) == 0) {
    return (void *) (&cuStreamSynchronize);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamDestroy)) == 0) {
    return (void *) (&cuStreamDestroy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamCopyAttributes)) == 0) {
    return (void *) (&cuStreamCopyAttributes);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamGetAttribute)) == 0) {
    return (void *) (&cuStreamGetAttribute);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamSetAttribute)) == 0) {
    return (void *) (&cuStreamSetAttribute);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventCreate)) == 0) {
    return (void *) (&cuEventCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventRecord)) == 0) {
    return (void *) (&cuEventRecord);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventRecordWithFlags)) == 0) {
    return (void *) (&cuEventRecordWithFlags);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventQuery)) == 0) {
    return (void *) (&cuEventQuery);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventSynchronize)) == 0) {
    return (void *) (&cuEventSynchronize);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventDestroy)) == 0) {
    return (void *) (&cuEventDestroy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuEventElapsedTime)) == 0) {
    return (void *) (&cuEventElapsedTime);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuImportExternalMemory)) == 0) {
    return (void *) (&cuImportExternalMemory);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuExternalMemoryGetMappedBuffer)) == 0) {
    return (void *) (&cuExternalMemoryGetMappedBuffer);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuExternalMemoryGetMappedMipmappedArray)) == 0) {
    return (void *) (&cuExternalMemoryGetMappedMipmappedArray);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDestroyExternalMemory)) == 0) {
    return (void *) (&cuDestroyExternalMemory);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuImportExternalSemaphore)) == 0) {
    return (void *) (&cuImportExternalSemaphore);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSignalExternalSemaphoresAsync)) == 0) {
    return (void *) (&cuSignalExternalSemaphoresAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuWaitExternalSemaphoresAsync)) == 0) {
    return (void *) (&cuWaitExternalSemaphoresAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDestroyExternalSemaphore)) == 0) {
    return (void *) (&cuDestroyExternalSemaphore);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamWaitValue32)) == 0) {
    return (void *) (&cuStreamWaitValue32);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamWaitValue64)) == 0) {
    return (void *) (&cuStreamWaitValue64);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamWriteValue32)) == 0) {
    return (void *) (&cuStreamWriteValue32);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamWriteValue64)) == 0) {
    return (void *) (&cuStreamWriteValue64);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamBatchMemOp)) == 0) {
    return (void *) (&cuStreamBatchMemOp);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncGetAttribute)) == 0) {
    return (void *) (&cuFuncGetAttribute);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncSetAttribute)) == 0) {
    return (void *) (&cuFuncSetAttribute);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncSetCacheConfig)) == 0) {
    return (void *) (&cuFuncSetCacheConfig);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncSetSharedMemConfig)) == 0) {
    return (void *) (&cuFuncSetSharedMemConfig);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchKernel)) == 0) {
    return (void *) (&cuLaunchKernel);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchCooperativeKernel)) == 0) {
    return (void *) (&cuLaunchCooperativeKernel);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchCooperativeKernelMultiDevice)) == 0) {
    return (void *) (&cuLaunchCooperativeKernelMultiDevice);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchHostFunc)) == 0) {
    return (void *) (&cuLaunchHostFunc);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncSetBlockShape)) == 0) {
    return (void *) (&cuFuncSetBlockShape);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncSetSharedSize)) == 0) {
    return (void *) (&cuFuncSetSharedSize);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuParamSetSize)) == 0) {
    return (void *) (&cuParamSetSize);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuParamSeti)) == 0) {
    return (void *) (&cuParamSeti);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuParamSetf)) == 0) {
    return (void *) (&cuParamSetf);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuParamSetv)) == 0) {
    return (void *) (&cuParamSetv);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunch)) == 0) {
    return (void *) (&cuLaunch);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchGrid)) == 0) {
    return (void *) (&cuLaunchGrid);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuLaunchGridAsync)) == 0) {
    return (void *) (&cuLaunchGridAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuParamSetTexRef)) == 0) {
    return (void *) (&cuParamSetTexRef);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphCreate)) == 0) {
    return (void *) (&cuGraphCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddKernelNode)) == 0) {
    return (void *) (&cuGraphAddKernelNode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphKernelNodeGetParams)) == 0) {
    return (void *) (&cuGraphKernelNodeGetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphKernelNodeSetParams)) == 0) {
    return (void *) (&cuGraphKernelNodeSetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddMemcpyNode)) == 0) {
    return (void *) (&cuGraphAddMemcpyNode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphMemcpyNodeGetParams)) == 0) {
    return (void *) (&cuGraphMemcpyNodeGetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphMemcpyNodeSetParams)) == 0) {
    return (void *) (&cuGraphMemcpyNodeSetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddMemsetNode)) == 0) {
    return (void *) (&cuGraphAddMemsetNode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphMemsetNodeGetParams)) == 0) {
    return (void *) (&cuGraphMemsetNodeGetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphMemsetNodeSetParams)) == 0) {
    return (void *) (&cuGraphMemsetNodeSetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddHostNode)) == 0) {
    return (void *) (&cuGraphAddHostNode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphHostNodeGetParams)) == 0) {
    return (void *) (&cuGraphHostNodeGetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphHostNodeSetParams)) == 0) {
    return (void *) (&cuGraphHostNodeSetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddChildGraphNode)) == 0) {
    return (void *) (&cuGraphAddChildGraphNode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphChildGraphNodeGetGraph)) == 0) {
    return (void *) (&cuGraphChildGraphNodeGetGraph);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddEmptyNode)) == 0) {
    return (void *) (&cuGraphAddEmptyNode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddEventRecordNode)) == 0) {
    return (void *) (&cuGraphAddEventRecordNode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphEventRecordNodeGetEvent)) == 0) {
    return (void *) (&cuGraphEventRecordNodeGetEvent);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphEventRecordNodeSetEvent)) == 0) {
    return (void *) (&cuGraphEventRecordNodeSetEvent);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddEventWaitNode)) == 0) {
    return (void *) (&cuGraphAddEventWaitNode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphEventWaitNodeGetEvent)) == 0) {
    return (void *) (&cuGraphEventWaitNodeGetEvent);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphEventWaitNodeSetEvent)) == 0) {
    return (void *) (&cuGraphEventWaitNodeSetEvent);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphClone)) == 0) {
    return (void *) (&cuGraphClone);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphNodeFindInClone)) == 0) {
    return (void *) (&cuGraphNodeFindInClone);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphNodeGetType)) == 0) {
    return (void *) (&cuGraphNodeGetType);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphGetNodes)) == 0) {
    return (void *) (&cuGraphGetNodes);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphGetRootNodes)) == 0) {
    return (void *) (&cuGraphGetRootNodes);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphGetEdges)) == 0) {
    return (void *) (&cuGraphGetEdges);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphNodeGetDependencies)) == 0) {
    return (void *) (&cuGraphNodeGetDependencies);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphNodeGetDependentNodes)) == 0) {
    return (void *) (&cuGraphNodeGetDependentNodes);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphAddDependencies)) == 0) {
    return (void *) (&cuGraphAddDependencies);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphRemoveDependencies)) == 0) {
    return (void *) (&cuGraphRemoveDependencies);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphDestroyNode)) == 0) {
    return (void *) (&cuGraphDestroyNode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphInstantiate)) == 0) {
    return (void *) (&cuGraphInstantiate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecKernelNodeSetParams)) == 0) {
    return (void *) (&cuGraphExecKernelNodeSetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecMemcpyNodeSetParams)) == 0) {
    return (void *) (&cuGraphExecMemcpyNodeSetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecMemsetNodeSetParams)) == 0) {
    return (void *) (&cuGraphExecMemsetNodeSetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecHostNodeSetParams)) == 0) {
    return (void *) (&cuGraphExecHostNodeSetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecChildGraphNodeSetParams)) == 0) {
    return (void *) (&cuGraphExecChildGraphNodeSetParams);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecEventRecordNodeSetEvent)) == 0) {
    return (void *) (&cuGraphExecEventRecordNodeSetEvent);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecEventWaitNodeSetEvent)) == 0) {
    return (void *) (&cuGraphExecEventWaitNodeSetEvent);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphUpload)) == 0) {
    return (void *) (&cuGraphUpload);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphLaunch)) == 0) {
    return (void *) (&cuGraphLaunch);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecDestroy)) == 0) {
    return (void *) (&cuGraphExecDestroy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphDestroy)) == 0) {
    return (void *) (&cuGraphDestroy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphExecUpdate)) == 0) {
    return (void *) (&cuGraphExecUpdate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphKernelNodeCopyAttributes)) == 0) {
    return (void *) (&cuGraphKernelNodeCopyAttributes);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphKernelNodeGetAttribute)) == 0) {
    return (void *) (&cuGraphKernelNodeGetAttribute);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphKernelNodeSetAttribute)) == 0) {
    return (void *) (&cuGraphKernelNodeSetAttribute);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuOccupancyMaxActiveBlocksPerMultiprocessor)) == 0) {
    return (void *) (&cuOccupancyMaxActiveBlocksPerMultiprocessor);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags)) == 0) {
    return (void *) (&cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuOccupancyMaxPotentialBlockSize)) == 0) {
    return (void *) (&cuOccupancyMaxPotentialBlockSize);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuOccupancyMaxPotentialBlockSizeWithFlags)) == 0) {
    return (void *) (&cuOccupancyMaxPotentialBlockSizeWithFlags);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuOccupancyAvailableDynamicSMemPerBlock)) == 0) {
    return (void *) (&cuOccupancyAvailableDynamicSMemPerBlock);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetArray)) == 0) {
    return (void *) (&cuTexRefSetArray);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetMipmappedArray)) == 0) {
    return (void *) (&cuTexRefSetMipmappedArray);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetAddress)) == 0) {
    return (void *) (&cuTexRefSetAddress);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetAddress2D)) == 0) {
    return (void *) (&cuTexRefSetAddress2D);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetFormat)) == 0) {
    return (void *) (&cuTexRefSetFormat);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetAddressMode)) == 0) {
    return (void *) (&cuTexRefSetAddressMode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetFilterMode)) == 0) {
    return (void *) (&cuTexRefSetFilterMode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetMipmapFilterMode)) == 0) {
    return (void *) (&cuTexRefSetMipmapFilterMode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetMipmapLevelBias)) == 0) {
    return (void *) (&cuTexRefSetMipmapLevelBias);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetMipmapLevelClamp)) == 0) {
    return (void *) (&cuTexRefSetMipmapLevelClamp);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetMaxAnisotropy)) == 0) {
    return (void *) (&cuTexRefSetMaxAnisotropy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetBorderColor)) == 0) {
    return (void *) (&cuTexRefSetBorderColor);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefSetFlags)) == 0) {
    return (void *) (&cuTexRefSetFlags);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetAddress)) == 0) {
    return (void *) (&cuTexRefGetAddress);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetArray)) == 0) {
    return (void *) (&cuTexRefGetArray);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetMipmappedArray)) == 0) {
    return (void *) (&cuTexRefGetMipmappedArray);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetAddressMode)) == 0) {
    return (void *) (&cuTexRefGetAddressMode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetFilterMode)) == 0) {
    return (void *) (&cuTexRefGetFilterMode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetFormat)) == 0) {
    return (void *) (&cuTexRefGetFormat);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetMipmapFilterMode)) == 0) {
    return (void *) (&cuTexRefGetMipmapFilterMode);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetMipmapLevelBias)) == 0) {
    return (void *) (&cuTexRefGetMipmapLevelBias);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetMipmapLevelClamp)) == 0) {
    return (void *) (&cuTexRefGetMipmapLevelClamp);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetMaxAnisotropy)) == 0) {
    return (void *) (&cuTexRefGetMaxAnisotropy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetBorderColor)) == 0) {
    return (void *) (&cuTexRefGetBorderColor);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefGetFlags)) == 0) {
    return (void *) (&cuTexRefGetFlags);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefCreate)) == 0) {
    return (void *) (&cuTexRefCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexRefDestroy)) == 0) {
    return (void *) (&cuTexRefDestroy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSurfRefSetArray)) == 0) {
    return (void *) (&cuSurfRefSetArray);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSurfRefGetArray)) == 0) {
    return (void *) (&cuSurfRefGetArray);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexObjectCreate)) == 0) {
    return (void *) (&cuTexObjectCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexObjectDestroy)) == 0) {
    return (void *) (&cuTexObjectDestroy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexObjectGetResourceDesc)) == 0) {
    return (void *) (&cuTexObjectGetResourceDesc);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexObjectGetTextureDesc)) == 0) {
    return (void *) (&cuTexObjectGetTextureDesc);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuTexObjectGetResourceViewDesc)) == 0) {
    return (void *) (&cuTexObjectGetResourceViewDesc);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSurfObjectCreate)) == 0) {
    return (void *) (&cuSurfObjectCreate);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSurfObjectDestroy)) == 0) {
    return (void *) (&cuSurfObjectDestroy);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuSurfObjectGetResourceDesc)) == 0) {
    return (void *) (&cuSurfObjectGetResourceDesc);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceCanAccessPeer)) == 0) {
    return (void *) (&cuDeviceCanAccessPeer);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxEnablePeerAccess)) == 0) {
    return (void *) (&cuCtxEnablePeerAccess);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuCtxDisablePeerAccess)) == 0) {
    return (void *) (&cuCtxDisablePeerAccess);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceGetP2PAttribute)) == 0) {
    return (void *) (&cuDeviceGetP2PAttribute);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsUnregisterResource)) == 0) {
    return (void *) (&cuGraphicsUnregisterResource);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsSubResourceGetMappedArray)) == 0) {
    return (void *) (&cuGraphicsSubResourceGetMappedArray);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsResourceGetMappedMipmappedArray)) == 0) {
    return (void *) (&cuGraphicsResourceGetMappedMipmappedArray);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsResourceGetMappedPointer)) == 0) {
    return (void *) (&cuGraphicsResourceGetMappedPointer);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsResourceSetMapFlags)) == 0) {
    return (void *) (&cuGraphicsResourceSetMapFlags);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsMapResources)) == 0) {
    return (void *) (&cuGraphicsMapResources);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGraphicsUnmapResources)) == 0) {
    return (void *) (&cuGraphicsUnmapResources);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuGetExportTable)) == 0) {
    return (void *) (&cuGetExportTable);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuFuncGetModule)) == 0) {
    return (void *) (&cuFuncGetModule);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuDeviceTotalMem)) == 0) {
    return (void *) (&cuDeviceTotalMem);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemGetInfo)) == 0) {
    return (void *) (&cuMemGetInfo);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemAllocHost)) == 0) {
    return (void *) (&cuMemAllocHost);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoA)) == 0) {
    return (void *) (&cuMemcpyHtoA);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoH)) == 0) {
    return (void *) (&cuMemcpyAtoH);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoA)) == 0) {
    return (void *) (&cuMemcpyAtoA);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyHtoAAsync)) == 0) {
    return (void *) (&cuMemcpyHtoAAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuMemcpyAtoHAsync)) == 0) {
    return (void *) (&cuMemcpyAtoHAsync);
  }
  else if (strcmp(symbol, CUDA_SYMBOL_STRING(cuStreamBeginCapture)) == 0) {
    return (void *) (&cuStreamBeginCapture);
  }

  return (real_dlsym(handle, symbol));
}


#define CU_HOOK_GENERATE_INTERCEPT(func_name, params, ...)                                  \
  CUresult CUDAAPI func_name params {                                                       \
    static void *table = dlopen("libcuda.so.1", RTLD_NOW | RTLD_NODELETE);                  \
    if (table == nullptr) {                                                                 \
      fatal("failed to load cuda table");                                                   \
    }                                                                                       \
    static void *real_func = (void *)real_dlsym(table, CUDA_SYMBOL_STRING(func_name));      \
    if (real_func == nullptr) {                                                             \
      fatal("failed to load function " + std::string(CUDA_SYMBOL_STRING(func_name)));       \
    }                                                                                       \
    writeRecord(std::string(CUDA_SYMBOL_STRING(func_name)));                                \
    CUresult result = ((CUresult CUDAAPI(*) params)real_func)(__VA_ARGS__);                 \
    return (result);                                                                        \
  }

// CUDA Driver APIs

CU_HOOK_GENERATE_INTERCEPT(cuGetErrorString, (CUresult error, const char **pStr), error, pStr)

CU_HOOK_GENERATE_INTERCEPT(cuGetErrorName, (CUresult error, const char **pStr), error, pStr)

CU_HOOK_GENERATE_INTERCEPT(cuInit, (unsigned int Flags), Flags)

CU_HOOK_GENERATE_INTERCEPT(cuDriverGetVersion, (int *driverVersion), driverVersion)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGet, (CUdevice *device, int ordinal), device, ordinal)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGetCount, (int *count), count)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGetName, (char *name, int len, CUdevice dev), name, len, dev)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGetUuid, (CUuuid *uuid, CUdevice dev), uuid, dev)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGetLuid, (char *luid, unsigned int *deviceNodeMask, CUdevice dev), luid, deviceNodeMask, dev)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceTotalMem, (size_t *bytes, CUdevice dev), bytes, dev)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGetTexture1DLinearMaxWidth, (size_t *maxWidthInElements, CUarray_format format, unsigned numChannels, CUdevice dev), maxWidthInElements, format, numChannels, dev)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGetAttribute, (int *pi, CUdevice_attribute attrib, CUdevice dev), pi, attrib, dev)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGetNvSciSyncAttributes, (void *nvSciSyncAttrList, CUdevice dev, int flags), nvSciSyncAttrList, dev, flags)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGetProperties, (CUdevprop *prop, CUdevice dev), prop, dev)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceComputeCapability, (int *major, int *minor, CUdevice dev), major, minor, dev)

CU_HOOK_GENERATE_INTERCEPT(cuDevicePrimaryCtxRetain, (CUcontext *pctx, CUdevice dev), pctx, dev)

CU_HOOK_GENERATE_INTERCEPT(cuDevicePrimaryCtxRelease, (CUdevice dev), dev)

CU_HOOK_GENERATE_INTERCEPT(cuDevicePrimaryCtxSetFlags, (CUdevice dev, unsigned int flags), dev, flags)

CU_HOOK_GENERATE_INTERCEPT(cuDevicePrimaryCtxGetState, (CUdevice dev, unsigned int *flags, int *active), dev, flags, active)

CU_HOOK_GENERATE_INTERCEPT(cuDevicePrimaryCtxReset, (CUdevice dev), dev)

CU_HOOK_GENERATE_INTERCEPT(cuCtxCreate, (CUcontext *pctx, unsigned int flags, CUdevice dev), pctx, flags, dev)

CU_HOOK_GENERATE_INTERCEPT(cuCtxDestroy, (CUcontext ctx), ctx)

CU_HOOK_GENERATE_INTERCEPT(cuCtxPushCurrent, (CUcontext ctx), ctx)

CU_HOOK_GENERATE_INTERCEPT(cuCtxPopCurrent, (CUcontext *pctx), pctx)

CU_HOOK_GENERATE_INTERCEPT(cuCtxSetCurrent, (CUcontext ctx), ctx)

CU_HOOK_GENERATE_INTERCEPT(cuCtxGetCurrent, (CUcontext *pctx), pctx)

CU_HOOK_GENERATE_INTERCEPT(cuCtxGetDevice, (CUdevice *device), device)

CU_HOOK_GENERATE_INTERCEPT(cuCtxGetFlags, (unsigned int *flags), flags)

CU_HOOK_GENERATE_INTERCEPT(cuCtxSynchronize, (void))

CU_HOOK_GENERATE_INTERCEPT(cuCtxSetLimit, (CUlimit limit, size_t value), limit, value)

CU_HOOK_GENERATE_INTERCEPT(cuCtxGetLimit, (size_t *pvalue, CUlimit limit), pvalue, limit)

CU_HOOK_GENERATE_INTERCEPT(cuCtxGetCacheConfig, (CUfunc_cache *pconfig), pconfig)

CU_HOOK_GENERATE_INTERCEPT(cuCtxSetCacheConfig, (CUfunc_cache config), config)

CU_HOOK_GENERATE_INTERCEPT(cuCtxGetSharedMemConfig, (CUsharedconfig *pConfig), pConfig)

CU_HOOK_GENERATE_INTERCEPT(cuCtxSetSharedMemConfig, (CUsharedconfig config), config)

CU_HOOK_GENERATE_INTERCEPT(cuCtxGetApiVersion, (CUcontext ctx, unsigned int *version), ctx, version)

CU_HOOK_GENERATE_INTERCEPT(cuCtxGetStreamPriorityRange, (int *leastPriority, int *greatestPriority), leastPriority, greatestPriority)

CU_HOOK_GENERATE_INTERCEPT(cuCtxResetPersistingL2Cache, (void))

CU_HOOK_GENERATE_INTERCEPT(cuCtxAttach, (CUcontext *pctx, unsigned int flags), pctx, flags)

CU_HOOK_GENERATE_INTERCEPT(cuCtxDetach, (CUcontext ctx), ctx)

CU_HOOK_GENERATE_INTERCEPT(cuModuleLoad, (CUmodule *module, const char *fname), module, fname)

CU_HOOK_GENERATE_INTERCEPT(cuModuleLoadData, (CUmodule *module, const void *image), module, image)

CU_HOOK_GENERATE_INTERCEPT(cuModuleLoadDataEx, (CUmodule *module, const void *image, unsigned int numOptions, CUjit_option *options, void **optionValues), module, image, numOptions, options, optionValues)

CU_HOOK_GENERATE_INTERCEPT(cuModuleLoadFatBinary, (CUmodule *module, const void *fatCubin), module, fatCubin)

CU_HOOK_GENERATE_INTERCEPT(cuModuleUnload, (CUmodule hmod), hmod)

CU_HOOK_GENERATE_INTERCEPT(cuModuleGetFunction, (CUfunction *hfunc, CUmodule hmod, const char *name), hfunc, hmod, name)

CU_HOOK_GENERATE_INTERCEPT(cuModuleGetGlobal, (CUdeviceptr *dptr, size_t *bytes, CUmodule hmod, const char *name), dptr, bytes, hmod, name)

CU_HOOK_GENERATE_INTERCEPT(cuModuleGetTexRef, (CUtexref *pTexRef, CUmodule hmod, const char *name), pTexRef, hmod, name)

CU_HOOK_GENERATE_INTERCEPT(cuModuleGetSurfRef, (CUsurfref *pSurfRef, CUmodule hmod, const char *name), pSurfRef, hmod, name)

CU_HOOK_GENERATE_INTERCEPT(cuLinkCreate, (unsigned int numOptions, CUjit_option *options, void **optionValues, CUlinkState *stateOut), numOptions, options, optionValues, stateOut)

CU_HOOK_GENERATE_INTERCEPT(cuLinkAddData, (CUlinkState state, CUjitInputType type, void *data, size_t size, const char *name, unsigned int numOptions, CUjit_option *options, void **optionValues), state, type, data, size, name, numOptions, options, optionValues)

CU_HOOK_GENERATE_INTERCEPT(cuLinkAddFile, (CUlinkState state, CUjitInputType type, const char *path, unsigned int numOptions, CUjit_option *options, void **optionValues), state, type, path, numOptions, options, optionValues)

CU_HOOK_GENERATE_INTERCEPT(cuLinkComplete, (CUlinkState state, void **cubinOut, size_t *sizeOut), state, cubinOut, sizeOut)

CU_HOOK_GENERATE_INTERCEPT(cuLinkDestroy, (CUlinkState state), state)

CU_HOOK_GENERATE_INTERCEPT(cuMemGetInfo, (size_t *free, size_t *total), free, total)

CU_HOOK_GENERATE_INTERCEPT(cuMemAlloc, (CUdeviceptr *dptr, size_t bytesize), dptr, bytesize)

CU_HOOK_GENERATE_INTERCEPT(cuMemAllocPitch, (CUdeviceptr *dptr, size_t *pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes), dptr, pPitch, WidthInBytes, Height, ElementSizeBytes)

CU_HOOK_GENERATE_INTERCEPT(cuMemFree, (CUdeviceptr dptr), dptr)

CU_HOOK_GENERATE_INTERCEPT(cuMemGetAddressRange, (CUdeviceptr *pbase, size_t *psize, CUdeviceptr dptr), pbase, psize, dptr)

CU_HOOK_GENERATE_INTERCEPT(cuMemAllocHost, (void **pp, size_t bytesize), pp, bytesize)

CU_HOOK_GENERATE_INTERCEPT(cuMemFreeHost, (void *p), p)

CU_HOOK_GENERATE_INTERCEPT(cuMemHostAlloc, (void **pp, size_t bytesize, unsigned int Flags), pp, bytesize, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuMemHostGetDevicePointer, (CUdeviceptr *pdptr, void *p, unsigned int Flags), pdptr, p, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuMemHostGetFlags, (unsigned int *pFlags, void *p), pFlags, p)

CU_HOOK_GENERATE_INTERCEPT(cuMemAllocManaged, (CUdeviceptr *dptr, size_t bytesize, unsigned int flags), dptr, bytesize, flags)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGetByPCIBusId, (CUdevice *dev, const char *pciBusId), dev, pciBusId)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGetPCIBusId, (char *pciBusId, int len, CUdevice dev), pciBusId, len, dev)

CU_HOOK_GENERATE_INTERCEPT(cuIpcGetEventHandle, (CUipcEventHandle *pHandle, CUevent event), pHandle, event)

CU_HOOK_GENERATE_INTERCEPT(cuIpcOpenEventHandle, (CUevent *phEvent, CUipcEventHandle handle), phEvent, handle)

CU_HOOK_GENERATE_INTERCEPT(cuIpcGetMemHandle, (CUipcMemHandle *pHandle, CUdeviceptr dptr), pHandle, dptr)

CU_HOOK_GENERATE_INTERCEPT(cuIpcOpenMemHandle, (CUdeviceptr *pdptr, CUipcMemHandle handle, unsigned int Flags), pdptr, handle, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuIpcCloseMemHandle, (CUdeviceptr dptr), dptr)

CU_HOOK_GENERATE_INTERCEPT(cuMemHostRegister, (void *p, size_t bytesize, unsigned int Flags), p, bytesize, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuMemHostUnregister, (void *p), p)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpy, (CUdeviceptr dst, CUdeviceptr src, size_t ByteCount), dst, src, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyPeer, (CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount), dstDevice, dstContext, srcDevice, srcContext, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyHtoD, (CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount), dstDevice, srcHost, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyDtoH, (void *dstHost, CUdeviceptr srcDevice, size_t ByteCount), dstHost, srcDevice, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyDtoD, (CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount), dstDevice, srcDevice, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyDtoA, (CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount), dstArray, dstOffset, srcDevice, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyAtoD, (CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount), dstDevice, srcArray, srcOffset, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyHtoA, (CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount), dstArray, dstOffset, srcHost, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyAtoH, (void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount), dstHost, srcArray, srcOffset, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyAtoA, (CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount), dstArray, dstOffset, srcArray, srcOffset, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpy2D, (const CUDA_MEMCPY2D *pCopy), pCopy)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpy2DUnaligned, (const CUDA_MEMCPY2D *pCopy), pCopy)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpy3D, (const CUDA_MEMCPY3D *pCopy), pCopy)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpy3DPeer, (const CUDA_MEMCPY3D_PEER *pCopy), pCopy)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyAsync, (CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream), dst, src, ByteCount, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyPeerAsync, (CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream), dstDevice, dstContext, srcDevice, srcContext, ByteCount, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyHtoDAsync, (CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, CUstream hStream), dstDevice, srcHost, ByteCount, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyDtoHAsync, (void *dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream), dstHost, srcDevice, ByteCount, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyDtoDAsync, (CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream), dstDevice, srcDevice, ByteCount, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyHtoAAsync, (CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount, CUstream hStream), dstArray, dstOffset, srcHost, ByteCount, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyAtoHAsync, (void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream), dstHost, srcArray, srcOffset, ByteCount, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpy2DAsync, (const CUDA_MEMCPY2D *pCopy, CUstream hStream), pCopy, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpy3DAsync, (const CUDA_MEMCPY3D *pCopy, CUstream hStream), pCopy, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpy3DPeerAsync, (const CUDA_MEMCPY3D_PEER *pCopy, CUstream hStream), pCopy, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD8, (CUdeviceptr dstDevice, unsigned char uc, size_t N), dstDevice, uc, N)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD16, (CUdeviceptr dstDevice, unsigned short us, size_t N), dstDevice, us, N)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD32, (CUdeviceptr dstDevice, unsigned int ui, size_t N), dstDevice, ui, N)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD2D8, (CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height), dstDevice, dstPitch, uc, Width, Height)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD2D16, (CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height), dstDevice, dstPitch, us, Width, Height)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD2D32, (CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height), dstDevice, dstPitch, ui, Width, Height)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD8Async, (CUdeviceptr dstDevice, unsigned char uc, size_t N, CUstream hStream), dstDevice, uc, N, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD16Async, (CUdeviceptr dstDevice, unsigned short us, size_t N, CUstream hStream), dstDevice, us, N, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD32Async, (CUdeviceptr dstDevice, unsigned int ui, size_t N, CUstream hStream), dstDevice, ui, N, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD2D8Async, (CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height, CUstream hStream), dstDevice, dstPitch, uc, Width, Height, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD2D16Async, (CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height, CUstream hStream), dstDevice, dstPitch, us, Width, Height, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemsetD2D32Async, (CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height, CUstream hStream), dstDevice, dstPitch, ui, Width, Height, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuArrayCreate, (CUarray *pHandle, const CUDA_ARRAY_DESCRIPTOR *pAllocateArray), pHandle, pAllocateArray)

CU_HOOK_GENERATE_INTERCEPT(cuArrayGetDescriptor, (CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray), pArrayDescriptor, hArray)

CU_HOOK_GENERATE_INTERCEPT(cuArrayGetSparseProperties, (CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties, CUarray array), sparseProperties, array)

CU_HOOK_GENERATE_INTERCEPT(cuMipmappedArrayGetSparseProperties, (CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties, CUmipmappedArray mipmap), sparseProperties, mipmap)

CU_HOOK_GENERATE_INTERCEPT(cuArrayDestroy, (CUarray hArray), hArray)

CU_HOOK_GENERATE_INTERCEPT(cuArray3DCreate, (CUarray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray), pHandle, pAllocateArray)

CU_HOOK_GENERATE_INTERCEPT(cuArray3DGetDescriptor, (CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray), pArrayDescriptor, hArray)

CU_HOOK_GENERATE_INTERCEPT(cuMipmappedArrayCreate, (CUmipmappedArray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pMipmappedArrayDesc, unsigned int numMipmapLevels), pHandle, pMipmappedArrayDesc, numMipmapLevels)

CU_HOOK_GENERATE_INTERCEPT(cuMipmappedArrayGetLevel, (CUarray *pLevelArray, CUmipmappedArray hMipmappedArray, unsigned int level), pLevelArray, hMipmappedArray, level)

CU_HOOK_GENERATE_INTERCEPT(cuMipmappedArrayDestroy, (CUmipmappedArray hMipmappedArray), hMipmappedArray)

CU_HOOK_GENERATE_INTERCEPT(cuMemAddressReserve, (CUdeviceptr *ptr, size_t size, size_t alignment, CUdeviceptr addr, unsigned long long flags), ptr, size, alignment, addr, flags)

CU_HOOK_GENERATE_INTERCEPT(cuMemAddressFree, (CUdeviceptr ptr, size_t size), ptr, size)

CU_HOOK_GENERATE_INTERCEPT(cuMemCreate, (CUmemGenericAllocationHandle *handle, size_t size, const CUmemAllocationProp *prop, unsigned long long flags), handle, size, prop, flags)

CU_HOOK_GENERATE_INTERCEPT(cuMemRelease, (CUmemGenericAllocationHandle handle), handle)

CU_HOOK_GENERATE_INTERCEPT(cuMemMap, (CUdeviceptr ptr, size_t size, size_t offset, CUmemGenericAllocationHandle handle, unsigned long long flags), ptr, size, offset, handle, flags)

CU_HOOK_GENERATE_INTERCEPT(cuMemMapArrayAsync, (CUarrayMapInfo  *mapInfoList, unsigned int count, CUstream hStream), mapInfoList, count, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemUnmap, (CUdeviceptr ptr, size_t size), ptr, size)

CU_HOOK_GENERATE_INTERCEPT(cuMemSetAccess, (CUdeviceptr ptr, size_t size, const CUmemAccessDesc *desc, size_t count), ptr, size, desc, count)

CU_HOOK_GENERATE_INTERCEPT(cuMemGetAccess, (unsigned long long *flags, const CUmemLocation *location, CUdeviceptr ptr), flags, location, ptr)

CU_HOOK_GENERATE_INTERCEPT(cuMemExportToShareableHandle, (void *shareableHandle, CUmemGenericAllocationHandle handle, CUmemAllocationHandleType handleType, unsigned long long flags), shareableHandle, handle, handleType, flags)

CU_HOOK_GENERATE_INTERCEPT(cuMemImportFromShareableHandle, (CUmemGenericAllocationHandle *handle, void *osHandle, CUmemAllocationHandleType shHandleType), handle, osHandle, shHandleType)

CU_HOOK_GENERATE_INTERCEPT(cuMemGetAllocationGranularity, (size_t *granularity, const CUmemAllocationProp *prop, CUmemAllocationGranularity_flags option), granularity, prop, option)

CU_HOOK_GENERATE_INTERCEPT(cuMemGetAllocationPropertiesFromHandle, (CUmemAllocationProp *prop, CUmemGenericAllocationHandle handle), prop, handle)

CU_HOOK_GENERATE_INTERCEPT(cuMemRetainAllocationHandle, (CUmemGenericAllocationHandle *handle, void *addr), handle, addr)

CU_HOOK_GENERATE_INTERCEPT(cuPointerGetAttribute, (void *data, CUpointer_attribute attribute, CUdeviceptr ptr), data, attribute, ptr)

CU_HOOK_GENERATE_INTERCEPT(cuMemPrefetchAsync, (CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream), devPtr, count, dstDevice, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemAdvise, (CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUdevice device), devPtr, count, advice, device)

CU_HOOK_GENERATE_INTERCEPT(cuMemRangeGetAttribute, (void *data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count), data, dataSize, attribute, devPtr, count)

CU_HOOK_GENERATE_INTERCEPT(cuMemRangeGetAttributes, (void **data, size_t *dataSizes, CUmem_range_attribute *attributes, size_t numAttributes, CUdeviceptr devPtr, size_t count), data, dataSizes, attributes, numAttributes, devPtr, count)

CU_HOOK_GENERATE_INTERCEPT(cuPointerSetAttribute, (const void *value, CUpointer_attribute attribute, CUdeviceptr ptr), value, attribute, ptr)

CU_HOOK_GENERATE_INTERCEPT(cuPointerGetAttributes, (unsigned int numAttributes, CUpointer_attribute *attributes, void **data, CUdeviceptr ptr), numAttributes, attributes, data, ptr)

CU_HOOK_GENERATE_INTERCEPT(cuStreamCreate, (CUstream *phStream, unsigned int Flags), phStream, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuStreamCreateWithPriority, (CUstream *phStream, unsigned int flags, int priority), phStream, flags, priority)

CU_HOOK_GENERATE_INTERCEPT(cuStreamGetPriority, (CUstream hStream, int *priority), hStream, priority)

CU_HOOK_GENERATE_INTERCEPT(cuStreamGetFlags, (CUstream hStream, unsigned int *flags), hStream, flags)

CU_HOOK_GENERATE_INTERCEPT(cuStreamGetCtx, (CUstream hStream, CUcontext *pctx), hStream, pctx)

CU_HOOK_GENERATE_INTERCEPT(cuStreamWaitEvent, (CUstream hStream, CUevent hEvent, unsigned int Flags), hStream, hEvent, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuStreamAddCallback, (CUstream hStream, CUstreamCallback callback, void *userData, unsigned int flags), hStream, callback, userData, flags)

CU_HOOK_GENERATE_INTERCEPT(cuStreamBeginCapture, (CUstream hStream, CUstreamCaptureMode mode), hStream, mode)

CU_HOOK_GENERATE_INTERCEPT(cuThreadExchangeStreamCaptureMode, (CUstreamCaptureMode *mode), mode)

CU_HOOK_GENERATE_INTERCEPT(cuStreamEndCapture, (CUstream hStream, CUgraph *phGraph), hStream, phGraph)

CU_HOOK_GENERATE_INTERCEPT(cuStreamIsCapturing, (CUstream hStream, CUstreamCaptureStatus *captureStatus), hStream, captureStatus)

CU_HOOK_GENERATE_INTERCEPT(cuStreamGetCaptureInfo, (CUstream hStream, CUstreamCaptureStatus *captureStatus, cuuint64_t *id), hStream, captureStatus, id)

CU_HOOK_GENERATE_INTERCEPT(cuStreamAttachMemAsync, (CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int flags), hStream, dptr, length, flags)

CU_HOOK_GENERATE_INTERCEPT(cuStreamQuery, (CUstream hStream), hStream)

CU_HOOK_GENERATE_INTERCEPT(cuStreamSynchronize, (CUstream hStream), hStream)

CU_HOOK_GENERATE_INTERCEPT(cuStreamDestroy, (CUstream hStream), hStream)

CU_HOOK_GENERATE_INTERCEPT(cuStreamCopyAttributes, (CUstream dst, CUstream src), dst, src)

CU_HOOK_GENERATE_INTERCEPT(cuStreamGetAttribute, (CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue *value_out), hStream, attr, value_out)

CU_HOOK_GENERATE_INTERCEPT(cuStreamSetAttribute, (CUstream hStream, CUstreamAttrID attr, const CUstreamAttrValue *value), hStream, attr, value)

CU_HOOK_GENERATE_INTERCEPT(cuEventCreate, (CUevent *phEvent, unsigned int Flags), phEvent, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuEventRecord, (CUevent hEvent, CUstream hStream), hEvent, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuEventRecordWithFlags, (CUevent hEvent, CUstream hStream, unsigned int flags), hEvent, hStream, flags)

CU_HOOK_GENERATE_INTERCEPT(cuEventQuery, (CUevent hEvent), hEvent)

CU_HOOK_GENERATE_INTERCEPT(cuEventSynchronize, (CUevent hEvent), hEvent)

CU_HOOK_GENERATE_INTERCEPT(cuEventDestroy, (CUevent hEvent), hEvent)

CU_HOOK_GENERATE_INTERCEPT(cuEventElapsedTime, (float *pMilliseconds, CUevent hStart, CUevent hEnd), pMilliseconds, hStart, hEnd)

CU_HOOK_GENERATE_INTERCEPT(cuImportExternalMemory, (CUexternalMemory *extMem_out, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *memHandleDesc), extMem_out, memHandleDesc)

CU_HOOK_GENERATE_INTERCEPT(cuExternalMemoryGetMappedBuffer, (CUdeviceptr *devPtr, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *bufferDesc), devPtr, extMem, bufferDesc)

CU_HOOK_GENERATE_INTERCEPT(cuExternalMemoryGetMappedMipmappedArray, (CUmipmappedArray *mipmap, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *mipmapDesc), mipmap, extMem, mipmapDesc)

CU_HOOK_GENERATE_INTERCEPT(cuDestroyExternalMemory, (CUexternalMemory extMem), extMem)

CU_HOOK_GENERATE_INTERCEPT(cuImportExternalSemaphore, (CUexternalSemaphore *extSem_out, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *semHandleDesc), extSem_out, semHandleDesc)

CU_HOOK_GENERATE_INTERCEPT(cuSignalExternalSemaphoresAsync, (const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream), extSemArray, paramsArray, numExtSems, stream)

CU_HOOK_GENERATE_INTERCEPT(cuWaitExternalSemaphoresAsync, (const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream), extSemArray, paramsArray, numExtSems, stream)

CU_HOOK_GENERATE_INTERCEPT(cuDestroyExternalSemaphore, (CUexternalSemaphore extSem), extSem)

CU_HOOK_GENERATE_INTERCEPT(cuStreamWaitValue32, (CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags), stream, addr, value, flags)

CU_HOOK_GENERATE_INTERCEPT(cuStreamWaitValue64, (CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags), stream, addr, value, flags)

CU_HOOK_GENERATE_INTERCEPT(cuStreamWriteValue32, (CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags), stream, addr, value, flags)

CU_HOOK_GENERATE_INTERCEPT(cuStreamWriteValue64, (CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags), stream, addr, value, flags)

CU_HOOK_GENERATE_INTERCEPT(cuStreamBatchMemOp, (CUstream stream, unsigned int count, CUstreamBatchMemOpParams *paramArray, unsigned int flags), stream, count, paramArray, flags)

CU_HOOK_GENERATE_INTERCEPT(cuFuncGetAttribute, (int *pi, CUfunction_attribute attrib, CUfunction hfunc), pi, attrib, hfunc)

CU_HOOK_GENERATE_INTERCEPT(cuFuncSetAttribute, (CUfunction hfunc, CUfunction_attribute attrib, int value), hfunc, attrib, value)

CU_HOOK_GENERATE_INTERCEPT(cuFuncSetCacheConfig, (CUfunction hfunc, CUfunc_cache config), hfunc, config)

CU_HOOK_GENERATE_INTERCEPT(cuFuncSetSharedMemConfig, (CUfunction hfunc, CUsharedconfig config), hfunc, config)

CU_HOOK_GENERATE_INTERCEPT(cuLaunchKernel, (CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams, void **extra), f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams, extra)

CU_HOOK_GENERATE_INTERCEPT(cuLaunchCooperativeKernel, (CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams), f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams)

CU_HOOK_GENERATE_INTERCEPT(cuLaunchCooperativeKernelMultiDevice, (CUDA_LAUNCH_PARAMS *launchParamsList, unsigned int numDevices, unsigned int flags), launchParamsList, numDevices, flags)

CU_HOOK_GENERATE_INTERCEPT(cuLaunchHostFunc, (CUstream hStream, CUhostFn fn, void *userData), hStream, fn, userData)

CU_HOOK_GENERATE_INTERCEPT(cuFuncSetBlockShape, (CUfunction hfunc, int x, int y, int z), hfunc, x, y, z)

CU_HOOK_GENERATE_INTERCEPT(cuFuncSetSharedSize, (CUfunction hfunc, unsigned int bytes), hfunc, bytes)

CU_HOOK_GENERATE_INTERCEPT(cuParamSetSize, (CUfunction hfunc, unsigned int numbytes), hfunc, numbytes)

CU_HOOK_GENERATE_INTERCEPT(cuParamSeti, (CUfunction hfunc, int offset, unsigned int value), hfunc, offset, value)

CU_HOOK_GENERATE_INTERCEPT(cuParamSetf, (CUfunction hfunc, int offset, float value), hfunc, offset, value)

CU_HOOK_GENERATE_INTERCEPT(cuParamSetv, (CUfunction hfunc, int offset, void *ptr, unsigned int numbytes), hfunc, offset, ptr, numbytes)

CU_HOOK_GENERATE_INTERCEPT(cuLaunch, (CUfunction f), f)

CU_HOOK_GENERATE_INTERCEPT(cuLaunchGrid, (CUfunction f, int grid_width, int grid_height), f, grid_width, grid_height)

CU_HOOK_GENERATE_INTERCEPT(cuLaunchGridAsync, (CUfunction f, int grid_width, int grid_height, CUstream hStream), f, grid_width, grid_height, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuParamSetTexRef, (CUfunction hfunc, int texunit, CUtexref hTexRef), hfunc, texunit, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuGraphCreate, (CUgraph *phGraph, unsigned int flags), phGraph, flags)

CU_HOOK_GENERATE_INTERCEPT(cuGraphAddKernelNode, (CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_KERNEL_NODE_PARAMS *nodeParams), phGraphNode, hGraph, dependencies, numDependencies, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphKernelNodeGetParams, (CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS *nodeParams), hNode, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphKernelNodeSetParams, (CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS *nodeParams), hNode, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphAddMemcpyNode, (CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMCPY3D *copyParams, CUcontext ctx), phGraphNode, hGraph, dependencies, numDependencies, copyParams, ctx)

CU_HOOK_GENERATE_INTERCEPT(cuGraphMemcpyNodeGetParams, (CUgraphNode hNode, CUDA_MEMCPY3D *nodeParams), hNode, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphMemcpyNodeSetParams, (CUgraphNode hNode, const CUDA_MEMCPY3D *nodeParams), hNode, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphAddMemsetNode, (CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMSET_NODE_PARAMS *memsetParams, CUcontext ctx), phGraphNode, hGraph, dependencies, numDependencies, memsetParams, ctx)

CU_HOOK_GENERATE_INTERCEPT(cuGraphMemsetNodeGetParams, (CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS *nodeParams), hNode, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphMemsetNodeSetParams, (CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS *nodeParams), hNode, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphAddHostNode, (CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_HOST_NODE_PARAMS *nodeParams), phGraphNode, hGraph, dependencies, numDependencies, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphHostNodeGetParams, (CUgraphNode hNode, CUDA_HOST_NODE_PARAMS *nodeParams), hNode, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphHostNodeSetParams, (CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS *nodeParams), hNode, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphAddChildGraphNode, (CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUgraph childGraph), phGraphNode, hGraph, dependencies, numDependencies, childGraph)

CU_HOOK_GENERATE_INTERCEPT(cuGraphChildGraphNodeGetGraph, (CUgraphNode hNode, CUgraph *phGraph), hNode, phGraph)

CU_HOOK_GENERATE_INTERCEPT(cuGraphAddEmptyNode, (CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies), phGraphNode, hGraph, dependencies, numDependencies)

CU_HOOK_GENERATE_INTERCEPT(cuGraphAddEventRecordNode, (CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event), phGraphNode, hGraph, dependencies, numDependencies, event)

CU_HOOK_GENERATE_INTERCEPT(cuGraphEventRecordNodeGetEvent, (CUgraphNode hNode, CUevent *event_out), hNode, event_out)

CU_HOOK_GENERATE_INTERCEPT(cuGraphEventRecordNodeSetEvent, (CUgraphNode hNode, CUevent event), hNode, event)

CU_HOOK_GENERATE_INTERCEPT(cuGraphAddEventWaitNode, (CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event), phGraphNode, hGraph, dependencies, numDependencies, event)

CU_HOOK_GENERATE_INTERCEPT(cuGraphEventWaitNodeGetEvent, (CUgraphNode hNode, CUevent *event_out), hNode, event_out)

CU_HOOK_GENERATE_INTERCEPT(cuGraphEventWaitNodeSetEvent, (CUgraphNode hNode, CUevent event), hNode, event)

CU_HOOK_GENERATE_INTERCEPT(cuGraphClone, (CUgraph *phGraphClone, CUgraph originalGraph), phGraphClone, originalGraph)

CU_HOOK_GENERATE_INTERCEPT(cuGraphNodeFindInClone, (CUgraphNode *phNode, CUgraphNode hOriginalNode, CUgraph hClonedGraph), phNode, hOriginalNode, hClonedGraph)

CU_HOOK_GENERATE_INTERCEPT(cuGraphNodeGetType, (CUgraphNode hNode, CUgraphNodeType *type), hNode, type)

CU_HOOK_GENERATE_INTERCEPT(cuGraphGetNodes, (CUgraph hGraph, CUgraphNode *nodes, size_t *numNodes), hGraph, nodes, numNodes)

CU_HOOK_GENERATE_INTERCEPT(cuGraphGetRootNodes, (CUgraph hGraph, CUgraphNode *rootNodes, size_t *numRootNodes), hGraph, rootNodes, numRootNodes)

CU_HOOK_GENERATE_INTERCEPT(cuGraphGetEdges, (CUgraph hGraph, CUgraphNode *from, CUgraphNode *to, size_t *numEdges), hGraph, from, to, numEdges)

CU_HOOK_GENERATE_INTERCEPT(cuGraphNodeGetDependencies, (CUgraphNode hNode, CUgraphNode *dependencies, size_t *numDependencies), hNode, dependencies, numDependencies)

CU_HOOK_GENERATE_INTERCEPT(cuGraphNodeGetDependentNodes, (CUgraphNode hNode, CUgraphNode *dependentNodes, size_t *numDependentNodes), hNode, dependentNodes, numDependentNodes)

CU_HOOK_GENERATE_INTERCEPT(cuGraphAddDependencies, (CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies), hGraph, from, to, numDependencies)

CU_HOOK_GENERATE_INTERCEPT(cuGraphRemoveDependencies, (CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies), hGraph, from, to, numDependencies)

CU_HOOK_GENERATE_INTERCEPT(cuGraphDestroyNode, (CUgraphNode hNode), hNode)

CU_HOOK_GENERATE_INTERCEPT(cuGraphInstantiate, (CUgraphExec *phGraphExec, CUgraph hGraph, CUgraphNode *phErrorNode, char *logBuffer, size_t bufferSize), phGraphExec, hGraph, phErrorNode, logBuffer, bufferSize)

CU_HOOK_GENERATE_INTERCEPT(cuGraphExecKernelNodeSetParams, (CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS *nodeParams), hGraphExec, hNode, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphExecMemcpyNodeSetParams, (CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMCPY3D *copyParams, CUcontext ctx), hGraphExec, hNode, copyParams, ctx)

CU_HOOK_GENERATE_INTERCEPT(cuGraphExecMemsetNodeSetParams, (CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS *memsetParams, CUcontext ctx), hGraphExec, hNode, memsetParams, ctx)

CU_HOOK_GENERATE_INTERCEPT(cuGraphExecHostNodeSetParams, (CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS *nodeParams), hGraphExec, hNode, nodeParams)

CU_HOOK_GENERATE_INTERCEPT(cuGraphExecChildGraphNodeSetParams, (CUgraphExec hGraphExec, CUgraphNode hNode, CUgraph childGraph), hGraphExec, hNode, childGraph)

CU_HOOK_GENERATE_INTERCEPT(cuGraphExecEventRecordNodeSetEvent, (CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event), hGraphExec, hNode, event)

CU_HOOK_GENERATE_INTERCEPT(cuGraphExecEventWaitNodeSetEvent, (CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event), hGraphExec, hNode, event)

CU_HOOK_GENERATE_INTERCEPT(cuGraphUpload, (CUgraphExec hGraphExec, CUstream hStream), hGraphExec, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuGraphLaunch, (CUgraphExec hGraphExec, CUstream hStream), hGraphExec, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuGraphExecDestroy, (CUgraphExec hGraphExec), hGraphExec)

CU_HOOK_GENERATE_INTERCEPT(cuGraphDestroy, (CUgraph hGraph), hGraph)

CU_HOOK_GENERATE_INTERCEPT(cuGraphExecUpdate, (CUgraphExec hGraphExec, CUgraph hGraph, CUgraphNode *hErrorNode_out, CUgraphExecUpdateResult *updateResult_out), hGraphExec, hGraph, hErrorNode_out, updateResult_out)

CU_HOOK_GENERATE_INTERCEPT(cuGraphKernelNodeCopyAttributes, (CUgraphNode dst, CUgraphNode src), dst, src)

CU_HOOK_GENERATE_INTERCEPT(cuGraphKernelNodeGetAttribute, (CUgraphNode hNode, CUkernelNodeAttrID attr, CUkernelNodeAttrValue *value_out), hNode, attr, value_out)

CU_HOOK_GENERATE_INTERCEPT(cuGraphKernelNodeSetAttribute, (CUgraphNode hNode, CUkernelNodeAttrID attr, const CUkernelNodeAttrValue *value), hNode, attr, value)

CU_HOOK_GENERATE_INTERCEPT(cuOccupancyMaxActiveBlocksPerMultiprocessor, (int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize), numBlocks, func, blockSize, dynamicSMemSize)

CU_HOOK_GENERATE_INTERCEPT(cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags, (int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize, unsigned int flags), numBlocks, func, blockSize, dynamicSMemSize, flags)

CU_HOOK_GENERATE_INTERCEPT(cuOccupancyMaxPotentialBlockSize, (int *minGridSize, int *blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit), minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit)

CU_HOOK_GENERATE_INTERCEPT(cuOccupancyMaxPotentialBlockSizeWithFlags, (int *minGridSize, int *blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit, unsigned int flags), minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit, flags)

CU_HOOK_GENERATE_INTERCEPT(cuOccupancyAvailableDynamicSMemPerBlock, (size_t *dynamicSmemSize, CUfunction func, int numBlocks, int blockSize), dynamicSmemSize, func, numBlocks, blockSize)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetArray, (CUtexref hTexRef, CUarray hArray, unsigned int Flags), hTexRef, hArray, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetMipmappedArray, (CUtexref hTexRef, CUmipmappedArray hMipmappedArray, unsigned int Flags), hTexRef, hMipmappedArray, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetAddress, (size_t *ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, size_t bytes), ByteOffset, hTexRef, dptr, bytes)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetAddress2D, (CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, size_t Pitch), hTexRef, desc, dptr, Pitch)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetFormat, (CUtexref hTexRef, CUarray_format fmt, int NumPackedComponents), hTexRef, fmt, NumPackedComponents)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetAddressMode, (CUtexref hTexRef, int dim, CUaddress_mode am), hTexRef, dim, am)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetFilterMode, (CUtexref hTexRef, CUfilter_mode fm), hTexRef, fm)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetMipmapFilterMode, (CUtexref hTexRef, CUfilter_mode fm), hTexRef, fm)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetMipmapLevelBias, (CUtexref hTexRef, float bias), hTexRef, bias)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetMipmapLevelClamp, (CUtexref hTexRef, float minMipmapLevelClamp, float maxMipmapLevelClamp), hTexRef, minMipmapLevelClamp, maxMipmapLevelClamp)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetMaxAnisotropy, (CUtexref hTexRef, unsigned int maxAniso), hTexRef, maxAniso)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetBorderColor, (CUtexref hTexRef, float *pBorderColor), hTexRef, pBorderColor)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefSetFlags, (CUtexref hTexRef, unsigned int Flags), hTexRef, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetAddress, (CUdeviceptr *pdptr, CUtexref hTexRef), pdptr, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetArray, (CUarray *phArray, CUtexref hTexRef), phArray, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetMipmappedArray, (CUmipmappedArray *phMipmappedArray, CUtexref hTexRef), phMipmappedArray, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetAddressMode, (CUaddress_mode *pam, CUtexref hTexRef, int dim), pam, hTexRef, dim)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetFilterMode, (CUfilter_mode *pfm, CUtexref hTexRef), pfm, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetFormat, (CUarray_format *pFormat, int *pNumChannels, CUtexref hTexRef), pFormat, pNumChannels, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetMipmapFilterMode, (CUfilter_mode *pfm, CUtexref hTexRef), pfm, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetMipmapLevelBias, (float *pbias, CUtexref hTexRef), pbias, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetMipmapLevelClamp, (float *pminMipmapLevelClamp, float *pmaxMipmapLevelClamp, CUtexref hTexRef), pminMipmapLevelClamp, pmaxMipmapLevelClamp, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetMaxAnisotropy, (int *pmaxAniso, CUtexref hTexRef), pmaxAniso, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetBorderColor, (float *pBorderColor, CUtexref hTexRef), pBorderColor, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefGetFlags, (unsigned int *pFlags, CUtexref hTexRef), pFlags, hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefCreate, (CUtexref *pTexRef), pTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexRefDestroy, (CUtexref hTexRef), hTexRef)

CU_HOOK_GENERATE_INTERCEPT(cuSurfRefSetArray, (CUsurfref hSurfRef, CUarray hArray, unsigned int Flags), hSurfRef, hArray, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuSurfRefGetArray, (CUarray *phArray, CUsurfref hSurfRef), phArray, hSurfRef)

CU_HOOK_GENERATE_INTERCEPT(cuTexObjectCreate, (CUtexObject *pTexObject, const CUDA_RESOURCE_DESC *pResDesc, const CUDA_TEXTURE_DESC *pTexDesc, const CUDA_RESOURCE_VIEW_DESC *pResViewDesc), pTexObject, pResDesc, pTexDesc, pResViewDesc)

CU_HOOK_GENERATE_INTERCEPT(cuTexObjectDestroy, (CUtexObject texObject), texObject)

CU_HOOK_GENERATE_INTERCEPT(cuTexObjectGetResourceDesc, (CUDA_RESOURCE_DESC *pResDesc, CUtexObject texObject), pResDesc, texObject)

CU_HOOK_GENERATE_INTERCEPT(cuTexObjectGetTextureDesc, (CUDA_TEXTURE_DESC *pTexDesc, CUtexObject texObject), pTexDesc, texObject)

CU_HOOK_GENERATE_INTERCEPT(cuTexObjectGetResourceViewDesc, (CUDA_RESOURCE_VIEW_DESC *pResViewDesc, CUtexObject texObject), pResViewDesc, texObject)

CU_HOOK_GENERATE_INTERCEPT(cuSurfObjectCreate, (CUsurfObject *pSurfObject, const CUDA_RESOURCE_DESC *pResDesc), pSurfObject, pResDesc)

CU_HOOK_GENERATE_INTERCEPT(cuSurfObjectDestroy, (CUsurfObject surfObject), surfObject)

CU_HOOK_GENERATE_INTERCEPT(cuSurfObjectGetResourceDesc, (CUDA_RESOURCE_DESC *pResDesc, CUsurfObject surfObject), pResDesc, surfObject)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceCanAccessPeer, (int *canAccessPeer, CUdevice dev, CUdevice peerDev), canAccessPeer, dev, peerDev)

CU_HOOK_GENERATE_INTERCEPT(cuCtxEnablePeerAccess, (CUcontext peerContext, unsigned int Flags), peerContext, Flags)

CU_HOOK_GENERATE_INTERCEPT(cuCtxDisablePeerAccess, (CUcontext peerContext), peerContext)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceGetP2PAttribute, (int* value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice), value, attrib, srcDevice, dstDevice)

CU_HOOK_GENERATE_INTERCEPT(cuGraphicsUnregisterResource, (CUgraphicsResource resource), resource)

CU_HOOK_GENERATE_INTERCEPT(cuGraphicsSubResourceGetMappedArray, (CUarray *pArray, CUgraphicsResource resource, unsigned int arrayIndex, unsigned int mipLevel), pArray, resource, arrayIndex, mipLevel)

CU_HOOK_GENERATE_INTERCEPT(cuGraphicsResourceGetMappedMipmappedArray, (CUmipmappedArray *pMipmappedArray, CUgraphicsResource resource), pMipmappedArray, resource)

CU_HOOK_GENERATE_INTERCEPT(cuGraphicsResourceGetMappedPointer, (CUdeviceptr *pDevPtr, size_t *pSize, CUgraphicsResource resource), pDevPtr, pSize, resource)

CU_HOOK_GENERATE_INTERCEPT(cuGraphicsResourceSetMapFlags, (CUgraphicsResource resource, unsigned int flags), resource, flags)

CU_HOOK_GENERATE_INTERCEPT(cuGraphicsMapResources, (unsigned int count, CUgraphicsResource *resources, CUstream hStream), count, resources, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuGraphicsUnmapResources, (unsigned int count, CUgraphicsResource *resources, CUstream hStream), count, resources, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuGetExportTable, (const void **ppExportTable, const CUuuid *pExportTableId), ppExportTable, pExportTableId)

CU_HOOK_GENERATE_INTERCEPT(cuFuncGetModule, (CUmodule *hmod, CUfunction hfunc), hmod, hfunc)

CU_HOOK_GENERATE_INTERCEPT(cuDeviceTotalMem, (unsigned int *bytes, CUdevice dev), bytes, dev)

CU_HOOK_GENERATE_INTERCEPT(cuMemGetInfo, (unsigned int *free, unsigned int *total), free, total)

CU_HOOK_GENERATE_INTERCEPT(cuMemAllocHost, (void **pp, unsigned int bytesize), pp, bytesize)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyHtoA, (CUarray dstArray, unsigned int dstOffset, const void *srcHost, unsigned int ByteCount), dstArray, dstOffset, srcHost, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyAtoH, (void *dstHost, CUarray srcArray, unsigned int srcOffset, unsigned int ByteCount), dstHost, srcArray, srcOffset, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyAtoA, (CUarray dstArray, unsigned int dstOffset, CUarray srcArray, unsigned int srcOffset, unsigned int ByteCount), dstArray, dstOffset, srcArray, srcOffset, ByteCount)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyHtoAAsync, (CUarray dstArray, unsigned int dstOffset, const void *srcHost, unsigned int ByteCount, CUstream hStream), dstArray, dstOffset, srcHost, ByteCount, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuMemcpyAtoHAsync, (void *dstHost, CUarray srcArray, unsigned int srcOffset, unsigned int ByteCount, CUstream hStream), dstHost, srcArray, srcOffset, ByteCount, hStream)

CU_HOOK_GENERATE_INTERCEPT(cuStreamBeginCapture, (CUstream hStream), hStream)

