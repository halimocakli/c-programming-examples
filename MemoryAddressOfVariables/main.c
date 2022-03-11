#include <stdio.h>

int main()
{
	int a = 45;
	double b = 4.5;
	char c = 'g';

	// Degiskenlerin tuttuklari degerleri ekrana yazdiralim
	printf("a Degiskeninin icerdigi deger: %d\n", a);
	printf("b Degiskeninin icerdigi deger: %f\n", b);
	printf("c Degiskeninin icerdigi deger: %c\n", c);

	printf("\n");

	// Degiskenlerin bellekteki adreslerini ekrana yazdiralim
	printf("a Degiskeninin bellekteki adresi: %X\n", &a);
	printf("b Degiskeninin bellekteki adresi: %X\n", &b);
	printf("c Degiskeninin bellekteki adresi: %X\n", &c);

	return 0;
}
