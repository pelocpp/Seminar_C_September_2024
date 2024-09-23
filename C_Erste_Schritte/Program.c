// Hello World

/* Hello World */

#include <stdio.h>

// Vorwärtsdeklaration
extern void test_control_structures();
extern void test_control_structures_02();
extern void test_control_structures_03();
extern void test_true_false();
extern void test_while();
extern void test_increment();
extern void test_even_uneven();

void exercise_teuflische_folge();
void exercise_zinsberechnung();

int main_hello_world() 
{
    printf("Hello World");

    return 0;
}

// ===========================

int test_short()
{
    int s1 = 123;

    int s2 = 456;

    int s3 = s1 + s2;

    return 0;
}

// globale Variable
int size = 1;

struct Time
{
    int hour;
    int minute;
    int second;
};

int test_datatypes()
{
    //struct Time jetzt;      // C/C++
    //struct Time jetztJava;
    //struct Time* jetztJava = new Time();  // Java oder C#
    //struct Time* jetztJava = malloc (sizeof (Time));  // Java oder C#
    //free();

    //int size;

    size_t size2;

    size = sizeof(int); 

    // Print formatted
    size = 0x1101;
    printf("Wert von size: %d Ende\\Nochmal Ende\n", size);


    size = sizeof(short);
    size = sizeof(char);

    size2 = sizeof(size_t);

    return 0;
}


int main()  // Einsprungpunkt // entry point
{


    size = 456;

    test_even_uneven();

    return 0;
}