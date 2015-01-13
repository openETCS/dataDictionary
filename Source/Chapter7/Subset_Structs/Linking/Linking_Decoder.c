
#include "Linking_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Linking_Decoder(Bitstream* stream, Linking* p)
{
    if (NormalBitstream(stream, LINKING_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 23,  2);
        p->D_LINK             = Bitwalker_Peek_Normal(addr, size, pos + 25,  15);
        p->Q_NEWCOUNTRY       = Bitwalker_Peek_Normal(addr, size, pos + 40,  1);
        p->NID_C              = Bitwalker_Peek_Normal(addr, size, pos + 41,  10);
        p->NID_BG             = Bitwalker_Peek_Normal(addr, size, pos + 51,  14);
        p->Q_LINKORIENTATION  = Bitwalker_Peek_Normal(addr, size, pos + 65,  1);
        p->Q_LINKREACTION     = Bitwalker_Peek_Normal(addr, size, pos + 66,  2);
        p->Q_LOCACC           = Bitwalker_Peek_Normal(addr, size, pos + 68,  6);
        p->N_ITER             = Bitwalker_Peek_Normal(addr, size, pos + 74,  5);
        p->D_LINK_(k)         = Bitwalker_Peek_Normal(addr, size, pos + 79,  15);
        p->Q_NEWCOUNTRY(k)    = Bitwalker_Peek_Normal(addr, size, pos + 94,  1);
        p->NID_C_(k)          = Bitwalker_Peek_Normal(addr, size, pos + 95,  10);
        p->NID_BG_(k)         = Bitwalker_Peek_Normal(addr, size, pos + 105, 14);
        p->Q_LINKORIENTATION_(k) = Bitwalker_Peek_Normal(addr, size, pos + 119, 1);
        p->Q_LINKREACTION_(k) = Bitwalker_Peek_Normal(addr, size, pos + 120, 2);
        p->Q_LOCACC_(k)       = Bitwalker_Peek_Normal(addr, size, pos + 122, 6);

        stream->bitpos += LINKING_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert D_LINK:            EqualBits(stream, pos + 25,  pos + 40,  p->D_LINK);
        //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 40,  pos + 41,  p->Q_NEWCOUNTRY);
        //@ assert NID_C:             EqualBits(stream, pos + 41,  pos + 51,  p->NID_C);
        //@ assert NID_BG:            EqualBits(stream, pos + 51,  pos + 65,  p->NID_BG);
        //@ assert Q_LINKORIENTATION: EqualBits(stream, pos + 65,  pos + 66,  p->Q_LINKORIENTATION);
        //@ assert Q_LINKREACTION:    EqualBits(stream, pos + 66,  pos + 68,  p->Q_LINKREACTION);
        //@ assert Q_LOCACC:          EqualBits(stream, pos + 68,  pos + 74,  p->Q_LOCACC);
        //@ assert N_ITER:            EqualBits(stream, pos + 74,  pos + 79,  p->N_ITER);
        //@ assert D_LINK_(k):        EqualBits(stream, pos + 79,  pos + 94,  p->D_LINK_(k));
        //@ assert Q_NEWCOUNTRY(k):   EqualBits(stream, pos + 94,  pos + 95,  p->Q_NEWCOUNTRY(k));
        //@ assert NID_C_(k):         EqualBits(stream, pos + 95,  pos + 105, p->NID_C_(k));
        //@ assert NID_BG_(k):        EqualBits(stream, pos + 105, pos + 119, p->NID_BG_(k));
        //@ assert Q_LINKORIENTATION_(k): EqualBits(stream, pos + 119, pos + 120, p->Q_LINKORIENTATION_(k));
        //@ assert Q_LINKREACTION_(k): EqualBits(stream, pos + 120, pos + 122, p->Q_LINKREACTION_(k));
        //@ assert Q_LOCACC_(k):      EqualBits(stream, pos + 122, pos + 128, p->Q_LOCACC_(k));

        return 1;
    }
    else
    {
        return 0;
    }
}

