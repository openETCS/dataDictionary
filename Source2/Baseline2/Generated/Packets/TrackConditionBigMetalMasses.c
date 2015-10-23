
#include "TrackConditionBigMetalMasses.h"
#include "Bit64.h"

TrackConditionBigMetalMasses* TrackConditionBigMetalMasses_New(void)
{
    void* raw = malloc(sizeof(TrackConditionBigMetalMasses));
    TrackConditionBigMetalMasses* ptr = (TrackConditionBigMetalMasses*)raw;
    TrackConditionBigMetalMasses_Init(ptr);
    return ptr;
}


void TrackConditionBigMetalMasses_Delete(TrackConditionBigMetalMasses* ptr)
{
    free(ptr);
}


int TrackConditionBigMetalMasses_UpperBitsNotSet(const TrackConditionBigMetalMasses* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_TRACKCOND,       15);
    status = status && UpperBitsNotSet64(p->L_TRACKCOND,       15);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && TrackConditionBigMetalMasses_1_UpperBitsNotSet(&(p->sub_1[i]));
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int TrackConditionBigMetalMasses_EncodeBit(const TrackConditionBigMetalMasses* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRACKCONDITIONBIGMETALMASSES_BITSIZE))
    {
        if (TrackConditionBigMetalMasses_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_TRACKCOND);
            Bitstream_Write(stream, 15, p->L_TRACKCOND);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                TrackConditionBigMetalMasses_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_TRACKCOND:       EqualBits(stream, pos + 17,  pos + 32,  p->D_TRACKCOND);
            //@ assert L_TRACKCOND:       EqualBits(stream, pos + 32,  pos + 47,  p->L_TRACKCOND);

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

int TrackConditionBigMetalMasses_DecodeBit(TrackConditionBigMetalMasses* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRACKCONDITIONBIGMETALMASSES_BITSIZE))
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
          requires D_TRACKCOND:    stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_TRACKCOND;
          ensures  D_TRACKCOND:    stream->bitpos == pos + 32;
          ensures  D_TRACKCOND:    EqualBits(stream, pos + 17, pos + 32, p->D_TRACKCOND);
          ensures  D_TRACKCOND:    UpperBitsNotSet(p->D_TRACKCOND, 15);
        */
        {
            p->D_TRACKCOND        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_TRACKCOND:    stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->L_TRACKCOND;
          ensures  L_TRACKCOND:    stream->bitpos == pos + 47;
          ensures  L_TRACKCOND:    EqualBits(stream, pos + 32, pos + 47, p->L_TRACKCOND);
          ensures  L_TRACKCOND:    UpperBitsNotSet(p->L_TRACKCOND, 15);
        */
        {
            p->L_TRACKCOND        = Bitstream_Read(stream, 15);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            TrackConditionBigMetalMasses_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_TRACKCOND:       EqualBits(stream, pos + 17,  pos + 32,  p->D_TRACKCOND);
        //@ assert L_TRACKCOND:       EqualBits(stream, pos + 32,  pos + 47,  p->L_TRACKCOND);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_TRACKCOND:       UpperBitsNotSet(p->D_TRACKCOND,       15);
        //@ assert L_TRACKCOND:       UpperBitsNotSet(p->L_TRACKCOND,       15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int TrackConditionBigMetalMasses_EncodeInt(const TrackConditionBigMetalMasses* p, PacketInfo* data, kcg_int* stream)
{
    return 0;
}

int TrackConditionBigMetalMasses_DecodeInt(TrackConditionBigMetalMasses* p, PacketInfo* data, kcg_int* stream)
{
    return 0;
}

