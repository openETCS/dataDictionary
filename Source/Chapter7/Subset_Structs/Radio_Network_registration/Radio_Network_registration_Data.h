
#ifndef RADIO_NETWORK_REGISTRATION_DATA_H_INCLUDED
#define RADIO_NETWORK_REGISTRATION_DATA_H_INCLUDED

#include "Bitstream.h"

struct Radio_Network_registration_Data
{
    // TransmissionMedia=Balise, RBC, RIU
    // Packet to give the identity of the Radio Network to which a registration shall be enforced.
    // Packet Number = 45

    uint32_t  Q_DIR;            // # 2
    uint32_t  NID_MN;           // # 24
};

typedef struct Radio_Network_registration_Data Radio_Network_registration_Data;

#define RADIO_NETWORK_REGISTRATION_DATA_BITSIZE 39

/*@
    logic integer BitSize{L}(Radio_Network_registration_Data* p) = RADIO_NETWORK_REGISTRATION_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Radio_Network_registration_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Radio_Network_registration_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Radio_Network_registration_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->NID_MN);

    predicate ZeroInitialized(Radio_Network_registration_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->NID_MN);

    predicate EqualBits(Bitstream* stream, integer pos, Radio_Network_registration_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 39,  p->NID_MN);


    predicate UpperBitsNotSet(Radio_Network_registration_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->NID_MN,           24);

*/

#endif // RADIO_NETWORK_REGISTRATION_DATA_H_INCLUDED

