#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

int sleepf(int n[20]) //落下してくるの書く（したの位置の数が0である時、一列落下する（0.5秒ぐらい）,落下したくない行（限界の位置）にはあらかじめ2を入れておくことで防ぐ）
{
    int fornum;
    int jnum;
    int testnum = 1;

    for(fornum = 1; fornum < 21; fornum++)
    {
        printf("%d\n",fornum);
        if(fornum < 11 && n[fornum] == 1) //一列目処理を分けて、0or1かを判別する1のしたが0であるのならば下へ行けるようにしもともと0であるなら飛ばすようにする
        {
            printf("ok\n");
        }
        else
        {
            printf("no\n");
        }
    }
}

int main()
{
    bool endmain = false;
    int ji = 1; //テスト用の横一列1にするやつの変数
    int i = 0; //テスト用の横一列1にするやつの変数
    int n; //横
    int fn; //縦
    int a = 0; //横一列そろったときの計算に使うやつ
    char key; //controlの関数をなくしたやつ

    int bloc[22][15] = {
                            { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 0}, //0行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //1行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //2行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //3行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //4行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //5行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //6行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //7行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //8行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //9行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //10行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //11行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //12行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //13行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //14行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //15行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //16行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //17行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //18行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //19行目0~11
                            { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}, //20行目0~11
                            { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 0}, //21行目0~11
                        };
    system("cls");

    while(endmain == false) //メインの繰り返し(game本体)
    {
        bool end = false; //こっちから宣言しないとダメな変数

                for(fn = 0; fn < 22; fn++) //配列の表示
                {
                    for(n = 0; n < 12; n++)
                    {
                        printf("%d  " , bloc[fn][n]);
                    }

                    printf("\n");
                }

        while(end == false) //コントローラーの繰り返し、この前にmain関数の繰り返し
        {
            if(_kbhit()) //キーボードからの入力があるかどうかをチェック
            {
                int sysnum;
                key = _getch(); //キー入力取得

                if(key == 'a' || key == 's' || key == 'd' || key == 'w' || key == 'r' || key == 'e')
                {

                }
                if(key == 'a') //左
                {
                    sysnum = 0;
                    system("cls");
                    end = true;
                }
                else if(key == 'd') //右
                {
                    sysnum = 1;
                    system("cls");
                    end = true;
                }
                else if(key == 'r') //再読み込みやで
                {
                    system("cls");
                    end = true;
                }
                else if(key == 'e') //eで終了
                {
                    end = true;
                    endmain = true;
                    system("cls");
                }
                else if(key == 'h') //配列の数値を変化させるテスト
                {
                    if(ji < 21)
                    {
                        for(i = 1; i < 11; i++)
                        {
                            bloc[ji][i]++;
                        }

                        if(ji >= 1 && ji < 21)
                        {
                            ji++;
                        }
                    }

                    system("cls");
                    end = true;
                }
            }
        }
    }
    return 0;
}