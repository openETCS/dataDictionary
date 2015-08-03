
#ifndef POSITION_REPORT_PARAMETERS_CORE_H_INCLUDED
#define POSITION_REPORT_PARAMETERS_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Position_Report_Parameters_Core_1.h"

struct Position_Report_Parameters_Core
{
    // TransmissionMedia=RBC
    // This packet is intended to give parameters telling when and how
    // often the position has to be reported.    
    // Packet Number = 58

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint8_t   T_CYCLOC;         // # 8
    uint16_t  D_CYCLOC;         // # 15
    uint32_t  M_LOC;            // # 3
    uint8_t   N_ITER_1;         // # 5
    Position_Report_Parameters_Core_1   sub_1[31];
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Position_Report_Parameters_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.T_CYCLOC << ','
       << +p.D_CYCLOC << ','
       << +p.M_LOC << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Position_Report_Parameters_Core& a, const Position_Report_Parameters_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.T_CYCLOC == b.T_CYCLOC);
    status = status && (a.D_CYCLOC == b.D_CYCLOC);
    status = status && (a.M_LOC == b.M_LOC);
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

inline bool operator!=(const Position_Report_Parameters_Core& a, const Position_Report_Parameters_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Position_Report_Parameters_Core Position_Report_Parameters_Core;

#define POSITION_REPORT_PARAMETERS_CORE_BITSIZE 48

/*@
    logic integer BitSize{L}(Position_Report_Parameters_Core* p) = POSITION_REPORT_PARAMETERS_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Position_Report_Parameters_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Position_Report_Parameters_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Position_Report_Parameters_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->T_CYCLOC)          &&
      Invariant(p->D_CYCLOC)          &&
      Invariant(p->M_LOC);

    predicate ZeroInitialized(Position_Report_Parameters_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->T_CYCLOC)          &&
      ZeroInitialized(p->D_CYCLOC)          &&
      ZeroInitialized(p->M_LOC);

    predicate EqualBits(Bitstream* stream, integer pos, Position_Report_Parameters_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 25,  p->T_CYCLOC)          &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_CYCLOC)          &&
      EqualBits(stream, pos + 40,  pos + 43,  p->M_LOC);

    predicate UpperBitsNotSet(Position_Report_Parameters_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->T_CYCLOC,         8)   &&
      UpperBitsNotSet(p->D_CYCLOC,         15)  &&
      UpperBitsNotSet(p->M_LOC,            3);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Position_Report_Parameters_UpperBitsNotSet(const Position_Report_Parameters_Core* p);

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
int Position_Report_Parameters_Encoder(Bitstream* stream, const Position_Report_Parameters_Core* p);

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
int Position_Report_Parameters_Decoder(Bitstream* stream, Position_Report_Parameters_Core* p);

#endif // POSITION_REPORT_PARAMETERS_CORE_H_INCLUDED

