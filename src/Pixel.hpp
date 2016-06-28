#include <cstdint>

#define SIZE(x) static_cast<uint32_t>(pow(2, x)) - 1

namespace RGB888
{
    namespace Bit
    {
        static const uint32_t R{ 8 };
        static const uint32_t G{ 8 };
        static const uint32_t B{ 8 };
        static const uint32_t A{ 0 };
    }
    namespace Size
    {
        static const uint32_t R{ SIZE(Bit::R) };
        static const uint32_t G{ SIZE(Bit::G) };
        static const uint32_t B{ SIZE(Bit::B) };
        static const uint32_t A{ SIZE(Bit::A) };
    }
};


struct Pixel
{
public:
    float_t r;
    float_t g;
    float_t b;
    float_t a;
};
