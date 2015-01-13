
#include "Movement_Authority_Request_Parameters_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Movement_Authority_Request_Parameters_Decoder(Bitstream* stream, Movement_Authority_Request_Parameters* p)
{
    if (NormalBitstream(stream, MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->T_MAR              = Bitwalker_Peek_Normal(addr, size, pos + 23,  8);
        p->T_TIMEOUTRQST      = Bitwalker_Peek_Normal(addr, size, pos + 31,  10);
        p->T_CYCRQST          = Bitwalker_Peek_Normal(addr, size, pos + 41,  8);

        stream->bitpos += MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert T_MAR:             EqualBits(stream, pos + 23,  pos + 31,  p->T_MAR);
        //@ assert T_TIMEOUTRQST:     EqualBits(stream, pos + 31,  pos + 41,  p->T_TIMEOUTRQST);
        //@ assert T_CYCRQST:         EqualBits(stream, pos + 41,  pos + 49,  p->T_CYCRQST);

        return 1;
    }
    else
    {
        return 0;
    }
}

