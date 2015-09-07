
#include <iostream>
#include <cassert>
#include "Euroradio_Message.h"
#include "Euroradio_Message_List.h"

Euroradio_MessagePtr Euroradio_Message_Decoder(Bitstream& stream)
{
    Message_Header messageID;
    Message_Header_Decoder(&stream, &messageID);

    switch (messageID.NID_MESSAGE)
    {
        case 129 :
        {
            auto ret = std::make_shared<Validated_Train_Data_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 130 :
        {
            auto ret = std::make_shared<Request_for_Shunting_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 132 :
        {
            auto ret = std::make_shared<MA_Request_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 136 :
        {
            auto ret = std::make_shared<Train_Position_Report_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 137 :
        {
            auto ret = std::make_shared<Request_to_shorten_MA_is_granted_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 138 :
        {
            auto ret = std::make_shared<Request_to_shorten_MA_is_rejected_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 146 :
        {
            auto ret = std::make_shared<Acknowledgement_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 147 :
        {
            auto ret = std::make_shared<Acknowledgement_of_Emergency_Stop_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 149 :
        {
            auto ret = std::make_shared<Track_Ahead_Free_Granted_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 150 :
        {
            auto ret = std::make_shared<End_of_Mission_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 153 :
        {
            auto ret = std::make_shared<Radio_infill_request_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 154 :
        {
            auto ret = std::make_shared<No_compatible_version_supported_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 155 :
        {
            auto ret = std::make_shared<Initiation_of_a_communication_session_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 156 :
        {
            auto ret = std::make_shared<Termination_of_a_communication_session_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 157 :
        {
            auto ret = std::make_shared<SoM_Position_Report_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 158 :
        {
            auto ret = std::make_shared<Text_message_acknowledged_by_driver_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 159 :
        {
            auto ret = std::make_shared<Session_Established_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 2 :
        {
            auto ret = std::make_shared<SR_Authorisation_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 3 :
        {
            auto ret = std::make_shared<Movement_Authority_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 6 :
        {
            auto ret = std::make_shared<Recognition_of_exit_from_TRIP_mode_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 8 :
        {
            auto ret = std::make_shared<Acknowledgement_of_Train_Data_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 9 :
        {
            auto ret = std::make_shared<Request_to_Shorten_MA_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 15 :
        {
            auto ret = std::make_shared<Conditional_Emergency_Stop_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 16 :
        {
            auto ret = std::make_shared<Unconditional_Emergency_Stop_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 18 :
        {
            auto ret = std::make_shared<Revocation_of_Emergency_Stop_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 24 :
        {
            auto ret = std::make_shared<General_message_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 27 :
        {
            auto ret = std::make_shared<SH_Refused_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 28 :
        {
            auto ret = std::make_shared<SH_Authorised_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 32 :
        {
            auto ret = std::make_shared<RBC_or_RIU_System_Version_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 33 :
        {
            auto ret = std::make_shared<MA_with_Shifted_Location_Reference_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 34 :
        {
            auto ret = std::make_shared<Track_Ahead_Free_Request_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 37 :
        {
            auto ret = std::make_shared<Infill_MA_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 38 :
        {
            auto ret = std::make_shared<Initiation_of_a_communication_session_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 39 :
        {
            auto ret = std::make_shared<Acknowledgement_of_termination_of_a_communication_session_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 40 :
        {
            auto ret = std::make_shared<Train_Rejected_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 41 :
        {
            auto ret = std::make_shared<Train_Accepted_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 43 :
        {
            auto ret = std::make_shared<SoM_position_report_confirmed_by_RBC_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        case 45 :
        {
            auto ret = std::make_shared<Assignment_of_coordinate_system_Message>();

            if ((*ret).decode(stream) == 1)
            {
                return ret;
            }
            else
            {
                return Euroradio_MessagePtr();
            }
        }

        default :
        {
            std::cout << "NID_MESSAGE " << +messageID.NID_MESSAGE << std::endl;
            std::cerr << "Error, unrecognized Euroradio Message in " << __FILE__ << std::endl;
            return Euroradio_MessagePtr();
        }
    }

    return Euroradio_MessagePtr();
}

bool Euroradio_Message_Encoder(Bitstream& stream, Euroradio_MessagePtr p)
{
    Message_Header_Encoder(&stream, &(p->header));

    switch (p->header.NID_MESSAGE)
    {
        case 129 :
        {
            auto ptr = std::dynamic_pointer_cast<Validated_Train_Data_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 130 :
        {
            auto ptr = std::dynamic_pointer_cast<Request_for_Shunting_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 132 :
        {
            auto ptr = std::dynamic_pointer_cast<MA_Request_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 136 :
        {
            auto ptr = std::dynamic_pointer_cast<Train_Position_Report_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 137 :
        {
            auto ptr = std::dynamic_pointer_cast<Request_to_shorten_MA_is_granted_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 138 :
        {
            auto ptr = std::dynamic_pointer_cast<Request_to_shorten_MA_is_rejected_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 146 :
        {
            auto ptr = std::dynamic_pointer_cast<Acknowledgement_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 147 :
        {
            auto ptr = std::dynamic_pointer_cast<Acknowledgement_of_Emergency_Stop_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 149 :
        {
            auto ptr = std::dynamic_pointer_cast<Track_Ahead_Free_Granted_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 150 :
        {
            auto ptr = std::dynamic_pointer_cast<End_of_Mission_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 153 :
        {
            auto ptr = std::dynamic_pointer_cast<Radio_infill_request_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 154 :
        {
            auto ptr = std::dynamic_pointer_cast<No_compatible_version_supported_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 155 :
        {
            auto ptr = std::dynamic_pointer_cast<Initiation_of_a_communication_session_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 156 :
        {
            auto ptr = std::dynamic_pointer_cast<Termination_of_a_communication_session_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 157 :
        {
            auto ptr = std::dynamic_pointer_cast<SoM_Position_Report_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 158 :
        {
            auto ptr = std::dynamic_pointer_cast<Text_message_acknowledged_by_driver_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 159 :
        {
            auto ptr = std::dynamic_pointer_cast<Session_Established_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 2 :
        {
            auto ptr = std::dynamic_pointer_cast<SR_Authorisation_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 3 :
        {
            auto ptr = std::dynamic_pointer_cast<Movement_Authority_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 6 :
        {
            auto ptr = std::dynamic_pointer_cast<Recognition_of_exit_from_TRIP_mode_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 8 :
        {
            auto ptr = std::dynamic_pointer_cast<Acknowledgement_of_Train_Data_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 9 :
        {
            auto ptr = std::dynamic_pointer_cast<Request_to_Shorten_MA_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 15 :
        {
            auto ptr = std::dynamic_pointer_cast<Conditional_Emergency_Stop_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 16 :
        {
            auto ptr = std::dynamic_pointer_cast<Unconditional_Emergency_Stop_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 18 :
        {
            auto ptr = std::dynamic_pointer_cast<Revocation_of_Emergency_Stop_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 24 :
        {
            auto ptr = std::dynamic_pointer_cast<General_message_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 27 :
        {
            auto ptr = std::dynamic_pointer_cast<SH_Refused_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 28 :
        {
            auto ptr = std::dynamic_pointer_cast<SH_Authorised_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 32 :
        {
            auto ptr = std::dynamic_pointer_cast<RBC_or_RIU_System_Version_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 33 :
        {
            auto ptr = std::dynamic_pointer_cast<MA_with_Shifted_Location_Reference_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 34 :
        {
            auto ptr = std::dynamic_pointer_cast<Track_Ahead_Free_Request_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 37 :
        {
            auto ptr = std::dynamic_pointer_cast<Infill_MA_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 38 :
        {
            auto ptr = std::dynamic_pointer_cast<Initiation_of_a_communication_session_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 39 :
        {
            auto ptr = std::dynamic_pointer_cast<Acknowledgement_of_termination_of_a_communication_session_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 40 :
        {
            auto ptr = std::dynamic_pointer_cast<Train_Rejected_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 41 :
        {
            auto ptr = std::dynamic_pointer_cast<Train_Accepted_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 43 :
        {
            auto ptr = std::dynamic_pointer_cast<SoM_position_report_confirmed_by_RBC_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }

        case 45 :
        {
            auto ptr = std::dynamic_pointer_cast<Assignment_of_coordinate_system_Message>(p);
            assert(ptr);

            return (*ptr).encode(stream) == 1;
        }


        default :
        {
            std::cout << "NID_MESSAGE " << +p->header.NID_MESSAGE << std::endl;
            std::cerr << "Error, unrecognized Euroradio Message in " << __FILE__ << std::endl;
            return false;
        }
    }

    return false;
}

