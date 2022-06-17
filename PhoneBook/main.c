#include <stdio.h>
#include <string.h>

struct record {
	char name[16];
	char surname[22];
	char phoneNumber[11];
};
typedef struct record Directory;

void Menu();
int AddPhoneNumber();
int ListPhoneNumbers();
int Search();

int main()
{
	int selection = -1;
	char searchedName[16];
	int findNumber = -1;

	Menu();

	do
	{

	} while (selection != 4);

	return 0;
}
