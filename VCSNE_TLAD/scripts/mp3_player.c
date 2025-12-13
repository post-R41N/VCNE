/***********************************************************************
			Fully stripped startup script
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

int isHelpTrackDir = 0, isHelpTrackRoll = 0;

int isHelpsDisplayedYet()
{
    if (isHelpTrackDir == 1 && isHelpTrackRoll == 1) return 1;
    return 0;
}

void main(void)
{
    char* radio_mp3 = "INDEPENDENT";
    char* radio_off = "OFF";
    char* radio_buf;

    THIS_SCRIPT_SHOULD_BE_SAVED();
    while (TRUE)
    {
        WAIT(0);
        if (isHelpsDisplayedYet() == 1) TERMINATE_THIS_SCRIPT();//Уничтожаем следующий код, если подсказки уже были получены однажды
        if (!GET_MISSION_FLAG())
        {
	       if (IS_RADIO_HUD_ON())
	       {
                radio_buf = GET_PLAYER_RADIO_STATION_NAME_ROLL();
                if (COMPARE_STRING(radio_buf, radio_off) == 0)//Узнаем является ли текущее радио - выключенным посредством сравнения названий радио
                {
                    if (COMPARE_STRING(radio_buf, radio_mp3) == 1)//Узнаем является ли текущее радио - МП3 посредством сравнения названий радио
                    {
                        if (!IS_HELP_MESSAGE_BEING_DISPLAYED())
                        {
                            CLEAR_HELP();
                            if (GET_PLAYER_HAS_TRACKS())
                            {
                                if (GET_PLAYER_RADIO_MODE() != 0 && isHelpTrackRoll == 0)//Если режим радио МП3 не "радио" и подсказка еще не была получена
                                {
                                    PRINT_HELP("ME_INFM_TUT5");//Подсказка о переключении треков
                                    isHelpTrackRoll++;
                                }
                            }
                            else if (isHelpTrackDir < 1)//Если треков на МП3-Плеере нет, то выводим подсказку о том куда кидать треки
                            {
                                PRINT_HELP("ME_IND_FM_TUT1");//Подсказка о директории пользовательских треков
                                isHelpTrackDir++;
                            }
                        }
                    }
                }
            }
        }   
    }
    return;
}