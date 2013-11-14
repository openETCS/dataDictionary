#include <oETCSApi.h>


struct STRUCT_DATA_oETCS_Virtual_Balise_Cover_marker { 
// TransmissionMedia=Balise
// Indication to on-board that the telegram can be ignored according to a VBC

	UInt32 NID_PACKET;                     	// Packet =   0; 		// # 8	
	UInt32 NID_VBCMK;                              			// # 6	
};
//=============================================

struct STRUCT_DATA_oETCS_System_Version_order { 
// TransmissionMedia=Balise
// This packet is used to tell the on-board which is the operated system version

	UInt32 NID_PACKET;                     	// Packet =   2; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 M_VERSION;                              			// # 7	
};
//=============================================

struct STRUCT_DATA_oETCS_National_Values { 
// TransmissionMedia=Balise, RBC
// Downloads a set of National Values to the train

	UInt32 NID_PACKET;                     	// Packet =   3; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_VALIDNV;                              			// # 15	
	UInt32 NID_C;                                  			// # 10		// Identification of national areas to which the set applies    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 NID_C;                           		// # 10		// Identification of additional national area(s) to which the set applies        
        } a_data[33];
        } m;

	UInt32 V_NVSHUNT;                              			// # 7	
	UInt32 V_NVSTFF;                               			// # 7	
	UInt32 V_NVONSIGHT;                            			// # 7	
	UInt32 V_NVLIMSUPERV;                          			// # 7	
	UInt32 V_NVUNFIT;                              			// # 7	
	UInt32 V_NVREL;                                			// # 7	
	UInt32 D_NVROLL;                               			// # 15	
	UInt32 Q_NVSBTSMPERM;                          			// # 1	
	UInt32 Q_NVEMRRLS;                             			// # 1	
	UInt32 Q_NVGUIPERM;                            			// # 1	
	UInt32 Q_NVSBFBPERM;                           			// # 1	
	UInt32 Q_NVINHSMICPERM;                        			// # 1	
	UInt32 V_NVALLOWOVTRP;                         			// # 7	
	UInt32 V_NVSUPOVTRP;                           			// # 7	
	UInt32 D_NVOVTRP;                              			// # 15	
	UInt32 T_NVOVTRP;                              			// # 8	
	UInt32 D_NVPOTRP;                              			// # 15	
	UInt32 M_NVCONTACT;                            			// # 2	
	UInt32 T_NVCONTACT;                            			// # 8	
	UInt32 M_NVDERUN;                              			// # 1	
	UInt32 D_NVSTFF;                               			// # 15	
	UInt32 Q_NVDRIVER_ADHES;                       			// # 1	
	UInt32 A_NVMAXREDADH1;                         			// # 6	
	UInt32 A_NVMAXREDADH2;                         			// # 6	
	UInt32 A_NVMAXREDADH3;                         			// # 6	
	UInt32 Q_NVLOCACC;                             			// # 6	
	UInt32 M_NVAVADH;                              			// # 5	
	UInt32 M_NVEBCL;                               			// # 4	
	UInt32 Q_NVKINT;                               			// # 1		// if (Q_NVKINT == 1)
	UInt32 Q_NVKVINTSET;                           			// # 2		// Only if Q_NVKINT = 1, Q_NVKVINTSET and the following variables follow	// if (Q_NVKVINTSET == 1)
	UInt32 A_NVP12;                                			// # 6		// Only if Q_NVKVINTSET = 1
	UInt32 A_NVP23;                                			// # 6		// Only if Q_NVKVINTSET = 1
	UInt32 V_NVKVINT;                              			// # 7		// = 0 km/h
	UInt32 M_NVKVINT;                              			// # 7		// Valid between V_NVKVINT and V_NVKVINT(1)If Q_NVKVINTSET = 1, gives the correction factor if maximum emergency brake deceleration is lower than A_NVP12    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 V_NVKVINT;                       		// # 7	
		UInt32 M_NVKVINT;                       		// # 7		// Valid between V_NVKVINT(n) and V_NVKVINT(n+1)If Q_NVKVINTSET = 1, gives the correction factor if maximum emergency brake deceleration is lower than A_NVP12        
        } a_data[33];
        } m;
    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 Q_NVKVINTSET;                    		// # 2		// if (Q_NVKVINTSET(k) == 1)
		UInt32 A_NVP12;                         		// # 6		// Only if Q_NVKVINTSET(k) = 1
		UInt32 A_NVP23;                         		// # 6		// Only if Q_NVKVINTSET(k) = 1
		UInt32 V_NVKVINT;                       		// # 7		// = 0km/h
		UInt32 M_NVKVINT;                       		// # 7		// If Q_NVKVINTSET(k) = 1; Valid between V_NVKVINT(k) and V_NVKVINT(k,1). Gives the correction factor if maximum emergency brake deceleration is lower than A_NVP12(k).
	struct {        
            UInt32 N_ITER;                      // N_ITER(k)            // # 5
		// # 5	
	struct {
		UInt32 V_NVKVINT;                       		// # 7	
		UInt32 M_NVKVINT;                       		// # 7		// If Q_NVKVINTSET(k) = 1.Valid between V_NVKVINT(k,m) and V_NVKVINT(k,m+1)gives the correction factor if maximum emergency brake deceleration is lower than A_NVP12(k)        
        } a_data[32];
        } k;
        
        } a_data[33];
        } m;

	UInt32 L_NVKRINT;                              			// # 5		// = 0m
	UInt32 M_NVKRINT;                              			// # 5		// Valid between L_NVKRINT and L_NVKRINT(1)    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 L_NVKRINT;                       		// # 5	
		UInt32 M_NVKRINT;                       		// # 5		// Valid between L_NVKRINT(l) and L_NVKRINT(l+1)        
        } a_data[33];
        } m;

	UInt32 M_NVKTINT;                              			// # 5	
};
//=============================================

struct STRUCT_DATA_oETCS_Linking { 
// TransmissionMedia=Any
// Linking Information.

	UInt32 NID_PACKET;                     	// Packet =   5; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_LINK;                                 			// # 15	
	UInt32 Q_NEWCOUNTRY;                           			// # 1		// if (Q_NEWCOUNTRY == 1)
	UInt32 NID_C;                                  			// # 10		// if Q_NEWCOUNTRY = 1
	UInt32 NID_BG;                                 			// # 14	
	UInt32 Q_LINKORIENTATION;                      			// # 1	
	UInt32 Q_LINKREACTION;                         			// # 2	
	UInt32 Q_LOCACC;                               			// # 6	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 D_LINK;                          		// # 15	
		UInt32 Q_NEWCOUNTRY;                    		// # 1		// if (Q_NEWCOUNTRY(k) == 1)
		UInt32 NID_C;                           		// # 10		// if Q_NEWCOUNTRY(k) = 1
		UInt32 NID_BG;                          		// # 14	
		UInt32 Q_LINKORIENTATION;               		// # 1	
		UInt32 Q_LINKREACTION;                  		// # 2	
		UInt32 Q_LOCACC;                        		// # 6	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Virtual_Balise_Cover_order { 
// TransmissionMedia=Balise
// The packet sets/removes a Virtual Balise Cover.

	UInt32 NID_PACKET;                     	// Packet =   6; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_VBCO;                                 			// # 1	
	UInt32 NID_VBCMK;                              			// # 6	
	UInt32 NID_C;                                  			// # 10		// if (Q_VBCO == 1)
	UInt32 T_VBC;                                  			// # 8		// Only if Q_VBCO = 1
};
//=============================================

struct STRUCT_DATA_oETCS_Level_1_Movement_Authority { 
// TransmissionMedia=Balise, Loop, RIU
// Transmission of a movement authority for level 1.

	UInt32 NID_PACKET;                     	// Packet =  12; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 V_MAIN;                                 			// # 7	
	UInt32 V_LOA;                                  			// # 7	
	UInt32 T_LOA;                                  			// # 10		// Can be set to 'no time-out'    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {
	// Set to zero if V_MAIN = 0 or if only one section in the MA
		UInt32 L_SECTION;                       		// # 15	
		UInt32 Q_SECTIONTIMER;                  		// # 1	
		UInt32 T_SECTIONTIMER;                  		// # 10	
		UInt32 D_SECTIONTIMERSTOPLOC;           		// # 15	        
        } a_data[33];
        } m;

	UInt32 L_ENDSECTION;                           			// # 15	
	UInt32 Q_SECTIONTIMER;                         			// # 1	
	UInt32 T_SECTIONTIMER;                         			// # 10	
	UInt32 D_SECTIONTIMERSTOPLOC;                  			// # 15	
	UInt32 Q_ENDTIMER;                             			// # 1	
	UInt32 T_ENDTIMER;                             			// # 10	
	UInt32 D_ENDTIMERSTARTLOC;                     			// # 15	
	UInt32 Q_DANGERPOINT;                          			// # 1	
	UInt32 D_DP;                                   			// # 15	
	UInt32 V_RELEASEDP;                            			// # 7	
	UInt32 Q_OVERLAP;                              			// # 1	
	UInt32 D_STARTOL;                              			// # 15	
	UInt32 T_OL;                                   			// # 10	
	UInt32 D_OL;                                   			// # 15	
	UInt32 V_RELEASEOL;                            			// # 7	
};
//=============================================

struct STRUCT_DATA_oETCS_Staff_Responsible_distance_Information_from_loop { 
// TransmissionMedia=Loop
// Information for trains in staff responsible mode

	UInt32 NID_PACKET;                     	// Packet =  13; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
		UInt32 Q_NEWCOUNTRY[0];                 		// # 1		// if (Q_NEWCOUNTRY(0) == 1)
		UInt32 NID_C[0];                        		// # 10		// If Q_NEWCOUNTRY(0) = 1
		UInt32 NID_BG[0];                       		// # 14		// Main signal balise group
		UInt32 Q_NEWCOUNTRY[1];                 		// # 1		// if (Q_NEWCOUNTRY(1) == 1)
		UInt32 NID_C[1];                        		// # 10		// If Q_NEWCOUNTRY(1) = 1
		UInt32 NID_BG[1];                       		// # 14		// Reference balise
	UInt32 D_SR;                                   			// # 15	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 Q_NEWCOUNTRY;                    		// # 1		// if (Q_NEWCOUNTRY (k) == 1)
		UInt32 NID_C;                           		// # 10		// If Q_NEWCOUNTRY (k) = 1
		UInt32 NID_BG;                          		// # 14		// Reference balise
		UInt32 D_SR;                            		// # 15	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Level_23_Movement_Authority { 
// TransmissionMedia=RBC
// Transmission of a movement authority for levels 2/3.

	UInt32 NID_PACKET;                     	// Packet =  15; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 V_LOA;                                  			// # 7	
	UInt32 T_LOA;                                  			// # 10		// Can be set to 'no time-out'    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {
	// Set to zero if only one section in the MA
		UInt32 L_SECTION;                       		// # 15	
		UInt32 Q_SECTIONTIMER;                  		// # 1	
		UInt32 T_SECTIONTIMER;                  		// # 10	
		UInt32 D_SECTIONTIMERSTOPLOC;           		// # 15	        
        } a_data[33];
        } m;

	UInt32 L_ENDSECTION;                           			// # 15	
	UInt32 Q_SECTIONTIMER;                         			// # 1	
	UInt32 T_SECTIONTIMER;                         			// # 10	
	UInt32 D_SECTIONTIMERSTOPLOC;                  			// # 15	
	UInt32 Q_ENDTIMER;                             			// # 1	
	UInt32 T_ENDTIMER;                             			// # 10	
	UInt32 D_ENDTIMERSTARTLOC;                     			// # 15	
	UInt32 Q_DANGERPOINT;                          			// # 1	
	UInt32 D_DP;                                   			// # 15	
	UInt32 V_RELEASEDP;                            			// # 7	
	UInt32 Q_OVERLAP;                              			// # 1	
	UInt32 D_STARTOL;                              			// # 15	
	UInt32 T_OL;                                   			// # 10	
	UInt32 D_OL;                                   			// # 15	
	UInt32 V_RELEASEOL;                            			// # 7	
};
//=============================================

struct STRUCT_DATA_oETCS_Repositioning_Information { 
// TransmissionMedia=Balise
// Transmission of the update of the current distance

	UInt32 NID_PACKET;                     	// Packet =  16; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 L_SECTION;                              			// # 15	
};
//=============================================

struct STRUCT_DATA_oETCS_Gradient_Profile { 
// TransmissionMedia=Any
// Transmission of the gradient.D_GRADIENT gives the distance to the next change of the gradient value. The gradient value is the minimum gradient for the given distance.

	UInt32 NID_PACKET;                     	// Packet =  21; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_GRADIENT;                             			// # 15	
	UInt32 Q_GDIR;                                 			// # 1		// 0 = downhill 1= uphill
	UInt32 G_A;                                    			// # 8	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 D_GRADIENT;                      		// # 15	
		UInt32 Q_GDIR;                          		// # 1		// 0 = downhill 1= uphill
		UInt32 G_A;                             		// # 8	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_International_Static_Speed_Profile { 
// TransmissionMedia=Any
// Static speed profile and optionally speed limits depending on the international train category.

	UInt32 NID_PACKET;                     	// Packet =  27; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_STATIC;                               			// # 15	
	UInt32 V_STATIC;                               			// # 7		// Basic SSP
	UInt32 Q_FRONT;                                			// # 1	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 Q_DIFF;                          		// # 2		// if (Q_DIFF(n) == 0)
		UInt32 NC_CDDIFF;                       		// # 4		// If Q_DIFF(n) = 0	// if ((Q_DIFF(n) == 1) or (Q_DIFF(n) == 2))
		UInt32 NC_DIFF;                         		// # 4		// If Q_DIFF(n) = 1 or 2
		UInt32 V_DIFF;                          		// # 7	        
        } a_data[33];
        } m;
    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 D_STATIC;                        		// # 15	
		UInt32 V_STATIC;                        		// # 7		// Basic SSP
		UInt32 Q_FRONT;                         		// # 1	
	struct {        
            UInt32 N_ITER;                      // N_ITER(k)            // # 5
		// # 5	
	struct {
		UInt32 Q_DIFF;                          		// # 2		// if (Q_DIFF(k,m) == 0)
		UInt32 NC_CDDIFF;                       		// # 4		// If Q_DIFF(k,m) = 0	// if ((Q_DIFF(k,m) == 1) or (Q_DIFF(k,m) == 2))
		UInt32 NC_DIFF;                         		// # 4		// If Q_DIFF(k,m) = 1 or 2
		UInt32 V_DIFF;                          		// # 7	        
        } a_data[32];
        } k;
        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Track_Condition_Change_of_traction_system { 
// TransmissionMedia=Any
// The packet gives information about change of the traction system.

	UInt32 NID_PACKET;                     	// Packet =  39; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_TRACTION;                             			// # 15	
	UInt32 M_VOLTAGE;                              			// # 4		// if (M_VOLTAGE != 0)
	UInt32 NID_CTRACTION;                          			// # 10		// only if M_VOLTAGE != 0  Identity of the traction system NID_CTRACTION given
};
//=============================================

struct STRUCT_DATA_oETCS_Track_Condition_Change_of_allowed_current_consumption { 
// TransmissionMedia=Any
// The packet gives information about change of the allowed current consumption.

	UInt32 NID_PACKET;                     	// Packet =  40; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_CURRENT;                              			// # 15	
	UInt32 M_CURRENT;                              			// # 10		// Allowed current consumption.
};
//=============================================

struct STRUCT_DATA_oETCS_Level_Transition_Order { 
// TransmissionMedia=Any
// Packet to identify where a level transition shall take place. In case of mixed levels, the successive M_LEVELTR go from the highest priority level to the lowest one.

	UInt32 NID_PACKET;                     	// Packet =  41; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_LEVELTR;                              			// # 15	
	UInt32 M_LEVELTR;                              			// # 3		// if (M_LEVELTR == 1)
	UInt32 NID_NTC;                                			// # 8		// If  M_LEVELTR = 1  (NTC)
	UInt32 L_ACKLEVELTR;                           			// # 15	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 M_LEVELTR;                       		// # 3		// if (M_LEVELTR(k) == 1)
		UInt32 NID_NTC;                         		// # 8		// If M_LEVELTR(k) = 1
		UInt32 L_ACKLEVELTR;                    		// # 15	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Session_Management { 
// TransmissionMedia=Balise, RBC
// Packet to give the identity and telephone number of the RBC with which a session shall be established or terminated.

	UInt32 NID_PACKET;                     	// Packet =  42; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_RBC;                                  			// # 1	
	UInt32 NID_C;                                  			// # 10		// RBC ETCS identity : NID_C not relevant if NID_RBC has value 'Contact last known RBC'
	UInt32 NID_RBC;                                			// # 14	
	UInt32 NID_RADIO;                              			// # 64		// not relevant if NID_RBC has value 'Contact last known RBC'
	UInt32 Q_SLEEPSESSION;                         			// # 1	
};
//=============================================

struct STRUCT_DATA_oETCS_Data_used_by_applications_outside_the_ERTMSETCS_system { 
// TransmissionMedia=Any
// Messages between trackside and on-board devices, which contain information used by applications outside the ERTMS/ETCS system.

	UInt32 NID_PACKET;                     	// Packet =  44; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 NID_XUSER;                              			// # 9		// if (NID_XUSER == 102)
	UInt32 NID_NTC;                                			// # 8		// Only if NID_XUSER = 102 (National System functions)
	UInt32 Other_data_depending_on__NID_XUSER;     			// # 	
};
//=============================================

struct STRUCT_DATA_oETCS_Radio_Network_registration { 
// TransmissionMedia=Balise, RBC, RIU
// Packet to give the identity of the Radio Network to which a registration shall be enforced.

	UInt32 NID_PACKET;                     	// Packet =  45; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 NID_MN;                                 			// # 24	
};
//=============================================

struct STRUCT_DATA_oETCS_Conditional_Level_Transition_Order { 
// TransmissionMedia=Balise
// Packet for a conditional level transition. The successive M_LEVELTR go from the highest priority level to the lowest one.

	UInt32 NID_PACKET;                     	// Packet =  46; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 M_LEVELTR;                              			// # 3		// if (M_LEVELTR == 1)
	UInt32 NID_NTC;                                			// # 8		// If M_LEVELTR = 1    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 M_LEVELTR;                       		// # 3		// if (M_LEVELTR(k) == 1)
		UInt32 NID_NTC;                         		// # 8		// If M_LEVELTR(k) = 1        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_List_of_balises_for_SH_Area { 
// TransmissionMedia=Any
// Used to list balise group(s) which the train can pass over in SH mode

	UInt32 NID_PACKET;                     	// Packet =  49; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 Q_NEWCOUNTRY;                    		// # 1		// if (Q_NEWCOUNTRY(k) == 1)
		UInt32 NID_C;                           		// # 10		// if Q_NEWCOUNTRY(k) = 1
		UInt32 NID_BG;                          		// # 14	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Axle_Load_Speed_Profile { 
// TransmissionMedia=Any
// This packet gives the speed restrictions for trains with axle load category higher than or equal to the specified value for the speed restriction

	UInt32 NID_PACKET;                     	// Packet =  51; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 Q_TRACKINIT;                            			// # 1		// if (Q_TRACKINIT == 1)
	UInt32 D_TRACKINIT;                            			// # 15		// Only if Q_TRACKINIT = 1	// if (Q_TRACKINIT == 0)
	UInt32 D_AXLELOAD;                             			// # 15		// Only if Q_TRACKINIT = 0D_AXLELOAD and the following variables follow
	UInt32 L_AXLELOAD;                             			// # 15	
	UInt32 Q_FRONT;                                			// # 1	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 M_AXLELOADCAT;                   		// # 7	
		UInt32 V_AXLELOAD;                      		// # 7		// Speed restriction to be applied if the axle load category of the train ( M_AXLELOADCAT(n)        
        } a_data[33];
        } m;
    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 D_AXLELOAD;                      		// # 15	
		UInt32 L_AXLELOAD;                      		// # 15	
		UInt32 Q_FRONT;                         		// # 1	
	struct {        
            UInt32 N_ITER;                      // N_ITER(k)            // # 5
		// # 5	
	struct {
		UInt32 M_AXLELOADCAT;                   		// # 7	
		UInt32 V_AXLELOAD;                      		// # 7		// Speed restriction to be applied if the axle load category of the train ( M_AXLELOADCAT(k,m)        
        } a_data[32];
        } k;
        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Permitted_Braking_Distance_Information { 
// TransmissionMedia=Any
// This packet requests the on-board calculation of speed restrictions which ensure a given permitted brake distance in case of an EB, or SB, intervention

	UInt32 NID_PACKET;                     	// Packet =  52; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 Q_TRACKINIT;                            			// # 1		// if (Q_TRACKINIT == 1)
	UInt32 D_TRACKINIT;                            			// # 15		// Only if Q_TRACKINIT = 1	// if (Q_TRACKINIT == 0)
	UInt32 D_PBD;                                  			// # 15		// Only if Q_TRACKINIT = 0 D_PBD and the following variables follow
	UInt32 Q_GDIR;                                 			// # 1		// 0 = downhill, 1 = uphill
	UInt32 G_PBDSR;                                			// # 8		// Gradient value to be used for the calculation
	UInt32 Q_PBDSR;                                			// # 1	
	UInt32 D_PBDSR;                                			// # 15	
	UInt32 L_PBDSR;                                			// # 15	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 D_PBD;                           		// # 15	
		UInt32 Q_GDIR;                          		// # 1		// 0 = downhill, 1 = uphill
		UInt32 G_PBDSR;                         		// # 8		// Gradient value to be used for the calculation
		UInt32 Q_PBDSR;                         		// # 1	
		UInt32 D_PBDSR;                         		// # 15	
		UInt32 L_PBDSR;                         		// # 15	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Movement_Authority_Request_Parameters { 
// TransmissionMedia=RBC
// This packet is intended to give parameters telling when and how often the train has to ask for a movement authority.

	UInt32 NID_PACKET;                     	// Packet =  57; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 T_MAR;                                  			// # 8	
	UInt32 T_TIMEOUTRQST;                          			// # 10	
	UInt32 T_CYCRQST;                              			// # 8	
};
//=============================================

struct STRUCT_DATA_oETCS_Position_Report_Parameters { 
// TransmissionMedia=RBC
// This packet is intended to give parameters telling when and how often the position has to be reported.

	UInt32 NID_PACKET;                     	// Packet =  58; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 T_CYCLOC;                               			// # 8	
	UInt32 D_CYCLOC;                               			// # 15	
	UInt32 M_LOC;                                  			// # 3	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 D_LOC;                           		// # 15	
		UInt32 Q_LGTLOC;                        		// # 1	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_List_of_Balises_in_SR_Authority { 
// TransmissionMedia=RBC
// Used to list balise group(s) which the train can pass over in SR mode

	UInt32 NID_PACKET;                     	// Packet =  63; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 Q_NEWCOUNTRY;                    		// # 1		// if (Q_NEWCOUNTRY(k) == 1)
		UInt32 NID_C;                           		// # 10		// if Q_NEWCOUNTRY(k) = 1
		UInt32 NID_BG;                          		// # 14	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Inhibition_of_revocable_TSRs_from_balises_in_L23 { 
// TransmissionMedia=RBC
// This packet is used to inhibit revocable TSRs from balises in level 2 or 3.

	UInt32 NID_PACKET;                     	// Packet =  64; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
};
//=============================================

struct STRUCT_DATA_oETCS_Temporary_Speed_Restriction { 
// TransmissionMedia=Any
// Transmission of temporary speed restriction.

	UInt32 NID_PACKET;                     	// Packet =  65; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 NID_TSR;                                			// # 8	
	UInt32 D_TSR;                                  			// # 15	
	UInt32 L_TSR;                                  			// # 15	
	UInt32 Q_FRONT;                                			// # 1	
	UInt32 V_TSR;                                  			// # 7	
};
//=============================================

struct STRUCT_DATA_oETCS_Temporary_Speed_Restriction_Revocation { 
// TransmissionMedia=Any
// Transmission of temporary speed restriction revocation.

	UInt32 NID_PACKET;                     	// Packet =  66; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 NID_TSR;                                			// # 8		// Identity of TSR to be revoked
};
//=============================================

struct STRUCT_DATA_oETCS_Track_Condition_Big_Metal_Masses { 
// TransmissionMedia=Balise
// The packet gives details concerning where to ignore integrity check alarms of balise transmission due to big metal masses trackside.

	UInt32 NID_PACKET;                     	// Packet =  67; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_TRACKCOND;                            			// # 15	
	UInt32 L_TRACKCOND;                            			// # 15		// The distance for which integrity check alarms of balise transmission shall be ignored    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 D_TRACKCOND;                     		// # 15	
		UInt32 L_TRACKCOND;                     		// # 15		// The distance for which integrity check alarms of balise transmission shall be ignored        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Track_Condition { 
// TransmissionMedia=Any
// The packet gives details concerning the track ahead to support the driver when e.g. lower pantograph

	UInt32 NID_PACKET;                     	// Packet =  68; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 Q_TRACKINIT;                            			// # 1		// if (Q_TRACKINIT == 1)
	UInt32 D_TRACKINIT;                            			// # 15		// Only if Q_TRACKINIT = 1	// if (Q_TRACKINIT == 0)
	UInt32 D_TRACKCOND;                            			// # 15		// Only if Q_TRACKINIT = 0D_TRACKCOND and the following variables follow
	UInt32 L_TRACKCOND;                            			// # 15	
	UInt32 M_TRACKCOND;                            			// # 4	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 D_TRACKCOND;                     		// # 15	
		UInt32 L_TRACKCOND;                     		// # 15	
		UInt32 M_TRACKCOND;                     		// # 4	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Track_Condition_Station_Platforms { 
// TransmissionMedia=Any
// The packet gives details concerning the location and height of station platforms for use by the train door control system

	UInt32 NID_PACKET;                     	// Packet =  69; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 Q_TRACKINIT;                            			// # 1		// if (Q_TRACKINIT == 1)
	UInt32 D_TRACKINIT;                            			// # 15		// Only if Q_TRACKINIT = 1	// if (Q_TRACKINIT == 0)
	UInt32 D_TRACKCOND;                            			// # 15		// Only if Q_TRACKINIT = 0D_TRACKCOND and the following variables follow
	UInt32 L_TRACKCOND;                            			// # 15	
	UInt32 M_PLATFORM;                             			// # 4	
	UInt32 Q_PLATFORM;                             			// # 2	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 D_TRACKCOND;                     		// # 15	
		UInt32 L_TRACKCOND;                     		// # 15	
		UInt32 M_PLATFORM;                      		// # 4	
		UInt32 Q_PLATFORM;                      		// # 2	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Route_Suitability_Data { 
// TransmissionMedia=Any
// The packet gives the characteristics needed to enter a route.

	UInt32 NID_PACKET;                     	// Packet =  70; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 Q_TRACKINIT;                            			// # 1		// if (Q_TRACKINIT == 1)
	UInt32 D_TRACKINIT;                            			// # 15		// Only if Q_TRACKINIT = 1	// if (Q_TRACKINIT == 0)
	UInt32 D_SUITABILITY;                          			// # 15		// Only If Q_TRACKINIT = 0D_SUITABILITY and the following variables follows
	UInt32 Q_SUITABILITY;                          			// # 2		// if (Q_SUITABILITY == 0)
	UInt32 M_LINEGAUGE;                            			// # 8		// If Q_SUITABILITY = 0 (loading gauge)	// if (Q_SUITABILITY == 1)
	UInt32 M_AXLELOADCAT;                          			// # 7		// If Q_SUITABILITY = 1 (Max axle load)	// if (Q_SUITABILITY == 2)
	UInt32 M_VOLTAGE;                              			// # 4		// If Q_SUITABILITY = 2 (traction system)	// if ((Q_SUITABILITY == 2) and (M_VOLTAGE != 0))
	UInt32 NID_CTRACTION;                          			// # 10		// If Q_SUITABILITY = 2 and M_VOLTAGE != 0    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 D_SUITABILITY;                   		// # 15	
		UInt32 Q_SUITABILITY;                   		// # 2		// if (Q_SUITABILITY(k) == 0)
		UInt32 M_LINEGAUGE;                     		// # 8		// If Q_SUITABILITY(k) = 0 (loading gauge)	// if (Q_SUITABILITY(k) == 1)
		UInt32 M_AXLELOADCAT;                   		// # 7		// If Q_SUITABILITY(k) = 1 (Max axle load)	// if (Q_SUITABILITY(k) == 2)
		UInt32 M_VOLTAGE;                       		// # 4		// If Q_SUITABILITY(k) = 2 ( traction system)	// if ((Q_SUITABILITY(k) == 2) and (M_VOLTAGE(k) != 0))
		UInt32 NID_CTRACTION;                   		// # 10		// If Q_SUITABILITY(k) = 2 and M_VOLTAGE(k) != 0        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Adhesion_factor { 
// TransmissionMedia=Any
// This packet is used when the trackside requests a change of the adhesion factor to be used in the brake model.

	UInt32 NID_PACKET;                     	// Packet =  71; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_ADHESION;                             			// # 15	
	UInt32 L_ADHESION;                             			// # 15	
	UInt32 M_ADHESION;                             			// # 1	
};
//=============================================

struct STRUCT_DATA_oETCS_Packet_for_sending_plain_text_messages { 
// TransmissionMedia=Balise, RBC

	UInt32 NID_PACKET;                     	// Packet =  72; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 Q_TEXTCLASS;                            			// # 2	
	UInt32 Q_TEXTDISPLAY;                          			// # 1		// Start/end events relation
	UInt32 D_TEXTDISPLAY;                          			// # 15		// Start event
		UInt32 M_MODETEXTDISPLAY[0];            		// # 4		// Start event
		UInt32 M_LEVELTEXTDISPLAY[0];           		// # 3		// Start event	// if (M_LEVELTEXTDISPLAY(0) == 1)
		UInt32 NID_NTC[0];                      		// # 8		// If M_LEVELTEXTDISPLAY(0) = 1
	UInt32 L_TEXTDISPLAY;                          			// # 15		// End event
	UInt32 T_TEXTDISPLAY;                          			// # 10		// End event
		UInt32 M_MODETEXTDISPLAY[1];            		// # 4		// End event
		UInt32 M_LEVELTEXTDISPLAY[1];           		// # 3		// End event	// if (M_LEVELTEXTDISPLAY(1) == 1)
		UInt32 NID_NTC[1];                      		// # 8		// If M_LEVELTEXTDISPLAY(1) = 1
	UInt32 Q_TEXTCONFIRM;                          			// # 2		// if (Q_TEXTCONFIRM != 0)
	UInt32 Q_CONFTEXTDISPLAY;                      			// # 1		// If Q_TEXTCONFIRM != 0
	UInt32 Q_TEXTREPORT;                           			// # 1		// If Q_TEXTCONFIRM != 0	// if (Q_TEXTREPORT == 1)
	UInt32 NID_TEXTMESSAGE;                        			// # 8		// Only If Q_TEXTREPORT = 1
	UInt32 NID_C;                                  			// # 10		// Only If Q_TEXTREPORT = 1
	UInt32 NID_RBC;                                			// # 14		// Only If Q_TEXTREPORT = 1
	UInt32 L_TEXT;                                 			// # 8	
	UInt32 X_TEXT;                                 			// # 8		// Length is L_TEXT
};
//=============================================

struct STRUCT_DATA_oETCS_Packet_for_sending_fixed_text_messages { 
// TransmissionMedia=Balise, RBC

	UInt32 NID_PACKET;                     	// Packet =  76; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 Q_TEXTCLASS;                            			// # 2	
	UInt32 Q_TEXTDISPLAY;                          			// # 1		// Start/end events relation
	UInt32 D_TEXTDISPLAY;                          			// # 15		// Start eventcondition
		UInt32 M_MODETEXTDISPLAY[0];            		// # 4		// Start event
		UInt32 M_LEVELTEXTDISPLAY[0];           		// # 3		// Start event	// if (M_LEVELTEXTDISPLAY(0) == 1)
		UInt32 NID_NTC[0];                      		// # 8		// If M_LEVELTEXTDISPLAY(0) = 1
	UInt32 L_TEXTDISPLAY;                          			// # 15		// End event
	UInt32 T_TEXTDISPLAY;                          			// # 10		// End event
		UInt32 M_MODETEXTDISPLAY[1];            		// # 4		// End event
		UInt32 M_LEVELTEXTDISPLAY[1];           		// # 3		// End event	// if (M_LEVELTEXTDISPLAY(1) == 1)
		UInt32 NID_NTC[1];                      		// # 8		// If M_LEVELTEXTDISPLAY(1) = 1
	UInt32 Q_TEXTCONFIRM;                          			// # 2		// if (Q_TEXTCONFIRM != 0)
	UInt32 Q_CONFTEXTDISPLAY;                      			// # 1		// If Q_TEXTCONFIRM != 0
	UInt32 Q_TEXTREPORT;                           			// # 1		// If Q_TEXTCONFIRM != 0	// if (Q_TEXTREPORT == 1)
	UInt32 NID_TEXTMESSAGE;                        			// # 8		// Only If Q_TEXTREPORT = 1
	UInt32 NID_C;                                  			// # 10		// Only If Q_TEXTREPORT = 1
	UInt32 NID_RBC;                                			// # 14		// Only If Q_TEXTREPORT = 1
	UInt32 Q_TEXT;                                 			// # 8	
};
//=============================================

struct STRUCT_DATA_oETCS_Geographical_Position_Information { 
// TransmissionMedia=Balise, RBC
// This packet gives geographical location information for one or multiple references to the train.

	UInt32 NID_PACKET;                     	// Packet =  79; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 Q_NEWCOUNTRY;                           			// # 1		// if (Q_NEWCOUNTRY == 1)
	UInt32 NID_C;                                  			// # 10		// if Q_NEWCOUNTRY = 1
	UInt32 NID_BG;                                 			// # 14		// Geographical Position Reference Balise Group
	UInt32 D_POSOFF;                               			// # 15	
	UInt32 Q_MPOSITION;                            			// # 1		// Geographical Position counting direction
	UInt32 M_POSITION;                             			// # 24		// Track kilometre reference value    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 Q_NEWCOUNTRY;                    		// # 1		// if (Q_NEWCOUNTRY(k) == 1)
		UInt32 NID_C;                           		// # 10		// if Q_NEWCOUNTRY(k) = 1
		UInt32 NID_BG;                          		// # 14		// Geographical Position Reference Balise Group
		UInt32 D_POSOFF;                        		// # 15	
		UInt32 Q_MPOSITION;                     		// # 1		// Geographical Position counting direction
		UInt32 M_POSITION;                      		// # 24		// Track kilometre reference value        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Mode_profile { 
// TransmissionMedia=Any
// Mode profile associated to an MA

	UInt32 NID_PACKET;                     	// Packet =  80; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_MAMODE;                               			// # 15	
	UInt32 M_MAMODE;                               			// # 2		// OS, LS, SH
	UInt32 V_MAMODE;                               			// # 7	
	UInt32 L_MAMODE;                               			// # 15	
	UInt32 L_ACKMAMODE;                            			// # 15	
	UInt32 Q_MAMODE;                               			// # 1	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 D_MAMODE;                        		// # 15	
		UInt32 M_MAMODE;                        		// # 2		// OS, LS, SH
		UInt32 V_MAMODE;                        		// # 7	
		UInt32 L_MAMODE;                        		// # 15	
		UInt32 L_ACKMAMODE;                     		// # 15	
		UInt32 Q_MAMODE;                        		// # 1	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Level_Crossing_information { 
// TransmissionMedia=Any
// Level Crossing information

	UInt32 NID_PACKET;                     	// Packet =  88; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 NID_LX;                                 			// # 8	
	UInt32 D_LX;                                   			// # 15	
	UInt32 L_LX;                                   			// # 15	
	UInt32 Q_LXSTATUS;                             			// # 1		// if (Q_LXSTATUS == 1)
	UInt32 V_LX;                                   			// # 7		// Only if Q_LXSTATUS = 1
	UInt32 Q_STOPLX;                               			// # 1		// Only if Q_LXSTATUS = 1	// if (Q_STOPLX == 1)
	UInt32 L_STOPLX;                               			// # 15		// Only if Q_STOPLX = 1
};
//=============================================

struct STRUCT_DATA_oETCS_Track_Ahead_Free_up_to_level_23_transition_location { 
// TransmissionMedia=Balise
// Notification to on-board that track ahead is free from the balise group transmitting this information up to the level 2/3 transition location

	UInt32 NID_PACKET;                     	// Packet =  90; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_NEWCOUNTRY;                           			// # 1		// if (Q_NEWCOUNTRY == 1)
	UInt32 NID_C;                                  			// # 10		// If Q_NEWCOUNTRY = 1
	UInt32 NID_BG;                                 			// # 14		// Level 2/3 transition location balise group
};
//=============================================

struct STRUCT_DATA_oETCS_RBC_transition_order { 
// TransmissionMedia=Balise, RBC
// Packet to order an RBC transition

	UInt32 NID_PACKET;                     	// Packet = 131; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_RBCTR;                                			// # 15	
	UInt32 NID_C;                                  			// # 10		// 'Accepting' RBC identity
	UInt32 NID_RBC;                                			// # 14	
	UInt32 NID_RADIO;                              			// # 64		// 'Accepting' RBC radio subscriber number
	UInt32 Q_SLEEPSESSION;                         			// # 1	
};
//=============================================

struct STRUCT_DATA_oETCS_Danger_for_Shunting_information { 
// TransmissionMedia=Balise
// Transmission of the aspect of a shunting signal

	UInt32 NID_PACKET;                     	// Packet = 132; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_ASPECT;                               			// # 1	
};
//=============================================

struct STRUCT_DATA_oETCS_Radio_infill_area_information { 
// TransmissionMedia=Balise

	UInt32 NID_PACKET;                     	// Packet = 133; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 Q_RIU;                                  			// # 1	
	UInt32 NID_C;                                  			// # 10		// RIU ETCS identity
	UInt32 NID_RIU;                                			// # 14	
	UInt32 NID_RADIO;                              			// # 64	
	UInt32 D_INFILL;                               			// # 15	
	UInt32 NID_BG;                                 			// # 14	
};
//=============================================

struct STRUCT_DATA_oETCS_EOLM_Packet { 
// TransmissionMedia=Balise
// This packet announces a loop.

	UInt32 NID_PACKET;                     	// Packet = 134; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 NID_LOOP;                               			// # 14	
	UInt32 D_LOOP;                                 			// # 15	
	UInt32 L_LOOP;                                 			// # 15	
	UInt32 Q_LOOPDIR;                              			// # 1	
	UInt32 Q_SSCODE;                               			// # 4	
};
//=============================================

struct STRUCT_DATA_oETCS_Stop_Shunting_on_desk_opening { 
// TransmissionMedia=Balise
// Packet to stop Shunting on desk opening.

	UInt32 NID_PACKET;                     	// Packet = 135; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
};
//=============================================

struct STRUCT_DATA_oETCS_Infill_location_reference { 
// TransmissionMedia=Balise, Loop, RIU
// Defines location reference for all data contained in the same radio message or balise/loop telegram respectively, following this packet.

	UInt32 NID_PACKET;                     	// Packet = 136; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_NEWCOUNTRY;                           			// # 1		// if (Q_NEWCOUNTRY == 1)
	UInt32 NID_C;                                  			// # 10		// If Q_NEWCOUNTRY = 1
	UInt32 NID_BG;                                 			// # 14	
};
//=============================================

struct STRUCT_DATA_oETCS_Stop_if_in_Staff_Responsible { 
// TransmissionMedia=Balise
// Information to stop a train in staff responsible.

	UInt32 NID_PACKET;                     	// Packet = 137; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SRSTOP;                               			// # 1	
};
//=============================================

struct STRUCT_DATA_oETCS_Reversing_area_information { 
// TransmissionMedia=Any
// Used to send start and length of reversing area to the on-board

	UInt32 NID_PACKET;                     	// Packet = 138; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_STARTREVERSE;                         			// # 15	
	UInt32 L_REVERSEAREA;                          			// # 15	
};
//=============================================

struct STRUCT_DATA_oETCS_Reversing_supervision_information { 
// TransmissionMedia=Any
// Used to send supervision parameters (distance to run, speed) of reversing area to the on-board

	UInt32 NID_PACKET;                     	// Packet = 139; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 D_REVERSE;                              			// # 15	
	UInt32 V_REVERSE;                              			// # 7	
};
//=============================================

struct STRUCT_DATA_oETCS_Train_running_number_from_RBC { 
// TransmissionMedia=RBC
// Train running number from RBC

	UInt32 NID_PACKET;                     	// Packet = 140; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 NID_OPERATIONAL;                        			// # 32	
};
//=============================================

struct STRUCT_DATA_oETCS_Default_Gradient_for_Temporary_Speed_Restriction { 
// TransmissionMedia=Balise
// It defines a default gradient to be used for TSR supervision when no gradient profile (packet 21) is available

	UInt32 NID_PACKET;                     	// Packet = 141; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_GDIR;                                 			// # 1		// 0 = downhill 1= uphill
	UInt32 G_TSR;                                  			// # 8	
};
//=============================================

struct STRUCT_DATA_oETCS_Session_Management_with_neighbouring_Radio_Infill_Unit { 
// TransmissionMedia=RIU
// Packet to give the identity and telephone number of the neighbouring Radio Infill Unit with which a session shall be established or terminated.

	UInt32 NID_PACKET;                     	// Packet = 143; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_RIU;                                  			// # 1	
	UInt32 NID_C;                                  			// # 10		// RIU ETCS identity
	UInt32 NID_RIU;                                			// # 14	
	UInt32 NID_RADIO;                              			// # 64	
};
//=============================================

struct STRUCT_DATA_oETCS_Inhibition_of_balise_group_message_consistency_reaction { 
// TransmissionMedia=Balise
// Indication to on-board that the balise group message consistency reaction (service brake command) can be inhibited for this balise group message only, in case one or more balise telegram(s) of the group is/are missed or is/are detected but not decoded.

	UInt32 NID_PACKET;                     	// Packet = 145; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
};
//=============================================

struct STRUCT_DATA_oETCS_Default_balise_or_Loop_or_RIU_information { 
// TransmissionMedia=Balise, Loop, RIU
// Indication to on-board that balise telegram, loop message or RIU information contains default information due to a fault of the trackside equipment.

	UInt32 NID_PACKET;                     	// Packet = 254; 		// # 8	
	UInt32 Q_DIR;                                  			// # 2	
	UInt32 L_PACKET;                               			// # 13	
};
//=============================================

struct STRUCT_DATA_oETCS_Position_Report { 
// TransmissionMedia=RBC, RIU
// This packet is used to report the train position and speed as well as some additional information (e.g. mode, level, etc.)

	UInt32 NID_PACKET;                     	// Packet =   0; 		// # 8	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 NID_LRBG;                               			// # 10+14	
	UInt32 D_LRBG;                                 			// # 15	
	UInt32 Q_DIRLRBG;                              			// # 2	
	UInt32 Q_DLRBG;                                			// # 2	
	UInt32 L_DOUBTOVER;                            			// # 15	
	UInt32 L_DOUBTUNDER;                           			// # 15	
	UInt32 Q_LENGTH;                               			// # 2		// if ((Q_LENGTH == 1) OR (Q_LENGTH == 2))
	UInt32 L_TRAININT;                             			// # 15		// If Q_LENGTH = 1 OR 2
	UInt32 V_TRAIN;                                			// # 7	
	UInt32 Q_DIRTRAIN;                             			// # 2	
	UInt32 M_MODE;                                 			// # 4	
	UInt32 M_LEVEL;                                			// # 3		// if (M_LEVEL == 1)
	UInt32 NID_NTC;                                			// # 8		// If M_LEVEL = 1
};
//=============================================

struct STRUCT_DATA_oETCS_Position_Report_based_on_two_balise_groups { 
// TransmissionMedia=RBC, RIU
// This packet is an extension of the 'standard position report ' packet 0. It is used in case of single balise groups if the orientation of the LRBG is unknown but the on-board equipment is able to report a second balise group (the one detected before) to give a direction reference for the directional information in the position report.

	UInt32 NID_PACKET;                     	// Packet =   1; 		// # 8	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 Q_SCALE;                                			// # 2	
	UInt32 NID_LRBG;                               			// # 10+14	
	UInt32 NID_PRVLRBG;                            			// # 10+14		// Used as reference for all directional information in the packet: a move from PRVLRBG towards the LRBG  defines the 'nominal' direction
	UInt32 D_LRBG;                                 			// # 15	
	UInt32 Q_DIRLRBG;                              			// # 2		// Train orientation according to reference direction
	UInt32 Q_DLRBG;                                			// # 2		// Train front position according to reference direction
	UInt32 L_DOUBTOVER;                            			// # 15	
	UInt32 L_DOUBTUNDER;                           			// # 15	
	UInt32 Q_LENGTH;                               			// # 2		// if ((Q_LENGTH == 1) OR (Q_LENGTH == 2))
	UInt32 L_TRAININT;                             			// # 15		// If Q_LENGTH = 1 OR 2
	UInt32 V_TRAIN;                                			// # 7	
	UInt32 Q_DIRTRAIN;                             			// # 2		// Actual running direction according to reference direction
	UInt32 M_MODE;                                 			// # 4	
	UInt32 M_LEVEL;                                			// # 3		// if (M_LEVEL == 1)
	UInt32 NID_NTC;                                			// # 8		// If M_LEVEL = 1
};
//=============================================

struct STRUCT_DATA_oETCS_Onboard_telephone_numbers { 
// TransmissionMedia=RBC, RIU
// Telephone numbers associated to the onboard equipment

	UInt32 NID_PACKET;                     	// Packet =   3; 		// # 8	
	UInt32 L_PACKET;                               			// # 13	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 NID_RADIO;                       		// # 64	        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Error_reporting { 
// TransmissionMedia=RBC
// Error reporting to the RBC

	UInt32 NID_PACKET;                     	// Packet =   4; 		// # 8	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 M_ERROR;                                			// # 8		// error type identifier
};
//=============================================

struct STRUCT_DATA_oETCS_Train_running_number { 
// TransmissionMedia=RBC
// Train running number

	UInt32 NID_PACKET;                     	// Packet =   5; 		// # 8	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 NID_OPERATIONAL;                        			// # 32	
};
//=============================================

struct STRUCT_DATA_oETCS_Level_23_transition_information { 
// TransmissionMedia=RBC
// Identity of the level 2/3 transition balise group

	UInt32 NID_PACKET;                     	// Packet =   9; 		// # 8	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 NID_LTRBG;                              			// # 10+14	
};
//=============================================

struct STRUCT_DATA_oETCS_Validated_train_data { 
// TransmissionMedia=RBC
// Validated train data.

	UInt32 NID_PACKET;                     	// Packet =  11; 		// # 8	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 NC_CDTRAIN;                             			// # 4	
	UInt32 NC_TRAIN;                               			// # 15	
	UInt32 L_TRAIN;                                			// # 12	
	UInt32 V_MAXTRAIN;                             			// # 7	
	UInt32 M_LOADINGGAUGE;                         			// # 8	
	UInt32 M_AXLELOADCAT;                          			// # 7	
	UInt32 M_AIRTIGHT;                             			// # 2	
	UInt32 N_AXLE;                                 			// # 10	    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 M_VOLTAGE;                       		// # 4		// Identity of the traction system	// if ((M_VOLTAGE(k) != 0) and (NID_CTRACTION(k) != 0))
		UInt32 NID_CTRACTION;                   		// # 10		// only if M_VOLTAGE(k) != 0 and NID_CTRACTION(k) != 0        
        } a_data[33];
        } m;
    
        struct {
            UInt32 used;                        //N_ITER+1              // # 5
            struct {

		UInt32 NID_NTC;                         		// # 8		// Type of National System available        
        } a_data[33];
        } m;

};
//=============================================

struct STRUCT_DATA_oETCS_Data_used_by_applications_outside_the_ERTMS_or_ETCS_system { 
// TransmissionMedia=RBC, RIU
// Messages between on-board and trackside devices, which contain information used by applications outside the ERTMS or ETCS system.

	UInt32 NID_PACKET;                     	// Packet =  44; 		// # 8	
	UInt32 L_PACKET;                               			// # 13	
	UInt32 NID_XUSER;                              			// # 9	
	UInt32 Other_data_depending_on__NID_XUSER;     			// # 	
};
//=============================================

struct STRUCT_DATA_oETCS_End_of_Information { 
// TransmissionMedia=Balise, Loop
// This packet consists only of NID_PACKET containing 8 bit 1sIt acts as a finish flag; the receiver will stop reading the remaining part of the message/telegram when receiving eight bits set to one in the NID_PACKET field.

	UInt32 NID_PACKET;                     	// Packet = 255; 		// # 8		// = 255 (1111 1111)
};
//=============================================
