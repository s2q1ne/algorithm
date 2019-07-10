#include <stdio.h>
#include <stdlib.h>

int compare (void *first, void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main()
{
    int N, nums[1000]={0,};
    int i, j, tmp, sum=0;

    scanf("%d", &N);
    for( i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }

    qsort(nums, N, sizeof(int), compare);

    if( nums[0]>1 ){
        printf("%d", 1);
        return 0;
    }
    for( i=0; i<N; i++){
        sum += nums[i];
        if( nums[i+1] > sum+1 )
            break;
    }
    printf("%d", sum+1);
    return 0;
}
