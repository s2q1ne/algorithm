#include <stdio.h>
#include <stdlib.h>

int N; //��ǰ�� ���� ��
int NS[100][4]={0,}; //�⺻��ǰ 1, �⺻��ǰ 2, �⺻ ��ǰ 3, �⺻ ��ǰ 4

int* get( int n ){ //�⺻ ��ǰ 5
    int i;
    int a[4]={0,};
    for( i=0; i<4; i++){
        if( NS[n][i] !=0 ){
            a[i] = NS[n][i];
        }
    }
    return a;
}

int P( int n){

}

int main()
{
    int NUM, i, a, b, c;
    scanf("%d", &N);
    scanf("%d", &NUM);
    for( i=0; i<NUM; i++){
        scanf("%d %d %d", &a, &b, &c);
        NS[a][b] = c;
    }
    return 0;
}
