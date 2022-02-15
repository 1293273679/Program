#include <stdio.h>
#include <math.h>
#include <windows.h>

void menu()
{
    printf("*****************************\n");
    printf("*           计算器          *\n");
    printf("* 1.Add                2.Sub*\n");
    printf("*                           *\n");
    printf("* 3.Mul                4.Div*\n");
    printf("*           0.Exit          *\n");
    printf("*****************************\n");
}

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

int main()
{
    int input = 0;
    int x = 0, y = 0;
    int (*pfArr[])(int, int) = {0, Add, Sub, Mul, Div};

    do
    {
        menu();
        printf("请选择你要的功能:");
        scanf("%d", &input);
        if(input >= 1 && input <= 4)
        {
            printf("请输入两个操作数:");
            scanf("%d%d", &x, &y);
            pfArr[input](x, y);
            printf("%d\n", pfArr[input](x, y));
            system("pause");
            system("cls");
        }
        else if(input == 0)
        {
            printf("退出\n");
        }
        else
        {
            printf("选择错误\n");
            system("pause");
            system("cls");
        }
    } while (input);
    
    return 0;
}