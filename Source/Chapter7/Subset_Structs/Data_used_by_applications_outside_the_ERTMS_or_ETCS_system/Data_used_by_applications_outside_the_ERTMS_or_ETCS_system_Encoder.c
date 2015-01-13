
#include "Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Encoder.h"
#include "Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Encoder(Bitstream* stream, const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system* p)
{
    if (NormalBitstream(stream, DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_BITSIZE))
    {
        if (Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 21,  9,  p->NID_XUSER);
            Bitwalker_Poke_Normal(addr, size, pos + 30,  ,   p->Other_data_depending_on__NID_XUSER);

            stream->bitpos += DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
            //@ assert NID_XUSER:         EqualBits(stream, pos + 21,  pos + 30,  p->NID_XUSER);
            //@ assert Other_data_depending_on__NID_XUSER: EqualBits(stream, pos + 30,  pos + 30,  p->Other_data_depending_on__NID_XUSER);

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

