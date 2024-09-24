
// void belegeFeldVor(int feld[], int length)

void belegeFeldVor( int* feld, int length )
{
	int anzahlBytes1 = sizeof(feld);
	int anzahlBytes2 = sizeof(*feld);
	int anzahlBytes3 = sizeof(int);

	for (int i = 0; i < length; i++)
	{
		feld[i] = 2 * i + 1;
	}
}

#define Length  10

void test_main()
{
	int zahlen[Length] = { 0 };

	int anzahlBytes1 = sizeof(zahlen);
	int anzahlBytes2 = sizeof(int[Length]);

	// aufsteigend ab 1, 2, ...
	belegeFeldVor( zahlen, Length);
	// oder auch
	belegeFeldVor(zahlen, sizeof(int[Length]) / sizeof(int));
}



void test_arrays_und_pointer()
{
	test_main();
}