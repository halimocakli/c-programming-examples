#include <stdio.h>
#include <stdlib.h>
//Klavyeden girilen iki tamsayinin carpimini carpim sembolu kullanmadan gerceklestiren
//C programini recursive fonksiyon yardimiyla yaziniz

int carpim(int sayi1, int sayi2)
{
	int sonuc;

	if (sayi2 == 1)
	{
		sonuc = sayi1;
	}
	else
	{
		sonuc = sayi1 + carpim(sayi1, sayi2 - 1);
	}

	return sonuc;
}

int main()
{
	int a, b;

	printf("Lutfen 1. Sayiyi Giriniz: ");
	scanf("%d", &a);

	printf("Lutfen 1. Sayiyi Giriniz: ");
	scanf("%d", &b);

	printf("\n%d x %d = %d", a, b, carpim(a, b));

	return 0;
}
