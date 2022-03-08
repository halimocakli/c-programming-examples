#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double dizi[10] = {0};
	int i = 0;
	double us = 0;
	int eleman;
	int elemanSayisi = 10;
	int kullanimKontrolSayaci = 0;

	for (i; i < elemanSayisi; i++)
	{
		printf("%d.Elemani Giriniz:", i + 1);
		scanf("%lf", &dizi[i]);
	}

	printf("\n\n...Diziniz Gosteriliyor...\n\n");

	for (i = 0; i < elemanSayisi; i++)
	{
		printf("%d. Eleman ---> \"dizi[%d]\": %.0lf\n", i + 1, i, dizi[i]);
	}

	printf("\nDizinin mevcut hali yukaridaki gibidir...\n");

	while (eleman != 0)
	{
		printf("\nUssunu Almak Istediginiz Elemani Giriniz:");
		scanf("%d", &eleman);

		if (eleman != 0)
		{
			printf("\nAlmak Istediginiz Kuvveti Giriniz:");
			scanf("%lf", &us);

			for (i = 0; i < elemanSayisi; i++)
			{
				if (i == (eleman - 1))
				{
					dizi[i] = pow(dizi[i], us);
				}
			}
			kullanimKontrolSayaci++;
		}
	}

	if (kullanimKontrolSayaci == 0)
	{
		puts("\n\n...Dizinizde Bir Degisiklik Yapilmadi...");

		for (i = 0; i < elemanSayisi; i++)
		{
			printf("%d. Eleman ---> \"dizi[%d]\": %lf\n", i + 1, i, dizi[i]);
		}
	}

	else
	{
		printf("\n\n...Degistirilmis Diziniz Su Sekildedir...\n\n");

		for (i = 0; i < elemanSayisi; i++)
		{
			printf("%d. Eleman ---> \"dizi[%d]\": %.0lf\n", i + 1, i, dizi[i]);
		}
	}

	return 0;
}
