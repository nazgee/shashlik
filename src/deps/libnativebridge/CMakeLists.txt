project(nativebridge)

set(REPO_PATH ${ANDROID_CORE_PATH}/libnativebridge)
#add_definitions(-DHAVE_SYS_UIO_H)
#add_definitions(-fpermissive) # To allow cast from char* to int

set(SRC
   ${REPO_PATH}/native_bridge.cc
)

add_definitions(-std=gnu++11)

#set(HEADERS
#    ${ANDROID_CORE_PATH}/include
#)

include_directories(${LIBNATIVEBRIDGE_INCLUDES} ${LIBNATIVEHELPER_INCLUDES})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../android-core/include) # for android/log.h
#include_directories(SYSTEM ${CMAKE_INSTALL_PREFIX}/include)

add_library(${PROJECT_NAME} SHARED ${SRC})
target_link_libraries(${PROJECT_NAME} dl nativehelper)

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_LIB_DIR})
#install(FILES
#        ${nativehelper_HEADERS}
#        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/nativehelper)
