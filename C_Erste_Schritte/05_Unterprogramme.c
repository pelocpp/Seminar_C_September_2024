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

void testProcedures()
{
	PrintHeader(5);

	printf("\n");

	int n = 7;
	PrintHeader(n);
}
