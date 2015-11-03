
This directory contains the packet data structures together
with their respective functions 
	- to en/decode data into/from a bitstream
	- to en/decode data into/from a integer stream 

The integer stream functions connect to the SCADE model and
have not been tested because we have no access to the SCADE model.

IMPORTANT:
	In order to compile for the SCADE model the preprocessor flag '-DHAVE_KCG_HEADER' must be used.

The directory structure is as follows

├── Foundation
│   ├── Bits
│   └── Packets
├── Generated
│   ├── PacketsWithNITER
│   └── PacketsWithoutNITER
├── Scripts
├── Telegram
└── Tests


The data structures for Eurobalise telegram are contained in the directory Telegram.

The basic bitstream function are in the directory Foundation/Bits.

All code is written in C99.
The code can be compiled with 'make'.
The default target of Makefile also executes a few tests in directory Tests.


