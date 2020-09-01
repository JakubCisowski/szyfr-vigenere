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
		printf("kluczSzyfrujacy - %s \n", kluczSzyfrujacy);
		// printf("jego dlugosc - %u \n", strlen(kluczSzyfrujacy));
		printf("plikWejsciowy - %s \n", plikWejsciowy);
		printf("plikWyjsciowy - %s \n", plikWyjsciowy);
		printf("szyfrowanie - %d \n", szyfrowanie);
		printf("deszyfrowanie - %d \n", deszyfrowanie);
	}
	else
	{
		printf("Nie udalo sie poprawnie wczytac przelacznikow, zamykam program.\n");
	}

	return 0;
}