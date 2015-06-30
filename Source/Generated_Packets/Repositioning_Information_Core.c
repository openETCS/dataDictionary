
#include "Repositioning_Information_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Repositioning_Information_UpperBitsNotSet(const Repositioning_Information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->L_SECTION,         15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Repositioning_Information_Encoder(Bitstream* stream, const Repositioning_Information_Core* p)
{
    if (NormalBitstream(stream, REPOSITIONING_INFORMATION_CORE_BITSIZE))
    {
        if (Repositioning_Information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->L_SECTION);



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

int Repositioning_Information_Decoder(Bitstream* stream, Repositioning_Information_Core* p)
{
    if (NormalBitstream(stream, REPOSITIONING_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->L_SECTION		= Bitstream_Read(stream, 15); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

