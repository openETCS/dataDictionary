
#include "Conditional_Level_Transition_Order_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Conditional_Level_Transition_Order_UpperBitsNotSet(const Conditional_Level_Transition_Order_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->M_LEVELTR,         3) ;
    if (p->M_LEVELTR == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_NTC,           8) ;
    }
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Conditional_Level_Transition_Order_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int Conditional_Level_Transition_Order_Encoder(Bitstream* stream, const Conditional_Level_Transition_Order_Core* p)
{
    if (NormalBitstream(stream, CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_BITSIZE))
    {
        if (Conditional_Level_Transition_Order_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 3,  p->M_LEVELTR);
            if (p->M_LEVELTR == 1)
            {
            Bitstream_Write(stream, 8,  p->NID_NTC);
            }

            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Conditional_Level_Transition_Order_Core_1_Encoder(stream, &(p->sub_1[i]));
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

int Conditional_Level_Transition_Order_Decoder(Bitstream* stream, Conditional_Level_Transition_Order_Core* p)
{
    if (NormalBitstream(stream, CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->M_LEVELTR		= Bitstream_Read(stream, 3); }

        if (p->M_LEVELTR == 1)
        {
	{ p->NID_NTC		= Bitstream_Read(stream, 8); }
        }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Conditional_Level_Transition_Order_Core_1_Decoder(stream, &(p->sub_1[i]));
        }


	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

