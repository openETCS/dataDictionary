
#ifndef PACKETFORSENDINGPLAINTEXTMESSAGES_H_INCLUDED
#define PACKETFORSENDINGPLAINTEXTMESSAGES_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"

struct PacketForSendingPlainTextMessages
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Packet Number = 72

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t   Q_TEXTCLASS;      // # 2
    uint64_t   Q_TEXTDISPLAY;    // # 1
    uint64_t  D_TEXTDISPLAY;    // # 15
    uint64_t   M_MODETEXTDISPLAY_0;// # 4
    uint64_t   M_LEVELTEXTDISPLAY_0;// # 3
    uint64_t   NID_STM_0;        // # 8
    uint64_t  L_TEXTDISPLAY;    // # 15
    uint64_t  T_TEXTDISPLAY;    // # 10
    uint64_t   M_MODETEXTDISPLAY_1;// # 4
    uint64_t   M_LEVELTEXTDISPLAY_1;// # 3
    uint64_t   NID_STM_1;        // # 8
    uint64_t   Q_TEXTCONFIRM;    // # 2
    uint64_t   L_TEXT;           // # 8
    uint64_t   X_TEXT;           // # 8
};

typedef struct PacketForSendingPlainTextMessages PacketForSendingPlainTextMessages;

#define PACKETFORSENDINGPLAINTEXTMESSAGES_BITSIZE 92

PacketForSendingPlainTextMessages*  PacketForSendingPlainTextMessages_New(void);

void   PacketForSendingPlainTextMessages_Delete(PacketForSendingPlainTextMessages*);

static inline void PacketForSendingPlainTextMessages_Init(PacketForSendingPlainTextMessages* p)
{
    p->header.NID_PACKET = 72;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->Q_TEXTCLASS = 0;
    p->Q_TEXTDISPLAY = 0;
    p->D_TEXTDISPLAY = 0;
    p->M_MODETEXTDISPLAY_0 = 0;
    p->M_LEVELTEXTDISPLAY_0 = 0;
    p->NID_STM_0 = 0;
    p->L_TEXTDISPLAY = 0;
    p->T_TEXTDISPLAY = 0;
    p->M_MODETEXTDISPLAY_1 = 0;
    p->M_LEVELTEXTDISPLAY_1 = 0;
    p->NID_STM_1 = 0;
    p->Q_TEXTCONFIRM = 0;
    p->L_TEXT = 0;
    p->X_TEXT = 0;
}

/*@
    logic integer BitSize{L}(PacketForSendingPlainTextMessages* p) = PACKETFORSENDINGPLAINTEXTMESSAGES_BITSIZE;

    logic integer MaxBitSize{L}(PacketForSendingPlainTextMessages* p) = BitSize(p);

    predicate Separated(Bitstream* stream, PacketForSendingPlainTextMessages* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(PacketForSendingPlainTextMessages* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TEXTCLASS)       &&
      Invariant(p->Q_TEXTDISPLAY)     &&
      Invariant(p->D_TEXTDISPLAY)     &&
      Invariant(p->M_MODETEXTDISPLAY_0) &&
      Invariant(p->M_LEVELTEXTDISPLAY_0);

    predicate ZeroInitialized(PacketForSendingPlainTextMessages* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TEXTCLASS)       &&
      ZeroInitialized(p->Q_TEXTDISPLAY)     &&
      ZeroInitialized(p->D_TEXTDISPLAY)     &&
      ZeroInitialized(p->M_MODETEXTDISPLAY_0) &&
      ZeroInitialized(p->M_LEVELTEXTDISPLAY_0);

    predicate EqualBits(Bitstream* stream, integer pos, PacketForSendingPlainTextMessages* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 19,  p->Q_TEXTCLASS)       &&
      EqualBits(stream, pos + 19,  pos + 20,  p->Q_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 20,  pos + 35,  p->D_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 35,  pos + 39,  p->M_MODETEXTDISPLAY_0) &&
      EqualBits(stream, pos + 39,  pos + 42,  p->M_LEVELTEXTDISPLAY_0);

    predicate UpperBitsNotSet(PacketForSendingPlainTextMessages* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TEXTCLASS,      2)   &&
      UpperBitsNotSet(p->Q_TEXTDISPLAY,    1)   &&
      UpperBitsNotSet(p->D_TEXTDISPLAY,    15)  &&
      UpperBitsNotSet(p->M_MODETEXTDISPLAY_0,4)   &&
      UpperBitsNotSet(p->M_LEVELTEXTDISPLAY_0,3);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int PacketForSendingPlainTextMessages_UpperBitsNotSet(const PacketForSendingPlainTextMessages* p);

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
int PacketForSendingPlainTextMessages_EncodeBit(const PacketForSendingPlainTextMessages* p, Bitstream* stream);

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
int PacketForSendingPlainTextMessages_DecodeBit(PacketForSendingPlainTextMessages* p, Bitstream* stream);

static inline void PacketForSendingPlainTextMessages_Print(const PacketForSendingPlainTextMessages* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64")",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->Q_TEXTCLASS,
            p->Q_TEXTDISPLAY,
            p->D_TEXTDISPLAY,
            p->M_MODETEXTDISPLAY_0,
            p->M_LEVELTEXTDISPLAY_0,
            p->NID_STM_0,
            p->L_TEXTDISPLAY,
            p->T_TEXTDISPLAY,
            p->M_MODETEXTDISPLAY_1,
            p->M_LEVELTEXTDISPLAY_1,
            p->NID_STM_1,
            p->Q_TEXTCONFIRM,
            p->L_TEXT,
            p->X_TEXT);
}

static inline int PacketForSendingPlainTextMessages_Equal(const PacketForSendingPlainTextMessages* a, const PacketForSendingPlainTextMessages* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->Q_TEXTCLASS == b->Q_TEXTCLASS);
    status = status && (a->Q_TEXTDISPLAY == b->Q_TEXTDISPLAY);
    status = status && (a->D_TEXTDISPLAY == b->D_TEXTDISPLAY);
    status = status && (a->M_MODETEXTDISPLAY_0 == b->M_MODETEXTDISPLAY_0);
    status = status && (a->M_LEVELTEXTDISPLAY_0 == b->M_LEVELTEXTDISPLAY_0);

    if (a->M_LEVELTEXTDISPLAY_0 == 1)
    {
        status = status && (a->NID_STM_0 == b->NID_STM_0);
    }
    status = status && (a->L_TEXTDISPLAY == b->L_TEXTDISPLAY);
    status = status && (a->T_TEXTDISPLAY == b->T_TEXTDISPLAY);
    status = status && (a->M_MODETEXTDISPLAY_1 == b->M_MODETEXTDISPLAY_1);
    status = status && (a->M_LEVELTEXTDISPLAY_1 == b->M_LEVELTEXTDISPLAY_1);

    if (a->M_LEVELTEXTDISPLAY_1 == 1)
    {
        status = status && (a->NID_STM_1 == b->NID_STM_1);
    }
    status = status && (a->Q_TEXTCONFIRM == b->Q_TEXTCONFIRM);
    status = status && (a->L_TEXT == b->L_TEXT);
    status = status && (a->X_TEXT == b->X_TEXT);

    return status;
}

static inline uint32_t PacketForSendingPlainTextMessages_Length(const PacketForSendingPlainTextMessages* p)
{
    return (uint32_t)(p->L_PACKET);
}

int PacketForSendingPlainTextMessages_EncodeInt(const PacketForSendingPlainTextMessages* p, PacketInfo* data, kcg_int* stream);

int PacketForSendingPlainTextMessages_DecodeInt(PacketForSendingPlainTextMessages* p, PacketInfo* data, kcg_int* stream);

#endif // PACKETFORSENDINGPLAINTEXTMESSAGES_H_INCLUDED

