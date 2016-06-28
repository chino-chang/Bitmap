#include "Bit.hpp"

uint8_t Bit::reverse(uint8_t data)
{
    data = ((data & 0x55) << 1) | ((data & 0xAA) >> 1);
    data = ((data & 0x33) << 2) | ((data & 0xCC) >> 2);
    data = (data << 4) | (data >> 4);
    return data;
}
