
#include "Decoder_Branch.h"

BasePacketPtr Decoder_Branch_TrainToTrack(Bitstream& stream, Packet_Header header)
{
    switch (header.NID_PACKET)
    {
        case 0 :
        {
            auto ret = std::make_shared<Position_Report>();

            if (Position_Report_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 1 :
        {
            auto ret = std::make_shared<Position_Report_based_on_two_balise_groups>();

            if (Position_Report_based_on_two_balise_groups_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 3 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Onboard_telephone_numbers>();

                if (Onboard_telephone_numbers_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 4 :
        {
            auto ret = std::make_shared<Error_Reporting>();

            if (Error_Reporting_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 5 :
        {
            auto ret = std::make_shared<Train_running_number>();

            if (Train_running_number_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 9 :
        {
            auto ret = std::make_shared<Level_23_transition_information>();

            if (Level_23_transition_information_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 11 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Validated_train_data>();

                if (Validated_train_data_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 44 :
        {
            auto ret = std::make_shared<Data_used_by_applications_outside_the_ERTMS_or_ETCS_system>();

            if (Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 255 :
        {
            auto ret = std::make_shared<End_of_Information>();

            if (End_of_Information_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

    default :
    {
        std::cerr << "Error, unrecognized Packet in " << __FILE__ << std::endl;
        return BasePacketPtr();
    }
    };
}

BasePacketPtr Decoder_Branch_TrackToTrain(Bitstream& stream, Packet_Header header)
{
    switch (header.NID_PACKET)
    {
        case 0 :
        {
            auto ret = std::make_shared<Virtual_Balise_Cover_marker>();

            if (Virtual_Balise_Cover_marker_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 2 :
        {
            auto ret = std::make_shared<System_Version_order>();

            if (System_Version_order_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 3 :
        {
            /*  Not implemented

                auto ret = std::make_shared<National_Values>();

                if (National_Values_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 5 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Linking>();

                if (Linking_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 6 :
        {
            auto ret = std::make_shared<Virtual_Balise_Cover_order>();

            if (Virtual_Balise_Cover_order_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 12 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Level_1_Movement_Authority>();

                if (Level_1_Movement_Authority_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 13 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Staff_Responsible_distance_Information_from_loop>();

                if (Staff_Responsible_distance_Information_from_loop_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 15 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Level_23_Movement_Authority>();

                if (Level_23_Movement_Authority_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 16 :
        {
            auto ret = std::make_shared<Repositioning_Information>();

            if (Repositioning_Information_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 21 :
        {

                auto ret = std::make_shared<Gradient_Profile>();

                if (Gradient_Profile_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            return BasePacketPtr();
        }
        case 27 :
        {
            /*  Not implemented

                auto ret = std::make_shared<International_Static_Speed_Profile>();

                if (International_Static_Speed_Profile_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 39 :
        {
            auto ret = std::make_shared<Track_Condition_Change_of_traction_system>();

            if (Track_Condition_Change_of_traction_system_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 40 :
        {
            auto ret = std::make_shared<Track_Condition_Change_of_allowed_current_consumption>();

            if (Track_Condition_Change_of_allowed_current_consumption_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 41 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Level_Transition_Order>();

                if (Level_Transition_Order_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 42 :
        {
            auto ret = std::make_shared<Session_Management>();

            if (Session_Management_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 44 :
        {
            auto ret = std::make_shared<Data_used_by_applications_outside_the_ERTMSETCS_system>();

            if (Data_used_by_applications_outside_the_ERTMSETCS_system_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 45 :
        {
            auto ret = std::make_shared<Radio_Network_registration>();

            if (Radio_Network_registration_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 46 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Conditional_Level_Transition_Order>();

                if (Conditional_Level_Transition_Order_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 49 :
        {
            /*  Not implemented

                auto ret = std::make_shared<List_of_balises_for_SH_Area>();

                if (List_of_balises_for_SH_Area_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 51 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Axle_Load_Speed_Profile>();

                if (Axle_Load_Speed_Profile_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 52 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Permitted_Braking_Distance_Information>();

                if (Permitted_Braking_Distance_Information_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 57 :
        {
            auto ret = std::make_shared<Movement_Authority_Request_Parameters>();

            if (Movement_Authority_Request_Parameters_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 58 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Position_Report_Parameters>();

                if (Position_Report_Parameters_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 63 :
        {
            /*  Not implemented

                auto ret = std::make_shared<List_of_Balises_in_SR_Authority>();

                if (List_of_Balises_in_SR_Authority_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 64 :
        {
            auto ret = std::make_shared<Inhibition_of_revocable_TSRs_from_balises_in_L23>();

            if (Inhibition_of_revocable_TSRs_from_balises_in_L23_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 65 :
        {
            auto ret = std::make_shared<Temporary_Speed_Restriction>();

            if (Temporary_Speed_Restriction_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 66 :
        {
            auto ret = std::make_shared<Temporary_Speed_Restriction_Revocation>();

            if (Temporary_Speed_Restriction_Revocation_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 67 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Track_Condition_Big_Metal_Masses>();

                if (Track_Condition_Big_Metal_Masses_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 68 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Track_Condition>();

                if (Track_Condition_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 69 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Track_Condition_Station_Platforms>();

                if (Track_Condition_Station_Platforms_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 70 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Route_Suitability_Data>();

                if (Route_Suitability_Data_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 71 :
        {
            auto ret = std::make_shared<Adhesion_Factor>();

            if (Adhesion_Factor_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 72 :
        {
            auto ret = std::make_shared<Packet_for_sending_plain_text_messages>();

            if (Packet_for_sending_plain_text_messages_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 76 :
        {
            auto ret = std::make_shared<Packet_for_sending_fixed_text_messages>();

            if (Packet_for_sending_fixed_text_messages_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 79 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Geographical_Position_Information>();

                if (Geographical_Position_Information_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 80 :
        {
            /*  Not implemented

                auto ret = std::make_shared<Mode_profile>();

                if (Mode_profile_Decoder(&stream, &(ret->core)) == 1)
                {
                    return ret;
                }
                else
                {
                    return BasePacketPtr();
                }
            */
            return BasePacketPtr();
        }
        case 88 :
        {
            auto ret = std::make_shared<Level_Crossing_information>();

            if (Level_Crossing_information_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 90 :
        {
            auto ret = std::make_shared<Track_Ahead_Free_up_to_level_23_transition_location>();

            if (Track_Ahead_Free_up_to_level_23_transition_location_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 131 :
        {
            auto ret = std::make_shared<RBC_transition_order>();

            if (RBC_transition_order_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 132 :
        {
            auto ret = std::make_shared<Danger_for_Shunting_information>();

            if (Danger_for_Shunting_information_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 133 :
        {
            auto ret = std::make_shared<Radio_infill_area_information>();

            if (Radio_infill_area_information_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 134 :
        {
            auto ret = std::make_shared<EOLM_Packet>();

            if (EOLM_Packet_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 135 :
        {
            auto ret = std::make_shared<Stop_Shunting_on_desk_opening>();

            if (Stop_Shunting_on_desk_opening_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 136 :
        {
            auto ret = std::make_shared<Infill_location_reference>();

            if (Infill_location_reference_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 137 :
        {
            auto ret = std::make_shared<Stop_if_in_Staff_Responsible>();

            if (Stop_if_in_Staff_Responsible_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 138 :
        {
            auto ret = std::make_shared<Reversing_area_information>();

            if (Reversing_area_information_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 139 :
        {
            auto ret = std::make_shared<Reversing_supervision_information>();

            if (Reversing_supervision_information_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 140 :
        {
            auto ret = std::make_shared<Train_running_number_from_RBC>();

            if (Train_running_number_from_RBC_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 141 :
        {
            auto ret = std::make_shared<Default_Gradient_for_Temporary_Speed_Restriction>();

            if (Default_Gradient_for_Temporary_Speed_Restriction_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 143 :
        {
            auto ret = std::make_shared<Session_Management_with_neighbouring_Radio_Infill_Unit>();

            if (Session_Management_with_neighbouring_Radio_Infill_Unit_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 145 :
        {
            auto ret = std::make_shared<Inhibition_of_balise_group_message_consistency_reaction>();

            if (Inhibition_of_balise_group_message_consistency_reaction_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 254 :
        {
            auto ret = std::make_shared<Default_balise_or_Loop_or_RIU_information>();

            if (Default_balise_or_Loop_or_RIU_information_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

        case 255 :
        {
            auto ret = std::make_shared<End_of_Information>();

            if (End_of_Information_Decoder(&stream, &(ret->core)) == 1)
            {
                return ret;
            }
            else
            {
                return BasePacketPtr();
            }
        }

    default :
    {
        std::cerr << "Error, unrecognized Packet in " << __FILE__ << std::endl;
        return BasePacketPtr();
    }
    };
}

