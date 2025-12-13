/***********************************************************************
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
#include "globals.h"
uint ambhelp;

void SetTime(uint time)
{
	SETTIMERA( 0 );
	while(true)
	{
		WAIT(0);
		if (TIMERA() > time)
		{
			break;
		}
	}
}

void main()
{
    THIS_SCRIPT_SHOULD_BE_SAVED();
    while (TRUE)
    {
        if (ambhelp < 3)
        {
            LOAD_ADDITIONAL_TEXT("ROMAN1", 6);
            if (IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed()))
            {
                if (ambhelp == 0)
                {
       	            SetTime(500);
                    PRINT_HELP_FOREVER("HELP4"); //To accelerate press W.
                    SetTime(3000);
                    CLEAR_HELP(); // удаляем текст подсказки
                    ambhelp = 1;
                }
                if (ambhelp == 1)
                {
   	                SetTime(3000);
                    PRINT_HELP_FOREVER("HELP1"); //To steer vehicle press A/D.
                    SetTime(3000);
                    CLEAR_HELP(); // удаляем текст подсказки
                    ambhelp = 2;
                }
                if (ambhelp == 2)
                {
   	                SetTime(3000);
                    if (IS_USING_CONTROLLER()) PRINT_HELP_FOREVER("HELP5"); //Press A/X to use handbrake for gamepads.
                    else PRINT_HELP_FOREVER("HBRAKE_PC");//Press Space to use handbrake for PC.
                    SetTime(3000);
                    CLEAR_HELP(); // удаляем текст подсказки
                    ambhelp = 3;
                }
            }
        }
    }
}