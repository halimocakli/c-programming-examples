#include<stdio.h>
#define STUDENTS   3
#define EXAMS   4

/* iki boyutlu dizilerde islemler */

int minimum(int grades[][EXAMS], size_t pupils, size_t tests);
int maximum(int grades[][EXAMS], size_t pupils, size_t tests);
double average(const int setOfGrades[], size_t tests);
void printArray(int grades[][EXAMS], size_t pupils, size_t tests);

int main()
{
	size_t student; /* ogrenci sayaci */

	/* 3 ogrencinin notlarina baslangic degeri atanmasi(satirlardaki) */
	int studentGrades[STUDENTS][EXAMS] =
			{{77, 68, 86, 73},
			 {96, 87, 89, 78},
			 {70, 90, 86, 81}};

	/* studentGrades dizisinin elemanlarinin ekrana yazdirilmasi */
	puts("Dizi:");
	printArray(studentGrades, STUDENTS, EXAMS);

	/* en yuksek ve dusuk notlarin tespiti */
	printf("\n\nEn dusuk not: %d\nEn yuksek not: %d\n",
			minimum(studentGrades, STUDENTS, EXAMS),
			maximum(studentGrades, STUDENTS, EXAMS));

	/* her ogrencinin not ortalamasini hesaplama */
	for (student = 0; student < STUDENTS; ++student)
	{
		printf("Ogrenci %u'nin ortalama notu = %.2f\n",
				student, average(studentGrades[student], EXAMS));
	}

	return 0;
}

/* en dusuk notun tespiti */
int minimum(int grades[][EXAMS], size_t pupils, size_t tests)
{
	size_t i;   /* ogrenci sayaci */
	size_t j;   /* sinav sayaci */
	int lowGrade = 100; /* en yuksek muhtemel notun baslangic olarak atanmasi */

	/* satirdaki notlar arasinda olusan dongu */
	for (i = 0; i < pupils; ++i)
	{
		/* sutundaki notlar arasinda dolasan dongu */
		for (j = 0; j < tests; ++j)
		{
			if (grades[i][j] < lowGrade)
			{
				lowGrade = grades[i][j];
			}
		}
	}

	return lowGrade;    /* en dusuk notun dondurulmesi */
}

/* en yuksek notun tespit edilmesi */
int maximum(int grades[][EXAMS], size_t pupils, size_t tests)
{
	size_t i;   /* ogrenci sayaci */
	size_t j;   /* sinav sayaci */
	int highGrade = 0;  /* en dusuk muhtemel notun baslangic degeri olarak atanmasi */

	/* satirdaki notlar arasinda dolasma */
	for (i = 0; i < pupils; ++i)
	{
		/* sutundaki notlar arasinda dolasma */
		for (j = 0; j < tests; ++j)
		{
			if (grades[i][j] > highGrade)
			{
				highGrade = grades[i][j];
			}
		}
	}

	return highGrade;
}

/* belirli bir ogrencinin not ortalamasinin hesabi */
double average(const int setOfGrades[], size_t tests)
{
	size_t i;   /* sinav sayaci */
	int total = 0;  /* sinav notlarinin toplami */

	/* bir ogrencinin tum notlarinin toplami */
	for (i = 0; i < tests; ++i)
	{
		total += setOfGrades[i];
	}

	return (double)total / tests;  /* ortalama */
}

/* dizinin yazdirilmasi */
void printArray(int grades[][EXAMS], size_t pupils, size_t tests)
{
	size_t i;   /* ogrenci sayaci */
	size_t j;   /* sinav sayaci */

	/* sutun basliklarinin yazdirilmasi */
	printf("%s", "                 [0] [1] [2] [3]");

	/* notlarin cizelge biciminde yazdirilmasi */
	for (i = 0; i < pupils; ++i)
	{
		/* satir etiklerinin yazdirilmasi */
		printf("\nStudentGrades[%d] ", i);

		/* bir ogrencinin notlarinin yazdirilmasi */
		for (j = 0; j < tests; ++j)
		{
			printf("%-5d", grades[i][j]);
		}
	}
}