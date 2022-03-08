#include <stdio.h>

int integerPower(int taban, int us)
{
	int i = 0;
	int sonuc = 1;

	for (i; i < us; ++i)
	{
		sonuc *= taban;
	}

	return sonuc;
}

int main()
{
	int us, taban;

	printf("Taban Giriniz: ");
	scanf("%d", &taban);

	printf("Us Giriniz: ");
	scanf("%d", &us);

	printf("%d Ussu %d = %d", taban, us, integerPower(taban, us));
}