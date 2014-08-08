#ifndef COMPILER_H_INCLUDED
#define COMPILER_H_INCLUDED
#include "file.h"
#include "compiler_error.h"
#include <vector>
#include <string>
class compiler{
    public:
        File* input_file;
        File* output_file;
        bool error;
        unsigned int line_number;
        std::vector<unsigned short> opcodes;
        std::vector<compiler_error> errors;
        std::string line;
        std::string instruction;
    public:
        compiler();
        void run();
        void inteperate_line();
        void get_next_line();
        void strip_instruction();
        void string_too_opcode(std::string opcode);
        void output();
        ///instructions
        ///instructions without arguments are done
        ///directly in inteperate_line()
        void sys();
        void jp();
        void call();
        void se();
        void sne();
        void ser();
        void add();
        void Or();
        void And();
        void Xor();
        void addr();
        void sub();
        void shr();
        void subn();
        void shl();
        void sner();
        void jpv();
        void rnd();
        void drw();
        void skp();
        void sknp();
        void addi();
        ///ld instructions and tools
        void ld();
        void strip_first_ld_arg();
        void strip_second_ld_arg();
        bool argument_register(std::string arg);
        std::string which_register(std::string arg);
        ///super chip instructions
        void scr();
        void scl();
        void exit();
        void low();
        void high();
        void drw0();
        void scd();
        ///error handling
        void handle_error(std::string message);
        void print_errors();
};
#endif // COMPILER_H_INCLUDED
