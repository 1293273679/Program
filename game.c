#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROW 3
#define COL 3

void menu()
{
    printf("*************************\n");
    printf("*****1.play   0.exit*****\n");
    printf("*************************\n");
}

void Initboard(char board[ROW][COL], int row, int col)
{
    int i = 0, j = 0;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void Displayboard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    
    for(i = 0; i < row; i++)
    {
        int j = 0;

        for(j = 0; j < col; j++)
        {
            printf(" %c ",board[i][j]);
            if( j < col - 1)
                printf("|");    
        } 
        
        printf("\n");

        if(i < row - 1)
        {
            for(j = 0; j < col; j++)
            {
                printf("---");
                
                if(j < col - 1)
                    printf("|");
            }

            printf("\n");

        }
    }
}

void Playermove(char board[ROW][COL], int row, int col)
{
    int x = 0, y = 0;

    while(1)
    {
        printf("玩家请输入要下的坐标:");
        scanf("%d%d", &x, &y);

        if(x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if(board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("该坐标被占用\n");
            }
        }
        else
        {
            printf("坐标非法，请重新输入\n");
        }
    }  
}

void Computermove(char board[ROW][COL], int row, int col)
{
    int x = 0, y = 0;

    printf("电脑输入的坐标:\n");

    while(1)
    {
        x = rand() % row;
        y = rand() % col;

        if(board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
    
}

int Isfull(char board[ROW][COL], int row, int col)
{
    int i = 0, j = 0;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

char Iswin(char board[ROW][COL], int row, int col)
{
    int i = 0;

    for(i = 0; i < row; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][1];
        }
    }

    for(i = 0; i < col; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[i][1] != ' ')
        {
            return board[1][i];
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }

    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }

    if(1 == Isfull(board, ROW, COL))
    {
        return 'Q';
    }
    return 'C';
}

void game()
{
    char ret = 0;

    char board[ROW][COL] = {0};

    Initboard(board, ROW, COL);
    Displayboard(board, ROW, COL);
    while(1)
    {
        Playermove(board, ROW, COL);
        Displayboard(board, ROW, COL);
        ret = Iswin(board, ROW, COL);
        if(ret != 'C')
        {
            break;
        }

        Computermove(board, ROW, COL);
        Displayboard(board, ROW, COL);
        ret = Iswin(board, ROW, COL);
        if(ret != 'C')
        {
            break;
        }
    }

    if(ret == '*')
    {
        printf("玩家赢\n");
        
        system("pause");
        system("cls");
    }
    else if(ret == '#')
    {
        printf("电脑赢\n");

        system("pause");
        system("cls");
    }
    else
    {
        printf("平局\n");

        system("pause");
        system("cls");
    }
}

void test()
{
    int input = 0;

    srand((unsigned int)time(NULL));

    do
    {
        menu();

        printf("请选择:");
        scanf("%d", &input);

        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误，请重新选择\n");
                break;
        }
    } while (input);
    
}

int main()
{
    test();

    return 0;
}