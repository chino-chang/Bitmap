#include <bitset>
#include <fstream>
#include <memory>
#include <vector>

#define ERROR "error"

class Blob
{
private:
    std::vector<char> binary;

    bool isRange(size_t length);

public:
    Blob(const char* path);

    virtual ~Blob() = default;

    size_t getSize();

    uint8_t read(size_t offset);

    std::unique_ptr<uint8_t[]> read(size_t offset, size_t size);

    void write(size_t offset, uint8_t byte);

    void output(const std::unique_ptr<char>& path);
};
