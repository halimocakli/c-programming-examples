#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 4
#define MINENUMBER 6

void Placement(int[][M], int, int);
void PrintArray(int[][M], int, int);
int main()
{
	int gameTable[N][M] = {0};
	int i;
	int j;

	srand(time(NULL));
	Placement(gameTable, N, M);
	PrintArray(gameTable, N, M);

	return 0;
}

void Placement(int array[][M], int row, int column)
{
	int counter;
	int tmpRow;
	int tmpColumn;

	for (counter = 0; counter < MINENUMBER; counter++)
	{
		tmpRow = rand() % row;
		tmpColumn = rand() % column;

		if (array[tmpRow][tmpColumn] == 0)
		{
			array[tmpRow][tmpColumn] = 1;
		}
		else
		{
			counter--;    /* Islemin yapilmasini garantiliyoruz */
		}
	}
}

void PrintArray(int array[][M], int row, int column)
{
	int i;
	int j;

	for (i = 0; i < row; i++)
	{
		printf("\n");
		for (j = 0; j < column; j++)
		{
			printf(" %d", array[i][j]);
		}
	}
}
