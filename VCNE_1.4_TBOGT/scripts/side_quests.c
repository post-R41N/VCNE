/***********************************************************************
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
#include "globals.h"
int in_ambulance = 0;
int in_copcar = 0;
int in_firetrck = 0;
int in_taxi = 0;
int in_pizzaboy = 0;
int in_crazy = 0;
int in_sparrow = 0;
int in_bmx = 0;
int in_pcj = 0;
int in_topfun = 0;


void start_heli_mission(void)
{
	REQUEST_SCRIPT("heli");
	while (!HAS_SCRIPT_LOADED("heli")) WAIT(0);
	G_ONMISSION = 1;
	uint script = START_NEW_SCRIPT("heli", 1024);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED("heli");
	while (IS_THREAD_ACTIVE(script)) WAIT(0);
	G_ONMISSION = 0;
	WAIT(1000);
}

void init_side_mission_help(void)
{
	REQUEST_SCRIPT("side_quests_help");
	while (!HAS_SCRIPT_LOADED("side_quests_help")) WAIT(0);
	uint script = START_NEW_SCRIPT("side_quests_help", 1024);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED("side_quests_help");
    PRINT_STRING_WITH_LITERAL_STRING_NOW("String", "LOADING SIDE QUEST HELP SCRIPT", 3000, 1);
}

void main(void)
{
	WAIT(0);
	while (TRUE) 
	{
		WAIT(0);
		if (G_ONMISSION == 0)
		{
			//------------------- Побочка -------------------
			if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("ambulance")))
			{
				if (in_ambulance == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
                    init_side_mission_help();
					in_ambulance = 1;
				}
				if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER()))
				{
					REQUEST_SCRIPT("ambulance");
					while (!HAS_SCRIPT_LOADED("ambulance")) WAIT(0);
					G_ONMISSION = 1;
					uint script = START_NEW_SCRIPT("ambulance", 1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("ambulance");
					while (IS_THREAD_ACTIVE(script)) WAIT(0);
					G_ONMISSION = 0;
					WAIT(1000);
				}
			}
			else
			{
				if (in_ambulance == 1) in_ambulance = 0; 
			}

			if ((IS_CHAR_IN_ANY_POLICE_VEHICLE(GetPlayerPed())) || (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("annihilator"))) || (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("fbi"))))
			{ 
				if (in_copcar == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
                {
                    init_side_mission_help();
                    in_copcar = 1;
                }
				if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER()))
				{
					REQUEST_SCRIPT("vigilante");
					while (!HAS_SCRIPT_LOADED("vigilante")) WAIT(0);
					G_ONMISSION = 1;
					uint script = START_NEW_SCRIPT("vigilante", 1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("vigilante");
					while (IS_THREAD_ACTIVE(script)) WAIT(0);
					G_ONMISSION = 0;
					WAIT(1000);
				}
			}
			else
			{
				if (in_copcar == 1) in_copcar = 0;
			}

			if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("firetruk")))
			{
				if (in_firetrck == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
				    init_side_mission_help();
					in_firetrck = 1;
				}
				if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER()))
				{
					REQUEST_SCRIPT("firetruck");
					while (!HAS_SCRIPT_LOADED("firetruck")) WAIT(0);
					G_ONMISSION = 1;
					uint script = START_NEW_SCRIPT("firetruck", 1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("firetruck");
					while (IS_THREAD_ACTIVE(script)) WAIT(0);
					G_ONMISSION = 0;
					WAIT(1000);
				}
			}
			else
			{
				if (in_firetrck == 1) in_firetrck = 0;
			}

			if (IS_CHAR_IN_TAXI(GetPlayerPed()) || IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_ROM))
			{
				if (in_taxi == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
				    init_side_mission_help();
					in_taxi = 1;
				}
				if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER()))
				{
					REQUEST_SCRIPT("taxi");
					while (!HAS_SCRIPT_LOADED("taxi")) WAIT(0);
					G_ONMISSION = 1;
					uint script = START_NEW_SCRIPT("taxi", 1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("taxi");
					while (IS_THREAD_ACTIVE(script)) WAIT(0);
					G_ONMISSION = 0;
					WAIT(1000);
				}
			}
			else
			{
				if (in_taxi == 1) in_taxi = 0;
			}

			if (G_PIZZA == 0 && G_ONMISSION == 0 && IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("hellfury")))
			{
				if (IS_CHAR_IN_AREA_3D(GetPlayerPed(), -461.1, 1331.7, -4.0, -481.1, 1351.7, 16.0, 0) || IS_CHAR_IN_AREA_3D(GetPlayerPed(), -585.7, 611.6, -4.2, -605.7, 631.6, 16.2, 0) || IS_CHAR_IN_AREA_3D(GetPlayerPed(), 836.8, 620.7, -4.9, 856.8, 640.7, 15.9, 0))
				{
					if (in_pizzaboy == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
					{
                        init_side_mission_help();
                        in_pizzaboy = 1;
					}
                    if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER()))
				    {
						REQUEST_SCRIPT("pizza");
						while (!HAS_SCRIPT_LOADED("pizza")) WAIT(0);
						G_ONMISSION = 1;
						in_pizzaboy = 1;
						uint script = START_NEW_SCRIPT("pizza", 1024);
						MARK_SCRIPT_AS_NO_LONGER_NEEDED("pizza");
						while (IS_THREAD_ACTIVE(script)) WAIT(0);
						G_ONMISSION = 0;
						WAIT(1000);
				    }
				}
			}
			else
			{
				if (in_pizzaboy == 1) in_pizzaboy = 0;
			}

			if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("stalion")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 555.0, -610.0, 22.0, 567.0, -635.0, 28.0, 0) && G_ONMISSION == 0)
			{
				if (in_crazy == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
					init_side_mission_help();
					in_crazy = 1;
				}
				if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER()))
				{
					REQUEST_SCRIPT("conecrazy");
					while (!HAS_SCRIPT_LOADED("conecrazy")) WAIT(0);
					G_ONMISSION = 1;
					uint script = START_NEW_SCRIPT("conecrazy", 1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("conecrazy");
					while (IS_THREAD_ACTIVE(script)) WAIT(0);
					G_ONMISSION = 0;
					WAIT(1000);
				}
			}
			else
			{
				if (in_crazy == 1) in_crazy = 0;
			}

			//if ((IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow"))) && (LOCATE_CHAR_IN_CAR_3D(GetPlayerPed(), -136.1451, 1384.0923, 17.8402, 2.0, 2.0, 2.0, 0)) && (G_ONMISSION == 0))
            if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), -133.04, 1378.923, 16.791, -143.605, 1389.26, 21.791, 0) && G_ONMISSION == 0)
			{
                if (in_sparrow == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
                    init_side_mission_help();
					in_sparrow = 1;
				}
                if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER())) start_heli_mission();
			}
			//else if ((IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow"))) && (LOCATE_CHAR_IN_CAR_3D(GetPlayerPed(), 461.4463, -778.7614, 11.4712, 2.0, 2.0, 2.0, 0)) && (G_ONMISSION == 0))
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 464.551, -783.93, 10.537, 453.986, -773.594, 15.537, 0) && G_ONMISSION == 0)
			{
				if (in_sparrow == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
                    init_side_mission_help();
					in_sparrow = 1;
				}
                if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER())) start_heli_mission();
			}
			//else if ((IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow"))) && (LOCATE_CHAR_IN_CAR_3D(GetPlayerPed(), 808.8450, 865.9194, 6.5155, 2.0, 2.0, 2.0, 0)) && (G_ONMISSION == 0))
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 811.95, 860.75, 5.486, 801.385, 871.087, 10.486, 0) && G_ONMISSION == 0)
			{
				if (in_sparrow == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
                    init_side_mission_help();
					in_sparrow = 1;
				}
                if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER())) start_heli_mission();
			}
			//else if ((IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow"))) && (LOCATE_CHAR_IN_CAR_3D(GetPlayerPed(), -453.5938, 769.5693, 8.9773, 2.0, 2.0, 2.0, 0)) && (G_ONMISSION == 0))
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), -450.489, 764.4, 8.977, -461.054, 774.737, 13.977, 0) && G_ONMISSION == 0)
			{
				if (in_sparrow == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
                    init_side_mission_help();
					in_sparrow = 1;
				}
                if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER())) start_heli_mission();
			}
            else
			{
				if (in_sparrow == 1) in_sparrow = 0;
			}
            
			if (IS_CHAR_IN_AREA_3D(GetPlayerPed(), 3.0, 1938.0, 3.5, 13.0, 1948.0, 7.5, 0) && G_ONMISSION == 0)
			{
				if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sanchez")) || IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("landstalker")))
				{
					if (in_bmx == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
					{
                        init_side_mission_help();
						in_bmx = 1;
					}
					if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER()))
					{
						REQUEST_SCRIPT("bmx");
						while (!HAS_SCRIPT_LOADED("bmx")) WAIT(0);
						G_ONMISSION = 1;
						uint script = START_NEW_SCRIPT("bmx", 1024);
						MARK_SCRIPT_AS_NO_LONGER_NEEDED("bmx");
						while (IS_THREAD_ACTIVE(script)) WAIT(0);
						G_ONMISSION = 0;
						WAIT(1000);
					}
				}
				else
				{
					if (in_bmx == 1) in_bmx = 0;
				}
			}
			else
			{
				if (in_bmx == 1) in_bmx = 0;
			}

			if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("pcj")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 937.4, 222.8, 7.0, 943.4, 228.8, 9.0, 0) && G_ONMISSION == 0)
			{
				if (in_pcj == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
					init_side_mission_help();
					in_pcj = 1;
				}
				if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER()))
				{
					REQUEST_SCRIPT("pcj");
					while (!HAS_SCRIPT_LOADED("pcj")) WAIT(0);
					G_ONMISSION = 1;
					uint script = START_NEW_SCRIPT("pcj", 1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("pcj");
					while (IS_THREAD_ACTIVE(script)) WAIT(0);
					G_ONMISSION = 0;
					WAIT(1000);
				}
			}
			else
			{
				if (in_pcj == 1) in_pcj = 0;
			}

			if (IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_SPEEDO) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 1165.666, 1220.26, 7.0, 1159.666, 1230.26, 12.0, 0) && G_ONMISSION == 0)
			{
				if (in_topfun == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
                    init_side_mission_help();
					in_topfun = 1;
				}
				if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER()))
				{
					REQUEST_SCRIPT("rcrace");
					while (!HAS_SCRIPT_LOADED("rcrace")) WAIT(0);
					G_ONMISSION = 1;
					uint script = START_NEW_SCRIPT("rcrace", 1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("rcrace");
					while (IS_THREAD_ACTIVE(script)) WAIT(0);
					G_ONMISSION = 0;
					WAIT(1000);
				}
			}
			else if (IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_SPEEDO) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), -797.529, -697.733, 8.282, -803.539, -705.255, 12.979, 0) && G_ONMISSION == 0)
			{
				if (in_topfun == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
					init_side_mission_help();
					in_topfun = 1;
				}
				if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER()))
				{
					REQUEST_SCRIPT("rcheli");
					while (!HAS_SCRIPT_LOADED("rcheli")) WAIT(0);
					G_ONMISSION = 1;
					uint script = START_NEW_SCRIPT("rcheli", 1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("rcheli");
					while (IS_THREAD_ACTIVE(script)) WAIT(0);
					G_ONMISSION = 0;
					WAIT(1000);
				}
			}
			else if (IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_SPEEDO) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 744.676, 1780.595, 21.0, 737.676, 1790.595, 27.0, 0) && G_ONMISSION == 0)
			{
				if (in_topfun == 0 && !HAS_SCRIPT_LOADED("side_quests_help"))
				{
                    init_side_mission_help();
					in_topfun = 1;
				}
				if ((IS_CONTROL_PRESSED(2, 23) && !IS_USING_CONTROLLER()) || (IS_BUTTON_PRESSED(0, 4) && IS_BUTTON_PRESSED(0, 6) && IS_USING_CONTROLLER()))
				{
					REQUEST_SCRIPT("rcplne");
					while (!HAS_SCRIPT_LOADED("rcplne")) WAIT(0);
					G_ONMISSION = 1;
					uint script = START_NEW_SCRIPT("rcplne", 1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("rcplne");
					while (IS_THREAD_ACTIVE(script)) WAIT(0);
					G_ONMISSION = 0;
					WAIT(1000);
				}
			}
			else
			{
				if (in_topfun == 1) in_topfun = 0;
			}
		}
	}
}