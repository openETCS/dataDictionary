
#include "Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_UpperBitsNotSet(const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_XUSER,         9) ;
    status = status && UpperBitsNotSet64(p->Other_data_depending_on__NID_XUSER, 8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Encoder(Bitstream* stream, const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p)
{
    if (NormalBitstream(stream, DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_CORE_BITSIZE))
    {
        if (Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 9,  p->NID_XUSER);
            Bitstream_Write(stream, 8,  p->Other_data_depending_on__NID_XUSER);



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

int Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Decoder(Bitstream* stream, Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p)
{
    if (NormalBitstream(stream, DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->NID_XUSER		= Bitstream_Read(stream, 9); }

	{ p->Other_data_depending_on__NID_XUSER		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

