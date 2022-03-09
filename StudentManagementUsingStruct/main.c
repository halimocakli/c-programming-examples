#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char s_name[30];
	char s_number[11];
	int midterm_grade;
	int final_grade;
	double average_grade;
	struct student* next;
};
typedef struct student Student;

Student* head = NULL;

double GradeCalculator(int midtermGrade, int finalGrade)
{
	return (midtermGrade * 0.4) + (finalGrade * 0.6);
}

Student* Create()
{
	Student* newStudent = (Student*)malloc(sizeof(Student));

	printf("Ogrenci adini giriniz: ");
	scanf("%s", newStudent->s_name);

	printf("Ogrenci numarasini giriniz: ");
	scanf("%s", newStudent->s_number);

	printf("Ogrencinin vize notunu giriniz: ");
	scanf("%d", &newStudent->midterm_grade);

	printf("Ogrencinin final notunu giriniz: ");
	scanf("%d", &newStudent->final_grade);

	newStudent->average_grade = GradeCalculator(newStudent->midterm_grade, newStudent->final_grade);
	newStudent->next = NULL;

	return newStudent;
}

void AddNewStudent()
{
	Student* addedToHead = Create();

	if (head == NULL)
	{
		head = addedToHead;
	}

	else
	{
		Student* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = addedToHead;
	}
}
void swap(Student* x, Student* y)
{
	double temp = x->average_grade;
	x->average_grade = y->average_grade;
	y->average_grade = temp;
}

void Sort()
{
	int swapped;
	Student* temp = head;
	Student* secondTemp = NULL;

	if (temp == NULL)
		return;

	do
	{
		swapped = 0;

		while (temp->next != NULL)
		{
			if (temp->average_grade < temp->next->average_grade)
			{
				swap(temp, temp->next);
				swapped = 1;
			}
			temp = temp->next;
		}
		secondTemp = temp;
	} while (swapped);

	head = temp;
}

void PrintStudentList()
{
	Student* temp = head;
	printf("*************************************************************\n");

	if (temp == NULL)
	{
		printf(" Liste Bos\a");
		printf("\n*************************************************************\n");
		return;
	}

	while (temp != NULL)
	{
		printf("\nOgrenci Adi: %s", temp->s_name);
		printf("\nOgrenci Numarasi: %s", temp->s_number);
		printf("\nOgrenci Vize Notu: %d", temp->midterm_grade);
		printf("\nOgrenci Final Notu: %d", temp->final_grade);
		printf("\nOgrencinin Not Ortalamasi: %f", temp->average_grade);
		printf("\n *************************************************************");
		temp = temp->next;
	}
	printf("\n *************************************************************");
	printf("\n");
}

void UpdateStudent()
{
	Student* temp = head;
	char tempStudentNumber[11];

	printf("\nGuncellemek istediginiz ogrencinin numarasini giriniz: ");
	scanf("%s", tempStudentNumber);

	while (strcmp(tempStudentNumber, temp->s_number) != 0)
	{
		temp = temp->next;
	}

	printf("\n\"%s\" numarali ogrencinin yeni vize notunu giriniz: ", tempStudentNumber);
	scanf("%d", &temp->midterm_grade);

	printf("\n\"%s\" numarali ogrencinin yeni final notunu giriniz: ", tempStudentNumber);
	scanf("%d", &temp->final_grade);
}

void AverageGrade()
{
	double average;
	double total = 0;
	int counter = 0;

	Student* temp = head;

	while (temp != NULL)
	{
		total = total + temp->average_grade;
		counter = counter + 1;
		temp = temp->next;
	}

	average = total / counter;
	printf("\nAverage: %.2f", average);
}

void PrintMenu()
{
	printf("\n***************** MENU *****************");
	printf("\n1- Yeni Kayit Ekle");
	printf("\n2- Kayitlari Listele");
	printf("\n3- Mevcut Kaydi Guncelle");
	printf("\n4- Sinif Ortalamasi Hesapla");
	printf("\n5- Ogrencileri Not Ortalamasi Sirasina Gore Listele");
	printf("\n****************************************");
}

int main()
{
	int selection;
	PrintMenu();
	do
	{
		printf("\nYapmak istediginiz islemi secin: ");
		scanf("%d", &selection);
		printf("----------------------------------------\n");

		switch (selection)
		{
		case 0: printf(" Program basariyla sonlandirildi...");
			break;
		case 1: AddNewStudent();
			break;
		case 2: PrintStudentList();
			break;
		case 3: UpdateStudent();
			break;
		case 4: AverageGrade();
			break;
		case 5: Sort();
			break;
		default: printf("Yanlis tuslama yaptiniz...");
			break;
		}
	} while (selection != 0);

	return 0;
}
