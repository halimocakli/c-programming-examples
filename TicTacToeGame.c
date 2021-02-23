#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* basit bir dokuz tas oyunu ornegi */

char matrix[3][3];  /* dokuz tas matrisi global olacak sekilde olusturuluyor */

char check();               /* kazanim kontrol fonksiyonunun prototipi */
void init_matrix();         /* matrisi ilk kullanima hazirlama fonksiyonunun prototipi */
void get_player_move();     /* oyunucunun hamlesini okuma fonksiyonunun prototipi */
void get_computer_move();   /* bilgisayarin hamlesini okuma fonksiyonunun prototipi */
void disp_matrix();         /* matrisi ekrana yazdirma fonksiyonunun prototipi */

int main()
{
    char done;

    printf("This is the game of Tic Tac Toe.\n");
    printf("You will be playing against the computer.\n\n");

    done = ' ';
    init_matrix();

    do{
        disp_matrix();
        get_player_move();
        done = check(); /* kazanip kazanmama durumunu kontrol etme */

        if(done != ' ')
            break;      /* kazandi */
        
        get_computer_move();
        done = check(); /* kazanip kazanmama durumunu kontrol etme */

    }while (done == ' ');
    
    if(done == 'X')
    {
        printf("You won!\n\n");
    }
    else
    {
        printf("I won!\n\n");
    }

    disp_matrix();  /* son konumlari goster */

    getch();
    return 0;
}

/* matrisi ilk kullanima hazirla */
/* 3x3'luk matrisin tum elemanlari bosluk karakteri olarak ataniyor */
void init_matrix()
{
    int i;
    int j;

    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            matrix[i][j] = ' ';
        }
    }
}

/* oyuncunun hamlesini oku */
void get_player_move()
{
    int x;
    int y;

    printf("\nEnter X, Y coordinates for your move: ");
    scanf("%d%*c%d", &x, &y);
    printf("\n*******************************************\n");
    printf("*******************************************\n\n");

    x--;
    y--;

    if(matrix[x][y] != ' ')
    {
        printf("Invalid move, try again.\n");
        get_player_move();
    }
    else
    {
        matrix[x][y] = 'X';
    }
}

/* bilgisayarin hamlesini oku */
void get_computer_move()
{
    int i;
    int j;

    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            if(matrix[i][j] == ' ')
            {
                break;
            }
        }
        if(matrix[i][j] == ' ')
        {
            break;
        } 
    }

    if(i * j == 9)
    {
        printf("draw\n");
        exit(0);
    }
    else
    {
        matrix[i][j] = '0';
    }
}

/* matrisi ekranda goster */
void disp_matrix()
{
    int t;

    for(t = 0; t < 3; ++t)
    {
        printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);

        if(t != 2)
        {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

/* kazanan var mi diye bak */
char check()
{
    int i;

    for (i = 0; i < 3; ++i) /* satirlari kontrol et */
    {
        if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
        {
            return matrix[i][0];
        }
    }

    for (i = 0; i < 3; ++i) /* sutunlari kontrol et */
    {
        if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
        {
            return matrix[0][i];
        }
    }

    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
    {
        return matrix[0][0];
    }

    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
    {
        return matrix[0][2];
    }

    return ' ';
}