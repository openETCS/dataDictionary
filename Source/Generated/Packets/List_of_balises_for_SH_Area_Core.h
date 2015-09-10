
#ifndef LIST_OF_BALISES_FOR_SH_AREA_CORE_H_INCLUDED
#define LIST_OF_BALISES_FOR_SH_AREA_CORE_H_INCLUDED

#include "Bitstream.h"
#include "List_of_balises_for_SH_Area_Core_1.h"

struct List_of_balises_for_SH_Area_Core
{
    // TransmissionMedia=Any
    // Used to list balise group(s) which the train can pass over
    // in SH mode
    // Packet Number = 49

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   N_ITER_1;         // # 5
    List_of_balises_for_SH_Area_Core_1   sub_1[31];
};

typedef struct List_of_balises_for_SH_Area_Core List_of_balises_for_SH_Area_Core;

#define LIST_OF_BALISES_FOR_SH_AREA_CORE_BITSIZE 20

/*@
    logic integer BitSize{L}(List_of_balises_for_SH_Area_Core* p) = LIST_OF_BALISES_FOR_SH_AREA_CORE_BITSIZE;

    logic integer MaxBitSize{L}(List_of_balises_for_SH_Area_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, List_of_balises_for_SH_Area_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(List_of_balises_for_SH_Area_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(List_of_balises_for_SH_Area_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, List_of_balises_for_SH_Area_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

    predicate UpperBitsNotSet(List_of_balises_for_SH_Area_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int List_of_balises_for_SH_Area_UpperBitsNotSet(const List_of_balises_for_SH_Area_Core* p);

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
int List_of_balises_for_SH_Area_Encoder(Bitstream* stream, const List_of_balises_for_SH_Area_Core* p);

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
int List_of_balises_for_SH_Area_Decoder(Bitstream* stream, List_of_balises_for_SH_Area_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const List_of_balises_for_SH_Area_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const List_of_balises_for_SH_Area_Core& a, const List_of_balises_for_SH_Area_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
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

inline bool operator!=(const List_of_balises_for_SH_Area_Core& a, const List_of_balises_for_SH_Area_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const List_of_balises_for_SH_Area_Core& p)
{
    return List_of_balises_for_SH_Area_Encoder(&stream, &p);
}

#endif // __cplusplus

#endif // LIST_OF_BALISES_FOR_SH_AREA_CORE_H_INCLUDED

