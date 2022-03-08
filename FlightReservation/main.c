/* Ucak rezervasyon sistemi */
/* Halim Can Ocaklı */

/* Kücük bir havayolu sirketi yeni otomatik rezervasyon sistemi icin bir bilgisayar satin almistir.
 * Mudur yeni sistemi programlamanizi istemektedir. Havayolundaki tek ucagin her seferi icin koltuk
 * atamasi yapmaniz gerekmektedir. Kapasite : 10 koltuk. Programinizi asagidaki gibi bir menu sunmalidir:
 *
 *                          "Lutfen birinci sinif icin 1'e basiniz"
 *                          "Lutfen ekonomik sinif icin 2'ye basiniz"
 *
 * Bir yolcu 1'e bastiginda programiniz birinci sinif bir koltuk atmasi yapmalidir (1-5 arasi koltuklardan)
 * Yolcu 2'ye bastiginda programiniz ekonomik sinif bir koltuk atamasi yapmalidir (6-10 arasi koltuklar)
 * Daha sonra programiniz koltuk numarasi ve ait oldugu sinifi gosteren bir gecis bileti bastirmalidir.
 * Ucaktaki oturma duzeni icin tek indisli bir dizi kullaniniz. Koltuklarin ilk etapta bos oldugunu gostermek
 * icin butun dizi elemanlarina 0 atayiniz. Koltuklar satin alindikca iliskili koltugun degerine 1 yazarak
 * koltugun dolu oldugunu gosteriniz. Programiniz atanmis bir koltugu yeniden satmaya calismamalidir.
 * Programinizdaki birinnci sinif koltuklar dolduktan sonra yolcuya ekonomik siniftan koltuk isteyip
 * istemedigi sorulmalidir (ya da tam tersi). İstenirse ilgili koltuk atamasi yapilmalidir. İstenmezse
 * "Bir sonraki ucus 3 saat sonra gerceklesecektir" yazisi ekrana bastirilmalidir.
 */

#include<stdio.h>
#include<ctype.h>

int main()
{
	int plane[11] = {0};
	int firstClass = 1;
	int economy = 6;
	int i;
	int choice;
	char response;

	while (i < 10)
	{
		printf("\n\nBirinci Sinif Icin \"1\" tuslayin...\nIkinci Sinif Icin \"2\" tuslayin...\nCikmak icin \"0\" tuslayin...\nYanit: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:

			if (!plane[firstClass] && firstClass < 6)
			{
				printf("\nKoltuk satin alma isleminiz gerceklesti.\nKoltuk numaraniz: %d\n", firstClass);
				plane[firstClass] = 1;
				firstClass++;
				i++;
			}

			else if (firstClass > 5 && economy < 11)
			{
				printf("\nUcagimizin First Class kisminda koltuk kalmamistir.\nEconomy kismindan bilet ayirtmak ister misiniz?");
				printf("Yanit (E/H): ");
				scanf("%s", response);

				if (toupper(response) == 'E')
				{
					printf("\nKoltuk satin alma isleminiz gerceklesti.\nKoltuk numaraniz: %d\n", economy);
					plane[economy] == 1;
					economy++;
					i++;
				}

				else
				{
					printf("\nBir sonraki ucak 3 saat sonra kalkacak.\n");
				}
			}

			else
			{
				printf("\nBir sonraki ucak 3 saat sonra kalkacak.\n");
			}

		case 2:

			if (!plane[economy] && economy < 11)
			{
				printf("\nKoltuk satin alma isleminiz gerceklesti.\nKoltuk numaraniz: %d\n", economy);
				plane[economy] = 1;
				economy++;
				i++;
			}

			else if (economy > 10 && firstClass < 6)
			{
				printf("\nUcagimizin Economy kisminda koltuk kalmamistir.\nFirst Class kismindan bilet ayirtmak ister misiniz?");
				printf("Yanit (E/H): ");
				scanf("%s", response);

				if (toupper(response) == 'E')
				{
					printf("\nKoltuk satin alma isleminiz gerceklesti.\nKoltuk numaraniz: %d\n", firstClass);
					plane[firstClass] = 1;
					firstClass++;
					i++;
				}

				else
				{
					printf("\nBir sonraki ucak 3 saat sonra kalkacak.\n");
				}
			}

			else
			{
				printf("\nBir sonraki ucak 3 saat sonra kalkacak.\n");
			}

		case 0: printf("\nProgram sonlandirildi.");
			return 0;

		default: printf("Hata numara girdiniz lutfen tekrar deneyin.");
			return 0;
		}
	}
	return 0;
}
