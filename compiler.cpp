#include "compiler.h"
#include <sstream>
#include <iostream>
compiler::compiler()
{
    error=false;
    input_file=new File("test.txt");
    output_file=new File();
}
void compiler::run()
{
    line_number=1;
    get_next_line();
    while(input_file->more==true){
        ///std::cout<<line_number<<"\n";
        inteperate_line();
        get_next_line();
    }
    for(unsigned int iii=0;iii<opcodes.size();iii++){
        std::cout<<opcodes[iii]<<" , "<<"\n";
    }
    print_errors();
    output();
}
void compiler::output()
{
    output_file->output(opcodes,"test_program.c8");
}
void compiler::inteperate_line()
{
    strip_instruction();
    ///std::cout<<instruction<<"\n";
    if(instruction=="cls"){
        opcodes.push_back(0x00E0);
    }else if(instruction=="ret"){
        opcodes.push_back(0x000E);
    }else if(instruction=="sys"){
        sys();
    }else if(instruction=="jp"){
        jp();
    }else if(instruction=="call"){
        call();
    }else if(instruction=="se"){
        se();
    }else if(instruction=="sne"){
        sne();
    }else if(instruction=="ser"){
        ser();
    }else if(instruction=="ld"){
        ld();
    }else if(instruction=="add"){
        add();
    }else if(instruction=="or"){
        Or();
    }else if(instruction=="and"){
        And();
    }else if(instruction=="xor"){
        Xor();
    }else if(instruction=="addr"){
        addr();
    }else if(instruction=="sub"){
        sub();
    }else if(instruction=="shr"){
        shr();
    }else if(instruction=="subn"){
        subn();
    }else if(instruction=="shl"){
        shl();
    }else if(instruction=="sner"){
        sner();
    }else if(instruction=="jpv"){
        jpv();
    }else if(instruction=="rnd"){
        rnd();
    }else if(instruction=="drw"){
        drw();
    }else if(instruction=="skp"){
        skp();
    }else if(instruction=="sknp"){
        sknp();
    }else if(instruction=="addi"){
        addi();
    }else if(instruction=="scr"){
        scr();
    }else if(instruction=="scl"){
        scl();
    }else if(instruction=="exit"){
        exit();
    }else if(instruction=="low"){
        low();
    }else if(instruction=="high"){
        high();
    }else if(instruction=="drw0"){
        drw0();
    }else if(instruction=="scd"){
        scd();
    }else{
        handle_error("unknown instruction");
    }
    line_number+=1;
    instruction="";
}
void compiler::get_next_line()
{
    line=input_file->get_next_line();
}
void compiler::strip_instruction()
{
    for(unsigned int iii=0;iii<line.length();iii++){
        if((line[iii])!=' '){
            instruction+=line[iii];
        }else if(line[iii]==' '){
            break;
        }
    }
}
void compiler::string_too_opcode(std::string opcode)
{
    std::istringstream buffer(opcode);
    unsigned short temp_opcode;
    ///buffer >> std::hex >> temp_opcode;
    opcodes.push_back(temp_opcode);
}
void compiler::handle_error(std::string message)
{
    error=true;
    compiler_error temp(message,line_number,line);
    errors.push_back(temp);
}
void compiler::print_errors()
{
    for(unsigned int iii=0;iii<errors.size();iii++){
        errors[iii].print_error();
    }
}
