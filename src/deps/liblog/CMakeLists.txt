project(log)

set(REPO_PATH ${ANDROID_CORE_PATH}/liblog)
set(INC_PATH ${ANDROID_CORE_PATH}/include/log)

include_directories(
    ${INC_PATH}/../
)

add_definitions(
    -DFAKE_LOG_DEVICE=1
)

set(SRC
    ${REPO_PATH}/event_tag_map.c
    ${REPO_PATH}/fake_log_device.c
    ${REPO_PATH}/logd_write.c
    #${REPO_PATH}/log_read.c
    ${REPO_PATH}/logprint.c
    ${REPO_PATH}/uio.c
)

set(INC
    ${INC_PATH}/event_tag_map.h
    ${INC_PATH}/logd.h
    ${INC_PATH}/logger.h
    ${INC_PATH}/log.h
    ${INC_PATH}/logprint.h
    ${INC_PATH}/uio.h
)

add_library(${PROJECT_NAME} SHARED ${SRC})

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_LIB_DIR})
#install(FILES
#        ${log_HEADERS}
#        DESTINATION include/log)

add_subdirectory(tests)
