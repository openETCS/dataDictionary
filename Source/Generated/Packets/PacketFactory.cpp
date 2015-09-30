
#include "PacketFactory.h"

BasePacketPtr PacketFactory_TrainToTrack(uint8_t nid)
{
    switch (nid)
    {
        case 0 :
        {
            return std::make_shared<Position_Report>();
        }

        case 1 :
        {
            return std::make_shared<Position_Report_based_on_two_balise_groups>();
        }

        case 3 :
        {
            return std::make_shared<Onboard_telephone_numbers>();
        }

        case 4 :
        {
            return std::make_shared<Error_Reporting>();
        }

        case 5 :
        {
            return std::make_shared<Train_running_number>();
        }

        case 9 :
        {
            return std::make_shared<Level_23_transition_information>();
        }

        case 11 :
        {
            return std::make_shared<Validated_train_data>();
        }

        case 44 :
        {
            return std::make_shared<Data_used_by_applications_outside_the_ERTMS_or_ETCS_system>();
        }

        case 255 :
        {
            return std::make_shared<End_of_Information>();
        }

        default :
        {
            std::cerr << "Error, unrecognized Packet " << nid
                      << " in " << __FILE__ << std::endl;
            return BasePacketPtr();
        }
    };
}

BasePacketPtr PacketFactory_TrackToTrain(uint8_t nid)
{
    switch (nid)
    {
        case 0 :
        {
            return std::make_shared<Virtual_Balise_Cover_marker>();
        }

        case 2 :
        {
            return std::make_shared<System_Version_order>();
        }

        case 3 :
        {
            return std::make_shared<National_Values>();
        }

        case 5 :
        {
            return std::make_shared<Linking>();
        }

        case 6 :
        {
            return std::make_shared<Virtual_Balise_Cover_order>();
        }

        case 12 :
        {
            return std::make_shared<Level_1_Movement_Authority>();
        }

        case 13 :
        {
            return std::make_shared<Staff_Responsible_distance_Information_from_loop>();
        }

        case 15 :
        {
            return std::make_shared<Level_23_Movement_Authority>();
        }

        case 16 :
        {
            return std::make_shared<Repositioning_Information>();
        }

        case 21 :
        {
            return std::make_shared<Gradient_Profile>();
        }

        case 27 :
        {
            return std::make_shared<International_Static_Speed_Profile>();
        }

        case 39 :
        {
            return std::make_shared<Track_Condition_Change_of_traction_system>();
        }

        case 40 :
        {
            return std::make_shared<Track_Condition_Change_of_allowed_current_consumption>();
        }

        case 41 :
        {
            return std::make_shared<Level_Transition_Order>();
        }

        case 42 :
        {
            return std::make_shared<Session_Management>();
        }

        case 44 :
        {
            return std::make_shared<Data_used_by_applications_outside_the_ERTMSETCS_system>();
        }

        case 45 :
        {
            return std::make_shared<Radio_Network_registration>();
        }

        case 46 :
        {
            return std::make_shared<Conditional_Level_Transition_Order>();
        }

        case 49 :
        {
            return std::make_shared<List_of_balises_for_SH_Area>();
        }

        case 51 :
        {
            return std::make_shared<Axle_Load_Speed_Profile>();
        }

        case 52 :
        {
            return std::make_shared<Permitted_Braking_Distance_Information>();
        }

        case 57 :
        {
            return std::make_shared<Movement_Authority_Request_Parameters>();
        }

        case 58 :
        {
            return std::make_shared<Position_Report_Parameters>();
        }

        case 63 :
        {
            return std::make_shared<List_of_Balises_in_SR_Authority>();
        }

        case 64 :
        {
            return std::make_shared<Inhibition_of_revocable_TSRs_from_balises_in_L23>();
        }

        case 65 :
        {
            return std::make_shared<Temporary_Speed_Restriction>();
        }

        case 66 :
        {
            return std::make_shared<Temporary_Speed_Restriction_Revocation>();
        }

        case 67 :
        {
            return std::make_shared<Track_Condition_Big_Metal_Masses>();
        }

        case 68 :
        {
            return std::make_shared<Track_Condition>();
        }

        case 69 :
        {
            return std::make_shared<Track_Condition_Station_Platforms>();
        }

        case 70 :
        {
            return std::make_shared<Route_Suitability_Data>();
        }

        case 71 :
        {
            return std::make_shared<Adhesion_Factor>();
        }

        case 72 :
        {
            return std::make_shared<Packet_for_sending_plain_text_messages>();
        }

        case 76 :
        {
            return std::make_shared<Packet_for_sending_fixed_text_messages>();
        }

        case 79 :
        {
            return std::make_shared<Geographical_Position_Information>();
        }

        case 80 :
        {
            return std::make_shared<Mode_profile>();
        }

        case 88 :
        {
            return std::make_shared<Level_Crossing_information>();
        }

        case 90 :
        {
            return std::make_shared<Track_Ahead_Free_up_to_level_23_transition_location>();
        }

        case 131 :
        {
            return std::make_shared<RBC_transition_order>();
        }

        case 132 :
        {
            return std::make_shared<Danger_for_Shunting_information>();
        }

        case 133 :
        {
            return std::make_shared<Radio_infill_area_information>();
        }

        case 134 :
        {
            return std::make_shared<EOLM_Packet>();
        }

        case 135 :
        {
            return std::make_shared<Stop_Shunting_on_desk_opening>();
        }

        case 136 :
        {
            return std::make_shared<Infill_location_reference>();
        }

        case 137 :
        {
            return std::make_shared<Stop_if_in_Staff_Responsible>();
        }

        case 138 :
        {
            return std::make_shared<Reversing_area_information>();
        }

        case 139 :
        {
            return std::make_shared<Reversing_supervision_information>();
        }

        case 140 :
        {
            return std::make_shared<Train_running_number_from_RBC>();
        }

        case 141 :
        {
            return std::make_shared<Default_Gradient_for_Temporary_Speed_Restriction>();
        }

        case 143 :
        {
            return std::make_shared<Session_Management_with_neighbouring_Radio_Infill_Unit>();
        }

        case 145 :
        {
            return std::make_shared<Inhibition_of_balise_group_message_consistency_reaction>();
        }

        case 254 :
        {
            return std::make_shared<Default_balise_or_Loop_or_RIU_information>();
        }

        case 255 :
        {
            return std::make_shared<End_of_Information>();
        }

        default :
        {
            std::cerr << "Error, unrecognized Packet " << nid
                      << " in " << __FILE__ << std::endl;
            return BasePacketPtr();
        }
    };
}

