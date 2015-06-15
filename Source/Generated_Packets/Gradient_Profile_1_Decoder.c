
#include "Gradient_Profile_1_Decoder.h"
#include "Bitstream_Read.h"

int Gradient_Profile_1_Decoder(Bitstream* stream, Gradient_Profile_1* p, uint8_t N_ITER)
{
	for (uint32_t i = 0; i < N_ITER; ++i)
	{
	    { p[i].D_GRADIENT	= Bitstream_Read(stream, 15); }
	    { p[i].Q_GDIR	= Bitstream_Read(stream, 1); }
	    { p[i].G_A		= Bitstream_Read(stream, 8); }
	}

        return 1;
}

