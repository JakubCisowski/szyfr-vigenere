#include "funkcje.h"

int main(int ileArgumentow, char* argumenty[])
{
	// Parametry programu
	char* kluczSzyfrujacy = malloc(100 * sizeof(char));
	char* plikWejsciowy = malloc(100 * sizeof(char));
	char* plikWyjsciowy = malloc(100 * sizeof(char));
	bool szyfrowanie = false, deszyfrowanie = false;

	printf("PROGRAM URUCHOMIONY --------\n");

	// Wczytywanie przelacznikow podanych przez liste polecen
	if (wczytajPrzelaczniki(ileArgumentow, argumenty, &kluczSzyfrujacy, &plikWejsciowy, &plikWyjsciowy, &szyfrowanie, &deszyfrowanie))
	{
		/*
		// DO USUNIECIA
		printf("kluczSzyfrujacy - %s \n", kluczSzyfrujacy);
		printf("plikWejsciowy - %s \n", plikWejsciowy);
		printf("plikWyjsciowy - %s \n", plikWyjsciowy);
		printf("szyfrowanie - %d \n", szyfrowanie);
		printf("deszyfrowanie - %d \n", deszyfrowanie);
		*/

		// Wczytanie danych wejsciowych do bufora
		Bufor* buforTekstu = wczytajDane(plikWejsciowy);

		/*
		// DO USUNIECIA
		printf("\nCO SIEDZI W LISCIE: ----\n");
		print(buforTekstu);
		*/
		

		//todo Operacja na danych wejsciowych

		// Zapis z bufora do pliku wyjsciowego
		zapiszDane(buforTekstu, plikWyjsciowy);

		//todo Zwolnienie pamieci bufora, usuniecie struktury

		printf("Program zostal wykonany pomyslnie, zamykam program.\n");
	}
	else
	{
		printf("Nie udalo sie poprawnie wczytac przelacznikow, zamykam program.\n");
	}

	return 0;
}