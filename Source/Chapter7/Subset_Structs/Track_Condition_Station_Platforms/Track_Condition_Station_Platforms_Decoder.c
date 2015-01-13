
#include "Track_Condition_Station_Platforms_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Track_Condition_Station_Platforms_Decoder(Bitstream* stream, Track_Condition_Station_Platforms* p)
{
    if (NormalBitstream(stream, TRACK_CONDITION_STATION_PLATFORMS_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 23,  2);
        p->Q_TRACKINIT        = Bitwalker_Peek_Normal(addr, size, pos + 25,  1);
        p->D_TRACKINIT        = Bitwalker_Peek_Normal(addr, size, pos + 26,  15);
        p->D_TRACKCOND        = Bitwalker_Peek_Normal(addr, size, pos + 41,  15);
        p->L_TRACKCOND        = Bitwalker_Peek_Normal(addr, size, pos + 56,  15);
        p->M_PLATFORM         = Bitwalker_Peek_Normal(addr, size, pos + 71,  4);
        p->Q_PLATFORM         = Bitwalker_Peek_Normal(addr, size, pos + 75,  2);
        p->N_ITER             = Bitwalker_Peek_Normal(addr, size, pos + 77,  5);
        p->D_TRACKCOND(k)     = Bitwalker_Peek_Normal(addr, size, pos + 82,  15);
        p->L_TRACKCOND(k)     = Bitwalker_Peek_Normal(addr, size, pos + 97,  15);
        p->M_PLATFORM(k)      = Bitwalker_Peek_Normal(addr, size, pos + 112, 4);
        p->Q_PLATFORM(k)      = Bitwalker_Peek_Normal(addr, size, pos + 116, 2);

        stream->bitpos += TRACK_CONDITION_STATION_PLATFORMS_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert Q_TRACKINIT:       EqualBits(stream, pos + 25,  pos + 26,  p->Q_TRACKINIT);
        //@ assert D_TRACKINIT:       EqualBits(stream, pos + 26,  pos + 41,  p->D_TRACKINIT);
        //@ assert D_TRACKCOND:       EqualBits(stream, pos + 41,  pos + 56,  p->D_TRACKCOND);
        //@ assert L_TRACKCOND:       EqualBits(stream, pos + 56,  pos + 71,  p->L_TRACKCOND);
        //@ assert M_PLATFORM:        EqualBits(stream, pos + 71,  pos + 75,  p->M_PLATFORM);
        //@ assert Q_PLATFORM:        EqualBits(stream, pos + 75,  pos + 77,  p->Q_PLATFORM);
        //@ assert N_ITER:            EqualBits(stream, pos + 77,  pos + 82,  p->N_ITER);
        //@ assert D_TRACKCOND(k):    EqualBits(stream, pos + 82,  pos + 97,  p->D_TRACKCOND(k));
        //@ assert L_TRACKCOND(k):    EqualBits(stream, pos + 97,  pos + 112, p->L_TRACKCOND(k));
        //@ assert M_PLATFORM(k):     EqualBits(stream, pos + 112, pos + 116, p->M_PLATFORM(k));
        //@ assert Q_PLATFORM(k):     EqualBits(stream, pos + 116, pos + 118, p->Q_PLATFORM(k));

        return 1;
    }
    else
    {
        return 0;
    }
}

