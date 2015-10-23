
#ifndef VALIDATEDTRAINDATA_H_INCLUDED
#define VALIDATEDTRAINDATA_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"
#include "ValidatedTrainData_1.h"
#include "ValidatedTrainData_2.h"

struct ValidatedTrainData
{
    PacketHeader header;

    // TransmissionMedia=Radio
    // Validated train data. For some variables, if the engine does not
    // know a data value, it may use the corresponding default value
    // Packet Number = 11

    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_OPERATIONAL;  // # 32
    uint64_t  NC_TRAIN;         // # 15
    uint64_t  L_TRAIN;          // # 12
    uint64_t   V_MAXTRAIN;       // # 7
    uint64_t   M_LOADINGGAUGE;   // # 8
    uint64_t   M_AXLELOAD;       // # 7
    uint64_t   M_AIRTIGHT;       // # 2
    uint64_t   N_ITER_1;         // # 5
    ValidatedTrainData_1   sub_1[31];
    uint64_t   N_ITER_2;         // # 5
    ValidatedTrainData_2   sub_2[31];
};

typedef struct ValidatedTrainData ValidatedTrainData;

#define VALIDATEDTRAINDATA_BITSIZE 106

ValidatedTrainData*  ValidatedTrainData_New(void);

void   ValidatedTrainData_Delete(ValidatedTrainData*);

static inline void ValidatedTrainData_Init(ValidatedTrainData* p)
{
    p->header.NID_PACKET = 11;
    p->header.list = TRAINTOTRACK;
    p->L_PACKET = 0;
    p->NID_OPERATIONAL = 0;
    p->NC_TRAIN = 0;
    p->L_TRAIN = 0;
    p->V_MAXTRAIN = 0;
    p->M_LOADINGGAUGE = 0;
    p->M_AXLELOAD = 0;
    p->M_AIRTIGHT = 0;
}

/*@
    logic integer BitSize{L}(ValidatedTrainData* p) = VALIDATEDTRAINDATA_BITSIZE;

    logic integer MaxBitSize{L}(ValidatedTrainData* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ValidatedTrainData* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ValidatedTrainData* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_OPERATIONAL)   &&
      Invariant(p->NC_TRAIN)          &&
      Invariant(p->L_TRAIN)           &&
      Invariant(p->V_MAXTRAIN)        &&
      Invariant(p->M_LOADINGGAUGE)    &&
      Invariant(p->M_AXLELOAD)        &&
      Invariant(p->M_AIRTIGHT);

    predicate ZeroInitialized(ValidatedTrainData* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_OPERATIONAL)   &&
      ZeroInitialized(p->NC_TRAIN)          &&
      ZeroInitialized(p->L_TRAIN)           &&
      ZeroInitialized(p->V_MAXTRAIN)        &&
      ZeroInitialized(p->M_LOADINGGAUGE)    &&
      ZeroInitialized(p->M_AXLELOAD)        &&
      ZeroInitialized(p->M_AIRTIGHT);

    predicate EqualBits(Bitstream* stream, integer pos, ValidatedTrainData* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 45,  p->NID_OPERATIONAL)   &&
      EqualBits(stream, pos + 45,  pos + 60,  p->NC_TRAIN)          &&
      EqualBits(stream, pos + 60,  pos + 72,  p->L_TRAIN)           &&
      EqualBits(stream, pos + 72,  pos + 79,  p->V_MAXTRAIN)        &&
      EqualBits(stream, pos + 79,  pos + 87,  p->M_LOADINGGAUGE)    &&
      EqualBits(stream, pos + 87,  pos + 94,  p->M_AXLELOAD)        &&
      EqualBits(stream, pos + 94,  pos + 96,  p->M_AIRTIGHT);

    predicate UpperBitsNotSet(ValidatedTrainData* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_OPERATIONAL,  32)  &&
      UpperBitsNotSet(p->NC_TRAIN,         15)  &&
      UpperBitsNotSet(p->L_TRAIN,          12)  &&
      UpperBitsNotSet(p->V_MAXTRAIN,       7)   &&
      UpperBitsNotSet(p->M_LOADINGGAUGE,   8)   &&
      UpperBitsNotSet(p->M_AXLELOAD,       7)   &&
      UpperBitsNotSet(p->M_AIRTIGHT,       2);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ValidatedTrainData_UpperBitsNotSet(const ValidatedTrainData* p);

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
int ValidatedTrainData_EncodeBit(const ValidatedTrainData* p, Bitstream* stream);

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
int ValidatedTrainData_DecodeBit(ValidatedTrainData* p, Bitstream* stream);

static inline void ValidatedTrainData_Print(const ValidatedTrainData* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64"",
            p->L_PACKET,
            p->NID_OPERATIONAL,
            p->NC_TRAIN,
            p->L_TRAIN,
            p->V_MAXTRAIN,
            p->M_LOADINGGAUGE,
            p->M_AXLELOAD,
            p->M_AIRTIGHT,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        ValidatedTrainData_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, "%"PRIu64"",
            p->N_ITER_2);

    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        ValidatedTrainData_2_Print(&p->sub_2[i], stream);
    }

    fprintf(stream, ")");
}

static inline int ValidatedTrainData_Equal(const ValidatedTrainData* a, const ValidatedTrainData* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->NID_OPERATIONAL == b->NID_OPERATIONAL);
    status = status && (a->NC_TRAIN == b->NC_TRAIN);
    status = status && (a->L_TRAIN == b->L_TRAIN);
    status = status && (a->V_MAXTRAIN == b->V_MAXTRAIN);
    status = status && (a->M_LOADINGGAUGE == b->M_LOADINGGAUGE);
    status = status && (a->M_AXLELOAD == b->M_AXLELOAD);
    status = status && (a->M_AIRTIGHT == b->M_AIRTIGHT);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && ValidatedTrainData_1_Equal(&a->sub_1[i], &b->sub_1[i]);
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
            status = status && ValidatedTrainData_2_Equal(&a->sub_2[i], &b->sub_2[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t ValidatedTrainData_Length(const ValidatedTrainData* p)
{
    return (uint32_t)(p->L_PACKET);
}

int ValidatedTrainData_EncodeInt(const ValidatedTrainData* p, PacketInfo* data, kcg_int* stream);

int ValidatedTrainData_DecodeInt(ValidatedTrainData* p, PacketInfo* data, kcg_int* stream);

#endif // VALIDATEDTRAINDATA_H_INCLUDED

