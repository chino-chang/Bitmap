#include <iostream>

#include "Command.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "error" << std::endl;
        exit(1);
    }

    Command c{ argv[1] };
    c.run();
    return 0;
}
