project(servicemanager)

set(REPO_PATH ${ANDROID_FRAMEWORKS_NATIVE_PATH}/cmds/servicemanager)

#FXIME: add selinux
#find_package(selinux REQUIRED)

include_directories(
    ${LIBLOG_INCLUDE_DIR}
    ${LIBBINDER_INCLUDE_DIR}
)

set(SRC
    ${REPO_PATH}/service_manager.cpp
    ${REPO_PATH}/binder.cpp
)

set_source_files_properties(SRC PROPERTIES LANGUAGE CXX)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME}
    ${LIBLOG_LIBRARY}
    selinux)

install(TARGETS ${PROJECT_NAME} DESTINATION ${ANDROID_BIN_DIR})
