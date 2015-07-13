
#include "Gradient_Profile_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Gradient_Profile_Core_1_UpperBitsNotSet(const Gradient_Profile_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_GRADIENT_k,      15);
    status = status && UpperBitsNotSet64(p->Q_GDIR_k,          1) ;
    status = status && UpperBitsNotSet64(p->G_A_k,             8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Gradient_Profile_Core_1_Encoder(Bitstream* stream, const Gradient_Profile_Core_1* p)
{
    if (NormalBitstream(stream, GRADIENT_PROFILE_CORE_1_CORE_BITSIZE))
    {
        if (Gradient_Profile_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_GRADIENT_k);
            Bitstream_Write(stream, 1,  p->Q_GDIR_k);
            Bitstream_Write(stream, 8,  p->G_A_k);


            //@ assert D_GRADIENT_k:      EqualBits(stream, pos,       pos + 15,  p->D_GRADIENT_k);
            //@ assert Q_GDIR_k:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR_k);
            //@ assert G_A_k:             EqualBits(stream, pos + 16,  pos + 24,  p->G_A_k);

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

int Gradient_Profile_Core_1_Decoder(Bitstream* stream, Gradient_Profile_Core_1* p)
{
    if (NormalBitstream(stream, GRADIENT_PROFILE_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires D_GRADIENT_k:   stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_GRADIENT_k;
	  ensures  D_GRADIENT_k:   stream->bitpos == pos + 15;
	  ensures  D_GRADIENT_k:   EqualBits(stream, pos + 0, pos + 15, p->D_GRADIENT_k);
	  ensures  D_GRADIENT_k:   UpperBitsNotSet(p->D_GRADIENT_k, 15);
	*/
	{ p->D_GRADIENT_k		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_GDIR_k:       stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_GDIR_k;
	  ensures  Q_GDIR_k:       stream->bitpos == pos + 16;
	  ensures  Q_GDIR_k:       EqualBits(stream, pos + 15, pos + 16, p->Q_GDIR_k);
	  ensures  Q_GDIR_k:       UpperBitsNotSet(p->Q_GDIR_k, 1);
	*/
	{ p->Q_GDIR_k		= Bitstream_Read(stream, 1); }

	/*@
	  requires G_A_k:          stream->bitpos == pos + 16;
	  assigns        	   stream->bitpos;
	  assigns		   p->G_A_k;
	  ensures  G_A_k:          stream->bitpos == pos + 24;
	  ensures  G_A_k:          EqualBits(stream, pos + 16, pos + 24, p->G_A_k);
	  ensures  G_A_k:          UpperBitsNotSet(p->G_A_k, 8);
	*/
	{ p->G_A_k		= Bitstream_Read(stream, 8); }

        //@ assert D_GRADIENT_k:      EqualBits(stream, pos,       pos + 15,  p->D_GRADIENT_k);
        //@ assert Q_GDIR_k:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR_k);
        //@ assert G_A_k:             EqualBits(stream, pos + 16,  pos + 24,  p->G_A_k);

        //@ assert D_GRADIENT_k:      UpperBitsNotSet(p->D_GRADIENT_k,      15);
        //@ assert Q_GDIR_k:          UpperBitsNotSet(p->Q_GDIR_k,          1);
        //@ assert G_A_k:             UpperBitsNotSet(p->G_A_k,             8);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

