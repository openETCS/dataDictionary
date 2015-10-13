
#ifndef TELEGRAMHEADER_H_INCLUDED
#define TELEGRAMHEADER_H_INCLUDED

#include "Bit64.h"
#include "Bitstream.h"
#include <stdio.h>
#include <stdlib.h>

struct TelegramHeader
{

    uint32_t  Q_UPDOWN;         // # 1
    uint8_t   M_VERSION;        // # 7
    uint32_t  Q_MEDIA;          // # 1
    uint8_t   N_PIG;            // # 3
    uint8_t   N_TOTAL;          // # 3
    uint8_t   M_DUP;            // # 2
    uint8_t   M_MCOUNT;         // # 8
    uint16_t  NID_C;            // # 10
    uint16_t  NID_BG;           // # 14
    uint32_t  Q_LINK;           // # 1
};


typedef struct TelegramHeader TelegramHeader;

#define TELEGRAM_HEADER_BITSIZE 50

/*@
    logic integer BitSize{L}(TelegramHeader* p) = TELEGRAM_HEADER_BITSIZE;

    logic integer MaxBitSize{L}(TelegramHeader* p) = BitSize(p);

    predicate Separated(Bitstream* stream, TelegramHeader* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(TelegramHeader* p) =
      Invariant(p->Q_UPDOWN)       &&
      Invariant(p->M_VERSION)      &&
      Invariant(p->Q_MEDIA)        &&
      Invariant(p->N_PIG)          &&
      Invariant(p->N_TOTAL)        &&
      Invariant(p->M_DUP)          &&
      Invariant(p->M_MCOUNT)       &&
      Invariant(p->NID_C)          &&
      Invariant(p->NID_BG)         &&
      Invariant(p->Q_LINK);

    predicate ZeroInitialized(TelegramHeader* p) =
      ZeroInitialized(p->Q_UPDOWN)       &&
      ZeroInitialized(p->M_VERSION)      &&
      ZeroInitialized(p->Q_MEDIA)        &&
      ZeroInitialized(p->N_PIG)          &&
      ZeroInitialized(p->N_TOTAL)        &&
      ZeroInitialized(p->M_DUP)          &&
      ZeroInitialized(p->M_MCOUNT)       &&
      ZeroInitialized(p->NID_C)          &&
      ZeroInitialized(p->NID_BG)         &&
      ZeroInitialized(p->Q_LINK);

    predicate EqualBits(Bitstream* stream, integer pos, TelegramHeader* p) =
      EqualBits(stream, pos,      pos + 1,  p->Q_UPDOWN)  &&
      EqualBits(stream, pos + 1,  pos + 8,  p->M_VERSION) &&
      EqualBits(stream, pos + 8,  pos + 9,  p->Q_MEDIA)   &&
      EqualBits(stream, pos + 9,  pos + 12, p->N_PIG)     &&
      EqualBits(stream, pos + 12, pos + 15, p->N_TOTAL)   &&
      EqualBits(stream, pos + 15, pos + 17, p->M_DUP)     &&
      EqualBits(stream, pos + 17, pos + 25, p->M_MCOUNT)  &&
      EqualBits(stream, pos + 25, pos + 35, p->NID_C)     &&
      EqualBits(stream, pos + 35, pos + 49, p->NID_BG)    &&
      EqualBits(stream, pos + 49, pos + 50, p->Q_LINK);

    predicate UpperBitsNotSet(TelegramHeader* p) =
      UpperBitsNotSet(p->Q_UPDOWN,  1)      &&
      UpperBitsNotSet(p->M_VERSION, 7)      &&
      UpperBitsNotSet(p->Q_MEDIA,   1)      &&
      UpperBitsNotSet(p->N_PIG,     3)      &&
      UpperBitsNotSet(p->N_TOTAL,   3)      &&
      UpperBitsNotSet(p->M_DUP,     2)      &&
      UpperBitsNotSet(p->M_MCOUNT,  8)      &&
      UpperBitsNotSet(p->NID_C,     10)     &&
      UpperBitsNotSet(p->NID_BG,    14)     &&
      UpperBitsNotSet(p->Q_LINK,    1);

*/


/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
static inline
int TelegramHeader_UpperBitsNotSet(const TelegramHeader* p)
{
    if (UpperBitsNotSet64(p->Q_UPDOWN,      1)  &&
        UpperBitsNotSet64(p->M_VERSION,     7)  &&
        UpperBitsNotSet64(p->Q_MEDIA,       1)  &&
        UpperBitsNotSet64(p->N_PIG,         3)  &&
        UpperBitsNotSet64(p->N_TOTAL,       3)  &&
        UpperBitsNotSet64(p->M_DUP,         2)  &&
        UpperBitsNotSet64(p->M_MCOUNT,      8)  &&
        UpperBitsNotSet64(p->NID_C,         10) &&
        UpperBitsNotSet64(p->NID_BG,        14) &&
        UpperBitsNotSet64(p->Q_LINK,        1))
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
int TelegramHeader_EncodeBit(Bitstream* stream, const TelegramHeader* p)
{
    if (Bitstream_Normal(stream, TELEGRAM_HEADER_BITSIZE))
    {
        if (TelegramHeader_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 1,  p->Q_UPDOWN);
            Bitstream_Write(stream, 7,  p->M_VERSION);
            Bitstream_Write(stream, 1,  p->Q_MEDIA);
            Bitstream_Write(stream, 3,  p->N_PIG);
            Bitstream_Write(stream, 3,  p->N_TOTAL);
            Bitstream_Write(stream, 2,  p->M_DUP);
            Bitstream_Write(stream, 8,  p->M_MCOUNT);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_BG);
            Bitstream_Write(stream, 1,  p->Q_LINK);

            //@ assert Q_UPDOWN:          EqualBits(stream, pos,       pos + 1,   p->Q_UPDOWN);
            //@ assert M_VERSION:         EqualBits(stream, pos + 1,   pos + 8,   p->M_VERSION);
            //@ assert Q_MEDIA:           EqualBits(stream, pos + 8,   pos + 9,   p->Q_MEDIA);
            //@ assert N_PIG:             EqualBits(stream, pos + 9,   pos + 12,  p->N_PIG);
            //@ assert N_TOTAL:           EqualBits(stream, pos + 12,  pos + 15,  p->N_TOTAL);
            //@ assert M_DUP:             EqualBits(stream, pos + 15,  pos + 17,  p->M_DUP);
            //@ assert M_MCOUNT:          EqualBits(stream, pos + 17,  pos + 25,  p->M_MCOUNT);
            //@ assert NID_C:             EqualBits(stream, pos + 25,  pos + 35,  p->NID_C);
            //@ assert NID_BG:            EqualBits(stream, pos + 35,  pos + 49,  p->NID_BG);
            //@ assert Q_LINK:            EqualBits(stream, pos + 49,  pos + 50,  p->Q_LINK);

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
int TelegramHeader_DecodeBit(Bitstream* stream, TelegramHeader* p)
{
    if (Bitstream_Normal(stream, TELEGRAM_HEADER_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
           requires Q_UPDOWN: stream->bitpos == pos;
           assigns            stream->bitpos;
           assigns            p->Q_UPDOWN;
           ensures  Q_UPDOWN: stream->bitpos == pos + 1;
           ensures  Q_UPDOWN: EqualBits(stream, pos, pos + 1, p->Q_UPDOWN);
           ensures  Q_UPDOWN: UpperBitsNotSet(p->Q_UPDOWN, 1);
        */
        {
            p->Q_UPDOWN    = Bitstream_Read(stream, 1);
        }

        /*@
           requires M_VERSION: stream->bitpos == pos + 1;
           assigns             stream->bitpos;
           assigns             p->M_VERSION;
           ensures  M_VERSION: stream->bitpos == pos + 8;
           ensures  M_VERSION: EqualBits(stream, pos + 1, pos + 8, p->M_VERSION);
           ensures  M_VERSION: UpperBitsNotSet(p->M_VERSION, 7);
        */
        {
            p->M_VERSION    = Bitstream_Read(stream, 7);
        }

        /*@
           requires Q_MEDIA: stream->bitpos == pos + 8;
           assigns           stream->bitpos;
           assigns           p->Q_MEDIA;
           ensures  Q_MEDIA: stream->bitpos == pos + 9;
           ensures  Q_MEDIA: EqualBits(stream, pos + 8, pos + 9, p->Q_MEDIA);
           ensures  Q_MEDIA: UpperBitsNotSet(p->Q_MEDIA, 1);
        */
        {
            p->Q_MEDIA    = Bitstream_Read(stream, 1);
        }

        /*@
           requires N_PIG: stream->bitpos == pos + 9;
           assigns         stream->bitpos;
           assigns         p->N_PIG;
           ensures  N_PIG: stream->bitpos == pos + 12;
           ensures  N_PIG: EqualBits(stream, pos + 9, pos + 12, p->N_PIG);
           ensures  N_PIG: UpperBitsNotSet(p->N_PIG, 3);
        */
        {
            p->N_PIG    = Bitstream_Read(stream, 3);
        }

        /*@
           requires N_TOTAL: stream->bitpos == pos + 12;
           assigns           stream->bitpos;
           assigns           p->N_TOTAL;
           ensures  N_TOTAL: stream->bitpos == pos + 15;
           ensures  N_TOTAL: EqualBits(stream, pos + 12, pos + 15, p->N_TOTAL);
           ensures  N_TOTAL: UpperBitsNotSet(p->N_TOTAL, 3);
        */
        {
            p->N_TOTAL    = Bitstream_Read(stream, 3);
        }

        /*@
           requires M_DUP: stream->bitpos == pos + 15;
           assigns         stream->bitpos;
           assigns         p->M_DUP;
           ensures  M_DUP: stream->bitpos == pos + 17;
           ensures  M_DUP: EqualBits(stream, pos + 15, pos + 17, p->M_DUP);
           ensures  M_DUP: UpperBitsNotSet(p->M_DUP, 2);
        */
        {
            p->M_DUP    = Bitstream_Read(stream, 2);
        }

        /*@
           requires M_MCOUNT: stream->bitpos == pos + 17;
           assigns            stream->bitpos;
           assigns            p->M_MCOUNT;
           ensures  M_MCOUNT: stream->bitpos == pos + 25;
           ensures  M_MCOUNT: EqualBits(stream, pos + 17, pos + 25, p->M_MCOUNT);
           ensures  M_MCOUNT: UpperBitsNotSet(p->M_MCOUNT, 8);
        */
        {
            p->M_MCOUNT    = Bitstream_Read(stream, 8);
        }

        /*@
           requires NID_C: stream->bitpos == pos + 25;
           assigns         stream->bitpos;
           assigns         p->NID_C;
           ensures  NID_C: stream->bitpos == pos + 35;
           ensures  NID_C: EqualBits(stream, pos + 25, pos + 35, p->NID_C);
           ensures  NID_C: UpperBitsNotSet(p->NID_C, 10);
        */
        {
            p->NID_C    = Bitstream_Read(stream, 10);
        }

        /*@
           requires NID_BG: stream->bitpos == pos + 35;
           assigns          stream->bitpos;
           assigns          p->NID_BG;
           ensures  NID_BG: stream->bitpos == pos + 49;
           ensures  NID_BG: EqualBits(stream, pos + 35, pos + 49, p->NID_BG);
           ensures  NID_BG: UpperBitsNotSet(p->NID_BG, 14);
        */
        {
            p->NID_BG    = Bitstream_Read(stream, 14);
        }

        /*@
           requires Q_LINK: stream->bitpos == pos + 49;
           assigns          stream->bitpos;
           assigns          p->Q_LINK;
           ensures  Q_LINK: stream->bitpos == pos + 50;
           ensures  Q_LINK: EqualBits(stream, pos + 49, pos + 50, p->Q_LINK);
           ensures  Q_LINK: UpperBitsNotSet(p->Q_LINK, 1);
        */
        {
            p->Q_LINK    = Bitstream_Read(stream, 1);
        }

        //@ assert stream->bitpos == \at(stream->bitpos,Pre) + TELEGRAM_HEADER_BITSIZE;

        //@ assert  Q_UPDOWN: EqualBits(stream, pos, pos + 1, p->Q_UPDOWN);
        //@ assert  Q_UPDOWN: UpperBitsNotSet(p->Q_UPDOWN, 1);

        //@ assert  M_VERSION: EqualBits(stream, pos + 1, pos + 8, p->M_VERSION);
        //@ assert  M_VERSION: UpperBitsNotSet(p->M_VERSION, 7);

        //@ assert  Q_MEDIA: EqualBits(stream, pos + 8, pos + 9, p->Q_MEDIA);
        //@ assert  Q_MEDIA: UpperBitsNotSet(p->Q_MEDIA, 1);

        //@ assert  N_PIG: EqualBits(stream, pos + 9, pos + 12, p->N_PIG);
        //@ assert  N_PIG: UpperBitsNotSet(p->N_PIG, 3);

        //@ assert  N_TOTAL: EqualBits(stream, pos + 12, pos + 15, p->N_TOTAL);
        //@ assert  N_TOTAL: UpperBitsNotSet(p->N_TOTAL, 3);

        //@ assert  M_DUP: EqualBits(stream, pos + 15, pos + 17, p->M_DUP);
        //@ assert  M_DUP: UpperBitsNotSet(p->M_DUP, 2);

        //@ assert  M_MCOUNT: EqualBits(stream, pos + 17, pos + 25, p->M_MCOUNT);
        //@ assert  M_MCOUNT: UpperBitsNotSet(p->M_MCOUNT, 8);

        //@ assert  NID_C: EqualBits(stream, pos + 25, pos + 35, p->NID_C);
        //@ assert  NID_C: UpperBitsNotSet(p->NID_C, 10);

        //@ assert  NID_BG: EqualBits(stream, pos + 35, pos + 49, p->NID_BG);
        //@ assert  NID_BG: UpperBitsNotSet(p->NID_BG, 14);

        //@ assert  Q_LINK: EqualBits(stream, pos + 49, pos + 50, p->Q_LINK);
        //@ assert  Q_LINK: UpperBitsNotSet(p->Q_LINK, 1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

static inline void TelegramHeader_Print(FILE* stream, const TelegramHeader* p)
{
    fprintf(stream, "(%llu,%llu,%llu,%llu,%llu,%llu,%llu,%llu,%llu,%llu)",
            p->Q_UPDOWN,
            p->M_VERSION,
            p->Q_MEDIA,
            p->N_PIG,
            p->N_TOTAL,
            p->M_DUP,
            p->M_MCOUNT,
            p->NID_C,
            p->NID_BG,
            p->Q_LINK);
}

static inline int TelegramHeader_Equal(const TelegramHeader* a, const TelegramHeader* b)
{
    int status = 1;

    status = status && (a->Q_UPDOWN    == b->Q_UPDOWN);
    status = status && (a->M_VERSION   == b->M_VERSION);
    status = status && (a->Q_MEDIA     == b->Q_MEDIA);
    status = status && (a->N_PIG       == b->N_PIG);
    status = status && (a->N_TOTAL     == b->N_TOTAL);
    status = status && (a->M_DUP       == b->M_DUP);
    status = status && (a->M_MCOUNT    == b->M_MCOUNT);
    status = status && (a->NID_C       == b->NID_C);
    status = status && (a->NID_BG      == b->NID_BG);
    status = status && (a->Q_LINK      == b->Q_LINK);

    return status;
}

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<< (std::ostream& stream, const TelegramHeader& p)
{
    stream << '('
           << uint64_t(p.Q_UPDOWN) << ','
           << uint64_t(p.M_VERSION) << ','
           << uint64_t(p.Q_MEDIA) << ','
           << uint64_t(p.N_PIG) << ','
           << uint64_t(p.N_TOTAL) << ','
           << uint64_t(p.M_DUP) << ','
           << uint64_t(p.M_MCOUNT) << ','
           << uint64_t(p.NID_C) << ','
           << uint64_t(p.NID_BG) << ','
           << uint64_t(p.Q_LINK) << ')';

    return stream;
}

inline bool operator==(const TelegramHeader& a, const TelegramHeader& b)
{
    return (a.Q_UPDOWN == b.Q_UPDOWN) &&
           (a.M_VERSION == b.M_VERSION) &&
           (a.Q_MEDIA == b.Q_MEDIA) &&
           (a.N_PIG == b.N_PIG) &&
           (a.N_TOTAL == b.N_TOTAL) &&
           (a.M_DUP == b.M_DUP) &&
           (a.M_MCOUNT == b.M_MCOUNT) &&
           (a.NID_C == b.NID_C) &&
           (a.NID_BG == b.NID_BG) &&
           (a.Q_LINK == b.Q_LINK);
}

inline bool operator!=(const TelegramHeader& a, const TelegramHeader& b)
{
    return !(a == b);
}

#endif // __cplusplus

#endif // TELEGRAMHEADER_H_INCLUDED
