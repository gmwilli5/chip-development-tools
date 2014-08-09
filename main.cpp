#include <iostream>
#include "compiler.h"
#include "chip_state.h"
int chip8_debug_main(int argc, char **argv);
int chip8_main(int argc, char **argv);
int main()
{
    std::cout<<sizeof(chip8_state)<<"\n";
    chip8_debug_main(0,0);
    //chip8_main(0,0);
}
