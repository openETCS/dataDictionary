
#include "Linking_Core_1.h"
#include "Bit64.h"

int Linking_Core_1_UpperBitsNotSet(const Linking_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_LINK,            15);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;

    if (p->Q_NEWCOUNTRY == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_C,             10);
    }

    status = status && UpperBitsNotSet64(p->NID_BG,            14);
    status = status && UpperBitsNotSet64(p->Q_LINKORIENTATION, 1) ;
    status = status && UpperBitsNotSet64(p->Q_LINKREACTION,    2) ;
    status = status && UpperBitsNotSet64(p->Q_LOCACC,          6) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Linking_Core_1_Encoder(Bitstream* stream, const Linking_Core_1* p)
{
    if (Bitstream_Normal(stream, LINKING_CORE_1_CORE_BITSIZE))
    {
        if (Linking_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_LINK);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);

            if (p->Q_NEWCOUNTRY == 1)
            {
                Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);
            Bitstream_Write(stream, 1,  p->Q_LINKORIENTATION);
            Bitstream_Write(stream, 2,  p->Q_LINKREACTION);
            Bitstream_Write(stream, 6,  p->Q_LOCACC);


            //@ assert D_LINK:            EqualBits(stream, pos,       pos + 15,  p->D_LINK);
            //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

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

int Linking_Core_1_Decoder(Bitstream* stream, Linking_Core_1* p)
{
    if (Bitstream_Normal(stream, LINKING_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_LINK:         stream->bitpos == pos + 0;
          assigns        	   stream->bitpos;
          assigns		   p->D_LINK;
          ensures  D_LINK:         stream->bitpos == pos + 15;
          ensures  D_LINK:         EqualBits(stream, pos + 0, pos + 15, p->D_LINK);
          ensures  D_LINK:         UpperBitsNotSet(p->D_LINK, 15);
        */
        {
            p->D_LINK		= Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_NEWCOUNTRY:   stream->bitpos == pos + 15;
          assigns        	   stream->bitpos;
          assigns		   p->Q_NEWCOUNTRY;
          ensures  Q_NEWCOUNTRY:   stream->bitpos == pos + 16;
          ensures  Q_NEWCOUNTRY:   EqualBits(stream, pos + 15, pos + 16, p->Q_NEWCOUNTRY);
          ensures  Q_NEWCOUNTRY:   UpperBitsNotSet(p->Q_NEWCOUNTRY, 1);
        */
        {
            p->Q_NEWCOUNTRY		= Bitstream_Read(stream, 1);
        }

        if (p->Q_NEWCOUNTRY == 1)
        {
            {
                p->NID_C		= Bitstream_Read(stream, 10);
            }
        }

        {
            p->NID_BG		= Bitstream_Read(stream, 14);
        }

        {
            p->Q_LINKORIENTATION		= Bitstream_Read(stream, 1);
        }

        {
            p->Q_LINKREACTION		= Bitstream_Read(stream, 2);
        }

        {
            p->Q_LOCACC		= Bitstream_Read(stream, 6);
        }

        //@ assert D_LINK:            EqualBits(stream, pos,       pos + 15,  p->D_LINK);
        //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

        //@ assert D_LINK:            UpperBitsNotSet(p->D_LINK,            15);
        //@ assert Q_NEWCOUNTRY:      UpperBitsNotSet(p->Q_NEWCOUNTRY,      1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

