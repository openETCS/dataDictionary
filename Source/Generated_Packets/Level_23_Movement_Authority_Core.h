
#ifndef LEVEL_23_MOVEMENT_AUTHORITY_CORE_H_INCLUDED
#define LEVEL_23_MOVEMENT_AUTHORITY_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Level_23_Movement_Authority_Core_1.h"

struct Level_23_Movement_Authority_Core
{
    // TransmissionMedia=RBC
    // Transmission of a movement authority for levels 2/3.   
    // Packet Number = 15

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint8_t   V_LOA;            // # 7
    uint16_t  T_LOA;            // # 10
    uint8_t   N_ITER_1;         // # 5
    Level_23_Movement_Authority_Core_1   sub_1[31];
    uint16_t  L_ENDSECTION;     // # 15
    uint32_t  Q_SECTIONTIMER;   // # 1
    uint16_t  T_SECTIONTIMER;   // # 10
    uint16_t  D_SECTIONTIMERSTOPLOC;// # 15
    uint32_t  Q_ENDTIMER;       // # 1
    uint16_t  T_ENDTIMER;       // # 10
    uint16_t  D_ENDTIMERSTARTLOC;// # 15
    uint32_t  Q_DANGERPOINT;    // # 1
    uint16_t  D_DP;             // # 15
    uint8_t   V_RELEASEDP;      // # 7
    uint32_t  Q_OVERLAP;        // # 1
    uint16_t  D_STARTOL;        // # 15
    uint16_t  T_OL;             // # 10
    uint16_t  D_OL;             // # 15
    uint8_t   V_RELEASEOL;      // # 7
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Level_23_Movement_Authority_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.V_LOA << ','
       << +p.T_LOA << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
    stream << ','
       << +p.L_ENDSECTION << ','
       << +p.Q_SECTIONTIMER << ','
       << +p.T_SECTIONTIMER << ','
       << +p.D_SECTIONTIMERSTOPLOC << ','
       << +p.Q_ENDTIMER << ','
       << +p.T_ENDTIMER << ','
       << +p.D_ENDTIMERSTARTLOC << ','
       << +p.Q_DANGERPOINT << ','
       << +p.D_DP << ','
       << +p.V_RELEASEDP << ','
       << +p.Q_OVERLAP << ','
       << +p.D_STARTOL << ','
       << +p.T_OL << ','
       << +p.D_OL << ','
       << +p.V_RELEASEOL;

    return stream;
}

inline bool operator==(const Level_23_Movement_Authority_Core& a, const Level_23_Movement_Authority_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.V_LOA == b.V_LOA);
    status = status && (a.T_LOA == b.T_LOA);
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
    status = status && (a.L_ENDSECTION == b.L_ENDSECTION);
    status = status && (a.Q_SECTIONTIMER == b.Q_SECTIONTIMER);
    status = status && (a.T_SECTIONTIMER == b.T_SECTIONTIMER);
    status = status && (a.D_SECTIONTIMERSTOPLOC == b.D_SECTIONTIMERSTOPLOC);
    status = status && (a.Q_ENDTIMER == b.Q_ENDTIMER);
    status = status && (a.T_ENDTIMER == b.T_ENDTIMER);
    status = status && (a.D_ENDTIMERSTARTLOC == b.D_ENDTIMERSTARTLOC);
    status = status && (a.Q_DANGERPOINT == b.Q_DANGERPOINT);
    status = status && (a.D_DP == b.D_DP);
    status = status && (a.V_RELEASEDP == b.V_RELEASEDP);
    status = status && (a.Q_OVERLAP == b.Q_OVERLAP);
    status = status && (a.D_STARTOL == b.D_STARTOL);
    status = status && (a.T_OL == b.T_OL);
    status = status && (a.D_OL == b.D_OL);
    status = status && (a.V_RELEASEOL == b.V_RELEASEOL);

    return status;
}

inline bool operator!=(const Level_23_Movement_Authority_Core& a, const Level_23_Movement_Authority_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Level_23_Movement_Authority_Core Level_23_Movement_Authority_Core;

#define LEVEL_23_MOVEMENT_AUTHORITY_CORE_BITSIZE 177

/*@
    logic integer BitSize{L}(Level_23_Movement_Authority_Core* p) = LEVEL_23_MOVEMENT_AUTHORITY_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_23_Movement_Authority_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_23_Movement_Authority_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_23_Movement_Authority_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->V_LOA)             &&
      Invariant(p->T_LOA);

    predicate ZeroInitialized(Level_23_Movement_Authority_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->V_LOA)             &&
      ZeroInitialized(p->T_LOA);

    predicate EqualBits(Bitstream* stream, integer pos, Level_23_Movement_Authority_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 24,  p->V_LOA)             &&
      EqualBits(stream, pos + 24,  pos + 34,  p->T_LOA);

    predicate UpperBitsNotSet(Level_23_Movement_Authority_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->V_LOA,            7)   &&
      UpperBitsNotSet(p->T_LOA,            10);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level_23_Movement_Authority_UpperBitsNotSet(const Level_23_Movement_Authority_Core* p);

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
int Level_23_Movement_Authority_Encoder(Bitstream* stream, const Level_23_Movement_Authority_Core* p);

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
int Level_23_Movement_Authority_Decoder(Bitstream* stream, Level_23_Movement_Authority_Core* p);

#endif // LEVEL_23_MOVEMENT_AUTHORITY_CORE_H_INCLUDED

