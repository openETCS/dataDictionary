#include <stdio.h>
#include "Bitwalker.h"
#include "opnETCS_Decoder.h"
#include "System_Version_order.h"
#include "opnETCS_DecoderBranch.h"

int main(void)
{
	uint8_t Teststream[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
							0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
						   };

	int size = sizeof(Teststream);

	uint64_t Testwort       = 0;
	uint64_t TestwortRetval = 0;

	T_Bitwalker_Incremental_Locals PokeLocals;

	Bitwalker_IncrementalWalker_Init(&PokeLocals, Teststream, size, 0);

    // create bitstream of telegram "System Version order"

    uint32_t Bitlength   = 30; //  net bitlength of telegram "System Version order" without header
    uint32_t Bytelength  = Bitlength / 8 + 1;
    uint32_t FirstBitPos = 0;
    uint32_t ArrayIndex  = 0;

    // <Packet Number="2" Name="System Version order" TransmissionMedia="Balise" ><TlgVar Name="NID_PACKET" Length="8"  />
    Bitwalker_IncrementalWalker_Poke_Next(&PokeLocals, 8, 2);
    // <TlgVar Name="Q_DIR" Length="2"  /> <Special Value="01"  Description="Nominal" />
    Bitwalker_IncrementalWalker_Poke_Next(&PokeLocals, 2, 1);
    // Telegrammlänge in Bit ( normalerweise incl. Header; Den haben wir aber noch nicht)
    Bitwalker_IncrementalWalker_Poke_Next(&PokeLocals, 13, Bitlength);
    // <Special Value="010 0000"  Description="Version 2_0 introduced in SRS 3_3_0" />
    Bitwalker_IncrementalWalker_Poke_Next(&PokeLocals, 7, 32);

//    T_DATA_oETCS_TrackToTrain_System_Version_order oETCS;

    oETCS_Union  oETCS;

     // TrackToTrain_Packet_002(&Teststream, FirstBitPos, Bytelength, ArrayIndex,  &oETCS);

    TrackToTrain_PackageDecoder(&Teststream, FirstBitPos,  &oETCS);


    switch (oETCS.NameSpace)
    {
        case E_DATA_oETCS_BothWays:
        {
            // here we are in BothWays
            // Access via oETCS->BothWP_<PackageNumber>.aPacket[ArrayIndex].<VarName>

        }
        break;
        case E_DATA_oETCS_TrainToTrack:
        {
            // here we are in TrainToTrack
            // Access via oETCS->TrainP_<PackageNumber>.aPacket[ArrayIndex].<VarName>

        }
        break;
        case E_DATA_oETCS_TrackToTrain:
        {
            // here we are in Track
            // Access via oETCS->TrackP_<PackageNumber>.aPacket[ArrayIndex].<VarName>

            if ( oETCS.TlgTrackToTrain == E_DATA_oETCS_TrackToTrain_System_Version_order )
            {
                Testwort = oETCS.TrackP_002.aPacket[ArrayIndex].NID_PACKET;  // shall be  2
                Testwort = oETCS.TrackP_002.aPacket[ArrayIndex].Q_DIR;       // shall be  1
                Testwort = oETCS.TrackP_002.aPacket[ArrayIndex].L_PACKET;    // shall be 30
                Testwort = oETCS.TrackP_002.aPacket[ArrayIndex].M_VERSION;   // shall be 32
            }
        }
        break;

        default:

        break;
    }

    exit(0);
}

