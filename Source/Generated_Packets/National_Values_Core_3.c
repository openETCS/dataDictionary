
#include "National_Values_Core_3.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"
#include "Bitstream_Normal.h"

int National_Values_Core_3_UpperBitsNotSet(const National_Values_Core_3* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_NVKVINTSET,      2) ;
    if (p->Q_NVKVINTSET == 1)
    {
    status = status && UpperBitsNotSet64(p->A_NVP12,           6) ;
    status = status && UpperBitsNotSet64(p->A_NVP23,           6) ;
    }
    status = status && UpperBitsNotSet64(p->V_NVKVINT,         7) ;
    status = status && UpperBitsNotSet64(p->M_NVKVINT,         7) ;
    status = status && UpperBitsNotSet64(p->N_ITER_3_1,        5) ;
    for (uint32_t i = 0; i < p->N_ITER_3_1; ++i)
    {
        status = status && National_Values_Core_3_1_UpperBitsNotSet(&(p->sub_3_1[i]));
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

int National_Values_Core_3_Encoder(Bitstream* stream, const National_Values_Core_3* p)
{
    if (Bitstream_Normal(stream, NATIONAL_VALUES_CORE_3_CORE_BITSIZE))
    {
        if (National_Values_Core_3_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_NVKVINTSET);
            if (p->Q_NVKVINTSET == 1)
            {
            Bitstream_Write(stream, 6,  p->A_NVP12);
            Bitstream_Write(stream, 6,  p->A_NVP23);
            }

            Bitstream_Write(stream, 7,  p->V_NVKVINT);
            Bitstream_Write(stream, 7,  p->M_NVKVINT);
            Bitstream_Write(stream, 5,  p->N_ITER_3_1);
            for (uint32_t i = 0; i < p->N_ITER_3_1; ++i)
            {
                National_Values_Core_3_1_Encoder(stream, &(p->sub_3_1[i]));
            }


            //@ assert Q_NVKVINTSET:      EqualBits(stream, pos,       pos + 2,   p->Q_NVKVINTSET);

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

int National_Values_Core_3_Decoder(Bitstream* stream, National_Values_Core_3* p)
{
    if (Bitstream_Normal(stream, NATIONAL_VALUES_CORE_3_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires Q_NVKVINTSET:   stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVKVINTSET;
	  ensures  Q_NVKVINTSET:   stream->bitpos == pos + 2;
	  ensures  Q_NVKVINTSET:   EqualBits(stream, pos + 0, pos + 2, p->Q_NVKVINTSET);
	  ensures  Q_NVKVINTSET:   UpperBitsNotSet(p->Q_NVKVINTSET, 2);
	*/
	{ p->Q_NVKVINTSET		= Bitstream_Read(stream, 2); }

        if (p->Q_NVKVINTSET == 1)
        {
	{ p->A_NVP12		= Bitstream_Read(stream, 6); }

	{ p->A_NVP23		= Bitstream_Read(stream, 6); }
        }

	{ p->V_NVKVINT		= Bitstream_Read(stream, 7); }

	{ p->M_NVKVINT		= Bitstream_Read(stream, 7); }

	{ p->N_ITER_3_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_3_1; ++i)
        {
            National_Values_Core_3_1_Decoder(stream, &(p->sub_3_1[i]));
        }
        //@ assert Q_NVKVINTSET:      EqualBits(stream, pos,       pos + 2,   p->Q_NVKVINTSET);

        //@ assert Q_NVKVINTSET:      UpperBitsNotSet(p->Q_NVKVINTSET,      2);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

