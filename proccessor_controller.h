#ifndef PROCCESSOR_CONTROLLER_H_INCLUDED
#define PROCCESSOR_CONTROLLER_H_INCLUDED
#include "SDL/SDL.h"
#undef main
class chip8_debug;
class chip8_state;
class debugger;
class controller{
    public:
        chip8_debug* chip;
        chip8_state* state;
        debugger* debug;
        bool paused;
    public:
        controller();
        void pause();
        void paused_events(SDL_Event * Event);
        void step();
        void reset();
        void restart();
        void read_mode();
        void write_mode();
        unsigned char read(unsigned short address);
        void write(unsigned short address,unsigned char data);
};
#endif // PROCCESSOR_CONTROLLER_H_INCLUDED
