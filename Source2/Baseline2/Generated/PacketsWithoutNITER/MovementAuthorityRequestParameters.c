
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_MovementAuthorityRequestParameters
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

#include "MovementAuthorityRequestParameters.h"
#include "Bit64.h"

// number of cells in allocation memory
#define MovementAuthorityRequestParametersMemoryMax		8

// end-of-freelist indicator
#define MovementAuthorityRequestParametersMemoryNil		(-1)

// allocation memory
static MovementAuthorityRequestParameters MovementAuthorityRequestParametersMemory[MovementAuthorityRequestParametersMemoryMax];

// lowest unused cell of allocation memory
static uint64_t MovementAuthorityRequestParametersMemoryTop = 0;

// index of first element of freelist
static uint64_t MovementAuthorityRequestParametersMemoryFreeList = MovementAuthorityRequestParametersMemoryNil;

MovementAuthorityRequestParameters* MovementAuthorityRequestParameters_New(void)
{
    MovementAuthorityRequestParameters* ptr;

    if (MovementAuthorityRequestParametersMemoryFreeList != MovementAuthorityRequestParametersMemoryNil)
    {
        // allocate from freelist
        ptr = &MovementAuthorityRequestParametersMemory[MovementAuthorityRequestParametersMemoryFreeList];
        MovementAuthorityRequestParametersMemoryFreeList = MovementAuthorityRequestParametersMemory[MovementAuthorityRequestParametersMemoryFreeList].header.NID_PACKET;
    }
    else if (MovementAuthorityRequestParametersMemoryTop < MovementAuthorityRequestParametersMemoryMax)
    {
        // allocate from top
        ptr = &MovementAuthorityRequestParametersMemory[MovementAuthorityRequestParametersMemoryTop];
        MovementAuthorityRequestParametersMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    MovementAuthorityRequestParameters_Init(ptr);

    return ptr;
}


void MovementAuthorityRequestParameters_Delete(MovementAuthorityRequestParameters* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = MovementAuthorityRequestParametersMemoryFreeList;
    MovementAuthorityRequestParametersMemoryFreeList = ptr - MovementAuthorityRequestParametersMemory;
}


int MovementAuthorityRequestParameters_UpperBitsNotSet(const MovementAuthorityRequestParameters* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->T_MAR,             8) ;
    status = status && UpperBitsNotSet64(p->T_TIMEOUTRQST,     10);
    status = status && UpperBitsNotSet64(p->T_CYCRQST,         8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int MovementAuthorityRequestParameters_EncodeBit(const MovementAuthorityRequestParameters* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, MOVEMENTAUTHORITYREQUESTPARAMETERS_BITSIZE))
    {
        if (MovementAuthorityRequestParameters_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 8,  p->T_MAR);
            Bitstream_Write(stream, 10, p->T_TIMEOUTRQST);
            Bitstream_Write(stream, 8,  p->T_CYCRQST);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert T_MAR:             EqualBits(stream, pos + 15,  pos + 23,  p->T_MAR);
            //@ assert T_TIMEOUTRQST:     EqualBits(stream, pos + 23,  pos + 33,  p->T_TIMEOUTRQST);
            //@ assert T_CYCRQST:         EqualBits(stream, pos + 33,  pos + 41,  p->T_CYCRQST);

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

int MovementAuthorityRequestParameters_DecodeBit(MovementAuthorityRequestParameters* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, MOVEMENTAUTHORITYREQUESTPARAMETERS_BITSIZE))
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
          requires T_MAR:          stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->T_MAR;
          ensures  T_MAR:          stream->bitpos == pos + 23;
          ensures  T_MAR:          EqualBits(stream, pos + 15, pos + 23, p->T_MAR);
          ensures  T_MAR:          UpperBitsNotSet(p->T_MAR, 8);
        */
        {
            p->T_MAR        = Bitstream_Read(stream, 8);
        }

        /*@
          requires T_TIMEOUTRQST:  stream->bitpos == pos + 23;
          assigns                  stream->bitpos;
          assigns                  p->T_TIMEOUTRQST;
          ensures  T_TIMEOUTRQST:  stream->bitpos == pos + 33;
          ensures  T_TIMEOUTRQST:  EqualBits(stream, pos + 23, pos + 33, p->T_TIMEOUTRQST);
          ensures  T_TIMEOUTRQST:  UpperBitsNotSet(p->T_TIMEOUTRQST, 10);
        */
        {
            p->T_TIMEOUTRQST        = Bitstream_Read(stream, 10);
        }

        /*@
          requires T_CYCRQST:      stream->bitpos == pos + 33;
          assigns                  stream->bitpos;
          assigns                  p->T_CYCRQST;
          ensures  T_CYCRQST:      stream->bitpos == pos + 41;
          ensures  T_CYCRQST:      EqualBits(stream, pos + 33, pos + 41, p->T_CYCRQST);
          ensures  T_CYCRQST:      UpperBitsNotSet(p->T_CYCRQST, 8);
        */
        {
            p->T_CYCRQST        = Bitstream_Read(stream, 8);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert T_MAR:             EqualBits(stream, pos + 15,  pos + 23,  p->T_MAR);
        //@ assert T_TIMEOUTRQST:     EqualBits(stream, pos + 23,  pos + 33,  p->T_TIMEOUTRQST);
        //@ assert T_CYCRQST:         EqualBits(stream, pos + 33,  pos + 41,  p->T_CYCRQST);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert T_MAR:             UpperBitsNotSet(p->T_MAR,             8);
        //@ assert T_TIMEOUTRQST:     UpperBitsNotSet(p->T_TIMEOUTRQST,     10);
        //@ assert T_CYCRQST:         UpperBitsNotSet(p->T_CYCRQST,         8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int MovementAuthorityRequestParameters_EncodeInt(const MovementAuthorityRequestParameters* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 57;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->T_MAR;
    stream[startAddress++] = p->T_TIMEOUTRQST;
    stream[startAddress++] = p->T_CYCRQST;

    data->endAddress = startAddress-1;

    return 1;
}

int MovementAuthorityRequestParameters_DecodeInt(MovementAuthorityRequestParameters* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 57)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->T_MAR = stream[startAddress++];
    p->T_TIMEOUTRQST = stream[startAddress++];
    p->T_CYCRQST = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

