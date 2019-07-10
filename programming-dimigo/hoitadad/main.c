#include <stdio.h>
int main(){
    int s,t=0;
    scanf("%d", &s);
    while( s > 0 ){
        t += s%2;
        s /= 2;
    }
    return printf("%d", t)*0;
}
