
#include "Stop_if_in_Staff_Responsible_Data_Encoder.h"
#include "Stop_if_in_Staff_Responsible_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Stop_if_in_Staff_Responsible_Data_Encoder(Bitstream* stream, const Stop_if_in_Staff_Responsible_Data* p)
{
    if (NormalBitstream(stream, STOP_IF_IN_STAFF_RESPONSIBLE_DATA_BITSIZE))
    {
        if (Stop_if_in_Staff_Responsible_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  1,  p->Q_SRSTOP);

            stream->bitpos += STOP_IF_IN_STAFF_RESPONSIBLE_DATA_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert Q_SRSTOP:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_SRSTOP);

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

