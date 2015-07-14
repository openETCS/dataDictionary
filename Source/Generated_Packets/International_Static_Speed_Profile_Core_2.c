
#include "International_Static_Speed_Profile_Core_2.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int International_Static_Speed_Profile_Core_2_UpperBitsNotSet(const International_Static_Speed_Profile_Core_2* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_STATIC_k,        15);
    status = status && UpperBitsNotSet64(p->V_STATIC_k,        7) ;
    status = status && UpperBitsNotSet64(p->Q_FRONT_k,         1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_2_1,        5) ;
    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        status = status && International_Static_Speed_Profile_Core_2_1_UpperBitsNotSet(&(p->sub_2_1[i]));
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

int International_Static_Speed_Profile_Core_2_Encoder(Bitstream* stream, const International_Static_Speed_Profile_Core_2* p)
{
    if (NormalBitstream(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_CORE_BITSIZE))
    {
        if (International_Static_Speed_Profile_Core_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_STATIC_k);
            Bitstream_Write(stream, 7,  p->V_STATIC_k);
            Bitstream_Write(stream, 1,  p->Q_FRONT_k);
            Bitstream_Write(stream, 5,  p->N_ITER_2_1);
            for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
            {
                International_Static_Speed_Profile_Core_2_1_Encoder(stream, &(p->sub_2_1[i]));
            }


            //@ assert D_STATIC_k:        EqualBits(stream, pos,       pos + 15,  p->D_STATIC_k);
            //@ assert V_STATIC_k:        EqualBits(stream, pos + 15,  pos + 22,  p->V_STATIC_k);
            //@ assert Q_FRONT_k:         EqualBits(stream, pos + 22,  pos + 23,  p->Q_FRONT_k);

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

int International_Static_Speed_Profile_Core_2_Decoder(Bitstream* stream, International_Static_Speed_Profile_Core_2* p)
{
    if (NormalBitstream(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires D_STATIC_k:     stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_STATIC_k;
	  ensures  D_STATIC_k:     stream->bitpos == pos + 15;
	  ensures  D_STATIC_k:     EqualBits(stream, pos + 0, pos + 15, p->D_STATIC_k);
	  ensures  D_STATIC_k:     UpperBitsNotSet(p->D_STATIC_k, 15);
	*/
	{ p->D_STATIC_k		= Bitstream_Read(stream, 15); }

	/*@
	  requires V_STATIC_k:     stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_STATIC_k;
	  ensures  V_STATIC_k:     stream->bitpos == pos + 22;
	  ensures  V_STATIC_k:     EqualBits(stream, pos + 15, pos + 22, p->V_STATIC_k);
	  ensures  V_STATIC_k:     UpperBitsNotSet(p->V_STATIC_k, 7);
	*/
	{ p->V_STATIC_k		= Bitstream_Read(stream, 7); }

	/*@
	  requires Q_FRONT_k:      stream->bitpos == pos + 22;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_FRONT_k;
	  ensures  Q_FRONT_k:      stream->bitpos == pos + 23;
	  ensures  Q_FRONT_k:      EqualBits(stream, pos + 22, pos + 23, p->Q_FRONT_k);
	  ensures  Q_FRONT_k:      UpperBitsNotSet(p->Q_FRONT_k, 1);
	*/
	{ p->Q_FRONT_k		= Bitstream_Read(stream, 1); }

	{ p->N_ITER_2_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
        {
            International_Static_Speed_Profile_Core_2_1_Decoder(stream, &(p->sub_2_1[i]));
        }
        //@ assert D_STATIC_k:        EqualBits(stream, pos,       pos + 15,  p->D_STATIC_k);
        //@ assert V_STATIC_k:        EqualBits(stream, pos + 15,  pos + 22,  p->V_STATIC_k);
        //@ assert Q_FRONT_k:         EqualBits(stream, pos + 22,  pos + 23,  p->Q_FRONT_k);

        //@ assert D_STATIC_k:        UpperBitsNotSet(p->D_STATIC_k,        15);
        //@ assert V_STATIC_k:        UpperBitsNotSet(p->V_STATIC_k,        7);
        //@ assert Q_FRONT_k:         UpperBitsNotSet(p->Q_FRONT_k,         1);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

