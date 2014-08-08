#include "compiler.h"
#include <string>
#include <sstream>
///0nnn - SYS addr
void compiler::sys()
{
    std::string temp="";
    for(unsigned int iii=4;iii<line.length();iii++){
        temp+=line[iii];
    }
    std::string opcode="0"+temp;
    string_too_opcode(opcode);
}
///1nnn - JP addr
void compiler::jp()
{
    std::string temp="";
    for(unsigned int iii=3;iii<line.length();iii++){
        temp+=line[iii];
    }
    std::string opcode="1"+temp;
    string_too_opcode(opcode);
}
///2nnn - CALL addr
void compiler::call()
{
    std::string temp="";
    for(unsigned int iii=5;iii<line.length();iii++){
        temp+=line[iii];
    }
    std::string opcode="2"+temp;
    string_too_opcode(opcode);
}
///3xkk - SE Vx, byte
void compiler::se()
{
    std::string temp="3";
    for(unsigned int iii=3;iii<line.length();iii++){
        if((line[iii]==',')|(line[iii]==' ')){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    string_too_opcode(temp);
}
///4xkk - SNE Vx, byte
void compiler::sne()
{
    std::string temp="4";
    for(unsigned int iii=4;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='0';
    string_too_opcode(temp);
}
///5xy0 - SER Vx, Vy
void compiler::ser()
{
    std::string temp="5";
    for(unsigned int iii=4;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='0';
    string_too_opcode(temp);
}
///6xkk - LD Vx, byte
/*void compiler::ld()
{
    std::string temp="6";
    for(unsigned int iii=3;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    string_too_opcode(temp);
}*/
///7xkk - ADD Vx, byte
void compiler::add()
{
    std::string temp="7";
    for(unsigned int iii=3;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    string_too_opcode(temp);
}
///8xy0 - LD Vx, Vy
/*void compiler::ldr()
{
    std::string temp="8";
    for(unsigned int iii=4;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='0';
    string_too_opcode(temp);
}*/
///8xy1 - OR Vx, Vy
void compiler::Or()
{
    std::string temp="8";
    for(unsigned int iii=3;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='1';
    string_too_opcode(temp);
}
///8xy2 - AND Vx, Vy
void compiler::And()
{
    std::string temp="8";
    for(unsigned int iii=4;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='2';
    string_too_opcode(temp);
}
///8xy3 - XOR Vx, Vy
void compiler::Xor()
{
    std::string temp="8";
    for(unsigned int iii=4;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='3';
    string_too_opcode(temp);
}
///8xy4 - ADD Vx, Vy
void compiler::addr()
{
    std::string temp="8";
    for(unsigned int iii=5;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='4';
    string_too_opcode(temp);
}
///8xy5 - SUB Vx, Vy
void compiler::sub()
{
    std::string temp="8";
    for(unsigned int iii=4;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='5';
    string_too_opcode(temp);
}
///8xy6 - SHR Vx {, Vy}
void compiler::shr()
{
    std::string temp="8";
    for(unsigned int iii=4;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='6';
    string_too_opcode(temp);
}
///8xy7 - SUBN Vx, Vy
void compiler::subn()
{
    std::string temp="8";
    for(unsigned int iii=5;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='7';
    string_too_opcode(temp);
}
///8xyE - SHL Vx {, Vy}
void compiler::shl()
{
    std::string temp="8";
    for(unsigned int iii=4;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='E';
    string_too_opcode(temp);
}
///9xy0 - SNEr Vx, Vy
void compiler::sner()
{
    std::string temp="9";
    for(unsigned int iii=4;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='0';
    string_too_opcode(temp);
}
///Annn - LDi addr
/*void compiler::ldi()
{
    std::string temp="";
    for(unsigned int iii=4;iii<line.length();iii++){
        temp+=line[iii];
    }
    std::string opcode="A"+temp;
    string_too_opcode(opcode);
}*/
///Bnnn - JPV, addr
void compiler::jpv()
{
    std::string temp="";
    for(unsigned int iii=4;iii<line.length();iii++){
        temp+=line[iii];
    }
    std::string opcode="B"+temp;
    string_too_opcode(opcode);
}
///Cxkk - RND Vx, byte
void compiler::rnd()
{
    std::string temp="C";
    for(unsigned int iii=3;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    string_too_opcode(temp);
}
///Dxyn - DRW Vx, Vy, nibble
void compiler::drw()
{
    std::string temp="D";
    for(unsigned int iii=3;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    string_too_opcode(temp);
}
///Ex9E - SKP Vx
void compiler::skp()
{
    std::string temp="E";
    for(unsigned int iii=3;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+="9E";
    string_too_opcode(temp);
}
///ExA1 - SKNP Vx
void compiler::sknp()
{
    std::string temp="E";
    for(unsigned int iii=3;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+="A1";
    string_too_opcode(temp);
}
///00FB - SCR
void compiler::addi()
{
    std::string temp="";
    for(unsigned int iii=4;iii<line.length();iii++){
        temp+=line[iii];
    }
    std::string opcode="F"+temp+"1E";
    string_too_opcode(opcode);
}
///00FC - SCL
void compiler::scr()
{
    string_too_opcode("00FB");
}
///00FC - SCL
void compiler::scl()
{
    string_too_opcode("00FC");
}
///00FD - EXIT
void compiler::exit()
{
    string_too_opcode("00FD");
}
///00FE - LOW
void compiler::low()
{
    string_too_opcode("00FE");
}
///00FF - HIGH
void compiler::high()
{
    string_too_opcode("00FF");
}
///Dxy0 - DRW0 Vx, Vy
void compiler::drw0()
{
    std::string temp="D";
    for(unsigned int iii=5;iii<line.length();iii++){
        if(line[iii]==','|line[iii]==' '){
            9*10;
        }else{
            temp+=line[iii];
        }
    }
    temp+='0';
    string_too_opcode(temp);
}
///00Cn - SCD nibble
void compiler::scd()
{
    std::string temp="00C"+line[4];
    string_too_opcode(temp);
}
