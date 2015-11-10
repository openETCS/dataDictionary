#ifndef COMPRESSEDPACKETS_H_INCLUDED
#define COMPRESSEDPACKETS_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / CompressedPackets
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

#ifdef HAVE_KCG_HEADER

#include "kcg_types.h"

#else

#ifndef kcg_int
#define kcg_int kcg_int
typedef int kcg_int;
#endif // kcg_int

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif // kcg_bool

// Q_DIR
/* typedef enum {
  Q_DIR_Reverse = 0,
  Q_DIR_Nominal = 1,
  Q_DIR_Both_directions = 2,
} Q_DIR; */
typedef kcg_int Q_DIR;

// packet info struct
typedef struct
{
    kcg_int nid_packet;
    Q_DIR q_dir;
    kcg_bool valid;
    kcg_int startAddress;
    kcg_int endAddress;
} MetadataElement_T_Common_Types_Pkg;


// packet sequence struct
typedef struct
{
    MetadataElement_T_Common_Types_Pkg PacketHeaders[30];
    kcg_int  PacketData[500];
} CompressedPackets_T_Common_Types_Pkg;

#endif // HAVE_KCG_HEADER

typedef MetadataElement_T_Common_Types_Pkg Metadata;

typedef CompressedPackets_T_Common_Types_Pkg CompressedPackets;


/*inline static
void FlatPacket_Write(PacketInfo* info, kcg_int* data, kcg_int v)
{
    ++info->endAddress;
    data[info->endAddress] = v;
}
*/
 

#endif // COMPRESSEDPACKETS_H_INCLUDED

