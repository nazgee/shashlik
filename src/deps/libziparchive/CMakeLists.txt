project(ziparchive)

set(REPO_PATH ${ANDROID_CORE_PATH}/libziparchive)

set(ziparchive_SRCS
    ${REPO_PATH}/zip_archive.cc
)

add_library(ziparchive SHARED ${ziparchive_SRCS})
target_include_directories(ziparchive
    PRIVATE
    ${LIBLOG_INCLUDES}
    ${LIBNATIVEHELPER_INCLUDE_DIR}
)
target_link_libraries(ziparchive
    z
    utils
)
#set_target_properties(ziparchive PROPERTIES COMPILE_FLAGS "-std=c++11")
if(FORCE_32BIT_BUILD)
    set_target_properties(ziparchive PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
endif(FORCE_32BIT_BUILD)
install(TARGETS ziparchive DESTINATION ${ANDROID_LIB_DIR})
