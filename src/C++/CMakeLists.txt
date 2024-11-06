




add_executable(mutex_test mutex/ab_mutex.cpp)
target_include_directories(mutex_test
        PUBLIC ../../inc)


target_link_libraries(mutex_test
        PUBLIC pthread)