
#include "Danger_for_Shunting_information_Encoder.h"
#include "Danger_for_Shunting_information_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Danger_for_Shunting_information_Encoder(Bitstream* stream, const Danger_for_Shunting_information_Core* p)
{
    if (NormalBitstream(stream, DANGER_FOR_SHUNTING_INFORMATION_CORE_BITSIZE))
    {
        if (Danger_for_Shunting_information_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_ASPECT);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_ASPECT:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

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

