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

int compare(const void *a, const void *b)    // �������� �� �Լ� ����
{
    int num1 = *(int *)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
    int num2 = *(int *)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

    if (num1 < num2)    // a�� b���� ���� ����
        return -1;      // -1 ��ȯ

    if (num1 > num2)    // a�� b���� Ŭ ����
        return 1;       // 1 ��ȯ

    return 0;    // a�� b�� ���� ���� 0 ��ȯ
}
