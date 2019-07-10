#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int A, B;
    double C;
    int i,cnt=0;
    scanf("%d", &A);
    // A^2 + B^2 = C^2
    // A < B < C, 모두 정수
    // B^2 = C^2 - A^2
    // B = root( C^2 - A^2 )
    // C = root( A^2 + B^2 )
    for( i=A; A+B>C; i++ ){
        B = A*A +i*i;
        C = sqrt( A*A + i*i );
        if(
           (int)C != C ||
           !( A<i && i<C))
            continue;
        else
            cnt++;
            printf("%d %d %d\n", A,B,C);
    }
    printf("%d", cnt);
    return 0;
}
