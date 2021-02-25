#include <stdio.h>
#include <math.h>

long long unsigned int us_alma(int taban, int us);


int main(void)
{
    long taban, us, yeniden;

    do
    {
        printf("\nTaban Giriniz: ");
        scanf("%d", &taban);

        printf("Us Giriniz:: ");
        scanf("%d", &us);

        printf("%d ^ %d = %llu\n", taban, us, us_alma(taban, us));

        printf("\nProgram Yeniden Calistirlsin Mi?\n1 : Evet\n0 : Hayir\nCevap: ");
        scanf("%d", &yeniden);
    }

    while (yeniden);

    return 0;
}


long long unsigned int us_alma(int taban, int us)
{

    if (us == 0)
        return 1;

    else if (taban == 1)
        return taban;

    else
        return taban * us_alma(taban, us - 1);
}
