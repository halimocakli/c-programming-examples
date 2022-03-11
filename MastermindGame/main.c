#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 4

void RandomColors(char computerColorChoices[], const unsigned int size)
{
	int randomColor;

	for (int i = 0; i < size; i++)
	{
		randomColor = 1 + rand() % 6;

		switch (randomColor)
		{
		case 1: computerColorChoices[i] = 'R';
			break;
		case 2: computerColorChoices[i] = 'G';
			break;
		case 3: computerColorChoices[i] = 'B';
			break;
		case 4: computerColorChoices[i] = 'Y';
			break;
		case 5: computerColorChoices[i] = 'P';
			break;
		case 6: computerColorChoices[i] = 'O';
			break;
		default: break;
		}
	}
}

void match1(const char computer_color_choices[], const char user_color_choices[], const unsigned int size)
{
	int i = strcmp(computer_color_choices, user_color_choices);
}

void userInterface()
{
	printf("");
}

int main()
{
	srand(time(NULL));

	char userColorChoices[SIZE];
	char computerColorChoices[SIZE];
	char wantToSee;
	unsigned int userPredictionRight;

	printf("How many times the user can try to predict? Please insert: ");
	scanf("%u", &userPredictionRight);

	RandomColors(computerColorChoices, SIZE);

	printf("Do you want to see the colors that computer has chosen? [Y/N]: ");
	scanf("%c", &wantToSee);

	if (toupper(wantToSee) == 'Y')
	{
		for (int i = 0; i < SIZE; i++)
		{
			printf("%c", computerColorChoices[i]);
		}
		printf("\n");
	}

	for (int i = 0; i < userPredictionRight; i++)
	{
		printf("Insert your prediction: ");
		scanf("%s", userColorChoices);

		match1(computerColorChoices, userColorChoices, SIZE);
	}
}