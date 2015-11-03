
#ifndef RADIONETWORKREGISTRATION_H_INCLUDED
#define RADIONETWORKREGISTRATION_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct RadioNetworkRegistration
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Packet to give the identity of the Radio Network to which
    // a registration shall be enforced.
    // Packet Number = 45

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_MN;           // # 24
};

typedef struct RadioNetworkRegistration RadioNetworkRegistration;

#define RADIONETWORKREGISTRATION_BITSIZE 39

RadioNetworkRegistration*  RadioNetworkRegistration_New(void);

void   RadioNetworkRegistration_Delete(RadioNetworkRegistration*);

static inline void RadioNetworkRegistration_Init(RadioNetworkRegistration* p)
{
    p->header.NID_PACKET = 45;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->NID_MN = 0;
}

/*@
    logic integer BitSize{L}(RadioNetworkRegistration* p) = RADIONETWORKREGISTRATION_BITSIZE;

    logic integer MaxBitSize{L}(RadioNetworkRegistration* p) = BitSize(p);

    predicate Separated(Bitstream* stream, RadioNetworkRegistration* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(RadioNetworkRegistration* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_MN);

    predicate ZeroInitialized(RadioNetworkRegistration* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_MN);

    predicate EqualBits(Bitstream* stream, integer pos, RadioNetworkRegistration* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 39,  p->NID_MN);

    predicate UpperBitsNotSet(RadioNetworkRegistration* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_MN,           24);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int RadioNetworkRegistration_UpperBitsNotSet(const RadioNetworkRegistration* p);

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
int RadioNetworkRegistration_EncodeBit(const RadioNetworkRegistration* p, Bitstream* stream);

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
int RadioNetworkRegistration_DecodeBit(RadioNetworkRegistration* p, Bitstream* stream);

static inline void RadioNetworkRegistration_Print(const RadioNetworkRegistration* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu)",
            p->Q_DIR,
            p->L_PACKET,
            p->NID_MN);
}

static inline int RadioNetworkRegistration_Equal(const RadioNetworkRegistration* a, const RadioNetworkRegistration* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->NID_MN == b->NID_MN);

    return status;
}

static inline uint32_t RadioNetworkRegistration_Length(const RadioNetworkRegistration* p)
{
    return (uint32_t)(p->L_PACKET);
}

int RadioNetworkRegistration_EncodeInt(const RadioNetworkRegistration* p, Metadata* data, kcg_int* stream);

int RadioNetworkRegistration_DecodeInt(RadioNetworkRegistration* p, const Metadata* data, const kcg_int* stream);

#endif // RADIONETWORKREGISTRATION_H_INCLUDED

