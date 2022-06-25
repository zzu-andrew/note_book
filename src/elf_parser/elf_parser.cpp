//
// Created by wangyz38535 on 2022/6/23.
//

#include "elf_parser.h"


/*
 * file size  $1 = 38488
 *
 * e_shoff = 36184
 *
 * */

int main(int argc, char* argv[])
{
    using ELF::ELF_reader;

    ELF_reader s(argv[1]);

    s.show_file_header();
    s.show_section_headers();
    s.show_symbols();
    return 0;
}

