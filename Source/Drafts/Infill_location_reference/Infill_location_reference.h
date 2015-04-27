
#ifndef INFILL_LOCATION_REFERENCE_H_INCLUDED
#define INFILL_LOCATION_REFERENCE_H_INCLUDED

#include "Bitstream.h"

struct Infill_location_reference
{
    // TransmissionMedia=Balise, Loop, RIU
    // Defines location reference for all data contained in the same radio
    // message or balise/loop telegram respectively, following this packet.   
    // Packet Number = 136

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_NEWCOUNTRY;     // # 1
    uint16_t  NID_C;            // # 10
    uint16_t  NID_BG;           // # 14
};

typedef struct Infill_location_reference Infill_location_reference;

#define INFILL_LOCATION_REFERENCE_BITSIZE 40

/*@
    logic integer BitSize{L}(Infill_location_reference* p) = INFILL_LOCATION_REFERENCE_BITSIZE;

    logic integer MaxBitSize{L}(Infill_location_reference* p) = BitSize(p);

    logic integer Q_DIR_B{L}(Infill_location_reference* p) = 0;
    logic integer Q_DIR_E{L}(Infill_location_reference* p) =
    	Q_DIR_B{L}(p) + 2;

    logic integer L_PACKET_B{L}(Infill_location_reference* p) =
        Q_DIR_E{L}(p);
    logic integer L_PACKET_E{L}(Infill_location_reference* p) =
        L_PACKET_B{L}(p) + 13;

    logic integer Q_NEWCOUNTRY_B{L}(Infill_location_reference* p) =
        L_PACKET_E{L}(p);
    logic integer Q_NEWCOUNTRY_E{L}(Infill_location_reference* p) =
        Q_NEWCOUNTRY_B{L}(p) + 1;

    logic integer NID_C_B{L}(Infill_location_reference* p) =
        Q_NEWCOUNTRY_E{L}(p);
    axiomatic NID_C_E_Axiomatic
    {
        logic integer NID_C_E{L}(Infill_location_reference* p)
	    reads p->Q_NEWCOUNTRY;
	
	axiom NID_C_E_read{L}: \forall Infill_location_reference* p;
	    p->Q_NEWCOUNTRY == 1 ==> NID_C_E{L}(p) == NID_C_B{L}(p) + 10;

	axiom NID_C_E_skip{L}: \forall Infill_location_reference* p;
	    p->Q_NEWCOUNTRY != 1 ==> NID_C_E{L}(p) == NID_C_B{L}(p);
    }

    logic integer NID_BG_B{L}(Infill_location_reference* p) =
        NID_C_E{L}(p);
    logic integer NID_BG_E{L}(Infill_location_reference* p) =
        NID_BG_B{L}(p) + 14;

    predicate Separated(Bitstream* stream, Infill_location_reference* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Infill_location_reference* p) = Invariant(p->Q_DIR)             && Invariant(p->L_PACKET)          && Invariant(p->Q_NEWCOUNTRY); predicate ZeroInitialized(Infill_location_reference* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_NEWCOUNTRY)      &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_BG);

    predicate EqualBits{L}(Bitstream* stream, integer pos, Infill_location_reference* p) =
      EqualBits(stream, pos + Q_DIR_B{L}(p), pos + Q_DIR_E{L}(p), p->Q_DIR) &&
      EqualBits(stream, pos + L_PACKET_B{L}(p), pos + L_PACKET_E{L}(p), p->L_PACKET) &&
      EqualBits(stream, pos + Q_NEWCOUNTRY_B{L}(p), pos + Q_NEWCOUNTRY_E{L}(p), p->Q_NEWCOUNTRY) &&
      EqualBits(stream, pos + NID_C_B{L}(p), pos + NID_C_E{L}(p), p->NID_C) &&
      EqualBits(stream, pos + NID_BG_B{L}(p), pos + NID_BG_E{L}(p), p->NID_BG);


    predicate UpperBitsNotSet(Infill_location_reference* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1)   &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_BG,           14);

*/

#endif // INFILL_LOCATION_REFERENCE_H_INCLUDED

