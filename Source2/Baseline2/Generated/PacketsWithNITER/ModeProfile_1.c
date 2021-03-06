
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_ModeProfile
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) 

- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): Fraunhofer FOKUS

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.       
============================================================================= */

#include "ModeProfile_1.h"
#include "Bit64.h"

int ModeProfile_1_UpperBitsNotSet(const ModeProfile_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->D_MAMODE,          15);
    status = status && UpperBitsNotSet64(p->M_MAMODE,          2) ;
    status = status && UpperBitsNotSet64(p->V_MAMODE,          7) ;
    status = status && UpperBitsNotSet64(p->L_MAMODE,          15);
    status = status && UpperBitsNotSet64(p->L_ACKMAMODE,       15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ModeProfile_1_EncodeBit(const ModeProfile_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, MODEPROFILE_1_BITSIZE))
    {
        if (ModeProfile_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_MAMODE);
            Bitstream_Write(stream, 2,  p->M_MAMODE);
            Bitstream_Write(stream, 7,  p->V_MAMODE);
            Bitstream_Write(stream, 15, p->L_MAMODE);
            Bitstream_Write(stream, 15, p->L_ACKMAMODE);


            //@ assert D_MAMODE:          EqualBits(stream, pos,       pos + 15,  p->D_MAMODE);
            //@ assert M_MAMODE:          EqualBits(stream, pos + 15,  pos + 17,  p->M_MAMODE);
            //@ assert V_MAMODE:          EqualBits(stream, pos + 17,  pos + 24,  p->V_MAMODE);
            //@ assert L_MAMODE:          EqualBits(stream, pos + 24,  pos + 39,  p->L_MAMODE);
            //@ assert L_ACKMAMODE:       EqualBits(stream, pos + 39,  pos + 54,  p->L_ACKMAMODE);

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

int ModeProfile_1_DecodeBit(ModeProfile_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, MODEPROFILE_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_MAMODE:       stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_MAMODE;
          ensures  D_MAMODE:       stream->bitpos == pos + 15;
          ensures  D_MAMODE:       EqualBits(stream, pos + 0, pos + 15, p->D_MAMODE);
          ensures  D_MAMODE:       UpperBitsNotSet(p->D_MAMODE, 15);
        */
        {
            p->D_MAMODE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_MAMODE:       stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->M_MAMODE;
          ensures  M_MAMODE:       stream->bitpos == pos + 17;
          ensures  M_MAMODE:       EqualBits(stream, pos + 15, pos + 17, p->M_MAMODE);
          ensures  M_MAMODE:       UpperBitsNotSet(p->M_MAMODE, 2);
        */
        {
            p->M_MAMODE        = Bitstream_Read(stream, 2);
        }

        /*@
          requires V_MAMODE:       stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->V_MAMODE;
          ensures  V_MAMODE:       stream->bitpos == pos + 24;
          ensures  V_MAMODE:       EqualBits(stream, pos + 17, pos + 24, p->V_MAMODE);
          ensures  V_MAMODE:       UpperBitsNotSet(p->V_MAMODE, 7);
        */
        {
            p->V_MAMODE        = Bitstream_Read(stream, 7);
        }

        /*@
          requires L_MAMODE:       stream->bitpos == pos + 24;
          assigns                  stream->bitpos;
          assigns                  p->L_MAMODE;
          ensures  L_MAMODE:       stream->bitpos == pos + 39;
          ensures  L_MAMODE:       EqualBits(stream, pos + 24, pos + 39, p->L_MAMODE);
          ensures  L_MAMODE:       UpperBitsNotSet(p->L_MAMODE, 15);
        */
        {
            p->L_MAMODE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_ACKMAMODE:    stream->bitpos == pos + 39;
          assigns                  stream->bitpos;
          assigns                  p->L_ACKMAMODE;
          ensures  L_ACKMAMODE:    stream->bitpos == pos + 54;
          ensures  L_ACKMAMODE:    EqualBits(stream, pos + 39, pos + 54, p->L_ACKMAMODE);
          ensures  L_ACKMAMODE:    UpperBitsNotSet(p->L_ACKMAMODE, 15);
        */
        {
            p->L_ACKMAMODE        = Bitstream_Read(stream, 15);
        }

        //@ assert D_MAMODE:          EqualBits(stream, pos,       pos + 15,  p->D_MAMODE);
        //@ assert M_MAMODE:          EqualBits(stream, pos + 15,  pos + 17,  p->M_MAMODE);
        //@ assert V_MAMODE:          EqualBits(stream, pos + 17,  pos + 24,  p->V_MAMODE);
        //@ assert L_MAMODE:          EqualBits(stream, pos + 24,  pos + 39,  p->L_MAMODE);
        //@ assert L_ACKMAMODE:       EqualBits(stream, pos + 39,  pos + 54,  p->L_ACKMAMODE);

        //@ assert D_MAMODE:          UpperBitsNotSet(p->D_MAMODE,          15);
        //@ assert M_MAMODE:          UpperBitsNotSet(p->M_MAMODE,          2);
        //@ assert V_MAMODE:          UpperBitsNotSet(p->V_MAMODE,          7);
        //@ assert L_MAMODE:          UpperBitsNotSet(p->L_MAMODE,          15);
        //@ assert L_ACKMAMODE:       UpperBitsNotSet(p->L_ACKMAMODE,       15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

#ifndef FRAMAC_IGNORE

int ModeProfile_1_EncodeInt(const ModeProfile_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->D_MAMODE;
    stream[(*startAddress)++] = p->M_MAMODE;
    stream[(*startAddress)++] = p->V_MAMODE;
    stream[(*startAddress)++] = p->L_MAMODE;
    stream[(*startAddress)++] = p->L_ACKMAMODE;

    return 1;
}

int ModeProfile_1_DecodeInt(ModeProfile_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->D_MAMODE = stream[(*startAddress)++];
    p->M_MAMODE = stream[(*startAddress)++];
    p->V_MAMODE = stream[(*startAddress)++];
    p->L_MAMODE = stream[(*startAddress)++];
    p->L_ACKMAMODE = stream[(*startAddress)++];

    return 1;
}

#endif // FRAMAC_IGNORE

