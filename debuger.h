#ifndef DEBUGER_H_INCLUDED
#define DEBUGER_H_INCLUDED
#include "chip8_with_debug.h"
#include "chip_state.h"
#include <string>
#include <fstream>
class debugger{
    public:
        chip8_debug* chip;
        std::fstream file;
        chip8_state current_state;
    public:
        debugger();
        debugger(chip8_debug* c8,std::string file_name);
        void print_info();
        void print_registers();
        void print_stack();
        void save_info();
        void save_registers();
        void save_stack();
};
#endif // DEBUGER_H_INCLUDED
