#include <memory>

#include "Bitmap.hpp"

class Command
{
private:
    enum Type
    {
        Save = 1,
        Fill = 2,
        Exit = 99,
    };

    std::unique_ptr<Bitmap> bitmap;

    void execFill();

    void execSave();

public:
    Command(const char* path);

    virtual ~Command(){}

    void run();
};
