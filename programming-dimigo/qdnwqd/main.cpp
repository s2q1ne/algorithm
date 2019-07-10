#include <stdio.h>
#include <algorithm>

using namespace std;

struct room{
	//int num;
	int start;
	int stop;
} arr[10000];

struct time{
    int start;
    int stop;
    int type; // 0 : ����, 1 : ä���� ��
} srt[10000];

bool mIs( struct room F1, struct room F2){

    if( F1.start == F2.start )
        return F1.stop < F2.stop;
    return F1.start < F2.start;
}

int main() {
    int n, start=0, stop=0;
    int mxB=0, mxF=0; //mxB: ��ĭ ���� �� ��, mxF: ä���� ���� �� ��
    int cnt = -1;
    int i, len;

    scanf("%d", &n);
    for( i=0; i<n; i++ ){
        scanf("%d %d", &arr[i].start, &arr[i].stop );
    }

    sort( arr, arr+n, mIs);

    for( i=0; i<n; i++){
        if( i==0 || srt[cnt].type == 0 ){ // ���� ������ ��
            srt[++cnt].start = arr[i].start;
            srt[cnt].stop = arr[i].stop;
            srt[cnt].type = 1;
            stop = arr[i].stop;
        }

        else if( stop >= arr[i].start ){ // ��ĥ ��
            srt[cnt].stop = arr[i].stop;
            stop = arr[i].stop;
        }

        else if( stop < arr[i].start ){// �� ��ĥ ��
            //�տ� ���� �߰��ϱ�
            srt[++cnt].start = stop;
            srt[cnt].stop = arr[i].start;
            srt[cnt].type = 0;

            stop = arr[i].stop;

            srt[++cnt].start = arr[i].start;
            srt[cnt].stop = arr[i].stop;
            srt[cnt].type = 1;
        }
    }


    for( i=0; i<=cnt; i++ ){
        len = srt[i].stop-srt[i].start;
        //printf("����: %d %d %d\n", srt[i].start, srt[i].stop, srt[i].type);
        if( srt[i].type == 0){
            if( mxB < len ){
               mxB = len;
            }
        }
        if( srt[i].type == 1 ){
            if( mxF < len ){
                mxF = len;
            }
        }
    }

    printf("%d %d", mxF, mxB);
	return 0;
}
