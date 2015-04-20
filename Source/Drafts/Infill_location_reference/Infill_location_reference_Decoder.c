
#include "Infill_location_reference_Decoder.h"
#include "Bitstream_Read.h"

int Infill_location_reference_Decoder(Bitstream* stream, Infill_location_reference* p)
{
    if (NormalBitstream(stream, INFILL_LOCATION_REFERENCE_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

	p->Q_DIR		= Bitstream_Read(stream, 2);

	p->L_PACKET		= Bitstream_Read(stream, 13);

	p->Q_NEWCOUNTRY		= Bitstream_Read(stream, 1);

	if (p->Q_NEWCOUNTRY == 1)
	{
	    p->NID_C		= Bitstream_Read(stream, 10);
	}

	p->NID_BG		= Bitstream_Read(stream, 14);

        return 1;
    }
    else
    {
        return 0;
    }
}

