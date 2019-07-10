/*

세 변수의 주소를 불러와 저장된 값을 서로 뒤바꾸는 함수를 정의해보자. 예를 들어서 함수의 이름이 Swap3이라면, 다음의 형태로 함수가 호출되어야 한다.
Swap3(&num1, &num2, &num3);

함수 호출의 결과로 num1에 저장된 값을 num2에, num2에 저장된 값을 num3에, 그리고 num3에 저장된 값을 num1에 저장되어야 한다.
또한, 프로그램 사용자로부터 세 개의 정수를 입력받아 세 개의 변수에 저장하고, 위의 방식으로 함수를 호출한 후 순서대로 출력하는 main함수도 작성해 보자.

*/

#include <stdio.h>

int Swap3( int *num1, int *num2, int *num3){
    int tmp = *num3;
    *num3 = *num2;
    *num2 = *num1;
    *num1 = tmp;
    return 0;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    Swap3( &a, &b, &c );
    printf( "%d %d %d", a, b, c);
    return 0;
}
