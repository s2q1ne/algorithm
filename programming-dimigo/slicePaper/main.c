#include <stdio.h>
#include <stdlib.h>

#define MAX_X 100
#define MAX_Y 100

int compare(const void *a, const void *b);

int main()
{
    int slice[2][100];
    int map[MAX_X][MAX_Y];
    int mx, mn, mc, i, j, tmp, tmp2,  sliceCnt[2]={0,0}; //A : 0 horizon B : 1 vertical
    int mxarea=0;
    scanf("%d %d", &mx, &mn);
    scanf("%d", &mc);
    slice[0][sliceCnt[0]++] = 0;
    slice[1][sliceCnt[1]++] = 0;
    for( i=0; i<mc; i++ ){
        scanf("%d", &tmp);
        scanf("%d", &slice[tmp][sliceCnt[tmp]++]);
        //printf("%d %d", tmp, slice[tmp][sliceCnt[tmp]-1]);
    }
    qsort( slice[0], sliceCnt[0], sizeof(int), compare );
    qsort( slice[1], sliceCnt[1], sizeof(int), compare );
    slice[0][sliceCnt[0]++] = mn;
    slice[1][sliceCnt[1]++] = mx;

    for( i=1; i<sliceCnt[0]; i++){
        tmp = slice[0][i]-slice[0][i-1];
        for( j=1; j<sliceCnt[1]; j++){
            tmp2 = slice[1][j]-slice[1][j-1];
            if( tmp*tmp2 > mxarea ) mxarea = tmp*tmp2;
        }
    }
    printf("%d", mxarea);
    return 0;
}

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환

    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환

    return 0;    // a와 b가 같을 때는 0 반환
}
