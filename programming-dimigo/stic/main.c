#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i, a=0, s=0;
    char A[100001];
    scanf("%s", &A);
    for( i=0; i<strlen(A)-1; i++){
        if( A[i] == '(' && A[i+1]==')'){
            s+=a;
            //printf("%d %d\n", a,s);
            i++;
        }
        else if( A[i]=='('){
            a++;
            s++;
        }
        else if( A[i]==')'){
            a--;
        }
    }
    printf("%d", s);
    return 0;
}
