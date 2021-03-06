
#ifndef PACKET_ENCODEBIT_H_INCLUDE
#define PACKET_ENCODEBIT_H_INCLUDE

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / Packet_EncodeBit
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

#include "PacketHeader.h"
#include "Bitstream.h"

int Packet_EncodeBit(const PacketHeader* header, Bitstream* stream);

#endif // PACKET_ENCODEBIT_H_INCLUDE

