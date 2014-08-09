#ifndef DEBUGER_H_INCLUDED
#define DEBUGER_H_INCLUDED
#include "chip8_with_debug.h"
class debuger{
    public:
        chip8_debug* chip;
    public:
        debuger();
        void print_info();
        void save_info();
};
#endif // DEBUGER_H_INCLUDED
