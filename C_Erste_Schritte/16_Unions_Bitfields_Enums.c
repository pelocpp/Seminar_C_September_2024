// ===========================================================================
// UnionsBitFieldsEnums.c // Unions, Bitfields and Enums
// ===========================================================================

#include <stdio.h>
#include <string.h>


struct IPAddress2
{
    int oktets[4];
};

struct IPAddress2 address;

// https://www.ibm.com/docs/en/zos/2.4.0?topic=initializers-designated-aggregate-types-c-only

void testIPDdress2()
{
    struct IPAddress2 ip1 = { 127, 0, 0, 1 };

   // int aa[4] = { [2] = 3,[1] = 6 };

   //// Designator list syntax for arrays

   // int aaa[100] = { [1] = 1 };

  //  struct IPAddress2 ip2 = { [2] = 3,[1] = 6 };
}

struct Rectangle
{
    int x;
    int y;
    int width;
    int height;
};

void testRectangle()
{
    struct Rectangle rect1 = { 1, 1, 10, 20 };  // x = 1, y = 1, width = 10, height = 20

    struct Rectangle rect2 = { .x= 1, .y=1, .width=10, .height=20 };
    
  //  struct Rectangle rect3 = { .width = 10, .height = 20, .x = 1, .y = 1 };
}

// ===========================================================================
// BitFields

/* define simple structure */
struct Status1
{
    unsigned char widthValidated;
    unsigned char heightValidated;
    unsigned char positionValidated;
};




/* define a structure with bit fields */
struct Status2
{
    unsigned int widthValidated : 1;       // 0 ..1
    unsigned int heightValidated : 4;      // 0 .. 7
    unsigned int positionValidated : 1;    // 0.. 1
};

union Status2AsUnion
{
    unsigned int widthValidated : 1;       // 0 ..1
    unsigned int heightValidated : 4;      // 0 .. 7
    unsigned int positionValidated : 1;    // 0.. 1
};

// =========================================

// Ein Character und seine 8 Bits

union Status2AsUnionZWEI
{
    unsigned char ch;   // 0 .. 255  0 .. 0xFF

    struct Bits
    {
        unsigned char bit0 : 1;     
        unsigned char bit1 : 1;      
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
    } bits;
};

void charAndItsBits()
{
    union Status2AsUnionZWEI einChar = { .ch = 0 };

    einChar.ch = 'A';

    einChar.bits.bit3 = 1;

    einChar.ch = 0b11111111;  // 0377;  // 0xFF; //   255;

    printf("%o\n\n", einChar.ch);
}

static void bitfields()
{
    printf("Memory size occupied by status1 : %zu\n", sizeof(struct Status1));
    printf("Memory size occupied by status2 : %zu\n", sizeof(struct Status2));

    struct Status1 s1 = { 0, 0, 0 };
    s1.positionValidated = 1;

    struct Status2 s2 = { 0, 0, 0 };

    s2.positionValidated = 124;   // Laxheit

    s2.heightValidated = 15;  // 0 .. 15
}

// ===========================================================================
// Ein Vergleich

struct Flags
{
    unsigned char flag_01 : 1;
    unsigned char flag_02 : 1;
    unsigned char flag_03 : 1;
    unsigned char flag_04 : 1;
    unsigned char flag_05 : 1;
    unsigned char flag_06 : 1;
    unsigned char flag_07 : 1;
    unsigned char flag_08 : 1;
};

struct FlagsWithBitfield
{
    unsigned char flag_01;
    unsigned char flag_02;
    unsigned char flag_03;
    unsigned char flag_04;
    unsigned char flag_05;
    unsigned char flag_06;
    unsigned char flag_07;
    unsigned char flag_08;
};

// ===========================================================================
// Unions

union UnionExample
{
    short   member1;     // 2
    char    member2;     // 1
    float   member3;     // 4
};

union UnionExampleEx
{
    long long     value;              // 32 Bits  ... 4 Bytes ... RGB
    unsigned char value_bytes[8];
};

static void unions()
{
    // defining a union variable
    union UnionExampleEx var = { 0 };

    var.value = 0x00AA0000;

    unsigned char byte1 = var.value_bytes[0];
    unsigned char byte2 = var.value_bytes[1];
    unsigned char byte3 = var.value_bytes[2];
    unsigned char byte4 = var.value_bytes[3];
}

// IP - Adresse: 127.0.0.1   Oktets

union IPAddress
{
    unsigned char oktets[4];
    unsigned int  address;
};

void test_ip_adress()
{
    union IPAddress localHost = { 127, 0, 0, 1 };

    // designated initalizer syntax for unions
    union IPAddress address = { .address = 22222 };

    //localHost.oktets[0] = 127;
    //localHost.oktets[1] = 0;
    //localHost.oktets[2] = 0;
    //localHost.oktets[3] = 1;
}

// =======================================================================

enum level
{
    LOW     = 50,
    MEDIUM  = 70,
    HIGH    = 90
};

int level = 123;

// int level = 456;

typedef enum level Level;

// does not compile
//enum LevelEx
//{
//    LOW = 25,
//    MEDIUM = 50,
//    HIGH = 75
//};

static void enums()
{
    enum level level = MEDIUM;
    enum level level1 = MEDIUM;

    // myVar = 123;   // very bad

    switch (level)
    {
    case LOW:
        printf("Low Level\n");
        break;
    case MEDIUM:
        printf("Medium Level\n");
        break;
    case HIGH:
        printf("High Level\n");
        break;
    }

    //if (level == 5) {    // very bad

    //}

    printf("myVar: %d\n", level);
}

// =======================================================================

void mainUnionsBitfieldsEnums()
{
    charAndItsBits();
    testIPDdress2();
    bitfields();
    unions();
    test_ip_adress();
    enums();
}

// ===========================================================================
// End-of-File
// ===========================================================================