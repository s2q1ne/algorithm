#include <stdio.h>
#include <stdlib.h>

int S[80000], snt, qnt;

int push(int n){
    S[qnt++] = n;
}

int pop(){
    if( qnt-snt > 0  ){
        printf("%d\n", S[snt]);
        S[snt++] = 0;
    }
    else{
        printf("empty\n");
    }
    return 0;
}

int main()
{
    int N, i, a, sum=0, s=0;
    scanf("%d", &N);
    for( i=0; i<N; i++){
        scanf("%d", &a);
        s=0;
        while(1){
            if( qnt < 1 || i==0){
                push(a); s++; break;
            }
            else if( S[qnt-1] > a){
                push(a); s++; break;
            }
            else{
                s++;
                pop();
                continue;
            }
        }
        sum += s;
    }printf("%d", sum);
    return 0;
}
