
#ifndef TRAINRUNNINGNUMBERFROMRBC_H_INCLUDED
#define TRAINRUNNINGNUMBERFROMRBC_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"

struct TrainRunningNumberFromRBC
{
    PacketHeader header;

    // TransmissionMedia=Radio
    // Train running number from RBC
    // Packet Number = 140

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_OPERATIONAL;  // # 32
};

typedef struct TrainRunningNumberFromRBC TrainRunningNumberFromRBC;

#define TRAINRUNNINGNUMBERFROMRBC_BITSIZE 47

TrainRunningNumberFromRBC*  TrainRunningNumberFromRBC_New(void);

void   TrainRunningNumberFromRBC_Delete(TrainRunningNumberFromRBC*);

static inline void TrainRunningNumberFromRBC_Init(TrainRunningNumberFromRBC* p)
{
    p->header.NID_PACKET = 140;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->NID_OPERATIONAL = 0;
}

/*@
    logic integer BitSize{L}(TrainRunningNumberFromRBC* p) = TRAINRUNNINGNUMBERFROMRBC_BITSIZE;

    logic integer MaxBitSize{L}(TrainRunningNumberFromRBC* p) = BitSize(p);

    predicate Separated(Bitstream* stream, TrainRunningNumberFromRBC* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(TrainRunningNumberFromRBC* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_OPERATIONAL);

    predicate ZeroInitialized(TrainRunningNumberFromRBC* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_OPERATIONAL);

    predicate EqualBits(Bitstream* stream, integer pos, TrainRunningNumberFromRBC* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 47,  p->NID_OPERATIONAL);

    predicate UpperBitsNotSet(TrainRunningNumberFromRBC* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_OPERATIONAL,  32);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int TrainRunningNumberFromRBC_UpperBitsNotSet(const TrainRunningNumberFromRBC* p);

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
int TrainRunningNumberFromRBC_EncodeBit(const TrainRunningNumberFromRBC* p, Bitstream* stream);

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
int TrainRunningNumberFromRBC_DecodeBit(TrainRunningNumberFromRBC* p, Bitstream* stream);

static inline void TrainRunningNumberFromRBC_Print(const TrainRunningNumberFromRBC* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64")",
            p->Q_DIR,
            p->L_PACKET,
            p->NID_OPERATIONAL);
}

static inline int TrainRunningNumberFromRBC_Equal(const TrainRunningNumberFromRBC* a, const TrainRunningNumberFromRBC* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->NID_OPERATIONAL == b->NID_OPERATIONAL);

    return status;
}

static inline uint32_t TrainRunningNumberFromRBC_Length(const TrainRunningNumberFromRBC* p)
{
    return (uint32_t)(p->L_PACKET);
}

#endif // TRAINRUNNINGNUMBERFROMRBC_H_INCLUDED

