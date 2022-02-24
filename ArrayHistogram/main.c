#include <stdio.h>
#define SIZE  10

/* Dizi eleman degerlerinin histogram grafigi ile gosterilmesi */

int main()
{
	/*arr dizisinin elemanlari liste yontemiyle ataniyor */
	int arr[SIZE] = {19, 3, 15, 7, 11, 9, 13, 5, 17, 1};
	size_t i;   /*Dizi elemanlari icin uretilen dıstaki for dongusunun sayaci */
	int j;  /* Her histogram sutunundaki yildizlari sayan icteki for dongusu */

	printf("%s%13s%16s\n", "Personal", "Value", "Histogram");

	/* arr dizisindeki her eleman icin histogram grafigine sutun yazdirilmasi */
	for (i = 0; i < SIZE; ++i)
	{
		printf("%8u%13d\t", i, arr[i]);

		for (j = 0; j < arr[i]; ++j) /* Sutun cizimi */
		{
			printf("%c", '*');
		}
		puts("");
	}
	return 0;
}