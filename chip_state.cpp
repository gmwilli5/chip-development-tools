#include "chip_state.h"
chip8_state::chip8_state(chip8_debug* chip)
{
    I=chip->I;
    pc=chip->pc;
    opcode=chip->opcode;
    for(int iii=0;iii<16;iii++){
        V[iii]=chip->V[iii];
    }
    for(int iii=0;iii<16;iii++){
        stack[iii]=chip->stack[iii];
    }
    delay_timer=chip->delay_timer;
    sound_timer=chip->sound_timer;
}
void chip8_state::fill_state(chip8_debug* chip)
{
    I=chip->I;
    pc=chip->pc;
    opcode=chip->opcode;
    for(int iii=0;iii<16;iii++){
        V[iii]=chip->V[iii];
    }
    for(int iii=0;iii<16;iii++){
        stack[iii]=chip->stack[iii];
    }
    delay_timer=chip->delay_timer;
    sound_timer=chip->sound_timer;
}
