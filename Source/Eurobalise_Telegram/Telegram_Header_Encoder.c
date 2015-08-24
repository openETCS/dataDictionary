
#include "Telegram_Header_Encoder.h"
#include "Telegram_Header_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Normal.h"

int Telegram_Header_Encoder(Bitstream* stream, const Telegram_Header* p)
{
    if (Bitstream_Normal(stream, TELEGRAM_HEADER_BITSIZE))
    {
        if (Telegram_Header_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

	    Bitstream_Write(stream, 1,  p->Q_UPDOWN);
	    Bitstream_Write(stream, 7,  p->M_VERSION);
	    Bitstream_Write(stream, 1,  p->Q_MEDIA);
	    Bitstream_Write(stream, 3,  p->N_PIG);
	    Bitstream_Write(stream, 3,  p->N_TOTAL);
	    Bitstream_Write(stream, 2,  p->M_DUP);
	    Bitstream_Write(stream, 8,  p->M_MCOUNT);
	    Bitstream_Write(stream, 10, p->NID_C);
	    Bitstream_Write(stream, 14, p->NID_BG);
	    Bitstream_Write(stream, 1,  p->Q_LINK);

	    //@ assert Q_UPDOWN:          EqualBits(stream, pos,       pos + 1,   p->Q_UPDOWN);
            //@ assert M_VERSION:         EqualBits(stream, pos + 1,   pos + 8,   p->M_VERSION);
            //@ assert Q_MEDIA:           EqualBits(stream, pos + 8,   pos + 9,   p->Q_MEDIA);
            //@ assert N_PIG:             EqualBits(stream, pos + 9,   pos + 12,  p->N_PIG);
            //@ assert N_TOTAL:           EqualBits(stream, pos + 12,  pos + 15,  p->N_TOTAL);
            //@ assert M_DUP:             EqualBits(stream, pos + 15,  pos + 17,  p->M_DUP);
            //@ assert M_MCOUNT:          EqualBits(stream, pos + 17,  pos + 25,  p->M_MCOUNT);
            //@ assert NID_C:             EqualBits(stream, pos + 25,  pos + 35,  p->NID_C);
            //@ assert NID_BG:            EqualBits(stream, pos + 35,  pos + 49,  p->NID_BG);
            //@ assert Q_LINK:            EqualBits(stream, pos + 49,  pos + 50,  p->Q_LINK);

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

