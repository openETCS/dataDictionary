
#include "Geographical_Position_Information_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Geographical_Position_Information_Core_1_UpperBitsNotSet(const Geographical_Position_Information_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_k,    1) ;
    if (p->Q_NEWCOUNTRY_k == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C_k,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_k,          14);
    status = status && UpperBitsNotSet64(p->D_POSOFF_k,        15);
    status = status && UpperBitsNotSet64(p->Q_MPOSITION_k,     1) ;
    status = status && UpperBitsNotSet64(p->M_POSITION_k,      24);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Geographical_Position_Information_Core_1_Encoder(Bitstream* stream, const Geographical_Position_Information_Core_1* p)
{
    if (NormalBitstream(stream, GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_BITSIZE))
    {
        if (Geographical_Position_Information_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_k);
            if (p->Q_NEWCOUNTRY_k == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C_k);
            }

            Bitstream_Write(stream, 14, p->NID_BG_k);
            Bitstream_Write(stream, 15, p->D_POSOFF_k);
            Bitstream_Write(stream, 1,  p->Q_MPOSITION_k);
            Bitstream_Write(stream, 24, p->M_POSITION_k);


            //@ assert Q_NEWCOUNTRY_k:    EqualBits(stream, pos,       pos + 1,   p->Q_NEWCOUNTRY_k);

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

int Geographical_Position_Information_Core_1_Decoder(Bitstream* stream, Geographical_Position_Information_Core_1* p)
{
    if (NormalBitstream(stream, GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires Q_NEWCOUNTRY_k: stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NEWCOUNTRY_k;
	  ensures  Q_NEWCOUNTRY_k: stream->bitpos == pos + 1;
	  ensures  Q_NEWCOUNTRY_k: EqualBits(stream, pos + 0, pos + 1, p->Q_NEWCOUNTRY_k);
	  ensures  Q_NEWCOUNTRY_k: UpperBitsNotSet(p->Q_NEWCOUNTRY_k, 1);
	*/
	{ p->Q_NEWCOUNTRY_k		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY_k == 1)
        {
	{ p->NID_C_k		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG_k		= Bitstream_Read(stream, 14); }

	{ p->D_POSOFF_k		= Bitstream_Read(stream, 15); }

	{ p->Q_MPOSITION_k		= Bitstream_Read(stream, 1); }

	{ p->M_POSITION_k		= Bitstream_Read(stream, 24); }

        //@ assert Q_NEWCOUNTRY_k:    EqualBits(stream, pos,       pos + 1,   p->Q_NEWCOUNTRY_k);

        //@ assert Q_NEWCOUNTRY_k:    UpperBitsNotSet(p->Q_NEWCOUNTRY_k,    1);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

