#include <stdbool.h>
#include <stdio.h>
#define R_SIZE 6    // Satır Sayısı
#define C_SIZE 12    // Sütun Sayısı

bool IsSafe(int _mainMatrix[][C_SIZE], int x, int y)
{
	if (x >= 0 && x < R_SIZE && y >= 0 && y < C_SIZE && _mainMatrix[x][y] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ShortestPathFinderUtility(int _mainMatrix[][C_SIZE], int _visitedCells[][C_SIZE], int x, int y)
{
	if (x == (R_SIZE - 1) && y == (C_SIZE - 1) && _mainMatrix[x][y] == 1)
	{
		_visitedCells[x][y] = 1;
		return true;
	}

	if (IsSafe(_mainMatrix, x, y) == true)
	{
		if (_visitedCells[x][y] == 1)
		{
			return false;
		}

		_visitedCells[x][y] = 1;

		if (ShortestPathFinderUtility(_mainMatrix, _visitedCells, x + 1, y) == true)
		{
			return true;
		}
		if (ShortestPathFinderUtility(_mainMatrix, _visitedCells, x, y + 1) == true)
		{
			return true;
		}
		if (ShortestPathFinderUtility(_mainMatrix, _visitedCells, x - 1, y) == true)
		{
			return true;
		}
		if (ShortestPathFinderUtility(_mainMatrix, _visitedCells, x, y - 1) == true)
		{
			return true;
		}

		_visitedCells[x][y] = 0;
		return false;
	}
	return false;
}

bool ShortestPathFinder(int _mainMatrix[][C_SIZE], int _visitedCells[][C_SIZE])
{
	if (ShortestPathFinderUtility(_mainMatrix, _visitedCells, 0, 0) == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void PrintSolutionMatrix(int _solutionMatrix[R_SIZE][C_SIZE])
{
	int i;
	int j;
	for (i = 0; i < R_SIZE; i++)
	{
		for (j = 0; j < C_SIZE; j++)
		{
			printf("%d ", _solutionMatrix[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int mainMatrix[R_SIZE][C_SIZE] = {{ 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0 },
									  { 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0 },
									  { 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0 },
									  { 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
									  { 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1 },
									  { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 }};

	int visitedCells[R_SIZE][C_SIZE] = {{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};

	if (ShortestPathFinder(mainMatrix, visitedCells) == true)
	{
		PrintSolutionMatrix(visitedCells);
	}
	else
	{
		printf("Path doesn't exist");
	}
	return 0;
}