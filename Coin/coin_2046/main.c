#include <stdio.h>
int main()
{
    int a=0, i=5, j=0;
    while(j<i){
        a=0;
        while( a<j ){
            printf("o");
            a++;
        }j++;
        printf("*\n");
    }
    return 0;
}
