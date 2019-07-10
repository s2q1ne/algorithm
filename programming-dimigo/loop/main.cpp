#include <iostream>
#include <stdio.h>

using namespace std;

int n, minmoney=100000000;
int ch1[12];
int mo[12][12];

void dfs( int from , int money ){

    if( money > minmoney ){
        return;
    }

    if( from == 0 && ch1[from]==1 ){ // �ٽ� ���ƿ��� ��
        int i;
        for( i=0; i<n; i++ ){ //�ٸ� ���� �� ���� ������
            if( ch1[i]==0 )break;
        }
        if( i==n ){ //�ٸ� ���� �� ���� �ִ� ���¸�
            if( money < minmoney ){
                minmoney = money;
                return;
            }
        }
        else
            return;
    }

    for( int i=0; i<n; i++){
        if( mo[from][i] !=0 && ch1[i]==0 ){ //�Ȱ� ���� ���
            ch1[i]=1;
            dfs( i, money+mo[from][i] );
            ch1[i]=0;
        }
    }
}

int main()
{
    int i,j;
    scanf("%d", &n);
    for( i=0; i<n; i++){
        for( j=0; j<n; j++){
            scanf("%d", &mo[i][j]);
        }
    }
    dfs(0,0);
    printf("%d", minmoney);
    return 0;
}
