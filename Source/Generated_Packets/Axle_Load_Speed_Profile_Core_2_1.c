
#include "Axle_Load_Speed_Profile_Core_2_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_2_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->M_AXLELOADCAT_k_m, 7) ;
    status = status && UpperBitsNotSet64(p->V_AXLELOAD_k_m,    7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Axle_Load_Speed_Profile_Core_2_1_Encoder(Bitstream* stream, const Axle_Load_Speed_Profile_Core_2_1* p)
{
    if (NormalBitstream(stream, AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE))
    {
        if (Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 7,  p->M_AXLELOADCAT_k_m);
            Bitstream_Write(stream, 7,  p->V_AXLELOAD_k_m);



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

int Axle_Load_Speed_Profile_Core_2_1_Decoder(Bitstream* stream, Axle_Load_Speed_Profile_Core_2_1* p)
{
    if (NormalBitstream(stream, AXLE_LOAD_SPEED_PROFILE_CORE_2_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->M_AXLELOADCAT_k_m		= Bitstream_Read(stream, 7); }

	{ p->V_AXLELOAD_k_m		= Bitstream_Read(stream, 7); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

