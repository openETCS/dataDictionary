
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrainToTrack_ErrorReporting
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

#include "ErrorReporting.h"
#include "Bit64.h"

// number of cells in allocation memory
#define ErrorReportingMemoryMax		8

// end-of-freelist indicator
#define ErrorReportingMemoryNil		(-1)

// allocation memory
static ErrorReporting ErrorReportingMemory[ErrorReportingMemoryMax];

// lowest unused cell of allocation memory
static uint64_t ErrorReportingMemoryTop = 0;

// index of first element of freelist
static uint64_t ErrorReportingMemoryFreeList = ErrorReportingMemoryNil;

ErrorReporting* ErrorReporting_New(void)
{
    ErrorReporting* ptr;

    if (ErrorReportingMemoryFreeList != ErrorReportingMemoryNil)
    {
        // allocate from freelist
        ptr = &ErrorReportingMemory[ErrorReportingMemoryFreeList];
        ErrorReportingMemoryFreeList = ErrorReportingMemory[ErrorReportingMemoryFreeList].header.NID_PACKET;
    }
    else if (ErrorReportingMemoryTop < ErrorReportingMemoryMax)
    {
        // allocate from top
        ptr = &ErrorReportingMemory[ErrorReportingMemoryTop];
        ErrorReportingMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    ErrorReporting_Init(ptr);

    return ptr;
}


void ErrorReporting_Delete(ErrorReporting* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = ErrorReportingMemoryFreeList;
    ErrorReportingMemoryFreeList = ptr - ErrorReportingMemory;
}


int ErrorReporting_UpperBitsNotSet(const ErrorReporting* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->M_ERROR,           8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ErrorReporting_EncodeBit(const ErrorReporting* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ERRORREPORTING_BITSIZE))
    {
        if (ErrorReporting_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 8,  p->M_ERROR);


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert M_ERROR:           EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

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

int ErrorReporting_DecodeBit(ErrorReporting* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ERRORREPORTING_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires L_PACKET:       stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 13;
          ensures  L_PACKET:       EqualBits(stream, pos + 0, pos + 13, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET        = Bitstream_Read(stream, 13);
        }

        /*@
          requires M_ERROR:        stream->bitpos == pos + 13;
          assigns                  stream->bitpos;
          assigns                  p->M_ERROR;
          ensures  M_ERROR:        stream->bitpos == pos + 21;
          ensures  M_ERROR:        EqualBits(stream, pos + 13, pos + 21, p->M_ERROR);
          ensures  M_ERROR:        UpperBitsNotSet(p->M_ERROR, 8);
        */
        {
            p->M_ERROR        = Bitstream_Read(stream, 8);
        }

        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert M_ERROR:           EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert M_ERROR:           UpperBitsNotSet(p->M_ERROR,           8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int ErrorReporting_EncodeInt(const ErrorReporting* p, Metadata* data, kcg_int* stream)
{
    data->nid_packet = 4;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->M_ERROR;

    data->endAddress = startAddress-1;

    return 1;
}

int ErrorReporting_DecodeInt(ErrorReporting* p, const Metadata* data, const kcg_int* stream)
{
    if(data->nid_packet != 4)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->L_PACKET = stream[startAddress++];
    p->M_ERROR = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

