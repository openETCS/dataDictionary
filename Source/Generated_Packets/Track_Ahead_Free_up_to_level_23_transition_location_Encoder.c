
#include "Track_Ahead_Free_up_to_level_23_transition_location_Encoder.h"
#include "Track_Ahead_Free_up_to_level_23_transition_location_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Track_Ahead_Free_up_to_level_23_transition_location_Encoder(Bitstream* stream, const Track_Ahead_Free_up_to_level_23_transition_location_Core* p)
{
    if (NormalBitstream(stream, TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_BITSIZE))
    {
        if (Track_Ahead_Free_up_to_level_23_transition_location_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);



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

