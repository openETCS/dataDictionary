
#include "Infill_location_reference_Decoder.h"
#include "Bitstream_Read.h"

int Infill_location_reference_Decoder(Bitstream* stream, Infill_location_reference* p)
{
    if (NormalBitstream(stream, INFILL_LOCATION_REFERENCE_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        /*@
	   requires Q_DIR: stream->bitpos == pos;
	   assigns         stream->bitpos;
	   assigns         p->Q_DIR;
	   ensures  Q_DIR: stream->bitpos == pos + 2;
	   ensures  Q_DIR: EqualBits(stream, pos, pos + 2, p->Q_DIR);
	   ensures  Q_DIR: UpperBitsNotSet(p->Q_DIR, 2);
	*/
	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

        /*@
	   requires L_PACKET: stream->bitpos == pos + 2;
	   assigns            stream->bitpos;
	   assigns            p->L_PACKET;
	   ensures  L_PACKET: stream->bitpos == pos + 15;
	   ensures  L_PACKET: EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
	   ensures  L_PACKET: UpperBitsNotSet(p->L_PACKET, 13);
	*/
        { p->L_PACKET		= Bitstream_Read(stream, 13); }

        /*@
	   requires Q_NEWCOUNTRY: stream->bitpos == pos + 15;
	   assigns                stream->bitpos;
	   assigns                p->Q_NEWCOUNTRY;
	   ensures  Q_NEWCOUNTRY: stream->bitpos == pos + 16;
	   ensures  Q_NEWCOUNTRY: EqualBits(stream, pos + 15, pos + 16, p->Q_NEWCOUNTRY);
	   ensures  Q_NEWCOUNTRY: UpperBitsNotSet(p->Q_NEWCOUNTRY, 1);
	*/
	{ p->Q_NEWCOUNTRY		= Bitstream_Read(stream, 1); }

	if (p->Q_NEWCOUNTRY == 1)
	{
	    p->NID_C		= Bitstream_Read(stream, 10);
	}

	p->NID_BG		= Bitstream_Read(stream, 14);

	//@ assert stream->bitpos <= \at(stream->bitpos, Pre) + INFILL_LOCATION_REFERENCE_BITSIZE;

	//@ assert Q_DIR:            EqualBits(stream, pos, pos + 2, p->Q_DIR);
	//@ assert Q_DIR:            UpperBitsNotSet(p->Q_DIR, 2);

	//@ assert L_PACKET:         EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
	//@ assert L_PACKET:         UpperBitsNotSet(p->L_PACKET, 13);

	//@ assert Q_NEQCOUNTRY:     EqualBits(stream, pos + 15, pos + 15, p->Q_NEWCOUNTRY);
	//@ assert Q_NEWCOUNTRY:     UpperBitsNotSet(p->Q_NEWCOUNTRY, 1);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

