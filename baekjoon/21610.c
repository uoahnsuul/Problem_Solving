#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

struct grid {
    int w;
    int flag;
};

struct direct {
    int v;
    int h;
};

int N=0, M=0;
struct grid A[51][51] = { 0 };
struct direct di[9] = { {0,0}, {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };
int d[101] = { 0 };
int s[101] = { 0 };

void init()
{
    int i, j;

    scanf("%d %d", &N, &M);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &A[i][j].w);
            A[i][j].flag = 0;
            if (i == N - 2 && j == 0) A[i][j].flag = 1;
            else if (i == N - 2 && j == 1) A[i][j].flag = 1;
            else if (i == N - 1 && j == 0) A[i][j].flag = 1;
            else if (i == N - 1 && j == 1) A[i][j].flag = 1;
        }
    }

    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &d[i], &s[i]);
    }
}


void cal(int i)
{
    int v = di[d[i]].v * s[i];
    int h = di[d[i]].h * s[i];

    int cnt = 0;
    int nextV, nextH;
    int tmp[2500][2];
    int j, k;

    for (j = 0; j < N; j++)
    {
        for (k = 0; k < N; k++)
        {
            if (A[j][k].flag == 1)
            {
                A[j][k].flag = 0;
               
                nextV = j + v;
                nextH = k + h;

                while (nextV >= N) nextV = nextV % N;
                while (nextV < 0) nextV = nextV + N;

                while (nextH >= N) nextH = nextH % N;
                while (nextH < 0) nextH = nextH + N;

                tmp[cnt][0] = nextV;
                tmp[cnt][1] = nextH;
                
                cnt++;
            }
        }
    }

    for (j = 0; j < cnt; j++)
    {
        nextV = tmp[j][0];
        nextH = tmp[j][1];
        A[nextV][nextH].flag = 1;
        A[nextV][nextH].w++;
    }

    for (j = 0; j < N; j++)
    {
        for (k = 0; k < N; k++)
        {
            if (A[j][k].flag == 1)
            {
                if (j - 1 >= 0 && k - 1 >= 0)
                {
                    if (A[j - 1][k - 1].w > 0) A[j][k].w++;
                }
                if (j - 1 >= 0 && k + 1 < N)
                {
                    if (A[j - 1][k + 1].w > 0) A[j][k].w++;
                }
                if (j + 1 < N && k - 1 >= 0)
                {
                    if (A[j + 1][k - 1].w > 0) A[j][k].w++;
                }
                if (j + 1 < N && k + 1 < N)
                {
                    if (A[j + 1][k + 1].w > 0) A[j][k].w++;
                }
            }
        }
    }
    for (j = 0; j < N; j++)
    {
        for (k = 0; k < N; k++)
        {
            if (A[j][k].flag == 1)
            {
                A[j][k].flag = 0;
            }
            else if (A[j][k].w >= 2)
            {
                A[j][k].flag = 1;
                A[j][k].w = A[j][k].w - 2;
            }
        }
    }
}

int main()
{
    int sum=0;
    int i, j, k;

    init();
   
    for (i = 0; i < M; i++)
    {
        cal(i);
    }

    for (j = 0; j < N; j++)
    {
        for (k = 0; k < N; k++)
        {
            sum += A[j][k].w;
        }
    }
    printf("%d", sum);
    
}