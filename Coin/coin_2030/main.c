#include <stdio.h>

int main()
{
    int AA, AB;
    int BA, BB;
    scanf("%d %d\n", &AA, &AB);
    scanf("%d %d", &BA, &BB);
    printf("%d", (BA-AA)*(BB-AB));
    return 0;
}
