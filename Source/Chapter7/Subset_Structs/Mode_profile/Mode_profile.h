
#ifndef MODE_PROFILE_H_INCLUDED
#define MODE_PROFILE_H_INCLUDED

#include "Bitstream.h"

struct Mode_profile
{
    // TransmissionMedia=Any
    // Mode profile associated to an MA
    // Packet Number = 80

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_MAMODE;         // # 15
    uint64_t  M_MAMODE;         // # 2
    uint64_t  V_MAMODE;         // # 7
    uint64_t  L_MAMODE;         // # 15
    uint64_t  L_ACKMAMODE;      // # 15
    uint64_t  Q_MAMODE;         // # 1
    uint64_t  N_ITER;           // # 5// # 15// # 2// # 7// # 15// # 15// # 1
};

typedef struct Mode_profile Mode_profile;

#define MODE_PROFILE_BITSIZE 140

/*@
    logic integer BitSize{L}(Mode_profile* p) = MODE_PROFILE_BITSIZE;

    logic integer MaxBitSize{L}(Mode_profile* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Mode_profile* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Mode_profile* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_MAMODE)          &&
      Invariant(p->M_MAMODE)          &&
      Invariant(p->V_MAMODE)          &&
      Invariant(p->L_MAMODE)          &&
      Invariant(p->L_ACKMAMODE)       &&
      Invariant(p->Q_MAMODE)          &&
      Invariant(p->N_ITER)            &&
      Invariant(p->D_MAMODE(k))       &&
      Invariant(p->M_MAMODE(k))       &&
      Invariant(p->V_MAMODE(k))       &&
      Invariant(p->L_MAMODE(k))       &&
      Invariant(p->L_ACKMAMODE(k))    &&
      Invariant(p->Q_MAMODE(k));

    predicate ZeroInitialized(Mode_profile* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_MAMODE)          &&
      ZeroInitialized(p->M_MAMODE)          &&
      ZeroInitialized(p->V_MAMODE)          &&
      ZeroInitialized(p->L_MAMODE)          &&
      ZeroInitialized(p->L_ACKMAMODE)       &&
      ZeroInitialized(p->Q_MAMODE)          &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->D_MAMODE(k))       &&
      ZeroInitialized(p->M_MAMODE(k))       &&
      ZeroInitialized(p->V_MAMODE(k))       &&
      ZeroInitialized(p->L_MAMODE(k))       &&
      ZeroInitialized(p->L_ACKMAMODE(k))    &&
      ZeroInitialized(p->Q_MAMODE(k));

    predicate EqualBits(Bitstream* stream, integer pos, Mode_profile* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_MAMODE)          &&
      EqualBits(stream, pos + 40,  pos + 42,  p->M_MAMODE)          &&
      EqualBits(stream, pos + 42,  pos + 49,  p->V_MAMODE)          &&
      EqualBits(stream, pos + 49,  pos + 64,  p->L_MAMODE)          &&
      EqualBits(stream, pos + 64,  pos + 79,  p->L_ACKMAMODE)       &&
      EqualBits(stream, pos + 79,  pos + 80,  p->Q_MAMODE)          &&
      EqualBits(stream, pos + 80,  pos + 85,  p->N_ITER)            &&
      EqualBits(stream, pos + 85,  pos + 100, p->D_MAMODE(k))       &&
      EqualBits(stream, pos + 100, pos + 102, p->M_MAMODE(k))       &&
      EqualBits(stream, pos + 102, pos + 109, p->V_MAMODE(k))       &&
      EqualBits(stream, pos + 109, pos + 124, p->L_MAMODE(k))       &&
      EqualBits(stream, pos + 124, pos + 139, p->L_ACKMAMODE(k))    &&
      EqualBits(stream, pos + 139, pos + 140, p->Q_MAMODE(k));


    predicate UpperBitsNotSet(Mode_profile* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_MAMODE,         15)  &&
      UpperBitsNotSet(p->M_MAMODE,         2)   &&
      UpperBitsNotSet(p->V_MAMODE,         7)   &&
      UpperBitsNotSet(p->L_MAMODE,         15)  &&
      UpperBitsNotSet(p->L_ACKMAMODE,      15)  &&
      UpperBitsNotSet(p->Q_MAMODE,         1)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->D_MAMODE(k),      15)  &&
      UpperBitsNotSet(p->M_MAMODE(k),      2)   &&
      UpperBitsNotSet(p->V_MAMODE(k),      7)   &&
      UpperBitsNotSet(p->L_MAMODE(k),      15)  &&
      UpperBitsNotSet(p->L_ACKMAMODE(k),   15)  &&
      UpperBitsNotSet(p->Q_MAMODE(k),      1);

*/

#endif // MODE_PROFILE_H_INCLUDED

