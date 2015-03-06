
#include "Movement_Authority_Request_Parameters_Encoder.h"
#include "Movement_Authority_Request_Parameters_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Movement_Authority_Request_Parameters_Encoder(Bitstream* stream, const Movement_Authority_Request_Parameters* p)
{
    if (NormalBitstream(stream, MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_BITSIZE))
    {
        if (Movement_Authority_Request_Parameters_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 2,   13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  8,  p->T_MAR);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  10, p->T_TIMEOUTRQST);
            Bitwalker_Poke_Normal(addr, size, pos + 33,  8,  p->T_CYCRQST);

            stream->bitpos += MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert T_MAR:             EqualBits(stream, pos + 15,  pos + 23,  p->T_MAR);
            //@ assert T_TIMEOUTRQST:     EqualBits(stream, pos + 23,  pos + 33,  p->T_TIMEOUTRQST);
            //@ assert T_CYCRQST:         EqualBits(stream, pos + 33,  pos + 41,  p->T_CYCRQST);

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

