#include <stdio.h>
#include <stdlib.h>
#define M 30
#define N 30

int main()
{
	//int imageMatrix[5][5]={{105,102,100,97,96},
	//      {103,99,103,101,102},
	//      {101,98,104,102,100},
	//      {99,101,106,104,99},
	//      {104,104,104,100,98}};

	//int kernelMatrix[3][3]={{0,-1,0},{-1,5,-1},{0,-1,0}};
	int estimated;

	printf("\n-------------KONVOLUSYON FILTRELEME ISLEMI BASLATILIYOR-------------\n\n");

	int kernelMatrix[3][3];
	int imageMatrix[M][N];
	int secImageMatrix[M][N];
	int outputMatrix[M][N];
	int sonuc = 0;
	int i, j, k, z;
	int satirSayisi, sutunSayisi;
	int outMtxRow, outMtxClm;
	int secImageMtxRow, secImageMtxClm;

	//imageMatrix Boyutu Kullanici Tarafindan Belirleniyor

	printf("Olusturacaginiz Ana Matrisin Satir Sayisini Giriniz:");
	scanf("%d", &satirSayisi);

	printf("\nOlusturacaginiz Ana Matrisin Sutun Sayisini Giriniz:");
	scanf("%d", &sutunSayisi);

	printf("\n******************************************************\n");

	//imageMatrix Rastgele Sayilardan Olusturuluyor

	printf("\nRastgele Sayilardan Oluturulan Image Matris Yazdiriliyor\n\n");

	for (i = 0; i < satirSayisi; i++)
	{
		for (j = 0; j < sutunSayisi; j++)
		{
			estimated = 1 + rand() % 100;
			imageMatrix[i][j] = estimated;
		}
	}

	outMtxRow = satirSayisi - 2;                //Filtreleme Isleminde Kontrol Sayaci Olarak Kullanilacak
	outMtxClm = sutunSayisi - 2;                //Filtreleme Isleminde Kontrol Sayaci Olarak Kullanilacak

	secImageMtxRow = satirSayisi + 2;             //Kenar Elemanlari Eklemek Icin Olusturulacak Matrisin Satir Boyutu
	secImageMtxClm = sutunSayisi + 2;             //Kenar Elemanlari Eklemek Icin Olusturulacak Matrisin Sutun Boyutu


	/*//imageMatrix Kullanici Tarafindan Belirleniyor

	for(i = 0; i < satirSayisi; i++)
	{
		for(j = 0; j < sutunSayisi; j++)
		{
			printf("\nDizinin %d.Satir - %d.Sutun Verisini Giriniz:",i+1,j+1);
			scanf("%d",&imageMatrix[i][j]);
		}

	}*/

	//imageMatrix Yazdiriliyor

	printf("\n******************************************************\n");

	printf("\n\n...Ana Matris Asagidaki Gibidir...\n\n");

	for (i = 0; i < satirSayisi; i++)
	{
		for (j = 0; j < sutunSayisi; j++)
		{
			printf("%d\t", imageMatrix[i][j]);
		}
		printf("\n\n");
	}

	//Kullanici 3x3 Kernel Matrisini Belirliyor

	printf("\n\n...3x3 Boyutlu Kernel Matrisi Olusturuluyor...\n\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("Kernel Matris %d.Satir - %d.Sutun ---->", i + 1, j + 1);
			scanf("%d", &kernelMatrix[i][j]);
		}
	}

	printf("\n\n");

	//Kullanicinin Belirledigi Kernel Matrisi Yazdiriliyor

	printf("...Kernel Matrisi Asagidaki Gibidir...\n\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d\t", kernelMatrix[i][j]);
		}
		printf("\n\n");
	}

	//Filtreleme Islemi Gerceklesitiriliyor

	for (k = 0; k < outMtxRow; k++)
	{
		for (z = 0; z < outMtxClm; z++)
		{
			sonuc = 0;

			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					sonuc += imageMatrix[i + k][j + z] * kernelMatrix[i][j];
					outputMatrix[k][z] = sonuc;
				}
			}
		}
	}

	printf("\n\n");

	//outputMatrix imageMatrix'e Aktariliyor

	for (k = 0; k < outMtxRow; k++)
	{
		for (z = 0; z < outMtxClm; z++)
		{
			imageMatrix[k + 1][z + 1] = outputMatrix[k][z];
		}
	}

	//outputMatrix Sifirlaniyor

	for (k = 0; k < outMtxRow; k++)
	{
		for (z = 0; z < outMtxClm; z++)
		{
			outputMatrix[k][z] = 0;
		}
	}

	//Filtreleme Islemine Tabii Tutulan imageMatrix Yazdiriliyor

	printf("...Filtreleme Islemine Tabi Tutulan imageMatrix Asagidaki Gibidir...\n\n");

	for (i = 0; i < satirSayisi; i++)
	{
		for (j = 0; j < sutunSayisi; j++)
		{
			printf("[%d]\t ", imageMatrix[i][j]);
		}
		printf("\n\n");
	}

	printf("\n\n");

	/*//Filtreleme Islemine Tabii Tutulan imageMatrix Yazdiriliyor (Sadece Filtrelenen Kisim)

	printf("Kernel Matris Filtresine Tabii Tutulan Matris Asagidaki Gibidir...\n\n");

	for(i = 0;i < outMtxRow ;i++)
	{
		for(j = 0; j < outMtxClm; j++)
		{
			printf("[%d] ",outputMatrix[i][j]);
		}
		printf("\n\n");
	}*/

	//secImageMatrix Olusturuluyor

	printf("\nKenarlara 0 Ekleniyor\n\n\n");

	for (i = 0; i < secImageMtxRow; i++)
	{
		for (j = 0; j < secImageMtxClm; j++)
		{
			secImageMatrix[i][j] = 0;
		}
	}

	//imageMatrix, secImageMatrix Icine Aktariliyor

	for (i = 0; i < satirSayisi; i++)
	{
		for (j = 0; j < sutunSayisi; j++)
		{
			secImageMatrix[i + 1][j + 1] = imageMatrix[i][j];
		}
	}

	//secImageMatrix Yazdiriliyor

	for (i = 0; i < secImageMtxRow; i++)
	{
		for (j = 0; j < secImageMtxClm; j++)
		{
			printf("%d\t", secImageMatrix[i][j]);
		}
		printf("\n\n");
	}

	//Kenar Elemanlari Filtrelemeye Tabii Tutuluyor

	for (k = 0; k < satirSayisi; k++)
	{
		for (z = 0; z < sutunSayisi; z++)
		{
			sonuc = 0;

			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					sonuc += secImageMatrix[i + k][j + z] * kernelMatrix[i][j];
					outputMatrix[k][z] = sonuc;
				}
			}
		}
	}

	//Son Filtreleme Isleminden Sonra Dizi Yazdiriliyor

	printf("\n...Kenar Elemanlari Filtreye Tabii Tutuldu...\n\n\n");

	for (k = 0; k < satirSayisi; k++)
	{
		for (z = 0; z < sutunSayisi; z++)
		{
			printf("%d\t", outputMatrix[k][z]);
		}
		printf("\n\n");
	}

	printf("\n\n");

	//Dizi secImageMatrix'e Aktariliyor

	for (i = 0; i < satirSayisi; i++)
	{
		for (j = 0; j < sutunSayisi; j++)
		{
			secImageMatrix[i + 1][j + 1] = outputMatrix[i][j];
		}
	}

	//Dizinin Son Hali Yazdiriliyor

	printf("Kenarlara Tekrar Sifir Eklendi\n\n");

	for (i = 0; i < secImageMtxRow; i++)
	{
		for (j = 0; j < secImageMtxClm; j++)
		{
			printf("%d\t", secImageMatrix[i][j]);
		}
		printf("\n\n");
	}

	return 0;
}