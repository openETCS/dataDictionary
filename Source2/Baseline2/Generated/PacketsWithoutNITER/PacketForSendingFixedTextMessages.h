
#ifndef PACKETFORSENDINGFIXEDTEXTMESSAGES_H_INCLUDED
#define PACKETFORSENDINGFIXEDTEXTMESSAGES_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_PacketForSendingFixedTextMessages
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) 

- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): Fraunhofer FOKUS

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.       
============================================================================= */

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct PacketForSendingFixedTextMessages
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Packet Number = 76

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
    uint64_t   Q_TEXT;           // # 8
};

typedef struct PacketForSendingFixedTextMessages PacketForSendingFixedTextMessages;

#define PACKETFORSENDINGFIXEDTEXTMESSAGES_BITSIZE 84

PacketForSendingFixedTextMessages*  PacketForSendingFixedTextMessages_New(void);

void   PacketForSendingFixedTextMessages_Delete(PacketForSendingFixedTextMessages*);

static inline void PacketForSendingFixedTextMessages_Init(PacketForSendingFixedTextMessages* p)
{
    p->header.NID_PACKET = 76;
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
    p->Q_TEXT = 0;
}

/*@
    logic integer BitSize{L}(PacketForSendingFixedTextMessages* p) = PACKETFORSENDINGFIXEDTEXTMESSAGES_BITSIZE;

    logic integer MaxBitSize{L}(PacketForSendingFixedTextMessages* p) = BitSize(p);

    predicate Separated(Bitstream* stream, PacketForSendingFixedTextMessages* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(PacketForSendingFixedTextMessages* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TEXTCLASS)       &&
      Invariant(p->Q_TEXTDISPLAY)     &&
      Invariant(p->D_TEXTDISPLAY)     &&
      Invariant(p->M_MODETEXTDISPLAY_0) &&
      Invariant(p->M_LEVELTEXTDISPLAY_0);

    predicate ZeroInitialized(PacketForSendingFixedTextMessages* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TEXTCLASS)       &&
      ZeroInitialized(p->Q_TEXTDISPLAY)     &&
      ZeroInitialized(p->D_TEXTDISPLAY)     &&
      ZeroInitialized(p->M_MODETEXTDISPLAY_0) &&
      ZeroInitialized(p->M_LEVELTEXTDISPLAY_0);

    predicate EqualBits(Bitstream* stream, integer pos, PacketForSendingFixedTextMessages* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 19,  p->Q_TEXTCLASS)       &&
      EqualBits(stream, pos + 19,  pos + 20,  p->Q_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 20,  pos + 35,  p->D_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 35,  pos + 39,  p->M_MODETEXTDISPLAY_0) &&
      EqualBits(stream, pos + 39,  pos + 42,  p->M_LEVELTEXTDISPLAY_0);

    predicate UpperBitsNotSet(PacketForSendingFixedTextMessages* p) =
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
int PacketForSendingFixedTextMessages_UpperBitsNotSet(const PacketForSendingFixedTextMessages* p);

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
int PacketForSendingFixedTextMessages_EncodeBit(const PacketForSendingFixedTextMessages* p, Bitstream* stream);

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
int PacketForSendingFixedTextMessages_DecodeBit(PacketForSendingFixedTextMessages* p, Bitstream* stream);

static inline void PacketForSendingFixedTextMessages_Print(const PacketForSendingFixedTextMessages* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu)",
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
            p->Q_TEXT);
}

static inline int PacketForSendingFixedTextMessages_Equal(const PacketForSendingFixedTextMessages* a, const PacketForSendingFixedTextMessages* b)
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
    status = status && (a->Q_TEXT == b->Q_TEXT);

    return status;
}

static inline uint32_t PacketForSendingFixedTextMessages_Length(const PacketForSendingFixedTextMessages* p)
{
    return (uint32_t)(p->L_PACKET);
}

int PacketForSendingFixedTextMessages_EncodeInt(const PacketForSendingFixedTextMessages* p, Metadata* data, kcg_int* stream);

int PacketForSendingFixedTextMessages_DecodeInt(PacketForSendingFixedTextMessages* p, const Metadata* data, const kcg_int* stream);

#endif // PACKETFORSENDINGFIXEDTEXTMESSAGES_H_INCLUDED

