#include <stdio.h>

#define SATIR (6)
#define SUTUN (12)

void labirentYazdir(int labirent[SATIR][SUTUN]);

int izci(int labirent[SATIR][SUTUN], int x, int y);

int main(void)
{

    int labirent[SATIR][SUTUN] ={
                    {1,1,1,1,1,1,1,1,1,1,1,1},
		            {1,0,0,1,0,0,0,0,0,0,0,1},
		            {1,0,0,1,1,0,1,0,1,1,1,1},
		            {1,0,0,0,1,0,1,0,1,0,1,1},
			        {1,0,0,1,1,0,1,0,0,0,0,1},
		            {1,1,1,1,0,0,1,1,1,1,1,1}
		            };

    printf("...Ana Labirent Yazdiriiliyor...\n\n");

    labirentYazdir(labirent);

    if (izci(labirent, 0, 0) == 1)              //izci fonksiyonundan 1 deðeri dönmesi koþulu
    {
        printf("\nLabirent Tamamlandi\a\n\n");
        printf("...Tamamlanan Labirent Yadiriliyor...\n\n");

        labirentYazdir(labirent);   //Sonuclandirilan labirent yazdiriliyor

    }

    return 0;
}

void labirentYazdir(int labirent[SATIR][SUTUN]) //izci fonksiyonu calistirilmadan once ve calistirildiktan sonra diziyi yazdirir
{

    for (int i = 0; i < SATIR; i++)
    {
        for (int j = 0; j < SUTUN; j++)
        {
            printf("%d ", labirent[i][j]);
        }

    printf("\n");
    }
}

int izci(int labirent[SATIR][SUTUN], int x, int y)
{
        labirent[x][y] = 5; ///ilk gelen deger (0.0)

    if (x == SATIR - 1 && y == SUTUN - 1) ///Sonlandirma Kosulu-->x=5 ve y=11 oldugunda yani matris tamamlandiginda durur
    {
        return 1;
    }

    if (y + 1 < SUTUN && labirent[x][y + 1] == 1)   ///Saga Dogru Gidis
    {
        if (izci(labirent, x, y + 1))
        {
            return 1;
        }
    }

    if (x + 1 < SATIR && labirent[x + 1][y] == 1)   ///Asagi Yone Gidis-Saga Gitmeden Once Labirent'ten Cikmadigini Dogrular
    {
        if (izci(labirent, x + 1, y))
        {
            return 1;
        }
    }

    /*if (y + 1 < SUTUN && labirent[x][y + 1] == 1)   ///Saga Dogru Gidis
    {
        if (izci(labirent, x, y + 1))
        {
            return 1;
        }
    }*/

    if (x - 1 >= 0 && labirent[x - 1][y] == 1) ///Yukari Dogru Gidis
    {
        if (izci(labirent, x - 1, y))
        {
            return 1;
        }
    }

    if (y - 1 >= 0 && labirent[x][y - 1] == 1)  ///Sola Dogru Gidis
    {
        if (izci(labirent, x, y - 1))
        {
            return 1;
        }
    }

    labirent[x][y] = 1; /*Eger Gittigi Yonden Devam Edemiyorsa ve Geri Donecekse Geri Donerken
                        Gittigi Yanlis Yolu Duzelterek (1 Yazarak) Doner (Backtracking)*/

    return 0;
}
