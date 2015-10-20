
#include "TrackConditionChangeOfTractionPower.h"
#include "Bit64.h"

TrackConditionChangeOfTractionPower* TrackConditionChangeOfTractionPower_New(void)
{
    void* raw = malloc(sizeof(TrackConditionChangeOfTractionPower));
    TrackConditionChangeOfTractionPower* ptr = (TrackConditionChangeOfTractionPower*)raw;
    TrackConditionChangeOfTractionPower_Init(ptr);
    return ptr;
}


void TrackConditionChangeOfTractionPower_Delete(TrackConditionChangeOfTractionPower* ptr)
{
    free(ptr);
}


int TrackConditionChangeOfTractionPower_UpperBitsNotSet(const TrackConditionChangeOfTractionPower* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_TRACTION,        15);
    status = status && UpperBitsNotSet64(p->M_TRACTION,        8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int TrackConditionChangeOfTractionPower_EncodeBit(const TrackConditionChangeOfTractionPower* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRACKCONDITIONCHANGEOFTRACTIONPOWER_BITSIZE))
    {
        if (TrackConditionChangeOfTractionPower_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_TRACTION);
            Bitstream_Write(stream, 8,  p->M_TRACTION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_TRACTION:        EqualBits(stream, pos + 17,  pos + 32,  p->D_TRACTION);
            //@ assert M_TRACTION:        EqualBits(stream, pos + 32,  pos + 40,  p->M_TRACTION);

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

int TrackConditionChangeOfTractionPower_DecodeBit(TrackConditionChangeOfTractionPower* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRACKCONDITIONCHANGEOFTRACTIONPOWER_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires Q_DIR:          stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->Q_DIR;
          ensures  Q_DIR:          stream->bitpos == pos + 2;
          ensures  Q_DIR:          EqualBits(stream, pos + 0, pos + 2, p->Q_DIR);
          ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
        */
        {
            p->Q_DIR        = Bitstream_Read(stream, 2);
        }

        /*@
          requires L_PACKET:       stream->bitpos == pos + 2;
          assigns                  stream->bitpos;
          assigns                  p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 15;
          ensures  L_PACKET:       EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET        = Bitstream_Read(stream, 13);
        }

        /*@
          requires Q_SCALE:        stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_SCALE;
          ensures  Q_SCALE:        stream->bitpos == pos + 17;
          ensures  Q_SCALE:        EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
          ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
        */
        {
            p->Q_SCALE        = Bitstream_Read(stream, 2);
        }

        /*@
          requires D_TRACTION:     stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_TRACTION;
          ensures  D_TRACTION:     stream->bitpos == pos + 32;
          ensures  D_TRACTION:     EqualBits(stream, pos + 17, pos + 32, p->D_TRACTION);
          ensures  D_TRACTION:     UpperBitsNotSet(p->D_TRACTION, 15);
        */
        {
            p->D_TRACTION        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_TRACTION:     stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->M_TRACTION;
          ensures  M_TRACTION:     stream->bitpos == pos + 40;
          ensures  M_TRACTION:     EqualBits(stream, pos + 32, pos + 40, p->M_TRACTION);
          ensures  M_TRACTION:     UpperBitsNotSet(p->M_TRACTION, 8);
        */
        {
            p->M_TRACTION        = Bitstream_Read(stream, 8);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_TRACTION:        EqualBits(stream, pos + 17,  pos + 32,  p->D_TRACTION);
        //@ assert M_TRACTION:        EqualBits(stream, pos + 32,  pos + 40,  p->M_TRACTION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_TRACTION:        UpperBitsNotSet(p->D_TRACTION,        15);
        //@ assert M_TRACTION:        UpperBitsNotSet(p->M_TRACTION,        8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

/*
int TrackConditionChangeOfTractionPower_EncodeInt(const TrackConditionChangeOfTractionPower* p, PacketInfo* data, kcg_int* stream)
{

}

int TrackConditionChangeOfTractionPower_DecodeInt(TrackConditionChangeOfTractionPower* p, PacketInfo* data, kcg_int* stream)
{

}
*/

