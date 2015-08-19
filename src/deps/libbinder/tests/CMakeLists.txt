project(binder_tests)

add_subdirectory(binder_demo)

add_executable(binder_test binder_test.cpp)
target_link_libraries(binder_test binder)
