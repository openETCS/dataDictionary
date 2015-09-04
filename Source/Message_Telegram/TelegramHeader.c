
#include "TelegramHeader.h"
#include "Bitstream_Normal.h"
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"
#include "UpperBitsNotSet.h"

int TelegramHeader_Decoder(Bitstream* stream, TelegramHeader* p)
{
    if (Bitstream_Normal(stream, TELEGRAM_HEADER_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
           requires Q_UPDOWN: stream->bitpos == pos;
           assigns            stream->bitpos;
           assigns            p->Q_UPDOWN;
           ensures  Q_UPDOWN: stream->bitpos == pos + 1;
           ensures  Q_UPDOWN: EqualBits(stream, pos, pos + 1, p->Q_UPDOWN);
           ensures  Q_UPDOWN: UpperBitsNotSet(p->Q_UPDOWN, 1);
        */
        {
            p->Q_UPDOWN    = Bitstream_Read(stream, 1);
        }

        /*@
           requires M_VERSION: stream->bitpos == pos + 1;
           assigns             stream->bitpos;
           assigns             p->M_VERSION;
           ensures  M_VERSION: stream->bitpos == pos + 8;
           ensures  M_VERSION: EqualBits(stream, pos + 1, pos + 8, p->M_VERSION);
           ensures  M_VERSION: UpperBitsNotSet(p->M_VERSION, 7);
        */
        {
            p->M_VERSION    = Bitstream_Read(stream, 7);
        }

        /*@
           requires Q_MEDIA: stream->bitpos == pos + 8;
           assigns           stream->bitpos;
           assigns           p->Q_MEDIA;
           ensures  Q_MEDIA: stream->bitpos == pos + 9;
           ensures  Q_MEDIA: EqualBits(stream, pos + 8, pos + 9, p->Q_MEDIA);
           ensures  Q_MEDIA: UpperBitsNotSet(p->Q_MEDIA, 1);
        */
        {
            p->Q_MEDIA    = Bitstream_Read(stream, 1);
        }

        /*@
           requires N_PIG: stream->bitpos == pos + 9;
           assigns         stream->bitpos;
           assigns         p->N_PIG;
           ensures  N_PIG: stream->bitpos == pos + 12;
           ensures  N_PIG: EqualBits(stream, pos + 9, pos + 12, p->N_PIG);
           ensures  N_PIG: UpperBitsNotSet(p->N_PIG, 3);
        */
        {
            p->N_PIG    = Bitstream_Read(stream, 3);
        }

        /*@
           requires N_TOTAL: stream->bitpos == pos + 12;
           assigns           stream->bitpos;
           assigns           p->N_TOTAL;
           ensures  N_TOTAL: stream->bitpos == pos + 15;
           ensures  N_TOTAL: EqualBits(stream, pos + 12, pos + 15, p->N_TOTAL);
           ensures  N_TOTAL: UpperBitsNotSet(p->N_TOTAL, 3);
        */
        {
            p->N_TOTAL    = Bitstream_Read(stream, 3);
        }

        /*@
           requires M_DUP: stream->bitpos == pos + 15;
           assigns         stream->bitpos;
           assigns         p->M_DUP;
           ensures  M_DUP: stream->bitpos == pos + 17;
           ensures  M_DUP: EqualBits(stream, pos + 15, pos + 17, p->M_DUP);
           ensures  M_DUP: UpperBitsNotSet(p->M_DUP, 2);
        */
        {
            p->M_DUP    = Bitstream_Read(stream, 2);
        }

        /*@
           requires M_MCOUNT: stream->bitpos == pos + 17;
           assigns            stream->bitpos;
           assigns            p->M_MCOUNT;
           ensures  M_MCOUNT: stream->bitpos == pos + 25;
           ensures  M_MCOUNT: EqualBits(stream, pos + 17, pos + 25, p->M_MCOUNT);
           ensures  M_MCOUNT: UpperBitsNotSet(p->M_MCOUNT, 8);
        */
        {
            p->M_MCOUNT    = Bitstream_Read(stream, 8);
        }

        /*@
           requires NID_C: stream->bitpos == pos + 25;
           assigns         stream->bitpos;
           assigns         p->NID_C;
           ensures  NID_C: stream->bitpos == pos + 35;
           ensures  NID_C: EqualBits(stream, pos + 25, pos + 35, p->NID_C);
           ensures  NID_C: UpperBitsNotSet(p->NID_C, 10);
        */
        {
            p->NID_C    = Bitstream_Read(stream, 10);
        }

        /*@
           requires NID_BG: stream->bitpos == pos + 35;
           assigns          stream->bitpos;
           assigns          p->NID_BG;
           ensures  NID_BG: stream->bitpos == pos + 49;
           ensures  NID_BG: EqualBits(stream, pos + 35, pos + 49, p->NID_BG);
           ensures  NID_BG: UpperBitsNotSet(p->NID_BG, 14);
        */
        {
            p->NID_BG    = Bitstream_Read(stream, 14);
        }

        /*@
           requires Q_LINK: stream->bitpos == pos + 49;
           assigns          stream->bitpos;
           assigns          p->Q_LINK;
           ensures  Q_LINK: stream->bitpos == pos + 50;
           ensures  Q_LINK: EqualBits(stream, pos + 49, pos + 50, p->Q_LINK);
           ensures  Q_LINK: UpperBitsNotSet(p->Q_LINK, 1);
        */
        {
            p->Q_LINK    = Bitstream_Read(stream, 1);
        }

        //@ assert stream->bitpos == \at(stream->bitpos,Pre) + TELEGRAM_HEADER_BITSIZE;

        //@ assert  Q_UPDOWN: EqualBits(stream, pos, pos + 1, p->Q_UPDOWN);
        //@ assert  Q_UPDOWN: UpperBitsNotSet(p->Q_UPDOWN, 1);

        //@ assert  M_VERSION: EqualBits(stream, pos + 1, pos + 8, p->M_VERSION);
        //@ assert  M_VERSION: UpperBitsNotSet(p->M_VERSION, 7);

        //@ assert  Q_MEDIA: EqualBits(stream, pos + 8, pos + 9, p->Q_MEDIA);
        //@ assert  Q_MEDIA: UpperBitsNotSet(p->Q_MEDIA, 1);

        //@ assert  N_PIG: EqualBits(stream, pos + 9, pos + 12, p->N_PIG);
        //@ assert  N_PIG: UpperBitsNotSet(p->N_PIG, 3);

        //@ assert  N_TOTAL: EqualBits(stream, pos + 12, pos + 15, p->N_TOTAL);
        //@ assert  N_TOTAL: UpperBitsNotSet(p->N_TOTAL, 3);

        //@ assert  M_DUP: EqualBits(stream, pos + 15, pos + 17, p->M_DUP);
        //@ assert  M_DUP: UpperBitsNotSet(p->M_DUP, 2);

        //@ assert  M_MCOUNT: EqualBits(stream, pos + 17, pos + 25, p->M_MCOUNT);
        //@ assert  M_MCOUNT: UpperBitsNotSet(p->M_MCOUNT, 8);

        //@ assert  NID_C: EqualBits(stream, pos + 25, pos + 35, p->NID_C);
        //@ assert  NID_C: UpperBitsNotSet(p->NID_C, 10);

        //@ assert  NID_BG: EqualBits(stream, pos + 35, pos + 49, p->NID_BG);
        //@ assert  NID_BG: UpperBitsNotSet(p->NID_BG, 14);

        //@ assert  Q_LINK: EqualBits(stream, pos + 49, pos + 50, p->Q_LINK);
        //@ assert  Q_LINK: UpperBitsNotSet(p->Q_LINK, 1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int TelegramHeader_Encoder(Bitstream* stream, const TelegramHeader* p)
{
    if (Bitstream_Normal(stream, TELEGRAM_HEADER_BITSIZE))
    {
        if (TelegramHeader_UpperBitsNotSet(p))
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


int TelegramHeader_UpperBitsNotSet(const TelegramHeader* p)
{
    if (UpperBitsNotSet64(p->Q_UPDOWN,      1)  &&
        UpperBitsNotSet64(p->M_VERSION,     7)  &&
        UpperBitsNotSet64(p->Q_MEDIA,       1)  &&
        UpperBitsNotSet64(p->N_PIG,         3)  &&
        UpperBitsNotSet64(p->N_TOTAL,       3)  &&
        UpperBitsNotSet64(p->M_DUP,         2)  &&
        UpperBitsNotSet64(p->M_MCOUNT,      8)  &&
        UpperBitsNotSet64(p->NID_C,         10) &&
        UpperBitsNotSet64(p->NID_BG,        14) &&
        UpperBitsNotSet64(p->Q_LINK,        1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

