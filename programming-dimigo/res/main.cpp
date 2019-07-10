#include <stdio.h>

// 모두 1부터 사용할 것
int board[20 + 2];  // 벽장
int open[2 + 2];    // 열린 벽장
int visit[20 + 2];  // 방문 순서
int bs;             // 벽장 크기
int vs;             // 방문 크기
int answer = 2147483647;
int result;

int abs(int a, int b){
    if (a > b)
        return a - b;
    else
        return b - a;
}

int recursion(int count){

    if (count > vs){
        if (result < answer){
            answer = result;
        }
        return 0;
    }

    int temp;

    for (int i = 1; i <= 2; i++){
        temp = open[i];

        result += abs(visit[count], open[i]);
        open[i] = visit[count];

        recursion(count+1);

        open[i] = temp;
        result -= abs(visit[count], open[i]);
    }

    return 0;
}

int main(void)
{
    scanf("%d", &bs);
    scanf("%d %d", &open[1], &open[2]);
    scanf("%d", &vs);
        for (int i = 1; i <= vs; i++){
        scanf("%d", &visit[i]);
    }
    recursion(1);
    printf("%d\n", answer);

    return 0;

}
