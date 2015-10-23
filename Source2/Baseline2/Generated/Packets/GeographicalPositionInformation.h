
#ifndef GEOGRAPHICALPOSITIONINFORMATION_H_INCLUDED
#define GEOGRAPHICALPOSITIONINFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"
#include "GeographicalPositionInformation_1.h"

struct GeographicalPositionInformation
{
    PacketHeader header;

    // TransmissionMedia=Any
    // This packet gives geographical location information for one or multiple references
    // to the train.
    // Packet Number = 79

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t   Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
    uint64_t  D_POSOFF;         // # 15
    uint64_t   Q_MPOSITION;      // # 1
    uint64_t  M_POSITION;       // # 20
    uint64_t   N_ITER_1;         // # 5
    GeographicalPositionInformation_1   sub_1[31];
};

typedef struct GeographicalPositionInformation GeographicalPositionInformation;

#define GEOGRAPHICALPOSITIONINFORMATION_BITSIZE 73

GeographicalPositionInformation*  GeographicalPositionInformation_New(void);

void   GeographicalPositionInformation_Delete(GeographicalPositionInformation*);

static inline void GeographicalPositionInformation_Init(GeographicalPositionInformation* p)
{
    p->header.NID_PACKET = 79;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->Q_NEWCOUNTRY = 0;
    p->NID_C = 0;
    p->NID_BG = 0;
    p->D_POSOFF = 0;
    p->Q_MPOSITION = 0;
    p->M_POSITION = 0;
}

/*@
    logic integer BitSize{L}(GeographicalPositionInformation* p) = GEOGRAPHICALPOSITIONINFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(GeographicalPositionInformation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, GeographicalPositionInformation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(GeographicalPositionInformation* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(GeographicalPositionInformation* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, GeographicalPositionInformation* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 18,  p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(GeographicalPositionInformation* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int GeographicalPositionInformation_UpperBitsNotSet(const GeographicalPositionInformation* p);

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
int GeographicalPositionInformation_EncodeBit(const GeographicalPositionInformation* p, Bitstream* stream);

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
int GeographicalPositionInformation_DecodeBit(GeographicalPositionInformation* p, Bitstream* stream);

static inline void GeographicalPositionInformation_Print(const GeographicalPositionInformation* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64"",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->Q_NEWCOUNTRY,
            p->NID_C,
            p->NID_BG,
            p->D_POSOFF,
            p->Q_MPOSITION,
            p->M_POSITION,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        GeographicalPositionInformation_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int GeographicalPositionInformation_Equal(const GeographicalPositionInformation* a, const GeographicalPositionInformation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->Q_NEWCOUNTRY == b->Q_NEWCOUNTRY);

    if (a->Q_NEWCOUNTRY == 1)
    {
        status = status && (a->NID_C == b->NID_C);
    }
    status = status && (a->NID_BG == b->NID_BG);
    status = status && (a->D_POSOFF == b->D_POSOFF);
    status = status && (a->Q_MPOSITION == b->Q_MPOSITION);
    status = status && (a->M_POSITION == b->M_POSITION);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && GeographicalPositionInformation_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t GeographicalPositionInformation_Length(const GeographicalPositionInformation* p)
{
    return (uint32_t)(p->L_PACKET);
}

int GeographicalPositionInformation_EncodeInt(const GeographicalPositionInformation* p, PacketInfo* data, kcg_int* stream);

int GeographicalPositionInformation_DecodeInt(GeographicalPositionInformation* p, PacketInfo* data, kcg_int* stream);

#endif // GEOGRAPHICALPOSITIONINFORMATION_H_INCLUDED

