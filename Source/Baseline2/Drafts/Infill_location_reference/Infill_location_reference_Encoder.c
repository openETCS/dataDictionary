
#include "Infill_location_reference_Encoder.h"
#include "Infill_location_reference_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Infill_location_reference_Encoder(Bitstream* stream, const Infill_location_reference* p)
{
    if (NormalBitstream(stream, INFILL_LOCATION_REFERENCE_BITSIZE))
    {
        if (Infill_location_reference_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            /*@
	       requires Q_DIR: stream->bitpos == pos + Q_DIR_B(p);
	       assigns         stream;
               ensures  Q_DIR: EqualBits(stream, pos + Q_DIR_B(p), pos + Q_DIR_E(p), p->Q_DIR);
	       ensures  Q_DIR: stream->bitpos == pos + Q_DIR_E(p);   
	    */
            { Bitstream_Write(stream, 2,  p->Q_DIR); }

            /*@
	       requires L_PACKET: stream->bitpos == pos + L_PACKET_B(p);
	       assigns            stream;
               ensures  L_PACKET: EqualBits(stream, pos + L_PACKET_B(p), pos + L_PACKET_E(p), p->L_PACKET);
	       ensures  L_PACKET: stream->bitpos == pos + L_PACKET_E(p);
	    */
            { Bitstream_Write(stream, 13, p->L_PACKET); }
	    
            /*@
	       requires Q_NEWCOUNTRY: stream->bitpos == pos + Q_NEWCOUNTRY_B(p);
	       assigns                stream;
               ensures  Q_NEWCOUNTRY: EqualBits(stream, pos + Q_NEWCOUNTRY_B(p), pos + Q_NEWCOUNTRY_E(p), p->Q_NEWCOUNTRY);
	       ensures  Q_NEWCOUNTRY: stream->bitpos == pos + Q_NEWCOUNTRY_E(p);
	    */
            { Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY); }

	    /*@
               requires NID_C: stream->bitpos == pos + NID_C_B(p);
	    */
	    if (p->Q_NEWCOUNTRY == 1)
	    {
                Bitstream_Write(stream, 10, p->NID_C);
	    }

            /*@
	       requires NID_BG: stream->bitpos == pos + NID_BG_B(p);
	       assigns          stream;
               ensures  NID_BG: EqualBits(stream, pos + NID_BG_B(p), pos + NID_BG_E(p), p->NID_BG);
	       ensures  NID_BG: stream->bitpos == pos + NID_BG_E(p);
	    */
            { Bitstream_Write(stream, 14, p->NID_BG); }


            //@ assert Q_DIR:        EqualBits(stream, pos + Q_DIR_B(p), pos + Q_DIR_E(p), p->Q_DIR);
            //@ assert L_PACKET:     EqualBits(stream, pos + L_PACKET_B(p), pos + L_PACKET_E(p), p->L_PACKET);
            //@ assert Q_NEWCOUNTRY: EqualBits(stream, pos + Q_NEWCOUNTRY_B(p), pos + Q_NEWCOUNTRY_E(p), p->Q_NEWCOUNTRY);
	    //@ assert NID_C:        EqualBits(stream, pos + NID_C_B(p), pos + NID_C_E(p), p->NID_C);
	    //@ assert NID_BG:       EqualBits(stream, pos + NID_BG_B(p), pos + NID_BG_E(p), p->NID_BG);

            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

