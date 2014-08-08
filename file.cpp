#include "file.h"
#include <iostream>
File::File()
{

}
File::File(std::string file_name)
{
    file.open(file_name);
    index=0;
    load_file();
    more=true;
}
std::string File::get_next_line()
{
    if(index<lines.size()){
        more=true;
        index+=1;
        return lines[index-1];
    }else{
        more=false;
        return "";
    }
}
void File::load_file()
{
    std::string line;
    while(getline(file,line)){
        lines.push_back(line);
    }
    file.close();
}
void File::output(std::vector<unsigned short> opcodes,std::string file_name)
{
    file.open(file_name,std::ios::binary);
    for(unsigned int iii=0;iii<opcodes.size();iii++){
        file<<opcodes[iii];
        std::cout<<opcodes[iii]<<"\n";
    }
    file.close();
}
