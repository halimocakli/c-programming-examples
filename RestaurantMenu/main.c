#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");

	/*      MENU             S�PAR�� KODU           F�YATI
		Ba�lang��lar              1                 5.5    TL
		Ara Sicaklar              2                 7.5    TL
		Salatalar                 3                 12     TL
		Ana Yemekler              4                 17.75  TL
		Tatlilar                  5                 11.25  TL
		Icecekler                 6                 2.25   TL*/

	printf("\t\t\t******RESTORAN MENUSU******\n\n\n"); /*Menunun hazirlandigi kisim*/
	printf("MENU\t\t\tSIPARIS KODU\t\t\tFIYATI\n");
	printf("Baslangiclar\t\t\t1\t\t\t5.5   TL\n");
	printf("Ara Sicaklar\t\t\t2\t\t\t7.5   TL\n");
	printf("Salatalar\t\t\t3\t\t\t12    TL\n");
	printf("Ana Yemekler\t\t\t4\t\t\t17.25 TL\n");
	printf("Tatlilar\t\t\t5\t\t\t11.25 TL\n");
	printf("Icecekler\t\t\t6\t\t\t2.25  TL\n\n");

	int siparisNumarasi;
	float toplamTutar = 0;
	float porsiyonMiktari;

	printf("SIPARIS ISLEMINI SONLANDIRMAK YA DA TAMAMLAMAK ICIN \"0\" DEGERINI GIRINIZ\n\n");

menu:
	printf("LUTFEN ISTEDIGINIZ URUNUN SIPARIS KODUNU GIRINIZ:");
	scanf("%d", &siparisNumarasi);

	if (siparisNumarasi == 0)
	{
		goto cikis;
	}

	if (siparisNumarasi < 1 || siparisNumarasi > 6)
	{
		printf("LUTFEN 1-6 ARASINDA BIR SIPARIS NUMARASI GIRINIZ!\n\n");
		goto menu;
	}

	if (siparisNumarasi > 0 && siparisNumarasi < 7)
	{
		printf("LUTFEN KAC PORSIYON ISTEDIGINIZI BELIRTINIZ:");
		scanf("%f", &porsiyonMiktari);
	}

	switch (siparisNumarasi)
	{
	case 1:
		if (porsiyonMiktari > 0)
		{
			toplamTutar += porsiyonMiktari * 5.5;
		}
		else
		{
			printf("LUTFEN 0'DAN BUYUK BIR PORSIYON GIRINIZ\n\n");
		}
		break;
	case 2:
		if (porsiyonMiktari > 0)
		{
			toplamTutar += porsiyonMiktari * 7.5;;
		}
		else
		{
			printf("LUTFEN 0'DAN BUYUK BIR PORSIYON GIRINIZ\n\n");
		}
		break;
	case 3:
		if (porsiyonMiktari > 0)
		{
			toplamTutar += porsiyonMiktari * 12;
		}
		else
		{
			printf("LUTFEN 0'DAN BUYUK BIR PORSIYON GIRINIZ\n\n");
		}
		break;
	case 4:
		if (porsiyonMiktari > 0)
		{
			toplamTutar += porsiyonMiktari * 17.25;
		}
		else
		{
			printf("LUTFEN 0'DAN BUYUK BIR PORSIYON GIRINIZ\n\n");
		}
		break;
	case 5:
		if (porsiyonMiktari > 0)
		{
			toplamTutar += porsiyonMiktari * 11.25;
		}
		else
		{
			printf("LUTFEN 0'DAN BUYUK BIR PORSIYON GIRINIZ\n\n");
		}
		break;
	case 6:
		if (porsiyonMiktari > 0)
		{
			toplamTutar += porsiyonMiktari * 2.25;
		}
		else
		{
			printf("LUTFEN 0'DAN BUYUK BIR PORSIYON GIRINIZ\n\n");
		}
		break;
	}

	if (porsiyonMiktari > 0)
	{
		printf("TUTAR = %.2f TL\n\n", toplamTutar);
	}

	goto menu;

cikis:
	printf("SIPARIS ISLEMINIZ TAMAMLANMISTIR\n\n");
	printf("TOPLAM TUTAR = %.2f TL\n\nAFIYET OLSUN \2", toplamTutar);
	return 0;
}
