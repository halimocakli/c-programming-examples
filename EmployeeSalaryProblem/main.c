#include <stdio.h>
#define SIZE 9

/* satis problemi */
/*
    Asagidaki problemi cozmek icin tek indisli dizi kullaniniz. Bir sirket satis temsilcilerine komisyon tabanli odeme yapmaktadir.
    Bir satici her hafta icin $200, arti o haftaki tüm satislarinin %9'u kadar odeme almaktadir. Ornegin, bir haftada $3000 satis
    yapan satis temsilcisi, $200, arti $3000'lik satisin %9'u kadar, toplamda $470 odeme almaktadir. Asagidaki araliklarda satis yapan
    satis temsilcilerinin ne kadar odeme aldiklarini bulan(her satis temsilcisinin odemelerinin tamsayi oldugunu varsayiniz) C programini
    dizi kullanarak yaziniz.

    a) $200-299
    b) $300-399
    c) $400-499
    d) $500-599
    e) $600-699
    f) $700-799
    g) $800-899
    h) $900-999
    i) $1000 ve uzeri
*/

int main()
{
	int employeesSalesMinValues[SIZE] = {200, 300, 400, 500, 600, 700, 800, 900,
										 1000};   /* tum saticilarin alt sinir satis degerleri */
	int employeesSalesMaxValues[SIZE] = {299, 399, 499, 599, 699, 799, 899, 999,
										 1100};   /* tum saticilarin ust sinir satis degerleri */

	double minPayment[SIZE];    /* komisyon sonrasi minimum maaslar */
	double maxPayment[SIZE];    /* komisyon sonrasi maximum maaslar */

	int i;  /* sayac */

	/* minimum maas hesaplaniyor */
	for (i = 0; i < SIZE; ++i)
	{
		minPayment[i] = (employeesSalesMinValues[i] * 9 / 100) + 200;
	}

	/* maximum maas hesaplaniyor */
	for (i = 0; i < SIZE; ++i)
	{
		maxPayment[i] = (employeesSalesMaxValues[i] * 9 / 100) + 200;
	}

	/* minimum ve maximum maaslar yazdiriliyor */
	printf("MINIMUM MAASLAR\n");
	printf("***************\n\n");

	for (i = 0; i < SIZE; ++i)
	{
		printf("%d. iscinin minimum maasi = %.2lf\n", i + 1, minPayment[i]);
	}

	printf("\nMAXIMUM MAASLAR\n");
	printf("***************\n\n");

	for (i = 0; i < SIZE; ++i)
	{
		printf("%d. iscinin maximum maasi = %.2lf\n", i + 1, maxPayment[i]);
	}

	return 0;
}