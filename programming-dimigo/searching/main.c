#include <stdio.h>
#include <stdlib.h>
int NUMS[60000], N;
int bs( int s ){
    int l=0, r=N-1, h=s, f;
    while(1){
        f = (l+r)/2;
        if( s > NUMS[f]  ){
            l = f+1;
        }
        else if( s < NUMS[f]  ){
            r = f-1;
        }
        else{
            return f+1;
        }
        if( l>r) return 0;

    }
}

int main()
{

    int  i, j, N2, NUMS2[50000] ;
    scanf("%d", &N);
    for( i=0; i<N; i++) scanf("%d", &NUMS[i]);
    scanf("%d", &N2);
    for( i=0; i<N2; i++) scanf("%d", &NUMS2[i]);
    for( i=0; i<N2; i++){
        printf("%d\n", bs(NUMS2[i]));
    }
    return 0;
}
