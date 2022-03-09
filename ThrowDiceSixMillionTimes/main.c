#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE    7

int main()
{
	size_t face;    /* 1-6 arasi zar yuzu */
	unsigned int cast;  /* atis sayaci 1-6.000.000 */
	unsigned int frequency[SIZE] = {0}; /* Gelen yuz sayisi */

	srand(time(NULL));  /* Rastgele sayi ureteci */

	/* 6.000.000 zar atisi */
	for (cast = 0; cast < 6000000; ++cast)
	{
		face = 1 + rand() % 6;
		++frequency[face];
	}

	printf("%s%17s\n", "Face", "Frequency");

	/* 1-6 frekans araligindaki elemanlari cizelge seklinde yazdirmak */
	for (face = 1; face < SIZE; ++face)
	{
		printf("%4d%17d\n", face, frequency[face]);
	}
	return 0;
}