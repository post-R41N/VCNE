/***********************************************************************
			Fully stripped startup script
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
#include "globals.h"
#include "vcneFunctionLibrary.h"
uint g_alt;
uint isOn;
Cam introCam;

void main(void)
{   
    Blip ice_ico; 
    isOn = false;
    g_alt = 0;
    bool firstTick = true;
    Ped ped1, ped2;
    float px, py, pz;
    while (true)
    {
        if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(28))
        {
            PLAY_AUDIO_EVENT( "FRONTEND_OTHER_RACE_321" );
                
            //GET_CHAR_COORDINATES(GetPlayerPed(), &px, &py, &pz);
            //GET_RANDOM_CHAR_IN_AREA_OFFSET_NO_SAVE(px, py, pz, 20.0, 20.0, 20.0, &ped1);
            //GET_RANDOM_CHAR_IN_AREA_OFFSET_NO_SAVE(px, py, pz, 20.0, 20.0, 20.0, &ped2);
            //TASK_CHAR_ARREST_CHAR(ped1, ped2);  
                
            if (firstTick)
            {
                g_alt = 1;    
                firstTick = false;
            }     
        }
        if (g_alt == 1)
        {
            DISPLAY_ALTIMETER_THIS_FRAME();
            //PRINT_HELP_FOREVER("LAW1_HELP_1");
        }
    }					
}