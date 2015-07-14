
#include "Level_Transition_Order_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Level_Transition_Order_Core_1_UpperBitsNotSet(const Level_Transition_Order_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->M_LEVELTR_k,       3) ;
    if (p->M_LEVELTR_k == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_NTC_k,         8) ;
    }
    status = status && UpperBitsNotSet64(p->L_ACKLEVELTR_k,    15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Level_Transition_Order_Core_1_Encoder(Bitstream* stream, const Level_Transition_Order_Core_1* p)
{
    if (NormalBitstream(stream, LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE))
    {
        if (Level_Transition_Order_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 3,  p->M_LEVELTR_k);
            if (p->M_LEVELTR_k == 1)
            {
            Bitstream_Write(stream, 8,  p->NID_NTC_k);
            }

            Bitstream_Write(stream, 15, p->L_ACKLEVELTR_k);


            //@ assert M_LEVELTR_k:       EqualBits(stream, pos,       pos + 3,   p->M_LEVELTR_k);

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

int Level_Transition_Order_Core_1_Decoder(Bitstream* stream, Level_Transition_Order_Core_1* p)
{
    if (NormalBitstream(stream, LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires M_LEVELTR_k:    stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_LEVELTR_k;
	  ensures  M_LEVELTR_k:    stream->bitpos == pos + 3;
	  ensures  M_LEVELTR_k:    EqualBits(stream, pos + 0, pos + 3, p->M_LEVELTR_k);
	  ensures  M_LEVELTR_k:    UpperBitsNotSet(p->M_LEVELTR_k, 3);
	*/
	{ p->M_LEVELTR_k		= Bitstream_Read(stream, 3); }

        if (p->M_LEVELTR_k == 1)
        {
	{ p->NID_NTC_k		= Bitstream_Read(stream, 8); }
        }

	{ p->L_ACKLEVELTR_k		= Bitstream_Read(stream, 15); }

        //@ assert M_LEVELTR_k:       EqualBits(stream, pos,       pos + 3,   p->M_LEVELTR_k);

        //@ assert M_LEVELTR_k:       UpperBitsNotSet(p->M_LEVELTR_k,       3);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

