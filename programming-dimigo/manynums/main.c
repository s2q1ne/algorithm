#include <stdio.h>
#include <stdlib.h>

int check(int n){
    int Num = 0, ch = 1000000;
    while( n > 0){
        Num += n/ch;
        n %= ch;
        ch /= 10;
    }
    return Num;
}

int checking( int N ){
    N = check(N);
    if( N >= 10) return checking(N);
    return N;
}

int main()
{
    int A[10], B[10]={0,};
    int i, j;
    for( i=0; i<10; i++ ){
        scanf("%d", &A[i]);
        B[checking(A[i])]++ ;
        //printf("%d ", checking(A[i]));
    }
    int mx=0;
    for( i=1; i<10; i++ ){
            //printf("%d : %d \n", B[i]);
        if( mx < B[i]){
            mx = B[i];
        }
    }
    for( i=0; i<10; i++){
        if(B[i] == mx)
            printf("%d ", i);
    }
    return 0;
}
