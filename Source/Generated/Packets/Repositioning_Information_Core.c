
#include "Repositioning_Information_Core.h"
#include "Bit64.h"

int Repositioning_Information_UpperBitsNotSet(const Repositioning_Information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->L_SECTION,         15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Repositioning_Information_Encoder(Bitstream* stream, const Repositioning_Information_Core* p)
{
    if (Bitstream_Normal(stream, REPOSITIONING_INFORMATION_CORE_BITSIZE))
    {
        if (Repositioning_Information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->L_SECTION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert L_SECTION:         EqualBits(stream, pos + 17,  pos + 32,  p->L_SECTION);

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

int Repositioning_Information_Decoder(Bitstream* stream, Repositioning_Information_Core* p)
{
    if (Bitstream_Normal(stream, REPOSITIONING_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires Q_DIR:          stream->bitpos == pos + 0;
          assigns        	   stream->bitpos;
          assigns		   p->Q_DIR;
          ensures  Q_DIR:          stream->bitpos == pos + 2;
          ensures  Q_DIR:          EqualBits(stream, pos + 0, pos + 2, p->Q_DIR);
          ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
        */
        {
            p->Q_DIR		= Bitstream_Read(stream, 2);
        }

        /*@
          requires L_PACKET:       stream->bitpos == pos + 2;
          assigns        	   stream->bitpos;
          assigns		   p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 15;
          ensures  L_PACKET:       EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET		= Bitstream_Read(stream, 13);
        }

        /*@
          requires Q_SCALE:        stream->bitpos == pos + 15;
          assigns        	   stream->bitpos;
          assigns		   p->Q_SCALE;
          ensures  Q_SCALE:        stream->bitpos == pos + 17;
          ensures  Q_SCALE:        EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
          ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
        */
        {
            p->Q_SCALE		= Bitstream_Read(stream, 2);
        }

        /*@
          requires L_SECTION:      stream->bitpos == pos + 17;
          assigns        	   stream->bitpos;
          assigns		   p->L_SECTION;
          ensures  L_SECTION:      stream->bitpos == pos + 32;
          ensures  L_SECTION:      EqualBits(stream, pos + 17, pos + 32, p->L_SECTION);
          ensures  L_SECTION:      UpperBitsNotSet(p->L_SECTION, 15);
        */
        {
            p->L_SECTION		= Bitstream_Read(stream, 15);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert L_SECTION:         EqualBits(stream, pos + 17,  pos + 32,  p->L_SECTION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert L_SECTION:         UpperBitsNotSet(p->L_SECTION,         15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

