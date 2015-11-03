
#ifndef TRACKCONDITIONBIGMETALMASSES_H_INCLUDED
#define TRACKCONDITIONBIGMETALMASSES_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"
#include "TrackConditionBigMetalMasses_1.h"

struct TrackConditionBigMetalMasses
{
    PacketHeader header;

    // TransmissionMedia=Balise
    // The packet gives details concerning where to ignore integrity check alarms
    // of balise transmission due to big metal masses trackside.
    // Packet Number = 67

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_TRACKCOND;      // # 15
    uint64_t  L_TRACKCOND;      // # 15
    uint64_t   N_ITER_1;         // # 5
    TrackConditionBigMetalMasses_1   sub_1[31];
};

typedef struct TrackConditionBigMetalMasses TrackConditionBigMetalMasses;

#define TRACKCONDITIONBIGMETALMASSES_BITSIZE 52

TrackConditionBigMetalMasses*  TrackConditionBigMetalMasses_New(void);

void   TrackConditionBigMetalMasses_Delete(TrackConditionBigMetalMasses*);

static inline void TrackConditionBigMetalMasses_Init(TrackConditionBigMetalMasses* p)
{
    p->header.NID_PACKET = 67;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->D_TRACKCOND = 0;
    p->L_TRACKCOND = 0;
    p->N_ITER_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        TrackConditionBigMetalMasses_1_Init(&(p->sub_1[i]));
    }

}

/*@
    logic integer BitSize{L}(TrackConditionBigMetalMasses* p) = TRACKCONDITIONBIGMETALMASSES_BITSIZE;

    logic integer MaxBitSize{L}(TrackConditionBigMetalMasses* p) = BitSize(p);

    predicate Separated(Bitstream* stream, TrackConditionBigMetalMasses* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(TrackConditionBigMetalMasses* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_TRACKCOND)       &&
      Invariant(p->L_TRACKCOND);

    predicate ZeroInitialized(TrackConditionBigMetalMasses* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_TRACKCOND)       &&
      ZeroInitialized(p->L_TRACKCOND);

    predicate EqualBits(Bitstream* stream, integer pos, TrackConditionBigMetalMasses* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_TRACKCOND)       &&
      EqualBits(stream, pos + 32,  pos + 47,  p->L_TRACKCOND);

    predicate UpperBitsNotSet(TrackConditionBigMetalMasses* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->L_TRACKCOND,      15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int TrackConditionBigMetalMasses_UpperBitsNotSet(const TrackConditionBigMetalMasses* p);

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
int TrackConditionBigMetalMasses_EncodeBit(const TrackConditionBigMetalMasses* p, Bitstream* stream);

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
int TrackConditionBigMetalMasses_DecodeBit(TrackConditionBigMetalMasses* p, Bitstream* stream);

static inline void TrackConditionBigMetalMasses_Print(const TrackConditionBigMetalMasses* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu,%lu",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->D_TRACKCOND,
            p->L_TRACKCOND,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        TrackConditionBigMetalMasses_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int TrackConditionBigMetalMasses_Equal(const TrackConditionBigMetalMasses* a, const TrackConditionBigMetalMasses* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->D_TRACKCOND == b->D_TRACKCOND);
    status = status && (a->L_TRACKCOND == b->L_TRACKCOND);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && TrackConditionBigMetalMasses_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t TrackConditionBigMetalMasses_Length(const TrackConditionBigMetalMasses* p)
{
    return (uint32_t)(p->L_PACKET);
}

int TrackConditionBigMetalMasses_EncodeInt(const TrackConditionBigMetalMasses* p, Metadata* data, kcg_int* stream);

int TrackConditionBigMetalMasses_DecodeInt(TrackConditionBigMetalMasses* p, const Metadata* data, const kcg_int* stream);

#endif // TRACKCONDITIONBIGMETALMASSES_H_INCLUDED

