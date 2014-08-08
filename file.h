#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include <fstream>
#include <string>
#include <vector>
class File{
    public:
        std::fstream file;
        std::vector<std::string> lines;
        bool more;
        unsigned int index;
    public:
        File();
        File(std::string file_name);
        std::string get_next_line();
        void load_file();
        void output(std::vector<unsigned short> opcodes,std::string file_name);
};
#endif // FILE_H_INCLUDED
