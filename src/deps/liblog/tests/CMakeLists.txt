project(log_tests)

add_executable(log_test log_test.cpp)
target_link_libraries(log_test ${LIBLOG_LIBRARY})
