#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[300][300]={0,}, t_n[300][300];
    int size; // size = Å©±â
    int CR; // È½¼ö
    int i,j, tmp;

    scanf("%d %d", &size, &CR);
    for( i=0; i<size; i++){
        for( j=0; j<size; j++){
            scanf("%d", &n[i][j]);
        }
    }

    for( i=0; i<CR; i++ ){
        for (i=1;i<=size;i++)
          for (j=1;j<=size-1;j++)
            if (a[i-1][j-1] > a[i-1][j]){
                tmp = a[i-1][j-1];
                a[i-1][j-1] = a[i-1][j];
                a[i-1][j] = tmp;
            }
        for( i=0; i<size; i++){
            for( j=0; j<size; j++){

            }
        }
    }
    return 0;
}
