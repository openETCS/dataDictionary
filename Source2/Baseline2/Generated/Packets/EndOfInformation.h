
#ifndef ENDOFINFORMATION_H_INCLUDED
#define ENDOFINFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"

struct EndOfInformation
{
    PacketHeader header;

    // TransmissionMedia=Any
    // This packet consists only of NID_PACKET containing 8 bit 1sIt acts
    // as a finish flag ; the receiver will stop reading the
    // remaining part of the message/telegram when receiving eight bits set to
    // one in the NID_PACKET field.
    // Packet Number = 255

};

typedef struct EndOfInformation EndOfInformation;

#define ENDOFINFORMATION_BITSIZE 0

EndOfInformation*  EndOfInformation_New(void);

void   EndOfInformation_Delete(EndOfInformation*);

static inline void EndOfInformation_Init(EndOfInformation* p)
{
    p->header.NID_PACKET = 255;
    p->header.list = BOTHWAYS;
}

/*@
    logic integer BitSize{L}(EndOfInformation* p) = ENDOFINFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(EndOfInformation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, EndOfInformation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(EndOfInformation* p) = \1;

    predicate ZeroInitialized(EndOfInformation* p) = \1;

    predicate EqualBits(Bitstream* stream, integer pos, EndOfInformation* p) = \1;

    predicate UpperBitsNotSet(EndOfInformation* p) = \1;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int EndOfInformation_UpperBitsNotSet(const EndOfInformation* p);

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
int EndOfInformation_EncodeBit(const EndOfInformation* p, Bitstream* stream);

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
int EndOfInformation_DecodeBit(EndOfInformation* p, Bitstream* stream);

static inline void EndOfInformation_Print(const EndOfInformation* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);

}

static inline int EndOfInformation_Equal(const EndOfInformation* a, const EndOfInformation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    

    return status;
}

static inline uint32_t EndOfInformation_Length(const EndOfInformation* p)
{
    return 8;
}

int EndOfInformation_EncodeInt(const EndOfInformation* p, PacketInfo* data, kcg_int* stream);

int EndOfInformation_DecodeInt(EndOfInformation* p, PacketInfo* data, kcg_int* stream);

#endif // ENDOFINFORMATION_H_INCLUDED

