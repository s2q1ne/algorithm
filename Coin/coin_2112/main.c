
#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4 , 5}, sum=0;
    int *ptr ;
    *&ptr = arr + 4;
    for( int i=0; i<5; i++){
        sum += *ptr;
         //printf("%d ", *ptr);
        *&ptr = (ptr - 1) ;
    }
    printf("%d", sum);
    return 0;
}
