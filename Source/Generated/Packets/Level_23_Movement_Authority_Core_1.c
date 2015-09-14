
#include "Level_23_Movement_Authority_Core_1.h"
#include "Bit64.h"

int Level_23_Movement_Authority_Core_1_UpperBitsNotSet(const Level_23_Movement_Authority_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_SECTION,         15);
    status = status && UpperBitsNotSet64(p->Q_SECTIONTIMER,    1) ;
    status = status && UpperBitsNotSet64(p->T_SECTIONTIMER,    10);
    status = status && UpperBitsNotSet64(p->D_SECTIONTIMERSTOPLOC, 15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Level_23_Movement_Authority_Core_1_Encode_Bit(Bitstream* stream, const Level_23_Movement_Authority_Core_1* p)
{
    if (Bitstream_Normal(stream, LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE))
    {
        if (Level_23_Movement_Authority_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->L_SECTION);
            Bitstream_Write(stream, 1,  p->Q_SECTIONTIMER);
            Bitstream_Write(stream, 10, p->T_SECTIONTIMER);
            Bitstream_Write(stream, 15, p->D_SECTIONTIMERSTOPLOC);


            //@ assert L_SECTION:         EqualBits(stream, pos,       pos + 15,  p->L_SECTION);
            //@ assert Q_SECTIONTIMER:    EqualBits(stream, pos + 15,  pos + 16,  p->Q_SECTIONTIMER);
            //@ assert T_SECTIONTIMER:    EqualBits(stream, pos + 16,  pos + 26,  p->T_SECTIONTIMER);
            //@ assert D_SECTIONTIMERSTOPLOC: EqualBits(stream, pos + 26,  pos + 41,  p->D_SECTIONTIMERSTOPLOC);

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

int Level_23_Movement_Authority_Core_1_Decode_Bit(Bitstream* stream, Level_23_Movement_Authority_Core_1* p)
{
    if (Bitstream_Normal(stream, LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires L_SECTION:      stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->L_SECTION;
          ensures  L_SECTION:      stream->bitpos == pos + 15;
          ensures  L_SECTION:      EqualBits(stream, pos + 0, pos + 15, p->L_SECTION);
          ensures  L_SECTION:      UpperBitsNotSet(p->L_SECTION, 15);
        */
        {
            p->L_SECTION        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_SECTIONTIMER: stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_SECTIONTIMER;
          ensures  Q_SECTIONTIMER: stream->bitpos == pos + 16;
          ensures  Q_SECTIONTIMER: EqualBits(stream, pos + 15, pos + 16, p->Q_SECTIONTIMER);
          ensures  Q_SECTIONTIMER: UpperBitsNotSet(p->Q_SECTIONTIMER, 1);
        */
        {
            p->Q_SECTIONTIMER        = Bitstream_Read(stream, 1);
        }

        /*@
          requires T_SECTIONTIMER: stream->bitpos == pos + 16;
          assigns                  stream->bitpos;
          assigns                  p->T_SECTIONTIMER;
          ensures  T_SECTIONTIMER: stream->bitpos == pos + 26;
          ensures  T_SECTIONTIMER: EqualBits(stream, pos + 16, pos + 26, p->T_SECTIONTIMER);
          ensures  T_SECTIONTIMER: UpperBitsNotSet(p->T_SECTIONTIMER, 10);
        */
        {
            p->T_SECTIONTIMER        = Bitstream_Read(stream, 10);
        }

        /*@
          requires D_SECTIONTIMERSTOPLOC: stream->bitpos == pos + 26;
          assigns                  stream->bitpos;
          assigns                  p->D_SECTIONTIMERSTOPLOC;
          ensures  D_SECTIONTIMERSTOPLOC: stream->bitpos == pos + 41;
          ensures  D_SECTIONTIMERSTOPLOC: EqualBits(stream, pos + 26, pos + 41, p->D_SECTIONTIMERSTOPLOC);
          ensures  D_SECTIONTIMERSTOPLOC: UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC, 15);
        */
        {
            p->D_SECTIONTIMERSTOPLOC        = Bitstream_Read(stream, 15);
        }

        //@ assert L_SECTION:         EqualBits(stream, pos,       pos + 15,  p->L_SECTION);
        //@ assert Q_SECTIONTIMER:    EqualBits(stream, pos + 15,  pos + 16,  p->Q_SECTIONTIMER);
        //@ assert T_SECTIONTIMER:    EqualBits(stream, pos + 16,  pos + 26,  p->T_SECTIONTIMER);
        //@ assert D_SECTIONTIMERSTOPLOC: EqualBits(stream, pos + 26,  pos + 41,  p->D_SECTIONTIMERSTOPLOC);

        //@ assert L_SECTION:         UpperBitsNotSet(p->L_SECTION,         15);
        //@ assert Q_SECTIONTIMER:    UpperBitsNotSet(p->Q_SECTIONTIMER,    1);
        //@ assert T_SECTIONTIMER:    UpperBitsNotSet(p->T_SECTIONTIMER,    10);
        //@ assert D_SECTIONTIMERSTOPLOC: UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC, 15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Level_23_Movement_Authority_Core_1_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Level_23_Movement_Authority_Core_1* p)
{
    std::cerr << "encode int function not implemented for packet 15 yet." << std::endl;
    return 0;
}

int Level_23_Movement_Authority_Core_1_Decode_Int(const Packet_Info* data, const kcg_int* stream, Level_23_Movement_Authority_Core_1* p)
{
    std::cerr << "decode int function not implemented for packet  15 yet." << std::endl;
    return 0;
}

