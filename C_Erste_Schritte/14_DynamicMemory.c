#include <stdio.h>
#include <stdlib.h>

#include "Wallet.h"

void dynamic_memory_01()
{
	int n = 123;   // n liegt am Stack

	// will eine int-Variable am Heap anlegen // reservieren
	int* ip = (int*) malloc ( sizeof (int) );

    // will die int-Variable verwenden
	*ip = 456;

	printf("Am Heap: %d\n", *ip);

	free(ip);

	//if (ip != NULL)
	//{
	//	// will die int-Variable verwenden
	//	*ip = 456;

	//	printf("Am Heap: %d\n", *ip);

	//	free(ip);
	//}
	//else
	//{
	//	printf("No memory\n");
	//}
}

#define Length 10

void dynamic_memory_02()
{
	// Feld am Heap anlegen: int-Array der Länge 10 
	// Konsekutiver Speicherbereich

	int ap0[10];   // STACK

	int* ap = (int*) malloc(Length * sizeof(int));    // HEAP

	// A) Mit Pointer-Arithmetik
	for (int i = 0; i < Length; i++)
	{
		*(ap + i) = 2 * i + 1;
	}

	// B) Mit dem Index-Operator
	for (int i = 0; i < Length; i++)
	{
		ap[i] = 3 * i + 1;
	}

	// C) Ausgeben
	for (int i = 0; i < Length; i++)
	{
		printf("%2d: %d\n", i, ap[i]);
	}

	free(ap);
}

void dynamic_memory_03()
{
	int* ap = (int*) malloc(257);    // HEAP

	printf("%d\n", ap[-1]);
	printf("%d\n", ap[-2]);
	printf("%d\n", ap[-3]);
	printf("%d\n", ap[-4]);
	printf("%d\n", ap[-5]);

	free(ap + 1);
}


void dynamic_memory_wallet()
{
	struct Wallet myStackWallet;                              // STACK

	myStackWallet.m_cents = 50;

	init(&myStackWallet, 10, 50);
	print(&myStackWallet);

	// ===================================================

	struct Wallet* myHeapWallet = 
		(struct Wallet*) malloc( sizeof (struct Wallet) );    // HEAP

	init(myHeapWallet, 20, 10);
	print(myHeapWallet);

	free(myHeapWallet);
}

// ==========================================================

void tueWasMitDemWallet(struct Wallet* wallet)
{
	wallet->m_euros++;

	// diesen Geldbeutel brauche ich nicht mehr ...
	// free(wallet);
}




void dynamic_memory_wallet_02()
{
	struct Wallet* myHeapWallet =
		(struct Wallet*) malloc(sizeof(struct Wallet));    // HEAP

	init(myHeapWallet, 20, 10);
	print(myHeapWallet);

	tueWasMitDemWallet(myHeapWallet);

	free(myHeapWallet);
}

// ====================================================================


// str_append_dynamic ("ABC", "12345", ==> "ABC12345")

char* str_append_dynamic_01(char* original, char* toAppend)
{
	// Skizze:

	// Kann die Länge der Ergebnisstrings berechnen
	// Len(original) + Len(toAppend) + 1 ('\0')
	int lenTotal = 10;

	char* result = malloc(sizeof (char) * lenTotal);

	return result;
}

int str_append_dynamic_02(char* original, char* toAppend, char** ergebnis)
{
	// Skizze:

	// Kann die Länge der Ergebnisstrings berechnen
	// Len(original) + Len(toAppend) + 1 ('\0')
	int lenTotal = 10;

	char* result = malloc(sizeof(char) * lenTotal);

	*ergebnis = result;

	return lenTotal;
}

void dynamic_memory()
{
	char* ergebnis = NULL;

	str_append_dynamic_02("ABC", "12345", & ergebnis);   // char**
}