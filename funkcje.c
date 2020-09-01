#include "funkcje.h"

bool wczytajPrzelaczniki(int ileArgumentow, char* argumenty[], char** kluczSzyfrujacy, char** plikWejsciowy, char** plikWyjsciowy, bool* szyfrowanie, bool* deszyfrowanie)
{
	// INFO
	// Jesli ktos wczytuje kilka razy ten sam przelacznik, program bierze pod uwage ostatni wczytany
	// Jesli ktos wczytuje przelacznik ktory nie istnieje, program go ignoruje
	


	/*printf("ilosc argumentow - %d\n", ileArgumentow);
	for (int i = 0; i < ileArgumentow; i++)
	{
		printf("%d argument - %s\n", i,argumenty[i]);
	}*/
	
	//*kluczSzyfrujacy = argumenty[1];



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
			if (checkKey(argumenty[i + 1]))
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

int checkKey(char key[])
{
	int i, x = 0, p;
	p = strlen(key);

	for (i = 0; i < p; i++)
		if ((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z'))
		{
			continue;
		}
		else return 0;

	return 1;
}