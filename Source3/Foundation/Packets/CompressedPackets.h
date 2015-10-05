#ifndef COMPRESSEDPACKETS_H_INCLUDED
#define COMPRESSEDPACKETS_H_INCLUDED

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

typedef MetadataElement_T_Common_Types_Pkg PacketInfo;

// packet sequence struct
typedef struct
{
    PacketInfo PacketHeaders[30];
    kcg_int  PacketData[500];
} CompressedPackets_T_Common_Types_Pkg;

typedef CompressedPackets_T_Common_Types_Pkg FlatPackets;


inline static
void FlatPacket_Write(PacketInfo* info, kcg_int* data, kcg_int v)
{
    ++info->endAddress;
    data[info->endAddress] = v;
}
 

#endif // COMPRESSEDPACKETS_H_INCLUDED

