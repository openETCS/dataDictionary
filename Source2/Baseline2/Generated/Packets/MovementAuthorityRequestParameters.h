
#ifndef MOVEMENTAUTHORITYREQUESTPARAMETERS_H_INCLUDED
#define MOVEMENTAUTHORITYREQUESTPARAMETERS_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct MovementAuthorityRequestParameters
{
    PacketHeader header;

    // TransmissionMedia=Radio
    // This packet is intended to give parameters telling when and how
    // often the train has to ask for a movement authority.
    // Packet Number = 57

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   T_MAR;            // # 8
    uint64_t  T_TIMEOUTRQST;    // # 10
    uint64_t   T_CYCRQST;        // # 8
};

typedef struct MovementAuthorityRequestParameters MovementAuthorityRequestParameters;

#define MOVEMENTAUTHORITYREQUESTPARAMETERS_BITSIZE 41

MovementAuthorityRequestParameters*  MovementAuthorityRequestParameters_New(void);

void   MovementAuthorityRequestParameters_Delete(MovementAuthorityRequestParameters*);

static inline void MovementAuthorityRequestParameters_Init(MovementAuthorityRequestParameters* p)
{
    p->header.NID_PACKET = 57;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->T_MAR = 0;
    p->T_TIMEOUTRQST = 0;
    p->T_CYCRQST = 0;
}

/*@
    logic integer BitSize{L}(MovementAuthorityRequestParameters* p) = MOVEMENTAUTHORITYREQUESTPARAMETERS_BITSIZE;

    logic integer MaxBitSize{L}(MovementAuthorityRequestParameters* p) = BitSize(p);

    predicate Separated(Bitstream* stream, MovementAuthorityRequestParameters* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(MovementAuthorityRequestParameters* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->T_MAR)             &&
      Invariant(p->T_TIMEOUTRQST)     &&
      Invariant(p->T_CYCRQST);

    predicate ZeroInitialized(MovementAuthorityRequestParameters* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->T_MAR)             &&
      ZeroInitialized(p->T_TIMEOUTRQST)     &&
      ZeroInitialized(p->T_CYCRQST);

    predicate EqualBits(Bitstream* stream, integer pos, MovementAuthorityRequestParameters* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 23,  p->T_MAR)             &&
      EqualBits(stream, pos + 23,  pos + 33,  p->T_TIMEOUTRQST)     &&
      EqualBits(stream, pos + 33,  pos + 41,  p->T_CYCRQST);

    predicate UpperBitsNotSet(MovementAuthorityRequestParameters* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->T_MAR,            8)   &&
      UpperBitsNotSet(p->T_TIMEOUTRQST,    10)  &&
      UpperBitsNotSet(p->T_CYCRQST,        8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int MovementAuthorityRequestParameters_UpperBitsNotSet(const MovementAuthorityRequestParameters* p);

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
int MovementAuthorityRequestParameters_EncodeBit(const MovementAuthorityRequestParameters* p, Bitstream* stream);

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
int MovementAuthorityRequestParameters_DecodeBit(MovementAuthorityRequestParameters* p, Bitstream* stream);

static inline void MovementAuthorityRequestParameters_Print(const MovementAuthorityRequestParameters* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64")",
            p->Q_DIR,
            p->L_PACKET,
            p->T_MAR,
            p->T_TIMEOUTRQST,
            p->T_CYCRQST);
}

static inline int MovementAuthorityRequestParameters_Equal(const MovementAuthorityRequestParameters* a, const MovementAuthorityRequestParameters* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->T_MAR == b->T_MAR);
    status = status && (a->T_TIMEOUTRQST == b->T_TIMEOUTRQST);
    status = status && (a->T_CYCRQST == b->T_CYCRQST);

    return status;
}

static inline uint32_t MovementAuthorityRequestParameters_Length(const MovementAuthorityRequestParameters* p)
{
    return (uint32_t)(p->L_PACKET);
}

int MovementAuthorityRequestParameters_EncodeInt(const MovementAuthorityRequestParameters* p, PacketInfo* data, kcg_int* stream);

int MovementAuthorityRequestParameters_DecodeInt(MovementAuthorityRequestParameters* p, const PacketInfo* data, const kcg_int* stream);

#endif // MOVEMENTAUTHORITYREQUESTPARAMETERS_H_INCLUDED

