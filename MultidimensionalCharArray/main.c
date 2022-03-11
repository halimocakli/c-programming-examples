#include <stdio.h>
#include <conio.h>
#define MAX 100
#define LEN 80

char text[MAX][LEN];

int main()
{
	register int t;
	register int i;
	register int j;

	printf("Enter an empty line to quit.\n");

	for (t = 0; t < MAX; ++t)
	{
		printf("%d: ", t);
		gets(text[t]);

		if (!*text[t])
			break;      /* bos satirda cik */
	}

	for (i = 0; i < t; ++i)
	{
		for (j = 0; text[i][j]; j++)
		{
			putchar(text[i][j]);
			puts("");
		}

	}

	getch();
	return 0;
}