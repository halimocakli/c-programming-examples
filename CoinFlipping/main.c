#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int flip(void);

int main(void)
{
	int para, sayac, toplamTura = 0, toplamYazi = 0;

	srand(time(NULL));

	for (sayac = 1; sayac <= 100; sayac++)
	{
		para = flip();

		printf("%d.Atis ---> %s Geldi\n", sayac, para ? "Tura" : "Yazi");

		if (para == 1)
			toplamTura++;
		else if (para == 0)
			toplamYazi++;
	}

	printf("\n\n");
	printf("Toplam Tura Sayisi\t%2d\n", toplamTura);
	printf("Toplam Yazi Sayisi\t%2d\n", toplamYazi);
	printf("\n\n");
	return 0;
}

int flip(void)
{
	return rand() % 2;
}
