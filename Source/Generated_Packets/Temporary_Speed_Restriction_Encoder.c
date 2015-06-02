
#include "Temporary_Speed_Restriction_Encoder.h"
#include "Temporary_Speed_Restriction_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Temporary_Speed_Restriction_Encoder(Bitstream* stream, const Temporary_Speed_Restriction_Core* p)
{
    if (NormalBitstream(stream, TEMPORARY_SPEED_RESTRICTION_CORE_BITSIZE))
    {
        if (Temporary_Speed_Restriction_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 8,  p->NID_TSR);
            Bitstream_Write(stream, 15, p->D_TSR);
            Bitstream_Write(stream, 15, p->L_TSR);
            Bitstream_Write(stream, 1,  p->Q_FRONT);
            Bitstream_Write(stream, 7,  p->V_TSR);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert NID_TSR:           EqualBits(stream, pos + 17,  pos + 25,  p->NID_TSR);
            //@ assert D_TSR:             EqualBits(stream, pos + 25,  pos + 40,  p->D_TSR);
            //@ assert L_TSR:             EqualBits(stream, pos + 40,  pos + 55,  p->L_TSR);
            //@ assert Q_FRONT:           EqualBits(stream, pos + 55,  pos + 56,  p->Q_FRONT);
            //@ assert V_TSR:             EqualBits(stream, pos + 56,  pos + 63,  p->V_TSR);

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

