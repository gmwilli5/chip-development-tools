#include <iostream>
#include "compiler_error.h"
compiler_error::compiler_error(std::string error,unsigned int ln,std::string l)
{
    error_message=error;
    line=l;
    line_number=ln;
}
void compiler_error::print_error()
{
    std::cout<<"line "<<line_number<<": "<<error_message<<"\n";
    std::cout<<"line "<<line_number<<": "<<line<<"\n";
}
