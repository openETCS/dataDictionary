
#ifndef SESSION_MANAGEMENT_DATA_H_INCLUDED
#define SESSION_MANAGEMENT_DATA_H_INCLUDED

#include "Bitstream.h"

struct Session_Management_Data
{
    // TransmissionMedia=Balise, RBC
    // Packet to give the identity and telephone number of the RBC with which a session shall be established or terminated.
    // Packet Number = 42

    uint32_t  Q_DIR;            // # 2
    uint32_t  Q_RBC;            // # 1
    uint16_t  NID_C;            // # 10
    uint16_t  NID_RBC;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint32_t  Q_SLEEPSESSION;   // # 1
};

typedef struct Session_Management_Data Session_Management_Data;

#define SESSION_MANAGEMENT_DATA_BITSIZE 105

/*@
    logic integer BitSize{L}(Session_Management_Data* p) = SESSION_MANAGEMENT_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Session_Management_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Session_Management_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Session_Management_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->Q_RBC)             &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_RBC)           &&
      Invariant(p->NID_RADIO)         &&
      Invariant(p->Q_SLEEPSESSION);

    predicate ZeroInitialized(Session_Management_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->Q_RBC)             &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_RBC)           &&
      ZeroInitialized(p->NID_RADIO)         &&
      ZeroInitialized(p->Q_SLEEPSESSION);

    predicate EqualBits(Bitstream* stream, integer pos, Session_Management_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_RBC)             &&
      EqualBits(stream, pos + 16,  pos + 26,  p->NID_C)             &&
      EqualBits(stream, pos + 26,  pos + 40,  p->NID_RBC)           &&
      EqualBits(stream, pos + 40,  pos + 104, p->NID_RADIO)         &&
      EqualBits(stream, pos + 104, pos + 105, p->Q_SLEEPSESSION);


    predicate UpperBitsNotSet(Session_Management_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->Q_RBC,            1)   &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_RBC,          14)  &&
      UpperBitsNotSet(p->NID_RADIO,        64)  &&
      UpperBitsNotSet(p->Q_SLEEPSESSION,   1);

*/

#endif // SESSION_MANAGEMENT_DATA_H_INCLUDED

