#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define A2 "����"
#define A0 "����"
#define A5 "��"

#define QQ 4

time_t t;
FILE* textfile;
FILE* output;
int A[100000], B[100000];
int FF[100000][QQ];

char* text( int a ){
    switch( a ){
    case 0:
        return A0;
    case 2:
        return A2;
    case 5:
        return A5;
    }
    return "error";
}

int win( int a, int b){printf("\n");
    if( a==b ){
        printf("���º�\nCOM: %s USER: %s\n\n",text(b), text(a));
        return 0;
    }
    else if( ( a==2 && b==0 ) || ( a==0 && b==5 ) || ( a==5 && b==2 ) ){
        printf("COM WIN\nCOM: %s USER: %s \n\n  ", text(b), text(a));
        return 0;
    }
    else {
        printf( "USER WIN\nCOM: %s USER: %s \n\n  ", text(b), text(a));
        return 0;
    }
}

int playing( int b ){
    int a;
    printf("(%s) : 2 (%s) : 0 (%s) : 5\nINPUT: ", A2, A0, A5); //A=���� B=���� C=��

    scanf("%d", &a);
    if( a == -1 ) return 0;

    if( !(a == 0 || a==2 || a==5) ){
        printf("\n\n");
        return playing(rand()%3);
    }
    win(make_(a), make_(b));
    report(a,b);
    playing(rand()%3);

}

int make_(int A){
    switch(A){
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 5;
    }
}

int report( int A, int B ){ //A = COM , B= USER
    output = fopen("output.txt", "at");
    fprintf( output, "%d %d\n", make_(A), make_(B));
    fclose(output);
    return 0;
}

int read(){
    int i;
    for( i=0; i<100000; i++ )   A[i] = B[i] = -1;
    textfile = fopen("input.txt", "rt");
    for( i=0;  fscanf(textfile, "%d %d", &A[i], &B[i])!=-1 ;i++);
    fclose(textfile);
    return 0;
}



int print(){ //���Ϸ� �о�� ���� �̿��� ����ϴ� �Լ�
    int i,j;
    printf("\n ������ �Է��ϼ���! : ");
    scanf("%d", &QQ);
    for( i=0; A[i]!=-1; i++ ){
        for( j=i; j<i+QQ && A[j+QQ] != -1; j++  ){ //��� ��� //�� ������ �� ���� �ִ��� ���
            //������ ����� �������� ����.
            //FF[i][j-i] =
        }
    }
}
int scan(){ //������ � �ִ��� Ȯ��

}

int main()
{
    srand((unsigned) time(&t));
    playing(rand()%3);
    return 0;
}
