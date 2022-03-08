#include <stdio.h>
#include <stdlib.h>

int linearSearchAlgorithm(int array[], int searchNumber, int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		if (array[i] == searchNumber)
		{
			return i;
		}
	}
	return -1;  //Basarisiz dönüs
}

int main()
{
	int i;
	int userSearchNumber;
	int result;

	int userArray[] = {1, 2, 3, 4, 5, 7, 9, 11, 15, 8, 67, 90, 45, 23};
	int sizeOfUserArray = sizeof(userArray) / sizeof(int);

	printf("Array Printing: ");
	for (i = 0; i < sizeOfUserArray; ++i)
	{
		printf("%d ", userArray[i]);
	}

	printf("\nInsert Your Search Number: ");
	scanf("%d", &userSearchNumber);

	result = linearSearchAlgorithm(userArray, userSearchNumber, sizeOfUserArray);

	if (result == -1)
	{
		printf("Your Search Number Couldn't Find...");
	}
	else
	{
		printf("Your Search Number Places At %d. Index Of Array", result);
	}

	return 0;
}