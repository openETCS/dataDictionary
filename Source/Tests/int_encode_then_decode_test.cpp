
#include "Adhesion_Factor.h"
#include "Compressed_Packets.h"
#include "PacketHeader.h"
#include <cassert>
#include <iostream>

int main ()
{
    Adhesion_Factor a;
    {
        // NID_PACKET = 0;
        a.core.Q_DIR = 1;
        a.core.L_PACKET = 56;
        a.core.Q_SCALE = 1;
        a.core.D_ADHESION = 9;
        a.core.L_ADHESION = 24;
        a.core.M_ADHESION = 0;
    }

    Flat_Packets container;

    std::cout << "\n\nEncoding the Packet: " << a << std::endl;

    if (a.encode(container.PacketHeaders[0], container.PacketData, 0))
    {
        std::cout << "The packet was encoded into the int stream." << std::endl;
    }
    else
    {
        std::cout << "An error occured during the encoding process of the packet." << std::endl;
    }

    std::cout << "The Metadata Element contains this data: "
              << "nid_packet: " << container.PacketHeaders[0].nid_packet << ", "
              << "q_dir: " << container.PacketHeaders[0].q_dir << ", "
              << "valid: " << +container.PacketHeaders[0].valid << ", "
              << "startAddress: " << container.PacketHeaders[0].startAddress << ", "
              << "endAddress: " << container.PacketHeaders[0].endAddress << std::endl;

    //std::cout << "The int stream contains this data: ";
    //std::cout << "0:" << container.PacketData[0];

    //for (unsigned int i = 1; i < 500; ++i)
    //{
        //std::cout << ", " << i << ":" << container.PacketData[i];
    //}

    std::cout << std::endl;

    Adhesion_Factor b;

    if (b.decode(container.PacketHeaders[0], container.PacketData))
    {
        std::cout << "The packet was decoded from the int stream." << std::endl;
    }
    else
    {
        std::cout << "An error occured during the decoding process of the packet." << std::endl;
    }

    std::cout << "Decoded the packet: " << b << std::endl;

    assert(a == b);

    std::cout << "Test successfull.\n" << std::endl;
}

