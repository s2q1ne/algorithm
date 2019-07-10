#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, num, C, D[30][30], E[30];
    int i,j, a, b;
    scanf("%d", &n); //공장의 수
    scanf("%d", &num); //수로의 개수
    for(i=0; i<30; i++){
        D[i][0] = 1;
        E[i] = 0;
    }
    for( i=0; i<num; i++){
        scanf("%d %d", &a, &b);
        D[a-1][D[a-1][0]] = b-1;
        if( E[a-1] != 1 )
            printf("%d %d\n", a, b);
        E[a-1] = E[b-1] = 1;
    }
    return 0;
}
