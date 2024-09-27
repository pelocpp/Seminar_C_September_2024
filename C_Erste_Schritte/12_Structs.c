#include <stdio.h>

#include "Time.h"
// #include "Time.h"

Time nowGlobal;

struct time time;  // 

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

// ============================================

int zahlen[10];

struct test
{
    int wert;
};

struct testWithArray
{
    int wert;
    int zahlen[5];
};

void procedureAcceptingArray(int a[])
{
    // nur zum Testen
    a[0] = 1;
}

void procedureAcceptingStruct(struct test t)
{
    // nur zum Testen
    t.wert = 1;
}

void procedureAcceptingStructWithArray(struct testWithArray t)
{
    // nur zum Testen
    t.wert = 1;
    t.zahlen[0] = 123;
}

void test_structs_vs_arrays()
{
    procedureAcceptingArray(zahlen);   // ORIGINAL // Anfangsadresse

    struct test test = { 0 };

    procedureAcceptingStruct(test);    // KOPIE

    struct testWithArray test2 = { 0, { 1, 2, 3, 4, 5 } };

    procedureAcceptingStructWithArray(test2);
}

void test_pointer_gimmick()
{
    int n = 123;

    int* ip = &n;
    int** ipp = &ip;
    int*** ippp = &ipp;
    int**** ipppp = &ippp;

    // Wert von n verändern - ohne den Namen von n verwenden
    ****ipppp = 456;
}