
#include "Gradient_Profile_1_Encoder.h"
#include "Bitstream_Write.h"

int Gradient_Profile_1_Encoder(Bitstream* stream, const Gradient_Profile_1* p, uint8_t N_ITER)
{
    //@ ghost const uint32_t pos = stream->bitpos;

    for (uint32_t i = 0; i < N_ITER; ++i)
    {
        Bitstream_Write(stream, 15, p[i].D_GRADIENT);
        Bitstream_Write(stream, 1,  p[i].Q_GDIR);
        Bitstream_Write(stream, 8,  p[i].G_A);
    }
	
    return 1;
}

