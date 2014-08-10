#include "proccessor_controller.h"
#include "chip8_interactive.h"
#include <iostream>
void controller::editor_mode()
{

}
void controller::interactive_mode()
{

}
void controller::editor_thread()
{

}
///need to test this
void controller::get_opcode()
{
    std::cout<<"input opcode: ";
    std::cin>>chip_i->opcode;
    std::cout<<"\n";
}
