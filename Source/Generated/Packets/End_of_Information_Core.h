
#ifndef END_OF_INFORMATION_CORE_H_INCLUDED
#define END_OF_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Compressed_Packets.h"

struct End_of_Information_Core
{
    // TransmissionMedia=Balise, Loop
    // This packet consists only of NID_PACKET containing 8 bit 1sIt acts
    // as a finish flag; the receiver will stop reading the remaining
    // part of the message/telegram when receiving eight bits set to one
    // in the NID_PACKET field.
    // Packet Number = 255

};

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

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int End_of_Information_UpperBitsNotSet(const End_of_Information_Core* p);

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid_read(p);
    requires invariant:         Invariant(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures left:       Unchanged{Here,Old}(stream, 0, \old(stream->bitpos));
      ensures middle:     EqualBits(stream, \old(stream->bitpos), p);
      ensures right:      Unchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    behavior values_too_big:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures result:        \result == -2;

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result:       \result == -1;

    complete behaviors;
    disjoint behaviors;
*/
int End_of_Information_Encode_Bit(Bitstream* stream, const End_of_Information_Core* p);

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          Unchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int End_of_Information_Decode_Bit(Bitstream* stream, End_of_Information_Core* p);

int End_of_Information_Encode_Int(Packet_Info* data, kcg_int* stream, const End_of_Information_Core* p);

int End_of_Information_Decode_Int(Packet_Info* data, const kcg_int* stream, End_of_Information_Core* p);

#ifdef __cplusplus

#include <iostream>

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

inline int encode(Bitstream& stream, const End_of_Information_Core& p)
{
    return End_of_Information_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, End_of_Information_Core& p)
{
    return End_of_Information_Decode_Bit(&stream, &p);
}

inline int encode(Packet_Info& data, kcg_int* stream, const End_of_Information_Core& p)
{
    return End_of_Information_Encode_Int(&data, stream, &p);
}

inline int decode(Packet_Info& data, const kcg_int* stream, End_of_Information_Core& p)
{
    return End_of_Information_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // END_OF_INFORMATION_CORE_H_INCLUDED

