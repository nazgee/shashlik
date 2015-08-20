project(cutils)

set(REPO_PATH ${ANDROID_CORE_PATH}/libcutils)
set(INC_PATH ${ANDROID_CORE_PATH}/include/)

if(NOT THREADS_FOUND)
    find_package(Threads REQUIRED)
endif()

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${INC_PATH}
)

add_definitions(
    -D_GNU_SOURCE
    -DHAVE_LINUX_LOCAL_SOCKET_NAMESPACE
    -DANDROID_SMP=0
)

set(SRC
    ${REPO_PATH}/android_reboot.c
    #${REPO_PATH}/ashmem-dev.c
    ${REPO_PATH}/ashmem-host.c
    ${REPO_PATH}/atomic.c # ARM only sources, apparently...
    ${REPO_PATH}/config_utils.c
    ${REPO_PATH}/cpu_info.c
    ${REPO_PATH}/debugger.c
    #${REPO_PATH}/dir_hash.c
    #    ${REPO_PATH}/dlmalloc_stubs.c
    ${REPO_PATH}/fs.c
    ${REPO_PATH}/hashmap.c
    ${REPO_PATH}/iosched_policy.c
    ${REPO_PATH}/klog.c
    #${REPO_PATH}/list.c
    ${REPO_PATH}/load_file.c
    ${REPO_PATH}/memory.c
    ${REPO_PATH}/multiuser.c
    ${REPO_PATH}/native_handle.c
    ${REPO_PATH}/open_memstream.c
    #    ${REPO_PATH}/partition_utils.c
    ${REPO_PATH}/process_name.c
    ${REPO_PATH}/qtaguid.c
    ${REPO_PATH}/record_stream.c
    ${REPO_PATH}/sched_policy.c
    #${REPO_PATH}/sha1.c
    ${REPO_PATH}/socket_inaddr_any_server.c
    ${REPO_PATH}/socket_local_client.c
    ${REPO_PATH}/socket_local_server.c
    ${REPO_PATH}/socket_loopback_client.c
    ${REPO_PATH}/socket_loopback_server.c
    ${REPO_PATH}/socket_network_client.c
    ${REPO_PATH}/sockets.c
    ${REPO_PATH}/strdup16to8.c
    ${REPO_PATH}/strdup8to16.c
    ${REPO_PATH}/str_parms.c
    ${REPO_PATH}/threads.c

    #${REPO_PATH}/properties.c
    #${REPO_PATH}/trace.c
    #${REPO_PATH}/uevent.c
)

set(INC
    ${INC_PATH}/android_reboot.h
    ${INC_PATH}/aref.h
    ${INC_PATH}/ashmem.h
    ${INC_PATH}/atomic-arm.h
    ${INC_PATH}/atomic.h
    ${INC_PATH}/atomic-inline.h
    ${INC_PATH}/atomic-mips.h
    ${INC_PATH}/atomic-x86_64.h
    ${INC_PATH}/bitops.h
    ${INC_PATH}/compiler.h
    ${INC_PATH}/config_utils.h
    ${INC_PATH}/cpu_info.h
    ${INC_PATH}/debugger.h
    ${INC_PATH}/dir_hash.h
    ${INC_PATH}/fs.h
    ${INC_PATH}/hashmap.h
    ${INC_PATH}/iosched_policy.h
    ${INC_PATH}/jstring.h
    ${INC_PATH}/klog.h
    ${INC_PATH}/list.h
    ${INC_PATH}/log.h
    ${INC_PATH}/memory.h
    ${INC_PATH}/misc.h
    ${INC_PATH}/multiuser.h
    ${INC_PATH}/native_handle.h
    ${INC_PATH}/open_memstream.h
    #    ${INC_PATH}/partition_utils.h
    ${INC_PATH}/process_name.h
    ${INC_PATH}/properties.h
    ${INC_PATH}/qtaguid.h
    ${INC_PATH}/record_stream.h
    ${INC_PATH}/sched_policy.h
    ${INC_PATH}/sockets.h
    ${INC_PATH}/str_parms.h
    ${INC_PATH}/threads.h
    ${INC_PATH}/trace.h
    ${INC_PATH}/tztime.h
    ${INC_PATH}/uevent.h
)

add_library(${PROJECT_NAME} SHARED ${SRC})

target_link_libraries(${PROJECT_NAME}
    ${CMAKE_THREAD_LIBS_INIT}
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_LIB_DIR})
install(FILES
        ${INC}
        DESTINATION include/cutils)
#install(FILES ${REPO_PATH}/include/sys/system_properties.h DESTINATION include/sys)

add_subdirectory(tests)
