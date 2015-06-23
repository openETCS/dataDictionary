
#include "List_of_Balises_in_SR_Authority_Core_1_Encoder.h"
#include "List_of_Balises_in_SR_Authority_Core_1_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int List_of_Balises_in_SR_Authority_Core_1_Encoder(Bitstream* stream, const List_of_Balises_in_SR_Authority_Core_1* p)
{
    if (NormalBitstream(stream, LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_BITSIZE))
    {
        if (List_of_Balises_in_SR_Authority_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_k);
            if (p->Q_NEWCOUNTRY_k == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C_k);
            }

            Bitstream_Write(stream, 14, p->NID_BG_k);



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

