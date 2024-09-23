#include <stdio.h>

#define True  1
#define False 0


// Bekanntmachung: Es gibt eine globale Variable size
// (( Welcher Wert: ?????????????? ))
extern int size;
// static int size;


void test_true_false()
{
    int gleich;

    int a = 10;
    int b = 5;

    gleich = (a == b);

    // ==  Ist gleich
    // !=  Ist ungleich
    if (a == b) {
        printf("Bedingung ist erfuellt!");
    }

    // Achtung: Auch das ist C --- Stilistik: Diskussionsfähig
    if ( a != 0 ) {
        printf("Bedingung ist erfuellt!");
    }

    printf("Ende!");
}

void test_control_structures()
{
    // if-Anweisung

    int a = 10;
    int b = 5;

    int c = 10;
    int d = 5;

    int ergebnis = a + b * c;  // 10 + 5 * 10 == 60 oder 150

    if ( a > b && c > d )   // Logisches Und: &&
    {
        // Rumpf // Folge von Anweisungen
        printf("Bedingung ist erfuellt!");
    }

    if (a < b || c > d)   // Logisches Oder: ||
    {
        // Rumpf // Folge von Anweisungen
        printf("Bedingung ist erfuellt!");
    }

    b = 0;
    int what = b;
    what = !b;

    if ( ! (a < b)  )   // Logisches Nicht:  !
    {
        // Rumpf // Folge von Anweisungen
        printf("Bedingung ist erfuellt!");
    }

    printf("Ende!");
}

void test_control_structures_02()
{
    // if-Anweisung
    int a = 10;
    int b = 5;

    // { }   Block  // Rumpf // Bereich // Scope

    if (a > b) 
    {
        // Rumpf // Folge von Anweisungen
        printf("Bedingung ist erfuellt!");
    }
    else
    {
        printf("Bedingung ist nicht erfuellt!");
    }


    if (a > b)
        printf("Bedingung ist erfuellt!");
        
    printf("Bedingung ist erfuellt!");


    printf("Ende!");
}


void test_control_structures_03()
{
    // if-Anweisung
    int a = 10;


    // Laufzeit: Könnte besser gehen....

    if (a == 9)
    {
        printf("Bedingung ist erfuellt!");
    }

    if (a == 10)
    {
        printf("Bedingung ist erfuellt!");
    }

    if (a == 11)
    {
        printf("Bedingung ist erfuellt!");
    }

    // VERSUS

    if (a == 9)
    {
        printf("Bedingung ist erfuellt!");
    }
    else if (a == 10)
    {
        printf("Bedingung ist erfuellt - a = 10!");
    }
    else if (a == 11)
    {
        printf("Bedingung ist erfuellt!");
    }
    else
    {
        printf("???");
    }

    // ALTERNATIVE:

    switch (a)  // a = 9
    {
    case 9:
        printf("Bedingung ist erfuellt - a == 9!");
        // break;
        // Fall-Through
    case 10:
        printf("Bedingung ist erfuellt - a == 10!");
        break;
    case 11:
        printf("Bedingung ist erfuellt - a == 11!");
        break;
    default:
        printf("???");
        break;
    }

    // Rechner für Hex-Zahlen 
    char ch = '1';

    switch (ch) 
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        // fall - through
        printf("Bedingung ist erfuellt !");
        break;

    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
        printf("Bedingung ist erfuellt - a == 10!");
        break;

    default:
        printf("???");
        break;
    }
}

void test_while()
{
}
