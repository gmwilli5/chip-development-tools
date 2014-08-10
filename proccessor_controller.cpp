#include "proccessor_controller.h"
#include "debuger.h"
#include "chip8_with_debug.h"
controller::controller()
{
    paused=false;
}
void controller::pause()
{
    SDL_Event event;
    while(paused==true){
        debug->pause();
        while(SDL_PollEvent(&event)) {
            paused_events(&event);
        }
    }
}
void controller::step()
{
    chip->emulateCycle();
}
void controller::reset()
{
    chip->init();
}
void controller::restart()
{
    paused=true;
}
unsigned char controller::read(unsigned short address)
{
    return chip->memory[address];
}
void controller::write(unsigned short address,unsigned char data)
{
    chip->memory[address]=data;
}
void controller::paused_events(SDL_Event * event)
{
    if(event->type==SDL_KEYDOWN){
        switch(event->key.keysym.sym){
            case SDLK_s:
                restart();
                break;
            case SDLK_RIGHT:
                step();
                break;
            case SDLK_r:
                reset();
                break;
        }
    }
}
