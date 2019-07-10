#include <stdio.h>
#include <stdlib.h>

int N[10000];
int len=0;

int pop( int index ){
    int i, a;
    a=N[index];
    for( i=index; i<len; i++){
        N[i] = N[i+1];
    }
    len--;
    return a;
}

int P()
{
    int i, a;
    for( i=0; i<=10000; i++){
        N[i]=i;
    }
    while( len>0 ){
        for( i=1; i<=len; i+=2 ){
            a=pop(i);
            i--;
            //printf("%d ", a);
        }
        if( len == 0) break;
        for( i=len; i>0; i-=2 ){
            a=pop(i);
            //printf("%d ", a);
        }
    }
    return a;
}

int main(){
    int n, i, sum=0;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        len=i;
        sum+=P();
    }
    printf("sum: %d", sum);
}
