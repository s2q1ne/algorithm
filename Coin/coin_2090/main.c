#include <stdio.h>
int main()
{
    int nums[5];
    int i, max_, min_, sum=0;
    scanf("%d", &nums[0]);
    max_ = min_ = nums[0];
    for( i=1; i<5; i++){
        scanf("%d", &nums[i]);
    }
    for( i=0; i<5; i++){
        max_ = max_ < nums[i] ? nums[i] : max_;
        min_ = min_ > nums[i] ? nums[i] : min_;
        sum+=nums[i];
    }
    printf("�ִ� : %d\n", max_);
    printf("�ּڰ� : %d\n", min_);
    printf("�� : %d", sum);
    return 0;
}
