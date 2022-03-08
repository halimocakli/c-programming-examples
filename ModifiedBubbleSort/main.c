#include <stdio.h>

void bubble_sort(int array[], int size);    /* bubble sort algoritma fonksiyonunun prototipi */
void print_array(int array[], int size);    /* dizi yazdirma fonksiyonunun prototipi */

int main(void)
{
	int a[10] = {6, 4, 4, 2, 7, 5, 1, 8, 15, 12};
	bubble_sort(a, 10);

	return 0;
}

void bubble_sort(int array[], int size)
{
	int pass;        /* sayac */
	int i;            /* vektor dizini */
	int hold;        /* gecici degisken */
	int flag;        /* dizi siralama kontrolu */

	for (pass = 1; pass < size; pass++)
	{
		flag = 0;

		printf("\nThe array before sorting pass\n");
		print_array(array, size);
		printf("let's sort it...\n");

		for (i = 0; i < size - pass; i++)
		{
			if (array[i] > array[i + 1])
			{
				hold = array[i];
				array[i] = array[i + 1];
				array[i + 1] = hold;

				print_array(array, size);

				flag = 1;
			}
		}
		printf("\n\n%d\n\n", flag);

		/* siralamaya devam etme ya da etmeme kontrolu */
		if (!flag)        /* eger degisim yoksa */
			break;        /* bir sonraki siralama suracine gec */
	}
}

void print_array(int array[], int size)
{
	int index;

	for (index = 0; index < size; index++)
	{
		printf("%3d ", array[index]);
	}

	printf("\n");
}