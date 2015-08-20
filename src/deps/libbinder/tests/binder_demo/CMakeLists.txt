project(binder_demo)

set(SERVER dk_server)
set(CLIENT dk_client)

include_directories(SYSTEM
    ${LIBBINDER_INCLUDE_DIR}
    ${LIBUTILS_INCLUDE_DIR}
)

add_definitions(
    -std=gnu++11
)

# Server
set(SRC
    main_server.cpp
    server.cpp
    client.cpp # WTF, why this is needed?
    idkinterface.cpp
)
add_executable(${SERVER} ${SRC})
target_link_libraries(${SERVER} ${LIBBINDER_LIBRARY})

# Client
set(SRC
    main_client.cpp
    client.cpp
    idkinterface.cpp
)
add_executable(${CLIENT} ${SRC})
target_link_libraries(${CLIENT} ${LIBBINDER_LIBRARY})
