#ifndef CHIP_STATE_H_INCLUDED
#define CHIP_STATE_H_INCLUDED
#include "chip8_with_debug.h"
class chip8_state{
    public:
        unsigned short I;
        unsigned short pc;
        unsigned short sp;
        unsigned short opcode;
        unsigned char  V[16];
        unsigned short stack[16];
        unsigned char  delay_timer;
        unsigned char  sound_timer;
    public:
        chip8_state();
        chip8_state(chip8_debug* chip);
        void fill_state(chip8_debug* chip);
};
#endif // CHIP_STATE_H_INCLUDED
