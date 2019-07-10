#include <stdio.h>
#include <stdlib.h>

int sorting(int *a ){
    if( a[1] > a[2]){
        return 1;
    }
    else
}

int main()
{
    int i, n, tmp_t[2], time_db[2000][3] = {0, }, t_st=0;
    scanf("%n", &n);
    for( i=0; i<n; i++ ){
        scanf("%d %d", &tmp_t[0], &tmp_t[1]);
        time_db[t_st][0] = 1;
        time_db[t_st][1] = tmp_t[0];
        time_db[t_st++][2] = tmp_t[1];

        scanf("%d %d", &tmp_t[0], &tmp_t[1]);
        time_db[t_st][0] = -1;
        time_db[t_st][1] = tmp_t[0];
        time_db[t_st++][2] = tmp_t[1];
    }
    return 0;
}
