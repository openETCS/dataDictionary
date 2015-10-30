
This directory contains the packet data structures together
with their respective functions 
	- to decode data from a bitstream
	- and encode data into a bitstream.

There are also functions to convert an eurobalise telegram into the format
required by the SCADE model.
(These functions are not tested because we have no access to the SCADE model.)

The data structure for eurobalise telegram is contained in the directory Tests.

The basic bitstream function are in the directory Foundation/Bits.

All code is written in C99.
The code can be compiled with 'make'.
The default target of Makefile also executes a few tests in directory Tests.

IMPORTANT:

In order to compile for the SCADE model the preprocessor flag '-DHAVE_KCG_HEADER' must be used.




