
#include "List_of_Balises_in_SR_Authority_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int List_of_Balises_in_SR_Authority_Core_1_UpperBitsNotSet(const List_of_Balises_in_SR_Authority_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_k,    1) ;
    if (p->Q_NEWCOUNTRY_k == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C_k,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_k,          14);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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


            //@ assert Q_NEWCOUNTRY_k:    EqualBits(stream, pos + 20,  pos + 21,  p->Q_NEWCOUNTRY_k);

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

int List_of_Balises_in_SR_Authority_Core_1_Decoder(Bitstream* stream, List_of_Balises_in_SR_Authority_Core_1* p)
{
    if (NormalBitstream(stream, LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires Q_NEWCOUNTRY_k: stream->bitpos == pos + 20;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NEWCOUNTRY_k;
	  ensures  Q_NEWCOUNTRY_k: stream->bitpos == pos + 21;
	  ensures  Q_NEWCOUNTRY_k: EqualBits(stream, pos + 20, pos + 21, p->Q_NEWCOUNTRY_k);
	  ensures  Q_NEWCOUNTRY_k: UpperBitsNotSet(p->Q_NEWCOUNTRY_k, 1);
	*/
	{ p->Q_NEWCOUNTRY_k		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY_k == 1)
        {
	{ p->NID_C_k		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG_k		= Bitstream_Read(stream, 14); }

        //@ assert Q_NEWCOUNTRY_k:    EqualBits(stream, pos + 20,  pos + 21,  p->Q_NEWCOUNTRY_k);

        //@ assert Q_NEWCOUNTRY_k:    UpperBitsNotSet(p->Q_NEWCOUNTRY_k,    1);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

