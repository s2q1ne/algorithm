#include <stdio.h>

int strlen(char A[200]){
    int i=0;
    while( A[i++] != '\0');
    return i-1;
    //A의 길이를 구해서 리턴한다.
}

int Max(int a, int b){
    return a>b?a:b;
    // a와 b중 큰 값을 리턴한다.
}

int ok(int a, int b){ // a--b가 성립되는지 확인하는 함수이다.
    if( a<0 || b<0 ) return 0;

    char A[500]={0,}, B[500]={0,};
    //나는 숫자 a, b를 비교하기 쉽게 문자열형으로 바꾸었다.
    int i, j, cnt=0, c;
    sprintf(A,"%d", Max(a,b)); // a,b 중 큰 숫자를 문자열로 바꾸어 A에 저장한다.
    sprintf(B, "%d", a+b-Max(a,b)); // a,b 중 작은 숫자를 문자열로 바꾸어 B에 저장한다.
    // a>b , A는 a를 문자열화, B는 b를 문자열화
    if( strlen(A)-strlen(B)>1 ) return 0; //자리수가 2개 이상 차이난다면 a--b가 성립되지 않는다.
    else {
        if( strlen(A)-strlen(B) == 1 ){
            // A가 B보다 한자리 많은 경우이다.
            for( i=strlen(B); i>0; i--){ //B의 맨 앞자리에 0을 추가한다면, 확인할 수 있다!
                B[i]= B[i-1]; //자리수를 한칸씩 뒤로 한다.
        //앞자리부터 바꾸어야 하므로 자리수+1인 strlen(B)부터 시작한다.
            }B[0] =0;

        }
        for( i=0; i<strlen(A); i++){
            if( A[i]==B[i] ){
                cnt++;
            }
            //A와 B를 비교해서 같은 경우에 cnt에 1을 추가한다.
        }
    }

    if( cnt == strlen(A)-1 ) // 한자리가 바뀌어도 상관 없으니, cnt가 A-1일
        //때 진실을 리턴한다.
        return 1;
    else //아니면 거짓을 리턴한다.
        return 0;
}

int A( int n)
{
    int i, j, k;
    int check, sum=0, cnt=0, N[10000]={0,}, D[10000]={0,}; //N은 소수 모음
    int a;
    for( i=2; i<=n; i++){ //2 ~ n까지 소수 구하기
        check = 1;
        for( j=2; j*j<=i; j++){ // i가 소수 인지 검출한다
            if( i % j == 0 ) { //2~i의 제곱근 까지 검색해서 나누어 떨어진다면 소수가 아니다
                check = 0;
                break;
            }
        }
        if( check == 0 ) continue; //소수가 아닌 경우 돌아간다.
        N[cnt++]=i; //소수를 배열에 저장한다
    }
    // N[0] ~ N[cnt-1] 는 오름차순의 소수이다.


    //이제 S(N)을 구해보자, 소수는 이미 검출해두었다.
    for( i=0; i<cnt; i++){
        // N[i] 에 대해 2->N[i]가 만족하는지 확인한다
        a = 2; // 2->P이므로 a를 2로 초기화 한다.
        for( k=0; k<=i; k++){
            D[k]=N[k];
        } //D를 초기화한다.
        printf("%d:\n", N[i]);

        for( j=0; j<i&&N[j]<n; j++){

            // a--N[j]가 맞으면 a를 N[j]로 설정한다.
            //ex) 2--3--5--7--17--127
            // 단, a--N[i]가 성립된다면 a를 바로 N[i]로 설정하고 빠져나온다.

            for(k=i; k>=0; k--){
                if( ok(D[k], a) ){
                    a=D[k];
                    D[k]=-1;
                    break;
                }
            }
            if( ok(a, N[i])){
                a=N[i];
                break;
            }
        }
        if( a!=N[i] || N[i]==2){
            sum +=N[i]; // a가 N[i]와 같다면 -> a--N[i]가 성립된 경우 2->N[i]를 만족함.
        //따라서 합계에 N[i]를 더한다.
        }
    }
    return sum;
}

int main(){
    int a;
    while(1){
        scanf("%d", &a);
        if( a<=0 ) break;
        printf("\nS(%d)=%d\n", a, A(a));
    }
}
