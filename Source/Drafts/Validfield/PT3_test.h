
struct {
  kcg_bool valid;
  number;
  aNID_RADIO_T_Packet_TrainTypes_Pkg aNID_RADIO;
} struct__81261; --> PT3_OnboardTelephoneNumbers_T_Packet_TrainTypes_Pkg;

struct {
  kcg_bool valid;
  telephoneNumber_T_Packet_TrainTypes_Pkg telephoneNumber;
} struct__81253; --> sNID_RADIO_T_Packet_TrainTypes_Pkg

sNID_RADIO_T_Packet_TrainTypes_Pkg --> array_81258[1] --> aNID_RADIO_T_Packet_TrainTypes_Pkg;

struct Onboard_telephone_numbers_Core
{
  l_packet;
  n_iter_1;
  Onboard_telephone_numbers_Core_1 sub_1[31];
}

struct Onboard_telephone_numbers_Core_1
{
  nid_radio;
}

