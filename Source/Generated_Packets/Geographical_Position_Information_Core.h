
#ifndef GEOGRAPHICAL_POSITION_INFORMATION_CORE_H_INCLUDED
#define GEOGRAPHICAL_POSITION_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Geographical_Position_Information_Core_1.h"

struct Geographical_Position_Information_Core
{
    // TransmissionMedia=Balise, RBC
    // This packet gives geographical location information for one or multiple references
    // to the train.        
    // Packet Number = 79

    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
    uint64_t  D_POSOFF;         // # 15
    uint64_t  Q_MPOSITION;      // # 1
    uint64_t  M_POSITION;       // # 24
    uint64_t   N_ITER_1;         // # 5
    Geographical_Position_Information_Core_1   sub_1[31];
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Geographical_Position_Information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.Q_NEWCOUNTRY << ','
       << +p.NID_C << ','
       << +p.NID_BG << ','
       << +p.D_POSOFF << ','
       << +p.Q_MPOSITION << ','
       << +p.M_POSITION << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Geographical_Position_Information_Core& a, const Geographical_Position_Information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.Q_NEWCOUNTRY == b.Q_NEWCOUNTRY);
    if (a.Q_NEWCOUNTRY == 1)
    {
    status = status && (a.NID_C == b.NID_C);
    }
    status = status && (a.NID_BG == b.NID_BG);
    status = status && (a.D_POSOFF == b.D_POSOFF);
    status = status && (a.Q_MPOSITION == b.Q_MPOSITION);
    status = status && (a.M_POSITION == b.M_POSITION);
    status = status && (a.N_ITER_1 == b.N_ITER_1);
    if (a.N_ITER_1 == b.N_ITER_1)
    {
        for (uint32_t i = 0; i < a.N_ITER_1; ++i)
        {
            status = status && (a.sub_1[i] == b.sub_1[i]);
        }
    }
    else
    {
        status = false;
    }

    return status;
}

inline bool operator!=(const Geographical_Position_Information_Core& a, const Geographical_Position_Information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Geographical_Position_Information_Core Geographical_Position_Information_Core;

#define GEOGRAPHICAL_POSITION_INFORMATION_CORE_BITSIZE 77

/*@
    logic integer BitSize{L}(Geographical_Position_Information_Core* p) = GEOGRAPHICAL_POSITION_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Geographical_Position_Information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Geographical_Position_Information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Geographical_Position_Information_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(Geographical_Position_Information_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, Geographical_Position_Information_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 18,  p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(Geographical_Position_Information_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Geographical_Position_Information_UpperBitsNotSet(const Geographical_Position_Information_Core* p);

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
int Geographical_Position_Information_Encoder(Bitstream* stream, const Geographical_Position_Information_Core* p);

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
int Geographical_Position_Information_Decoder(Bitstream* stream, Geographical_Position_Information_Core* p);

#endif // GEOGRAPHICAL_POSITION_INFORMATION_CORE_H_INCLUDED

