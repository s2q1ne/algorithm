#include <stdio.h>
int main() {
	int n,n2;
	double n3;
	scanf("%d", &n);
    n2 = n/1071;
    n = n-(n2 *1071);
    n3 = (double)n/1071 * 100;
	printf("%d�޷� %d��Ʈ", n2, (int)n3 );
	return 0;
}
