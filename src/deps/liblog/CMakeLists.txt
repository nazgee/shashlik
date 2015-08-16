project(log)

set(REPO_PATH ${ANDROID_CORE_PATH})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${LIBLOG_INCLUDES}
)

add_definitions(-DFAKE_LOG_DEVICE=1)

set(log_SRCS
    ${REPO_PATH}/liblog/event_tag_map.c
    ${REPO_PATH}/liblog/fake_log_device.c
    ${REPO_PATH}/liblog/logd_write.c
    #${REPO_PATH}/liblog/log_read.c
    ${REPO_PATH}/liblog/logprint.c
    ${REPO_PATH}/liblog/uio.c
)

set(log_HEADERS
    ${REPO_PATH}/include/log/event_tag_map.h
    ${REPO_PATH}/include/log/logd.h
    ${REPO_PATH}/include/log/logger.h
    ${REPO_PATH}/include/log/log.h
    ${REPO_PATH}/include/log/logprint.h
    ${REPO_PATH}/include/log/uio.h
)

add_library(${PROJECT_NAME} SHARED ${log_SRCS})
if(FORCE_32BIT_BUILD)
    set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
endif(FORCE_32BIT_BUILD)

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_LIB_DIR})
#install(FILES
#        ${log_HEADERS}
#        DESTINATION include/log)

add_executable(log_test tests/log_test.cpp)
target_link_libraries(log_test log)

