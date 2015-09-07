
#include "Error_Reporting_Core.h"
#include "Bit64.h"

int Error_Reporting_UpperBitsNotSet(const Error_Reporting_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->M_ERROR,           8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Error_Reporting_Encoder(Bitstream* stream, const Error_Reporting_Core* p)
{
    if (Bitstream_Normal(stream, ERROR_REPORTING_CORE_BITSIZE))
    {
        if (Error_Reporting_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 8,  p->M_ERROR);


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert M_ERROR:           EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

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

int Error_Reporting_Decoder(Bitstream* stream, Error_Reporting_Core* p)
{
    if (Bitstream_Normal(stream, ERROR_REPORTING_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires L_PACKET:       stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PACKET;
	  ensures  L_PACKET:       stream->bitpos == pos + 13;
	  ensures  L_PACKET:       EqualBits(stream, pos + 0, pos + 13, p->L_PACKET);
	  ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
	*/
	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	/*@
	  requires M_ERROR:        stream->bitpos == pos + 13;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_ERROR;
	  ensures  M_ERROR:        stream->bitpos == pos + 21;
	  ensures  M_ERROR:        EqualBits(stream, pos + 13, pos + 21, p->M_ERROR);
	  ensures  M_ERROR:        UpperBitsNotSet(p->M_ERROR, 8);
	*/
	{ p->M_ERROR		= Bitstream_Read(stream, 8); }

        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert M_ERROR:           EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert M_ERROR:           UpperBitsNotSet(p->M_ERROR,           8);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

