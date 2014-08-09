#include "debuger.h"
#include <iostream>
debugger::debugger()
{

}
debugger::debugger(chip8_debug* c8,std::string file_name)
{
    file.open(file_name);
    chip=c8;
    current_state=new chip8_state;
}
debugger::~debugger()
{
    delete current_state;
}
void debugger::print_info()
{
    current_state->fill_state(chip);
    print_registers();
    print_stack();
    std::cout<<"Opcode: "<<std::hex<<current_state->opcode<<"\n";
    std::cout<<"delay timer: "<<std::hex<<current_state->delay_timer<<", ";
    std::cout<<"sound timer: "<<std::hex<<current_state->sound_timer<<", ";
}
void debugger::print_registers()
{
    std::cout<<"Registers: "<<"\n";
    for(int iii=0;iii<8;iii++){
        std::cout<<"V"<< iii <<": "<<std::hex<<current_state->V[iii]<<" ";
    }
    std::cout<<"\n";
    for(int iii=8;iii<16;iii++){
        std::cout<<"V"<<iii<<": "<<std::hex<<current_state->V[iii]<<" ";
    }
    std::cout<<"\n";
    std::cout<<"I: "<<std::hex<<current_state->I<<", ";
    std::cout<<"PC: "<<std::hex<<current_state->pc<<", ";
    std::cout<<"SP: "<<std::hex<<current_state->sp<<", ";
}
void debugger::print_stack()
{
    std::cout<<"Stack: "<<"\n";
    for(int iii=0;iii<8;iii++){
        std::cout<<"Stack "<<iii<<": "<<std::hex<<current_state->stack[iii]<<" ";
    }
    std::cout<<"\n";
    for(int iii=8;iii<16;iii++){
        std::cout<<"Stack "<<iii<<": "<<std::hex<<current_state->stack[iii]<<" ";
    }
    std::cout<<"\n";
}
void debugger::save_info()
{
    current_state->fill_state(chip);
    save_registers();
    save_stack();
    file<<"Opcode: "<<std::hex<<current_state->opcode<<"\n";
    file<<"delay timer: "<<std::hex<<current_state->delay_timer<<", ";
    file<<"sound timer: "<<std::hex<<current_state->sound_timer<<", ";
    file.close();
}
void debugger::save_registers()
{
    file<<"Registers: "<<"\n";
    for(int iii=0;iii<8;iii++){
        file<<"V"<< iii <<": "<<std::hex<<current_state->V[iii]<<" ";
    }
    file<<"\n";
    for(int iii=8;iii<16;iii++){
        file<<"V"<<iii<<": "<<std::hex<<current_state->V[iii]<<" ";
    }
    file<<"\n";
    file<<"I: "<<std::hex<<current_state->I<<", ";
    file<<"PC: "<<std::hex<<current_state->pc<<", ";
    file<<"SP: "<<std::hex<<current_state->sp<<", ";
}
void debugger::save_stack()
{
    file<<"Stack: "<<"\n";
    for(int iii=0;iii<8;iii++){
        file<<"Stack "<<iii<<": "<<std::hex<<current_state->stack[iii]<<" ";
    }
    file<<"\n";
    for(int iii=8;iii<16;iii++){
        file<<"Stack "<<iii<<": "<<std::hex<<current_state->stack[iii]<<" ";
    }
    file<<"\n";
}
