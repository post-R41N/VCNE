/***********************************************************************
    This file is a part of scocl project by Alexander Blade (c) 2011
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
#include "globals.h"

uint helpState;

void HelpAmbulance(void)
{   
    if (!IS_HELP_MESSAGE_BEING_DISPLAYED())
    {
        if (helpState == 0)
        {
            SETTIMERA(0);
            WAIT(0);
            while (TRUE)
            {
                WAIT(0);
                if (TIMERA() > 5000 || G_ONMISSION == 1 || IS_CHAR_DEAD(GetPlayerPed()) || HAS_CHAR_BEEN_ARRESTED(GetPlayerPed()) || !IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
                {
                    CLEAR_HELP();// удаляем текст подсказки
                    helpState = 1;
                    break;
                }
                else
                {
                    if (IS_USING_CONTROLLER() && !IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("ATUTOR_PAD")) PRINT_HELP_FOREVER("ATUTOR_PAD");//Press L1+R1 to toggle on/off Paramedic mission on Gamepad.
                    if (!IS_USING_CONTROLLER() && !IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("ATUTOR")) PRINT_HELP_FOREVER("ATUTOR");//Press E to toggle on/off Paramedic mission on Keyboard.
                }
            }
        }
    }
}

void HelpVigilante(void)
{   
    if (!IS_HELP_MESSAGE_BEING_DISPLAYED())
    {
        if (helpState == 0)
        {
            SETTIMERA(0);
            WAIT(0);
            while (TRUE)
            {
                WAIT(0);
                if (TIMERA() > 5000 || G_ONMISSION == 1 || IS_CHAR_DEAD(GetPlayerPed()) || HAS_CHAR_BEEN_ARRESTED(GetPlayerPed()) || !IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
                {
                    CLEAR_HELP();// удаляем текст подсказки
                    helpState = 1;
                    break;
                }
                else
                {
                    if (IS_USING_CONTROLLER() && !IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("CTUTOR_PAD")) PRINT_HELP_FOREVER("CTUTOR_PAD");//Press L1+R1 to toggle on/off Vigilante mission on Gamepad.
                    if (!IS_USING_CONTROLLER() && !IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("CTUTOR")) PRINT_HELP_FOREVER("CTUTOR");//Press E to toggle on/off Vigilante mission on Keyboard.
                }
            }
        }
    }
}

void HelpFireTruck(void)
{   
    if (!IS_HELP_MESSAGE_BEING_DISPLAYED())
    {
        if (helpState == 0)
        {
            SETTIMERA(0);
            WAIT(0);
            while (TRUE)
            {
                WAIT(0);
                if (TIMERA() > 5000 || G_ONMISSION == 1 || IS_CHAR_DEAD(GetPlayerPed()) || HAS_CHAR_BEEN_ARRESTED(GetPlayerPed()) || !IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
                {
                    CLEAR_HELP();// удаляем текст подсказки
                    helpState = 1;
                    break;
                }
                else
                {
                    if (IS_USING_CONTROLLER() && !IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("FTUTOR_PAD")) PRINT_HELP_FOREVER("FTUTOR_PAD");//Press L1+R1 to toggle on/off Fire Truck mission on Gamepad.
                    if (!IS_USING_CONTROLLER() && !IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("FTUTOR")) PRINT_HELP_FOREVER("FTUTOR");//Press E to toggle on/off Fire Truck mission on Keyboard.
                }
            }
        }
    }
}

void HelpTaxi(void)
{   
    if (!IS_HELP_MESSAGE_BEING_DISPLAYED())
    {
        if (helpState == 0)
        {
            SETTIMERA(0);
            WAIT(0);
            while (TRUE)
            {
                WAIT(0);
                if (TIMERA() > 5000 || G_ONMISSION == 1 || IS_CHAR_DEAD(GetPlayerPed()) || HAS_CHAR_BEEN_ARRESTED(GetPlayerPed()) || !IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
                {
                    CLEAR_HELP();// удаляем текст подсказки
                    helpState = 1;
                    break;
                }
                else
                {
                    if (IS_USING_CONTROLLER() && !IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("TTUTOR_PAD")) PRINT_HELP_FOREVER("TTUTOR_PAD");//Press L1+R1 to toggle on/off Fire Truck mission on Gamepad.
                    if (!IS_USING_CONTROLLER() && !IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("TTUTOR")) PRINT_HELP_FOREVER("TTUTOR");//Press E to toggle on/off Fire Truck mission on Keyboard.
                }
            }
        }
    }
}

void HelpRegularSideMission(void)
{   
    if (!IS_HELP_MESSAGE_BEING_DISPLAYED())
    {
        if (helpState == 0)
        {
            SETTIMERA(0);
            WAIT(0);
            while (TRUE)
            {
                WAIT(0);
                if (TIMERA() > 5000 || G_ONMISSION == 1 || IS_CHAR_DEAD(GetPlayerPed()) || HAS_CHAR_BEEN_ARRESTED(GetPlayerPed()) || !IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
                {
                    CLEAR_HELP();// удаляем текст подсказки
                    helpState = 1;
                    break;
                }
                else
                {
                    if (IS_USING_CONTROLLER() && !IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("NEHELP2_PAD")) PRINT_HELP_FOREVER("NEHELP2_PAD");//Press L1+R1 to activate mission on Gamepad.
                    if (!IS_USING_CONTROLLER() && !IS_THIS_HELP_MESSAGE_BEING_DISPLAYED("NEHELP2")) PRINT_HELP_FOREVER("NEHELP2");//Press E to activate mission on Keyboard.
                }
            }
        }
    }
}

void DrawVariable(void)
{
    DISPLAY_TEXT_WITH_NUMBER(0.5, 0.5, "NUMBER", helpState);
}

void main(void)
{
    while (TRUE)
    {
        WAIT(0);
        DrawVariable();
        if (G_ONMISSION == 0 && !IS_CHAR_DEAD(GetPlayerPed()) && !HAS_CHAR_BEEN_ARRESTED(GetPlayerPed()))
        {
            if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("ambulance"))) HelpAmbulance();//Ambulance Help Message
            else if (IS_CHAR_IN_ANY_POLICE_VEHICLE(GetPlayerPed()) || IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("annihilator")) || IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("fbi"))) HelpVigilante();//Vigilante Help Message
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("firetruk"))) HelpFireTruck();//Fire Truck Help Message
            else if (IS_CHAR_IN_TAXI(GetPlayerPed()) || IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_ROM)) HelpTaxi();//Taxi Help Message
            else if (G_PIZZA == 0 && IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("hellfury")) &&
                    (IS_CHAR_IN_AREA_3D(GetPlayerPed(), -461.1, 1331.7, -4.0, -481.1, 1351.7, 16.0, 0) ||
                    IS_CHAR_IN_AREA_3D(GetPlayerPed(), -585.7, 611.6, -4.2, -605.7, 631.6, 16.2, 0) ||
                    IS_CHAR_IN_AREA_3D(GetPlayerPed(), 836.8, 620.7, -4.9, 856.8, 640.7, 15.9, 0))) HelpRegularSideMission();//Help Message for Pizzaboy
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("stalion")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 555.0, -610.0, 22.0, 567.0, -635.0, 28.0, 0)) HelpRegularSideMission();//Help Message for Cone Crazy
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), -133.04, 1378.923, 16.791, -143.605, 1389.26, 21.791, 0)) HelpRegularSideMission();//Help Message for Chopper Checkpoint at Downtown
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 464.551, -783.93, 10.537, 453.986, -773.594, 15.537, 0)) HelpRegularSideMission();//Help Message for Chopper Checkpoint at Ocean Beach 
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 811.95, 860.75, 5.486, 801.385, 871.087, 10.486, 0)) HelpRegularSideMission();//Help Message for Chopper Checkpoint at Vice Point
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sparrow")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), -450.489, 764.4, 8.977, -461.054, 774.737, 13.977, 0)) HelpRegularSideMission();//Help Message for Chopper Checkpoint at Little Haiti
            else if (IS_CHAR_IN_AREA_3D(GetPlayerPed(), 3.0, 1938.0, 3.5, 13.0, 1948.0, 7.5, 0) && 
            (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("sanchez")) ||
             IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("landstalker")))) HelpRegularSideMission();//Help Message for Trial by Drit/Test Track
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), GET_HASH_KEY("pcj")) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 937.4, 222.8, 7.0, 943.4, 228.8, 9.0, 0)) HelpRegularSideMission();//Help Message for PCJ Playground
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_SPEEDO) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 1165.666, 1220.26, 7.0, 1159.666, 1230.26, 12.0, 0)) HelpRegularSideMission();//Help Message for RC Bandit Race
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_SPEEDO) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), -797.529, -697.733, 8.282, -803.539, -705.255, 12.979, 0)) HelpRegularSideMission();//Help Message for RC Raider Pickup
            else if (IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_SPEEDO) && IS_CHAR_IN_AREA_3D(GetPlayerPed(), 744.676, 1780.595, 21.0, 737.676, 1790.595, 27.0, 0)) HelpRegularSideMission();//Help Message for RC Goblin Race
            else 
            {
                if (helpState == 1) helpState = 0;
            }
        }
    }
}