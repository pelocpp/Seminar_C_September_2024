#include <stdio.h>    // printf
#include <stdlib.h>   // malloc, free

void jaggedArray_01()
{
	// Ein gezacktes Feld -- auf dem STACK

	int feld1[] = { 1, 2, 3 };
	int feld2[] = { 10, 20, 30, 40, 50, 60 };
	int feld3[] = { 100 };

	int* feld[3] = { feld1, feld2, feld3 };

	int lengths[3] = { 3, 6, 1 };   // verschiedene Längen bei "gezackten" Feldern

	// Traversieren
	for (int i = 0; i < 3; i++)
	{
		printf("Adresse von Feld %d: %p\n\n", i, feld[i]);

		for (int k = 0; k < lengths[i]; k++)
		{
			printf("%4d   ", feld[i][k]);
		}
		printf("\n");
	}
}


int** jaggedArray_02_init(int** sizes)
{
	// Ein gezacktes Feld -- auf dem HEAP

	// Felder unterschiedlicher Länge --- auf dem Heap
	int* feld1 = (int*) malloc(sizeof(int) * 3);
	feld1[0] = 1;
	feld1[1] = 2;
	feld1[2] = 3;

	// Felder unterschiedlicher Länge --- auf dem Heap
	int* feld2 = (int*) malloc (sizeof(int) * 6);
	feld2[0] = 10;
	feld2[1] = 20;
	feld2[2] = 30;
	feld2[3] = 40;
	feld2[4] = 50;
	feld2[5] = 60;

	// Felder unterschiedlicher Länge --- auf dem Heap
	int* feld3 = (int*) malloc(sizeof(int) * 1);
	feld3[0] = 100;

	// 3 int* Werte in einem Feld ablegen
	int** feld = (int**) malloc(3 * sizeof(int*));
	feld[0] = feld1;
	feld[1] = feld2;
	feld[2] = feld3;

	// ================================================

    // Felder unterschiedlicher Länge --- auf dem Heap
	int* lengths = (int*) malloc(sizeof(int) * 3);
	lengths[0] = 3;
	lengths[1] = 6;
	lengths[2] = 1;

	*sizes = lengths;

	return feld;
}



int** jaggedArray_02_init_frage ()
{
	// Ein gezacktes Feld -- auf dem HEAP

	// Felder unterschiedlicher Länge --- auf dem Heap
	int* feld1 = (int*)malloc(sizeof(int) * 4);
	feld1[0] = 1;
	feld1[1] = 2;
	feld1[2] = 3;
	feld1[3] = -1;

	// Felder unterschiedlicher Länge --- auf dem Heap
	int* feld2 = (int*)malloc(sizeof(int) * 7);
	feld2[0] = 10;
	feld2[1] = 20;
	feld2[2] = 30;
	feld2[3] = 40;
	feld2[4] = 50;
	feld2[5] = 60;
	feld2[6] = -1;

	// Felder unterschiedlicher Länge --- auf dem Heap
	int* feld3 = (int*)malloc(sizeof(int) * 2);   // 1024
	feld3[0] = 100;
	feld3[1] = -1;

	// 3 int* Werte in einem Feld ablegen
	int** feld = (int**)malloc(3 * sizeof(int*));
	feld[0] = feld1;
	feld[1] = feld2;
	feld[2] = feld3;

	// ================================================

	return feld;
}



// feld und sizes sind Felder DERSELBEN Laenge
void jaggedArray_02_print(int** feld, int length, int* sizes)
{
	for (int i = 0; i < length; i++)
	{
		int* anfang = feld[i];

		for (int k = 0; k < sizes[i]; k++)
		{
			printf("%4d ", anfang[k]);  // feld[i][k]
		}
		printf("\n");
	}
}

void jaggedArray_02_print_frage (int** feld, int length)
{
	for (int i = 0; i < length; i++)
	{
		int* anfang = feld[i];

		int k = 0;
		while (anfang[k] != -1)
		{
			printf("%4d ", anfang[k]);  // feld[i][k]
			k++;
		}
		printf("\n");
	}
}

void jaggedArray_02_release(int** feld, int length, int* sizes)
{
	// man beachte die Reihenfolge:
	//zuerst die Unterfelder -- dann das vorgelagerte Feld
	for (int i = 0; i < length; i++)
	{
		free(feld[i]);
	}

	free(feld);


	// ACHTUNG !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// MUSS sizes aufheben:
	int* sizesCopy = sizes;

	for (int i = 0; i < length; i++)
	{
		printf("Size: %d\n", *sizes);
		++sizes;
	}

	free(sizesCopy);   // 1024
}

// int** jaggedArray_02_init(int** sizes)
// void jaggedArray_02_print(int** feld, int length, int* sizes)
void jaggedArrays()
{
	int* lengths = NULL;

	int** jaggedArray = jaggedArray_02_init(& lengths);

	jaggedArray_02_print(jaggedArray, 3, lengths);

	jaggedArray_02_release(jaggedArray, 3, lengths);
}

void jaggedArrays_frage()
{
	int** jaggedArray = jaggedArray_02_init_frage();

	jaggedArray_02_print_frage(jaggedArray, 3);
}