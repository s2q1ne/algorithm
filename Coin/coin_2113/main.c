/*
길이가 6인 int형 배열 arr을 선언하고 이를 1, 2, 3, 4, 5, 6으로 초기화한 다음,
 배열에 저장된 값의 순서가 6, 5, 4, 3, 2, 1이 되도록 변경하는 예제를 작성해보자
 . 단, 배열의 앞과 뒤를 가리키는 포인터 변수 두 개를 선언하여 이를 활용하여 저장된 값의 순서를 뒤바꿔야 한다.
변경한 배열은 arr[0]부터 arr[5]까지 공백 한 칸으로 구분하여 한 줄에 출력한다.

*/


#include <stdio.h>
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6}, *front, *back, tmp, i;
    front = &arr[0];
    *&back = arr+5;
    for( i=0; i<3; i++){
        tmp=*(front+i);
        *(front+i) = *(back-i);
        *(back-i) = tmp;
    }
    printf("%d %d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);

    return 0;
}
