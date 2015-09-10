
#include "Track_Condition_Station_Platforms_Core_1.h"
#include "Bit64.h"

int Track_Condition_Station_Platforms_Core_1_UpperBitsNotSet(const Track_Condition_Station_Platforms_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_TRACKCOND,       15);
    status = status && UpperBitsNotSet64(p->L_TRACKCOND,       15);
    status = status && UpperBitsNotSet64(p->M_PLATFORM,        4) ;
    status = status && UpperBitsNotSet64(p->Q_PLATFORM,        2) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Track_Condition_Station_Platforms_Core_1_Encoder(Bitstream* stream, const Track_Condition_Station_Platforms_Core_1* p)
{
    if (Bitstream_Normal(stream, TRACK_CONDITION_STATION_PLATFORMS_CORE_1_CORE_BITSIZE))
    {
        if (Track_Condition_Station_Platforms_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_TRACKCOND);
            Bitstream_Write(stream, 15, p->L_TRACKCOND);
            Bitstream_Write(stream, 4,  p->M_PLATFORM);
            Bitstream_Write(stream, 2,  p->Q_PLATFORM);


            //@ assert D_TRACKCOND:       EqualBits(stream, pos,       pos + 15,  p->D_TRACKCOND);
            //@ assert L_TRACKCOND:       EqualBits(stream, pos + 15,  pos + 30,  p->L_TRACKCOND);
            //@ assert M_PLATFORM:        EqualBits(stream, pos + 30,  pos + 34,  p->M_PLATFORM);
            //@ assert Q_PLATFORM:        EqualBits(stream, pos + 34,  pos + 36,  p->Q_PLATFORM);

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

int Track_Condition_Station_Platforms_Core_1_Decoder(Bitstream* stream, Track_Condition_Station_Platforms_Core_1* p)
{
    if (Bitstream_Normal(stream, TRACK_CONDITION_STATION_PLATFORMS_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_TRACKCOND:    stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_TRACKCOND;
          ensures  D_TRACKCOND:    stream->bitpos == pos + 15;
          ensures  D_TRACKCOND:    EqualBits(stream, pos + 0, pos + 15, p->D_TRACKCOND);
          ensures  D_TRACKCOND:    UpperBitsNotSet(p->D_TRACKCOND, 15);
        */
        {
            p->D_TRACKCOND        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_TRACKCOND:    stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->L_TRACKCOND;
          ensures  L_TRACKCOND:    stream->bitpos == pos + 30;
          ensures  L_TRACKCOND:    EqualBits(stream, pos + 15, pos + 30, p->L_TRACKCOND);
          ensures  L_TRACKCOND:    UpperBitsNotSet(p->L_TRACKCOND, 15);
        */
        {
            p->L_TRACKCOND        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_PLATFORM:     stream->bitpos == pos + 30;
          assigns                  stream->bitpos;
          assigns                  p->M_PLATFORM;
          ensures  M_PLATFORM:     stream->bitpos == pos + 34;
          ensures  M_PLATFORM:     EqualBits(stream, pos + 30, pos + 34, p->M_PLATFORM);
          ensures  M_PLATFORM:     UpperBitsNotSet(p->M_PLATFORM, 4);
        */
        {
            p->M_PLATFORM        = Bitstream_Read(stream, 4);
        }

        /*@
          requires Q_PLATFORM:     stream->bitpos == pos + 34;
          assigns                  stream->bitpos;
          assigns                  p->Q_PLATFORM;
          ensures  Q_PLATFORM:     stream->bitpos == pos + 36;
          ensures  Q_PLATFORM:     EqualBits(stream, pos + 34, pos + 36, p->Q_PLATFORM);
          ensures  Q_PLATFORM:     UpperBitsNotSet(p->Q_PLATFORM, 2);
        */
        {
            p->Q_PLATFORM        = Bitstream_Read(stream, 2);
        }

        //@ assert D_TRACKCOND:       EqualBits(stream, pos,       pos + 15,  p->D_TRACKCOND);
        //@ assert L_TRACKCOND:       EqualBits(stream, pos + 15,  pos + 30,  p->L_TRACKCOND);
        //@ assert M_PLATFORM:        EqualBits(stream, pos + 30,  pos + 34,  p->M_PLATFORM);
        //@ assert Q_PLATFORM:        EqualBits(stream, pos + 34,  pos + 36,  p->Q_PLATFORM);

        //@ assert D_TRACKCOND:       UpperBitsNotSet(p->D_TRACKCOND,       15);
        //@ assert L_TRACKCOND:       UpperBitsNotSet(p->L_TRACKCOND,       15);
        //@ assert M_PLATFORM:        UpperBitsNotSet(p->M_PLATFORM,        4);
        //@ assert Q_PLATFORM:        UpperBitsNotSet(p->Q_PLATFORM,        2);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

