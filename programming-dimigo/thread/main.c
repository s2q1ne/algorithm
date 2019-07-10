#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <pthread.h>
#include <string.h>
#include <math.h>

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
#define BLOCK_PERSON 7

#define COLOR_SNOW 0x0B
#define COLOR_DEFAULT 0x07
#define COLOR_PLAYER 0x0C
#define COLOR_UI 0x06
#define COLOR_ACTIVESNOW 0x03
#define COLOR_PERSON 0x0c
#define COLOR_BGUI 0x60
#define COLOR_RED 0x0C
#define COLOR_KEYBOARD 0x80

#define DEFAULT_HP 5
#define SPEED_DEFAULT 3

struct Gblock{
    int num;
    char *content;
    int len;
    char *blank;
    int color;
} blocks[10];

const int LenOfGblock=5;
typedef struct Gblock Gblock;
int isInited = 0;
int isPlaying = 0;
int score = 0;
int HP = DEFAULT_HP;
int snowSpeed = SPEED_DEFAULT;


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
int moveSnow( object *snow, int speed, object user );
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
    if(1){
        struct Gblock tmp = { BLOCK_PERSON, "P", 1, " ", COLOR_PERSON};
        blocks[BLOCK_PERSON]=tmp;
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
            char text2[50];
            printf("%s", text);
            Sleep(500);
            getoxy( CONSOLE_WIDTH/2-14, CONSOLE_HEIGHT/2 );
            for( int i=0; i<=strlen(text); i++) printf(" ");
            printf(" ");
            if( kbhit() ){
                getch();
                int speedM = SPEED_DEFAULT;
                Rect background={CONSOLE_WIDTH/2-25,CONSOLE_HEIGHT/2-10, CONSOLE_WIDTH/2+25,CONSOLE_HEIGHT/2+10 };
                Rect select = {CONSOLE_WIDTH/2-8, CONSOLE_HEIGHT/2-7, CONSOLE_WIDTH/2+8,CONSOLE_HEIGHT/2-7 };
                Rect opt1 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2-5, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2-5 };
                Rect opt2 = {CONSOLE_WIDTH/2-10, CONSOLE_HEIGHT/2-3, CONSOLE_WIDTH/2+10,CONSOLE_HEIGHT/2-3 };
                Rect opt3 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2-1, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2-1 };

                Rect mes1 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2+2, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2+2 };
                Rect mes2 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2+3, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2+3 };
                Rect mes3 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2+5, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2+5 };
                Rect mes4 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2+7, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2+7 };


                sprintf(text2,"선택한 속도 : %2d", speedM);
                drawUI("",background,COLOR_DEFAULT);
                drawUI("난이도 선택하기", select, COLOR_RED);
                drawUI("◀ 속도 조절 ▶ ", opt1, COLOR_DEFAULT);
                drawUI(text2, opt2, COLOR_DEFAULT);
                drawUI("Enter 키를 눌러 게임을 시작하세요", opt3, COLOR_DEFAULT);
                drawUI("▲", mes1, COLOR_KEYBOARD);
                drawUI("◀▼▶", mes2, COLOR_KEYBOARD);
                drawUI("# SPACE 키로 제설을 할 수 있습니다 #", mes3, COLOR_DEFAULT);
                drawUI("# 플레이어가 눈에 부딪히면 체력이 감소합니다 #", mes4, COLOR_DEFAULT);


                while( 1 ){
                    if(kbhit()){
                        char A = getch();

                        if( A==75 || A==80){ // <<
                            if( speedM >= 2)
                                speedM--;
                            sprintf(text2, "선택한 속도 : %2d", speedM);
                            drawUI(text2, opt2, COLOR_DEFAULT);
                        }
                        else if( A==77 || A==72){
                            if( speedM < 15 )
                                speedM++;
                            sprintf(text2, "선택한 속도 : %2d", speedM);
                            drawUI(text2, opt2, COLOR_DEFAULT);
                        }

                        else if( A=='\r'){
                            isPlaying = 1;
                            snowSpeed = speedM;
                            clearUI(select);
                            clearUI(opt1);
                            clearUI(opt2);
                            clearUI(opt3);
                            clearUI(background);
                            clearUI(mes1);
                            clearUI(mes2);
                            clearUI(mes3);
                            clearUI(mes4);
                            clearDisplay();
                            initMap();
                            Sleep(500);
                            return;
                        }


                    }
                }

                break;
            }

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
        isInited = 0;
        isPlaying = 0;
        score = 0;
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
            drawObj( i,j, blocks[map[i][j]].color,  blocks[map[i][j]].content);
            //printf("%1d", blocks[map[i][j]].num);
        }
    }
}

void setUI( Rect rect ){
    for( int i=rect.lbx; i<=rect.rtx; i++){
        drawObj(i , rect.lby, COLOR_BGUI, " ");
        map[i][rect.lby] = BLOCK_UI;
    }
}

void drawUI( char message[30], Rect rect, int color ){
    int len = strlen(message);
    char *mes;

    drawRect(rect, BLOCK_UI);
    for( int i=rect.lbx; i<=rect.rtx; i++){
        for( int j=rect.lby; j<=rect.rty; j++){
            drawObj( i, j, COLOR_BGUI, " ");
        }
    }
    //if( rect.rtx - rect.lbx > len ){
    drawObj( (rect.lbx+rect.rtx)/2-len/2+len%2 , (rect.lby+rect.rty)/2, COLOR_BGUI, message);
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

void drawObj( int x, int y, int color, char content[10]){
    getoxy( x , y );
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    printf("%s", content);
}

int Move(object *user, char dir){ //방향 통해 움직이기 -> 임시
    switch( dir ){
case 'A':case 'a':
    case 75 : //move LEFT
        user->player.content = "<";
        if(  user->x - user->player.len < 0 ) {//MAP밖
            if( map[CONSOLE_WIDTH-1][user->y] == BLOCK_BLANK ){ //충돌X
                drawObj( user->x , user->y, COLOR_DEFAULT, user->player.blank);

                map[user->x][user->y]=BLOCK_BLANK;

                drawObj( user->x = CONSOLE_WIDTH-1 , user->y, blocks[BLOCK_PLAYER].color, "<");

                map[user->x][user->y]=BLOCK_PLAYER;
            }
        }
        else if( map[user->x - user->player.len][user->y] == BLOCK_BLANK ){ //충돌X
            drawObj( user->x , user->y, COLOR_DEFAULT, user->player.blank);

            map[user->x][user->y]=BLOCK_BLANK;

            drawObj( user->x -= user->player.len , user->y, blocks[BLOCK_PLAYER].color, "<");

            map[user->x][user->y]=BLOCK_PLAYER;
        }
        else{
            drawObj( user->x , user->y, COLOR_PLAYER, user->player.content);
            map[user->x][user->y]=BLOCK_PLAYER;
        }

        break;
    case 72 : // move TOP
    case 'W':case 'w':
        if( map[user->x ][user->y-1] == BLOCK_BLANK ){
            drawObj( user->x , user->y, COLOR_DEFAULT, user->player.blank);

            map[user->x][user->y]=BLOCK_BLANK;

            drawObj( user->x , user->y-=1, blocks[BLOCK_PLAYER].color, user->player.content);

            map[user->x][user->y]=BLOCK_PLAYER;
        }
        break;
    case 80 : // move BOTTOM
    case 's':case 'S':

        if( user->y + 1 >= CONSOLE_HEIGHT ) break;
        else if( map[user->x][user->y+1] == BLOCK_BLANK && user->y+1 < CONSOLE_HEIGHT ){
            drawObj( user->x , user->y, COLOR_DEFAULT, user->player.blank);

            map[user->x][user->y]=BLOCK_BLANK;

            drawObj( user->x , user->y+=1, blocks[BLOCK_PLAYER].color, user->player.content);

            map[user->x][user->y]=BLOCK_PLAYER;
        }

        break;
    case 77 : //move Right
    case 'D':case 'd':
        user->player.content = ">";
        if( user->x + user->player.len >= (CONSOLE_WIDTH)  ){//MAP밖
            if( map[0][user->y] == BLOCK_BLANK ){ //충돌X
                drawObj( user->x , user->y, COLOR_DEFAULT, user->player.blank);

                map[user->x][user->y]=BLOCK_BLANK;

                drawObj( user->x = 0 , user->y, blocks[BLOCK_PLAYER].color, ">");

                map[user->x][user->y]=BLOCK_PLAYER;
            }
        }
        else if( map[user->x + user->player.len ][user->y] == BLOCK_BLANK ){ //충돌X

            drawObj( user->x , user->y, COLOR_DEFAULT, user->player.blank);

            map[user->x][user->y]=BLOCK_BLANK;

            drawObj( user->x += user->player.len , user->y, blocks[BLOCK_PLAYER].color, ">");

            map[user->x][user->y]=BLOCK_PLAYER;
        }
        else{
            drawObj( user->x , user->y, COLOR_PLAYER, user->player.content);
            map[user->x][user->y]=BLOCK_PLAYER;
        }
        break;
    case ' ': // 제설제설
         if( user->x == CONSOLE_WIDTH-1 ){
            if( strcmp(user->player.content,">")==0 ){
                if( map[0][user->y] == BLOCK_ACTIVE_SNOW ){
                    map[ 0 ][user->y] = BLOCK_BLANK;
                    drawObj( 0 , user->y, COLOR_DEFAULT, user->player.blank);
                    addScore();
                    for( int i=PLAYER_USER_MIN_Y; i<=user->y; i++){
                        if( map[0][i] == BLOCK_ACTIVE_SNOW ){
                            map[0][i] = BLOCK_BLANK;
                            drawObj( 0 , i, COLOR_DEFAULT, blocks[BLOCK_BLANK].content );
                            map[0][user->y] = BLOCK_ACTIVE_SNOW;
                            drawObj( 0 , user->y, COLOR_ACTIVESNOW, blocks[BLOCK_ACTIVE_SNOW].content );
                            break;
                        }
                    }
                }
            }
         }
        else if( strcmp(user->player.content,">")==0 ){
            if( map[user->x +1 ][user->y] == BLOCK_ACTIVE_SNOW ){
                map[user->x +1 ][user->y] = BLOCK_BLANK;
                drawObj( user->x +1 , user->y, COLOR_DEFAULT, user->player.blank);
                map[user->x][user->y]=BLOCK_BLANK;
                addScore();
                for( int i=PLAYER_USER_MIN_Y; i<=user->y; i++){
                    if( map[user->x+1][i] == BLOCK_ACTIVE_SNOW ){
                        map[user->x+1][i] = BLOCK_BLANK;
                        drawObj( user->x+1 , i, COLOR_DEFAULT, blocks[BLOCK_BLANK].content );
                        map[user->x+1][user->y] = BLOCK_ACTIVE_SNOW;
                        drawObj( user->x+1 , user->y, COLOR_ACTIVESNOW, blocks[BLOCK_ACTIVE_SNOW].content );
                        break;
                    }
                }
            }
        }// RIGHT
        if( user->x == 0 ){
            if( strcmp(user->player.content,"<")==0 ){
                if( map[CONSOLE_WIDTH-1 ][user->y] == BLOCK_ACTIVE_SNOW ){
                    map[CONSOLE_WIDTH-1 ][user->y] = BLOCK_BLANK;
                    drawObj( CONSOLE_WIDTH-1 , user->y, COLOR_DEFAULT, user->player.blank);
                    map[CONSOLE_WIDTH-1][user->y]=BLOCK_BLANK;
                    addScore();
                    for( int i=PLAYER_USER_MIN_Y; i<=user->y; i++){
                        if( map[CONSOLE_WIDTH-1][i] == BLOCK_ACTIVE_SNOW ){
                            map[CONSOLE_WIDTH-1][i] = BLOCK_BLANK;
                            drawObj( CONSOLE_WIDTH-1 , i, COLOR_DEFAULT, blocks[BLOCK_BLANK].content );
                            map[CONSOLE_WIDTH-1][user->y] = BLOCK_ACTIVE_SNOW;
                            drawObj( CONSOLE_WIDTH-1 , user->y, COLOR_ACTIVESNOW, blocks[BLOCK_ACTIVE_SNOW].content );
                            break;
                        }
                    }
                }
            }
        }
        else if( map[user->x -1 ][user->y] == BLOCK_ACTIVE_SNOW ){
            map[user->x -1 ][user->y] = BLOCK_BLANK;
            drawObj( user->x -1 , user->y, COLOR_DEFAULT, user->player.blank);
            map[user->x-1][user->y]=BLOCK_BLANK;
            addScore();
            for( int i=PLAYER_USER_MIN_Y; i<=user->y; i++){
                if( map[user->x-1][i] == BLOCK_ACTIVE_SNOW ){
                    map[user->x-1][i] = BLOCK_BLANK;
                    drawObj( user->x-1 , i, COLOR_DEFAULT, blocks[BLOCK_BLANK].content );
                    map[user->x-1][user->y] = BLOCK_ACTIVE_SNOW;
                    drawObj( user->x-1 , user->y, COLOR_ACTIVESNOW, blocks[BLOCK_ACTIVE_SNOW].content );
                    break;
                }
            }
        }// LEFT
        break;

    default:
        drawObj( user->x , user->y, blocks[BLOCK_PLAYER].color, user->player.content);
        map[user->x][user->y]=BLOCK_PLAYER;
    }

    return 0;
}

void addScore(){
    score+=(int)sqrt((double)snowSpeed+1)*2;
}

void drawRect( Rect rect, const int block ){//맵에 도형 그리기
    int cnt=0;
    for( int i=rect.lbx; i<=rect.rtx; i++){
        for( int j=rect.lby; j<=rect.rty; j++ ){
            if( i > CONSOLE_WIDTH || i<0 || j<0 || j>CONSOLE_HEIGHT ) continue;
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

    Rect rect = {0, PLAYER_USER_MIN_Y-1, CONSOLE_WIDTH-1, PLAYER_USER_MIN_Y-1};
    drawRect( rect, BLOCK_DEFAULT );
    //Rect rect2 = {10, 2, 30, 5};
    //drawUI( rect2, "HELLO");

}

void setColor( int color ){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//제설하기 게임

// 쓰레드 함수

int moveSnow( object *snow, int speed, object user ){
    if( snow->y + speed < PLAYER_USER_MIN_Y-1 ){ //내릴 때
        if( map[snow->x][snow->y] != BLOCK_UI ){
            drawObj( snow->x , snow->y, COLOR_DEFAULT, blocks[BLOCK_BLANK].content);
            map[snow->x][snow->y] = BLOCK_BLANK;
        }
        if( map[snow->x][snow->y+speed] != BLOCK_UI ){
            drawObj( snow->x , snow->y += speed , COLOR_SNOW, blocks[BLOCK_SNOW].content);
            map[snow->x][snow->y] = BLOCK_SNOW;
        }else snow->y += speed;
    }else{ //아래에 부딪힘
        for( int i=CONSOLE_HEIGHT-1; i>=PLAYER_USER_MIN_Y; i-- ){
            /*
            if( snow->x == user.x && i==user.y ){
                continue;
            }
            */
            if( map[snow->x][i] == BLOCK_PLAYER ) {
                Sleep(100);
                continue;//스턴
            }


            if( map[snow->x][i] == BLOCK_BLANK ){
                drawObj( snow->x , snow->y, COLOR_DEFAULT, blocks[BLOCK_BLANK].content);
                map[snow->x][snow->y] = BLOCK_BLANK;
                drawObj( snow->x , i, COLOR_ACTIVESNOW, blocks[BLOCK_ACTIVE_SNOW].content);
                map[snow->x][i] = BLOCK_ACTIVE_SNOW;
                snow->y = 0;
                break;
            }
            if( map[snow->x][i] == BLOCK_PERSON ){
                //게임 오버
                return -1;
            }

        }
    }
    return 0;
}

int movePerson( object *person){
    if( person->x == 0 ){
        if( map[CONSOLE_WIDTH-1][person->y] == BLOCK_BLANK ){
            drawObj(person->x, person->y, COLOR_DEFAULT, blocks[BLOCK_BLANK].content );
            map[person->x][person->y] = BLOCK_BLANK;
            drawObj(person->x = CONSOLE_WIDTH-1, person->y, COLOR_PERSON, blocks[BLOCK_PERSON].content );
            map[person->x][person->y] = BLOCK_PERSON;
        }else if( map[CONSOLE_WIDTH-1][person->y] == BLOCK_ACTIVE_SNOW ){ // 게임오버
            HP--;
            if( HP>0 ){
                return 0;
            }else{
                return -1;
            }

        }
    }
    else if( map[person->x-1][person->y] == BLOCK_BLANK ){
        drawObj(person->x, person->y, COLOR_DEFAULT, blocks[BLOCK_BLANK].content );
        map[person->x][person->y] = BLOCK_BLANK;
        drawObj(person->x -=1 , person->y, COLOR_PERSON, blocks[BLOCK_PERSON].content );
        map[person->x][person->y] = BLOCK_PERSON;
    }else if( map[person->x-1][person->y] == BLOCK_ACTIVE_SNOW ){
        return -1;
    }

    return 0;
}

void clearDisplay(){
    for( int i=0; i<CONSOLE_WIDTH; i++){
        for( int j=0; j<CONSOLE_HEIGHT; j++){
            drawObj(i,j, COLOR_DEFAULT, blocks[BLOCK_BLANK].content);
        }
    }
}

void clearMap(){
    Rect eraseMap = {0, 0, CONSOLE_WIDTH-1, CONSOLE_HEIGHT-1};
    drawRect(eraseMap, BLOCK_BLANK);
}

void clearUI( Rect uir){
    for( int i=uir.lbx; i<=uir.rtx; i++){
        for( int j=uir.lby; j<=uir.rty; j++){
            if( map[i][j]==BLOCK_UI ) {
                map[i][j]=BLOCK_BLANK;
                drawObj(i,j, COLOR_DEFAULT, blocks[BLOCK_BLANK].content);
            }
        }
    }
}

void closeScene(){
    clearDisplay();
    clearMap();
    char message[20];
    int a=2;
    Rect ScoreUi = {CONSOLE_WIDTH/2-4, CONSOLE_HEIGHT/2-5, CONSOLE_WIDTH/2+4, CONSOLE_HEIGHT/2-5};
    Rect backgroundUi = {CONSOLE_WIDTH/2-10, CONSOLE_HEIGHT/2-10, CONSOLE_WIDTH/2+10, CONSOLE_HEIGHT/2+10};
    Rect endUi = { CONSOLE_WIDTH/2-5, CONSOLE_HEIGHT/2, CONSOLE_WIDTH/2+5, CONSOLE_HEIGHT/2};
    drawUI( " ", backgroundUi, COLOR_DEFAULT);
    sprintf(message,"점수: %5d",score);
    drawUI( message, ScoreUi, COLOR_UI);
    drawUI( "GAMEOVER" ,COLOR_BGUI, endUi);
    while( 1 ){
        drawUI( "GAMEOVER" ,COLOR_BGUI, endUi);
        Sleep(800);
        clearUI(endUi);
        Sleep(300);
        if( kbhit() ){
            a--;
        }
        if( a==0){
            getch();
            break;
        }
    }
    clearUI( ScoreUi );
    clearUI(backgroundUi);
    clearDisplay();

    Sleep(2000);
    isPlaying=0;
}

int main()
{
    Gblock player_ = {BLOCK_PLAYER,">",1," ",COLOR_PLAYER};
    object user={CONSOLE_WIDTH/2-1, (PLAYER_USER_MIN_Y+CONSOLE_HEIGHT)/2, player_ };
    Gblock snow = {BLOCK_SNOW, "*",1," ", COLOR_SNOW};
    Gblock snow_block = {BLOCK_SNOW, "*", 1, " ", COLOR_SNOW};
    Gblock person_block = {BLOCK_PERSON, "P", 1, " ", COLOR_PERSON};
    object person = {CONSOLE_WIDTH/2-1, PLAYER_USER_MIN_Y, person_block  };
    object snows[CONSOLE_WIDTH]; //{ x, y, player: GBlock }
    srand(time(NULL));
    int c=0;

    //Gblock camera_ = {1, "", 1, "", 0x00 };
    //object camera = {CONSOLE_WIDTH/2, CONSOLE_HEIGHT/2, camera_};
    Rect XYui = { 0, 2, 20, 2};
    Rect ScoreUi = {0, 1, 20, 1};
    Rect SpeedUi = {0, 0, 20, 0};
    Rect HPUi = { 0,3, 20, 3};

    char ch, message[30];
    initalize();

    drawMap();
    drawObj( user.x , user.y, blocks[BLOCK_PLAYER].color, user.player.content);
    drawObj( person.x , person.y, blocks[BLOCK_PERSON].color, person.player.content);

    sprintf(message,"x: %2d, y: %2d",user.x, user.y);
    drawUI( message, XYui, COLOR_UI);
    sprintf(message,"점수: %7d",score);
    drawUI( message, ScoreUi, COLOR_UI);
    sprintf(message,"속도: %2d",snowSpeed);
    drawUI( message, SpeedUi, COLOR_UI);
    sprintf(message,"체력: %2d",HP);
    drawUI( message, HPUi, COLOR_UI);

    //INIT snow
    for( int i=0; i<CONSOLE_WIDTH; i++ ){
        snows[i].x = i;
        snows[i].y = 0;
        snows[i].player = snow_block;
    }

    //Swap -> Random
    for( int i=0; i<CONSOLE_WIDTH; i++ ){
        int j = rand()%CONSOLE_WIDTH;
        object tmpsnow;
        tmpsnow = snows[ j ];
        snows[j] = snows[ i ];
        snows[i] = tmpsnow;
    }

    isInited=1;

        while( isPlaying ){

        for( int i=0; i<snowSpeed; i++, c++){

            if( moveSnow(&snows[c%CONSOLE_WIDTH], rand() %((int)sqrt((double)snowSpeed)+2), user) == -1 ){
                //게임 오버
                closeScene();
                return main();
            }
            Sleep(10/snowSpeed+1);

        }

        if( kbhit() ){
            ch = getch();
            Move(&user, ch);


            sprintf(message,"x: %2d, y: %2d",user.x, user.y);
            drawUI( message, XYui, COLOR_UI);
            sprintf(message,"점수: %7d",score);
            drawUI( message, ScoreUi, COLOR_UI);
            sprintf(message,"속도: %2d",snowSpeed);
            drawUI( message, SpeedUi, COLOR_UI);
            sprintf(message,"체력: %2d",HP);
            drawUI( message, HPUi, COLOR_UI);

        }
        if( rand() % (15/snowSpeed+1) == 0 ){
            if( movePerson(&person) == -1 ) // 게임 오버
            {
                closeScene();
                return main();
            }
        }
    }
    getchar();
    return 0;
}
