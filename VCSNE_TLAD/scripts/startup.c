/***********************************************************************
			Fully stripped startup script
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#define MAINSCRIPT "main"

void main(void)
{
	// create player
	Player plind;
	CREATE_PLAYER(0, 756.774, -214.403, 4.8223, &plind);
	SET_CHAR_COORDINATES(GetPlayerPed(), 756.774, -214.403, 4.8223);
	SET_CHAR_HEADING(GetPlayerPed(), 90.0);
    	// load main script
	REQUEST_SCRIPT(MAINSCRIPT);
	while (!HAS_SCRIPT_LOADED(MAINSCRIPT)) WAIT(0);
	uint script = START_NEW_SCRIPT(MAINSCRIPT, 1024);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED(MAINSCRIPT);
	// return to the loading process
	return;
}
