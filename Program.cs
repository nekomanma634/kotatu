using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("操作方法---");
        Console.WriteLine("１で加法");
        Console.WriteLine("２で減法");
        Console.WriteLine("入力して計算します");
        Console.WriteLine("A+Bの場合,Aの値が一回目、Bの値が二回目");
        Console.WriteLine("終了するにはESCキーを押してください");

        while (true)
        {
            ConsoleKeyInfo keyInfo = Console.ReadKey(true);

            if (keyInfo.Key == ConsoleKey.D1 || keyInfo.Key == ConsoleKey.D2)
            {
                bool isAddition = (keyInfo.Key == ConsoleKey.D1);
                Calculate(isAddition);
            }
            else if (keyInfo.Key == ConsoleKey.Escape)
            {
                Console.WriteLine("\n終了しました");
                break;
            }
        }
    }

    static void Calculate(bool isAddition)
    {
        string operation = isAddition ? "+" : "-";
        Console.WriteLine(isAddition ? "足し算をします" : "引き算をします");

        int num1 = GetValidInput("最初の数値を入力してください");
        int num2 = GetValidInput("次の数値を入力してください");

        int result = isAddition ? num1 + num2 : num1 - num2;
        Console.WriteLine($"{num1} {operation} {num2} = {result}");
    }

    static int GetValidInput(string prompt)
    {
        int num;
        while (true)
        {
            Console.WriteLine(prompt);
            if (int.TryParse(Console.ReadLine(), out num))
                break;
            Console.WriteLine("無効な数字または文字です");
        }
        return num;
    }
}
