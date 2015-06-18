
#ifndef END_OF_INFORMATION_CORE_H_INCLUDED
#define END_OF_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct End_of_Information_Core
{
    // TransmissionMedia=Balise, Loop
    // This packet consists only of NID_PACKET containing 8 bit 1sIt acts
    // as a finish flag; the receiver will stop reading the remaining
    // part of the message/telegram when receiving eight bits set to one
    // in the NID_PACKET field.       
    // Packet Number = 255

};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const End_of_Information_Core& p)
{
    

    return stream;
}

inline bool operator==(const End_of_Information_Core& a, const End_of_Information_Core& b)
{
    bool status = true;
    

    return status;
}

inline bool operator!=(const End_of_Information_Core& a, const End_of_Information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct End_of_Information_Core End_of_Information_Core;

#define END_OF_INFORMATION_CORE_BITSIZE 0

/*@
    logic integer BitSize{L}(End_of_Information_Core* p) = END_OF_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(End_of_Information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, End_of_Information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(End_of_Information_Core* p) = \true;

    predicate ZeroInitialized(End_of_Information_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, End_of_Information_Core* p) = \true;

    predicate UpperBitsNotSet(End_of_Information_Core* p) = \true;

*/

#endif // END_OF_INFORMATION_CORE_H_INCLUDED

