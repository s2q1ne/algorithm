#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check( char n[20] ){
	int a, b, i;
	for( i=0; i<=(strlen(n))/2; i++)
		if( n[i] != n[strlen(n)-1-i] ) return 0;
	return 1;
}

int main() {
	int i,j;
	char A[20]="";
	int top=0;
	for( i=999; i>=100; i--){
		for( j=999; j>=100; j--){
			itoa(i*j, A, 10);
			if( check( A )){
                if( top < i*j )
                    top=i*j;
			}
		}
	}
	printf("%d", top);
	return 0;
}
