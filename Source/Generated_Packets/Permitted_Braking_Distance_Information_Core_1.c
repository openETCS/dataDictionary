
#include "Permitted_Braking_Distance_Information_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet(const Permitted_Braking_Distance_Information_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_PBD,             15);
    status = status && UpperBitsNotSet64(p->Q_GDIR,            1) ;
    status = status && UpperBitsNotSet64(p->G_PBDSR,           8) ;
    status = status && UpperBitsNotSet64(p->Q_PBDSR,           1) ;
    status = status && UpperBitsNotSet64(p->D_PBDSR,           15);
    status = status && UpperBitsNotSet64(p->L_PBDSR,           15);

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

            Bitstream_Write(stream, 15, p->D_PBD);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_PBDSR);
            Bitstream_Write(stream, 1,  p->Q_PBDSR);
            Bitstream_Write(stream, 15, p->D_PBDSR);
            Bitstream_Write(stream, 15, p->L_PBDSR);


            //@ assert D_PBD:             EqualBits(stream, pos,       pos + 15,  p->D_PBD);
            //@ assert Q_GDIR:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR);
            //@ assert G_PBDSR:           EqualBits(stream, pos + 16,  pos + 24,  p->G_PBDSR);
            //@ assert Q_PBDSR:           EqualBits(stream, pos + 24,  pos + 25,  p->Q_PBDSR);
            //@ assert D_PBDSR:           EqualBits(stream, pos + 25,  pos + 40,  p->D_PBDSR);
            //@ assert L_PBDSR:           EqualBits(stream, pos + 40,  pos + 55,  p->L_PBDSR);

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
	  requires D_PBD:          stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_PBD;
	  ensures  D_PBD:          stream->bitpos == pos + 15;
	  ensures  D_PBD:          EqualBits(stream, pos + 0, pos + 15, p->D_PBD);
	  ensures  D_PBD:          UpperBitsNotSet(p->D_PBD, 15);
	*/
	{ p->D_PBD		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_GDIR:         stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_GDIR;
	  ensures  Q_GDIR:         stream->bitpos == pos + 16;
	  ensures  Q_GDIR:         EqualBits(stream, pos + 15, pos + 16, p->Q_GDIR);
	  ensures  Q_GDIR:         UpperBitsNotSet(p->Q_GDIR, 1);
	*/
	{ p->Q_GDIR		= Bitstream_Read(stream, 1); }

	/*@
	  requires G_PBDSR:        stream->bitpos == pos + 16;
	  assigns        	   stream->bitpos;
	  assigns		   p->G_PBDSR;
	  ensures  G_PBDSR:        stream->bitpos == pos + 24;
	  ensures  G_PBDSR:        EqualBits(stream, pos + 16, pos + 24, p->G_PBDSR);
	  ensures  G_PBDSR:        UpperBitsNotSet(p->G_PBDSR, 8);
	*/
	{ p->G_PBDSR		= Bitstream_Read(stream, 8); }

	/*@
	  requires Q_PBDSR:        stream->bitpos == pos + 24;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_PBDSR;
	  ensures  Q_PBDSR:        stream->bitpos == pos + 25;
	  ensures  Q_PBDSR:        EqualBits(stream, pos + 24, pos + 25, p->Q_PBDSR);
	  ensures  Q_PBDSR:        UpperBitsNotSet(p->Q_PBDSR, 1);
	*/
	{ p->Q_PBDSR		= Bitstream_Read(stream, 1); }

	/*@
	  requires D_PBDSR:        stream->bitpos == pos + 25;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_PBDSR;
	  ensures  D_PBDSR:        stream->bitpos == pos + 40;
	  ensures  D_PBDSR:        EqualBits(stream, pos + 25, pos + 40, p->D_PBDSR);
	  ensures  D_PBDSR:        UpperBitsNotSet(p->D_PBDSR, 15);
	*/
	{ p->D_PBDSR		= Bitstream_Read(stream, 15); }

	/*@
	  requires L_PBDSR:        stream->bitpos == pos + 40;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PBDSR;
	  ensures  L_PBDSR:        stream->bitpos == pos + 55;
	  ensures  L_PBDSR:        EqualBits(stream, pos + 40, pos + 55, p->L_PBDSR);
	  ensures  L_PBDSR:        UpperBitsNotSet(p->L_PBDSR, 15);
	*/
	{ p->L_PBDSR		= Bitstream_Read(stream, 15); }

        //@ assert D_PBD:             EqualBits(stream, pos,       pos + 15,  p->D_PBD);
        //@ assert Q_GDIR:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR);
        //@ assert G_PBDSR:           EqualBits(stream, pos + 16,  pos + 24,  p->G_PBDSR);
        //@ assert Q_PBDSR:           EqualBits(stream, pos + 24,  pos + 25,  p->Q_PBDSR);
        //@ assert D_PBDSR:           EqualBits(stream, pos + 25,  pos + 40,  p->D_PBDSR);
        //@ assert L_PBDSR:           EqualBits(stream, pos + 40,  pos + 55,  p->L_PBDSR);

        //@ assert D_PBD:             UpperBitsNotSet(p->D_PBD,             15);
        //@ assert Q_GDIR:            UpperBitsNotSet(p->Q_GDIR,            1);
        //@ assert G_PBDSR:           UpperBitsNotSet(p->G_PBDSR,           8);
        //@ assert Q_PBDSR:           UpperBitsNotSet(p->Q_PBDSR,           1);
        //@ assert D_PBDSR:           UpperBitsNotSet(p->D_PBDSR,           15);
        //@ assert L_PBDSR:           UpperBitsNotSet(p->L_PBDSR,           15);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

