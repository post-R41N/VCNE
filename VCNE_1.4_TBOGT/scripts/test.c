/***********************************************************************
			Fully stripped startup script
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
int radioID;
void main(void)
{
    radioID = 0;
    //THIS_SCRIPT_SHOULD_BE_SAVED();
    while (TRUE)
    {
  		if (IS_GAME_KEYBOARD_KEY_JUST_PRESSED(28))
		{
			PRINT_WITH_NUMBER_NOW("STRING", radioID, 1000, 1);
            WAIT(1000);
            PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "TEST_STRING", 1000, 1);
		}
		
        /*
        if (!GET_MISSION_FLAG())
        {
            if (IS_RADIO_HUD_ON())
            {
                if (IS_CHAR_SITTING_IN_ANY_CAR(GetPlayerPed()))
                {
                    radioID = GET_PLAYER_RADIO_STATION_INDEX();
                    //Get
                    //if (GET_PLAYER_RADIO_STATION_INDEX() == 22)
                    //{
                    //}
                    //else PRINT_STRING_WITH_LITERAL_STRING_NOW("String", "Не мп3 плеер", 5000, 1);
                    PRINT_WITH_NUMBER_NOW("STRING", radioID, 1000, 1);
                }   
            }
        }
        */
    }
}