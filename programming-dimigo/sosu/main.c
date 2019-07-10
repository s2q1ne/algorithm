#include <stdio.h>
#include <stdlib.h>

int is( int a){
    if( a <= 1 ){ return 0; }
    if( a == 2) return 1;
    for( int i=2; i<=a/2; i++){
        if( a%i == 0 ) return 0;
    }
    return 1;
}

int main()
{
    int nums[100], n, i, cnt=0;
    scanf("%d", &n);
    for( i=0; i<n; i++){
        scanf("%d", &nums[i]);
        if(is(nums[i])) /*printf("%d", nums[i])*/cnt++;
    }
    printf("%d", cnt);
    return 0;
}
