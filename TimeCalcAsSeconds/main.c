#include <stdio.h>

int saniyeCevirme(int saat, int dakika, int saniye);

int main()
{
	int saat, dakika, saniye;
	int saat2, dakika2, saniye2;
	int toplamSaniye1, toplamSaniye2;
	int fark;

	printf("1.Zaman Icin\n");
	printf("------------\n\n");

	printf("Saat Giriniz(0-12): ");
	scanf("%d", &saat);

	printf("Dakika Giriniz(0-60): ");
	scanf("%d", &dakika);

	printf("Saniye Giriniz(0-60): ");
	scanf("%d", &saniye);

	printf("\n\n");

	printf("2.Zaman Icin\n");
	printf("------------\n\n");

	printf("Saat Giriniz(0-12): ");
	scanf("%d", &saat2);

	printf("Dakika Giriniz(0-60): ");
	scanf("%d", &dakika2);

	printf("Saniye Giriniz(0-60): ");
	scanf("%d", &saniye2);

	toplamSaniye1 = saniyeCevirme(saat, dakika, saniye);
	toplamSaniye2 = saniyeCevirme(saat2, dakika2, saniye2);

	fark = toplamSaniye1 - toplamSaniye2;

	printf("\nGirdiginiz 1. ve 2. Zaman Arasindaki Saniye Farki = %d Saniyedir...", fark);

	getchar();
	return 0;
}

int saniyeCevirme(int saat, int dakika, int saniye)
{
	int saniyeSaat, saniyeDakika;

	saniyeSaat = 3600 * saat;
	saniyeDakika = 60 * dakika;

	return saniyeSaat + saniyeDakika + saniye;
}
