#include "Blob.hpp"

Blob::Blob(const char* path)
{
    std::ifstream stream{ path, std::ios::in | std::ios::binary };
    if (!stream)
    {
        throw std::runtime_error{ ERROR };
    }

    stream.seekg(0, std::ios::end);
    size_t length = static_cast<size_t>(stream.tellg());
    binary.resize(length);

    stream.seekg(0, std::ios::beg);
    stream.read(&binary.front(), length);
    stream.close();
}


bool Blob::isRange(const size_t length)
{
    return length <= getSize();
}


size_t Blob::getSize()
{
    return binary.size();
}


uint8_t Blob::read(const size_t offset)
{
    if (!isRange(offset))
    {
        throw std::invalid_argument{ ERROR };
    }
    return static_cast<uint8_t>(binary[offset]);
}


std::unique_ptr<uint8_t[]> Blob::read(const size_t offset, const size_t size)
{
    std::unique_ptr<uint8_t[]> block{ new uint8_t[size] };
    for (size_t i = 0; i < size; i++)
    {
        block[i] = read(offset + i);
    }
    return block;
}


void Blob::write(const size_t offset, const uint8_t data)
{
    if (!isRange(offset))
    {
        throw std::invalid_argument{ ERROR };
    }
    binary[offset] = static_cast<char>(data);
}


void Blob::output(const std::unique_ptr<char>& path)
{
    std::ofstream stream{ path.get() };
    if (!stream)
    {
        throw std::runtime_error{ ERROR };
    }
    for (size_t i = 0; i < getSize(); i++)
    {
        stream << binary[i];
    }
    stream.close();
}
