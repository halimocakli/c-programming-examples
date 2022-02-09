#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 4

/* strrev() fonksiyonu linux üzerinde çalışmıyor. Karakter dizisiniz ters çeviren bir fonksiyon yaz */

void MatrixGenerator(char decoderMatrix[][SIZE])
{
	printf("The MatrixGenerator() function has ran...\n\n");
	printf("Insert members of Decoder Matrix...\n\n");

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("Insert DecoderMatrix[%d][%d]: ", i, j);
			scanf(" %c", &decoderMatrix[i][j]);
		}
	}
	printf("\n\n");
}

void Decryption(char decoderMatrix[][SIZE], int userCrypto, char* decryptedText)
{

	int i;
	int j;

	int letterFinder;
	int counter = 0;

	while (userCrypto != 0)
	{
		letterFinder = userCrypto % 100;

		i = (letterFinder / 10) - 1;
		j = (letterFinder % 10) - 1;

		*(decryptedText + counter) = decoderMatrix[i][j];
		counter++;
		userCrypto = userCrypto / 100;
	}
	strrev(decryptedText);
}

int UserCryptoLengthCalc(int user_crypto)
{
	int length = 0;

	while (user_crypto != 0)
	{
		user_crypto = user_crypto / 10;
		length++;
	}
	return length;
}

void PrintMatrix(char decoderMatrix[][SIZE])
{
	printf("Decoder matrix has printed...\n\n");

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%c\t", toupper(decoderMatrix[i][j]));
		}
		printf("\n\n");
	}
}

void ToUpperForString(char* decrypted_text)
{
	for (int i = 0; decrypted_text[i] != '\0'; i++)
	{
		if (decrypted_text[i] >= 'a' && decrypted_text[i] <= 'z')
		{
			decrypted_text[i] = decrypted_text[i] - 32;
		}
	}
}

int main()
{
	char decoderMatrix[SIZE][SIZE] = { 'X' };
	char* decryptedText;
	int userCrypto = 0;
	int decryptedTextLength;

	MatrixGenerator(decoderMatrix);
	system("cls");
	PrintMatrix(decoderMatrix);

	printf("-----------------------------------------------------------------------\n");

	do
	{
		printf("Insert your crypto code[CODE'S NUMBER OF DIGITS MUST BE A MULTIPLE OF 2]: ");
		scanf("%d", &userCrypto);

		if (UserCryptoLengthCalc(userCrypto) % 2 != 0)
		{
			printf("Code's number of digits is not multiple of 2, try again!!!\n");
		}
	} while (UserCryptoLengthCalc(userCrypto) % 2 != 0);

	printf("\n-----------------------------------------------------------------------\n");

	decryptedTextLength = (UserCryptoLengthCalc(userCrypto)) / 2;
	decryptedText = (char*)malloc(decryptedTextLength * sizeof(char));// bu kısmı düzenle

	Decryption(decoderMatrix, userCrypto, decryptedText);
	ToUpperForString(decryptedText);

	printf("\nEncrypted text resolved: %u -> %s", userCrypto, decryptedText);

	return 0;
}
