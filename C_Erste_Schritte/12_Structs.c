#include <stdio.h>

#include "Time.h"
// #include "Time.h"

Time nowGlobal;

void printTime(Time t)
{
    printf("%02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);
}

void printTimeEx(const Time* tp)
{
    printf("%02d:%02d:%02d\n", 
        tp->hours, tp->minutes, tp->seconds);
}

void resetTimeEx(Time* tp)
{
    //t.hours = 0;
    //t.minutes = 0;
    //t.seconds = 0;

    //(*tp).hours = 0;
    //(*tp).minutes = 0;
    //(*tp).seconds = 0;

    tp -> hours = 0;
    tp -> minutes = 0;
    tp -> seconds = 0;
}


void resetTime(Time t)
{
    t.hours = 0;
    t.minutes = 0;
    t.seconds = 0;
}

void test_structs()
{
    int n = 123;

    // A) Strukturvariablen
    Time now;
    struct time than;

    // B) Zugriff
    now.hours = 9;
    now.minutes = 24;
    now.seconds = 0;

    // C) Initialisierung
    Time now1 = { 16, 29, 59 };
    struct time than1 = { 16, 59, 59 };

    // D) Parameterübergabe einer Struktur
    printTime(now);

    resetTime(now);
    printTime(now);

    resetTimeEx(&now);
    printTimeEx(&now);
}
