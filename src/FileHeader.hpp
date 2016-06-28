#include <cstdint>

namespace FileHeader
{
    namespace Offset
    {
        static const size_t Signature{ 0 };
        static const size_t FileSize{ 2 };
        static const size_t Reserved1{ 6 };
        static const size_t Reserved2{ 8 };
        static const size_t OffsetToPixelArray{ 10 };
    };

    namespace Size
    {
        static const size_t Signature{ 2 };
        static const size_t FileSize{ 4 };
        static const size_t Reserved1{ 2 };
        static const size_t Reserved2{ 2 };
        static const size_t OffsetToPixelArray{ 4 };
    };
};
