#include <stdio.h>
#include <stdlib.h>
int N[11]={1,}, NUM, M;
int output(int lv){
    for( int i=1; i<lv; i++){
        printf("%d ", N[i]);
    }
    printf("\n");
    return 0;
}

int SUM(int lv){
    int i,s=0;
    for( i=1; i<=lv; i++){
        s+=N[i];
    }return s;
}
int A( int lv){
    int i, s=0;
    if( lv>NUM) {
        s = SUM(lv);
        if( s == M)   output(lv);
        return 0;
    }

    s = SUM(lv);
    //if( s > M ) return 0;

    for( i=1; i<=6; i++){
        N[lv] = i;
        A(lv+1);
    }
}

int main()
{
    scanf("%d %d", &NUM, &M);
    A(1);
    return 0;
}
