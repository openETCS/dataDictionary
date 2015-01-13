
#include "Data_used_by_applications_outside_the_ERTMSETCS_system_Encoder.h"
#include "Data_used_by_applications_outside_the_ERTMSETCS_system_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Data_used_by_applications_outside_the_ERTMSETCS_system_Encoder(Bitstream* stream, const Data_used_by_applications_outside_the_ERTMSETCS_system* p)
{
    if (NormalBitstream(stream, DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_BITSIZE))
    {
        if (Data_used_by_applications_outside_the_ERTMSETCS_system_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  9,  p->NID_XUSER);
            Bitwalker_Poke_Normal(addr, size, pos + 32,  8,  p->NID_NTC);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  ,   p->Other_data_depending_on__NID_XUSER);

            stream->bitpos += DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert NID_XUSER:         EqualBits(stream, pos + 23,  pos + 32,  p->NID_XUSER);
            //@ assert NID_NTC:           EqualBits(stream, pos + 32,  pos + 40,  p->NID_NTC);
            //@ assert Other_data_depending_on__NID_XUSER: EqualBits(stream, pos + 40,  pos + 40,  p->Other_data_depending_on__NID_XUSER);

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

