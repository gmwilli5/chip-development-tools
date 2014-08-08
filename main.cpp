#include <iostream>
#include "compiler.h"
int main()
{
    std::cout<<sizeof(unsigned short)<<"\n";
    compiler c;
    c.run();
}
