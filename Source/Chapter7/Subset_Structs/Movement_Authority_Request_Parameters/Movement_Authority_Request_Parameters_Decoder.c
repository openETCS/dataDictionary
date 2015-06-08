
#include "Movement_Authority_Request_Parameters_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Movement_Authority_Request_Parameters_Decoder(Bitstream* stream, Movement_Authority_Request_Parameters* p)
{
    if (NormalBitstream(stream, MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 2,   13);
        p->T_MAR              = Bitwalker_Peek_Normal(addr, size, pos + 15,  8);
        p->T_TIMEOUTRQST      = Bitwalker_Peek_Normal(addr, size, pos + 23,  10);
        p->T_CYCRQST          = Bitwalker_Peek_Normal(addr, size, pos + 33,  8);

        stream->bitpos += MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert T_MAR:             EqualBits(stream, pos + 15,  pos + 23,  p->T_MAR);
        //@ assert T_TIMEOUTRQST:     EqualBits(stream, pos + 23,  pos + 33,  p->T_TIMEOUTRQST);
        //@ assert T_CYCRQST:         EqualBits(stream, pos + 33,  pos + 41,  p->T_CYCRQST);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert T_MAR:             UpperBitsNotSet(p->T_MAR,             8);
        //@ assert T_TIMEOUTRQST:     UpperBitsNotSet(p->T_TIMEOUTRQST,     10);
        //@ assert T_CYCRQST:         UpperBitsNotSet(p->T_CYCRQST,         8);

        return 1;
    }
    else
    {
        return 0;
    }
}

