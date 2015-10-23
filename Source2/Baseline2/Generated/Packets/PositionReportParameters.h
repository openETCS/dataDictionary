
#ifndef POSITIONREPORTPARAMETERS_H_INCLUDED
#define POSITIONREPORTPARAMETERS_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"
#include "PositionReportParameters_1.h"

struct PositionReportParameters
{
    PacketHeader header;

    // TransmissionMedia=Radio
    // This packet is intended to give parameters telling when and how
    // often the position has to be reported.
    // Packet Number = 58

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t   T_CYCLOC;         // # 8
    uint64_t  D_CYCLOC;         // # 15
    uint64_t   M_LOC;            // # 3
    uint64_t   N_ITER_1;         // # 5
    PositionReportParameters_1   sub_1[31];
};

typedef struct PositionReportParameters PositionReportParameters;

#define POSITIONREPORTPARAMETERS_BITSIZE 48

PositionReportParameters*  PositionReportParameters_New(void);

void   PositionReportParameters_Delete(PositionReportParameters*);

static inline void PositionReportParameters_Init(PositionReportParameters* p)
{
    p->header.NID_PACKET = 58;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->T_CYCLOC = 0;
    p->D_CYCLOC = 0;
    p->M_LOC = 0;
}

/*@
    logic integer BitSize{L}(PositionReportParameters* p) = POSITIONREPORTPARAMETERS_BITSIZE;

    logic integer MaxBitSize{L}(PositionReportParameters* p) = BitSize(p);

    predicate Separated(Bitstream* stream, PositionReportParameters* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(PositionReportParameters* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->T_CYCLOC)          &&
      Invariant(p->D_CYCLOC)          &&
      Invariant(p->M_LOC);

    predicate ZeroInitialized(PositionReportParameters* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->T_CYCLOC)          &&
      ZeroInitialized(p->D_CYCLOC)          &&
      ZeroInitialized(p->M_LOC);

    predicate EqualBits(Bitstream* stream, integer pos, PositionReportParameters* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 25,  p->T_CYCLOC)          &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_CYCLOC)          &&
      EqualBits(stream, pos + 40,  pos + 43,  p->M_LOC);

    predicate UpperBitsNotSet(PositionReportParameters* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->T_CYCLOC,         8)   &&
      UpperBitsNotSet(p->D_CYCLOC,         15)  &&
      UpperBitsNotSet(p->M_LOC,            3);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int PositionReportParameters_UpperBitsNotSet(const PositionReportParameters* p);

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
int PositionReportParameters_EncodeBit(const PositionReportParameters* p, Bitstream* stream);

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
int PositionReportParameters_DecodeBit(PositionReportParameters* p, Bitstream* stream);

static inline void PositionReportParameters_Print(const PositionReportParameters* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64"",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->T_CYCLOC,
            p->D_CYCLOC,
            p->M_LOC,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        PositionReportParameters_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int PositionReportParameters_Equal(const PositionReportParameters* a, const PositionReportParameters* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->T_CYCLOC == b->T_CYCLOC);
    status = status && (a->D_CYCLOC == b->D_CYCLOC);
    status = status && (a->M_LOC == b->M_LOC);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && PositionReportParameters_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t PositionReportParameters_Length(const PositionReportParameters* p)
{
    return (uint32_t)(p->L_PACKET);
}

int PositionReportParameters_EncodeInt(const PositionReportParameters* p, PacketInfo* data, kcg_int* stream);

int PositionReportParameters_DecodeInt(PositionReportParameters* p, PacketInfo* data, kcg_int* stream);

#endif // POSITIONREPORTPARAMETERS_H_INCLUDED

