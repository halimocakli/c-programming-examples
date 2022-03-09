#include <stdio.h>
#define SIZE 20

/* Karakter dizilerinin karakter dizinleri gibi gosterilmesi, string to char */

int main()
{
	char string1[SIZE]; /* Diziye 20 karakter ayirildi */
	char string2[] = "String Literal"; /* 14 karakterlik alan ayrildi */
	size_t i; /* sayac */

	/* Kullanicidan karakter dizini alınıyor */
	printf("%s", "En fazla 19 karakter icermesi sartiyla bir karakter dizini giriniz:");
	scanf("%19s", string1); /* %19s belirteci kullanilarak 19 karakterden fazla okunmasinin engellenmesi */

	/* Karakter dizininin gosterilmesi */
	printf("string1 : %s\nstring2 : %s\n"
		   "string1'in karakterler arasi bosluk birakilarak yazdirilmasi: ",
			string1, string2);

	/* null karakter gelene kadar ekrana yazdirilmasi */
	for (i = 0; i < SIZE && string1[i] != '\0'; ++i)
	{
		printf("%c ", string1[i]);
	}

	puts("");

	return 0;
}