#include <stdio.h>
#include <stdlib.h>


typedef struct hi n;
struct hi{
    int a;
};

int main()
{
    printf("Hello world!\n");
    n hello = {4};
    printf("%d",hello.a);
    return 0;
}
