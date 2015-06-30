
#include "Movement_Authority_Request_Parameters_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Movement_Authority_Request_Parameters_UpperBitsNotSet(const Movement_Authority_Request_Parameters_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->T_MAR,             8) ;
    status = status && UpperBitsNotSet64(p->T_TIMEOUTRQST,     10);
    status = status && UpperBitsNotSet64(p->T_CYCRQST,         8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Movement_Authority_Request_Parameters_Encoder(Bitstream* stream, const Movement_Authority_Request_Parameters_Core* p)
{
    if (NormalBitstream(stream, MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_BITSIZE))
    {
        if (Movement_Authority_Request_Parameters_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 8,  p->T_MAR);
            Bitstream_Write(stream, 10, p->T_TIMEOUTRQST);
            Bitstream_Write(stream, 8,  p->T_CYCRQST);



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

int Movement_Authority_Request_Parameters_Decoder(Bitstream* stream, Movement_Authority_Request_Parameters_Core* p)
{
    if (NormalBitstream(stream, MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->T_MAR		= Bitstream_Read(stream, 8); }

	{ p->T_TIMEOUTRQST		= Bitstream_Read(stream, 10); }

	{ p->T_CYCRQST		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

