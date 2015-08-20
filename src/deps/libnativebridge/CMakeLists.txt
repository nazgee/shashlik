project(nativebridge)

set(REPO_PATH ${ANDROID_CORE_PATH}/libnativebridge)
set(INC_PATH ${ANDROID_CORE_PATH}/include/nativebridge)

include_directories(
    ${INC_PATH}/../
    ${LIBNATIVEHELPER_INCLUDE_DIR}
)

add_definitions(
    -std=gnu++11
)

set(SRC
   ${REPO_PATH}/native_bridge.cc
)

#set(INC
#    ${ANDROID_CORE_PATH}/include
#)

add_library(${PROJECT_NAME} SHARED ${SRC})

target_link_libraries(${PROJECT_NAME}
    ${LIBNATIVEHELPER_LIBRARY}
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_LIB_DIR})
#install(FILES
#        ${nativehelper_HEADERS}
#        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/nativehelper)
