/*

섭씨(Celsius) 온도를 입력하면
화씨(Fahrenheit) 온도를 반환하는 CelToFah라는 이름의 함수와
그 반대로 화씨 온도를 입력하면 섭씨 온도를 반환하는 FahToCel이라는 이름의 함수를 정의하자.
 프로그램 사용자로부터 한 정수 a를 입력받으면 미리 정의한 함수를 이용해 섭씨 a도를 화씨 온도로 변환,
 화씨 a도를 섭씨 온도로 변환하여 출력하는 main함수도 작성해 보자. 출력할 때 소수점은 버리고 정수로 출력한다.

참고로 섭씨와 화씨 간 온도 변환의 공식은 다음과 같다.
Fah = 1.8 * Cel + 32

섭씨 20도는 화씨 68도
화씨 20도는 섭씨 -6도
*/

#include <stdio.h>

int CelToFah( float Cel ){
    return 1.8 * Cel + 32;
}
int FahToCel( float Fah ){
    return (Fah-32) / 1.8;
}
int main()
{
    int t;
    scanf("%d", &t);
    printf("섭씨 %d도는 화씨 %d도\n", t, CelToFah(t));
    printf("화씨 %d도는 섭씨 %d도\n", t, FahToCel(t));
    return 0;
}
