#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

#define Verticalbloc 0,0,0,0,0,0,0,0,0,0

int blocprintF(int bloc[20][10])
{
    for(int vertical = 0; vertical < 20; vertical++) //縦を制御するfor
    {
        printf("\n");

    for(int side = 0; side < 10; side++) //横を制御するfor
    {
        printf("%d " , bloc[vertical][side]);
    }

    }
}

int blocPassCount_And_blocPassF(int num[20][10])
{
    int countnum = 0;
    int nextBloc = 0;

    for(int vertical = 0; vertical < 19; vertical++) //縦を制御するfor
    {
        nextBloc++;

    for(int side = 0; side < 10; side++) //横を制御するfor
    {
        if((num[vertical][side] == 1) && (num[nextBloc][side] != 1))
        {
            num[vertical][side]--;
            num[nextBloc][side]++;
            countnum++;
        }
    }
    sleep(1);
    system("cls");
    printf("\nブロックが移動した回数:%d\n" , countnum);
    blocprintF(num);

    }
}

int main()
{
    int bloc[20][10] =
    {
        {0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,0}
    };

    #define 1 ■
    #define 0 □
    blocprintF(bloc);
    blocPassCount_And_blocPassF(bloc);

    return 0;
}