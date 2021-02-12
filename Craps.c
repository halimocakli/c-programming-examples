//Barbut Oyun Simulasyonu
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h> // time() ve zaman fonksiyonu prototipini icerir

/*
 * Bir oyuncu iki zar atar. Her zarin alti kenari vardir. Bu Yuzlerin uzerine 1,2,3,4,5 ve 6 nokta vardir.
 * Zar durduktan sonra yukariya dogru duran iki yuz uzerindeki noktalarin toplami hesaplanir. Ilk atista
 * toplam 7 veya 11 ise oyuncu kazanir. Ilk atista toplam 2,3 veya 12 gelirse "Barbut" denir, oyuncu kaybeder
 * yani kasa kazanir. Ilk atista toplam 4,5,6,8,9 veya 10 gelirse elde edilen toplam oyuncunu puani olur.
 * Kazanmak icin puaninizi tutturana kadar devam etmek, zar atmak zorundasiniz. Puani tutturmadan once
 * 7 atan oyuncu kaybeder.
 */

// oyun durumunu temsil eden sabitleri listeleme
enum Durum { DEVAM, KAZANDI, KAYBETTI }; //enum sabitlarine program surecinde deger atanamaz. Buyuk harf kullanilir.

int zarAtisi( void ); // fonksiyon prototipi

// main fonksiyonu calistiriliyor
int main( void )
{
    int toplam; // atilan zarlarin toplami
    int oyuncuPuani; // oyuncu kazanmak icin kendi puanini tutturmalidir

    enum Durum oyunDurumu; // DEVAM, KAZANDI, KAYBETTI icerir

    // saati kullanarak rastgele sayi uretecini rastgele hale getirmek
    srand( time( NULL ) );

    toplam = zarAtisi(); // zarlarin ilk atisi

    // zarlarin toplamina gore oyunun durumunu belirle
    switch( toplam )
    {

      // ilk atista kazanma
      case 7: // 7 kazanir
      case 11: // 11 kazanir
         oyunDurumu = KAZANDI; // oyun kazanildi
         break;

      // ilk atista kaybetme
      case 2: // 2 kaybeder"
      case 3: // 3 kaybeder
      case 12: // 12 kaybeder
         oyunDurumu = KAYBETTI; // oyun kaybedildi
         break;

      // puani hatirla
      default:
         oyunDurumu = DEVAM; // oyuncu zar atmaya devam etmeli
         oyuncuPuani = toplam; // puani hatirla
         printf( "Oyuncu Puani: %d\n", oyuncuPuani );
         break; // istege bagli

    } // switch sonu

    // oyun tamamlanmadiysa
    while ( DEVAM == oyunDurumu )
    {
        // oyuncu zar atmaya devam etmeli
        toplam = zarAtisi(); // roll dice again

        // oyun durumunu belirle
        if ( toplam == oyuncuPuani )
        { // puan durumuna g�re kazanma

            oyunDurumu = KAZANDI; // oyun bitti, kazandiniz

        } // if sonu

        else
        {
            if ( 7 == toplam )
            { // 7 attiginiz icin kaybettiniz

                oyunDurumu = KAYBETTI; // oyun bitti, kaybettiniz

            } // if sonu

      } // else sonu

    } // while sonu

    // kaybetti ya da kazandi yazisini g�sterme
    if ( KAZANDI == oyunDurumu )
    {
      puts( "Kazandiniz..." );
    } // if sonu

    else
    { // oyuncu kaybetti
      puts( "Kaybettiniz..." );
    } // else sonu

    getch();
    return 0;

} // main sonu

// zar atma, toplami hesaplama ve sonuclari gosterme
int zarAtisi( void )
{
   int zar1;
   int zar2;
   int toplamZar;

   zar1 = 1 + ( rand() % 6 );
   zar2 = 1 + ( rand() % 6 );
   toplamZar = zar1 + zar2;

   // bu atisin sayilarini ve toplamini goster
   printf( "Oyuncu Atis Yapti ---> %d + %d = %d\n", zar1, zar2, toplamZar );
   return toplamZar; // toplam� geri d�nd�r
} // zarAtisi fonksiyonunun sonu
