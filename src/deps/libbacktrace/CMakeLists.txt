project(backtrace)

set(REPO_PATH ${ANDROID_CORE_PATH})
set(MOD_PATH ${REPO_PATH}/libbacktrace)
set(INC_PATH ${REPO_PATH}/include/backtrace)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${LIBCORKSCREW_INCLUDES}
)

add_definitions(-D_GNU_SOURCE
                -DCORKSCREW_HAVE_ARCH
                -std=gnu++11
)

set(SRC
   ${MOD_PATH}/BacktraceImpl.cpp
   ${MOD_PATH}/BacktraceMap.cpp
   ${MOD_PATH}/BacktraceThread.cpp
   ${MOD_PATH}/thread_utils.c
   ${MOD_PATH}/UnwindCurrent.cpp
   ${MOD_PATH}/UnwindMap.cpp
   ${MOD_PATH}/UnwindPtrace.cpp
)

#set(HEADERS
#   ${INC_PATH}/backtrace.h
#   ${INC_PATH}/demangle.h
#   ${INC_PATH}/map_info.h
#   ${INC_PATH}/ptrace.h
#   ${INC_PATH}/symbol_table.h
#)

add_library(${PROJECT_NAME} SHARED ${SRC})
#FIXME: add find_package into main CMakeLists.txt
target_link_libraries(${PROJECT_NAME}
    dl unwind unwind-ptrace
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_LIB_DIR})
#install(FILES
#        ${HEADERS}
#        DESTINATION include/backtrace)
