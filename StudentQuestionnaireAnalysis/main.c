#include <stdio.h>
#define ANSWERSIZE  40
#define FREQUENCYSIZE   11

/*  Her dizi boyutunu sembolik bir sabitle belirtmek programlari daha fazla orneklendirebilir hale getirir */

/* 40 adet ogrenciden, ogrenci kafeteryasindaki yiyecekleri yiyeceklerin kalitesini 1-10 arasinda puanlamalarini istenmiştir. */
/* (1: kotü, 10: cok iyi) 40 adet sonucu bir tamsayi dizisinde tutunuz ve anket sonuclarini ozetleyiniz. */


int main()
{
	size_t answer;
	size_t point;

	/* frequence sayacina 0 atandi*/
	int frequency[FREQUENCYSIZE] = {0};

	/* Anket sonuclari answerArr dizisine ataniyor */
	int answerArr[ANSWERSIZE] = {1, 2, 6, 4, 8, 5, 9, 7, 8, 10,
								 1, 6, 3, 8, 6, 10, 3, 8, 2, 7, 6, 5, 7, 6, 8, 6, 7, 5, 6, 6,
								 5, 6, 7, 5, 6, 4, 8, 6, 8, 10};

	/* Her cevap icin answerArr dizisindeki elemanin degerinin secilmesi ve bu degerin */
	/* frequence dizisinde indis olarak eleman arttirilmasi icin kullanilmasi */
	for (answer = 0; answer < ANSWERSIZE; ++answer)
	{
		++frequency[answerArr[answer]];
	}

	/* Sonuclarin goruntulenmesi */
	printf("%2s%17s\n", "Votes", "Frequency");

	/* frekanslarin cizelge biciminde bastirilmasi */
	for (point = 1; point < FREQUENCYSIZE; ++point)
	{
		printf("%5d%17d\n", point, frequency[point]);
	}

	return 0;
}