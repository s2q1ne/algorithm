#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N[100],NUM, i, j, m, mn;
    scanf("%d", &NUM);
    int tmp=0;

    for( i=0; i<NUM; i++)
        scanf("%d",&N[i]);
    for( i=0; i<NUM-1; i++){
        m=N[i]; mn=i;
        for( j=i+1; j<NUM; j++){
            if( m>N[j]){
                mn = j;
                m = N[j];
            }
        }
        tmp = N[i];
        N[i] = N[mn];
        N[mn] = tmp;
        for( j=0; j<NUM; j++)
            printf("%d ", N[j]);
        printf("\n");
    }

    return 0;
}
