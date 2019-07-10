#include <stdio.h>
#include <stdlib.h>

int te[30][30];
int n;
int cor( )

int main()
{
    int num_, a, b;
    scanf("%d", &n);
    scanf("%d" ,&num);

    int i,j;


    for( i=0; i<n; i++)
        te[i][0]=1;

    for( i=0; i<num; i++){
        scanf( "%d %d", &a, &b );
        te[a-1][b-1]=1;
    }

    for( i=0; i<n; i++){
        te[i][0] = 0;
    }


    return 0;
}
