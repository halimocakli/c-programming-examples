#include <stdio.h>
#include <math.h>
#include <time.h>

int asal(int sayi);
int hizliAsal(int sayi);

int main(void)
{

	int i;
	int sure_a, sure_b, sure_c, sure_d;

	sure_a = time(NULL);

	for (i = 2; i <= 50000; i++)
	{
		if (asal(i))
			printf("%d Asal Sayidir...\n", i);
	}

	sure_b = time(NULL);

	printf("\n---------------------------------------\n\n");

	sure_c = time(NULL);

	for (i = 2; i <= 50000; i++)
	{
		if (hizliAsal(i))
			printf("%d Asal Sayidir...\n", i);
	}

	sure_d = time(NULL);

	printf("\n\n");
	printf("Gecen Sure\n============\n");
	printf("asal Fonksiyonu %d Saniye Calisti\n", sure_b - sure_a);
	printf("hizliAsal Fonksiyonu %d Saniye Calisti\n", sure_d - sure_c);
	printf("\n\n");

	return 0;
}

int asal(int sayi)
{
	int bolenSayi;

	for (bolenSayi = 2; bolenSayi <= sayi / 2; bolenSayi++)
	{
		if (sayi % bolenSayi == 0)
			return 0;
	}

	return 1;

}

int hizliAsal(int sayi)
{
	int bolenSayi2;

	for (bolenSayi2 = 2; bolenSayi2 <= (int)floor(sqrt(sayi)); bolenSayi2++)
	{
		if (sayi % bolenSayi2 == 0)
			return 0;
	}

	return 1;

}
