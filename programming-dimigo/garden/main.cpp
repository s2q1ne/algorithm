#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
int val[10000];

struct whereis{
    int from;
    int to;
    int cnt;
    bool operator<(const whereis &r){
        if( to == r.to ) return to-from < r.to-r.from;
        return to < r.to;
    };
} whereis[100000];

int main()
{
    int vol, m, pos, cont=0, value=0;

    scanf("%d %d", &n, &vol);
    scanf("%d", &m);
    for( int i=0; i<m; i++ ){
        scanf("%d %d %d", &whereis[i].from, &whereis[i].to, &whereis[i].cnt);
        whereis[i].from --;
        whereis[i].to --;
    }
    sort(whereis, whereis+m);

    for( int i=0; i<m; i++ ){
        printf("%d) Cnt: %d\n", i, whereis[i].cnt);
        //printf("%d) from: %d to: %d cnt: %d\n\n",i,whereis[i].from,whereis[i].to,whereis[i].cnt);
        cont=0;
        for( int j=whereis[i].from; j<n; j++){
            cont += val[j];
        }
        printf("%d) Cont: %d\n", i, cont);
        if( whereis[i].cnt<=vol-cont ) //vol-cont: �ִ밪
            val[whereis[i].from]+= whereis[i].cnt;
        else if( vol-cont > 0 ){
            val[whereis[i].from] += vol-cont;
        }

    }
    for( int i=0; i<n; i++){
        value += val[i];
        printf("value%d: %d\n", i, val[i]);
    }
    printf("%d", value);
    return 0;
}

