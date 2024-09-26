#include <stdio.h>
#include <stdlib.h>

#include "Wallet.h"

static void dynamic_memory_01()
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

static void dynamic_memory_02()
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

static void dynamic_memory_03()
{
	int* ap = (int*) malloc(257);    // HEAP

	//printf("%d\n", ap[-1]);
	//printf("%d\n", ap[-2]);
	//printf("%d\n", ap[-3]);
	//printf("%d\n", ap[-4]);  // hier liegt die Länge des allokierten Speicherbereichs
	//printf("%d\n", ap[-5]);

	free(ap);
}


static void dynamic_memory_wallet()
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

static void tueWasMitDemWallet(struct Wallet* wallet)
{
	wallet->m_euros++;

	// diesen Geldbeutel brauche ich nicht mehr ...
	// free(wallet);
}

static void dynamic_memory_wallet_02()
{
	struct Wallet* myHeapWallet =
		(struct Wallet*) malloc(sizeof(struct Wallet));    // HEAP

	init(myHeapWallet, 20, 10);
	print(myHeapWallet);

	tueWasMitDemWallet(myHeapWallet);

	free(myHeapWallet);
}

// ====================================================================

static int str_length(char* s)
{
	int length = 0;
	while (s[length] != '\0') length++;
	return length;
}

// str_append_dynamic ("ABC", "12345", ==> "ABC12345")

static char* str_append_dynamic_01(char* original, char* toAppend)
{
	// Berechne Länge des Ergebnisstrings
	int lenTotal = str_length(original) + str_length(toAppend) + 1;

	// Speicher fuer Ergebniszeichenkette reservieren
	char* result = malloc(sizeof (char) * lenTotal);
	if (result == NULL) return NULL;

	// Speicher fuer Ergebniszeichenkette fuellen: Ersten Teil umkopieren
	int i = 0;
	while (original[i] != '\0') {
		result[i] = original[i];
		i++;
	}

	// Speicher fuer Ergebniszeichenkette fuellen: Zweiten Teil umkopieren
	int j = 0;
	while (toAppend[j] != '\0') {
		result[i] = toAppend[j];
		j++;
		i++;
	}

	// Terminierende Null anhängen
	result[i] = '\0';

	return result;
}

static int str_append_dynamic_02(char* original, char* toAppend, char** ergebnis)
{
	// Berechne Länge des Ergebnisstrings
	int lenTotal = str_length(original) + str_length(toAppend) + 1;

	// Speicher fuer Ergebniszeichenkette reservieren
	char* result = malloc(sizeof(char) * lenTotal);
	if (result == NULL) return -1;

	// Speicher fuer Ergebniszeichenkette fuellen: Ersten Teil umkopieren
	int i = 0;
	while (original[i] != '\0') {
		result[i] = original[i];
		i++;
	}

	// Speicher fuer Ergebniszeichenkette fuellen: Zweiten Teil umkopieren
	int j = 0;
	while (toAppend[j] != '\0') {
		result[i] = toAppend[j];
		j++;
		i++;
	}

	// Terminierende Null anhängen
	result[i] = '\0';

	// Heap-Zeigervariable nach aussen reichen
	*ergebnis = result;

	return lenTotal;
}

void dynamic_memory()
{
	char* ergebnis = NULL;

	// 1. Variante
	ergebnis = str_append_dynamic_01("ABCDEF", "12345");
	printf("Ergebnis 1: %s\n", ergebnis);
	free(ergebnis);

	// 2. Variante
	ergebnis = NULL;
	int length = str_append_dynamic_02("ABCDEF", "12345", &ergebnis);
	printf("Ergebnis 2: %s (Length: %d)\n", ergebnis, length);
	free(ergebnis);
}

