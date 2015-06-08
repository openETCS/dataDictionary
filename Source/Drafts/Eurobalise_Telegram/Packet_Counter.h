
#ifndef PACKET_COUNTER_H_INCLUDED
#define PACKET_COUNTER_H_INCLUDED

/*
    The counter instance is filled with information in the Eurobalise_Telegram_Decoder
    and contains the count for all packet types transmitted in the telegram. 
*/
struct Packet_Counter
{
    // The Eurobalise_Header might be stored in here as well.
    int Adhesion_Factor_Counter;
    int Gradient_Profile_Counter; 
    int Infill_location_reference_Counter;
    ...
};

typedef struct Packet_Counter Packet_Counter;

#endif // PACKET_COUNTER_H_INCLUDED

