/*##############################################################################
(RU)
Файл для быстрого копирования самописанный функций из vcneFunctionLibrary.h
Не для компиляции, просто текстовик
(EN)
This file for quick copy-paste of custom functions from vcneFunctionLibrary.h
Not a script for compilation, but just text file for quick copy functions
##############################################################################*/

//Название Миссии//Mission Name(textType = 0)
DrawText("LAW_1", 0, false, 0);//Вызываем строчку названия миссии(тип строки 0)

//Миссия пройдена//Mission Passed(textType = 1)
DrawText("MISSION_PASSED", 1, true, 0);//Вызываем строчку Миссия пройдена(тип строки 1)

//Миссия провалена//Mission Failed(textType = 2)
DrawText("MISSION_FAILED", 2, false, 0);//Вызываем строчку Миссия провалена(тип строки 2)

//(RU)Цикл с ожиданием концовки текущего хелпа, чтобы его не прерывать новым хелпом
//(EN)Waiting until current help messages will fade in, to not interrupt it with next help messages
WaitUntilHelpFadeIn();