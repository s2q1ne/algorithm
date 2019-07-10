#include <stdio.h>
#include <stdlib.h>

int compare (void *first, void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main()
{
    int N, n, COIN[6], M[6]={0,}, cnt=0, money[6]={500, 100, 50, 10, 5, 1};
    int i, j, k;
    scanf("%d", &N);
    for( i=0; i<N; i++) scanf("%d", &COIN[i]);
    n=N;
    for( i=0; i<N; i++){
        M[i] = n/(money[i]);
        n %= money[i];
    }

    for( i=0; i<N; i++){
        sum += nums[i];
        if( nums[i+1] > sum+1 )
            break;
    }
    return 0;
}



