
#include "International_Static_Speed_Profile_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int International_Static_Speed_Profile_Core_1_UpperBitsNotSet(const International_Static_Speed_Profile_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIFF_n,          2) ;
    if (p->Q_DIFF_n == 0)
    {
    status = status && UpperBitsNotSet64(p->NC_CDDIFF_n,       4) ;
    }
    if ((p->Q_DIFF_n == 1) || (p->Q_DIFF_n == 2))
    {
    status = status && UpperBitsNotSet64(p->NC_DIFF_n,         4) ;
    }
    status = status && UpperBitsNotSet64(p->V_DIFF_n,          7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int International_Static_Speed_Profile_Core_1_Encoder(Bitstream* stream, const International_Static_Speed_Profile_Core_1* p)
{
    if (NormalBitstream(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_CORE_BITSIZE))
    {
        if (International_Static_Speed_Profile_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIFF_n);
            if (p->Q_DIFF_n == 0)
            {
            Bitstream_Write(stream, 4,  p->NC_CDDIFF_n);
            }

            if ((p->Q_DIFF_n == 1) || (p->Q_DIFF_n == 2))
            {
            Bitstream_Write(stream, 4,  p->NC_DIFF_n);
            }

            Bitstream_Write(stream, 7,  p->V_DIFF_n);


            //@ assert Q_DIFF_n:          EqualBits(stream, pos,       pos + 2,   p->Q_DIFF_n);

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

int International_Static_Speed_Profile_Core_1_Decoder(Bitstream* stream, International_Static_Speed_Profile_Core_1* p)
{
    if (NormalBitstream(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires Q_DIFF_n:       stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_DIFF_n;
	  ensures  Q_DIFF_n:       stream->bitpos == pos + 2;
	  ensures  Q_DIFF_n:       EqualBits(stream, pos + 0, pos + 2, p->Q_DIFF_n);
	  ensures  Q_DIFF_n:       UpperBitsNotSet(p->Q_DIFF_n, 2);
	*/
	{ p->Q_DIFF_n		= Bitstream_Read(stream, 2); }

        if (p->Q_DIFF_n == 0)
        {
	{ p->NC_CDDIFF_n		= Bitstream_Read(stream, 4); }
        }

        if ((p->Q_DIFF_n == 1) || (p->Q_DIFF_n == 2))
        {
	{ p->NC_DIFF_n		= Bitstream_Read(stream, 4); }
        }

	{ p->V_DIFF_n		= Bitstream_Read(stream, 7); }

        //@ assert Q_DIFF_n:          EqualBits(stream, pos,       pos + 2,   p->Q_DIFF_n);

        //@ assert Q_DIFF_n:          UpperBitsNotSet(p->Q_DIFF_n,          2);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

