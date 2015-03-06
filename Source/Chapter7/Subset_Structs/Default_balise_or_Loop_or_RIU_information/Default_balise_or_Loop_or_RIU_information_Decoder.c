
#include "Default_balise_or_Loop_or_RIU_information_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Default_balise_or_Loop_or_RIU_information_Decoder(Bitstream* stream, Default_balise_or_Loop_or_RIU_information* p)
{
    if (NormalBitstream(stream, DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 2,   13);

        stream->bitpos += DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);

        return 1;
    }
    else
    {
        return 0;
    }
}

