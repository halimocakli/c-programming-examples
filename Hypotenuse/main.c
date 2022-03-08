#include <stdio.h>
#include <math.h>

double hypotenuse(double kenar1, double kenar2)
{
	return sqrt(pow(kenar1, 2) + pow(kenar2, 2));
}

int main()
{
	int ucgenSayisi;
	double kenar1;
	double kenar2;

	printf("Hipotenus Hesabi Yapmak Icin Ucgen Sayisini Giriniz: ");
	scanf("%d", &ucgenSayisi);

	for (int i = 0; i < ucgenSayisi; ++i)
	{
		printf("1.Kenar: ");
		scanf("%lf", &kenar1);

		printf("2. Kenar: ");
		scanf("%lf", &kenar2);

		printf("Hipotenus = %.2lf\n", hypotenuse(kenar1, kenar2));
	}

	return 0;
}
