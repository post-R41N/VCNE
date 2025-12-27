/***********************************************************************
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#define SAVE "save"
#define LOAD "save_load"
#define no_save_script "no_save_script"
#define traffic "traffic"
#define street_phone "street_phone"
#define mob_phone "mob_phone"
#define intro "intro"
#define LAWYER "LAWYER"
#define AVERY "AVERY"
#define CUBAN "CUBAN"
#define HAITI "HAITI"
#define CORTEZ "CORTEZ"
#define DIAZ "DIAZ"
#define PROTECT "PROTECT"
#define KAUFMAN "KAUFMAN"
#define ROCK "ROCK"
#define BIKE "BIKE"
#define PRON "PRON"
#define COKERUN "COKERUN"
#define ICECREAM "ICECREAM"
#define MALIBU "MALIBU"
#define PHIL "PHIL"
#define COUNT "COUNT"
#define WORLD "WORLD"
#define STRIP "STRIP"
#define stadium "stadium"
#define sunshine_garages "sunshine_garages"
#define sunshine_race "sunshine_race"
#define map_bounds "map_bounds"
#define ambstreams "ambstreams"
#define business_sale "business_sale"
#define pickups "pickups"
#define weap_sounds "weap_sounds"
#define side_quests "side_quests"
#define side_quests_help "side_quests_help"
#define cheats "cheats"
#define packages "packages"
#define vc_jump "vc_jump"
#define mp3_player "mp3_player"
#define intro_help "intro_help"
#define test_fonts "test_fonts"
#define parachutelauncher "parachutelauncher"


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
		CheckScript(SAVE, TRUE);
		CheckScript(LOAD, TRUE);
		CheckScript(no_save_script, TRUE);
		CheckScript(traffic, TRUE);
		CheckScript(mob_phone, TRUE);
		CheckScript(intro, TRUE);
		CheckScript(LAWYER, TRUE);
		CheckScript(AVERY, TRUE);
		CheckScript(CORTEZ, TRUE);
		CheckScript(DIAZ, TRUE);
		CheckScript(PROTECT, TRUE);
		CheckScript(KAUFMAN, TRUE);
		CheckScript(ROCK, TRUE);
		CheckScript(BIKE, TRUE);
		CheckScript(PRON, TRUE);
		CheckScript(COKERUN, TRUE);
		CheckScript(ICECREAM, TRUE);
		CheckScript(MALIBU, TRUE);
		CheckScript(WORLD, TRUE);
		CheckScript(PHIL, TRUE);
		CheckScript(COUNT, TRUE);
		CheckScript(CUBAN, TRUE);
		CheckScript(HAITI, TRUE);
		CheckScript(street_phone, TRUE);
		CheckScript(sunshine_garages, TRUE);
		CheckScript(sunshine_race, TRUE);
		CheckScript(map_bounds, TRUE);
		CheckScript(ambstreams, TRUE);
		CheckScript(STRIP, TRUE);
		CheckScript(business_sale, TRUE);
		CheckScript(pickups, TRUE);
		CheckScript(weap_sounds, TRUE);
		CheckScript(side_quests, TRUE);
        //CheckScript(side_quests_help, TRUE);
		CheckScript(stadium, TRUE);
		CheckScript(cheats, TRUE);
		CheckScript(packages, TRUE);
		CheckScript(vc_jump, TRUE);
        CheckScript(mp3_player, TRUE);
        CheckScript(intro_help, TRUE);
        CheckScript(test_fonts, TRUE);
        //CheckScript(parachutelauncher, TRUE);

		
		
		WAIT(100);
	}

	return;
}
