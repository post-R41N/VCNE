/***********************************************************************
	This file is a part of scocl project by Alexander Blade (c) 2011
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
#include "globals.h"

uint helpVeh, helpOnFoot, helpWanted;
uint wanted;

void SetTime(uint time)
{
	SETTIMERA(0);
	while (true)
	{
		WAIT(0);
		if (TIMERA() > time)
		{
			break;
		}
	}
}

void HelpsAfterIntro(void)
{
    Cam camera;
    if (!IS_HELP_MESSAGE_BEING_DISPLAYED())
    {
        if (helpOnFoot == 0)
        {
            while (TRUE)
            {
                WAIT(0);
                if (IS_CHAR_IN_AREA_3D(GetPlayerPed(), 662.581, -750.27, 5.496, 667.581, -740.27, 10.496, 0))
                {
                    SET_PLAYER_CONTROL_ADVANCED(GetPlayerIndex(), 0, 0, 0);//замораживаем игрока
                    CREATE_CAM(14, &camera);
                    POINT_CAM_AT_COORD(camera, 679.021, -723.314, 5.507); // куда смотрит камера
                    SET_CAM_POS(camera, 690.751, -711.325, 9.127);//расположение камеры
                    SET_CAM_ACTIVE(camera, 1);
                    SET_CAM_PROPAGATE(camera, 1);
                    ACTIVATE_SCRIPTED_CAMS(1, 1);
                    SET_CAM_FOV(camera, 45.0);
                    SET_WIDESCREEN_BORDERS(1);

                    PRINT_HELP_FOREVER("CARSAVE");  // You can save any vehicle in the parking spot outside your safehouse. Park your car there and exit it. The car will remain there for you to use.
                    SetTime(5000);
                    if (IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("CARSAVE")) CLEAR_HELP();
                    SET_CAM_BEHIND_PED(GetPlayerPed());
                    ACTIVATE_SCRIPTED_CAMS(0, 0);
                    DESTROY_CAM(camera);
                    SET_WIDESCREEN_BORDERS(0);
                    SET_PLAYER_CONTROL_ADVANCED(GetPlayerIndex(), 1, 1, 1);//размораживаем игрока
                    CLEAR_HELP();// удаляем текст подсказки
                    helpOnFoot = 1;
                    break;
                }
                else if (!IS_CHAR_IN_AREA_3D(GetPlayerPed(), 627.417, -777.408, 3.332, 677.166, -710.844, 40.07, 0))
                {
                    break;
                }
            }
        }
        else if (helpOnFoot == 1)
        {
            PRINT_HELP_FOREVER("CLOTH2"); //Street outfit delivered to Safehouses.
            SetTime(5000);
            CLEAR_HELP();// удаляем текст подсказки
            helpOnFoot = 2;
        }
        else if (helpOnFoot == 2)
        {
            PRINT_HELP_FOREVER("HELP14"); // To find the Lawyer's office, follow the ~h~L blip~w~ on the radar
            G_FLASH_BLIP = 1;
            SetTime(6500);
            CLEAR_HELP();// удаляем текст подсказки
            G_FLASH_BLIP = 0;
            helpOnFoot = 3;
        }
        else if (helpOnFoot == 3)
        {
            PRINT_HELP_FOREVER("HEALTH"); //Help about health and armour bar around a radar circuit
            FLASH_RADAR(1);//Мигание радара
            SetTime(5000);
            FLASH_RADAR(0);//Отключение мигания радара
            SetTime(5000);
            CLEAR_HELP();// удаляем текст подсказки
            helpOnFoot = 4;
        }
        else if (helpOnFoot == 4)
        {
            if (IS_CHAR_ON_FOOT(GetPlayerPed()))
            {
                if (IS_USING_CONTROLLER()) PRINT_HELP_FOREVER("RUNKEY"); //Taping A/X to srpint for gamepads.
                else PRINT_HELP_FOREVER("B3_SPRINT_PC");//Press LShift to sprint for PC.
                SetTime(5000);
                CLEAR_HELP();// удаляем текст подсказки
                helpOnFoot = 5;
            }
        }
    }
}

void HelpsCarControls(void)
{
	if (IS_CHAR_IN_ANY_CAR(GetPlayerPed()) && !IS_CHAR_IN_ANY_BOAT(GetPlayerPed()) && !IS_CHAR_IN_ANY_HELI(GetPlayerPed()))
	{
        if (!IS_HELP_MESSAGE_BEING_DISPLAYED())
        {
            if (helpVeh == 0)
            {
                PRINT_HELP_FOREVER("HELP_NE_1"); //To accelerate press W.
                SetTime(6500);
                CLEAR_HELP();// удаляем текст подсказки
                helpVeh = 1;
            }
            else if (helpVeh == 1)
            {
                PRINT_HELP_FOREVER("HELP_NE_2"); //To steer vehicle press A/D.
                SetTime(6500);
                CLEAR_HELP();// удаляем текст подсказки
                helpVeh = 2;
            }
            else if (helpVeh == 2)
            {
                PRINT_HELP_FOREVER("INT_A_HELP_1");//~s~While in a vehicle the colored line on the radar shows the shortest legal route
                SetTime(6500);
                CLEAR_HELP();// удаляем текст подсказки
                helpVeh = 3;
            }
            else if (helpVeh == 3)
            {
                if (IS_USING_CONTROLLER()) PRINT_HELP_FOREVER("HELP5"); //Press A/X to use handbrake for gamepads.
                else PRINT_HELP_FOREVER("HBRAKE_PC");//Press Space to use handbrake for PC.
                SetTime(6500);
                CLEAR_HELP();// удаляем текст подсказки
                helpVeh = 4;
            }
            else if (helpVeh == 4)
            {
                PRINT_HELP_FOREVER("DIPPED"); //Press H to swtich headlights between full beam and dimmed.
                SetTime(6500);
                CLEAR_HELP();// удаляем текст подсказки
                helpVeh = 5;
            }
            else if (helpVeh == 5)
            {
                PRINT_HELP_FOREVER("CARDIVE"); //Press F to dive out of car.
                SetTime(6500);
                CLEAR_HELP();// удаляем текст подсказки
                helpVeh = 6;
            }
            else if (helpVeh == 6 && G_LAWYER > 1)
            {
                PRINT_HELP_FOREVER("CARCAMS");//Change camera view help
                SetTime(6500);
                CLEAR_HELP();// удаляем текст подсказки
                helpVeh = 7;
            }
        }
	}
}

void HelpWanted(void)
{
    if (IS_WANTED_LEVEL_GREATER(GetPlayerIndex(), 0) && helpWanted == 0) helpWanted = 1;//Если у персонажа есть уровень розыска, то начинаем цепочку подсказок по поводу розыска
    if (!IS_HELP_MESSAGE_BEING_DISPLAYED())
    {
        if (helpWanted == 1)
        {
            PRINT_HELP_FOREVER("WANTED1");
            SetTime(6500);
            CLEAR_HELP();// удаляем текст подсказки
            helpWanted = 2;
        }
        else if (helpWanted == 2)
        {
            PRINT_HELP_FOREVER("WANTED2");
            SetTime(6500);
            CLEAR_HELP();// удаляем текст подсказки
            helpWanted = 3;
        }
        else if (helpWanted == 3)
        {
            PRINT_HELP_FOREVER("WANTED3");
            SetTime(6500);
            CLEAR_HELP();// удаляем текст подсказки
            helpWanted = 4;
        }
        else if (helpWanted == 4)
        {
            PRINT_HELP_FOREVER("WANTED4");
            SetTime(6500);
            CLEAR_HELP();// удаляем текст подсказки
            helpWanted = 5;
        }
        else if (helpWanted == 5 && WANTED_STARS_ARE_FLASHING())
        {
            PRINT_HELP_FOREVER("GREYSTARS");
            SetTime(6500);
            CLEAR_HELP();// удаляем текст подсказки
            helpWanted = 6;
        }
    }
}

void DrawGlobals(void)
{
	DISPLAY_TEXT_WITH_FLOAT(0.5, 0.5, "NUMBER", G_HELP, 1);
	DISPLAY_TEXT_WITH_FLOAT(0.5, 0.7, "NUMBER", helpVeh, 1);
    DISPLAY_TEXT_WITH_FLOAT(0.5, 0.7, "NUMBER", helpWanted, 1);
}

void main(void)
{
	THIS_SCRIPT_SHOULD_BE_SAVED();
	helpVeh = 0;
	helpOnFoot = 0;
    helpWanted = 0;
	while (TRUE)
	{
		WAIT(0);
        //DrawGlobals();
        if (G_HELP > 0 && helpVeh < 7 && (helpWanted == 0 || helpWanted > 4)) HelpsCarControls();
		if (G_HELP > 0 && G_LAWYER > 0 && helpOnFoot < 5 && (helpWanted == 0 || helpWanted > 4)) HelpsAfterIntro();
        if (G_HELP > 0 && G_LAWYER > 0 && helpWanted < 6) HelpWanted();
	}
}