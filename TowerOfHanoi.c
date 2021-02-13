#include <stdio.h>
#include <conio.h>

// Hanoi Kuleleri Problemi Icin C Recursive Programi

///Iki disk icin bir gelistirme ornegi inceleyelim,

/// 1. Cubuk = A , 2. Cubuk = B, 3. Cubuk = C

/// 1. ADIM ---> Birinci Diski A'dan B'ye Tasiyin
/// 2. ADIM ---> Ikinci Diski A'dan C'ye Tasiyin
/// 3. ADIM ---> Birinci Diski B'den C'ye Tasiyin

/// Uygulama adimlari su sekilde gerceklesir,

/// (n-1). Diski A'dan B'ye Tasiyin
/// Kalan Diski A'dan C'ye Tasiyin
/// (n-1). Diski B'den C'ye Tasiyin

/// N adet disk icin 2^n - 1 adet hamle gereklidir
/// N adet disk icin 2^n * 2^(-1) adet fonksiyon cagrisi yapilir

void hanoiKuleleri(int n, char cubuktan_gelis, char cubuka_gidis, char yardimci_cubuk)
{
    if (n == 1)
    {
        printf("\n 1. Diski %c Cubugundan %c Cubuguna Goturun", cubuktan_gelis, cubuka_gidis);
        return;
    }

    hanoiKuleleri(n-1, cubuktan_gelis, yardimci_cubuk, cubuka_gidis);

    printf("\n %d. Diski %c Cubugundan %c Cubuguna Goturun", n, cubuktan_gelis, cubuka_gidis);

    hanoiKuleleri(n - 1, yardimci_cubuk, cubuka_gidis, cubuktan_gelis);
}

int main()
{
    int n;

    printf("Disk Sayisini Giriniz: ");
    scanf("%d", &n);

    printf("\n\t\tYONERGELER\n");
    printf("------------------------------------------");

    hanoiKuleleri(n, 'A', 'C', 'B');  // A, B ve C ---> Cubuk Adlari

    getch();
    return 0;
}
