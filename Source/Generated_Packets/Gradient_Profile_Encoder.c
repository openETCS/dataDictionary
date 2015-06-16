
#include "Gradient_Profile_Encoder.h"
#include "Gradient_Profile_UpperBitsNotSet.h"
#include "Gradient_Profile_Core_1_Encoder.h"
#include "Bitstream_Write.h"

int Gradient_Profile_Encoder(Bitstream* stream, const Gradient_Profile_Core* p)
{
    if (NormalBitstream(stream, GRADIENT_PROFILE_CORE_BITSIZE))
    {
        if (Gradient_Profile_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_GRADIENT);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_A);
	    Bitstream_Write(stream, 5,  p->N_ITER);
	    Gradient_Profile_Core_1_Encoder(stream, p->sub_1, p->N_ITER);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_GRADIENT:        EqualBits(stream, pos + 17,  pos + 32,  p->D_GRADIENT);
            //@ assert Q_GDIR:            EqualBits(stream, pos + 32,  pos + 33,  p->Q_GDIR);
            //@ assert G_A:               EqualBits(stream, pos + 33,  pos + 41,  p->G_A);
            //@ assert N_ITER:            EqualBits(stream, pos + 41,  pos + 46,  p->N_ITER);

            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

