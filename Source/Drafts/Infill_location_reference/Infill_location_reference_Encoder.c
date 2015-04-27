
#include "Infill_location_reference_Encoder.h"
#include "Infill_location_reference_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Infill_location_reference_Encoder(Bitstream* stream, const Infill_location_reference* p)
{
    if (NormalBitstream(stream, INFILL_LOCATION_REFERENCE_BITSIZE))
    {
        if (Infill_location_reference_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);

	    if (p->Q_NEWCOUNTRY == 1)
	    {
                Bitstream_Write(stream, 10, p->NID_C);
	    }

            Bitstream_Write(stream, 14, p->NID_BG);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

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

