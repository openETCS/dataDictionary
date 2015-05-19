
#include "Packet_Counter_Init.h"

/*
    Initialize all counter variables with 0.
*/
void Packet_Counter_Init(Counter* counter)
{
    counter->Adhesion_Factor_Counter = 0;
    counter->Gradient_Profile_Counter = 0;
    counter->Infill_location_reference = 0;
    ...
}

