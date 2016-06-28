namespace DIBHeader
{
    namespace Offset
    {
        static const size_t DIBHeaderSize{ 14 };
        static const size_t ImageWidth{ 18 };
        static const size_t ImageHeight{ 22 };
        static const size_t Planes{ 26 };
        static const size_t BitPerPixel{ 28 };
        static const size_t Compression{ 30 };
        static const size_t ImageSize{ 34 };
        static const size_t XPixelsPerMeter{ 38 };
        static const size_t YPixelsPerMeter{ 42 };
        static const size_t ColorsInColorTable{ 46 };
        static const size_t ImportantColorCount{ 50 };
    }

    namespace Size
    {
        static const size_t DIBHeaderSize{ 4 };
        static const size_t ImageWidth{ 4 };
        static const size_t ImageHeight{ 4 };
        static const size_t Planes{ 2 };
        static const size_t BitPerPixel{ 2 };
        static const size_t Compression{ 4 };
        static const size_t ImageSize{ 4 };
        static const size_t XPixelsPerMeter{ 4 };
        static const size_t YPixelsPerMeter{ 4 };
        static const size_t ColorsInColorTable{ 4 };
        static const size_t ImportantColorCount{ 4 };
    }
}
