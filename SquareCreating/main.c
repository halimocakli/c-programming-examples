#include <stdio.h>
#include <stdlib.h>

void fillCharacter(int kenar, char sekil);

int main()
{
	int kenar;
	char sekil;

	printf("Lutfen Olusturmak Istediginiz Bilesen Seklini Giriniz: ");
	scanf("%c", &sekil);

	printf("Lutfen Olusturmak Istediginiz Karenin Kenar Boyutunu Giriniz: ");
	scanf("%d", &kenar);

	printf("\n");

	fillCharacter(kenar, sekil);
	return 0;
}

void fillCharacter(int kenar, char sekil)
{
	int i, j;

	for (i = 0; i < kenar; ++i)
	{
		for (j = 0; j < kenar; ++j)
		{
			printf("%c ", sekil);
		}
		printf("\n");
	}
}
