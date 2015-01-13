
#ifndef GRADIENT_PROFILE_H_INCLUDED
#define GRADIENT_PROFILE_H_INCLUDED

#include "Bitstream.h"

struct Gradient_Profile
{
    // TransmissionMedia=Any
    // Transmission of the gradient.D_GRADIENT gives the distance to the next change of the gradient value. The gradient value is the minimum gradient for the given distance.
    // Packet Number = 21

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_GRADIENT;       // # 15
    uint64_t  Q_GDIR;           // # 1
    uint64_t  G_A;              // # 8
    uint64_t  N_ITER;           // # 5// # 15// # 1// # 8
};

typedef struct Gradient_Profile Gradient_Profile;

#define GRADIENT_PROFILE_BITSIZE 78

/*@
    logic integer BitSize{L}(Gradient_Profile* p) = GRADIENT_PROFILE_BITSIZE;

    logic integer MaxBitSize{L}(Gradient_Profile* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Gradient_Profile* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Gradient_Profile* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_GRADIENT)        &&
      Invariant(p->Q_GDIR)            &&
      Invariant(p->G_A)               &&
      Invariant(p->N_ITER)            &&
      Invariant(p->D_GRADIENT(k))     &&
      Invariant(p->Q_GDIR(k))         &&
      Invariant(p->G_A(k));

    predicate ZeroInitialized(Gradient_Profile* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_GRADIENT)        &&
      ZeroInitialized(p->Q_GDIR)            &&
      ZeroInitialized(p->G_A)               &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->D_GRADIENT(k))     &&
      ZeroInitialized(p->Q_GDIR(k))         &&
      ZeroInitialized(p->G_A(k));

    predicate EqualBits(Bitstream* stream, integer pos, Gradient_Profile* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_GRADIENT)        &&
      EqualBits(stream, pos + 40,  pos + 41,  p->Q_GDIR)            &&
      EqualBits(stream, pos + 41,  pos + 49,  p->G_A)               &&
      EqualBits(stream, pos + 49,  pos + 54,  p->N_ITER)            &&
      EqualBits(stream, pos + 54,  pos + 69,  p->D_GRADIENT(k))     &&
      EqualBits(stream, pos + 69,  pos + 70,  p->Q_GDIR(k))         &&
      EqualBits(stream, pos + 70,  pos + 78,  p->G_A(k));


    predicate UpperBitsNotSet(Gradient_Profile* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_GRADIENT,       15)  &&
      UpperBitsNotSet(p->Q_GDIR,           1)   &&
      UpperBitsNotSet(p->G_A,              8)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->D_GRADIENT(k),    15)  &&
      UpperBitsNotSet(p->Q_GDIR(k),        1)   &&
      UpperBitsNotSet(p->G_A(k),           8);

*/

#endif // GRADIENT_PROFILE_H_INCLUDED

