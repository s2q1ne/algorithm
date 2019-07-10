#include <stdio.h>
#include <stdlib.h>

int S[100], snt;

int push(int n){
    S[snt++] = n;
}

int pop(){
    int a;
    if( snt > 0  ){
        snt--;
        a = S[snt];
        S[snt] = 0;
    }
    return a;
}

int main()
{
    int N, i, n;

            int A, B;
    scanf("%d", &N);
    for( i=0; i<N; i++){
        scanf(" %c", &n);
        if( '0' <=n && n <= '9'){
        push(n-'0');
    }else{
        switch( n ){
        case '+':
            push( pop()+pop() );
            break;
        case '-':
            A = pop();
            B = pop();
            push( B-A );
            break;
        case '*':
            push( pop() * pop());
            break;
        case '/':
            A = pop();
             B=pop();
            if( A==0 ) return 0;
            push( B / A);
        }
    }
    }
    printf("%d", pop());
    return 0;
}
