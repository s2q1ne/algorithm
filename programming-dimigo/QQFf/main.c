#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int N = 3;
    const int CLASS = 4;
    int i,j, k[4][3], p[4];
    for( i=0; i<CLASS; i++){
        printf("%dclass? ",i+1);
        scanf("%d %d %d", &k[i][0], &k[i][1], &k[i][2]);
        p[i] = k[i][0] + k[i][1] + k[i][2];
    }
    for( i=0; i<CLASS; i++){
        printf("%dclass : %d\n", i+1, p[i]);
    }
    return 0;
}
