#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h>

typedef struct Bufor
{
    char* wartosc;
    struct Bufor* next;
}Bufor;