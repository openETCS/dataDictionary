
#include "Encoder_Branch.h"
#include <cassert>

bool Encoder_Branch_TrainToTrack(Bitstream& stream, BasePacketPtr packet)
{

    switch (packet->id)
    {
        /*
        Not implemented
        case 0 :
        {
            auto ptr = std::dynamic_pointer_cast<Position_Report>(packet);
            assert(ptr);

            return Position_Report_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 1 :
        {
            auto ptr = std::dynamic_pointer_cast<Position_Report_based_on_two_balise_groups>(packet);
            assert(ptr);

            return Position_Report_based_on_two_balise_groups_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 3 :
        {
            auto ptr = std::dynamic_pointer_cast<Onboard_telephone_numbers>(packet);
            assert(ptr);

            return Onboard_telephone_numbers_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        case 4 :
        {
            auto ptr = std::dynamic_pointer_cast<Error_Reporting>(packet);
            assert(ptr);

            return Error_Reporting_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 5 :
        {
            auto ptr = std::dynamic_pointer_cast<Train_running_number>(packet);
            assert(ptr);

            return Train_running_number_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 9 :
        {
            auto ptr = std::dynamic_pointer_cast<Level_23_transition_information>(packet);
            assert(ptr);

            return Level_23_transition_information_Encoder(&stream, &(ptr->core)) == 1;

        }

        /*
        Not implemented
        case 11 :
        {
            auto ptr = std::dynamic_pointer_cast<Validated_train_data>(packet);
            assert(ptr);

            return Validated_train_data_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 44 :
        {
            auto ptr = std::dynamic_pointer_cast<Data_used_by_applications_outside_the_ERTMS_or_ETCS_system>(packet);
            assert(ptr);

            return Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        case 255 :
        {
            auto ptr = std::dynamic_pointer_cast<End_of_Information>(packet);
            assert(ptr);

            return End_of_Information_Encoder(&stream, &(ptr->core)) == 1;

        }

    default :
    {
        return false;
    }

    };

}

bool Encoder_Branch_TrackToTrain(Bitstream& stream, BasePacketPtr packet)
{

    switch (packet->id)
    {
        case 0 :
        {
            auto ptr = std::dynamic_pointer_cast<Virtual_Balise_Cover_marker>(packet);
            assert(ptr);

            return Virtual_Balise_Cover_marker_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 2 :
        {
            auto ptr = std::dynamic_pointer_cast<System_Version_order>(packet);
            assert(ptr);

            return System_Version_order_Encoder(&stream, &(ptr->core)) == 1;

        }

        /*
        Not implemented
        case 3 :
        {
            auto ptr = std::dynamic_pointer_cast<National_Values>(packet);
            assert(ptr);

            return National_Values_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 5 :
        {
            auto ptr = std::dynamic_pointer_cast<Linking>(packet);
            assert(ptr);

            return Linking_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 6 :
        {
            auto ptr = std::dynamic_pointer_cast<Virtual_Balise_Cover_order>(packet);
            assert(ptr);

            return Virtual_Balise_Cover_order_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 12 :
        {
            auto ptr = std::dynamic_pointer_cast<Level_1_Movement_Authority>(packet);
            assert(ptr);

            return Level_1_Movement_Authority_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 13 :
        {
            auto ptr = std::dynamic_pointer_cast<Staff_Responsible_distance_Information_from_loop>(packet);
            assert(ptr);

            return Staff_Responsible_distance_Information_from_loop_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 15 :
        {
            auto ptr = std::dynamic_pointer_cast<Level_23_Movement_Authority>(packet);
            assert(ptr);

            return Level_23_Movement_Authority_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        case 16 :
        {
            auto ptr = std::dynamic_pointer_cast<Repositioning_Information>(packet);
            assert(ptr);

            return Repositioning_Information_Encoder(&stream, &(ptr->core)) == 1;

        }

        /*
        Not implemented
        case 21 :
        {
            auto ptr = std::dynamic_pointer_cast<Gradient_Profile>(packet);
            assert(ptr);

            return Gradient_Profile_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 27 :
        {
            auto ptr = std::dynamic_pointer_cast<International_Static_Speed_Profile>(packet);
            assert(ptr);

            return International_Static_Speed_Profile_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 39 :
        {
            auto ptr = std::dynamic_pointer_cast<Track_Condition_Change_of_traction_system>(packet);
            assert(ptr);

            return Track_Condition_Change_of_traction_system_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        case 40 :
        {
            auto ptr = std::dynamic_pointer_cast<Track_Condition_Change_of_allowed_current_consumption>(packet);
            assert(ptr);

            return Track_Condition_Change_of_allowed_current_consumption_Encoder(&stream, &(ptr->core)) == 1;

        }

        /*
        Not implemented
        case 41 :
        {
            auto ptr = std::dynamic_pointer_cast<Level_Transition_Order>(packet);
            assert(ptr);

            return Level_Transition_Order_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        case 42 :
        {
            auto ptr = std::dynamic_pointer_cast<Session_Management>(packet);
            assert(ptr);

            return Session_Management_Encoder(&stream, &(ptr->core)) == 1;

        }

        /*
        Not implemented
        case 44 :
        {
            auto ptr = std::dynamic_pointer_cast<Data_used_by_applications_outside_the_ERTMSETCS_system>(packet);
            assert(ptr);

            return Data_used_by_applications_outside_the_ERTMSETCS_system_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        case 45 :
        {
            auto ptr = std::dynamic_pointer_cast<Radio_Network_registration>(packet);
            assert(ptr);

            return Radio_Network_registration_Encoder(&stream, &(ptr->core)) == 1;

        }

        /*
        Not implemented
        case 46 :
        {
            auto ptr = std::dynamic_pointer_cast<Conditional_Level_Transition_Order>(packet);
            assert(ptr);

            return Conditional_Level_Transition_Order_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 49 :
        {
            auto ptr = std::dynamic_pointer_cast<List_of_balises_for_SH_Area>(packet);
            assert(ptr);

            return List_of_balises_for_SH_Area_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 51 :
        {
            auto ptr = std::dynamic_pointer_cast<Axle_Load_Speed_Profile>(packet);
            assert(ptr);

            return Axle_Load_Speed_Profile_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 52 :
        {
            auto ptr = std::dynamic_pointer_cast<Permitted_Braking_Distance_Information>(packet);
            assert(ptr);

            return Permitted_Braking_Distance_Information_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        case 57 :
        {
            auto ptr = std::dynamic_pointer_cast<Movement_Authority_Request_Parameters>(packet);
            assert(ptr);

            return Movement_Authority_Request_Parameters_Encoder(&stream, &(ptr->core)) == 1;

        }

        /*
        Not implemented
        case 58 :
        {
            auto ptr = std::dynamic_pointer_cast<Position_Report_Parameters>(packet);
            assert(ptr);

            return Position_Report_Parameters_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 63 :
        {
            auto ptr = std::dynamic_pointer_cast<List_of_Balises_in_SR_Authority>(packet);
            assert(ptr);

            return List_of_Balises_in_SR_Authority_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        case 64 :
        {
            auto ptr = std::dynamic_pointer_cast<Inhibition_of_revocable_TSRs_from_balises_in_L23>(packet);
            assert(ptr);

            return Inhibition_of_revocable_TSRs_from_balises_in_L23_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 65 :
        {
            auto ptr = std::dynamic_pointer_cast<Temporary_Speed_Restriction>(packet);
            assert(ptr);

            return Temporary_Speed_Restriction_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 66 :
        {
            auto ptr = std::dynamic_pointer_cast<Temporary_Speed_Restriction_Revocation>(packet);
            assert(ptr);

            return Temporary_Speed_Restriction_Revocation_Encoder(&stream, &(ptr->core)) == 1;

        }

        /*
        Not implemented
        case 67 :
        {
            auto ptr = std::dynamic_pointer_cast<Track_Condition_Big_Metal_Masses>(packet);
            assert(ptr);

            return Track_Condition_Big_Metal_Masses_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 68 :
        {
            auto ptr = std::dynamic_pointer_cast<Track_Condition>(packet);
            assert(ptr);

            return Track_Condition_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 69 :
        {
            auto ptr = std::dynamic_pointer_cast<Track_Condition_Station_Platforms>(packet);
            assert(ptr);

            return Track_Condition_Station_Platforms_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 70 :
        {
            auto ptr = std::dynamic_pointer_cast<Route_Suitability_Data>(packet);
            assert(ptr);

            return Route_Suitability_Data_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        case 71 :
        {
            auto ptr = std::dynamic_pointer_cast<Adhesion_Factor>(packet);
            assert(ptr);

            return Adhesion_Factor_Encoder(&stream, &(ptr->core)) == 1;

        }

        /*
        Not implemented
        case 72 :
        {
            auto ptr = std::dynamic_pointer_cast<Packet_for_sending_plain_text_messages>(packet);
            assert(ptr);

            return Packet_for_sending_plain_text_messages_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 76 :
        {
            auto ptr = std::dynamic_pointer_cast<Packet_for_sending_fixed_text_messages>(packet);
            assert(ptr);

            return Packet_for_sending_fixed_text_messages_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 79 :
        {
            auto ptr = std::dynamic_pointer_cast<Geographical_Position_Information>(packet);
            assert(ptr);

            return Geographical_Position_Information_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 80 :
        {
            auto ptr = std::dynamic_pointer_cast<Mode_profile>(packet);
            assert(ptr);

            return Mode_profile_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 88 :
        {
            auto ptr = std::dynamic_pointer_cast<Level_Crossing_information>(packet);
            assert(ptr);

            return Level_Crossing_information_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        /*
        Not implemented
        case 90 :
        {
            auto ptr = std::dynamic_pointer_cast<Track_Ahead_Free_up_to_level_23_transition_location>(packet);
            assert(ptr);

            return Track_Ahead_Free_up_to_level_23_transition_location_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        case 131 :
        {
            auto ptr = std::dynamic_pointer_cast<RBC_transition_order>(packet);
            assert(ptr);

            return RBC_transition_order_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 132 :
        {
            auto ptr = std::dynamic_pointer_cast<Danger_for_Shunting_information>(packet);
            assert(ptr);

            return Danger_for_Shunting_information_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 133 :
        {
            auto ptr = std::dynamic_pointer_cast<Radio_infill_area_information>(packet);
            assert(ptr);

            return Radio_infill_area_information_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 134 :
        {
            auto ptr = std::dynamic_pointer_cast<EOLM_Packet>(packet);
            assert(ptr);

            return EOLM_Packet_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 135 :
        {
            auto ptr = std::dynamic_pointer_cast<Stop_Shunting_on_desk_opening>(packet);
            assert(ptr);

            return Stop_Shunting_on_desk_opening_Encoder(&stream, &(ptr->core)) == 1;

        }

        /*
        Not implemented
        case 136 :
        {
            auto ptr = std::dynamic_pointer_cast<Infill_location_reference>(packet);
            assert(ptr);

            return Infill_location_reference_Encoder(&stream, &(ptr->core)) == 1;

        }

        */
        case 137 :
        {
            auto ptr = std::dynamic_pointer_cast<Stop_if_in_Staff_Responsible>(packet);
            assert(ptr);

            return Stop_if_in_Staff_Responsible_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 138 :
        {
            auto ptr = std::dynamic_pointer_cast<Reversing_area_information>(packet);
            assert(ptr);

            return Reversing_area_information_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 139 :
        {
            auto ptr = std::dynamic_pointer_cast<Reversing_supervision_information>(packet);
            assert(ptr);

            return Reversing_supervision_information_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 140 :
        {
            auto ptr = std::dynamic_pointer_cast<Train_running_number_from_RBC>(packet);
            assert(ptr);

            return Train_running_number_from_RBC_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 141 :
        {
            auto ptr = std::dynamic_pointer_cast<Default_Gradient_for_Temporary_Speed_Restriction>(packet);
            assert(ptr);

            return Default_Gradient_for_Temporary_Speed_Restriction_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 143 :
        {
            auto ptr = std::dynamic_pointer_cast<Session_Management_with_neighbouring_Radio_Infill_Unit>(packet);
            assert(ptr);

            return Session_Management_with_neighbouring_Radio_Infill_Unit_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 145 :
        {
            auto ptr = std::dynamic_pointer_cast<Inhibition_of_balise_group_message_consistency_reaction>(packet);
            assert(ptr);

            return Inhibition_of_balise_group_message_consistency_reaction_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 254 :
        {
            auto ptr = std::dynamic_pointer_cast<Default_balise_or_Loop_or_RIU_information>(packet);
            assert(ptr);

            return Default_balise_or_Loop_or_RIU_information_Encoder(&stream, &(ptr->core)) == 1;

        }

        case 255 :
        {
            auto ptr = std::dynamic_pointer_cast<End_of_Information>(packet);
            assert(ptr);

            return End_of_Information_Encoder(&stream, &(ptr->core)) == 1;

        }

    default :
    {
        return false;
    }

    };

}

