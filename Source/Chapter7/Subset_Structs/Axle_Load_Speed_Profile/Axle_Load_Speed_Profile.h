
#ifndef AXLE_LOAD_SPEED_PROFILE_H_INCLUDED
#define AXLE_LOAD_SPEED_PROFILE_H_INCLUDED

#include "Bitstream.h"

struct Axle_Load_Speed_Profile
{
    // TransmissionMedia=Any
    // This packet gives the speed restrictions for trains with axle load category higher than or equal to the specified value for the speed restriction
    // Packet Number = 51

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  Q_TRACKINIT;      // # 1
    uint64_t  D_TRACKINIT;      // # 15
    uint64_t  D_AXLELOAD;       // # 15
    uint64_t  L_AXLELOAD;       // # 15
    uint64_t  Q_FRONT;          // # 1
    uint64_t  N_ITER;           // # 5// # 7// # 7
    uint64_t  N_ITER;           // # 5// # 15// # 15// # 1// # 5// # 7// # 7
};

typedef struct Axle_Load_Speed_Profile Axle_Load_Speed_Profile;

#define AXLE_LOAD_SPEED_PROFILE_BITSIZE 146

/*@
    logic integer BitSize{L}(Axle_Load_Speed_Profile* p) = AXLE_LOAD_SPEED_PROFILE_BITSIZE;

    logic integer MaxBitSize{L}(Axle_Load_Speed_Profile* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Axle_Load_Speed_Profile* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Axle_Load_Speed_Profile* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TRACKINIT)       &&
      Invariant(p->D_TRACKINIT)       &&
      Invariant(p->D_AXLELOAD)        &&
      Invariant(p->L_AXLELOAD)        &&
      Invariant(p->Q_FRONT)           &&
      Invariant(p->N_ITER)            &&
      Invariant(p->M_AXLELOADCAT(n))  &&
      Invariant(p->V_AXLELOAD(n))     &&
      Invariant(p->N_ITER)            &&
      Invariant(p->D_AXLELOAD(k))     &&
      Invariant(p->L_AXLELOAD(k))     &&
      Invariant(p->Q_FRONT(k))        &&
      Invariant(p->N_ITER(k))         &&
      Invariant(p->M_AXLELOADCAT(k,m)) &&
      Invariant(p->V_AXLELOAD(k,m));

    predicate ZeroInitialized(Axle_Load_Speed_Profile* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TRACKINIT)       &&
      ZeroInitialized(p->D_TRACKINIT)       &&
      ZeroInitialized(p->D_AXLELOAD)        &&
      ZeroInitialized(p->L_AXLELOAD)        &&
      ZeroInitialized(p->Q_FRONT)           &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->M_AXLELOADCAT(n))  &&
      ZeroInitialized(p->V_AXLELOAD(n))     &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->D_AXLELOAD(k))     &&
      ZeroInitialized(p->L_AXLELOAD(k))     &&
      ZeroInitialized(p->Q_FRONT(k))        &&
      ZeroInitialized(p->N_ITER(k))         &&
      ZeroInitialized(p->M_AXLELOADCAT(k,m)) &&
      ZeroInitialized(p->V_AXLELOAD(k,m));

    predicate EqualBits(Bitstream* stream, integer pos, Axle_Load_Speed_Profile* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 26,  p->Q_TRACKINIT)       &&
      EqualBits(stream, pos + 26,  pos + 41,  p->D_TRACKINIT)       &&
      EqualBits(stream, pos + 41,  pos + 56,  p->D_AXLELOAD)        &&
      EqualBits(stream, pos + 56,  pos + 71,  p->L_AXLELOAD)        &&
      EqualBits(stream, pos + 71,  pos + 72,  p->Q_FRONT)           &&
      EqualBits(stream, pos + 72,  pos + 77,  p->N_ITER)            &&
      EqualBits(stream, pos + 77,  pos + 84,  p->M_AXLELOADCAT(n))  &&
      EqualBits(stream, pos + 84,  pos + 91,  p->V_AXLELOAD(n))     &&
      EqualBits(stream, pos + 91,  pos + 96,  p->N_ITER)            &&
      EqualBits(stream, pos + 96,  pos + 111, p->D_AXLELOAD(k))     &&
      EqualBits(stream, pos + 111, pos + 126, p->L_AXLELOAD(k))     &&
      EqualBits(stream, pos + 126, pos + 127, p->Q_FRONT(k))        &&
      EqualBits(stream, pos + 127, pos + 132, p->N_ITER(k))         &&
      EqualBits(stream, pos + 132, pos + 139, p->M_AXLELOADCAT(k,m)) &&
      EqualBits(stream, pos + 139, pos + 146, p->V_AXLELOAD(k,m));


    predicate UpperBitsNotSet(Axle_Load_Speed_Profile* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TRACKINIT,      1)   &&
      UpperBitsNotSet(p->D_TRACKINIT,      15)  &&
      UpperBitsNotSet(p->D_AXLELOAD,       15)  &&
      UpperBitsNotSet(p->L_AXLELOAD,       15)  &&
      UpperBitsNotSet(p->Q_FRONT,          1)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->M_AXLELOADCAT(n), 7)   &&
      UpperBitsNotSet(p->V_AXLELOAD(n),    7)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->D_AXLELOAD(k),    15)  &&
      UpperBitsNotSet(p->L_AXLELOAD(k),    15)  &&
      UpperBitsNotSet(p->Q_FRONT(k),       1)   &&
      UpperBitsNotSet(p->N_ITER(k),        5)   &&
      UpperBitsNotSet(p->M_AXLELOADCAT(k,m),7)   &&
      UpperBitsNotSet(p->V_AXLELOAD(k,m),  7);

*/

#endif // AXLE_LOAD_SPEED_PROFILE_H_INCLUDED

