/* Mod fonksiyonuna histogram opsiyonu ekle */
/* Birden fazla mod bulma işini çöz */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 101    /* FindMode() fonksiyonu icin olusturuldu */
#define N 30    /* Dizi boyutu */

int Menu();
void PrintArray(int array[], int n);                        /* Dizi yazdiran fonksiyon */
void RandomFiller(int array[], int n);                        /* Diziyi rastgele degerlerle dolduran fonksiyon */
void BubbleSort(int array[],
		int n);                        /* Bubble Sort Algoritmasi kullanarak dizi elemanlarini siralayan fonksiyon */
void SelectionSort(int array[],
		int n);                        /*	Selection Sort Algoritmasi kullanarak dizi elemanlarini siralayan fonksiyon */
int LinearSearch(int array[], int n,
		int searchedValue);    /* Linear Search Algoritmasi kullanarak belirlenen elemani bulan fonksiyon */
int BinarySearch(int array[], int n,
		int searchedValue);    /* Binary Search Algoritmasi kullanarak belirlenen elemani bulan fonksiyon */
float
FindAverage(int array[], int n);                        /* Dizinin degerlerini toplayip ortalamayi bulan fonksiyon */
float FindMedian(int array[], int n);                        /* Dizinin medyan degerini bulan fonksiyon */
int FindMode(int array[], int n);                            /* Dizide en cok tekrar eden degeri bulan fonksiyon */
int FindMinValue(int array[], int n);                        /* Dizinin en kucuk elemanini bulan fonskiyon */
int FindMaxValue(int array[], int n);                        /* Dizinin en buyuk elemanini bulan fonksiyon */

int main()
{
	int array[N] = {0};

	int choice;            /* Switch - Case yapisinde tercih yapabilmek icin olusturuldu */
	int searchedValue;    /* Dizide aranan deger */
	int index;            /* Aranan degerin dizide olup olmadigini kontrol etmek amacıyla Binary Search ve Linear Search Algoritmalari icin olusturuldu */

	srand(time(NULL));    /* Rastgele sayi ureteci */
	do
	{
		choice = Menu();    /* menu() fonksiyonu cagirildi */
		switch (choice)
		{
		case 0: printf("Execution has ended successfully...\n");
			break;
		case 1: RandomFiller(array, N);
			printf("Array has filled with random numbers...\n");
			break;
		case 2: PrintArray(array, N);
			break;
		case 3: BubbleSort(array, N);
			printf("Array has sorted...\n");
			break;
		case 4: SelectionSort(array, N);
			printf("Array has sorted...\n");
			break;
		case 5: printf("Insert the value that I'm gonna search it by using Linear Search Algorithm: ");
			scanf("%d", &searchedValue);
			index = LinearSearch(array, N, searchedValue);
			if (index == -1)
			{
				printf("The value you've entered was not found\n");
			}
			else
			{
				printf("The value you've entered is in %d. index of array.\n", index);
			}
			break;
		case 6: printf("Insert the value that I'm gonna search it by using Binary Search Algorithm: ");
			scanf("%d", &searchedValue);
			index = BinarySearch(array, N, searchedValue);
			if (index == -1)
			{
				printf("The value you've entered was not found");
			}
			else
			{
				printf("The value you've entered is in %d. index of array.\n", index);
			}
			break;
		case 7: printf("Average is: %.2f", FindAverage(array, N));
			break;
		case 8: printf("Median is: %.2f", FindMedian(array, N));
			break;
		case 9: printf("Mode is: %d", FindMode(array, N));
			break;
		case 10: printf("Average value is: %.3f", FindAverage(array, N));
			break;
		case 11: printf("Minimum value in the array is: %d", FindMinValue(array, N));
			break;
		case 12: printf("Maximum value in the array is: %d", FindMaxValue(array, N));
			break;
		default: printf("\n Incorrect Entry \a\n ");
		}
	} while (choice
			!= 0);    /* menu() fonksiyonu icersinde kullanicidan alinan choice degiskeni 0 olmadigi muddetce dongu devam eder */

	return 0;
}

int Menu()
{
	int choice;

	printf("\n\n__________________MENU__________________\n");
	printf("0- End Process \n");
	printf("1- Fill the array with random numbers which numbers are between 0 and 100...\n");
	printf("2- Print Array \n");
	printf("3- Sort the Array by using Bubble Sort Algorithm \n");
	printf("4- Sort the Array by using Selection Sort Algorithm \n");
	printf("5- Search the Given Value in Array by using Linear Search Algorithm \n");
	printf("6- Search the Given Value in Array by using Binary Search Algorithm \n");
	printf("7- Mean\n");
	printf("8- Median\n");
	printf("9- Mode\n");
	printf("10- Average\n");
	printf("11- Minimum Value\n");
	printf("12- Maximum Value\n");
	printf("------------------------------------------\n");
	printf("Insert Your Choice: ");
	scanf("%d", &choice);
	printf("-----------------------------------------\n");

	return choice;
}

/* Diziyi yazdiran fonksiyon */
void PrintArray(int array[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("\n%d. Number is: %d", i + 1, array[i]);
	}
}

/* Diziyi rastgele degerlerle dolduran fonksiyon */
void RandomFiller(int array[], int n)
{
	int m;
	for (m = 0; m < n; m++)
	{
		array[m] = rand() % M;
	}
}

/* Bubble Sort Algoritmasi kullanarak dizi elemanlarini siralayan fonksiyon */
void BubbleSort(int array[], int n)
{
	int pass;
	int temp;
	int j;

	for (pass = 1; pass < n; pass++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

/* Selection Sort Algoritmasi kullanarak dizi elemanlarini siralayan fonksiyon */
void SelectionSort(int array[], int n)
{
	int k;
	int m;
	int temp;
	int smaller;

	for (k = 0; k < n - 1; k++)
	{
		smaller = k;
		for (m = k + 1; m < n; m++)
		{
			if (array[m] < array[smaller])
			{
				smaller = m;
			}
		}
		temp = array[k];
		array[k] = array[smaller];
		array[smaller] = temp;
	}
}

/* Linear Search Algoritmasi kullanarak belirlenen elemani bulan fonksiyon */
int LinearSearch(int array[], int n, int searchedValue)
{
	int location = -1;
	int m;

	for (m = 0; m < N; m++)
	{
		if (array[m] == searchedValue)
		{
			location = m;
		}
	}
	return location;
}

/* Binary Search Algoritmasi kullanarak belirlenen elemani bulan fonksiyon */
int BinarySearch(int array[], int n, int searchedValue)
{
	int head = 0;
	int tail = n - 1;
	int mid;

	BubbleSort(array, n);
	while (head <= tail)
	{
		mid = (head + tail) / 2;
		if (array[mid] == searchedValue)
		{
			return mid;
		}
		else if (array[mid] > searchedValue)
		{
			tail = mid - 1;
		}
		else
		{
			head = mid + 1;
		}
	}
	return -1;
}

/* Dizinin degerlerini toplayip ortalamayi bulan fonksiyon */
float FindAverage(int array[], int n)
{
	float total = 0;
	int i;

	for (i = 0; i < n; i++)
	{
		total += array[i];
	}

	return total / (float)n;
}

/* Dizinin medyan degerini bulan fonksiyon */
float FindMedian(int array[], int n)
{
	BubbleSort(array, n);
	if (n % 2 == 0)
	{
		return (array[(n / 2) - 1] + array[n / 2]) / 2.0;
	}
	else
	{
		return array[n / 2];
	}
}

/* Dizide en cok tekrar eden degeri bulan fonksiyon */
int FindMode(int array[], int n)
{
	int frequence[M - 1] = {0};
	int maxRepeatedValue = 0;
	int m;

	for (m = 0; m < n; m++)
	{
		frequence[array[m]]++;
	}

	for (m = 0; m < M - 1; m++)
	{
		if (frequence[m] > frequence[maxRepeatedValue])
		{
			maxRepeatedValue = m;
		}
	}
	return maxRepeatedValue;
}

/* Dizinin en kucuk elemanini bulan fonskiyon */
int FindMinValue(int array[], int n)
{
	int min;
	int i;

	min = array[0];
	for (i = 0; i < n; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}

	return min;
}

/* Dizinin en buyuk elemanini bulan fonksiyon */
int FindMaxValue(int array[], int n)
{
	int max;
	int i;

	max = array[0];
	for (i = 0; i < n; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return max;
}