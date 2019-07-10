#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //int i=0;
    //while( ++i%101 )
    //    else if( i%2 == 0)
    //        printf("%d는 짝수입니다.\n", i);
    int a=0;
    time_t now;
    struct tm tt;
    time(&now);
    tt = *localtime(&now);
    a = tt.tm_year;
    a += tt. tm_mon;
    a += tt.tm_mday;
    printf("%d %d %d\n", 1, 2, 3);
    return 0;
}
