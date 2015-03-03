#include <stdint.h>
#include "subset026_7.h"
#include "Bitstream.h"
#include "opnETCS_DecoderBranch.h"

// Use the return value of Adhesion_Factor_Data_Decoder();
int TrackToTrain_PackageDecoder(Bitstream* stream, oETCS_Union *oETCS)
{
    TrackToTrain_Header union_Header;
    // This call has a return value
    TrackToTrain_Decoder(stream, &union_Header);

    int ret = 0;
    
    // Previous to a potential data packet read it has to be checked
    // whether the decoding of the header was correct. (via the return value)
    switch(union_Header->NID->PACKET)
    {
       case 71 :
       {
	    Adhesion_Factor_Data union_Data;
	    // The return value can be used for the decoder branch as well
	    Adhesion_Factor_Data_Decoder(stream, &union_Data);
	    // Write the header and the data packet into the oETCS_Union oETCS
	    // Set the enums Namespace ...
	    ret =  // CODE FOR CORRECT READ (maybe the value of the decoder return
       }    
       default :
       {
            // The header was read correctly, but the packet, matching the header, does not exists.
	    // However we received the information, how big this packet should have been.
	    // So the readposition of the stream can be updated to the current position +
	    // the position transmitted via the bitstream - the bits used for reading the header.
	    // (while reading the header the bitposition is updated automatically)
            stream->bitpos = stream->bitpos + union_Header->L_PACKET - BitSize(&union_Header);;
	    // Return value that has not benn used for the decoders yet
	    ret =  // ERRORCODE
       }
    };

    if (ret == 0) {
       // Do the L_PACKET test here and return the errorcode for
       // wrong L_PACKET values or return 0
       return ret;
    } else {
       // There has been an even more critical error than a wrong L_PACKET value
       // return the critical errorcode
       return ret;
    }
};

int TrainToTrack_PackageDecoder(void* Stream, int FirstBitPos,  oETCS_Union *oETCS )
{
    TrainToTrack_Header union_Header;
    // This call has a return value
    TrainToTrack_Header_Decoder(stream, &union_Header);

    int ret = 0;
    
    // Previous to a potential data packet read it has to be checked
    // whether the decoding of the header was correct. (via the return value)
    switch(union_Header->NID->PACKET)
    {
       case 0 :
       {
	    Position_Report_Data union_Data;
	    // The return value can be used for the decoder branch as well
	    Position_Report_Data_Decoder(stream, &union_Data);
	    // Write the header and the data packet into the oETCS_Union oETCS
	    // Set the enums Namespace ...
	    ret =  // CODE FOR CORRECT READ (maybe the value of the decoder return
       }    
       default :
       {
            // The header was read correctly, but the packet, matching the header, does not exists.
	    // However we received the information, how big this packet should have been.
	    // So the readposition of the stream can be updated to the current position +
	    // the position transmitted via the bitstream - the bits used for reading the header.
	    // (while reading the header the bitposition is updated automatically)
            stream->bitpos = stream->bitpos + union_Header->L_PACKET - BitSize(&union_Header);;
	    // Return value that has not benn used for the decoders yet
	    ret =  // ERRORCODE
       }
    };

    if (ret == 0) {
       // Do the L_PACKET test here and return the errorcode for
       // wrong L_PACKET values or return 0
       return ret;
    } else {
       // There has been an even more critical error than a wrong L_PACKET value
       // return the critical errorcode
       return ret;
    }
};

int BothWays_PackageDecoder(void* Stream, int FirstBitPos,  oETCS_Union *oETCS )
{
    BothWays_Header union_Header;
    // This call has a return value
    BothWays_Header_Decoder(stream, &union_Header);

    int ret = 0;
    
    // Previous to a potential data packet read it has to be checked
    // whether the decoding of the header was correct. (via the return value)
    switch(union_Header->NID->PACKET)
    {
       case 255 :
       {
            End_of_Information_Data union_Data;
	    // The return value can be used for the decoder branch as well
	    End_of_Information_Data_Decoder(stream, &union_Data);
	    // Write the header and the data packet into the oETCS_Union oETCS
	    // Set the enums Namespace ...
	    ret =  // CODE FOR CORRECT READ (maybe the value of the decoder return
       }    
       default :
       {
            // The header was read correctly, but the packet, matching the header, does not exists.
	    // However we received the information, how big this packet should have been.
	    // So the readposition of the stream can be updated to the current position +
	    // the position transmitted via the bitstream - the bits used for reading the header.
	    // (while reading the header the bitposition is updated automatically)
            stream->bitpos = stream->bitpos + union_Header->L_PACKET - BitSize(&union_Header);;
	    // Return value that has not benn used for the decoders yet
	    ret =  // ERRORCODE
       }
    };

    if (ret == 0) {
       // Do the L_PACKET test here and return the errorcode for
       // wrong L_PACKET values or return 0
       return ret;
    } else {
       // There has been an even more critical error than a wrong L_PACKET value
       // return the critical errorcode
       return ret;
    }
};

