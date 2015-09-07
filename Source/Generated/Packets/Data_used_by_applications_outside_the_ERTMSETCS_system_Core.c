
#include "Data_used_by_applications_outside_the_ERTMSETCS_system_Core.h"
#include "Bit64.h"

int Data_used_by_applications_outside_the_ERTMSETCS_system_UpperBitsNotSet(const Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_XUSER,         9) ;
    if (p->NID_XUSER == 102)
    {
    status = status && UpperBitsNotSet64(p->NID_NTC,           8) ;
    }
    status = status && UpperBitsNotSet64(p->Other_data_depending_on__NID_XUSER, 8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Data_used_by_applications_outside_the_ERTMSETCS_system_Encoder(Bitstream* stream, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p)
{
    if (Bitstream_Normal(stream, DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_BITSIZE))
    {
        if (Data_used_by_applications_outside_the_ERTMSETCS_system_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 9,  p->NID_XUSER);
            if (p->NID_XUSER == 102)
            {
            Bitstream_Write(stream, 8,  p->NID_NTC);
            }

            Bitstream_Write(stream, 8,  p->Other_data_depending_on__NID_XUSER);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert NID_XUSER:         EqualBits(stream, pos + 15,  pos + 24,  p->NID_XUSER);

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

int Data_used_by_applications_outside_the_ERTMSETCS_system_Decoder(Bitstream* stream, Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p)
{
    if (Bitstream_Normal(stream, DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_BITSIZE))
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
	  requires NID_XUSER:      stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_XUSER;
	  ensures  NID_XUSER:      stream->bitpos == pos + 24;
	  ensures  NID_XUSER:      EqualBits(stream, pos + 15, pos + 24, p->NID_XUSER);
	  ensures  NID_XUSER:      UpperBitsNotSet(p->NID_XUSER, 9);
	*/
	{ p->NID_XUSER		= Bitstream_Read(stream, 9); }

        if (p->NID_XUSER == 102)
        {
	{ p->NID_NTC		= Bitstream_Read(stream, 8); }
        }

	{ p->Other_data_depending_on__NID_XUSER		= Bitstream_Read(stream, 8); }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert NID_XUSER:         EqualBits(stream, pos + 15,  pos + 24,  p->NID_XUSER);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_XUSER:         UpperBitsNotSet(p->NID_XUSER,         9);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

