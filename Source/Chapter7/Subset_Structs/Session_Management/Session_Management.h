
#ifndef SESSION_MANAGEMENT_H_INCLUDED
#define SESSION_MANAGEMENT_H_INCLUDED

#include "Bitstream.h"

struct Session_Management
{
    // TransmissionMedia=Balise, RBC
    // Packet to give the identity and telephone number of the RBC with which a session shall be established or terminated.
    // Packet Number = 42

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_RBC;            // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_RBC;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint64_t  Q_SLEEPSESSION;   // # 1
};

typedef struct Session_Management Session_Management;

#define SESSION_MANAGEMENT_BITSIZE 113

/*@
    logic integer BitSize{L}(Session_Management* p) = SESSION_MANAGEMENT_BITSIZE;

    logic integer MaxBitSize{L}(Session_Management* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Session_Management* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Session_Management* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_RBC)             &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_RBC)           &&
      Invariant(p->NID_RADIO)         &&
      Invariant(p->Q_SLEEPSESSION);

    predicate ZeroInitialized(Session_Management* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_RBC)             &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_RBC)           &&
      ZeroInitialized(p->NID_RADIO)         &&
      ZeroInitialized(p->Q_SLEEPSESSION);

    predicate EqualBits(Bitstream* stream, integer pos, Session_Management* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 24,  p->Q_RBC)             &&
      EqualBits(stream, pos + 24,  pos + 34,  p->NID_C)             &&
      EqualBits(stream, pos + 34,  pos + 48,  p->NID_RBC)           &&
      EqualBits(stream, pos + 48,  pos + 112, p->NID_RADIO)         &&
      EqualBits(stream, pos + 112, pos + 113, p->Q_SLEEPSESSION);


    predicate UpperBitsNotSet(Session_Management* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_RBC,            1)   &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_RBC,          14)  &&
      UpperBitsNotSet(p->NID_RADIO,        64)  &&
      UpperBitsNotSet(p->Q_SLEEPSESSION,   1);

*/

#endif // SESSION_MANAGEMENT_H_INCLUDED

