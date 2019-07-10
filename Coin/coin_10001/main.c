#include <stdio.h>

int main()
{
    int N, nums, a,b,c=0, count=0, tmp=0;
    int r[30][30], RR[30], pts[30], D=0, Hoit[30];
    int i,j;
    // input : N, number of factory, position of water load
    scanf("%d", &N);
    scanf("%d", &nums);
    //printf("a %d\n", nums);

    for( i=0; i<=N+1; i++){
        RR[i] = 0;
        Hoit[i] = 0;
        pts[i] = 0;
        for( j=0; j<=N+1; j++){
            r[i][j]=0;
        }
    } // 오류 방지를 위한 초기화 작업
    for( i=0; i<nums; i++){
        scanf("%d %d", &a,&b);
        //printf("a %d %d\n", a, b);
        r[a-1][++r[a-1][0]] = b-1;
        r[b-1][++r[b-1][0]] = a-1;
        if( pts[a-1] == 0)
            pts[a-1] = ++D;
        if( pts[b-1] == 0)
            pts[b-1] = ++D;
    }
    RR[0] = 1;
    for( i=0; i<N; i++){
        for( j=1; j<N; j++)
            if(r[i][j]!=0){
                printf("A%d %d\n", r[i][j]+1, i+1);
                RR[r[i][j]] = count++;
            }
    }
    for( i=0; i<N; i++){
            if(RR[i]>0){
                Hoit[pts[i]] = i+1;
                printf("ok %d       pts: %d\n", i+1 , pts[i]);
                c++;
            }
    }

    printf("%d\n",c-1);
    for( i=0; i<N; i++){
        if(Hoit[i]>0){
            printf("%d ", Hoit[i]);
        }
    }
    return 0;
}
