
#ifndef VALIDATED_TRAIN_DATA_H_INCLUDED
#define VALIDATED_TRAIN_DATA_H_INCLUDED

#include "Bitstream.h"

struct Validated_train_data
{
    // TransmissionMedia=RBC
    // Validated train data.
    // Packet Number = 11

    uint64_t  NID_PACKET;       // # 8
    uint64_t  L_PACKET;         // # 13
    uint64_t  NC_CDTRAIN;       // # 4
    uint64_t  NC_TRAIN;         // # 15
    uint64_t  L_TRAIN;          // # 12
    uint64_t  V_MAXTRAIN;       // # 7
    uint64_t  M_LOADINGGAUGE;   // # 8
    uint64_t  M_AXLELOADCAT;    // # 7
    uint64_t  M_AIRTIGHT;       // # 2
    uint64_t  N_AXLE;           // # 10
    uint64_t  N_ITER;           // # 5// # 4// # 10
    uint64_t  N_ITER;           // # 5// # 8
};

typedef struct Validated_train_data Validated_train_data;

#define VALIDATED_TRAIN_DATA_BITSIZE 118

/*@
    logic integer BitSize{L}(Validated_train_data* p) = VALIDATED_TRAIN_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Validated_train_data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Validated_train_data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Validated_train_data* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NC_CDTRAIN)        &&
      Invariant(p->NC_TRAIN)          &&
      Invariant(p->L_TRAIN)           &&
      Invariant(p->V_MAXTRAIN)        &&
      Invariant(p->M_LOADINGGAUGE)    &&
      Invariant(p->M_AXLELOADCAT)     &&
      Invariant(p->M_AIRTIGHT)        &&
      Invariant(p->N_AXLE)            &&
      Invariant(p->N_ITER)            &&
      Invariant(p->M_VOLTAGE(k))      &&
      Invariant(p->NID_CTRACTION(k))  &&
      Invariant(p->N_ITER)            &&
      Invariant(p->NID_NTC(n));

    predicate ZeroInitialized(Validated_train_data* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NC_CDTRAIN)        &&
      ZeroInitialized(p->NC_TRAIN)          &&
      ZeroInitialized(p->L_TRAIN)           &&
      ZeroInitialized(p->V_MAXTRAIN)        &&
      ZeroInitialized(p->M_LOADINGGAUGE)    &&
      ZeroInitialized(p->M_AXLELOADCAT)     &&
      ZeroInitialized(p->M_AIRTIGHT)        &&
      ZeroInitialized(p->N_AXLE)            &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->M_VOLTAGE(k))      &&
      ZeroInitialized(p->NID_CTRACTION(k))  &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->NID_NTC(n));

    predicate EqualBits(Bitstream* stream, integer pos, Validated_train_data* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET)          &&
      EqualBits(stream, pos + 21,  pos + 25,  p->NC_CDTRAIN)        &&
      EqualBits(stream, pos + 25,  pos + 40,  p->NC_TRAIN)          &&
      EqualBits(stream, pos + 40,  pos + 52,  p->L_TRAIN)           &&
      EqualBits(stream, pos + 52,  pos + 59,  p->V_MAXTRAIN)        &&
      EqualBits(stream, pos + 59,  pos + 67,  p->M_LOADINGGAUGE)    &&
      EqualBits(stream, pos + 67,  pos + 74,  p->M_AXLELOADCAT)     &&
      EqualBits(stream, pos + 74,  pos + 76,  p->M_AIRTIGHT)        &&
      EqualBits(stream, pos + 76,  pos + 86,  p->N_AXLE)            &&
      EqualBits(stream, pos + 86,  pos + 91,  p->N_ITER)            &&
      EqualBits(stream, pos + 91,  pos + 95,  p->M_VOLTAGE(k))      &&
      EqualBits(stream, pos + 95,  pos + 105, p->NID_CTRACTION(k))  &&
      EqualBits(stream, pos + 105, pos + 110, p->N_ITER)            &&
      EqualBits(stream, pos + 110, pos + 118, p->NID_NTC(n));


    predicate UpperBitsNotSet(Validated_train_data* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NC_CDTRAIN,       4)   &&
      UpperBitsNotSet(p->NC_TRAIN,         15)  &&
      UpperBitsNotSet(p->L_TRAIN,          12)  &&
      UpperBitsNotSet(p->V_MAXTRAIN,       7)   &&
      UpperBitsNotSet(p->M_LOADINGGAUGE,   8)   &&
      UpperBitsNotSet(p->M_AXLELOADCAT,    7)   &&
      UpperBitsNotSet(p->M_AIRTIGHT,       2)   &&
      UpperBitsNotSet(p->N_AXLE,           10)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->M_VOLTAGE(k),     4)   &&
      UpperBitsNotSet(p->NID_CTRACTION(k), 10)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->NID_NTC(n),       8);

*/

#endif // VALIDATED_TRAIN_DATA_H_INCLUDED

