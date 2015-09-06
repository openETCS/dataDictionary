
#include "Radio_Network_registration_Core.h"
#include "Bit64.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"
#include "Bitstream_Normal.h"

int Radio_Network_registration_UpperBitsNotSet(const Radio_Network_registration_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_MN,            24);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Radio_Network_registration_Encoder(Bitstream* stream, const Radio_Network_registration_Core* p)
{
    if (Bitstream_Normal(stream, RADIO_NETWORK_REGISTRATION_CORE_BITSIZE))
    {
        if (Radio_Network_registration_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 24, p->NID_MN);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert NID_MN:            EqualBits(stream, pos + 15,  pos + 39,  p->NID_MN);

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

int Radio_Network_registration_Decoder(Bitstream* stream, Radio_Network_registration_Core* p)
{
    if (Bitstream_Normal(stream, RADIO_NETWORK_REGISTRATION_CORE_BITSIZE))
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
	  requires NID_MN:         stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_MN;
	  ensures  NID_MN:         stream->bitpos == pos + 39;
	  ensures  NID_MN:         EqualBits(stream, pos + 15, pos + 39, p->NID_MN);
	  ensures  NID_MN:         UpperBitsNotSet(p->NID_MN, 24);
	*/
	{ p->NID_MN		= Bitstream_Read(stream, 24); }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert NID_MN:            EqualBits(stream, pos + 15,  pos + 39,  p->NID_MN);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_MN:            UpperBitsNotSet(p->NID_MN,            24);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

