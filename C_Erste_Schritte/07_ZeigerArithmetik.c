// Zeiger - Arithmetik

void test_pointer_arithmetic_01()
{
	int speicher[10] = { 0 };  // Feld: 10 int-Variablen am Stück

	// ----------------------------------------------------

	int* ip;   // Adresse in Bezug auf eine int-Variable

	// A) ip soll auf den Anfang des Arrays / Felds 'speicher' zeigen

	ip = & speicher[0];

	// A2) das geht einfacher

	ip = speicher;

	// B1) Dem ersten Feldelement den Wert 123 zuweisen

	speicher[0] = 123;

	// B2) Dem ersten Feldelement den Wert 123 zuweisen

	*ip = 456;

	// B3) Dem ersten Feldelement den Wert 123 zuweisen

	*speicher = 789;

	// ==============================================

	// C1) Dem zweiten Feldelement den Wert 123 zuweisen

	speicher[1] = 123; 

	// C2) Dem zweiten Feldelement den Wert 456 zuweisen

	* (ip + 1) = 456;

	// Ausführlich:
	int* ip2;
	ip2 = ip + 1;  // 1 ist auf Maschinebene als sizeof (int) = 4 zu verstehen
	// versus
	ip2 = ip;
	ip2++;


	// Zweites Beispiel
	short andereZahlen[10] = { 0 };
	short* sp = andereZahlen;
	short* sp2 = sp + 1;  // sizeof(short) = 2

	// short* sp3 = sp + sp2;  // Zwei Zeiger können nicht addiert werden	
	// ip + 1              = 456;

    // C3) Dem zweiten Feldelement den Wert 789 zuweisen
	*(speicher + 1) = 789;
}

// ========================================================

void test_pointer_arithmetic_02()
{
	int speicher[10];

	// ------------------------------------------

	// Feld vorbelegen: So sollten wir es als Anwender machen

	for (int i = 0; i < 10; i++)
	{
		speicher[i] = 2 * i + 1;
	}

	// ------------------------------------------

    // Speicher belegen: So sieht es fast wie Maschinencode aus

	// Anfangsadress in ip
	// for (int* ip = speicher, i = 0 ; ip != ip + 10; ip++, i++ )
	for (int* ip = speicher, i = 0; ip != speicher + 10; ip++, i++)
	{
		*ip = 3 * i + 1; // i noch lösen
	}

	// ------------------------------------------

	// Variante 2:
	// Speicher belegen: So sieht es immer noch wie Maschinencode aus

	// Anfangsadress in ip
	int* ip = speicher;

	// speicher++;
	// *(speicher + 1000) = 99;

	for (int i = 0; i < 10; i++)
	{
		* (ip + i) = 4 * i + 1;
		// i = 0, 1, 2, 3
		// ip = 1024, 1028, 102C, 1030, 1034, ...

		// VEREINFACHENDE SYNTAX
		ip[i] = 4 * i + 1;  // IST IDENTISCH zu Zeile 97
	}
}

// ==================================================

// Gimmicks

void test_pointer_arithmetic_04()
{
	int speicher[10] = { 0 };

	// 3.-tes Element auf den Wert 10 setzen

	// langweilig:
	speicher [3] = 10;

	// interessanter
	*(speicher + 3) = 11;

	// very interesting
	*(3 + speicher) = 12;

	// very, very interesting
	3 [speicher] = 13;
}

void test_pointer_arithmetic()
{
	int speicher[10] = { 0 };

	int* ip = speicher;

	// 3.-tes Element auf den Wert 10 setzen

	// langweilig:
	ip[3] = 10;

	// interessanter
	*(ip + 3) = 11;

	// very interesting
	*(3 + ip) = 12;

	// very, very interesting
	3[ip] = 13;
}