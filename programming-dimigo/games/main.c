#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

#define MAX_X 60
#define MAX_Y 30

const char* player_ = "*";
const int player_len = 1;
const char* player_blank = " ";
struct Rect {
    int lbx;
    int lby;
    int rtx;
    int rty;
} map[100]; // -> 후에 큐 자료형으로 변경
int MAP_len = 0;

void initRect(){
    int i=0;
    while(i++<2){
        addRect();
    }
}
void addRect(int y){
    int width=rand()%MAX_X/2;
    int height = rand()%MAX_Y/2;
    int ax = rand()%MAX_X;
    int ay = rand()%MAX_Y;
    int cx = MAX_X/2 - ax/2;
    int cy = MAX_Y/2 - ay/2;
    struct Rect tmp = { cx-width/2,y+cy-height/2,cx+width/2,y+cy+height/2};
    map[MAP_len++]=tmp;
}

void drawMap(int y){
    for( int i=0; i<MAP_len; i++){
        draw( map[i], y );
    }
}

void getoxy( int x, int y) {
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void resizeConsole(){
    char A[100];
    sprintf(A, "Mode con cols=%d lines=%d", MAX_X, MAX_Y);
    system(A);
}

void displayStart(){
    while( 1 ){
        getoxy( MAX_X/2-14, MAX_Y/2 );
        printf("시작하려면 아무키나 누르세요!");
        Sleep(500);
        getoxy( MAX_X/2-14, MAX_Y/2 );
        printf("                             ");
        if( kbhit() ){ getch(); break; }
        Sleep(500);
    }
}

void initCursor(){
    CONSOLE_CURSOR_INFO info = {0};
    info.dwSize = 1;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
int Move(int x, int y, char dir){
    switch( dir ){
    case 75 : //move LEFT
        getoxy(x, y);
        printf("%s",player_blank);
        getoxy(x-player_len, y);
        printf("%s",player_);
        return -1;
    case 32 : //SPACE -> JUMP
        return 3;
        getoxy(x, y);
        printf("%s",player_blank);
        getoxy(x, y+player_len);
        printf("%s",player_);
        //JUMP() : 추후 구현


    case 77 : //move Right
        getoxy(x, y);
        printf("%s",player_blank);
        getoxy(x+player_len, y);
        printf("%s",player_);
        return 1;

    default:
        getoxy(x, y);
        printf("%s",player_);

    }
    return 0;
}

int draw( struct Rect b, int y  ){//현재 위치
    int cnt=0;
    y=0;
    for( int i=b.lbx; i<=b.rtx; i++){
        for( int j=b.lby-y; j<=b.rty-y; j++ ){
            if( i > MAX_X || i<0 || j<0 || j>MAX_Y ) continue;
            getoxy(i,j);
            printf("%s", player_);
            cnt++;
        }
    }
    for( int i=b.lbx+1; i<=b.rtx-1; i++){
        for( int j=b.lby+1-y; j<=b.rty-1-y; j++ ){
            if( i > MAX_X || i<0 || j<0 || j>MAX_Y ) continue;
            getoxy(i,j);
            printf("%s", player_blank);
            //cnt++;
        }
    }
    if( cnt <= 0 ) return -1; //map 없애기 신호
    return 0; // 정상종료
}

int eraseRect( struct Rect b, int y ){
    int cnt=0;
    for( int i=b.lbx; i<=b.rtx; i++){
        for( int j=b.lby-y; j<=b.rty-y; j++ ){
            if( i > MAX_X || i<0 || j<0 || j>MAX_Y ) continue;
            getoxy(i,j);
            printf("%s", player_blank);
            cnt++;
        }
    }
    if(cnt <=0) return -1; //맵 없애기 신호
    return 0; //정상종료
}



int main()
{
    srand(time(NULL));
    int x=MAX_X/2-1,y=MAX_Y*2/3;
    resizeConsole();
    initCursor();
    displayStart();

    char ch;
    int tmp;
    initRect();
    drawMap(y);
    getoxy(x, y);
    printf("%s", player_);
    while( 1 ){
        if( kbhit() ){
            ch = getch();
            tmp = Move(x, y, ch); //1 -> Right, -1 -> Left , 3 -> Jump , 0 -> default;
            if( tmp == 1 || tmp == -1 ) x += tmp;
        }
    }
    getchar();
    return 0;
}

/*

점프!
*/
