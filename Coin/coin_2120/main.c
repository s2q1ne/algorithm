/*

���� num�� ����� ���� ������ ����ϴ� �Լ��� �����ϰ�, ���α׷� ����ڷκ��� ������ �Է¹޾�
������ ����ϴ� �Լ��� ������ ��ȯ ���� ����ϴ� main �Լ��� �ۼ��غ���. �� ���⼭�� ���� �� ���� ���·� �Լ��� �����ؾ� �Ѵ�.
1. Call-by-value ����� SquareByValue �Լ�
2. Call-by-reference ����� SquareByReference�Լ�

SquareByValue �Լ��� ���ڷ� ���޵� ���� ������ ��ȯ�ؾ� �ϸ�, SquareByReference
�Լ��� ������ ����Ǵ� �ִ� ������ �ּ� ���� ���ڷ� �޾Ƽ� �ش� ������ ����� ���� ������ �� ������ �ٽ� �����ؾ� �Ѵ�.

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
