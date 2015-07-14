
#include "Mode_profile_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Mode_profile_Core_1_UpperBitsNotSet(const Mode_profile_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_MAMODE_k,        15);
    status = status && UpperBitsNotSet64(p->M_MAMODE_k,        2) ;
    status = status && UpperBitsNotSet64(p->V_MAMODE_k,        7) ;
    status = status && UpperBitsNotSet64(p->L_MAMODE_k,        15);
    status = status && UpperBitsNotSet64(p->L_ACKMAMODE_k,     15);
    status = status && UpperBitsNotSet64(p->Q_MAMODE_k,        1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Mode_profile_Core_1_Encoder(Bitstream* stream, const Mode_profile_Core_1* p)
{
    if (NormalBitstream(stream, MODE_PROFILE_CORE_1_CORE_BITSIZE))
    {
        if (Mode_profile_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_MAMODE_k);
            Bitstream_Write(stream, 2,  p->M_MAMODE_k);
            Bitstream_Write(stream, 7,  p->V_MAMODE_k);
            Bitstream_Write(stream, 15, p->L_MAMODE_k);
            Bitstream_Write(stream, 15, p->L_ACKMAMODE_k);
            Bitstream_Write(stream, 1,  p->Q_MAMODE_k);


            //@ assert D_MAMODE_k:        EqualBits(stream, pos,       pos + 15,  p->D_MAMODE_k);
            //@ assert M_MAMODE_k:        EqualBits(stream, pos + 15,  pos + 17,  p->M_MAMODE_k);
            //@ assert V_MAMODE_k:        EqualBits(stream, pos + 17,  pos + 24,  p->V_MAMODE_k);
            //@ assert L_MAMODE_k:        EqualBits(stream, pos + 24,  pos + 39,  p->L_MAMODE_k);
            //@ assert L_ACKMAMODE_k:     EqualBits(stream, pos + 39,  pos + 54,  p->L_ACKMAMODE_k);
            //@ assert Q_MAMODE_k:        EqualBits(stream, pos + 54,  pos + 55,  p->Q_MAMODE_k);

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

int Mode_profile_Core_1_Decoder(Bitstream* stream, Mode_profile_Core_1* p)
{
    if (NormalBitstream(stream, MODE_PROFILE_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires D_MAMODE_k:     stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_MAMODE_k;
	  ensures  D_MAMODE_k:     stream->bitpos == pos + 15;
	  ensures  D_MAMODE_k:     EqualBits(stream, pos + 0, pos + 15, p->D_MAMODE_k);
	  ensures  D_MAMODE_k:     UpperBitsNotSet(p->D_MAMODE_k, 15);
	*/
	{ p->D_MAMODE_k		= Bitstream_Read(stream, 15); }

	/*@
	  requires M_MAMODE_k:     stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_MAMODE_k;
	  ensures  M_MAMODE_k:     stream->bitpos == pos + 17;
	  ensures  M_MAMODE_k:     EqualBits(stream, pos + 15, pos + 17, p->M_MAMODE_k);
	  ensures  M_MAMODE_k:     UpperBitsNotSet(p->M_MAMODE_k, 2);
	*/
	{ p->M_MAMODE_k		= Bitstream_Read(stream, 2); }

	/*@
	  requires V_MAMODE_k:     stream->bitpos == pos + 17;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_MAMODE_k;
	  ensures  V_MAMODE_k:     stream->bitpos == pos + 24;
	  ensures  V_MAMODE_k:     EqualBits(stream, pos + 17, pos + 24, p->V_MAMODE_k);
	  ensures  V_MAMODE_k:     UpperBitsNotSet(p->V_MAMODE_k, 7);
	*/
	{ p->V_MAMODE_k		= Bitstream_Read(stream, 7); }

	/*@
	  requires L_MAMODE_k:     stream->bitpos == pos + 24;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_MAMODE_k;
	  ensures  L_MAMODE_k:     stream->bitpos == pos + 39;
	  ensures  L_MAMODE_k:     EqualBits(stream, pos + 24, pos + 39, p->L_MAMODE_k);
	  ensures  L_MAMODE_k:     UpperBitsNotSet(p->L_MAMODE_k, 15);
	*/
	{ p->L_MAMODE_k		= Bitstream_Read(stream, 15); }

	/*@
	  requires L_ACKMAMODE_k:  stream->bitpos == pos + 39;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_ACKMAMODE_k;
	  ensures  L_ACKMAMODE_k:  stream->bitpos == pos + 54;
	  ensures  L_ACKMAMODE_k:  EqualBits(stream, pos + 39, pos + 54, p->L_ACKMAMODE_k);
	  ensures  L_ACKMAMODE_k:  UpperBitsNotSet(p->L_ACKMAMODE_k, 15);
	*/
	{ p->L_ACKMAMODE_k		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_MAMODE_k:     stream->bitpos == pos + 54;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_MAMODE_k;
	  ensures  Q_MAMODE_k:     stream->bitpos == pos + 55;
	  ensures  Q_MAMODE_k:     EqualBits(stream, pos + 54, pos + 55, p->Q_MAMODE_k);
	  ensures  Q_MAMODE_k:     UpperBitsNotSet(p->Q_MAMODE_k, 1);
	*/
	{ p->Q_MAMODE_k		= Bitstream_Read(stream, 1); }

        //@ assert D_MAMODE_k:        EqualBits(stream, pos,       pos + 15,  p->D_MAMODE_k);
        //@ assert M_MAMODE_k:        EqualBits(stream, pos + 15,  pos + 17,  p->M_MAMODE_k);
        //@ assert V_MAMODE_k:        EqualBits(stream, pos + 17,  pos + 24,  p->V_MAMODE_k);
        //@ assert L_MAMODE_k:        EqualBits(stream, pos + 24,  pos + 39,  p->L_MAMODE_k);
        //@ assert L_ACKMAMODE_k:     EqualBits(stream, pos + 39,  pos + 54,  p->L_ACKMAMODE_k);
        //@ assert Q_MAMODE_k:        EqualBits(stream, pos + 54,  pos + 55,  p->Q_MAMODE_k);

        //@ assert D_MAMODE_k:        UpperBitsNotSet(p->D_MAMODE_k,        15);
        //@ assert M_MAMODE_k:        UpperBitsNotSet(p->M_MAMODE_k,        2);
        //@ assert V_MAMODE_k:        UpperBitsNotSet(p->V_MAMODE_k,        7);
        //@ assert L_MAMODE_k:        UpperBitsNotSet(p->L_MAMODE_k,        15);
        //@ assert L_ACKMAMODE_k:     UpperBitsNotSet(p->L_ACKMAMODE_k,     15);
        //@ assert Q_MAMODE_k:        UpperBitsNotSet(p->Q_MAMODE_k,        1);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

