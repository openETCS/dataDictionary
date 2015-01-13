
#include "List_of_Balises_in_SR_Authority_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int List_of_Balises_in_SR_Authority_Decoder(Bitstream* stream, List_of_Balises_in_SR_Authority* p)
{
    if (NormalBitstream(stream, LIST_OF_BALISES_IN_SR_AUTHORITY_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->N_ITER             = Bitwalker_Peek_Normal(addr, size, pos + 23,  5);
        p->Q_NEWCOUNTRY(k)    = Bitwalker_Peek_Normal(addr, size, pos + 28,  1);
        p->NID_C(k)           = Bitwalker_Peek_Normal(addr, size, pos + 29,  10);
        p->NID_BG(k)          = Bitwalker_Peek_Normal(addr, size, pos + 39,  14);

        stream->bitpos += LIST_OF_BALISES_IN_SR_AUTHORITY_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert N_ITER:            EqualBits(stream, pos + 23,  pos + 28,  p->N_ITER);
        //@ assert Q_NEWCOUNTRY(k):   EqualBits(stream, pos + 28,  pos + 29,  p->Q_NEWCOUNTRY(k));
        //@ assert NID_C(k):          EqualBits(stream, pos + 29,  pos + 39,  p->NID_C(k));
        //@ assert NID_BG(k):         EqualBits(stream, pos + 39,  pos + 53,  p->NID_BG(k));

        return 1;
    }
    else
    {
        return 0;
    }
}

