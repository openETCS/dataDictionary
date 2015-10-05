
#include "National_Values_Core.h"
#include "Bit64.h"

int National_Values_UpperBitsNotSet(const National_Values_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_VALIDNV,         15);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && National_Values_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->V_NVSHUNT,         7) ;
    status = status && UpperBitsNotSet64(p->V_NVSTFF,          7) ;
    status = status && UpperBitsNotSet64(p->V_NVONSIGHT,       7) ;
    status = status && UpperBitsNotSet64(p->V_NVUNFIT,         7) ;
    status = status && UpperBitsNotSet64(p->V_NVREL,           7) ;
    status = status && UpperBitsNotSet64(p->D_NVROLL,          15);
    status = status && UpperBitsNotSet64(p->Q_NVSRBKTRG,       1) ;
    status = status && UpperBitsNotSet64(p->Q_NVEMRRLS,        1) ;
    status = status && UpperBitsNotSet64(p->V_NVALLOWOVTRP,    7) ;
    status = status && UpperBitsNotSet64(p->V_NVSUPOVTRP,      7) ;
    status = status && UpperBitsNotSet64(p->D_NVOVTRP,         15);
    status = status && UpperBitsNotSet64(p->T_NVOVTRP,         8) ;
    status = status && UpperBitsNotSet64(p->D_NVPOTRP,         15);
    status = status && UpperBitsNotSet64(p->M_NVCONTACT,       2) ;
    status = status && UpperBitsNotSet64(p->T_NVCONTACT,       8) ;
    status = status && UpperBitsNotSet64(p->M_NVDERUN,         1) ;
    status = status && UpperBitsNotSet64(p->D_NVSTFF,          15);
    status = status && UpperBitsNotSet64(p->Q_NVDRIVER_ADHES,  1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int National_Values_Encode_Bit(Bitstream* stream, const National_Values_Core* p)
{
    if (Bitstream_Normal(stream, NATIONAL_VALUES_CORE_BITSIZE))
    {
        if (National_Values_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_VALIDNV);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                National_Values_Core_1_Encode_Bit(stream, &(p->sub_1[i]));
            }
            Bitstream_Write(stream, 7,  p->V_NVSHUNT);
            Bitstream_Write(stream, 7,  p->V_NVSTFF);
            Bitstream_Write(stream, 7,  p->V_NVONSIGHT);
            Bitstream_Write(stream, 7,  p->V_NVUNFIT);
            Bitstream_Write(stream, 7,  p->V_NVREL);
            Bitstream_Write(stream, 15, p->D_NVROLL);
            Bitstream_Write(stream, 1,  p->Q_NVSRBKTRG);
            Bitstream_Write(stream, 1,  p->Q_NVEMRRLS);
            Bitstream_Write(stream, 7,  p->V_NVALLOWOVTRP);
            Bitstream_Write(stream, 7,  p->V_NVSUPOVTRP);
            Bitstream_Write(stream, 15, p->D_NVOVTRP);
            Bitstream_Write(stream, 8,  p->T_NVOVTRP);
            Bitstream_Write(stream, 15, p->D_NVPOTRP);
            Bitstream_Write(stream, 2,  p->M_NVCONTACT);
            Bitstream_Write(stream, 8,  p->T_NVCONTACT);
            Bitstream_Write(stream, 1,  p->M_NVDERUN);
            Bitstream_Write(stream, 15, p->D_NVSTFF);
            Bitstream_Write(stream, 1,  p->Q_NVDRIVER_ADHES);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_VALIDNV:         EqualBits(stream, pos + 17,  pos + 32,  p->D_VALIDNV);

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

int National_Values_Decode_Bit(Bitstream* stream, National_Values_Core* p)
{
    if (Bitstream_Normal(stream, NATIONAL_VALUES_CORE_BITSIZE))
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
          requires D_VALIDNV:      stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_VALIDNV;
          ensures  D_VALIDNV:      stream->bitpos == pos + 32;
          ensures  D_VALIDNV:      EqualBits(stream, pos + 17, pos + 32, p->D_VALIDNV);
          ensures  D_VALIDNV:      UpperBitsNotSet(p->D_VALIDNV, 15);
        */
        {
            p->D_VALIDNV        = Bitstream_Read(stream, 15);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            National_Values_Core_1_Decode_Bit(stream, &(p->sub_1[i]));
        }
        {
            p->V_NVSHUNT        = Bitstream_Read(stream, 7);
        }

        {
            p->V_NVSTFF        = Bitstream_Read(stream, 7);
        }

        {
            p->V_NVONSIGHT        = Bitstream_Read(stream, 7);
        }

        {
            p->V_NVUNFIT        = Bitstream_Read(stream, 7);
        }

        {
            p->V_NVREL        = Bitstream_Read(stream, 7);
        }

        {
            p->D_NVROLL        = Bitstream_Read(stream, 15);
        }

        {
            p->Q_NVSRBKTRG        = Bitstream_Read(stream, 1);
        }

        {
            p->Q_NVEMRRLS        = Bitstream_Read(stream, 1);
        }

        {
            p->V_NVALLOWOVTRP        = Bitstream_Read(stream, 7);
        }

        {
            p->V_NVSUPOVTRP        = Bitstream_Read(stream, 7);
        }

        {
            p->D_NVOVTRP        = Bitstream_Read(stream, 15);
        }

        {
            p->T_NVOVTRP        = Bitstream_Read(stream, 8);
        }

        {
            p->D_NVPOTRP        = Bitstream_Read(stream, 15);
        }

        {
            p->M_NVCONTACT        = Bitstream_Read(stream, 2);
        }

        {
            p->T_NVCONTACT        = Bitstream_Read(stream, 8);
        }

        {
            p->M_NVDERUN        = Bitstream_Read(stream, 1);
        }

        {
            p->D_NVSTFF        = Bitstream_Read(stream, 15);
        }

        {
            p->Q_NVDRIVER_ADHES        = Bitstream_Read(stream, 1);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_VALIDNV:         EqualBits(stream, pos + 17,  pos + 32,  p->D_VALIDNV);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_VALIDNV:         UpperBitsNotSet(p->D_VALIDNV,         15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int National_Values_Encode_Int(PacketInfo* data, kcg_int* stream, const National_Values_Core* p)
{
    return 0;
}

int National_Values_Decode_Int(PacketInfo* data, const kcg_int* stream, National_Values_Core* p)
{
    return 0;
}

