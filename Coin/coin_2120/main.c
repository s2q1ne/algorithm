/*

변수 num에 저장된 값의 제곱을 계산하는 함수를 정의하고, 프로그램 사용자로부터 정수를 입력받아
제곱을 계산하는 함수에 전달해 반환 값을 출력하는 main 함수를 작성해보자. 단 여기서는 다음 두 가지 형태로 함수를 정의해야 한다.
1. Call-by-value 기반의 SquareByValue 함수
2. Call-by-reference 기반의 SquareByReference함수

SquareByValue 함수는 인자로 전달된 값의 제곱을 반환해야 하며, SquareByReference
함수는 정수가 저장되더 있는 변수의 주소 값을 인자로 받아서 해당 변수에 저장된 값의 제곱을 그 변수에 다시 저장해야 한다.

*/


#include <stdio.h>

int SquareByValue( int num ){
    return num*num;
}
int SquareByReference( int *num ){
    *num = *num * *num;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d ", SquareByValue(n));
    SquareByReference(&n);
    printf("%d", n);
    return 0;
}
