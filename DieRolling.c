#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

/* 
 * Bir cift zarin atisini simule eden bir program yaziniz. Program, ilk ve ikinci zar icin
 * iki kez rand fonksiyonu kullanmalidir. Daha sonra cikan iki deger toplanmalidir. Her zar
 * 1-6 arasi deger icerdiginden toplam sonuc 2-12 arasinda degisecek, en cok rastlanan sonuc 
 * 7 olacak ve en az 2 ve 12 sonuclari ortaya cikacak. Programimiz iki zari toplamda 36.000
 * kere atmalidir. Her olasi toplami depolamak icin tek indisli dizi kullaniniz. Sonucu cizelge 
 * olarak gosteriniz. 
 */

/* 1-6 arasi rastgele sayi ureten fonksiyon */
int randomNumberGenerator();

int main()
{
    int firstDie;   /* ilk zar */
    int secondDie;  /* ikinci zar */
    int i;          /* sayac */
    int j;          /* sayac */

    int sum[13] = {0};                                              /* 
                                                                     * İki zar atildiğinda olusacak kombinasyonun sayisini topladigimiz dizi
                                                                     * su sekilde dusunun, diyelim ki iki zar da 5 geldi ve toplamlari 10 oldu.
                                                                     * bunu sonucunda iki zarin atilip gelen yuzdeki sayilarin toplaminin on oldugu
                                                                     * durumu her seferinde bir arttiracagiz. Boylece dizinin 10. indisi +1 olacak 
                                                                     * ve kombinasyon sayisini tutabilecegiz 
                                                                    */
    
    int expected[13]  = {0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};    /* iki zarin toplaminin gerçekte gelme olasiligi */

    srand(time(NULL));                                              /* Rastgele sayi ureteci ana fonksiyonu */

    for(i = 0; i < 36000; ++i)
    {
        firstDie = randomNumberGenerator();
        secondDie = randomNumberGenerator();

        ++sum[firstDie + secondDie];                                /* yukarida bahsettigimiz islemi gerceklestiriyoruz */
    }

    printf( "%10s%10s%10s%10s\n", "Sum", "Total", "Expected", "Actual" );

    /* zar atma analizinin tablo olarak gosterimi */ 
    for ( j = 2; j < 13; j++ ) 
    {
        printf( "%10d%10d%9.3f%%%9.3f%%\n", j, sum[ j ], 100.0 * expected[ j ] / 36, 100.0 * sum[ j ] / 36000 );
    }

    getch();
    return 0;
}

int randomNumberGenerator()
{
    return 1 + rand() % 6;
}
