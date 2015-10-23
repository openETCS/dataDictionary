
#ifndef SESSIONMANAGEMENT_H_INCLUDED
#define SESSIONMANAGEMENT_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"

struct SessionManagement
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Packet to give the identity and telephone number of the RBC
    // with which a session shall be established or terminated.
    // Packet Number = 42

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_RBC;            // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_RBC;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint64_t   Q_SLEEPSESSION;   // # 1
};

typedef struct SessionManagement SessionManagement;

#define SESSIONMANAGEMENT_BITSIZE 31

SessionManagement*  SessionManagement_New(void);

void   SessionManagement_Delete(SessionManagement*);

static inline void SessionManagement_Init(SessionManagement* p)
{
    p->header.NID_PACKET = 42;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_RBC = 0;
    p->NID_C = 0;
    p->NID_RBC = 0;
    p->NID_RADIO = 0;
    p->Q_SLEEPSESSION = 0;
}

/*@
    logic integer BitSize{L}(SessionManagement* p) = SESSIONMANAGEMENT_BITSIZE;

    logic integer MaxBitSize{L}(SessionManagement* p) = BitSize(p);

    predicate Separated(Bitstream* stream, SessionManagement* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(SessionManagement* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_RBC);

    predicate ZeroInitialized(SessionManagement* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_RBC);

    predicate EqualBits(Bitstream* stream, integer pos, SessionManagement* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_RBC);

    predicate UpperBitsNotSet(SessionManagement* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_RBC,            1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int SessionManagement_UpperBitsNotSet(const SessionManagement* p);

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid_read(p);
    requires invariant:         Invariant(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures left:       Unchanged{Here,Old}(stream, 0, \old(stream->bitpos));
      ensures middle:     EqualBits(stream, \old(stream->bitpos), p);
      ensures right:      Unchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    behavior values_too_big:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures result:        \result == -2;

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result:       \result == -1;

    complete behaviors;
    disjoint behaviors;
*/
int SessionManagement_EncodeBit(const SessionManagement* p, Bitstream* stream);

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          Unchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int SessionManagement_DecodeBit(SessionManagement* p, Bitstream* stream);

static inline void SessionManagement_Print(const SessionManagement* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64")",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_RBC,
            p->NID_C,
            p->NID_RBC,
            p->NID_RADIO,
            p->Q_SLEEPSESSION);
}

static inline int SessionManagement_Equal(const SessionManagement* a, const SessionManagement* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_RBC == b->Q_RBC);

    if (a->NID_RBC != 16383)
    {
        status = status && (a->NID_C == b->NID_C);
    }
    status = status && (a->NID_RBC == b->NID_RBC);

    if (a->NID_RBC != 16383)
    {
        status = status && (a->NID_RADIO == b->NID_RADIO);
    }
    status = status && (a->Q_SLEEPSESSION == b->Q_SLEEPSESSION);

    return status;
}

static inline uint32_t SessionManagement_Length(const SessionManagement* p)
{
    return (uint32_t)(p->L_PACKET);
}

int SessionManagement_EncodeInt(const SessionManagement* p, PacketInfo* data, kcg_int* stream);

int SessionManagement_DecodeInt(SessionManagement* p, PacketInfo* data, kcg_int* stream);

#endif // SESSIONMANAGEMENT_H_INCLUDED

