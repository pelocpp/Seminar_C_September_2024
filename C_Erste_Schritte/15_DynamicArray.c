
#include <stdio.h>
#include <stdlib.h>


#include "15_DynamicArray.h"

// Realisierung:

int initDynamicIntArray(struct DynamicIntArray* da, size_t length)
{
	int* tmp = (int*) calloc(length, sizeof(int));
	if (tmp == NULL)
	{
		printf("Out of Memory!");
		return -1;
	}

	da->m_data = tmp;
	da->m_length = length;

	return 1;
}

void releaseDynamicIntArray(struct DynamicIntArray* da)
{
	if (da->m_data != NULL)
	{
		free(da->m_data);

		da->m_data = NULL;
		da->m_length = 0;
	}
}

void fillDynamicIntArray(struct DynamicIntArray* da, int value)
{
	// memset - geht aus meiner Sicht nicht ... schreibt byte-weise
	for (int i = 0; i < da->m_length; i++)
	{
		da->m_data[i] = value; 
	}
}

// getter
size_t getLength (struct DynamicIntArray* da)
{
	if (da->m_data != NULL) {
		return da->m_length;
	}
	else {
		return 0;
	}
}

int get(struct DynamicIntArray* da, int index)
{
	if (index >= 0 && index < (int) da->m_length) {
		return da->m_data[index];
	}
	else {
		printf("Wrong Index: %d [Length = %zu]\n", index, da->m_length);
		return -1;
	}
}

int resizeDynamicIntArray(struct DynamicIntArray* da, int newLength)
{
	if (newLength <= da->m_length) {

		// very simple: just shorten length, keep buffer
		da->m_length = newLength;
		return 1;   // succeeded
	}
	else
	{
		// new length is huger
		 
	    // allocate new (temporary) buffer
		int* tmp = (int*) calloc(newLength, sizeof(int));
		if (tmp == NULL) {
			printf("resizeDynamicIntArray: Out of memory");
			return 0;
		}

		// copy current buffer into new one
		for (size_t i = 0; i < da->m_length; ++i) {
			tmp[i] = da->m_data[i];
		}

		// Rest ist wegen calloc mit 0 vorbelegt

		// release current buffer
		free(da->m_data);     // free, calloc 

		// switch to new buffer
		da->m_data = tmp;
		da->m_length = newLength;

		return 1;
	}
}


int shrinkToFitDynamicIntArray(struct DynamicIntArray* da)
{
	// Vorrausetzung: Der interne (da->m_data) Speicherbereich ist größer als da->length

	// allocate new - temporary and fitting - buffer
	int* tmp = (int*) calloc(da->m_length, sizeof(int));

	if (tmp == NULL) {
		printf("shrinkToFitDynamicIntArray: Out of memory");
		return 0;
	}
	else
	{
		// copy current buffer into new one
		for (size_t i = 0; i < da->m_length; ++i) {
			tmp[i] = da->m_data[i];
		}

		// release current buffer
		free(da->m_data);

		// switch to new buffer
		da->m_data = tmp;

		return 1;
	}
}


void printDynamicIntArray(struct DynamicIntArray* da)
{
	printf("{");
	for (int i = 0; i < da->m_length; i++)
	{
		printf("%d", da->m_data[i]);
		if (i < da->m_length - 1) {
			printf(",");
		}
	}
	printf("}\n");
}

// ========================================================

// Anwendung:

void test_dynamic_int_array_01()
{
	struct DynamicIntArray anArray = { NULL, 0 };

	int length = 20;   // Variable length könnte berechnet werden

	initDynamicIntArray(&anArray, length);
	fillDynamicIntArray(&anArray, 1);
	printDynamicIntArray(&anArray);

	int len = getLength(&anArray);
	for (int i = -5; i <= len; i++)
	{
		int tmp = get(&anArray, i);
		printf("%2d: %d\n", i, tmp);
	}

	releaseDynamicIntArray(&anArray);
}


void test_dynamic_int_array()
{
	struct DynamicIntArray anArray = { NULL, 0 };

	initDynamicIntArray(&anArray, 5);     // Length: 5
	fillDynamicIntArray(&anArray, 1);
	printDynamicIntArray(&anArray);

	resizeDynamicIntArray(&anArray, 10);  // Length: 10
	printDynamicIntArray(&anArray);

	fillDynamicIntArray(&anArray, 2);  
	printDynamicIntArray(&anArray);

	resizeDynamicIntArray(&anArray, 2);    // Length: 2, ABER intern sind noch 10 reserviert
	printDynamicIntArray(&anArray);

	shrinkToFitDynamicIntArray(&anArray);  // Length: bleibt 2,
	                                       // aber intern sind auch nur noch 2 reserviert
	printDynamicIntArray(&anArray);
}
