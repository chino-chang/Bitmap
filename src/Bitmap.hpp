#include <bitset>
#include <cstdint>

#include "Binary.hpp"
#include "Bit.hpp"
#include "Blob.hpp"
#include "FileHeader.hpp"
#include "DIBHeader.hpp"
#include "Pixel.hpp"

class Bitmap : public Blob
{
private:
    size_t getPosition(uint32_t x, uint32_t y);

public:
    Bitmap(const char* filePath) : Blob{ filePath }{}

    uint32_t getFileSize();

    uint32_t getOffsetToPixelArray();

    int32_t getWidth();

    int32_t getHeight();

    uint16_t getBitPerPixel();

    uint16_t getBytePerPixel();

    Pixel getPixel(uint32_t x, uint32_t y);

    void setPixel(uint32_t x, uint32_t y, Pixel color);
};

