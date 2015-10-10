
#ifndef PACKETHEADER_H_INCLUDED
#define PACKETHEADER_H_INCLUDED

#include "Bit64.h"
#include "Bitstream.h"
#include <stdio.h>
#include <stdlib.h>

struct PacketHeader
{
    uint8_t  NID_PACKET;         // # 8
};

typedef struct PacketHeader PacketHeader;

#define PACKETHEADER_BITSIZE 8

/*@
    logic integer BitSize{L}(PacketHeader* p) = PACKETHEADER_BITSIZE;

    logic integer MaxBitSize{L}(PacketHeader* p) = BitSize(p);

    predicate Separated(Bitstream* stream, PacketHeader* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(PacketHeader* p) =
      Invariant(p->NID_PACKET);

    predicate ZeroInitialized(PacketHeader* p) =
      ZeroInitialized(p->NID_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, PacketHeader* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);


    predicate UpperBitsNotSet(PacketHeader* p) =
      UpperBitsNotSet(p->NID_PACKET,  8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
static inline
int PacketHeader_UpperBitsNotSet(const PacketHeader* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,             8))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


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
static inline
int PacketHeader_Encode(const PacketHeader* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, PACKETHEADER_BITSIZE))
    {
        if (PacketHeader_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 8, p->NID_PACKET);

            //@ assert NID_PACKET:           EqualBits(stream, pos,       pos + 8,  p->NID_PACKET);

            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

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
static inline
int PacketHeader_Decode(PacketHeader* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, PACKETHEADER_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        p->NID_PACKET = Bitstream_Read(stream, 8);

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert NID_PACKET:        UpperBitsNotSet(p->NID_PACKET,        8);

        return 1;
    }
    else
    {
        return 0;
    }
}

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const PacketHeader& p)
{
    stream << +p.NID_PACKET;

    return stream;
}

inline bool operator==(const PacketHeader& a, const PacketHeader& b)
{
    return a.NID_PACKET == b.NID_PACKET;
}

inline bool operator!=(const PacketHeader& a, const PacketHeader& b)
{
    return !(a == b);
}

#endif // __cplusplus

#endif // PACKETHEADER_H_INCLUDED

