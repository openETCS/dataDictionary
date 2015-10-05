
#include "Session_Management_Encoder.h"
#include "Session_Management_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Session_Management_Encoder(Bitstream* stream, const Session_Management* p)
{
    if (NormalBitstream(stream, SESSION_MANAGEMENT_BITSIZE))
    {
        if (Session_Management_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_RBC);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_RBC);
            Bitstream_Write(stream, 64, p->NID_RADIO);
            Bitstream_Write(stream, 1,  p->Q_SLEEPSESSION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_RBC:             EqualBits(stream, pos + 15,  pos + 16,  p->Q_RBC);
            //@ assert NID_C:             EqualBits(stream, pos + 16,  pos + 26,  p->NID_C);
            //@ assert NID_RBC:           EqualBits(stream, pos + 26,  pos + 40,  p->NID_RBC);
            //@ assert NID_RADIO:         EqualBits(stream, pos + 40,  pos + 104, p->NID_RADIO);
            //@ assert Q_SLEEPSESSION:    EqualBits(stream, pos + 104, pos + 105, p->Q_SLEEPSESSION);

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

