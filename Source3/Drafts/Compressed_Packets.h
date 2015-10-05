#ifndef COMPRESSED_PACKETS_H_INCLUDED
#define COMPRESSED_PACKETS_H_INCLUDED

#ifndef kcg_int
#define kcg_int kcg_int
typedef int kcg_int;
#endif /* kcg_int */

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif /* kcg_bool */

typedef kcg_int array_int_500[500];

/* Common_Types_Pkg::CompressedPacketData_T */
typedef array_int_500 CompressedPacketData_T_Common_Types_Pkg;

typedef struct {
  kcg_int nid_packet;
  Q_DIR q_dir;
  kcg_bool valid;
  kcg_int startAddress;
  kcg_int endAddress;
} struct__80388;

/* Common_Types_Pkg::MetadataElement_T */
typedef struct__80388 MetadataElement_T_Common_Types_Pkg;

typedef struct__80388 array__80396[30];

/* Common_Types_Pkg::Metadata_T */
typedef array__80396 Metadata_T_Common_Types_Pkg;

typedef struct {
  array__80396 PacketHeaders;
  array_int_500 PacketData;
} struct__80399;

/* Common_Types_Pkg::CompressedPackets_T */
typedef struct__80399 CompressedPackets_T_Common_Types_Pkg;

#endif // COMPRESSED_PACKETS_H_INCLUDED

