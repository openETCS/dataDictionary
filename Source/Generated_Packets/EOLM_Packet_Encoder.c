
#include "EOLM_Packet_Encoder.h"
#include "EOLM_Packet_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int EOLM_Packet_Encoder(Bitstream* stream, const EOLM_Packet_Core* p)
{
    if (NormalBitstream(stream, EOLM_PACKET_CORE_BITSIZE))
    {
        if (EOLM_Packet_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 14, p->NID_LOOP);
            Bitstream_Write(stream, 15, p->D_LOOP);
            Bitstream_Write(stream, 15, p->L_LOOP);
            Bitstream_Write(stream, 1,  p->Q_LOOPDIR);
            Bitstream_Write(stream, 4,  p->Q_SSCODE);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert NID_LOOP:          EqualBits(stream, pos + 17,  pos + 31,  p->NID_LOOP);
            //@ assert D_LOOP:            EqualBits(stream, pos + 31,  pos + 46,  p->D_LOOP);
            //@ assert L_LOOP:            EqualBits(stream, pos + 46,  pos + 61,  p->L_LOOP);
            //@ assert Q_LOOPDIR:         EqualBits(stream, pos + 61,  pos + 62,  p->Q_LOOPDIR);
            //@ assert Q_SSCODE:          EqualBits(stream, pos + 62,  pos + 66,  p->Q_SSCODE);

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

