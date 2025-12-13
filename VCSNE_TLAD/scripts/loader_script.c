/***********************************************************************
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

//#define parachuteLauncher "parachuteLauncher"
#define mp3_player "mp3_player"


void CheckScript(char *name, boolean checkloading)
{
	if ( GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(name) == 0 )
	{
		if (checkloading) FORCE_LOADING_SCREEN(TRUE);
		REQUEST_SCRIPT(name);
		while ( !HAS_SCRIPT_LOADED(name) ) WAIT(0);
		uint script = START_NEW_SCRIPT(name, 1024);
		MARK_SCRIPT_AS_NO_LONGER_NEEDED(name);	
	}
}

void main(void)
{
	THIS_SCRIPT_SHOULD_BE_SAVED();
	while (TRUE)
	{
		//CheckScript(mp3_player, TRUE);
		//TestCheckScript();
		
		WAIT(100);
	}

	return;
}
