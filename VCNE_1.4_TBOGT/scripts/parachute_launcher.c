/***********************************************************************
	This file is a part of scocl project by Alexander Blade (c) 2011 
***********************************************************************/

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
#include "globals.h"

void main(void)
{
    int iVar2;
    int iVar3;
    int I;
    int iVar5;
    float fVar6;
    int iVar7;
    int iVar8;
    unknown uVar9;
    unknown uVar10;
    unknown uVar11;
    unknown uVar12;
    unknown uVar13;
    unknown uVar14;
    unknown uVar15;

    l_U0 = 86.00000000;
    l_U1 = 274.00000000;
    l_U35 = 0;
    l_U36 = 0;
    l_U37 = 0;
    l_U38 = 0;
    l_U39 = 0;
    l_U41 = 0;
    l_U42 = 0;
    l_U43 = 0;
    THIS_SCRIPT_SHOULD_BE_SAVED();
    while (true)
    {
        WAIT(0);
        if ((g_U2792) || (g_U2799))
        {
            if (DOES_OBJECT_EXIST( l_U40 ))
            {
                DELETE_OBJECT( ref l_U40 );
            }
            if (NOT g_U2799)
            {
                if (g_U2692[0]._fU56)
                {
                    if ((g_U2692[0]._fU4 == 0) || (g_U2692[0]._fU4 == 1))
                    {
                        if (NOT (IS_CHAR_INJURED( sub_196() )))
                        {
                            if (NOT (HAS_CHAR_GOT_WEAPON( sub_196(), 41 )))
                            {
                                GIVE_WEAPON_TO_CHAR( sub_196(), 41, 1, 0 );
                            }
                        }
                    }
                }
            }
            else if (NOT (IS_CHAR_INJURED( sub_196() )))
            {
                if (HAS_CHAR_GOT_WEAPON( sub_196(), 41 ))
                {
                    REMOVE_WEAPON_FROM_CHAR( sub_196(), 41 );
                }
            }
            sub_346();
            SET_DRAW_PLAYER_COMPONENT( 8, 0 );
        }
        if (NOT (IS_CHAR_INJURED( sub_196() )))
        {
            if (NOT l_U36)
            {
                if (NOT (DOES_PICKUP_EXIST( l_U6[0] )))
                {
                    if (g_U15811[65])
                    {
                        sub_791();
                        l_U36 = 1;
                    }
                }
            }
            else
            {
                sub_2098();
            }
            if (NOT l_U37)
            {
                if (NOT (DOES_PICKUP_EXIST( l_U32 )))
                {
                    if (g_U42974)
                    {
                        sub_2241();
                        l_U37 = 1;
                    }
                }
            }
            else if (HAS_PICKUP_BEEN_COLLECTED( l_U32 ))
            {
                if (NOT (HAS_CHAR_GOT_WEAPON( sub_196(), 41 )))
                {
                    GIVE_WEAPON_TO_CHAR( sub_196(), 41, 1, 0 );
                    g_U2798 = 1;
                }
            }
            if (NOT l_U39)
            {
                if (NOT (DOES_PICKUP_EXIST( l_U34 )))
                {
                    if (g_U15811[4])
                    {
                        sub_2453();
                        l_U39 = 1;
                    }
                }
            }
            else if (HAS_PICKUP_BEEN_COLLECTED( l_U34 ))
            {
                if (NOT (HAS_CHAR_GOT_WEAPON( sub_196(), 41 )))
                {
                    GIVE_WEAPON_TO_CHAR( sub_196(), 41, 1, 0 );
                }
            }
            if (NOT l_U38)
            {
                if (NOT (DOES_PICKUP_EXIST( l_U33 )))
                {
                    if (g_U15811[65])
                    {
                        iVar2 = GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT( "yusuf2" );
                        if (iVar2 == 0)
                        {
                            sub_2657();
                            l_U38 = 1;
                        }
                    }
                }
            }
            else
            {
                iVar2 = GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT( "yusuf2" );
                if (iVar2 == 0)
                {
                    if (HAS_PICKUP_BEEN_COLLECTED( l_U33 ))
                    {
                        if (NOT (HAS_CHAR_GOT_WEAPON( sub_196(), 41 )))
                        {
                            GIVE_WEAPON_TO_CHAR( sub_196(), 41, 1, 0 );
                        }
                    }
                }
                else if (DOES_PICKUP_EXIST( l_U33 ))
                {
                    REMOVE_PICKUP( l_U33 );
                    l_U38 = 0;
                }
            }
        }
        if (NOT g_U2795)
        {
            if (NOT sub_2869())
            {
                sub_3087();
            }
            if (NOT g_U2787)
            {
                SET_DRAW_PLAYER_COMPONENT( 8, 0 );
            }
        }
        iVar3 = 0;
        I = 0;
        for ( I = 0; I < g_U2692; I++ )
        {
            if (g_U2692[I]._fU56)
            {
                if ((NOT (HAS_MODEL_LOADED( 1490460832 ))) || (NOT (HAVE_ANIMS_LOADED( "PARACHUTE" ))))
                {
                    sub_3254();
                }
                else if (NOT g_U2692[I]._fU60)
                {
                    if (I == 0)
                    {
                        if (DOES_OBJECT_EXIST( l_U40 ))
                        {
                            DELETE_OBJECT( ref l_U40 );
                        }
                        if (HAS_SCRIPT_LOADED( "parachute_player" ))
                        {
                            START_NEW_SCRIPT( "parachute_player", 512 );
                        }
                        else
                        {
                            REQUEST_SCRIPT( "parachute_player" );
                        }
                    }
                    else if (HAS_SCRIPT_LOADED( "parachute_ai" ))
                    {
                        START_NEW_SCRIPT_WITH_ARGS( "parachute_ai", ref I, 1, 512 );
                    }
                    else
                    {
                        REQUEST_SCRIPT( "parachute_ai" );
                    }
                }
                iVar3++;
            }
        }
        if (iVar3 == 0)
        {
            if (NOT (DOES_OBJECT_EXIST( l_U40 )))
            {
                sub_3586();
            }
        }
        else
        {
            sub_3254();
        }
        if (NOT (IS_CHAR_INJURED( sub_196() )))
        {
            GET_CURRENT_CHAR_WEAPON( sub_196(), ref iVar5 );
            if (iVar5 == 41)
            {
                if ((sub_3730( 4, 0 )) AND (NOT g_U2800))
                {
                    if (((NOT l_U43) AND (l_U42 < 2)) AND (NOT IS_HELP_MESSAGE_BEING_DISPLAYED()))
                    {
                        PRINT_HELP( "PARA_EQUIP" );
                        l_U43 = 1;
                        l_U42++;
                    }
                    if (IS_CONTROL_JUST_PRESSED( 0, 4 ))
                    {
                        REMOVE_WEAPON_FROM_CHAR( sub_196(), 41 );
                        GIVE_WEAPON_TO_CHAR( sub_196(), 0, 0, 1 );
                        sub_4161( sub_196() );
                    }
                }
            }
            else if (l_U43)
            {
                if (IS_THIS_HELP_MESSAGE_BEING_DISPLAYED( "PARA_EQUIP" ))
                {
                    CLEAR_HELP();
                }
                l_U43 = 0;
            }
        }
        if (NOT (IS_CHAR_INJURED( sub_196() )))
        {
            if (g_U2692[0]._fU56)
            {
                if (NOT g_U2787)
                {
                    sub_4767( 1 );
                }
                if (NOT (DOES_OBJECT_EXIST( l_U40 )))
                {
                    if ((((g_U2692[0]._fU4 == 3) || (g_U2692[0]._fU4 == 5)) || (g_U2692[0]._fU4 == 7)) || (g_U2692[0]._fU4 == 8))
                    {
                        sub_4976();
                    }
                }
            }
            else if (DOES_OBJECT_EXIST( l_U40 ))
            {
                if (NOT IS_SCREEN_FADED_OUT())
                {
                    if (NOT (IS_CHAR_IN_WATER( sub_196() )))
                    {
                        if (HAVE_ANIMS_LOADED( "PARACHUTE" ))
                        {
                            if (g_U2787)
                            {
                                if (NOT l_U35)
                                {
                                    if ((sub_3730( 4, 0 )) AND (NOT (IS_CHAR_IN_ANY_CAR( sub_196() ))))
                                    {
                                        sub_5286();
                                        l_U35 = 1;
                                    }
                                }
                                else if (l_U41 == 0)
                                {
                                    SET_DRAW_PLAYER_COMPONENT( 8, 0 );
                                    if (IS_OBJECT_PLAYING_ANIM( l_U40, "obj_chute_off", "PARACHUTE" ))
                                    {
                                        GET_OBJECT_ANIM_CURRENT_TIME( l_U40, "obj_chute_off", "PARACHUTE", ref fVar6 );
                                        if (fVar6 > 0.95000000)
                                        {
                                            DETACH_OBJECT( l_U40, 1 );
                                            PLAY_OBJECT_ANIM( l_U40, "obj_chute_off_idle", "PARACHUTE", 8.00000000, 1, 0 );
                                            GET_GAME_TIMER( ref l_U41 );
                                        }
                                        if (NOT (IS_CHAR_PLAYING_ANIM( sub_196(), "PARACHUTE", "chute_off" )))
                                        {
                                            sub_5771();
                                        }
                                    }
                                }
                                else
                                {
                                    GET_GAME_TIMER( ref iVar7 );
                                    GET_OBJECT_COORDINATES( l_U40, ref uVar10._fU0, ref uVar10._fU4, ref uVar10._fU8 );
                                    GET_GROUND_Z_FOR_3D_COORD( uVar10._fU0, uVar10._fU4, uVar10._fU8 + 1000.00000000, ref uVar9 );
                                    if (uVar10._fU8 < (uVar9 + 1.00000000))
                                    {
                                        FREEZE_OBJECT_POSITION( l_U40, 1 );
                                    }
                                    iVar8 = iVar7 - l_U41;
                                    if (iVar8 > 2000)
                                    {
                                        sub_5771();
                                    }
                                    else if (iVar8 > 1000)
                                    {
                                        SET_OBJECT_ALPHA( l_U40, 255 - (ROUND( ((TO_FLOAT( iVar8 - 1000 )) / 1000.00000000) * 255.00000000 )) );
                                    }
                                }
                            }
                            else
                            {
                                sub_5771();
                            }
                        }
                        else
                        {
                            sub_5771();
                        }
                    }
                    else
                    {
                        sub_5771();
                    }
                }
                else
                {
                    sub_5771();
                }
            }
            else if (g_U2787)
            {
                if (NOT IS_PLAYER_BEING_ARRESTED())
                {
                    sub_4767( 0 );
                }
            };;;
        }
        else
        {
            sub_5771();
        }
        sub_6107();
    }
    return;
}