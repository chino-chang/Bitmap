#include "Bitmap.hpp"

uint32_t Bitmap::getFileSize()
{
    const size_t offset = FileHeader::Offset::FileSize;
    const size_t size = FileHeader::Size::FileSize;

    const auto binary = read(offset, size);
    return Binary<uint32_t>::convert(binary, size);
}


uint32_t Bitmap::getOffsetToPixelArray()
{
    const size_t offset = FileHeader::Offset::OffsetToPixelArray;
    const size_t size = FileHeader::Size::OffsetToPixelArray;

    const auto binary = read(offset, size);
    return Binary<uint32_t>::convert(binary, size);
}


int32_t Bitmap::getWidth()
{
    const size_t offset = DIBHeader::Offset::ImageWidth;
    const size_t size = DIBHeader::Size::ImageWidth;

    const auto binary = read(offset, size);
    return Binary<int32_t>::convert(binary, size);
}


int32_t Bitmap::getHeight()
{
    const size_t offset = DIBHeader::Offset::ImageHeight;
    const size_t size = DIBHeader::Size::ImageHeight;

    const auto binary = read(offset, size);
    return Binary<int32_t>::convert(binary, size);
}


uint16_t Bitmap::getBitPerPixel()
{
    const size_t offset = DIBHeader::Offset::BitPerPixel;
    const size_t size = DIBHeader::Size::BitPerPixel;

    const auto binary = read(offset, size);
    return Binary<uint16_t>::convert(binary, size);
}


uint16_t Bitmap::getBytePerPixel()
{
    const uint32_t Bit = 8;
    return this->getBitPerPixel() / Bit;
}


Pixel Bitmap::getPixel(uint32_t x, uint32_t y)
{
    const size_t offset = static_cast<size_t>(getOffsetToPixelArray() + getPosition(x, y));
    const size_t size = getBytePerPixel();

    const auto binary = read(offset, size);

    Pixel p;
    p.r = Bit::reverse(binary.get()[2]);
    p.g = Bit::reverse(binary.get()[1]);
    p.b = Bit::reverse(binary.get()[0]);
    p.a = 0;
    return p;
}


void Bitmap::setPixel(uint32_t x, uint32_t y, Pixel color)
{
    const size_t offset = static_cast<size_t>(getOffsetToPixelArray() + getPosition(x, y));

    uint8_t vr = static_cast<uint8_t>(RGB888::Size::R * color.r);
    uint8_t vg = static_cast<uint8_t>(RGB888::Size::G * color.g);
    uint8_t vb = static_cast<uint8_t>(RGB888::Size::B * color.b);

    write(offset + 0, Bit::reverse(vb));
    write(offset + 1, Bit::reverse(vg));
    write(offset + 2, Bit::reverse(vr));
}


size_t Bitmap::getPosition(uint32_t x, uint32_t y)
{
    const uint16_t BPP = getBytePerPixel();
    return x * BPP + y * getWidth() * BPP;
}