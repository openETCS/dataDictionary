#include <stdio.h>
#include "Bitwalker.h"
#include "opnETCS_Variables.h"
#include "Radio_Decoder.h"
#include "Radio_DecoderBranch8.h"
#include "subset026_8.h"

/*
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-8 / Bitwalker8 / main.c
- Description: UNISIG SUBSET-026-8, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright Siemens AG, 2014
- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): SiemensRailAutomation

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE. 
*/

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

	uint64_t Testwort = 0;
	uint64_t TestwortRetval = 0;

	T_Bitwalker_Incremental_Locals PeekLocals;
	T_Bitwalker_Incremental_Locals PokeLocals;

	Bitwalker_IncrementalWalker_Init(&PeekLocals, Teststream, size, 0);
	Bitwalker_IncrementalWalker_Init(&PokeLocals, Teststream, size, 0);

    // create bitstream of telegram
    // <Packet Number="129" Name="Validated Train Data" TransmissionMedia="RBC" >

    uint32_t Bitlength   = 80; //  net bitlength of telegram "Validated Train Data"
    uint32_t Bytelength  = Bitlength / 8 + 1;
    uint32_t FirstBitPos = 0;


// preset bitstram to simulate a new received message

    // <TlgVar Name="NID_MESSAGE" Length="8" Type="int" />   
    Bitwalker_IncrementalWalker_Poke_Next(&PeekLocals, 8, 129);

    // <TlgVar Name="L_MESSAGE" Length="10" Type="int" />
    Bitwalker_IncrementalWalker_Poke_Next(&PeekLocals, 10, Bitlength );

    // <TlgVar Name="T_TRAIN" Length="32" Type="real" />
    Bitwalker_IncrementalWalker_Poke_Next(&PeekLocals, 32, 456789 );

    // <TlgVar Name="NID_ENGINE" Length="24" Type="int" />
    Bitwalker_IncrementalWalker_Poke_Next(&PeekLocals, 24, 1735);

    // <TlgVar Name="PADDING0" Length="6" Type="int" Comment="address byte boundary" />
    Bitwalker_IncrementalWalker_Poke_Next(&PeekLocals, 6, 0);

// normal operation as follows
    uint32_t ArrayIndex  = 0;

    uint32_t MessageID  = (uint32_t) Bitwalker_Peek (0, 8,  Teststream, 18) ;
    Bitlength  = (uint32_t) Bitwalker_Peek (8, 10, Teststream, 18) ;
    Bytelength = Bitlength / 8 + 1;


    switch (MessageID) {
    case 129: {
        T_DATA_Radio_TrainToTrack_Validated_Train_Data Radio;
        TrainToTrack_Message_129 (&Teststream, FirstBitPos, Bytelength, ArrayIndex, &Radio);
        Testwort = Radio.Message[ArrayIndex].NID_MESSAGE;  // shall be    129
        Testwort = Radio.Message[ArrayIndex].L_MESSAGE;    // shall be     80
        Testwort = Radio.Message[ArrayIndex].T_TRAIN;      // shall be 456789
        Testwort = Radio.Message[ArrayIndex].NID_ENGINE;   // shall be   1735
        Testwort = Radio.Message[ArrayIndex].PADDING0;     // shall be      0
        break;
    }
    case 130: {
        T_DATA_Radio_TrainToTrack_Request_for_Shunting Radio;
        TrainToTrack_Message_130 (&Teststream, FirstBitPos, Bytelength, ArrayIndex, &Radio);
        Testwort = Radio.Message[ArrayIndex].NID_MESSAGE;  // shall be    130
        break;
    }
    default:
// Error Message to indicate that a value is present,
// but no function is available to use it
        break;
    }






    return Testwort;
}

