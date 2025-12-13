/*	---------------------------------------------------------------
     This header contains VCNE script common functions.

     This file is a part of VCNE project (C) post-R41N 2025/2026
    ---------------------------------------------------------------

Технические комментарии
##### 16:9 / 4:3 #####
По высоте шрифт должен быть с одинаковым значением.
По ширине - меньшее значение занимает 1.0125/1.35 = 0.75(75%) от большего.
Если считать от большего к меньшему, то 1.351/1.0125 = 1.33(33%)
*/

void SetupDrawMissionName(char* textCont, uint a)//Функция настройки и отрисовки названий Миссий
{

    SET_TEXT_TO_USE_TEXT_FILE_COLOURS(1);
    SET_TEXT_COLOUR(220, 170, 0, a);//Задаём цвет текста
    SET_TEXT_EDGE(1, 0, 0, 0, a);//Задаем обводку текста
    SET_TEXT_DROPSHADOW(1, 0, 0, 0, a);//Задаём тень текста           
    SET_TEXT_RIGHT_JUSTIFY(1);//Задаем выравнивание текста по правому краю экрана
    SET_TEXT_CENTRE_WRAPX(0.947);//Задаем значение смещения текста от правого края экрана
    SET_TEXT_FONT(1);//Задаем шрифт текста
    if (GET_IS_WIDESCREEN())
    {
        SET_TEXT_SCALE(0.54, 1.016);//Размер шрифта под 16:9
        DISPLAY_TEXT(0.0, 0.815, textCont);//Рисуем нужный текст под 16:9
    }
    else
    {
        SET_TEXT_SCALE(0.72, 1.016);//Размер шрифта под 4:3
        DISPLAY_TEXT(0.0, 0.725, textCont);//Рисуем нужный текст под 4:3
    }
}

void SetupDrawMissionResult(char* textCont, uint a)//Функция настройки и отрисовки результата миссия(Миссия провалена, Миссия пройдена)
{
    SET_TEXT_TO_USE_TEXT_FILE_COLOURS(1);
    SET_TEXT_COLOUR(255, 156, 226, a);//Задаём цвет текста
    if (GET_IS_WIDESCREEN())SET_TEXT_SCALE(1.0125, 1.488);//Размер шрифта под 16:9 
    else SET_TEXT_SCALE(1.35, 1.488); //Размер шрифта под 4:3
    SET_TEXT_DROPSHADOW(2, 0, 0, 0, a);//Задаём тень текста           
    SET_TEXT_CENTRE(1);
    SET_TEXT_FONT(0);//Задаем шрифт текста
    DISPLAY_TEXT(0.5, 0.462, textCont);//Рисуем нужный текст
}

void SetupDrawMissionReward(uint cash, uint a)//Функция настройки и отрисовки награды за прохождение миссии
{
    SET_TEXT_TO_USE_TEXT_FILE_COLOURS(1);
    SET_TEXT_COLOUR(255, 156, 226, a);//Задаём цвет текста
    if (GET_IS_WIDESCREEN()) SET_TEXT_SCALE(1.0125, 1.488);//Размер шрифта под 16:9
    else SET_TEXT_SCALE(1.35, 1.488); //Размер шрифта под 4:3
    SET_TEXT_DROPSHADOW(2, 0, 0, 0, a);//Задаём тень текста           
    SET_TEXT_CENTRE(1);
    SET_TEXT_FONT(0);//Задаем шрифт текста
    DISPLAY_TEXT_WITH_NUMBER(0.5, 0.552, "CASH", cash);//Рисуем награду за выполнение миссии
}

void DrawText(char* textCont, uint textType, bool isRewardExist, uint cash)
{
    uint textState = 0, curAlpha, maxAlpha = 255, time = 5000, fadeTime;
    bool firstTick = true;
    float alphaMult = 0.0;
    if (textType == 0)//Выбор тайминга фейда для типов надписей(0 - для названий миссий, 1 - для "Миссия пройдена", 2 - "Миссия провалена")
    {
        time = 5000;
        fadeTime = 250;
    }
    else if (textType == 1)
    {
        time = 7000;
        fadeTime = 833;
    }
    else if (textType == 2)
    {
        time = 3000;
        fadeTime = 833;
    }
    SETTIMERA(0);//сбрасываем таймер 
    while (true)
    {
        if (IS_SCREEN_FADING_OUT())//Если экран гаснет, то переключаемся сразу на этап исчезновения текста
        {
            if (firstTick)
            {
                SETTIMERA(0);
                fadeTime = 250;
                firstTick = false;
                textState = 2;
            }
        }
        if (textState == 0)
        {
            alphaMult = TIMERA();//Записываем текущее значение таймера
            WAIT(0);
            if (TIMERA() > fadeTime)
            {
                textState = 1;
                SETTIMERA(0);//сбрасываем таймер
            }
        }
        else if (textState == 1)
        {
            WAIT(0);
            if (TIMERA() > time)
            {
                textState = 2;
                SETTIMERA(0);//сбрасываем таймер
            }
        }
        else if (textState == 2)
        {
            alphaMult = (fadeTime - TIMERA());//Записываем обратное значение таймера, сколько осталось миллисекунд до окончания таймера
            WAIT(0);
            if (TIMERA() > fadeTime)
            {
                SETTIMERA(0);//сбрасываем таймер
                break;
            }
        }
        if (textState != 1)
        {
            alphaMult /= fadeTime;//Получаем отношение текущего значения таймера к общему времени, к примеру 0/250 = 0 или 50/250 = 0.2
            curAlpha = ROUND(maxAlpha * alphaMult);//Умножаем множитель альфы на значение максимальной альфы, и округляем чтобы не было ошибки с типом данных
        }
        if (textType == 0) SetupDrawMissionName(textCont, curAlpha);//Вызов функции отрисовки названий миссий
        else if (textType == 1 || textType == 2)
        {
            SetupDrawMissionResult(textCont, curAlpha);//Вызов функции отрисовки Миссия пройдена/провалена
            if (isRewardExist) SetupDrawMissionReward(cash, curAlpha);//Вызов функции отрисовки денежной награды за миссию
        }
    }
}