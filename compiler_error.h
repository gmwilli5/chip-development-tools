#ifndef COMPILER_ERROR_H_INCLUDED
#define COMPILER_ERROR_H_INCLUDED
#include <string>
class compiler_error{
    public:
        std::string error_message;
        unsigned int line_number;
        std::string line;
    public:
        compiler_error(std::string error,unsigned int ln,std::string l);
        void print_error();
};
#endif // COMPILER_ERROR_H_INCLUDED
