#include "compiler.h"
#include <string>
///parses all of the ld instructions
std::string first_argument;
std::string second_argument;
void compiler::ld()
{
    strip_first_ld_arg();
    strip_second_ld_arg();
    std::string opcode="";
    if(argument_register(first_argument)==true){
        std::string register_1=which_register(first_argument);
        if(second_argument=="DT"){
            opcode="F"+first_argument+"07";
            string_too_opcode(opcode);
        }else if(second_argument=="K"){
            opcode="F"+first_argument+"0A";
            string_too_opcode(opcode);
        }else if(second_argument=="[I]"){
            opcode="F"+first_argument+"65";
            string_too_opcode(opcode);
        }else{
            opcode="6"+first_argument+second_argument;
            string_too_opcode(opcode);
        }
    }else if(first_argument=="DT"){
        opcode="F"+second_argument+"15";
        string_too_opcode(opcode);
    }else if(first_argument=="ST"){
        opcode="F"+second_argument+"18";
        string_too_opcode(opcode);
    }else if(first_argument=="F"){
        opcode="F"+second_argument+"29";
        string_too_opcode(opcode);
    }else if(first_argument=="B"){
        opcode="F"+second_argument+"33";
        string_too_opcode(opcode);
    }else if(first_argument=="[I]"){
        opcode="F"+second_argument+"55";
        string_too_opcode(opcode);
    }else if(first_argument=="HF"){
        opcode="F"+second_argument+"30";
        string_too_opcode(opcode);
    }else if(first_argument=="R"){
        opcode="F"+second_argument+"75";
        string_too_opcode(opcode);
    }else if(second_argument=="R"){
        opcode="F"+second_argument+"85";
        string_too_opcode(opcode);
    }else{
        handle_error("unknown ld instruction");
    }
}
void compiler::strip_first_ld_arg()
{
    std::string temp="";
    for(unsigned int iii=3;iii<line.length();iii++){
        if(line[iii]==','){
            break;
        }else{
            temp+=line[iii];
        }
    }

}
void compiler::strip_second_ld_arg()
{
    unsigned int legnth=0;
    for(unsigned int iii=0;iii<line.length();iii++){
        if(line[iii]==','){
            break;
        }else{
            legnth+=1;
        }
    }
}
bool compiler::argument_register(std::string arg)
{
    if(arg=="V0"){
        return true;
    }else if(arg=="V1"){
        return true;
    }else if(arg=="V2"){
        return true;
    }else if(arg=="V3"){
        return true;
    }else if(arg=="V4"){
        return true;
    }else if(arg=="V5"){
        return true;
    }else if(arg=="V6"){
        return true;
    }else if(arg=="V7"){
        return true;
    }else if(arg=="V8"){
        return true;
    }else if(arg=="V9"){
        return true;
    }else if(arg=="VA"){
        return true;
    }else if(arg=="VB"){
        return true;
    }else if(arg=="VC"){
        return true;
    }else if(arg=="VD"){
        return true;
    }else if(arg=="VE"){
        return true;
    }else if(arg=="VF"){
        return true;
    }
    return false;
}
std::string compiler::which_register(std::string arg)
{
    if(arg=="V0"){
        return "0";
    }else if(arg=="V1"){
        return "1";
    }else if(arg=="V2"){
        return "2";
    }else if(arg=="V3"){
        return "3";
    }else if(arg=="V4"){
        return "4";
    }else if(arg=="V5"){
        return "5";
    }else if(arg=="V6"){
        return "6";
    }else if(arg=="V7"){
        return "7";
    }else if(arg=="V8"){
        return "8";
    }else if(arg=="V9"){
        return "9";
    }else if(arg=="VA"){
        return "A";
    }else if(arg=="VB"){
        return "B";
    }else if(arg=="VC"){
        return "C";
    }else if(arg=="VD"){
        return "D";
    }else if(arg=="VE"){
        return "E";
    }else if(arg=="VF"){
        return "F";
    }
    return "";
}
