project(backtrace)

set(REPO_PATH ${ANDROID_CORE_PATH}/libbacktrace)
set(INC_PATH ${ANDROID_CORE_PATH}/include/backtrace)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

if(NOT UNWIND_FOUND)
    find_package(Unwind REQUIRED)
endif()

include_directories(
    ${LIBBACKTRACE_INCLUDE_DIR}
    ${LIBUNWIND_INCLUDE_DIR}
)

add_definitions(
    -std=gnu++11
)

set(SRC
   ${REPO_PATH}/BacktraceImpl.cpp
   ${REPO_PATH}/BacktraceMap.cpp
   ${REPO_PATH}/BacktraceThread.cpp
   ${REPO_PATH}/thread_utils.c
   ${REPO_PATH}/UnwindCurrent.cpp
   ${REPO_PATH}/UnwindMap.cpp
   ${REPO_PATH}/UnwindPtrace.cpp
)

set(INC
   ${INC_PATH}/backtrace_constants.h
   ${INC_PATH}/Backtrace.h
   ${INC_PATH}/BacktraceMap.h
)

add_library(${PROJECT_NAME} SHARED ${SRC} ${INC})

target_link_libraries(${PROJECT_NAME}
    ${LIBUNWIND_LIBRARY}
    ${LIBUNWIND_PTRACE_LIBRARY}
    ${LIBLOG_LIBRARY}
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_LIB_DIR})
#install(FILES
#        ${HEADERS}
#        DESTINATION include/backtrace)
