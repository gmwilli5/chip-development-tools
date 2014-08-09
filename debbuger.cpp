#include "debuger.h"
debugger::debugger()
{

}
debugger::debugger(chip8_debug* c8,std::string file_name)
{
    file.open(file_name);
    chip=c8;
}
void debugger::print_info()
{

}
void debugger::save_info()
{

}

