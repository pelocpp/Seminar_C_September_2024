#include <stdio.h>

#include "GlobalDefinitions.h"

// oberste Ebene: globale Variable
int globalVariable = 123;

// oberste Ebene: Datei-globale Variable
static int fileGlobalVariable = 456;

static void access_my_variable(int* ptr)
{
	printf("via ptr: data: %d\n", *ptr);

	(*ptr)  ++;
}

static void test_function_global_variable()
{
	static int data = 123;

	double d = 123.123;

	/* auto */ int localData = 123;

	data++;

	printf("data: %d\n", data);

	access_my_variable(& data);  // Hmmm ...da wird die Adresse
	            // einer static-Variablen weitergereicht: "Bad Smell"
}

static void test_daten()
{
	int n = 123;

	int feld[10] = { 0 };

	char feld2[] = { '1', '2', '3' };

	char feld3[] = "ABC";
	feld3[0] = 'a';

	char* cp = NULL;
	cp = "123456789";
	// cp[0] = 'a';
	cp++;

	// Mini-Gimmick
	char zeichenVorher = cp[-1];

	//char* cp1;
	//char* cp2;
	//cp1 = cp2;
}

void test_memory()
{
	test_daten();

	test_function_global_variable();
	test_function_global_variable();
	test_function_global_variable();

	int localVariable = 456;

	printf("globalVariable: %d\n", globalVariable);

	printf("fileGlobalVariable: %d\n", fileGlobalVariable);

	printf("localVariable: %d\n", localVariable);
}


