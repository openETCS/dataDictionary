
// Sieht so aus wie unser Gradient_Profile_Core
// (es fehlen aber n_iter und die Substruktur)
struct {
  kcg_bool valid;
  q_dir;
  q_scale;
  d_gradient;
  q_gdir;
  g_a;
} struct__80663; --> P21_GradientProfile_T_Packet_Types_Pkg

// Sieht so aus wie unser Gradient_Profile_Core_1
struct {
  kcg_bool valid;
  d_gradient;
  q_gdir;
  g_a;
} struct__80675; --> P021_section_enum_T_TM;

struct {
  kcg_bool valid;
  q_dir;
  q_scale;
  n_iter;
  P021_OBU_sectionlist_enum_T_TM sections;
} struct__80685; --> P021_OBU_T_TM

P21_GradientProfile_T_Packet_Types_Pkg --> array__80672[7] --> P21_GradientProfiles_T_Packet_Types_Pkg;

P021_section_enum_T_TM --> array__80682[33] --> P021_OBU_sectionlist_enum_T_TM;

#define kcg_comp_P021_OBU_T_TM kcg_comp_struct__80685
#define kcg_copy_P021_OBU_T_TM kcg_copy_struct__80685
#define kcg_comp_P21_GradientProfile_T_Packet_Types_Pkg kcg_comp_struct__80663
#define kcg_copy_P21_GradientProfile_T_Packet_Types_Pkg kcg_copy_struct__80663
#define kcg_comp_P21_GradientProfiles_T_Packet_Types_Pkg kcg_comp_struct__80672
#define kcg_copy_P21_GradientProfiles_T_Packet_Types_Pkg kcg_copy_struct__80672

struct Gradient_Profile_Core
{
  q_dir;
  l_packet;
  q_scale;
  d_gradient;
  q_gdir;
  g_a;
  n_iter_1;
  Gradient_Profile_Core_1 sub_1[31];
};

struct Gradient_Profile_Core_1
{
  d_gradient;
  q_gdir;
  g_a;
};

