#include <stdio.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#define L   2
#define R   6

int w[4][8];
int tmp;
int k;
int arr[100][2];

void init()
{
    int i, j;
    
    
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &tmp);
        for (j = 7;j>=0;j--)
        {
            w[i][j] = tmp % 10;
            tmp = tmp / 10;
        }
    }
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &arr[i][0]);
        scanf("%d", &arr[i][1]);
        arr[i][0] = arr[i][0] - 1;
    }
}

void cal()
{
    int i, j, z;
    int tmp, temp;
    int flag[100][4][2] = { 0 };
    int di;

    for (i = 0; i < k; i++)
    {
        tmp = arr[i][0];
        di = arr[i][1];
        flag[i][tmp][0] = 1;
        flag[i][tmp][1] = di;

        while (tmp - 1 >= 0 && flag[i][tmp][0]==1)
        {
            if (w[tmp - 1][L] != w[tmp][R])
            {
                flag[i][tmp - 1][0] = 1;
                flag[i][tmp - 1][1] = di * (-1);
                di = di * (-1);
            }
            tmp--;
        }
        
        tmp = arr[i][0];
        di = arr[i][1];
        while (tmp + 1 <4 && flag[i][tmp][0] == 1)
        {
            if (w[tmp][L] != w[tmp + 1][R])
            {
                flag[i][tmp + 1][0] = 1;
                flag[i][tmp + 1][1] = di * (-1);
                di = di * (-1);
            }
            tmp++;
        }

        for (j = 0; j < 4; j++)
        {
            if (flag[i][j][0] == 1 && flag[i][j][1] == -1)
            {
                temp = w[j][0];
                for (z = 0; z < 7; z++) w[j][z] = w[j][z + 1];
                w[j][7] = temp;
            }
            else if (flag[i][j][0] == 1 && flag[i][j][1] == 1)
            {
                temp = w[j][7];
                for (z = 7; z > 0; z--) w[j][z] = w[j][z - 1];
                w[j][0] = temp;
            }
        }
    }
}


int main()
{
    int i, j;
    int sum = 0;
    
    init();

    cal();
    
    if (w[0][0] == 1) sum += 1;
    if (w[1][0] == 1) sum += 2;
    if (w[2][0] == 1) sum += 4;
    if (w[3][0] == 1) sum += 8;

    printf("%d", sum);

}