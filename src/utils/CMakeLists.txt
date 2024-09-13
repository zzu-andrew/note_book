
cmake_minimum_required (VERSION 3.3.0)
cmake_policy(VERSION 3.2.2)
cmake_policy(SET CMP0054 NEW)

# Set up the project
project (leetcode)

#
## all cpp files
#file(GLOB_RECURSE CPP_SRC_LIST ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
## generate target for every cpp file
#foreach(v ${CPP_SRC_LIST})
#    # file relative path from src/
#    string(REGEX MATCH ".*" relative_path ${v})
##    # delete string "src/"
#    string(REGEX REPLACE "src/" "" target_name ${relative_path})
#    # rename '/' and '.' to '_'
#    string(REGEX REPLACE "/|\\." "_" target_name ${target_name})
#
#    add_executable(${target_name}_demo ${v})
#    target_link_libraries(${target_name}_demo
#            gtest
#            gmock
#            gtest_main
#            pthread)
#endforeach()


# all cpp files
file(GLOB_RECURSE CPP_SRC_LIST ${CMAKE_CURRENT_LIST_DIR}/*.cpp)

#message(STATUS ${CMAKE_CURRENT_LIST_DIR})

# generate target for every cpp file
foreach(v ${CPP_SRC_LIST})
    # file relative path from src/
    string(REGEX MATCH ".*" relative_path ${v})
    #    message(STATUS ${relative_path})

    # delete string "src/"
    string(REGEX REPLACE "${CMAKE_CURRENT_LIST_DIR}/" "" target_name ${relative_path})
    #    message(STATUS ${target_name})
    # rename '/' and '.' to '_'
    string(REGEX REPLACE "/|\\." "_" target_name ${target_name})

    add_executable(${target_name} ${v})
    target_link_libraries(${target_name}
            pthread)
endforeach()



