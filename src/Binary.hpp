#include <cstdint>
#include <memory>

template <typename T>
class Binary
{
public:
    static T Binary<T>::convert(const std::unique_ptr<uint8_t[]>& binary, size_t size)
    {
        const int32_t Hex = 16 * 16;
        T value = 0;
        for (size_t i = 0; i < size; i++)
        {
            auto weight = static_cast<int32_t>(pow(Hex, i));
            value += (binary.get()[i] * weight);
        }
        return value;
    }
};
