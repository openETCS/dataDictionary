
#include "Radio_infill_area_information_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Radio_infill_area_information_UpperBitsNotSet(const Radio_infill_area_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_RIU,             1) ;
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    status = status && UpperBitsNotSet64(p->NID_RIU,           14);
    status = status && UpperBitsNotSet64(p->NID_RADIO,         64);
    status = status && UpperBitsNotSet64(p->D_INFILL,          15);
    status = status && UpperBitsNotSet64(p->NID_BG,            14);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Radio_infill_area_information_Encoder(Bitstream* stream, const Radio_infill_area_information_Core* p)
{
    if (NormalBitstream(stream, RADIO_INFILL_AREA_INFORMATION_CORE_BITSIZE))
    {
        if (Radio_infill_area_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_RIU);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_RIU);
            Bitstream_Write(stream, 64, p->NID_RADIO);
            Bitstream_Write(stream, 15, p->D_INFILL);
            Bitstream_Write(stream, 14, p->NID_BG);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert Q_RIU:             EqualBits(stream, pos + 17,  pos + 18,  p->Q_RIU);
            //@ assert NID_C:             EqualBits(stream, pos + 18,  pos + 28,  p->NID_C);
            //@ assert NID_RIU:           EqualBits(stream, pos + 28,  pos + 42,  p->NID_RIU);
            //@ assert NID_RADIO:         EqualBits(stream, pos + 42,  pos + 106, p->NID_RADIO);
            //@ assert D_INFILL:          EqualBits(stream, pos + 106, pos + 121, p->D_INFILL);
            //@ assert NID_BG:            EqualBits(stream, pos + 121, pos + 135, p->NID_BG);

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

int Radio_infill_area_information_Decoder(Bitstream* stream, Radio_infill_area_information_Core* p)
{
    if (NormalBitstream(stream, RADIO_INFILL_AREA_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires Q_DIR:          stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_DIR;
	  ensures  Q_DIR:          stream->bitpos == pos + 2;
	  ensures  Q_DIR:          EqualBits(stream, pos + 0, pos + 2, p->Q_DIR);
	  ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
	*/
	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	/*@
	  requires L_PACKET:       stream->bitpos == pos + 2;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PACKET;
	  ensures  L_PACKET:       stream->bitpos == pos + 15;
	  ensures  L_PACKET:       EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
	  ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
	*/
	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	/*@
	  requires Q_SCALE:        stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_SCALE;
	  ensures  Q_SCALE:        stream->bitpos == pos + 17;
	  ensures  Q_SCALE:        EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
	  ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
	*/
	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	/*@
	  requires Q_RIU:          stream->bitpos == pos + 17;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_RIU;
	  ensures  Q_RIU:          stream->bitpos == pos + 18;
	  ensures  Q_RIU:          EqualBits(stream, pos + 17, pos + 18, p->Q_RIU);
	  ensures  Q_RIU:          UpperBitsNotSet(p->Q_RIU, 1);
	*/
	{ p->Q_RIU		= Bitstream_Read(stream, 1); }

	/*@
	  requires NID_C:          stream->bitpos == pos + 18;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_C;
	  ensures  NID_C:          stream->bitpos == pos + 28;
	  ensures  NID_C:          EqualBits(stream, pos + 18, pos + 28, p->NID_C);
	  ensures  NID_C:          UpperBitsNotSet(p->NID_C, 10);
	*/
	{ p->NID_C		= Bitstream_Read(stream, 10); }

	/*@
	  requires NID_RIU:        stream->bitpos == pos + 28;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_RIU;
	  ensures  NID_RIU:        stream->bitpos == pos + 42;
	  ensures  NID_RIU:        EqualBits(stream, pos + 28, pos + 42, p->NID_RIU);
	  ensures  NID_RIU:        UpperBitsNotSet(p->NID_RIU, 14);
	*/
	{ p->NID_RIU		= Bitstream_Read(stream, 14); }

	/*@
	  requires NID_RADIO:      stream->bitpos == pos + 42;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_RADIO;
	  ensures  NID_RADIO:      stream->bitpos == pos + 106;
	  ensures  NID_RADIO:      EqualBits(stream, pos + 42, pos + 106, p->NID_RADIO);
	  ensures  NID_RADIO:      UpperBitsNotSet(p->NID_RADIO, 64);
	*/
	{ p->NID_RADIO		= Bitstream_Read(stream, 64); }

	/*@
	  requires D_INFILL:       stream->bitpos == pos + 106;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_INFILL;
	  ensures  D_INFILL:       stream->bitpos == pos + 121;
	  ensures  D_INFILL:       EqualBits(stream, pos + 106, pos + 121, p->D_INFILL);
	  ensures  D_INFILL:       UpperBitsNotSet(p->D_INFILL, 15);
	*/
	{ p->D_INFILL		= Bitstream_Read(stream, 15); }

	/*@
	  requires NID_BG:         stream->bitpos == pos + 121;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_BG;
	  ensures  NID_BG:         stream->bitpos == pos + 135;
	  ensures  NID_BG:         EqualBits(stream, pos + 121, pos + 135, p->NID_BG);
	  ensures  NID_BG:         UpperBitsNotSet(p->NID_BG, 14);
	*/
	{ p->NID_BG		= Bitstream_Read(stream, 14); }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert Q_RIU:             EqualBits(stream, pos + 17,  pos + 18,  p->Q_RIU);
        //@ assert NID_C:             EqualBits(stream, pos + 18,  pos + 28,  p->NID_C);
        //@ assert NID_RIU:           EqualBits(stream, pos + 28,  pos + 42,  p->NID_RIU);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 42,  pos + 106, p->NID_RADIO);
        //@ assert D_INFILL:          EqualBits(stream, pos + 106, pos + 121, p->D_INFILL);
        //@ assert NID_BG:            EqualBits(stream, pos + 121, pos + 135, p->NID_BG);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert Q_RIU:             UpperBitsNotSet(p->Q_RIU,             1);
        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);
        //@ assert NID_RIU:           UpperBitsNotSet(p->NID_RIU,           14);
        //@ assert NID_RADIO:         UpperBitsNotSet(p->NID_RADIO,         64);
        //@ assert D_INFILL:          UpperBitsNotSet(p->D_INFILL,          15);
        //@ assert NID_BG:            UpperBitsNotSet(p->NID_BG,            14);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

