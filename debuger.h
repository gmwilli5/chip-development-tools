#ifndef DEBUGER_H_INCLUDED
#define DEBUGER_H_INCLUDED
#include "chip8_with_debug.h"
#include "chip_state.h"
class chip8_state;
#include <string>
#include <fstream>
class chip8_debug;
class debugger{
    public:
        chip8_debug* chip;
        std::ofstream file;
        std::ofstream mem_dump_file;
        chip8_state* current_state;
    public:
        debugger();
        ~debugger();
        debugger(chip8_debug* c8,std::string file_name,std::string mem_file_name);
        void print_info();
        void print_registers();
        void print_stack();
        void save_info();
        void save_registers();
        void save_stack();
        void mem_dump();
        void opcode_dump();
        void pause();
};
#endif // DEBUGER_H_INCLUDED
