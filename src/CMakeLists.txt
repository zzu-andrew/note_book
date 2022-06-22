


add_executable(main
        main.cpp
        extern.cpp)

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


add_executable(ftrace
        ftrace/ftrace.c)

add_executable(elf_parser
        elf_parser/elf_parser.c)

add_executable(elf_parser32
        elf_parser/elf_parser32.c)


add_executable(tracer
        tracer/tracer.c)

add_executable(tracer2
        tracer/tracer2.c)

add_executable(tracer_test
        tracer/tracer_test.c)




