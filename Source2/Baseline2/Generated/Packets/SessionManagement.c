
#include "SessionManagement.h"
#include "Bit64.h"

// number of cells in allocation memory
#define SessionManagementMemoryMax		32

// end-of-freelist indicator
#define SessionManagementMemoryNil		(-1)

// allocation memory
static SessionManagement SessionManagementMemory[SessionManagementMemoryMax];

// lowest unused cell of allocation memory
static uint64_t SessionManagementMemoryTop = 0;

// index of first element of freelist
static uint64_t SessionManagementMemoryFreeList = SessionManagementMemoryNil;

SessionManagement* SessionManagement_New(void)
{
    SessionManagement* ptr;

    if (SessionManagementMemoryFreeList != SessionManagementMemoryNil)
    {
        // allocate from freelist
        ptr = &SessionManagementMemory[SessionManagementMemoryFreeList];
        SessionManagementMemoryFreeList = SessionManagementMemory[SessionManagementMemoryFreeList].header.NID_PACKET;
    }
    else if (SessionManagementMemoryTop < SessionManagementMemoryMax)
    {
        // allocate from top
        ptr = &SessionManagementMemory[SessionManagementMemoryTop];
        SessionManagementMemoryTop += 1;
    }
    else
    {
        // memory exhausted
        return 0;
    }

    SessionManagement_Init(ptr);

    return ptr;
}


void SessionManagement_Delete(SessionManagement* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = SessionManagementMemoryFreeList;
    SessionManagementMemoryFreeList = ptr - SessionManagementMemory;
}


int SessionManagement_UpperBitsNotSet(const SessionManagement* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_RBC,             1) ;
    if (p->NID_RBC != 16383)
    {
        status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_RBC,           14);
    if (p->NID_RBC != 16383)
    {
        status = status && UpperBitsNotSet64(p->NID_RADIO,         64);
    }
    status = status && UpperBitsNotSet64(p->Q_SLEEPSESSION,    1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int SessionManagement_EncodeBit(const SessionManagement* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, SESSIONMANAGEMENT_BITSIZE))
    {
        if (SessionManagement_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_RBC);
            if (p->NID_RBC != 16383)
            {
                Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_RBC);
            if (p->NID_RBC != 16383)
            {
                Bitstream_Write(stream, 64, p->NID_RADIO);
            }

            Bitstream_Write(stream, 1,  p->Q_SLEEPSESSION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_RBC:             EqualBits(stream, pos + 15,  pos + 16,  p->Q_RBC);

            return 1;
        }
        else
        {
            fprintf(stdout, "error");
            return -2;
        }
    }
    else
    {
        fprintf(stdout, "error");
        return -1;
    }
}

int SessionManagement_DecodeBit(SessionManagement* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, SESSIONMANAGEMENT_BITSIZE))
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
          requires Q_RBC:          stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_RBC;
          ensures  Q_RBC:          stream->bitpos == pos + 16;
          ensures  Q_RBC:          EqualBits(stream, pos + 15, pos + 16, p->Q_RBC);
          ensures  Q_RBC:          UpperBitsNotSet(p->Q_RBC, 1);
        */
        {
            p->Q_RBC        = Bitstream_Read(stream, 1);
        }

        if (p->NID_RBC != 16383)
        {
            {
                p->NID_C        = Bitstream_Read(stream, 10);
            }

        }

        {
            p->NID_RBC        = Bitstream_Read(stream, 14);
        }

        if (p->NID_RBC != 16383)
        {
            {
                p->NID_RADIO        = Bitstream_Read(stream, 64);
            }

        }

        {
            p->Q_SLEEPSESSION        = Bitstream_Read(stream, 1);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_RBC:             EqualBits(stream, pos + 15,  pos + 16,  p->Q_RBC);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_RBC:             UpperBitsNotSet(p->Q_RBC,             1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int SessionManagement_EncodeInt(const SessionManagement* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 42;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_RBC;
    stream[startAddress++] = p->NID_C;
    stream[startAddress++] = p->NID_RBC;
    stream[startAddress++] = p->NID_RADIO;
    stream[startAddress++] = p->Q_SLEEPSESSION;

    data->endAddress = startAddress-1;

    return 1;
}

int SessionManagement_DecodeInt(SessionManagement* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 42)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_RBC = stream[startAddress++];
    p->NID_C = stream[startAddress++];
    p->NID_RBC = stream[startAddress++];
    p->NID_RADIO = stream[startAddress++];
    p->Q_SLEEPSESSION = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

