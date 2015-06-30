
#include "Linking_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Linking_UpperBitsNotSet(const Linking_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_LINK,            15);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;
    if (p->Q_NEWCOUNTRY == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG,            14);
    status = status && UpperBitsNotSet64(p->Q_LINKORIENTATION, 1) ;
    status = status && UpperBitsNotSet64(p->Q_LINKREACTION,    2) ;
    status = status && UpperBitsNotSet64(p->Q_LOCACC,          6) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Linking_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Linking_Encoder(Bitstream* stream, const Linking_Core* p)
{
    if (NormalBitstream(stream, LINKING_CORE_BITSIZE))
    {
        if (Linking_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_LINK);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);
            Bitstream_Write(stream, 1,  p->Q_LINKORIENTATION);
            Bitstream_Write(stream, 2,  p->Q_LINKREACTION);
            Bitstream_Write(stream, 6,  p->Q_LOCACC);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Linking_Core_1_Encoder(stream, &(p->sub_1[i]));
            }



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

int Linking_Decoder(Bitstream* stream, Linking_Core* p)
{
    if (NormalBitstream(stream, LINKING_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->D_LINK		= Bitstream_Read(stream, 15); }

	{ p->Q_NEWCOUNTRY		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY == 1)
        {
	{ p->NID_C		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG		= Bitstream_Read(stream, 14); }

	{ p->Q_LINKORIENTATION		= Bitstream_Read(stream, 1); }

	{ p->Q_LINKREACTION		= Bitstream_Read(stream, 2); }

	{ p->Q_LOCACC		= Bitstream_Read(stream, 6); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Linking_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

