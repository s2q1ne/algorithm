
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char A[10][101], find, *C[10];
    int n=0;
    for( int i=0; i<10; i++ ){
        scanf("%s", &A[i]);
    }
    scanf(" %c", &find);
    for( int i=0; i<10; i++){
        if( strchr(A[i], find) != NULL){
            C[n++] = A[i];
        }
    }
    for( int i=0;i<n; i++){
        for( int j=0; j<n; j++){
            if( strcmp(C[i], C[j]) < 0 ){
                char tmp[101];
                strcpy(tmp, C[i]);
                strcpy(C[i],C[j]);
                strcpy(C[j], tmp);
            }
        }
    }
    for( int i=0; i<n; i++ ){
        printf("%s\n", C[i]);
    }
    return 0;
}
