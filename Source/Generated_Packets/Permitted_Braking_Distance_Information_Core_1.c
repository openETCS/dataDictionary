
#include "Permitted_Braking_Distance_Information_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet(const Permitted_Braking_Distance_Information_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_PBD_k,           15);
    status = status && UpperBitsNotSet64(p->Q_GDIR_k,          1) ;
    status = status && UpperBitsNotSet64(p->G_PBDSR_k,         8) ;
    status = status && UpperBitsNotSet64(p->Q_PBDSR_k,         1) ;
    status = status && UpperBitsNotSet64(p->D_PBDSR_k,         15);
    status = status && UpperBitsNotSet64(p->L_PBDSR_k,         15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Permitted_Braking_Distance_Information_Core_1_Encoder(Bitstream* stream, const Permitted_Braking_Distance_Information_Core_1* p)
{
    if (NormalBitstream(stream, PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE))
    {
        if (Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_PBD_k);
            Bitstream_Write(stream, 1,  p->Q_GDIR_k);
            Bitstream_Write(stream, 8,  p->G_PBDSR_k);
            Bitstream_Write(stream, 1,  p->Q_PBDSR_k);
            Bitstream_Write(stream, 15, p->D_PBDSR_k);
            Bitstream_Write(stream, 15, p->L_PBDSR_k);


            //@ assert D_PBD_k:           EqualBits(stream, pos,       pos + 15,  p->D_PBD_k);
            //@ assert Q_GDIR_k:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR_k);
            //@ assert G_PBDSR_k:         EqualBits(stream, pos + 16,  pos + 24,  p->G_PBDSR_k);
            //@ assert Q_PBDSR_k:         EqualBits(stream, pos + 24,  pos + 25,  p->Q_PBDSR_k);
            //@ assert D_PBDSR_k:         EqualBits(stream, pos + 25,  pos + 40,  p->D_PBDSR_k);
            //@ assert L_PBDSR_k:         EqualBits(stream, pos + 40,  pos + 55,  p->L_PBDSR_k);

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

int Permitted_Braking_Distance_Information_Core_1_Decoder(Bitstream* stream, Permitted_Braking_Distance_Information_Core_1* p)
{
    if (NormalBitstream(stream, PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires D_PBD_k:        stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_PBD_k;
	  ensures  D_PBD_k:        stream->bitpos == pos + 15;
	  ensures  D_PBD_k:        EqualBits(stream, pos + 0, pos + 15, p->D_PBD_k);
	  ensures  D_PBD_k:        UpperBitsNotSet(p->D_PBD_k, 15);
	*/
	{ p->D_PBD_k		= Bitstream_Read(stream, 15); }

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
	  requires G_PBDSR_k:      stream->bitpos == pos + 16;
	  assigns        	   stream->bitpos;
	  assigns		   p->G_PBDSR_k;
	  ensures  G_PBDSR_k:      stream->bitpos == pos + 24;
	  ensures  G_PBDSR_k:      EqualBits(stream, pos + 16, pos + 24, p->G_PBDSR_k);
	  ensures  G_PBDSR_k:      UpperBitsNotSet(p->G_PBDSR_k, 8);
	*/
	{ p->G_PBDSR_k		= Bitstream_Read(stream, 8); }

	/*@
	  requires Q_PBDSR_k:      stream->bitpos == pos + 24;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_PBDSR_k;
	  ensures  Q_PBDSR_k:      stream->bitpos == pos + 25;
	  ensures  Q_PBDSR_k:      EqualBits(stream, pos + 24, pos + 25, p->Q_PBDSR_k);
	  ensures  Q_PBDSR_k:      UpperBitsNotSet(p->Q_PBDSR_k, 1);
	*/
	{ p->Q_PBDSR_k		= Bitstream_Read(stream, 1); }

	/*@
	  requires D_PBDSR_k:      stream->bitpos == pos + 25;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_PBDSR_k;
	  ensures  D_PBDSR_k:      stream->bitpos == pos + 40;
	  ensures  D_PBDSR_k:      EqualBits(stream, pos + 25, pos + 40, p->D_PBDSR_k);
	  ensures  D_PBDSR_k:      UpperBitsNotSet(p->D_PBDSR_k, 15);
	*/
	{ p->D_PBDSR_k		= Bitstream_Read(stream, 15); }

	/*@
	  requires L_PBDSR_k:      stream->bitpos == pos + 40;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PBDSR_k;
	  ensures  L_PBDSR_k:      stream->bitpos == pos + 55;
	  ensures  L_PBDSR_k:      EqualBits(stream, pos + 40, pos + 55, p->L_PBDSR_k);
	  ensures  L_PBDSR_k:      UpperBitsNotSet(p->L_PBDSR_k, 15);
	*/
	{ p->L_PBDSR_k		= Bitstream_Read(stream, 15); }

        //@ assert D_PBD_k:           EqualBits(stream, pos,       pos + 15,  p->D_PBD_k);
        //@ assert Q_GDIR_k:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR_k);
        //@ assert G_PBDSR_k:         EqualBits(stream, pos + 16,  pos + 24,  p->G_PBDSR_k);
        //@ assert Q_PBDSR_k:         EqualBits(stream, pos + 24,  pos + 25,  p->Q_PBDSR_k);
        //@ assert D_PBDSR_k:         EqualBits(stream, pos + 25,  pos + 40,  p->D_PBDSR_k);
        //@ assert L_PBDSR_k:         EqualBits(stream, pos + 40,  pos + 55,  p->L_PBDSR_k);

        //@ assert D_PBD_k:           UpperBitsNotSet(p->D_PBD_k,           15);
        //@ assert Q_GDIR_k:          UpperBitsNotSet(p->Q_GDIR_k,          1);
        //@ assert G_PBDSR_k:         UpperBitsNotSet(p->G_PBDSR_k,         8);
        //@ assert Q_PBDSR_k:         UpperBitsNotSet(p->Q_PBDSR_k,         1);
        //@ assert D_PBDSR_k:         UpperBitsNotSet(p->D_PBDSR_k,         15);
        //@ assert L_PBDSR_k:         UpperBitsNotSet(p->L_PBDSR_k,         15);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

