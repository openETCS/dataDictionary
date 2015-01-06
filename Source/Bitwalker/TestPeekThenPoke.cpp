
extern "C"
{
#include "PeekThenPoke.h"
}

#include <cstdlib>
#include <cassert>
#include <vector>
#include <iostream>

int main()
{
    const int BitstreamSize = 10;
    std::vector<uint8_t> Bitstream(BitstreamSize);

    uint32_t Start = 24;
    uint32_t Length = 21;

    Bitstream[3] = 182;
    Bitstream[4] = 237;

    std::vector<uint8_t> SaveBitstream = Bitstream;

    int result = PeekThenPoke(Bitstream.data(), BitstreamSize, Start, Length);

    assert(result == 0);
    assert(Bitstream == SaveBitstream);

    std::cout << "successful test of PeekThenPoke" << std::endl;

    return EXIT_SUCCESS;
}

