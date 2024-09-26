#include <stdio.h>

static void test_chars_01()
{
	char ch = '?';

	printf("Zeichen: %c\n", ch);

	// -------------------------

	// A)
	printf("Zeichen: %d\n", ch);

	//B)
	int n = ch;

	printf("Wert:    %d\n", n);

	// C) 
	n = n + 5;
	printf("Zeichen: %c\n", n);

	// D) 
	n = '\n';
	printf("Zeichen: %d\n", n);
}

void test_chars()
{
	// ASCII Tabelle   // UNICODE

	for ( int i = 0; i <= 127; i++)
	{
		printf("Index: %d - %x - %c\n", i, i, i);
	}
}


static void test_strings_01()
{
	char* s = "ABC";  // TODO: schreibender Zugriff
	printf("Zeichenkette: %s\n", s);

	// ===========================

	char s2[] = "123";
	printf("Zeichenkette: %s\n", s2);

	// ===========================

	// s3 ist ein Feld von char-Elementen, ABER KEINE ZEICHENKETTE
	char s3[] = { 'a', 'b', 'c' };
	printf("Zeichenkette: %s\n", s3);

	// ===========================

	// s4 ist eine Zeichenkette
	char s4[] = { 'a', 'b', 'c', 0 };
	printf("Zeichenkette: %s\n", s4);

	// ===========================

    // s5 ist eine Zeichenkette
	char s5[] = { 'a', 'b', 'c', '\0' };
	printf("Zeichenkette: %s\n", s5);
}


void test_strings()
{
	const char* s = "ABC";
	printf("Zeichenkette: %s\n", s);

	// Frage: Schreibender Zugriff auf Zeichenketten ???
	// *s = 'a';
	//printf("Zeichenkette: %s\n", s);

	// ===========================

	//int n = 123;
	//n++;

	char* s22 = "123456";
	char s2[] = "123456";
	printf("Zeichenkette: %s\n", s2);

	*s2 = '?';
	printf("Zeichenkette: %s\n", s2);
}

static int str_length(char* s)
{
	int length = 0;

	while ( s[length] != '\0' )
	{
		length++;
	}

	return length;
}

static int str_append(char* s, char ch, char* result, int length)
{
    // Return Value: 0 = Puffer zu klein // 1 = Success

	int index = 0; 

	// Originalzeichenkette in Resultatzeichenkette umkopieren
	while ( s[index] != '\0' )
	{
		if (index >= length)
		{
			return 0;
		}

		result[index] = s[index];
		index++;
	}

	// einzelnes Zeichen ch anhängen
	if (index >= length)
	{
		return 0;
	}
	result[index] = ch;
	index++;

	// Resultatzeichenkette mit '\0' terminieren
	if (index >= length)
	{
		return 0;
	}
	result[index] = '\0';

	return 1;
}

static int str_insert(char* s, char ch, int pos, char* result, int length)
{
	// ist das Ergebnisfeld gross genug
	int len = str_length(s);
	if (len + 1 >= length) {
		return 0;
	}

	int index = 0;

	// Ersten Teil Originalzeichenkette in Resultatzeichenkette umkopieren
	while (s[index] != '\0' && index < pos)
	{
		result[index] = s[index];
		index++;
	}

	// einzelnes Zeichen ch einfuegen
	result[index] = ch;
	index++;

	// Zweiten Teil Originalzeichenkette in Resultatzeichenkette umkopieren
	while (s[index-1] != '\0')
	{
		result[index] = s[index-1];
		index++;
	}

	// Resultatzeichenkette mit '\0' terminieren
	result[index] = '\0';

	return 1;
}

static int str_append_ex(char* s, char* toInsert, char* result, int length)
{
	// Return Value: 0 = Puffer zu klein // 1 = Success
	
    // ist das Ergebnisfeld gross genug
	int len1 = str_length(s);
	int len2 = str_length(toInsert);

	if (len1 + len2 + 1 >= length) {
		return 0;
	}

	int index = 0;

	// Originalzeichenkette in Resultatzeichenkette umkopieren
	while (s[index] != '\0')
	{
		if (index >= length)
		{
			return 0;
		}

		result[index] = s[index];
		index++;
	}

	// Zeichenkette 'toInsert' anhaengen
	int indexToInsert = 0;
	while (toInsert[indexToInsert] != '\0')
	{
		result[index] = toInsert[indexToInsert];
		index++;
		indexToInsert++;
	}

	// Resultatzeichenkette mit '\0' terminieren
	result[index] = '\0';

	return 1;
}


#define Length  256   // diesen Wert werde ich niemals überschreiten

void test_exercises_strings()
{
	char ergebnis[Length];

	//int hatGeklappt = str_insert("ABC", '!', 1, ergebnis, Length);

	//if (hatGeklappt) printf("Ergebnis: %s\n", ergebnis);
	//else printf("Fehler\n");

	int hatGeklappt = str_append_ex("ABC", "DEF", ergebnis, Length);

	if (hatGeklappt) printf("Ergebnis: %s\n", ergebnis);
	else printf("Fehler\n");
}

void test_exercises_strings_01()
{
	int length = str_length("123");
	// oder
	char vieleZeichen[] = "ABC";
	length = str_length(vieleZeichen);

	// ===================================
	//int str_append(char* s, char ch, char* result, int length)

	char ergebnis[4]; // = { 0 };
	int hatGeklappt = str_append("ABC", 'D', ergebnis, sizeof(ergebnis) / sizeof (char));

	if (hatGeklappt)
	{
		printf("Ergebnis: %s\n", ergebnis);
	}
	else
	{
		printf("Fehler\n");
	}
}