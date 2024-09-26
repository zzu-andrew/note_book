
include_directories(../inc)

add_executable(main
        main.cpp
        extern.cpp)

target_include_directories(main
        PUBLIC ../inc)


target_link_libraries(main
        PUBLIC pthread)

#add_executable(memory/memory_management
#        memory/memory_management/memory_management.cpp)
#target_include_directories(memory/memory_management
#        PUBLIC memory/memory_management
#        PUBLIC ../inc)

#add_executable(C++/exception_sample
#        C++/exception_sample/exception_sample.cpp)
#target_include_directories(C++/exception_sample
#        PUBLIC C++/exception_sample
#        PUBLIC ../inc)


IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")

    add_executable(ftrace
            linux/ftrace/ftrace.c)

    add_executable(racer
            linux/tracer/tracer.c)

    add_executable(tracer2
            linux/tracer/tracer2.c)

    add_executable(tracer_test
            linux/tracer/tracer_test.c)

    add_executable(elf_parser
            C++/elf_parser/elf_parser.cpp)

    add_executable(elf_main
            C++/elf_parser/main.c)

    add_subdirectory(linux)

ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    MESSAGE(STATUS "current platform: FreeBSD")
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")


#add_executable(db
#        db/db.c)
#
#add_executable(db_example
#        db/db_example.cpp)

#add_executable(linux/semaphore
#        linux/semaphore/semaphore.cpp)
#
#add_executable(stack_frame
#        C++/stack_frames/stack_frames.cpp)



#add_executable(lru algorithm/lru_cache/lru_cache.cpp)
#
add_subdirectory(C++/smart_ptr)

add_subdirectory(linux/track_new)

add_subdirectory(allocator)

add_subdirectory(utils)

add_subdirectory(memory)

#add_subdirectory(tie)





