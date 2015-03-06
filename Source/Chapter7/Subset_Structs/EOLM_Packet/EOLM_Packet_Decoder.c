
#include "EOLM_Packet_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int EOLM_Packet_Decoder(Bitstream* stream, EOLM_Packet* p)
{
    if (NormalBitstream(stream, EOLM_PACKET_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 2,   13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 15,  2);
        p->NID_LOOP           = Bitwalker_Peek_Normal(addr, size, pos + 17,  14);
        p->D_LOOP             = Bitwalker_Peek_Normal(addr, size, pos + 31,  15);
        p->L_LOOP             = Bitwalker_Peek_Normal(addr, size, pos + 46,  15);
        p->Q_LOOPDIR          = Bitwalker_Peek_Normal(addr, size, pos + 61,  1);
        p->Q_SSCODE           = Bitwalker_Peek_Normal(addr, size, pos + 62,  4);

        stream->bitpos += EOLM_PACKET_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert NID_LOOP:          EqualBits(stream, pos + 17,  pos + 31,  p->NID_LOOP);
        //@ assert D_LOOP:            EqualBits(stream, pos + 31,  pos + 46,  p->D_LOOP);
        //@ assert L_LOOP:            EqualBits(stream, pos + 46,  pos + 61,  p->L_LOOP);
        //@ assert Q_LOOPDIR:         EqualBits(stream, pos + 61,  pos + 62,  p->Q_LOOPDIR);
        //@ assert Q_SSCODE:          EqualBits(stream, pos + 62,  pos + 66,  p->Q_SSCODE);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert NID_LOOP:          UpperBitsNotSet(p->NID_LOOP,          14);
        //@ assert D_LOOP:            UpperBitsNotSet(p->D_LOOP,            15);
        //@ assert L_LOOP:            UpperBitsNotSet(p->L_LOOP,            15);
        //@ assert Q_LOOPDIR:         UpperBitsNotSet(p->Q_LOOPDIR,         1);
        //@ assert Q_SSCODE:          UpperBitsNotSet(p->Q_SSCODE,          4);

        return 1;
    }
    else
    {
        return 0;
    }
}

