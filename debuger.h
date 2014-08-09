#ifndef DEBUGER_H_INCLUDED
#define DEBUGER_H_INCLUDED
#include "chip8_with_debug.h"
#include <string>
#include <fstream>
class debugger{
    public:
        chip8_debug* chip;
        std::fstream file;
    public:
        debugger();
        debugger(chip8_debug* c8,std::string file_name);
        void print_info();
        void save_info();
};
#endif // DEBUGER_H_INCLUDED
