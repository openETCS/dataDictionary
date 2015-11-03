
#ifndef DANGERFORSHUNTINGINFORMATION_H_INCLUDED
#define DANGERFORSHUNTINGINFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct DangerForShuntingInformation
{
    PacketHeader header;

    // TransmissionMedia=Balise
    // Transmission of the aspect of a shunting signal
    // Packet Number = 132

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_ASPECT;         // # 1
};

typedef struct DangerForShuntingInformation DangerForShuntingInformation;

#define DANGERFORSHUNTINGINFORMATION_BITSIZE 16

DangerForShuntingInformation*  DangerForShuntingInformation_New(void);

void   DangerForShuntingInformation_Delete(DangerForShuntingInformation*);

static inline void DangerForShuntingInformation_Init(DangerForShuntingInformation* p)
{
    p->header.NID_PACKET = 132;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_ASPECT = 0;
}

/*@
    logic integer BitSize{L}(DangerForShuntingInformation* p) = DANGERFORSHUNTINGINFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(DangerForShuntingInformation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, DangerForShuntingInformation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(DangerForShuntingInformation* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_ASPECT);

    predicate ZeroInitialized(DangerForShuntingInformation* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_ASPECT);

    predicate EqualBits(Bitstream* stream, integer pos, DangerForShuntingInformation* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

    predicate UpperBitsNotSet(DangerForShuntingInformation* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_ASPECT,         1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int DangerForShuntingInformation_UpperBitsNotSet(const DangerForShuntingInformation* p);

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
int DangerForShuntingInformation_EncodeBit(const DangerForShuntingInformation* p, Bitstream* stream);

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
int DangerForShuntingInformation_DecodeBit(DangerForShuntingInformation* p, Bitstream* stream);

static inline void DangerForShuntingInformation_Print(const DangerForShuntingInformation* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu)",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_ASPECT);
}

static inline int DangerForShuntingInformation_Equal(const DangerForShuntingInformation* a, const DangerForShuntingInformation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_ASPECT == b->Q_ASPECT);

    return status;
}

static inline uint32_t DangerForShuntingInformation_Length(const DangerForShuntingInformation* p)
{
    return (uint32_t)(p->L_PACKET);
}

int DangerForShuntingInformation_EncodeInt(const DangerForShuntingInformation* p, Metadata* data, kcg_int* stream);

int DangerForShuntingInformation_DecodeInt(DangerForShuntingInformation* p, const Metadata* data, const kcg_int* stream);

#endif // DANGERFORSHUNTINGINFORMATION_H_INCLUDED

