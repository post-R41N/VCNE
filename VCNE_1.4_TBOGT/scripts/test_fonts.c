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
void main(void)
{   
    Blip ice_ico; 
    g_alt = 0;
    bool firstTick = true;
    while (true)
    {
        if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(28))
        {
            //DrawText("MISSION_PASSED", 1, true, 5000);//Вызываем строчку Миссия пройдена(тип строки 1)
            //PLAY_AUDIO_EVENT( "FRONTEND_OTHER_RACE_321" );      
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