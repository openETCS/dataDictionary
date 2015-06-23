
#include "Movement_Authority_Request_Parameters_Encoder.h"
#include "Movement_Authority_Request_Parameters_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

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

