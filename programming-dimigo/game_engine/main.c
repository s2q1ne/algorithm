#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <pthread.h>

#define MAX_X 600
#define MAX_Y 300
#define CONSOLE_WIDTH 60
#define CONSOLE_HEIGHT 30

#define PLAYER_USER_MIN_Y CONSOLE_HEIGHT-4

#define BLOCK_BLANK 0
#define BLOCK_SNOW 1
#define BLOCK_ACTIVE_SNOW 2
#define BLOCK_DEFAULT 3
#define BLOCK_PLAYER 4
#define BLOCK_UI 5

#define COLOR_SNOW 0x03
#define COLOR_DEFAULT 0x07
#define COLOR_PLAYER 0x0C
#define COLOR_UI 0x06

struct Gblock{
    int num;
    char *content;
    int len;
    char *blank;
    int color;
} blocks[10];

const int LenOfGblock=5;
typedef struct Gblock Gblock;

int map[MAX_X][MAX_Y];
// 0: 공백
// 1: block
// 2: Out of Map
// 3+.. -> Another


    struct Rect {
        int lbx;
        int lby;
        int rtx;
        int rty;
    }; // -> 후에 큐 자료형으로 변경
    typedef struct Rect Rect;
/*
    struct Circle {
        int x;
        int y;
        int radius;
    };
    typedef struct Circle Circle;
*/

struct Obj{
    int x;
    int y;
    Gblock player;
};

typedef struct Obj object;

void drawRect2( Rect rect, const int block );
void drawRect( Rect rect, const int block );
void eraseRect( Rect rect );
void initMap();
void drawUI( char *message, Rect rect , int color);

void initBlock(){
    int i=0;
    if(1){
        struct Gblock tmp = { BLOCK_BLANK, " ", 1, " ", COLOR_DEFAULT };
        blocks[BLOCK_BLANK]=tmp;
    } // 공백: 빈 곳
    if(1){
        struct Gblock tmp = { BLOCK_SNOW, "*", 1, " ", COLOR_DEFAULT};
        blocks[BLOCK_SNOW]=tmp;
    } // * : SNOW
    if(1){
        struct Gblock tmp = { BLOCK_ACTIVE_SNOW, "*", 1, " ", COLOR_SNOW};
        blocks[BLOCK_ACTIVE_SNOW]=tmp;
    } // * : 블럭 1
    if(1){
        struct Gblock tmp = { BLOCK_DEFAULT, "=", 1, " ", COLOR_DEFAULT};
        blocks[BLOCK_DEFAULT]=tmp;
    }

    if(1){
        struct Gblock tmp = { BLOCK_PLAYER, "P", 1, " ", COLOR_PLAYER};
        blocks[BLOCK_PLAYER]=tmp;
    }

    //UI
} // 블럭 초기화 하기 : Player 별 색


    void getoxy( int x, int y) {
        COORD pos = {x,y};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    }

    void resizeConsole(){
        char A[100];
        sprintf(A, "Mode con cols=%d lines=%d", CONSOLE_WIDTH, CONSOLE_HEIGHT);
        system(A);
    }

    void displayStart(){
        while( 1 ){
            getoxy( CONSOLE_WIDTH/2-14, CONSOLE_HEIGHT/2 );
            char *text = "시작하려면 아무키나 누르세요!";
            printf("%s", text);
            Sleep(500);
            getoxy( CONSOLE_WIDTH/2-strlen(text)/2, CONSOLE_HEIGHT/2 );
            for( int i=0; i<=strlen(text); i++) printf(" ");
            printf(" ");
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

    void initalize(){
        srand(time(NULL));
        resizeConsole();
        initCursor();
        initBlock();
        initMap();
        displayStart();
    }


void drawMap(){
    for( int j=0; j<CONSOLE_HEIGHT; j++){
        for( int i=0; i<CONSOLE_WIDTH; i+=1){//(blocks[map[i][j]].len>0?blocks[map[i][j]].len:1)
            if( map[i][j] == BLOCK_UI ) continue;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),blocks[map[i][j]].color);
            getoxy( i, j );
            printf("%s", blocks[map[i][j]].content);
            //printf("%1d", blocks[map[i][j]].num);
        }
    }
}

void drawUI( char message[30], Rect rect, int color ){
    int len = strlen(message);
    drawRect2(rect, BLOCK_UI);

    //if( rect.rtx - rect.lbx > len ){
        for( int i=rect.lbx , c=0 ; i<rect.lbx+len; i++, c++){
            getoxy( i , (rect.lby+rect.rty)/2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            printf("%c", message[c]);
        }
    /*}
    else{
        for( int i=(rect.lbx+rect.rtx)/2-len/2 , c=0 ; i<(rect.lbx+rect.rtx)/2+len/2; i++, c++){
            getoxy( i , (rect.lby+rect.rty)/2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            printf("%c", message[c]);
        }
    }*/

}

void movePlayer( object user, object user2 ){

}

int Move(object *user, char dir){ //방향 통해 움직이기 -> 임시
    switch( dir ){
    case 75 : //move LEFT

        if(  user->x - user->player.len < 0 ) {//MAP밖
            getoxy( user->x , user->y );
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_DEFAULT);
            printf("%s", user->player.blank);
            user->x = CONSOLE_WIDTH-1;
            getoxy( user->x , user->y );
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), blocks[BLOCK_PLAYER].color);
            printf("%s", user->player.content);
        }
        else if( map[user->x - user->player.len][user->y] == BLOCK_BLANK ){ //충돌X
            getoxy( user->x, user->y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLOCK_BLANK);
            printf("%s",user->player.blank);
            getoxy(user->x -= user->player.len, user->y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), blocks[BLOCK_PLAYER].color);
            printf("%s",user->player.content);
        }

        break;
    case 72 : // move TOP
        if( map[user->x ][user->y-1] == BLOCK_BLANK ){
            getoxy( user->x, user->y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_DEFAULT);
            printf("%s",user->player.blank);
            getoxy(user->x , user->y-=1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), blocks[BLOCK_PLAYER].color);
            printf("%s",user->player.content);
        }
        break;
    case 80 :
        if( user->y + 1 >= CONSOLE_HEIGHT ) break;
        else if( map[user->x][user->y+1] == BLOCK_BLANK && user->y+1 < CONSOLE_HEIGHT ){
            getoxy( user->x, user->y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_DEFAULT);
            printf("%s",user->player.blank);
            getoxy(user->x, user->y +=1 );
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), blocks[BLOCK_PLAYER].color);
            printf("%s",user->player.content);
        }

        break;
    case 77 : //move Right
        if( user->x + user->player.len >= (CONSOLE_WIDTH)  ){//MAP밖
            getoxy( user->x , user->y );
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_DEFAULT);
            printf("%s", user->player.blank);
            user->x = 0;
            getoxy( user->x , user->y );
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), blocks[BLOCK_PLAYER].color);
            printf("%s", user->player.content);
        }
        else if( map[user->x + user->player.len ][user->y] == BLOCK_BLANK ){ //충돌X
            getoxy( user->x, user->y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_DEFAULT);
            printf("%s",user->player.blank);
            getoxy(user->x += user->player.len, user->y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), blocks[BLOCK_PLAYER].color);
            printf("%s",user->player.content);
        }
        break;

    default:
        getoxy(user->x, user->y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), blocks[BLOCK_PLAYER].color);
        printf("%s",user->player.content);

    }
    return 0;
}

void fallSnow(){
    //for( int i=0; i<snows[SNOW_MAX]; i++){

    //}
}

void drawRect( Rect rect, const int block ){//맵에 도형 그리기
    int cnt=0;
    for( int i=rect.lbx; i<=rect.rtx; i++){
        for( int j=rect.lby; j<=rect.rty; j++ ){
            if( i > CONSOLE_WIDTH || i<0 || j<0 || j>CONSOLE_HEIGHT ) continue;
            map[i][j] = block ;
        }
    }
    /*
    for( int i=0; i<=CONSOLE_WIDTH; i++){
        getoxy( i, PLAYER_USER_MIN_Y-1);
        printf("*");
    }
    */
}
void eraseRect( Rect rect ){
    drawRect( rect, 0 );
}

void drawRect2( Rect rect, const int block ){
    drawRect( rect, block );
    rect.lbx +=1;
    rect.lby +=1;
    rect.rtx -=1;
    rect.rty -=1;
    eraseRect( rect );
}


void initMap(){

    Rect rect = {0, PLAYER_USER_MIN_Y-1, CONSOLE_WIDTH-1, PLAYER_USER_MIN_Y-1};
    drawRect( rect, BLOCK_DEFAULT );
    //Rect rect2 = {10, 2, 30, 5};
    //drawUI( rect2, "HELLO");

}

void setColor( int color ){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//제설하기 게임

int main()
{
    Gblock player_ = {BLOCK_PLAYER,"P",1," ",0x04};
    object user={CONSOLE_WIDTH/2-1, (PLAYER_USER_MIN_Y+CONSOLE_HEIGHT)/2, player_ };
    Gblock snow = {BLOCK_SNOW, "*",1," ", 0x03};
    //Gblock camera_ = {1, "", 1, "", 0x00 };
    //object camera = {CONSOLE_WIDTH/2, CONSOLE_HEIGHT/2, camera_};
    Rect XYui = { 1, 1, 8, 1};

    char ch, message[30];
    initalize();

    drawMap();

    getoxy(user.x, user.y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),blocks[BLOCK_PLAYER].color);
    printf("%s", user.player.content);
    sprintf(message,"x: %3d, y: %3d",user.x, user.y);
    drawUI( message, XYui, COLOR_UI);

    while( 1 ){
        if( kbhit() ){
            ch = getch();
            Move(&user, ch);

            sprintf(message,"x: %3d, y: %3d",user.x, user.y);
            drawUI( message, XYui, COLOR_UI);
        }
    }
    getchar();
    return 0;
}
