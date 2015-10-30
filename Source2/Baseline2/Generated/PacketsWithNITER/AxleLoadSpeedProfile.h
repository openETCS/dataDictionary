
#ifndef AXLELOADSPEEDPROFILE_H_INCLUDED
#define AXLELOADSPEEDPROFILE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"
#include "AxleLoadSpeedProfile_1.h"
#include "AxleLoadSpeedProfile_2.h"

struct AxleLoadSpeedProfile
{
    PacketHeader header;

    // TransmissionMedia=Any
    // This packet gives the speed restrictions for trains with axle load
    // higher than or equal to the specified value for the speed
    // restriction
    // Packet Number = 51

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t   Q_TRACKINIT;      // # 1
    uint64_t  D_AXLELOAD;       // # 15
    uint64_t  L_AXLELOAD;       // # 15
    uint64_t   Q_FRONT;          // # 1
    uint64_t   N_ITER_1;         // # 5
    AxleLoadSpeedProfile_1   sub_1[31];
    uint64_t   N_ITER_2;         // # 5
    AxleLoadSpeedProfile_2   sub_2[31];
};

typedef struct AxleLoadSpeedProfile AxleLoadSpeedProfile;

#define AXLELOADSPEEDPROFILE_BITSIZE 59

AxleLoadSpeedProfile*  AxleLoadSpeedProfile_New(void);

void   AxleLoadSpeedProfile_Delete(AxleLoadSpeedProfile*);

static inline void AxleLoadSpeedProfile_Init(AxleLoadSpeedProfile* p)
{
    p->header.NID_PACKET = 51;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->Q_TRACKINIT = 0;
    p->D_AXLELOAD = 0;
    p->L_AXLELOAD = 0;
    p->Q_FRONT = 0;
    p->N_ITER_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        AxleLoadSpeedProfile_1_Init(&(p->sub_1[i]));
    }

    p->N_ITER_2 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        AxleLoadSpeedProfile_2_Init(&(p->sub_2[i]));
    }

}

/*@
    logic integer BitSize{L}(AxleLoadSpeedProfile* p) = AXLELOADSPEEDPROFILE_BITSIZE;

    logic integer MaxBitSize{L}(AxleLoadSpeedProfile* p) = BitSize(p);

    predicate Separated(Bitstream* stream, AxleLoadSpeedProfile* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(AxleLoadSpeedProfile* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TRACKINIT)       &&
      Invariant(p->D_AXLELOAD)        &&
      Invariant(p->L_AXLELOAD)        &&
      Invariant(p->Q_FRONT);

    predicate ZeroInitialized(AxleLoadSpeedProfile* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TRACKINIT)       &&
      ZeroInitialized(p->D_AXLELOAD)        &&
      ZeroInitialized(p->L_AXLELOAD)        &&
      ZeroInitialized(p->Q_FRONT);

    predicate EqualBits(Bitstream* stream, integer pos, AxleLoadSpeedProfile* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 18,  p->Q_TRACKINIT)       &&
      EqualBits(stream, pos + 18,  pos + 33,  p->D_AXLELOAD)        &&
      EqualBits(stream, pos + 33,  pos + 48,  p->L_AXLELOAD)        &&
      EqualBits(stream, pos + 48,  pos + 49,  p->Q_FRONT);

    predicate UpperBitsNotSet(AxleLoadSpeedProfile* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TRACKINIT,      1)   &&
      UpperBitsNotSet(p->D_AXLELOAD,       15)  &&
      UpperBitsNotSet(p->L_AXLELOAD,       15)  &&
      UpperBitsNotSet(p->Q_FRONT,          1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int AxleLoadSpeedProfile_UpperBitsNotSet(const AxleLoadSpeedProfile* p);

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
int AxleLoadSpeedProfile_EncodeBit(const AxleLoadSpeedProfile* p, Bitstream* stream);

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
int AxleLoadSpeedProfile_DecodeBit(AxleLoadSpeedProfile* p, Bitstream* stream);

static inline void AxleLoadSpeedProfile_Print(const AxleLoadSpeedProfile* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64"",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->Q_TRACKINIT,
            p->D_AXLELOAD,
            p->L_AXLELOAD,
            p->Q_FRONT,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        AxleLoadSpeedProfile_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, "%"PRIu64"",
            p->N_ITER_2);

    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        AxleLoadSpeedProfile_2_Print(&p->sub_2[i], stream);
    }

    fprintf(stream, ")");
}

static inline int AxleLoadSpeedProfile_Equal(const AxleLoadSpeedProfile* a, const AxleLoadSpeedProfile* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->Q_TRACKINIT == b->Q_TRACKINIT);
    status = status && (a->D_AXLELOAD == b->D_AXLELOAD);
    status = status && (a->L_AXLELOAD == b->L_AXLELOAD);
    status = status && (a->Q_FRONT == b->Q_FRONT);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && AxleLoadSpeedProfile_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }
    status = status && (a->N_ITER_2 == b->N_ITER_2);
    if (a->N_ITER_2 == b->N_ITER_2)
    {
        for (uint32_t i = 0; i < a->N_ITER_2; ++i)
        {
            status = status && AxleLoadSpeedProfile_2_Equal(&a->sub_2[i], &b->sub_2[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t AxleLoadSpeedProfile_Length(const AxleLoadSpeedProfile* p)
{
    return (uint32_t)(p->L_PACKET);
}

int AxleLoadSpeedProfile_EncodeInt(const AxleLoadSpeedProfile* p, PacketInfo* data, kcg_int* stream);

int AxleLoadSpeedProfile_DecodeInt(AxleLoadSpeedProfile* p, const PacketInfo* data, const kcg_int* stream);

#endif // AXLELOADSPEEDPROFILE_H_INCLUDED

