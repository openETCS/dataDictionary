
#ifndef END_OF_INFORMATION_DATA_H_INCLUDED
#define END_OF_INFORMATION_DATA_H_INCLUDED

#include "Bitstream.h"

struct End_of_Information_Data
{
    // TransmissionMedia=Balise, Loop
    // This packet consists only of NID_PACKET containing 8 bit 1sIt acts as a finish flag; the receiver will stop reading the remaining part of the message/telegram when receiving eight bits set to one in the NID_PACKET field.
    // Packet Number = 255

};

typedef struct End_of_Information_Data End_of_Information_Data;

#define END_OF_INFORMATION_DATA_BITSIZE 0

/*@
    logic integer BitSize{L}(End_of_Information_Data* p) = END_OF_INFORMATION_DATA_BITSIZE;

    logic integer MaxBitSize{L}(End_of_Information_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, End_of_Information_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(End_of_Information_Data* p) = \true;

    predicate ZeroInitialized(End_of_Information_Data* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, End_of_Information_Data* p) = \true;


    predicate UpperBitsNotSet(End_of_Information_Data* p) = \true;

*/

#endif // END_OF_INFORMATION_DATA_H_INCLUDED

