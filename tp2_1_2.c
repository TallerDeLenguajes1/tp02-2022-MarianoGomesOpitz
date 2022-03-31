#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 20

int main()
{
    int i;
    int vt[N], *p_vt;
    p_vt = vt;

    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        *(p_vt + i) = 1 + rand() % 100;
        printf("%d ", *(p_vt + i));
        p_vt++;
    }

    getchar();
    return 0;
}
