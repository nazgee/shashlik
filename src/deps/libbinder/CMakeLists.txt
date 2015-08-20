project(binder)

set(REPO_PATH ${ANDROID_FRAMEWORKS_NATIVE_PATH}/libs/binder)
set(INC_PATH ${ANDROID_FRAMEWORKS_NATIVE_PATH}/include/binder)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${INC_PATH}/../
    ${LIBUTILS_INCLUDES}
    ${LIBCUTILS_INCLUDE_DIR}
)

add_definitions(
    -fpermissive                # for redeclaration of  char32_t
)

set(SRC
    ${REPO_PATH}/AppOpsManager.cpp
    ${REPO_PATH}/Binder.cpp
    ${REPO_PATH}/BpBinder.cpp
    ${REPO_PATH}/BufferedTextOutput.cpp
    ${REPO_PATH}/Debug.cpp
    ${REPO_PATH}/IAppOpsCallback.cpp
    ${REPO_PATH}/IAppOpsService.cpp
    ${REPO_PATH}/IInterface.cpp
    ${REPO_PATH}/IMemory.cpp
    ${REPO_PATH}/IPCThreadState.cpp
    ${REPO_PATH}/IPermissionController.cpp
    ${REPO_PATH}/IServiceManager.cpp
    ${REPO_PATH}/MemoryBase.cpp
    ${REPO_PATH}/MemoryDealer.cpp
    ${REPO_PATH}/MemoryHeapBase.cpp
    ${REPO_PATH}/Parcel.cpp
    ${REPO_PATH}/PermissionCache.cpp
    ${REPO_PATH}/ProcessState.cpp
    ${REPO_PATH}/Static.cpp
    ${REPO_PATH}/TextOutput.cpp
)

set(INC
    #    ${INC_PATH}/AppOpsManager.h
    ${INC_PATH}/Binder.h
    #    ${INC_PATH}/BinderService.h
    ${INC_PATH}/BpBinder.h
    ${INC_PATH}/BufferedTextOutput.h
    ${INC_PATH}/Debug.h
    #    ${INC_PATH}/IAppOpsCallback.h
    #    ${INC_PATH}/IAppOpsService.h
    ${INC_PATH}/IBinder.h
    ${INC_PATH}/IInterface.h
    #    ${INC_PATH}/IMemory.h
    ${INC_PATH}/IPCThreadState.h
    #    ${INC_PATH}/IPermissionController.h
    #    ${INC_PATH}/IServiceManager.h
    #    ${INC_PATH}/MemoryBase.h
    #    ${INC_PATH}/MemoryDealer.h
    #    ${INC_PATH}/MemoryHeapBase.h
    ${INC_PATH}/Parcel.h
    #    ${INC_PATH}/PermissionCache.h
    ${INC_PATH}/ProcessState.h
    ${INC_PATH}/TextOutput.h
)

add_library(${PROJECT_NAME} SHARED ${SRC} ${INC})

target_link_libraries(${PROJECT_NAME}
    ${LIBUTILS_LIBRARY}
    ${LIBCUTILS_LIBRARY}
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_LIB_DIR})
install(FILES
        ${INC}
        DESTINATION include/binder)

add_subdirectory(tests)
