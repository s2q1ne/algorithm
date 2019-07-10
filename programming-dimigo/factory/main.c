#include <stdio.h>
#include <stdlib.h>

int map[101][101];
int m,n;
int compare(const void *a, const void *b);    // �������� �� �Լ� ����

int get( int x, int y ){
    if( x > n || x <= 0 || y <= 0 || y > m ){
        return 0;
    }
    if( map[x][y] != 0 ) {
        printf("x:%d , y:%d\n", x,y);
        map[x][y] = 0;
        return get( x+1, y) + get(x-1, y) + get(x, y+1) + get( x, y-1 ) + 1;
    }
    else
        return 0;
}

int main()
{
    int k, TOW[10000], cnt=0,tmp ;
    int i,j,x,y,a,b,c,d;
    scanf("%d %d %d", &m, &n, &k);
    for( i=0; i<k; i++ ){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for( x=a; x<=c; x++ ){
            for( y=b; y<=d; y++){
                map[x][y]=1;
            }
        }
    }
    for( i=1; i<=n; i++, printf("\n")){
        for( j=1; j<=m; j++){
            if( map[i][j] != 0 )
                printf("*");
            else
                printf("a");
        }
    }
    for( i=1; i<=n; i++){
        for( j=1; j<=m; j++){
            if( map[i][j] != 0 ){
                printf("x:%d y:%d\n", i,j);
                tmp = get(i,j);
                if( tmp ) TOW[cnt++] = tmp;
            }
        }
    }
    qsort( TOW, cnt, sizeof(int), compare);
    printf("%d\n", cnt);
    for( i=0; i<cnt; i++ )
        printf("%d ", TOW[i]);

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
