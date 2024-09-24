#include <stdio.h>

void test_pointer_01()
{
    int n = 123;
    int m = 456;

    int zweiZahlen[2] = { 1, 2 };

    int* ip1 = &zweiZahlen[0];
    int* ip2 = &zweiZahlen[1];

    int wieGross = sizeof(int);

    int* ip;  // Deklaration // Vereinbarung // Zeigervariablen

    ip = &n;

    n = 456;
    // versus
    *ip = 456;     // Anweisung // Statement // indirekte Zugriff
}

// =========================================================

void malDrei(int argument)  // Stellvertreter
{
    argument = 3 * argument;
}

void malDreiEx(int* ipArgument)  // Stellvertreter
{
    int result;

    result = *ipArgument;   // indirekter Zugriff - lesend

    result = 3 * result;

    *ipArgument = result;   // indirekter Zugriff - schreibend
}

void malDreiExEx(int* ipArgument)  // Stellvertreter
{
    *ipArgument = *ipArgument * 3;
}

void test_pointer()
{
    int wert = 5;

    printf("Wert: %d\n", wert);

    malDrei(wert);

    printf("Wert: %d\n", wert);

    // wert enthält Adresse von IO
    malDreiExEx(&wert);

    printf("Wert: %d\n", wert);
}