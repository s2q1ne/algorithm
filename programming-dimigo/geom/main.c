#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

#define MAX_X 600
#define MAX_Y 300
#define CONSOLE_WIDTH 60
#define CONSOLE_HEIGHT 30

#define BLOCK_BLANK 0
#define BLOCK_DAFAULT 1
#define BLOCK_OUT 2
#define BLOCK_PLAYER 3
#define BLOCK_UI 4

struct Gblock{
    int num;
    char *content;
    int len;
    char *blank;
} blocks[10];
int LenOfGblock=0;
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

struct Circle {
    int x;
    int y;
    int radius;
};
typedef struct Circle Circle;

struct Player{
    int x;
    int y;
    Gblock player;
};

typedef struct Player Player;

void drawRect2( Rect rect, const int block );
void drawRect( Rect rect, const int block );
void eraseRect( Rect rect );
void initMap();
void drawUI( Rect rect, char *message);

void initBlock(){
    int i=0;
    if(1){
        int num=0;
        char *content=" ";
        int len = 1;
        char *blank = " ";
        struct Gblock tmp = { num, content, len, blank };
        blocks[LenOfGblock++]=tmp;
    } // 공백: 빈 곳
    if(1){
        int num=1;
        char *content="*";
        int len = 1;
        char *blank = " ";
        struct Gblock tmp = { num, content, len, blank };
        blocks[LenOfGblock++]=tmp;
    } // * : 블럭 1
    if(1){
        int num=2;
        char *content="H";
        int len = 1;
        char *blank = " ";
        struct Gblock tmp = { num, content, len, blank };
        blocks[3]=tmp;
        LenOfGblock++;
    } // * : 블럭 1
    if(1){
        int num=3;
        char *content="P";
        int len = 1;
        char *blank = " ";
        struct Gblock tmp = { num, content, len, blank };
        blocks[LenOfGblock++]=tmp;
    } // P : Player

    if(1){
        struct Gblock tmp = { 4, "", 0, ""};
        blocks[LenOfGblock++]=tmp;
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
            printf("시작하려면 아무키나 누르세요!");
            Sleep(500);
            getoxy( CONSOLE_WIDTH/2-14, CONSOLE_HEIGHT/2 );
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

    void initalize(){
        srand(time(NULL));
        resizeConsole();
        initCursor();
        initBlock();
        initMap();
        displayStart();
    }


void drawMap(Player camera){
    for( int j=camera.y-CONSOLE_HEIGHT/2; j<=camera.y+CONSOLE_HEIGHT/2; j++){
        for( int i=camera.x-CONSOLE_WIDTH/2; i<=camera.x+CONSOLE_WIDTH/2; i+=blocks[map[i][j]].len){
            if( map[i][j] == BLOCK_UI ) continue;
            getoxy( i,j );
            printf("%s", blocks[map[i][j]].content);
        }
    }
}

void drawUI(Rect rect, char* message){
    drawRect2(rect, 1);
    getoxy((rect.lbx+rect.rtx)/2, (rect.lby+rect.rty)/2);
    printf("%s", message);
}

void movePlayer( Player user, Player user2 ){

}

int Move(Player *user, Player *camera, char dir){ //방향 통해 움직이기 -> 임시
    switch( dir ){
    case 75 : //move LEFT
        break;
        /*
        if( user->x > (camera->x+CONSOLE_WIDTH/2) || user->x < (camera->x - CONSOLE_WIDTH/2) ){//MAP밖
            getoxy( user->x , user->y );
            printf("%s", user->player.blank);
        }
        else if( map[user->x - user->player.len][user->y] == 0 ){ //충돌X
            getoxy( user->x, user->y);
            printf("%s",user->player.blank);
            getoxy(user->x -= user->player.len, user->y);
            printf("%s",user->player.content);
        }

        break;
    /*
    case 32 : //SPACE -> JUMP
        getoxy(x, y);
        printf("%s",player_blank);
        getoxy(x, y+player_len);
        printf("%s",player_);
        //JUMP() : 추후 구현
        return 1;
        break;
*/
    case 77 : //move Right
        if( user->x + user->player.len > (camera->x+CONSOLE_WIDTH/2) || user->x + user->player.len < (camera->x - CONSOLE_WIDTH/2) ){//MAP밖
            //getoxy( user->x , user->y );
            //printf("%s", user->player.blank);
        }
        else if( map[user->x + user->player.len][user->y] == 0 ){ //충돌X
            getoxy( user->x, user->y);
            printf("%s",user->player.blank);
            getoxy(user->x += user->player.len, user->y);
            printf("%s",user->player.content);
        }
        break;

    default:
        getoxy(user->x, user->y);
        printf("%s",user->player.content);

    }
    return 0;
}


void drawRect( Rect rect, const int block ){//맵에 도형 그리기
    int cnt=0;
    for( int i=rect.lbx; i<=rect.rtx; i++){
        for( int j=rect.lby; j<=rect.rty; j++ ){
            if( i > MAX_X || i<0 || j<0 || j>MAX_Y ) continue;
            map[i][j] = block ;
        }
    }
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
    Rect rect = {5, 9, 20, 14};
    drawRect( rect, BLOCK_DAFAULT );
    Rect rect2 = {10, 2, 30, 5};
    drawUI( rect2, "HELLO");
}

int main()
{
    Gblock player_ = blocks[BLOCK_PLAYER];
    Gblock camera_ = {1, "", 1, "" };
    Player user={CONSOLE_WIDTH/2-1, CONSOLE_HEIGHT*2/3, player_}; //X, Y
    Player camera = {CONSOLE_WIDTH/2, CONSOLE_HEIGHT/2, camera_};
    char ch;
    initalize();

    drawMap(camera);
    getoxy(user.x, user.y);
    printf("%s", user.player.content);

    while( 1 ){
        if( kbhit() ){
            ch = getch();
            Move(&user, &camera,ch); //1 -> Jump, 0 -> Move
        }
    }
    getchar();
    return 0;
}
