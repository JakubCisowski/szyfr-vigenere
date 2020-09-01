#include "funkcje.h"

bool wczytajPrzelaczniki(int ileArgumentow, char* argumenty[], char** kluczSzyfrujacy, char** plikWejsciowy, char** plikWyjsciowy, bool* szyfrowanie, bool* deszyfrowanie)
{
	// INFO
	// Jesli ktos wczytuje kilka razy ten sam przelacznik, program bierze pod uwage ostatni wczytany
	// Jesli ktos wczytuje przelacznik ktory nie istnieje, program go ignoruje

	// Zmienne pomocnicze do sprawdzenia czy podano wszystkie wymagane przelaczniki przy wlaczeniu programu
	bool jestKlucz = false, jestWej = false, jestWyj = false, jestSzyfr = false, jestDeszyfr = false;

	// Iterowanie po kazdym z przelacznikow
	for (int i = 1; i < ileArgumentow; i++)
	{
		// Przelacznik pliku wejsciowego
		if (strcmp(argumenty[i], "-i") == 0)
		{
			// Sprawdzenie czy istnieje nastepny argument
			if (i + 1 == ileArgumentow)
			{
				printf("Nie podano nazwy pliku wejsciowego po przelaczniku -i.\n");
				return false;
			}

			// Sprawdzanie poprawnosci pliku wejsciowego
			FILE* file;
			if ((file = fopen(argumenty[i+1], "r")) != NULL)
			{
				jestWej = true;
				*plikWejsciowy = argumenty[++i];
				fclose(file);
			}
			else
			{
				printf("Podanego pliku wejsciowego nie udalo sie otworzyc (pamietaj o dopisaniu .txt).\n");
				return false;
			}
		}

		// Przelacznik pliku wyjsciowego
		if (strcmp(argumenty[i], "-o") == 0)
		{
			// Sprawdzenie czy istnieje nastepny argument
			if (i + 1 == ileArgumentow)
			{
				printf("Nie podano nazwy pliku wyjsciowego po przelaczniku -o.\n");
				return false;
			}
			
			// Sprawdzenie poprawnosci pliku wyjsciowego
			FILE* file;
			if ((file = fopen(argumenty[i + 1], "a")) != NULL)
			{
				printf("<Plik wyjsciowy utworzony, upewnij sie czy stworzyles go w formacie .txt>\n");
				jestWyj = true;
				*plikWyjsciowy = argumenty[++i];
				fclose(file);
			}
			else
			{
				printf("Podanego pliku wyjsciowego nie udalo sie utworzyc (pamietaj o dopisaniu .txt).\n");
				return false;
			}
		}

		// Przelacznik klucza szyfrujacego
		if (strcmp(argumenty[i], "-k") == 0)
		{
			// Sprawdzenie czy istnieje nastepny argument
			if (i + 1 == ileArgumentow)
			{
				printf("Nie podano klucza szyfrujacego po przelaczniku -k.\n");
				return false;
			}

			//Sprawdzenie poprawnosci klucza szyfrujacego
			if (sprawdzKlucz(argumenty[i + 1]))
			{
				jestKlucz = true;
				*kluczSzyfrujacy = argumenty[++i];
			}
			else
			{
				printf("Podany klucz szyfrujacy jest niepoprawny, pamietaj ze moze skladac sie jedynie z malych oraz wielkich liter alfabetu lacinskiego.\n");
				return false;
			}
			
		}

		// Przelacznik szyfrowania
		if (strcmp(argumenty[i], "-e") == 0)
		{
			if (jestDeszyfr)
			{
				printf("Nie mozna jednoczesnie szyfrowac oraz deszyfrowac, nastepnym razem wybierz jedna opcje.\n");
				return false;
			}

			jestSzyfr = true;
			*szyfrowanie = true;
		}

		// Przelacznik deszyfrowania
		if (strcmp(argumenty[i], "-d") == 0)
		{
			if (jestSzyfr)
			{
				printf("Nie mozna jednoczesnie szyfrowac oraz deszyfrowac, nastepnym razem wybierz jedna opcje.\n");
				return false;
			}

			jestDeszyfr = true;
			*deszyfrowanie = true;
		}

	}

	// Sprawdzenie czy wszystkie potrzebne przelaczniki zostaly podane
	if (!jestWej || !jestWyj || !jestKlucz || (!jestDeszyfr && !jestSzyfr))
	{
		printf("Nie podano wszystkich wymaganych przelacznikow, wymagane: -i -o -k oraz jeden z dwoch trybow: -e lub -d.\n");
		return false;
	}

	return true;
}

int sprawdzKlucz(char klucz[])
{
	int i, x = 0, p;
	p = strlen(klucz);

	for (i = 0; i < p; i++)
		if ((klucz[i] >= 'a' && klucz[i] <= 'z') || (klucz[i] >= 'A' && klucz[i] <= 'Z'))
		{
			continue;
		}
		else return 0;

	return 1;
}

Bufor* wczytajDane(char* plikWejsciowy)
{
	Bufor* glowa = NULL;

	FILE* plik = fopen(plikWejsciowy, "r");
	char czescTekstu[10];

	while (fgets(czescTekstu, sizeof(czescTekstu), plik))
	{
		printf("\n%s",czescTekstu);
		glowa = wstawNaKoniec(glowa, czescTekstu);
	}

	fclose(plik);

	return glowa;
}

void zapiszDane(Bufor* glowa, char* plikWyjsciowy)
{
	FILE* plik = fopen(plikWyjsciowy, "w");

	// Iterujemy po czesciach tekstu w buforze
	while(glowa != NULL)
	{
		fprintf(plik, glowa->wartosc);
		glowa = glowa->next;
	}

	fclose(plik);
}

Bufor* nowyElement(char* wartosc)
{
	Bufor* nowyElement = (Bufor*)malloc(sizeof(Bufor));
	nowyElement->wartosc = _strdup(wartosc);
	nowyElement->next = NULL;
	return nowyElement;
}

Bufor* wstawNaKoniec(Bufor* glowa, char* wartosc)
{
	if (glowa == NULL)
		return nowyElement(wartosc);

	else
		glowa->next = wstawNaKoniec(glowa->next, wartosc);
	return glowa;
}




// DO USUNIECIA
void print(Bufor* head)
{
	Bufor* current_node = head;
	while (current_node != NULL)
	{
		printf("%s\n", current_node->wartosc);
		current_node = current_node->next;
	}
}