
#ifndef LEVEL23MOVEMENTAUTHORITY_1_H_INCLUDED
#define LEVEL23MOVEMENTAUTHORITY_1_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct Level23MovementAuthority_1
{

    uint64_t  L_SECTION;        // # 15
    uint64_t   Q_SECTIONTIMER;   // # 1
    uint64_t  T_SECTIONTIMER;   // # 10
    uint64_t  D_SECTIONTIMERSTOPLOC;// # 15
};

typedef struct Level23MovementAuthority_1 Level23MovementAuthority_1;

#define LEVEL23MOVEMENTAUTHORITY_1_BITSIZE 41

static inline void Level23MovementAuthority_1_Init(Level23MovementAuthority_1* p)
{
    p->L_SECTION = 0;
    p->Q_SECTIONTIMER = 0;
    p->T_SECTIONTIMER = 0;
    p->D_SECTIONTIMERSTOPLOC = 0;
}

/*@
    logic integer BitSize{L}(Level23MovementAuthority_1* p) = LEVEL23MOVEMENTAUTHORITY_1_BITSIZE;

    logic integer MaxBitSize{L}(Level23MovementAuthority_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level23MovementAuthority_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level23MovementAuthority_1* p) =
      Invariant(p->L_SECTION)         &&
      Invariant(p->Q_SECTIONTIMER)    &&
      Invariant(p->T_SECTIONTIMER)    &&
      Invariant(p->D_SECTIONTIMERSTOPLOC);

    predicate ZeroInitialized(Level23MovementAuthority_1* p) =
      ZeroInitialized(p->L_SECTION)         &&
      ZeroInitialized(p->Q_SECTIONTIMER)    &&
      ZeroInitialized(p->T_SECTIONTIMER)    &&
      ZeroInitialized(p->D_SECTIONTIMERSTOPLOC);

    predicate EqualBits(Bitstream* stream, integer pos, Level23MovementAuthority_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->L_SECTION)         &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_SECTIONTIMER)    &&
      EqualBits(stream, pos + 16,  pos + 26,  p->T_SECTIONTIMER)    &&
      EqualBits(stream, pos + 26,  pos + 41,  p->D_SECTIONTIMERSTOPLOC);

    predicate UpperBitsNotSet(Level23MovementAuthority_1* p) =
      UpperBitsNotSet(p->L_SECTION,        15)  &&
      UpperBitsNotSet(p->Q_SECTIONTIMER,   1)   &&
      UpperBitsNotSet(p->T_SECTIONTIMER,   10)  &&
      UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC,15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level23MovementAuthority_1_UpperBitsNotSet(const Level23MovementAuthority_1* p);

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
int Level23MovementAuthority_1_EncodeBit(const Level23MovementAuthority_1* p, Bitstream* stream);

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

      ensures result: \result == 0; complete behaviors;
    disjoint behaviors;
*/
int Level23MovementAuthority_1_DecodeBit(Level23MovementAuthority_1* p, Bitstream* stream);

static inline void Level23MovementAuthority_1_Print(const Level23MovementAuthority_1* p, FILE* stream)
{
    fprintf(stream, "(%lu,%lu,%lu,%lu)",
            p->L_SECTION,
            p->Q_SECTIONTIMER,
            p->T_SECTIONTIMER,
            p->D_SECTIONTIMERSTOPLOC);
}

static inline int Level23MovementAuthority_1_Equal(const Level23MovementAuthority_1* a, const Level23MovementAuthority_1* b)
{
    int status = 1;

    status = status && (a->L_SECTION == b->L_SECTION);
    status = status && (a->Q_SECTIONTIMER == b->Q_SECTIONTIMER);
    status = status && (a->T_SECTIONTIMER == b->T_SECTIONTIMER);
    status = status && (a->D_SECTIONTIMERSTOPLOC == b->D_SECTIONTIMERSTOPLOC);

    return status;
}

int Level23MovementAuthority_1_EncodeInt(const Level23MovementAuthority_1* p, kcg_int* startAddress, kcg_int* stream);

int Level23MovementAuthority_1_DecodeInt(Level23MovementAuthority_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // LEVEL23MOVEMENTAUTHORITY_1_H_INCLUDED

