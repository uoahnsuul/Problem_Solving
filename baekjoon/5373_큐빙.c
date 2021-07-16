#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int n;
int c, i, k;

char cube[54];
char color[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };

char rule[1000][2];
char tmp[3];
char self[9];

// U, D, F, B, L, R
int num[6][4] = { {27, 47, 20, 36}, {35,44,24,51}, {6, 45, 17, 42}, {2, 38, 9, 53}, { 0, 18, 15, 33 }, {8, 29, 11, 26} }; 
int s[6][4] = { {1,-1,-1, 1}, {-1,-1,1,1}, {1,3,-1,-3}, {-1,3,1,-3},{3,3,-3,-3},{-3,3,3,-3} };
int p[1000] = { 0 };

void rotatePlane(int N) {
    int start = N * 9;
    int k, z;
    int cnt = 0;

    for (k = 0; k < 3; k++)
    {
        self[cnt] = cube[start + k + 6];
        self[cnt+1] = cube[start + k + 3];
        self[cnt+2] = cube[start + k];
        cnt += 3;
    }
    for (k = 0; k < 9; k++)
    {
        cube[start + k] = self[k];
    }
}

void rotatePlaneB(int N) {
    int start = N * 9;
    int k, z;
    int cnt = 0;

    for (k = 2; k >= 0; k--)
    {
        self[cnt] = cube[start + k];
        self[cnt +1] = cube[start + k + 3];
        self[cnt+2] = cube[start + k + 6];
        cnt += 3;
    }

    for (k = 0; k < 9; k++)
    {
        cube[start + k] = self[k];
    }

}

void changeColorDown(int N) {
    int z;

    tmp[0] = cube[num[N][0]];
    tmp[1] = cube[num[N][0] + s[N][0]];
    tmp[2] = cube[num[N][0] + s[N][0] * 2];

    for (z = 1; z < 4; z++)
    {
        cube[num[N][z - 1]] = cube[num[N][z]];
        cube[num[N][z - 1] + s[N][z-1]] = cube[num[N][z]+s[N][z]];
        cube[num[N][z - 1] + s[N][z-1]*2] = cube[num[N][z]+s[N][z]*2];
    }

    cube[num[N][3]] = tmp[0];
    cube[num[N][3] + s[N][3]] = tmp[1];
    cube[num[N][3] + s[N][3]*2] = tmp[2];

}

void changeColorUp(int N) {
    int z;

    tmp[0] = cube[num[N][3]];
    tmp[1] = cube[num[N][3] + s[N][3]];
    tmp[2] = cube[num[N][3] + s[N][3] * 2];

    for (z = 2; z >= 0; z--)
    {
        cube[num[N][z + 1]] = cube[num[N][z]];
        cube[num[N][z + 1] + s[N][z+1]] = cube[num[N][z]+s[N][z]];
        cube[num[N][z + 1] + s[N][z+1]*2] = cube[num[N][z]+s[N][z]*2];
    }

    cube[num[N][0]] = tmp[0];
    cube[num[N][0] + s[N][0]] = tmp[1];
    cube[num[N][0] + s[N][0]*2] = tmp[2];

}

int main() {
    int j, P, C;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (c = 0; c < 6; c++)
        {
            for (j = 0; j < 9; j++)
            {
                cube[c * 9 + j] = color[c];
            }
        }

        scanf("%d", &C);
        getchar();
        for (j = 0; j < C; j++)
        {
            scanf("%c%c", &rule[j][0],&rule[j][1]);

            if (rule[j][0] == 'U') p[j] = 0;
            else if (rule[j][0] == 'D') p[j] = 1;
            else if (rule[j][0] == 'F') p[j] = 2;
            else if (rule[j][0] == 'B') p[j] = 3;
            else if (rule[j][0] == 'L') p[j] = 4;
            else if (rule[j][0] == 'R') p[j] = 5;

            getchar();
        }

        for (j = 0; j < C; j++)
        {
            P = p[j];
            if (rule[j][1] == '-')
            {
                changeColorDown(P);
                if (P == 0 || P == 2 || P == 5) rotatePlaneB(P);
                else rotatePlane(P);
            }
            else
            {
                changeColorUp(P);
                if (P == 0 || P == 2 || P == 5) rotatePlane(P);
                else rotatePlaneB(P);
            }
        }
        for (c = 0; c < 9; c++)
        {
            printf("%c", cube[c]);
            if (c == 2 || c == 5 || c == 8) printf("\n");
        }
    }
}