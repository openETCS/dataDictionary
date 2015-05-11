
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
	   ensures  Q_DIR: stream->bitpos == pos + Q_DIR_E(p);
	   ensures  Q_DIR: EqualBits(stream, pos + Q_DIR_B(p), pos + Q_DIR_E(p), p->Q_DIR);
	   ensures  Q_DIR: UpperBitsNotSet(p->Q_DIR, 2);
	*/
	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

        /*@
	   requires L_PACKET: stream->bitpos == pos + L_PACKET_B(p);
	   assigns            stream->bitpos;
	   assigns            p->L_PACKET;
	   ensures  L_PACKET: stream->bitpos == pos + L_PACKET_E(p);
	   ensures  L_PACKET: EqualBits(stream, pos + L_PACKET_B(p), pos + L_PACKET_E(p), p->L_PACKET);
	   ensures  L_PACKET: UpperBitsNotSet(p->L_PACKET, 13);
	*/
        { p->L_PACKET		= Bitstream_Read(stream, 13); }

        /*@
	   requires Q_NEWCOUNTRY: stream->bitpos == pos + Q_NEWCOUNTRY_B(p);
	   assigns                stream->bitpos;
	   assigns                p->Q_NEWCOUNTRY;
	   ensures  Q_NEWCOUNTRY: stream->bitpos == pos + Q_NEWCOUNTRY_E(p);
	   ensures  Q_NEWCOUNTRY: EqualBits(stream, pos + Q_NEWCOUNTRY_B(p), pos + Q_NEWCOUNTRY_E(p), p->Q_NEWCOUNTRY);
	   ensures  Q_NEWCOUNTRY: UpperBitsNotSet(p->Q_NEWCOUNTRY, 1);
	*/
	{ p->Q_NEWCOUNTRY		= Bitstream_Read(stream, 1); }

	/*@
	   requires NID_C: stream->bitpos == pos + NID_C_B(p);
	   requires NID_C: ZeroInitialized(p->NID_C);
	   assigns         stream->bitpos;
	   assigns         p->NID_C;
	   ensures  NID_C: EqualBits(stream, pos + NID_C_B(p), pos + NID_C_E(p), p->NID_C);
	   ensures  NID_C: UpperBitsNotSet(p->NID_C, NID_C_E(p) - NID_C_B(p));
	   ensures  NID_C: stream->bitpos == pos + NID_C_E(p);

	   behavior read:
	     assumes NID_C: \at(p->Q_NEWCOUNTRY,Here) == 1;

             assigns         stream->bitpos;
	     assigns         p->NID_C;

	     ensures  NID_C: NID_C_E(p) == NID_C_B(p) + 10;
	     ensures  NID_C: EqualBits(stream, pos + NID_C_B(p), pos + NID_C_B(p) + 10, p->NID_C);
	     ensures  NID_C: EqualBits(stream, pos + NID_C_B(p), pos + NID_C_E(p), p->NID_C);
	     ensures  NID_C: UpperBitsNotSet(p->NID_C, 10);

	   behavior skip:
	     assumes NID_C: \at(p->Q_NEWCOUNTRY,Here) != 1;

	     assigns         \nothing;

	     ensures  NID_C: NID_C_E(p) == NID_C_B(p);
             ensures  NID_C: EqualBits(stream, pos + NID_C_B(p), pos + NID_C_B(p), p->NID_C);
	     ensures  NID_C: EqualBits(stream, pos + NID_C_B(p), pos + NID_C_E(p), p->NID_C);
	       
	   disjoint behaviors;
	   complete behaviors;
	*/
        if (p->Q_NEWCOUNTRY == 1)
        {
            { p->NID_C		= Bitstream_Read(stream, 10); }
        }

        /*@
	   requires NID_BG: stream->bitpos == pos + NID_BG_B(p);
	   assigns         stream->bitpos;
	   assigns         p->NID_BG;
	   ensures  NID_BG: stream->bitpos == pos + NID_BG_E(p);
	   ensures  NID_BG: EqualBits(stream, pos + NID_BG_B(p), pos + NID_BG_E(p), p->NID_BG);
	   ensures  NID_BG: UpperBitsNotSet(p->NID_BG, 14);
	*/
	{ p->NID_BG		= Bitstream_Read(stream, 14); }

	//@ assert stream->bitpos <= \at(stream->bitpos, Pre) + INFILL_LOCATION_REFERENCE_BITSIZE;

	//@ assert Q_DIR:            EqualBits(stream, pos + Q_DIR_B(p), pos + Q_DIR_E(p), p->Q_DIR);
	//@ assert Q_DIR:            UpperBitsNotSet(p->Q_DIR, 2);

	//@ assert L_PACKET:         EqualBits(stream, pos + L_PACKET_B(p), pos + L_PACKET_E(p), p->L_PACKET);
	//@ assert L_PACKET:         UpperBitsNotSet(p->L_PACKET, 13);

	//@ assert Q_NEQCOUNTRY:     EqualBits(stream, pos + Q_NEWCOUNTRY_B(p), pos + Q_NEWCOUNTRY_E(p), p->Q_NEWCOUNTRY);
	//@ assert Q_NEWCOUNTRY:     UpperBitsNotSet(p->Q_NEWCOUNTRY, 1);

	//@ assert NID_C:            EqualBits(stream, pos + NID_C_B(p), pos + NID_C_E(p), p->NID_C);
	//@ assert NID_C:            UpperBitsNotSet(p->NID_C, 10);

	//@ assert NID_BG:            EqualBits(stream, pos + NID_BG_B(p), pos + NID_BG_E(p), p->NID_BG);
	//@ assert NID_BG:            UpperBitsNotSet(p->NID_BG, 10);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

