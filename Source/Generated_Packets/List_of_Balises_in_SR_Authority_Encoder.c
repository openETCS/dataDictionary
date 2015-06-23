
#include "List_of_Balises_in_SR_Authority_Encoder.h"
#include "List_of_Balises_in_SR_Authority_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "List_of_Balises_in_SR_Authority_Core_1_Encoder.h"

int List_of_Balises_in_SR_Authority_Encoder(Bitstream* stream, const List_of_Balises_in_SR_Authority_Core* p)
{
    if (NormalBitstream(stream, LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_BITSIZE))
    {
        if (List_of_Balises_in_SR_Authority_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                List_of_Balises_in_SR_Authority_Core_1_Encoder(stream, &(p->sub_1[i]));
            }



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

