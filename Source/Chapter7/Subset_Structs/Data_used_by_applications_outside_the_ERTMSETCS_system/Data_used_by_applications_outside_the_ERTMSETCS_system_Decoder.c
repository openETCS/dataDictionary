
#include "Data_used_by_applications_outside_the_ERTMSETCS_system_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Data_used_by_applications_outside_the_ERTMSETCS_system_Decoder(Bitstream* stream, Data_used_by_applications_outside_the_ERTMSETCS_system* p)
{
    if (NormalBitstream(stream, DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->NID_XUSER          = Bitwalker_Peek_Normal(addr, size, pos + 23,  9);
        p->NID_NTC            = Bitwalker_Peek_Normal(addr, size, pos + 32,  8);
        p->Other_data_depending_on__NID_XUSER = Bitwalker_Peek_Normal(addr, size, pos + 40,  0);

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
        return 0;
    }
}

