#include <stdio.h>

int MAX(int n1, int n2, int n3){
    return n1>n2?(n3>n1?n3:n1):(n3>n2?n3:n2) ;
}
int MIN(int n1, int n2, int n3){
    return n1<n2?(n3<n1?n3:n1):(n3<n2?n3:n2) ;
}

int main()
{
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    printf("���� ū �� : %d\n", MAX(n1,n2,n3));
    printf("���� ���� �� : %d", MIN(n1, n2, n3));
    return 0;
}
