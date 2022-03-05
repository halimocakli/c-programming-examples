#include <stdio.h>
#include <stdlib.h>

int* make_array(size_t size, int init_val);
void print_array(int* ptr, int len);

int main()
{
	size_t size;
	int eleman_degeri;
	int* dizi;

	printf("Kac Elemanli Bir Dizi Olusturmak Istiyorsunuz : ");
	scanf("%d", &size);

	printf("Dizinin Elemanlarina Girilecek Deger  Ne Olsun : ");
	scanf("%d", &eleman_degeri);

	dizi = make_array(size, eleman_degeri);
	print_array(dizi, size);

	return 0;
}

int* make_array(size_t size, int init_val)
{
	int i = 0;
	int* ptr = (int*)malloc(sizeof(int) * size);

	if (ptr != NULL)
	{
		for (i; i < size; ++i)
		{
			*(ptr + i) = init_val;
		}
		return ptr;
	}
}

void print_array(int* ptr, int len)
{
	printf("\n");
	int i = 0;
	for (i; i < len; ++i)
	{
		printf("%d ", ptr[i]);
	}
}
