
#ifndef ERRORREPORTING_H_INCLUDED
#define ERRORREPORTING_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct ErrorReporting
{
    PacketHeader header;

    // TransmissionMedia=Radio
    // Error reporting to the RBC
    // Packet Number = 4

    uint64_t  L_PACKET;         // # 13
    uint64_t   M_ERROR;          // # 8
};

typedef struct ErrorReporting ErrorReporting;

#define ERRORREPORTING_BITSIZE 21

ErrorReporting*  ErrorReporting_New(void);

void   ErrorReporting_Delete(ErrorReporting*);

static inline void ErrorReporting_Init(ErrorReporting* p)
{
    p->header.NID_PACKET = 4;
    p->header.list = TRAINTOTRACK;
    p->L_PACKET = 0;
    p->M_ERROR = 0;
}

/*@
    logic integer BitSize{L}(ErrorReporting* p) = ERRORREPORTING_BITSIZE;

    logic integer MaxBitSize{L}(ErrorReporting* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ErrorReporting* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ErrorReporting* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->M_ERROR);

    predicate ZeroInitialized(ErrorReporting* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->M_ERROR);

    predicate EqualBits(Bitstream* stream, integer pos, ErrorReporting* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

    predicate UpperBitsNotSet(ErrorReporting* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->M_ERROR,          8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ErrorReporting_UpperBitsNotSet(const ErrorReporting* p);

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
int ErrorReporting_EncodeBit(const ErrorReporting* p, Bitstream* stream);

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
int ErrorReporting_DecodeBit(ErrorReporting* p, Bitstream* stream);

static inline void ErrorReporting_Print(const ErrorReporting* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64")",
            p->L_PACKET,
            p->M_ERROR);
}

static inline int ErrorReporting_Equal(const ErrorReporting* a, const ErrorReporting* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->M_ERROR == b->M_ERROR);

    return status;
}

static inline uint32_t ErrorReporting_Length(const ErrorReporting* p)
{
    return (uint32_t)(p->L_PACKET);
}

int ErrorReporting_EncodeInt(const ErrorReporting* p, PacketInfo* data, kcg_int* stream);

int ErrorReporting_DecodeInt(ErrorReporting* p, PacketInfo* data, kcg_int* stream);

#endif // ERRORREPORTING_H_INCLUDED

