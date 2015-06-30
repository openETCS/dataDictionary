
#include "Reversing_area_information_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Reversing_area_information_UpperBitsNotSet(const Reversing_area_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_STARTREVERSE,    15);
    status = status && UpperBitsNotSet64(p->L_REVERSEAREA,     15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Reversing_area_information_Encoder(Bitstream* stream, const Reversing_area_information_Core* p)
{
    if (NormalBitstream(stream, REVERSING_AREA_INFORMATION_CORE_BITSIZE))
    {
        if (Reversing_area_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_STARTREVERSE);
            Bitstream_Write(stream, 15, p->L_REVERSEAREA);



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

int Reversing_area_information_Decoder(Bitstream* stream, Reversing_area_information_Core* p)
{
    if (NormalBitstream(stream, REVERSING_AREA_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_STARTREVERSE		= Bitstream_Read(stream, 15); }

	{ p->L_REVERSEAREA		= Bitstream_Read(stream, 15); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

