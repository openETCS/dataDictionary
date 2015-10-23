
#include "Level23MovementAuthority_1.h"
#include "Bit64.h"

Level23MovementAuthority_1* Level23MovementAuthority_1_New(void)
{
    void* raw = malloc(sizeof(Level23MovementAuthority_1));
    Level23MovementAuthority_1* ptr = (Level23MovementAuthority_1*)raw;
    Level23MovementAuthority_1_Init(ptr);
    return ptr;
}


void Level23MovementAuthority_1_Delete(Level23MovementAuthority_1* ptr)
{
    free(ptr);
}


int Level23MovementAuthority_1_UpperBitsNotSet(const Level23MovementAuthority_1* p)
{
    int status = 1;

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

int Level23MovementAuthority_1_EncodeBit(const Level23MovementAuthority_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LEVEL23MOVEMENTAUTHORITY_1_BITSIZE))
    {
        if (Level23MovementAuthority_1_UpperBitsNotSet(p))
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

int Level23MovementAuthority_1_DecodeBit(Level23MovementAuthority_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LEVEL23MOVEMENTAUTHORITY_1_BITSIZE))
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

int Level23MovementAuthority_1_EncodeInt(const Level23MovementAuthority_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->L_SECTION;
    stream[(*startAddress)++] = p->Q_SECTIONTIMER;
    stream[(*startAddress)++] = p->T_SECTIONTIMER;
    stream[(*startAddress)++] = p->D_SECTIONTIMERSTOPLOC;

    return 1;
}

int Level23MovementAuthority_1_DecodeInt(Level23MovementAuthority_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->L_SECTION = stream[(*startAddress)++];
    p->Q_SECTIONTIMER = stream[(*startAddress)++];
    p->T_SECTIONTIMER = stream[(*startAddress)++];
    p->D_SECTIONTIMERSTOPLOC = stream[(*startAddress)++];

    return 1;
}

