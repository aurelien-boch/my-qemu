cmake_minimum_required(VERSION 3.18)

project(myquemu C)

set(CMAKE_C_STANDARD 11)

add_executable(myquemu main.c include/instructions.h src/misc/default_behavior.c src/parser/read_file.c src/parser/parser.c src/parser/types/number.c src/parser/types/string.c include/parser.h include/instructions_table.h src/parser/split_parameters.c src/parser/split_parameters.c src/exec/execute_instruction.c include/execution.h include/execution.h include/execution.h)

target_compile_options(myquemu PRIVATE -Wall -Wextra -g3)
