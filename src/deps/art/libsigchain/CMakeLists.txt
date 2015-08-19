project(sigchain)

set(MODULE_PATH ${ART_PATH}/sigchainlib)

set(SRC
    ${MODULE_PATH}/sigchain.cc
)

set(INC )

add_library(${PROJECT_NAME} SHARED ${SRC})
