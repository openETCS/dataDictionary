
#ifndef POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_CORE_H_INCLUDED
#define POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Position_Report_based_on_two_balise_groups_Core
{
    // TransmissionMedia=RBC, RIU
    // This packet is an extension of the 'standard position report '
    // packet 0. It is used in case of single balise groups
    // if the orientation of the LRBG is unknown but the on-board
    // equipment is able to report a second balise group (the one
    // detected before) to give a direction reference for the directional information
    // in the position report.       
    // Packet Number = 1

    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  NID_LRBG;         // # 24
    uint32_t  NID_PRVLRBG;      // # 24
    uint16_t  D_LRBG;           // # 15
    uint32_t  Q_DIRLRBG;        // # 2
    uint32_t  Q_DLRBG;          // # 2
    uint16_t  L_DOUBTOVER;      // # 15
    uint16_t  L_DOUBTUNDER;     // # 15
    uint32_t  Q_LENGTH;         // # 2
    uint16_t  L_TRAININT;       // # 15
    uint8_t   V_TRAIN;          // # 7
    uint32_t  Q_DIRTRAIN;       // # 2
    uint32_t  M_MODE;           // # 4
    uint32_t  M_LEVEL;          // # 3
    uint8_t   NID_NTC;          // # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Position_Report_based_on_two_balise_groups_Core& p)
{
    stream 
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.NID_LRBG << ','
       << +p.NID_PRVLRBG << ','
       << +p.D_LRBG << ','
       << +p.Q_DIRLRBG << ','
       << +p.Q_DLRBG << ','
       << +p.L_DOUBTOVER << ','
       << +p.L_DOUBTUNDER << ','
       << +p.Q_LENGTH << ','
       << +p.L_TRAININT << ','
       << +p.V_TRAIN << ','
       << +p.Q_DIRTRAIN << ','
       << +p.M_MODE << ','
       << +p.M_LEVEL << ','
       << +p.NID_NTC;

    return stream;
}

inline bool operator==(const Position_Report_based_on_two_balise_groups_Core& a, const Position_Report_based_on_two_balise_groups_Core& b)
{
    bool status = true;
    
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.NID_LRBG == b.NID_LRBG);
    status = status && (a.NID_PRVLRBG == b.NID_PRVLRBG);
    status = status && (a.D_LRBG == b.D_LRBG);
    status = status && (a.Q_DIRLRBG == b.Q_DIRLRBG);
    status = status && (a.Q_DLRBG == b.Q_DLRBG);
    status = status && (a.L_DOUBTOVER == b.L_DOUBTOVER);
    status = status && (a.L_DOUBTUNDER == b.L_DOUBTUNDER);
    status = status && (a.Q_LENGTH == b.Q_LENGTH);
    if ((a.Q_LENGTH == 1) || (a.Q_LENGTH == 2))
    {
    status = status && (a.L_TRAININT == b.L_TRAININT);
    }
    status = status && (a.V_TRAIN == b.V_TRAIN);
    status = status && (a.Q_DIRTRAIN == b.Q_DIRTRAIN);
    status = status && (a.M_MODE == b.M_MODE);
    status = status && (a.M_LEVEL == b.M_LEVEL);
    if (a.M_LEVEL == 1)
    {
    status = status && (a.NID_NTC == b.NID_NTC);
    }

    return status;
}

inline bool operator!=(const Position_Report_based_on_two_balise_groups_Core& a, const Position_Report_based_on_two_balise_groups_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Position_Report_based_on_two_balise_groups_Core Position_Report_based_on_two_balise_groups_Core;

#define POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_CORE_BITSIZE 153

/*@
    logic integer BitSize{L}(Position_Report_based_on_two_balise_groups_Core* p) = POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Position_Report_based_on_two_balise_groups_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Position_Report_based_on_two_balise_groups_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Position_Report_based_on_two_balise_groups_Core* p) = \true;

    predicate ZeroInitialized(Position_Report_based_on_two_balise_groups_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Position_Report_based_on_two_balise_groups_Core* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 15,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 15,  pos + 39,  p->NID_LRBG)          &&
      EqualBits(stream, pos + 39,  pos + 63,  p->NID_PRVLRBG)       &&
      EqualBits(stream, pos + 63,  pos + 78,  p->D_LRBG)            &&
      EqualBits(stream, pos + 78,  pos + 80,  p->Q_DIRLRBG)         &&
      EqualBits(stream, pos + 80,  pos + 82,  p->Q_DLRBG)           &&
      EqualBits(stream, pos + 82,  pos + 97,  p->L_DOUBTOVER)       &&
      EqualBits(stream, pos + 97,  pos + 112, p->L_DOUBTUNDER)      &&
      EqualBits(stream, pos + 112, pos + 114, p->Q_LENGTH)          &&
      EqualBits(stream, pos + 129, pos + 136, p->V_TRAIN)           &&
      EqualBits(stream, pos + 136, pos + 138, p->Q_DIRTRAIN)        &&
      EqualBits(stream, pos + 138, pos + 142, p->M_MODE)            &&
      EqualBits(stream, pos + 142, pos + 145, p->M_LEVEL);

    predicate UpperBitsNotSet(Position_Report_based_on_two_balise_groups_Core* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->NID_LRBG,         24)  &&
      UpperBitsNotSet(p->NID_PRVLRBG,      24)  &&
      UpperBitsNotSet(p->D_LRBG,           15)  &&
      UpperBitsNotSet(p->Q_DIRLRBG,        2)   &&
      UpperBitsNotSet(p->Q_DLRBG,          2)   &&
      UpperBitsNotSet(p->L_DOUBTOVER,      15)  &&
      UpperBitsNotSet(p->L_DOUBTUNDER,     15)  &&
      UpperBitsNotSet(p->Q_LENGTH,         2)   &&
      UpperBitsNotSet(p->V_TRAIN,          7)   &&
      UpperBitsNotSet(p->Q_DIRTRAIN,       2)   &&
      UpperBitsNotSet(p->M_MODE,           4)   &&
      UpperBitsNotSet(p->M_LEVEL,          3);

*/

#endif // POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_CORE_H_INCLUDED

