
#ifndef MODEPROFILE_H_INCLUDED
#define MODEPROFILE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"
#include "ModeProfile_1.h"

struct ModeProfile
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Mode profile associated to an MA
    // Packet Number = 80

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_MAMODE;         // # 15
    uint64_t   M_MAMODE;         // # 2
    uint64_t   V_MAMODE;         // # 7
    uint64_t  L_MAMODE;         // # 15
    uint64_t  L_ACKMAMODE;      // # 15
    uint64_t   N_ITER_1;         // # 5
    ModeProfile_1   sub_1[31];
};

typedef struct ModeProfile ModeProfile;

#define MODEPROFILE_BITSIZE 76

ModeProfile*  ModeProfile_New(void);

void   ModeProfile_Delete(ModeProfile*);

static inline void ModeProfile_Init(ModeProfile* p)
{
    p->header.NID_PACKET = 80;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->D_MAMODE = 0;
    p->M_MAMODE = 0;
    p->V_MAMODE = 0;
    p->L_MAMODE = 0;
    p->L_ACKMAMODE = 0;
    p->N_ITER_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        ModeProfile_1_Init(&(p->sub_1[i]));
    }

}

/*@
    logic integer BitSize{L}(ModeProfile* p) = MODEPROFILE_BITSIZE;

    logic integer MaxBitSize{L}(ModeProfile* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ModeProfile* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ModeProfile* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_MAMODE)          &&
      Invariant(p->M_MAMODE)          &&
      Invariant(p->V_MAMODE)          &&
      Invariant(p->L_MAMODE)          &&
      Invariant(p->L_ACKMAMODE);

    predicate ZeroInitialized(ModeProfile* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_MAMODE)          &&
      ZeroInitialized(p->M_MAMODE)          &&
      ZeroInitialized(p->V_MAMODE)          &&
      ZeroInitialized(p->L_MAMODE)          &&
      ZeroInitialized(p->L_ACKMAMODE);

    predicate EqualBits(Bitstream* stream, integer pos, ModeProfile* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_MAMODE)          &&
      EqualBits(stream, pos + 32,  pos + 34,  p->M_MAMODE)          &&
      EqualBits(stream, pos + 34,  pos + 41,  p->V_MAMODE)          &&
      EqualBits(stream, pos + 41,  pos + 56,  p->L_MAMODE)          &&
      EqualBits(stream, pos + 56,  pos + 71,  p->L_ACKMAMODE);

    predicate UpperBitsNotSet(ModeProfile* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_MAMODE,         15)  &&
      UpperBitsNotSet(p->M_MAMODE,         2)   &&
      UpperBitsNotSet(p->V_MAMODE,         7)   &&
      UpperBitsNotSet(p->L_MAMODE,         15)  &&
      UpperBitsNotSet(p->L_ACKMAMODE,      15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ModeProfile_UpperBitsNotSet(const ModeProfile* p);

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
int ModeProfile_EncodeBit(const ModeProfile* p, Bitstream* stream);

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
int ModeProfile_DecodeBit(ModeProfile* p, Bitstream* stream);

static inline void ModeProfile_Print(const ModeProfile* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->D_MAMODE,
            p->M_MAMODE,
            p->V_MAMODE,
            p->L_MAMODE,
            p->L_ACKMAMODE,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        ModeProfile_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int ModeProfile_Equal(const ModeProfile* a, const ModeProfile* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->D_MAMODE == b->D_MAMODE);
    status = status && (a->M_MAMODE == b->M_MAMODE);
    status = status && (a->V_MAMODE == b->V_MAMODE);
    status = status && (a->L_MAMODE == b->L_MAMODE);
    status = status && (a->L_ACKMAMODE == b->L_ACKMAMODE);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && ModeProfile_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t ModeProfile_Length(const ModeProfile* p)
{
    return (uint32_t)(p->L_PACKET);
}

int ModeProfile_EncodeInt(const ModeProfile* p, Metadata* data, kcg_int* stream);

int ModeProfile_DecodeInt(ModeProfile* p, const Metadata* data, const kcg_int* stream);

#endif // MODEPROFILE_H_INCLUDED

