#include<stdio.h>

int mukemmel(int sayi);

int main()
{

	int a, b, c;

	printf("\nLutfen Ust Sinir Sayisini Giriniz: ");
	scanf("%d", &a);
	printf("1 ve %d Arasindaki Mukemmel Sayilar-->\n\n", a);

	for (c = 1; c <= a; c++)
	{

		b = mukemmel(c);

		if (b == c)
		{
			printf("%d\n", c);
		}

	}

	return 0;
}

int mukemmel(int sayi)
{
	int i, toplam = 0;

	for (i = 1; i < sayi; i++)
	{
		if (sayi % i == 0)
			toplam += i;
	}

	return toplam;
}
