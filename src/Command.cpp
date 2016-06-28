#include <iostream>

#include "Command.hpp"

Command::Command(const char* path)
{
    bitmap = std::make_unique<Bitmap>(path);
}


void Command::run()
{
    for (;;)
    {
        int command;
        std::cout << "please enter command id : ";
        std::cin >> command;

        switch (static_cast<Type>(command))
        {
        case Type::Fill: execFill(); break;
        case Type::Save: execSave(); break;
        case Type::Exit: return;
        }
    }
}


void Command::execFill()
{
    Pixel pixel;

    std::cout << "please enter rgb rate :" << std::endl;
    std::cout << "r : ";
    std::cin >> pixel.r;
    std::cout << "g : ";
    std::cin >> pixel.g;
    std::cout << "b : ";
    std::cin >> pixel.b;

    const int32_t width = bitmap->getWidth();
    const int32_t height = bitmap->getHeight();

    for (int32_t x = 0; x < width; x++)
    {
        for (int32_t y = 0; y < height; y++)
        {
            bitmap->setPixel(x, y, pixel);
        }
    }
}


void Command::execSave()
{
    std::unique_ptr<char> path{ new char };
    std::cout << "please enter save path :";
    std::cin >> path.get();

    bitmap->output(path);
}
