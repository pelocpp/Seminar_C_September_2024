#include <stdio.h>

void PrintHeaderRek(int wieOft)
{
	if (wieOft == 0)
	{
		printf("Wert von wieOft: %d - wir sollten aufhoeren\n", wieOft);
		return;
	}
	else
	{
		printf("Wert von wieOft: %d\n", wieOft);
		PrintHeaderRek(wieOft - 1);
	}
}

void testProceduresRek()
{
	PrintHeaderRek(5);
}

void PrintHeader(int wieOft)
{
	for (int i = 0; i < wieOft; i++)
	{
		printf("Guten Morgen\n");
	}
}

// ==================================================

// Unterprogramm: Funktion - es wird ein Ergebnis berechnet
int malZwei(int wert)
{
	int result;

	result = wert * 2;

	return result;
}

void testFunctions()
{
	int ergebnis = 0;

	ergebnis = malZwei(10);

	printf("Ergebnis: %d\n", ergebnis);
}

void testProcedures()
{
	PrintHeader(5);

	printf("\n");

	int n = 7;
	PrintHeader(n);
}
