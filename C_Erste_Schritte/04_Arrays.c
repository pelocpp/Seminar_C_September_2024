
#define   Length   20

const int Length2 = 20;

void test_arrays()
{
	// 10 Werte des Typs int sind hierdurch definiert
	int zahlen[Length];
	//int zahlen[20; ];

	int weitereZahlen[] = { 1, 2, 3, 4, 5 };

	int nochmalWeitereZahlen[100] = { 0 };

	// versus

	for (int i = 0; i < 100; i++)
	{
		nochmalWeitereZahlen[i] = 0;
	}

	// ======================================

	// Zugriff aus das ERSTE Element
	zahlen[0] = 123;

	// Zugriff aus das ERSTE Element
	zahlen[9] = 321;

	//int n = 20;
	//zahlen[n] = 321;  // keine Überprüfung: PERFORMANZ

	// if, while, do while, switch, for

	for ( int i = 0 ; i < Length; i++ )
	{
		zahlen[i] = 2 * i + 1;
	}
}