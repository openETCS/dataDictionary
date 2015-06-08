
#include <cstdint>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <iostream>

void Bitwalker_PeekThenPoke(uint8_t* addr, uint32_t size, uint32_t bitpos, uint32_t length);

int main()
{
    const int BitstreamSize = 10;
    std::vector<uint8_t> Bitstream(BitstreamSize);

    uint32_t Start = 24;
    uint32_t Length = 21;

    Bitstream[3] = 182;
    Bitstream[4] = 237;

    std::vector<uint8_t> SaveBitstream = Bitstream;

    Bitwalker_PeekThenPoke(Bitstream.data(), BitstreamSize, Start, Length);

    assert(Bitstream == SaveBitstream);

    std::cout << "successful test of PeekThenPoke" << std::endl;

    return EXIT_SUCCESS;
}

