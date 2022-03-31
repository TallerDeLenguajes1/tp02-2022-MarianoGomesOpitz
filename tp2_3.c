#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 5
#define M 7

int main()
{
    int i, j;
    int mt[N][M], *p_mt;
    p_mt = mt[0][0];

    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            *(p_mt + (i * M + j)) = rand() % 100 + 1;
            printf("%d ", *(p_mt + (i * M + j)));
        }
        printf("\n");
    }

    getchar();
    return 0;
}