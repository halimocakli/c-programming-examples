#include <stdio.h>

int buyukSayi(int sayi1, int sayi2)
{
	if (sayi1 > sayi2)
		return sayi1;

	else
		return sayi2;
}

int kucukSayi(int sayi1, int sayi2)
{
	if (sayi1 < sayi2)
		return sayi1;

	else
		return sayi2;
}

int ebob(int sayi1, int sayi2)
{
	int kalan;

	kalan = sayi1 % sayi2;

	while (kalan != 0)
	{
		sayi1 = sayi2;
		sayi2 = kalan;
		kalan = sayi1 % sayi2;
	}

	return sayi2;

}

int main()
{
	int sayi1, sayi2;

	printf("Birinci Sayiyi Giriniz: ");
	scanf("%d", &sayi1);

	printf("2. Sayiyi Giriniz: ");
	scanf("%d", &sayi2);

	printf("\nEBOB<%d,%d> = %d", buyukSayi(sayi1, sayi2), kucukSayi(sayi1, sayi2), ebob(sayi1, sayi2));

	return 0;
}
