#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

struct judgedate //テスト構造体
{
    int judg;
};

int timer() //一秒ごとのタイマーで実行されて一秒後に処理を行うもの。
{
    int timer1 = 0;
    int timer1Running = 0;

    timer1Running = 1;

    for(int i = 0; i < 1; i++)
    {
        if(timer1Running)
        {
            timer1++;
        }
        sleep(1);
    }
}

int myprint(int n , int num[10][5]) //配列を表示
{
    int forn;
    for(forn = 0; forn < 10; forn++)
    {
        for(n = 0; n < 5; n++)
        {
            printf("%d " ,  num[forn][n]);
        }
        printf("\n");
        n = 0;
    }
    return 1;
}

int judgeF(int n , int num[10][5])
{
    int forn;
    struct judgedate data;
    data.judg = 0;

    for(forn = 0; forn < 10; forn++)
    {
        for(n = 0; n < 5; n++)
        {
            if(num[forn][n] == 1)
            {
                data.judg++;
            }
        }
        n = 0;
    }
    return printf("\n判定数(１の総数):%d\n",data.judg);
}

int main()
{
    bool endmain = false; //ゲーム本体を終了させるかさせないか
    bool start = false; //ゲームのコントローラーを制御する変数
    char key; //コントローラーのキーボード入力された場合に文字が入力される変数
    int blocmove = 0; //ブロック一つ一つが移動した数をカウントする変数

    int num[10][5] = {
                    {0,0,0,0,1}, //1
                    {0,0,0,0,0}, //2
                    {0,0,0,0,0}, //3
                    {0,0,0,0,0}, //4
                    {0,0,0,0,0}, //5
                    {0,0,0,0,0}, //6
                    {0,0,0,0,0}, //7
                    {0,0,0,0,0}, //8
                    {0,0,0,0,0}, //9
                    {1,1,1,1,0}, //10
                    }; //ゲームのブロック配列

    while(endmain == false)
    {
        int n = 0;
        bool end = false;

        myprint(n , num);
        judgeF(n,num);
        printf("\nbloc通過数%d\n" , blocmove);

        while(end == false)
        {
            if(_kbhit())
            {
                key = _getch();

                //if()//n秒立っていないのならやる、逆にn秒立ったら受け付けないでmainの繰り返しに戻る

                if(key == 'h')
                {
                    end = true;
                    system("cls");
                    num[1][1]++;
                }
                else if(key == 'e')
                {
                    //system("cls");
                    endmain = true;
                    end = true;
                }
                else if(key  == 'm')
                {
                    int n2 = 0; //次の段の変数
                    int n3 = 9; //落下させる数（0が10個あるとしたら9になる。なぜかというと、次の段が0である場合下がるというコードで下の段を参照するのがn2+1のような形になっているため。だが今回は他の変数を用いている。）
                    int n4; //横の行の数の変数
                    int n5 = 0; //１行がある行
                    int judgenum[2];
                    bool notjudge = false; //移動する場合としない場合でアニメーションをつけるかつけないか
                    start = true;
                    judgenum[0] = 0;

                    for(n = 0; n < 10; n++) //１がある行を探しその行をnとし動くプログラムを導入する。配列を使って、縦の行のデータを管理する。
                    {
                        n4 = 0; //横の行のforに使う変数
                        n2++;

                        for(n4 = 0; n4 < 5; n4++) //5は横の行
                        {
                            notjudge = false;

                            if(num[n2][n4] == 1)
                            {
                                judgenum[0]++;
                            }

                            if((num[n][n4] == 1) && (num[n2][n4] == 0)) //n回繰り返し、1が来たらやめる
                            {
                                num[n][n4]--;
                                num[n2][n4]++;
                                blocmove++;
                            }
                        }

                        if(judgenum[0] == 5)
                        {
                            for(n4 = 0; n4 < 5; n4++)
                            {
                                num[n][n4]--;
                            }
                        }

                        if(notjudge == false)
                        {
                            printf("\n%d %d\n",n,n2);
                            timer();
                            system("cls");
                            printf("\n%d\n" , judgenum[0]);
                            myprint(n , num);
                        }
                    }
                    system("cls");
                    printf("\n%d\n" , judgenum[0]);
                    end = true;
                }
                else if(key == 'r')
                {
                    end = true;
                    system("cls");
                }
            }
        }
    }
}