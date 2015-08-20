project(dalvikvm)

#if(NOT ${LIBNATIVEHELPER_FOUND})
#    find_package(libnativehelper REQUIRED)
#endif()

set(REPO_PATH ${ART_PATH}/dalvikvm)

set(SRC
    ${REPO_PATH}/dalvikvm.cc
)

set(INC )

include_directories(
    ${LIBNATIVEHELPER_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME}
    ${LIBNATIVEHELPER_LIBRARY}
)
