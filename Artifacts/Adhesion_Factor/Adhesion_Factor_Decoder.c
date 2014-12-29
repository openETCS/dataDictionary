
#include "Adhesion_Factor_Decoder.h"
#include "Bitstream_Read.h"

int Adhesion_Factor_Decoder(Bitstream* stream, Adhesion_Factor* p)
{
    if (stream->bitpos + ADHESION_FACTOR_BITSIZE > 8 * stream->size)
    {
        return 0;
    }
    else
    {
        //@ assert NormalBitsequence(stream, ADHESION_FACTOR_BITSIZE);
        //@ ghost uint32_t pos = stream->bitpos;

        /*@
            requires NID_PACKET_normal: NormalBitsequence(stream, 8);

            assigns stream->bitpos;
            assigns p->NID_PACKET;

            ensures NID_PACKET_bitpos: stream->bitpos == pos + 8;
            ensures NID_PACKET_equal:  BitstreamEqual64(stream, pos, pos + 8,  p->NID_PACKET);
            ensures NID_PACKET_upper:  UpperBitsNotSet(p->NID_PACKET, 8);
        */
        p->NID_PACKET = Bitstream_Read(stream, 8);

        /*@
            requires Q_DIR_normal: NormalBitsequence{Here}(stream, 2);

            assigns stream->bitpos;
            assigns p->Q_DIR;

            ensures Q_DIR_bitpos: stream->bitpos == pos + 10;
            ensures Q_DIR_equal:  BitstreamEqual64(stream, pos + 8, pos + 10,  p->Q_DIR);
            ensures Q_DIR_upper:  UpperBitsNotSet(p->Q_DIR, 2);
        */
        p->Q_DIR = Bitstream_Read(stream, 2);

        /*@
            requires L_PACKET_normal: NormalBitsequence(stream, 13);

            assigns stream->bitpos;
            assigns p->L_PACKET;

            ensures L_PACKET_bitpos: stream->bitpos == pos + 23;
            ensures L_PACKET_equal:  BitstreamEqual64(stream, pos + 10, pos + 23,  p->L_PACKET);
            ensures L_PACKET_upper:  UpperBitsNotSet(p->L_PACKET, 13);
        */
        p->L_PACKET = Bitstream_Read(stream, 13);

        /*@
            requires Q_SCALE_normal: NormalBitsequence(stream, 2);

            assigns stream->bitpos;
            assigns p->Q_SCALE;

            ensures Q_SCALE_bitpos: stream->bitpos == pos + 25;
            ensures Q_SCALE_equal:  BitstreamEqual64(stream, pos + 23, pos + 25,  p->Q_SCALE);
            ensures Q_SCALE_upper:  UpperBitsNotSet(p->Q_SCALE, 2);
        */
        p->Q_SCALE = Bitstream_Read(stream, 2);

        /*@
            requires D_ADHESION_normal: NormalBitsequence(stream, 15);

            assigns stream->bitpos;
            assigns p->D_ADHESION;

            ensures D_ADHESION_bitpos: stream->bitpos == pos + 40;
            ensures D_ADHESION_equal:  BitstreamEqual64(stream, pos + 25, pos + 40,  p->D_ADHESION);
            ensures D_ADHESION_upper:  UpperBitsNotSet(p->D_ADHESION, 15);
        */
        p->D_ADHESION = Bitstream_Read(stream, 15);

        /*@
            requires L_ADHESION_normal: NormalBitsequence(stream, 15);

            assigns stream->bitpos;
            assigns p->L_ADHESION;

            ensures L_ADHESION_bitpos: stream->bitpos == pos + 55;
            ensures L_ADHESION_equal:  BitstreamEqual64(stream, pos + 40, pos + 55,  p->L_ADHESION);
            ensures L_ADHESION_upper:  UpperBitsNotSet(p->L_ADHESION, 15);
        */
        p->L_ADHESION = Bitstream_Read(stream, 15);

        /*@
            requires M_ADHESION_normal: NormalBitsequence(stream, 1);

            assigns stream->bitpos;
            assigns p->M_ADHESION;

            ensures M_ADHESION_bitpos: stream->bitpos == pos + 56;
            ensures M_ADHESION_equal:  BitstreamEqual64(stream, pos + 55, pos + 56,  p->M_ADHESION);
            ensures M_ADHESION_upper:  UpperBitsNotSet(p->M_ADHESION, 1);
        */
        p->M_ADHESION = Bitstream_Read(stream, 1);

        //@ assert NID_PACKET_final: BitstreamEqual64(stream, pos,      pos + 8,  p->NID_PACKET);
        //@ assert Q_DIR_final:      BitstreamEqual64(stream, pos + 8,  pos + 10, p->Q_DIR);
        //@ assert L_PACKET_final:   BitstreamEqual64(stream, pos + 10, pos + 23, p->L_PACKET);
        //@ assert Q_SCALE_final:    BitstreamEqual64(stream, pos + 23, pos + 25, p->Q_SCALE);
        //@ assert D_ADHESION_final: BitstreamEqual64(stream, pos + 25, pos + 40, p->D_ADHESION);
        //@ assert L_ADHESION_final: BitstreamEqual64(stream, pos + 40, pos + 55, p->L_ADHESION);
        //@ assert M_ADHESION_final: BitstreamEqual64(stream, pos + 55, pos + 56, p->M_ADHESION);

        //@ assert p_equal:          BitstreamEqual(stream, pos, p);

        return 1;
    }
}

