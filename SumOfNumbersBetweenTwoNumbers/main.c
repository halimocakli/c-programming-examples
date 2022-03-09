#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sayi1, sayi2, toplam = 0;
	int buyuk, kucuk;
	int esit1, esit2;

	printf("Gireceginiz Iki Sayi Arasindaki Sayilar Toplacanaktir...\n\n");

	printf("Lutfen Birinci Sayiyi Giriniz: ");
	scanf("%d", &sayi1);

	printf("Lutfen Ikinci Sayiyi Giriniz:");
	scanf("%d", &sayi2);

	//1 5

	int terimSayisi = abs(sayi2 - sayi1) + 1; // Mutlak deger saglayan "abs" fonksiyonu kullanildi

	//printf("%d", terimSayisi);

	if (sayi1 > sayi2)
	{
		buyuk = sayi1;
		kucuk = sayi2;

		while (terimSayisi > 0)
		{
			//printf("%d\n",sayi2);
			toplam += sayi2;
			sayi2++;
			terimSayisi--;

		}
		printf("%d ile %d Arasindaki Sayilarin Toplami = %d\n", kucuk, buyuk, toplam);
	}

	else if (sayi2 > sayi1)
	{
		buyuk = sayi2;
		kucuk = sayi1;

		while (terimSayisi > 0)
		{
			//printf("%d\n",sayi1);
			toplam += sayi1;
			sayi1++;
			terimSayisi--;
		}
		printf("%d ile %d Arasindaki Sayilarin Toplami = %d\n", kucuk, buyuk, toplam);
	}

	else if (sayi1 == sayi2)
	{
		esit1 = sayi1;
		esit2 = sayi2;

		while (terimSayisi > 0)
		{
			//printf("%d\n",sayi1);
			toplam += sayi1;
			sayi1++;
			terimSayisi--;
		}
		printf("%d ile %d Arasindaki Sayilarin Toplami = %d\n", esit1, esit2, toplam);
	}
	return 0;
}
