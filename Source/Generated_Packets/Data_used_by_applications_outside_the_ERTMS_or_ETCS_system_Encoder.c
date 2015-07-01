
#include "Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Encoder.h"
#include "Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

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

