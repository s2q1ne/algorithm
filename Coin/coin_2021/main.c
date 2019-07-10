#include <stdio.h>

int main()
{
    // 3 * 8 / 4 but  *사용 X / 사용 X
    int a=3, b=8, c=4,i=0,s=0,t=0;
    for(i=0; i<b; i++){
        s+=a;
    }
    s = s - ( s % c);
    for( i=s; i>1; i-=c){
        t++;
    }
    printf("%d\n", t);
    return 0;
}
