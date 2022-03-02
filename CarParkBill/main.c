#include <stdio.h>
#include <math.h>

double calculateCharges(float sure);

int main(void)
{
	float arac_1_sure, arac_2_sure, arac_3_sure, toplamSure;
	float arac_1_tutar, arac_2_tutar, arac_3_tutar, toplamTutar;

	printf("\n\n");

	printf("#1. Aracin Park Suresini Giriniz: ");
	scanf("%f", &arac_1_sure);
	printf("#2. Aracin Park Suresini Giriniz: ");
	scanf("%f", &arac_2_sure);
	printf("#3. Aracin Park Suresini Giriniz: ");
	scanf("%f", &arac_3_sure);

	toplamSure = arac_1_sure + arac_2_sure + arac_3_sure;

	arac_1_tutar = calculateCharges(arac_1_sure);
	arac_2_tutar = calculateCharges(arac_2_sure);
	arac_3_tutar = calculateCharges(arac_3_sure);

	toplamTutar = arac_1_tutar + arac_2_tutar + arac_3_tutar;

	printf("\n\n");

	printf("Arac\tSure\tTutar\n");
	printf("%d\t%5.1f\t%6.2f\n", 1, arac_1_sure, arac_1_tutar);
	printf("%d\t%5.1f\t%6.2f\n", 2, arac_2_sure, arac_2_tutar);
	printf("%d\t%5.1f\t%6.2f\n", 3, arac_3_sure, arac_3_tutar);
	printf("TOTAL\t%5.1f\t%6.2f\n", toplamSure, toplamTutar);

	printf("\n\n");

	return 0;
}

double calculateCharges(float sure)
{
	if ((sure - 3.0) <= 0)
		return 2.0;

	else if ((sure == 24.0))
		return 10;

	else
		return (ceil(sure) - 3) * 0.5 + 2;
}
