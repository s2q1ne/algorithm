
#include <stdio.h>
#include <stdlib.h>
int N[11]={1,}, NUM, M;
int A( int lv){
    int i, s=0;
    if( lv>NUM ) {
        for( i=1; i<lv; i++){
            s+=N[i];
            //printf("%d ", N[i]);
        }
        if( s == M) {
            for( i=1; i<lv; i++){
                printf("%d ", N[i]);
            }
                printf("\n");
        }
        return  0;
    }
    for( i=N[lv-1]; i<=6; i++){
            N[lv] = i;
            A(lv+1);
    }
}

int main()
{
    scanf("%d %d", &NUM, &M);
    A(1);
    return 0;
}/*
#include <stdio.h>
#include <stdlib.h>

long long A(long long n){
    if( n==1) {
        printf("1! = 1\n");
        return 1;
    }else if(n<1 )return 0;
    printf("%d! = %d * %d!\n", n, n, n-1);
    return A(n-1) * n;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lli", A(n));
    return 0;
}
/*/
