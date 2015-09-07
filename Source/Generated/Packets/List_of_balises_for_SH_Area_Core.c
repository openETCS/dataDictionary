
#include "List_of_balises_for_SH_Area_Core.h"
#include "Bit64.h"

int List_of_balises_for_SH_Area_UpperBitsNotSet(const List_of_balises_for_SH_Area_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && List_of_balises_for_SH_Area_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int List_of_balises_for_SH_Area_Encoder(Bitstream* stream, const List_of_balises_for_SH_Area_Core* p)
{
    if (Bitstream_Normal(stream, LIST_OF_BALISES_FOR_SH_AREA_CORE_BITSIZE))
    {
        if (List_of_balises_for_SH_Area_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 5,  p->N_ITER_1);

            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                List_of_balises_for_SH_Area_Core_1_Encoder(stream, &(p->sub_1[i]));
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

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

int List_of_balises_for_SH_Area_Decoder(Bitstream* stream, List_of_balises_for_SH_Area_Core* p)
{
    if (Bitstream_Normal(stream, LIST_OF_BALISES_FOR_SH_AREA_CORE_BITSIZE))
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

        {
            p->N_ITER_1		= Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            List_of_balises_for_SH_Area_Core_1_Decoder(stream, &(p->sub_1[i]));
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

