
#include "Level_1_Movement_Authority_Core.h"
#include "Bit64.h"

int Level_1_Movement_Authority_UpperBitsNotSet(const Level_1_Movement_Authority_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->V_MAIN,            7) ;
    status = status && UpperBitsNotSet64(p->V_LOA,             7) ;
    status = status && UpperBitsNotSet64(p->T_LOA,             10);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Level_1_Movement_Authority_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->L_ENDSECTION,      15);
    status = status && UpperBitsNotSet64(p->Q_SECTIONTIMER,    1) ;
    status = status && UpperBitsNotSet64(p->T_SECTIONTIMER,    10);
    status = status && UpperBitsNotSet64(p->D_SECTIONTIMERSTOPLOC, 15);
    status = status && UpperBitsNotSet64(p->Q_ENDTIMER,        1) ;
    status = status && UpperBitsNotSet64(p->T_ENDTIMER,        10);
    status = status && UpperBitsNotSet64(p->D_ENDTIMERSTARTLOC, 15);
    status = status && UpperBitsNotSet64(p->Q_DANGERPOINT,     1) ;
    status = status && UpperBitsNotSet64(p->D_DP,              15);
    status = status && UpperBitsNotSet64(p->V_RELEASEDP,       7) ;
    status = status && UpperBitsNotSet64(p->Q_OVERLAP,         1) ;
    status = status && UpperBitsNotSet64(p->D_STARTOL,         15);
    status = status && UpperBitsNotSet64(p->T_OL,              10);
    status = status && UpperBitsNotSet64(p->D_OL,              15);
    status = status && UpperBitsNotSet64(p->V_RELEASEOL,       7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Level_1_Movement_Authority_Encode_Bit(Bitstream* stream, const Level_1_Movement_Authority_Core* p)
{
    if (Bitstream_Normal(stream, LEVEL_1_MOVEMENT_AUTHORITY_CORE_BITSIZE))
    {
        if (Level_1_Movement_Authority_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 7,  p->V_MAIN);
            Bitstream_Write(stream, 7,  p->V_LOA);
            Bitstream_Write(stream, 10, p->T_LOA);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Level_1_Movement_Authority_Core_1_Encode_Bit(stream, &(p->sub_1[i]));
            }
            Bitstream_Write(stream, 15, p->L_ENDSECTION);
            Bitstream_Write(stream, 1,  p->Q_SECTIONTIMER);
            Bitstream_Write(stream, 10, p->T_SECTIONTIMER);
            Bitstream_Write(stream, 15, p->D_SECTIONTIMERSTOPLOC);
            Bitstream_Write(stream, 1,  p->Q_ENDTIMER);
            Bitstream_Write(stream, 10, p->T_ENDTIMER);
            Bitstream_Write(stream, 15, p->D_ENDTIMERSTARTLOC);
            Bitstream_Write(stream, 1,  p->Q_DANGERPOINT);
            Bitstream_Write(stream, 15, p->D_DP);
            Bitstream_Write(stream, 7,  p->V_RELEASEDP);
            Bitstream_Write(stream, 1,  p->Q_OVERLAP);
            Bitstream_Write(stream, 15, p->D_STARTOL);
            Bitstream_Write(stream, 10, p->T_OL);
            Bitstream_Write(stream, 15, p->D_OL);
            Bitstream_Write(stream, 7,  p->V_RELEASEOL);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert V_MAIN:            EqualBits(stream, pos + 17,  pos + 24,  p->V_MAIN);
            //@ assert V_LOA:             EqualBits(stream, pos + 24,  pos + 31,  p->V_LOA);
            //@ assert T_LOA:             EqualBits(stream, pos + 31,  pos + 41,  p->T_LOA);

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

int Level_1_Movement_Authority_Decode_Bit(Bitstream* stream, Level_1_Movement_Authority_Core* p)
{
    if (Bitstream_Normal(stream, LEVEL_1_MOVEMENT_AUTHORITY_CORE_BITSIZE))
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
          requires V_MAIN:         stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->V_MAIN;
          ensures  V_MAIN:         stream->bitpos == pos + 24;
          ensures  V_MAIN:         EqualBits(stream, pos + 17, pos + 24, p->V_MAIN);
          ensures  V_MAIN:         UpperBitsNotSet(p->V_MAIN, 7);
        */
        {
            p->V_MAIN        = Bitstream_Read(stream, 7);
        }

        /*@
          requires V_LOA:          stream->bitpos == pos + 24;
          assigns                  stream->bitpos;
          assigns                  p->V_LOA;
          ensures  V_LOA:          stream->bitpos == pos + 31;
          ensures  V_LOA:          EqualBits(stream, pos + 24, pos + 31, p->V_LOA);
          ensures  V_LOA:          UpperBitsNotSet(p->V_LOA, 7);
        */
        {
            p->V_LOA        = Bitstream_Read(stream, 7);
        }

        /*@
          requires T_LOA:          stream->bitpos == pos + 31;
          assigns                  stream->bitpos;
          assigns                  p->T_LOA;
          ensures  T_LOA:          stream->bitpos == pos + 41;
          ensures  T_LOA:          EqualBits(stream, pos + 31, pos + 41, p->T_LOA);
          ensures  T_LOA:          UpperBitsNotSet(p->T_LOA, 10);
        */
        {
            p->T_LOA        = Bitstream_Read(stream, 10);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Level_1_Movement_Authority_Core_1_Decode_Bit(stream, &(p->sub_1[i]));
        }
        {
            p->L_ENDSECTION        = Bitstream_Read(stream, 15);
        }

        {
            p->Q_SECTIONTIMER        = Bitstream_Read(stream, 1);
        }

        {
            p->T_SECTIONTIMER        = Bitstream_Read(stream, 10);
        }

        {
            p->D_SECTIONTIMERSTOPLOC        = Bitstream_Read(stream, 15);
        }

        {
            p->Q_ENDTIMER        = Bitstream_Read(stream, 1);
        }

        {
            p->T_ENDTIMER        = Bitstream_Read(stream, 10);
        }

        {
            p->D_ENDTIMERSTARTLOC        = Bitstream_Read(stream, 15);
        }

        {
            p->Q_DANGERPOINT        = Bitstream_Read(stream, 1);
        }

        {
            p->D_DP        = Bitstream_Read(stream, 15);
        }

        {
            p->V_RELEASEDP        = Bitstream_Read(stream, 7);
        }

        {
            p->Q_OVERLAP        = Bitstream_Read(stream, 1);
        }

        {
            p->D_STARTOL        = Bitstream_Read(stream, 15);
        }

        {
            p->T_OL        = Bitstream_Read(stream, 10);
        }

        {
            p->D_OL        = Bitstream_Read(stream, 15);
        }

        {
            p->V_RELEASEOL        = Bitstream_Read(stream, 7);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert V_MAIN:            EqualBits(stream, pos + 17,  pos + 24,  p->V_MAIN);
        //@ assert V_LOA:             EqualBits(stream, pos + 24,  pos + 31,  p->V_LOA);
        //@ assert T_LOA:             EqualBits(stream, pos + 31,  pos + 41,  p->T_LOA);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert V_MAIN:            UpperBitsNotSet(p->V_MAIN,            7);
        //@ assert V_LOA:             UpperBitsNotSet(p->V_LOA,             7);
        //@ assert T_LOA:             UpperBitsNotSet(p->T_LOA,             10);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Level_1_Movement_Authority_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Level_1_Movement_Authority_Core* p)
{
    std::cerr << "encode int function not implemented for packet " << 12 << " yet." << std::endl;
    return 0;
}

int Level_1_Movement_Authority_Decode_Int(const Packet_Info* data, const kcg_int* stream, Level_1_Movement_Authority_Core* p)
{
    std::cerr << "decode int function not implemented for packet " << 12 << " yet." << std::endl;
    return 0;
}

