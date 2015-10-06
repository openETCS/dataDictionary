#include <stdint.h>
#include "subset026_7.h"
#include "Bitstream.h"
#include "opnETCS_DecoderBranch.h"

// This function returns a value, that indicates, whether or not the 
// packet was read correctly
// return == 3 -> the header was read correctly but the NID_PACKET value does not match any packet number
// return == 2 -> The header was not read correctly (Because of !NormalBitstream(stream, 8))
// return == 1 -> The header and the data packet have were read correctly
// return == 0 -> The header was read correctly but the data packet not (Because of !NormalBitstream(stream, ...))
int TrackToTrain_PackageDecoder(Bitstream* stream, oETCS_Union *oETCS)
{
    int ret = 1;

    Header union_Header;
    // Read the header from the stream
    // ret is 1 if the header was read correctly, 0 if not
    ret = TrackToTrain_Decoder(stream, &union_Header);

    // If the header was not read correctly, there is no nead to try to read a data packet
    if (ret == 0) {
	return 2; // Header was not read correctly
    }
    
    switch(union_Header->NID->PACKET)
    {
       case 71 :
       {
	    Adhesion_Factor union_Data;
	    // Read the data packet from the stream
	    // ret is 1 if the data packed was read correctly, 0 if not
	    ret = Adhesion_Factor_Decoder(stream, &union_Data);
       }    
       default :
       {
	    // The NID_PACKET value read doe not match any packet number
	    // and the decoder does not know which function to call.
	    ret = 3
       }
    };
    return ret;
}

// Similar to TrackToTrain_PackageDecoder but other cases
int TrainToTrack_PackageDecoder(void* Stream, int FirstBitPos,  oETCS_Union *oETCS )
{

}

// Similar to TrackToTrain_PackageDecoder but only one case (255) + default case
int BothWays_PackageDecoder(void* Stream, int FirstBitPos,  oETCS_Union *oETCS )
{

}

