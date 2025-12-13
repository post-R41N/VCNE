/***********************************************************************
					Fully stripped main script
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

void Superman(void)
{
	Ped ped = GetPlayerPed();
	if (ped > 0)
	{
		Player pid = GetPlayerIndex();
		SET_PLAYER_INVINCIBLE(pid, TRUE);
		SET_PLAYER_NEVER_GETS_TIRED(pid, TRUE);
		SET_PLAYER_FAST_RELOAD(pid, TRUE);
		ENABLE_MAX_AMMO_CAP(FALSE);
		UpdateWeaponOfPed(ped, WEAPON_KNIFE);
		UpdateWeaponOfPed(ped, WEAPON_MOLOTOV);
		UpdateWeaponOfPed(ped, WEAPON_DEAGLE);
		UpdateWeaponOfPed(ped, WEAPON_SHOTGUN);
		UpdateWeaponOfPed(ped, WEAPON_MP5);
		UpdateWeaponOfPed(ped, WEAPON_AK47);						
	}
}

void CreateScript(char* name)
{
	REQUEST_SCRIPT(name);
	while (!HAS_SCRIPT_LOADED(name)) WAIT(0);
	uint script = START_NEW_SCRIPT(name, 1024);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED(name);
}

void InitScriptLauncher(void)
{
	CreateScript("loader_script");
}

void main(void)
{
	//int inVideoEditor = 0;
	FORCE_LOADING_SCREEN(TRUE);
	float x = 42.207, y = -40.7841, z = 35.0114;
	THIS_SCRIPT_SHOULD_BE_SAVED();
	SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(TRUE);
	SET_CAR_DENSITY_MULTIPLIER(1.0);
	SET_MAX_WANTED_LEVEL(6);
	SET_PLAYER_CONTROL(GetPlayerIndex(), TRUE);
	LOAD_SCENE(x, y, z);
	SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), x, y, z);
	SET_CHAR_HEADING(GetPlayerPed(), 180.0);
	ADD_HOSPITAL_RESTART(x, y, z, 5000.0, 0);
	ADD_HOSPITAL_RESTART(x, y, z, 5000.0, 1);
	ADD_HOSPITAL_RESTART(x, y, z, 5000.0, 2);
	ADD_POLICE_RESTART(x, y, z, 5000.0, 0);
	ADD_POLICE_RESTART(x, y, z, 5000.0, 1);
	ADD_POLICE_RESTART(x, y, z, 5000.0, 2);
	RELEASE_WEATHER();
	RELEASE_TIME_OF_DAY();
	WAIT(2000);
	FORCE_LOADING_SCREEN(FALSE);
	DO_SCREEN_FADE_IN_UNHACKED(4000);

	Superman();

	InitScriptLauncher();
	UNLOCK_LAZLOW_STATION();

	LOAD_ADDITIONAL_TEXT("STRPLDR", 6);
	while (TRUE)
	{
        
	}
}
