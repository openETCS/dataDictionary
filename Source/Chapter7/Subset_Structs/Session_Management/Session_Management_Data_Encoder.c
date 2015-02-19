
#include "Session_Management_Data_Encoder.h"
#include "Session_Management_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Session_Management_Data_Encoder(Bitstream* stream, const Session_Management_Data* p)
{
    if (NormalBitstream(stream, SESSION_MANAGEMENT_DATA_BITSIZE))
    {
        if (Session_Management_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  1,  p->Q_RBC);
            Bitwalker_Poke_Normal(addr, size, pos + 16,  10, p->NID_C);
            Bitwalker_Poke_Normal(addr, size, pos + 26,  14, p->NID_RBC);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  64, p->NID_RADIO);
            Bitwalker_Poke_Normal(addr, size, pos + 104, 1,  p->Q_SLEEPSESSION);

            stream->bitpos += SESSION_MANAGEMENT_DATA_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
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

