#include <stdio.h>
#include <stdlib.h>

int S[100], snt, qnt;

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

int p( int n ){
    int io;
    switch(n){
    case 'i':
        scanf("%d", &io);
        push(io);
        break;
    case 'o':
        pop();
        break;
    case 'c':
        printf("%d\n", qnt-snt);
    }
}

int main()
{
    int N, i, a;
    scanf("%d", &N);
    for( i=0; i<N; i++){
        scanf(" %c", &a);
        p(a);
    }
    return 0;
}
