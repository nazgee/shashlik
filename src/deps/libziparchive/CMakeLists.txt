project(ziparchive)

set(REPO_PATH ${ANDROID_CORE_PATH}/libziparchive)
set(INC_PATH ${ANDROID_CORE_PATH}/include/ziparchive)

if(NOT ZLIB_FOUND)
    find_package(ZLIB REQUIRED)
endif()

include_directories(
    ${INC_PATH}/../
    ${LIBLOG_INCLUDE_DIR}
    ${LIBNATIVEHELPER_INCLUDE_DIR}
)

set(SRC
    ${REPO_PATH}/zip_archive.cc
)

add_library(${PROJECT_NAME} SHARED ${SRC})

target_link_libraries(${PROJECT_NAME}
    ${ZLIB_LIBRARY}
    ${LIBUTILS_LIBRARY}
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_LIB_DIR})
