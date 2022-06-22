# Use at least CMake 3.3
cmake_minimum_required (VERSION 3.3.0)
cmake_policy(VERSION 3.2.2)
cmake_policy(SET CMP0054 NEW)

# Set up the project
project (node_books)

add_definitions("-pg -o0 -g")


add_subdirectory(src)













