
include_directories(../inc)

add_executable(main
        main.cpp
        extern.cpp)

target_include_directories(main
        PUBLIC ../inc)


target_link_libraries(main
        PUBLIC pthread)

add_executable(memory_management
        memory_management/memory_management.cpp)
target_include_directories(memory_management
        PUBLIC memory_management
        PUBLIC ../inc)

add_executable(exception_sample
        exception_sample/exception_sample.cpp)
target_include_directories(exception_sample
        PUBLIC exception_sample
        PUBLIC ../inc)


IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")

    add_executable(ftrace
            ftrace/ftrace.c)

    add_executable(tracer
            tracer/tracer.c)

    add_executable(tracer2
            tracer/tracer2.c)

    add_executable(tracer_test
            tracer/tracer_test.c)

    add_executable(elf_parser
            elf_parser/elf_parser.cpp)

    add_executable(elf_main
            elf_parser/main.c)


ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    MESSAGE(STATUS "current platform: FreeBSD")
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")


add_executable(db
        db/db.c)

add_executable(db_example
        db/db_example.cpp)

add_executable(semaphore
        semaphore/semaphore.cpp)

add_executable(defer
        defer/defer.cpp)

add_subdirectory(smart_ptr)

add_subdirectory(track_new)





