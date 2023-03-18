cmake_minimum_required(VERSION 3.18)

project(myquemu C)

set(CMAKE_C_STANDARD 11)

add_executable(myquemu main.c include/instructions.h src/misc/default_behavior.c src/parser/read_file.c src/parser/parser.c src/parser/types/number.c src/parser/types/string.c include/parser.h include/instructions_table.h src/parser/split_parameters.c src/parser/split_parameters.c src/exec/execute_instruction.c include/execution.h include/execution.h include/execution.h src/exec/instructions/jmp.c src/parser/verify_instructions.c src/parser/verify_instructions.c src/exec/instructions/add.c src/exec/instructions/mov.c src/exec/instructions/inc.c src/exec/instructions/dec.c src/exec/instructions/div.c src/exec/instructions/dec.c src/exec/instructions/div.c src/exec/instructions/or.c src/exec/instructions/and.c src/exec/instructions/xor.c src/exec/instructions/not.c src/parser/types/register.c src/parser/types/register.c src/parser/types/get_param_type.c src/parser/types/get_param_type.c)

target_compile_options(myquemu PRIVATE -Wall -Wextra -g3)
