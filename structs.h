#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
struct chip8_state_turned_into_class{
    unsigned short I;
    unsigned short pc;
    unsigned short sp;
    unsigned short opcode;
    unsigned char  V[16];
    unsigned short stack[16];
    unsigned char  delay_timer;
    unsigned char  sound_timer;
};
#endif // STRUCTS_H_INCLUDED
