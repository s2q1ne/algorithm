#include <iostream>
#include <algorithm>

using namespace std;

int N;

struct data{
    bool u = true;
    int n, x;
    bool operator < (const data &r) const{
        if( n==r.n) return x < r.x;
        return n < r.n;
    }
}meet[505];

int sorting(){
    int i,j;
    data tmp;
    for( i=0; i<N-1; i++){
        for( j=i+1; j<N; j++){
            if( meet[j].n < meet[i].n ){
                tmp = meet[j];
                meet[j] = meet[i];
                meet[i] = tmp;
            }

        }
    }
}


data isIn(data A, data B){
    A.n = A.n > B.n ? A.n : B.n;
    A.x = A.x < B.x ? A.x : B.x;
    if( A.n>=A.x ){
        return A;
    } else{
        A.u = false;
        return A;
    }
    return A;
}


int greedy(){
    int i, j, cnt=1, mn=meet[0].n, mx=meet[0].x;
    for( i=1; i<N; i++){
        if( meet[i].n<=mx && mn <= meet[i].x ){
            mn = meet[i].n< mn ? mn :meet[i].n;
            mx = meet[i].x> mx ? mx : meet[i].x;
        }// µé¾î°¨
        else{
            cnt++;
            mn = meet[i].n;
            mx = meet[i].x;
        }
    }
    return cnt;
}

int main()
{
    int i;
    scanf("%d", &N);
    for( i=0; i<N; i++)
        scanf("%d %d", &meet[i].n, &meet[i].x);

    sorting();
    printf("%d\n", greedy());
    return 0;
}
