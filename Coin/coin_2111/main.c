
#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4 , 5};
    int *ptr = &arr[0];
    for( int i=0; i<5; i++){
        *(ptr+i) += 2;
    }
    printf("%d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4]);
    return 0;
}
