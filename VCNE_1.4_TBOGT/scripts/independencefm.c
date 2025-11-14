/***********************************************************************
			Fully stripped startup script
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>


void main(void)
{
    //THIS_SCRIPT_SHOULD_BE_SAVED();
    while (TRUE)
    {
        if (!GET_MISSION_FLAG())
        {
            if (IS_RADIO_HUD_ON())
            {
                if (IS_CHAR_SITTING_IN_ANY_CAR())
                {
                    if ( GET_PLAYER_RADIO_STATION_NAME() == "INDEPENDENT")
                    {
                        if (!IS_HELP_MESSAGE_BEING_DISPLAYED())
                        {
                            CLEAR_HELP();
                            if (GET_PLAYER_HAS_TRACKS())
                            {
                                if (GET_PLAYER_RADIO_MODE() != 0) PRINT_HELP("ME_INFM_TUT5");
                            }
                            else PRINT_HELP("ME_IND_FM_TUT1");
                            WAIT(0);
                        }
                    }
                }   
            }
        }
    }
}
