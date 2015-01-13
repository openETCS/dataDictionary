
#ifndef STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_H_INCLUDED
#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_H_INCLUDED

#include "Bitstream.h"

struct Staff_Responsible_distance_Information_from_loop
{
    // TransmissionMedia=Loop
    // Information for trains in staff responsible mode
    // Packet Number = 13

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2// # 1// # 10// # 14// # 1// # 10// # 14
    uint64_t  D_SR;             // # 15
    uint64_t  N_ITER;           // # 5// # 1// # 10// # 14// # 15
};

typedef struct Staff_Responsible_distance_Information_from_loop Staff_Responsible_distance_Information_from_loop;

#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_BITSIZE 135

/*@
    logic integer BitSize{L}(Staff_Responsible_distance_Information_from_loop* p) = STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_BITSIZE;

    logic integer MaxBitSize{L}(Staff_Responsible_distance_Information_from_loop* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Staff_Responsible_distance_Information_from_loop* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Staff_Responsible_distance_Information_from_loop* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_NEWCOUNTRY(0))   &&
      Invariant(p->NID_C(0))          &&
      Invariant(p->NID_BG(0))         &&
      Invariant(p->Q_NEWCOUNTRY(1))   &&
      Invariant(p->NID_C(1))          &&
      Invariant(p->NID_BG(1))         &&
      Invariant(p->D_SR)              &&
      Invariant(p->N_ITER)            &&
      Invariant(p->Q_NEWCOUNTRY_(k))  &&
      Invariant(p->NID_C_(k))         &&
      Invariant(p->NID_BG_(k))        &&
      Invariant(p->D_SR_(k));

    predicate ZeroInitialized(Staff_Responsible_distance_Information_from_loop* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_NEWCOUNTRY(0))   &&
      ZeroInitialized(p->NID_C(0))          &&
      ZeroInitialized(p->NID_BG(0))         &&
      ZeroInitialized(p->Q_NEWCOUNTRY(1))   &&
      ZeroInitialized(p->NID_C(1))          &&
      ZeroInitialized(p->NID_BG(1))         &&
      ZeroInitialized(p->D_SR)              &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->Q_NEWCOUNTRY_(k))  &&
      ZeroInitialized(p->NID_C_(k))         &&
      ZeroInitialized(p->NID_BG_(k))        &&
      ZeroInitialized(p->D_SR_(k));

    predicate EqualBits(Bitstream* stream, integer pos, Staff_Responsible_distance_Information_from_loop* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 26,  p->Q_NEWCOUNTRY(0))   &&
      EqualBits(stream, pos + 26,  pos + 36,  p->NID_C(0))          &&
      EqualBits(stream, pos + 36,  pos + 50,  p->NID_BG(0))         &&
      EqualBits(stream, pos + 50,  pos + 51,  p->Q_NEWCOUNTRY(1))   &&
      EqualBits(stream, pos + 51,  pos + 61,  p->NID_C(1))          &&
      EqualBits(stream, pos + 61,  pos + 75,  p->NID_BG(1))         &&
      EqualBits(stream, pos + 75,  pos + 90,  p->D_SR)              &&
      EqualBits(stream, pos + 90,  pos + 95,  p->N_ITER)            &&
      EqualBits(stream, pos + 95,  pos + 96,  p->Q_NEWCOUNTRY_(k))  &&
      EqualBits(stream, pos + 96,  pos + 106, p->NID_C_(k))         &&
      EqualBits(stream, pos + 106, pos + 120, p->NID_BG_(k))        &&
      EqualBits(stream, pos + 120, pos + 135, p->D_SR_(k));


    predicate UpperBitsNotSet(Staff_Responsible_distance_Information_from_loop* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY(0),  1)   &&
      UpperBitsNotSet(p->NID_C(0),         10)  &&
      UpperBitsNotSet(p->NID_BG(0),        14)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY(1),  1)   &&
      UpperBitsNotSet(p->NID_C(1),         10)  &&
      UpperBitsNotSet(p->NID_BG(1),        14)  &&
      UpperBitsNotSet(p->D_SR,             15)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY_(k), 1)   &&
      UpperBitsNotSet(p->NID_C_(k),        10)  &&
      UpperBitsNotSet(p->NID_BG_(k),       14)  &&
      UpperBitsNotSet(p->D_SR_(k),         15);

*/

#endif // STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_H_INCLUDED

