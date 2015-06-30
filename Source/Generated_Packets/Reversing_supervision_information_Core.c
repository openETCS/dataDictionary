
#include "Reversing_supervision_information_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Reversing_supervision_information_UpperBitsNotSet(const Reversing_supervision_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_REVERSE,         15);
    status = status && UpperBitsNotSet64(p->V_REVERSE,         7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Reversing_supervision_information_Encoder(Bitstream* stream, const Reversing_supervision_information_Core* p)
{
    if (NormalBitstream(stream, REVERSING_SUPERVISION_INFORMATION_CORE_BITSIZE))
    {
        if (Reversing_supervision_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_REVERSE);
            Bitstream_Write(stream, 7,  p->V_REVERSE);



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

int Reversing_supervision_information_Decoder(Bitstream* stream, Reversing_supervision_information_Core* p)
{
    if (NormalBitstream(stream, REVERSING_SUPERVISION_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_REVERSE		= Bitstream_Read(stream, 15); }

	{ p->V_REVERSE		= Bitstream_Read(stream, 7); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

