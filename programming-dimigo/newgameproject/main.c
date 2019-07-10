#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

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
#define BLOCK_ITEM_LINE 8
#define BLOCK_ITEM_DECREASE 9
#define BLOCK_ITEM_BLOCK 11
#define BLOCK_ITEM_HEALTHUP 10

#define COLOR_SNOW 0x0B
#define COLOR_DEFAULT 0x07
#define COLOR_PLAYER 0x0C
#define COLOR_UI 0x06
#define COLOR_ACTIVESNOW 0x03
#define COLOR_PERSON 0x0c
#define COLOR_BGUI 0x60
#define COLOR_RED 0x0C
#define COLOR_KEYBOARD 0x80
#define COLOR_ITEM_LINE 0x0B
#define COLOR_ITEM_DECREASE 0x09
#define COLOR_ITEM_BLOCK 0x09
#define COLOR_ITEM_HEALTHUP 0x06

#define ITEM_RANDOM_DROP 60
#define DEFAULT_HP 5
#define SPEED_DEFAULT 3
#define STUN_DELAY 400
#define SCORE_UP 100
#define ITEM_MAX_COUNT 7

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
double time1;
int item_count = 0;
int HP = DEFAULT_HP;
int snowSpeed = SPEED_DEFAULT;
int first_speed = SPEED_DEFAULT;


int map[CONSOLE_WIDTH][CONSOLE_HEIGHT];
// 0: ����
// 1: block
// 2: Out of Map
// 3+.. -> Another

struct Rect {
    int lbx;
    int lby;
    int rtx;
    int rty;
}; // �簢�� ��� ����
typedef struct Rect Rect;
struct Circle {
    int x;
    int y;
    int radius;
};
typedef struct Circle Circle;
struct Obj{
    int x;
    int y;
    Gblock player;
}; //Sprite ����
typedef struct Obj object;

void drawRect2( Rect rect, const int block );
void drawRect( Rect rect, const int block );
void eraseRect( Rect rect );
void initMap();
int moveSnow( object *snow, int speed, object user );
void drawUI( char *message, Rect rect , int color);
//������Ÿ�� ����

void initBlock(){ //BLOCK ���� �����ϱ�
    int i=0;
    if(1){
        struct Gblock tmp = { BLOCK_BLANK, " ", 1, " ", COLOR_DEFAULT };
        blocks[BLOCK_BLANK]=tmp;
    } // ����: �� ��
    if(1){
        struct Gblock tmp = { BLOCK_SNOW, "*", 1, " ", COLOR_DEFAULT};
        blocks[BLOCK_SNOW]=tmp;
    } // * : SNOW
    if(1){
        struct Gblock tmp = { BLOCK_ACTIVE_SNOW, "*", 1, " ", COLOR_SNOW};
        blocks[BLOCK_ACTIVE_SNOW]=tmp;
    } // * : �� 1
    if(1){
        struct Gblock tmp = { BLOCK_DEFAULT, "=", 1, " ", COLOR_DEFAULT};
        blocks[BLOCK_DEFAULT]=tmp;
    }

    if(1){
        struct Gblock tmp = { BLOCK_PLAYER, ">", 1, " ", COLOR_PLAYER};
        blocks[BLOCK_PLAYER]=tmp;
    }
    if(1){
        struct Gblock tmp = { BLOCK_PERSON, "P", 1, " ", COLOR_PERSON};
        blocks[BLOCK_PERSON]=tmp;
    }
    if(1){
        struct Gblock tmp = { BLOCK_ITEM_LINE, "Q", 1, " ", COLOR_ITEM_LINE};
        blocks[BLOCK_ITEM_LINE]=tmp;
    }
    if(1){
        struct Gblock tmp = { BLOCK_ITEM_DECREASE, "-", 1, " ", COLOR_ITEM_DECREASE};
        blocks[BLOCK_ITEM_DECREASE]=tmp;
    }
    if(1){
        struct Gblock tmp = { BLOCK_ITEM_BLOCK, "X", 1, " ", COLOR_ITEM_BLOCK};
        blocks[BLOCK_ITEM_BLOCK]=tmp;
    }
    if(1){
        struct Gblock tmp = { BLOCK_ITEM_HEALTHUP, "H", 1, " ", COLOR_ITEM_HEALTHUP};
        blocks[BLOCK_ITEM_HEALTHUP]=tmp;
    }
    //UI
} // �� �ʱ�ȭ �ϱ� : Player �� ��

void getoxy( int x, int y) { //��ǥ �����ϱ�
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void resizeConsole(){ // �ܼ� ũ�� �����ϱ�
    char A[100];
    sprintf(A, "Mode con cols=%d lines=%d", CONSOLE_WIDTH, CONSOLE_HEIGHT);
    system(A);
}

void initCursor(){ // Ŀ�� �ʱ�ȭ �ϱ�
        CONSOLE_CURSOR_INFO info = {0};
        info.dwSize = 1;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    } //
void initalize(){ // �ʱ�ȭ�ϱ�
        srand(time(NULL));
        system("title ���� ���� ����");
        isInited = 0;
        isPlaying = 0;
        score = 0;
        item_count = 0;
        HP = DEFAULT_HP;
        resizeConsole();
        initCursor();
        initBlock();
        initMap();
        displayStart();
        time1 = (double)clock() / CLOCKS_PER_SEC;
    }
void displayStart(){ // ���� �����ϱ�
    Rect bgrect = {CONSOLE_WIDTH/2-20, CONSOLE_HEIGHT/2-8, CONSOLE_WIDTH/2+20, CONSOLE_HEIGHT/2+9};
    Rect title = {CONSOLE_WIDTH/2-15, CONSOLE_HEIGHT/2-4, CONSOLE_WIDTH/2+15, CONSOLE_HEIGHT/2-4};
    Rect comment = {CONSOLE_WIDTH/2-15, CONSOLE_HEIGHT/2-1, CONSOLE_WIDTH/2+15, CONSOLE_HEIGHT/2-1};
    Rect comment2 = {CONSOLE_WIDTH/2-15, CONSOLE_HEIGHT/2+1, CONSOLE_WIDTH/2+15, CONSOLE_HEIGHT/2+1};
    Rect comment3 = {CONSOLE_WIDTH/2-15, CONSOLE_HEIGHT/2+3, CONSOLE_WIDTH/2+15, CONSOLE_HEIGHT/2+3};
    Rect comment4 = {CONSOLE_WIDTH/2-15, CONSOLE_HEIGHT/2+5, CONSOLE_WIDTH/2+15, CONSOLE_HEIGHT/2+5};
    drawUI("",bgrect,COLOR_BGUI);
    drawUI("�������� ���� �������ּ���",comment,COLOR_DEFAULT);
    drawUI("������ Q�� ���� �������ݴϴ�",comment2,COLOR_DEFAULT);
    drawUI("������ X�� ��ó�� �������ݴϴ�",comment3,COLOR_DEFAULT);
    drawUI("������ H�� ü���� ȸ����ŵ�ϴ�",comment4,COLOR_DEFAULT);
    //�ȳ����� ���
    while( 1 ){

        char text2[50];
        Sleep(100);
        drawUI("�����Ϸ��� �ƹ�Ű�� ��������!",title,COLOR_DEFAULT);
        Sleep(500);
        drawUI("",title,COLOR_DEFAULT);//�����

        if( kbhit() ){
            getch();
            clearUI(bgrect);
            clearUI(comment);
            clearUI(comment2);
            clearUI(comment3);
            clearUI(comment4);
            // UI �ʱ�ȭ,
            int speedM = SPEED_DEFAULT;
            Rect background={CONSOLE_WIDTH/2-25,CONSOLE_HEIGHT/2-10, CONSOLE_WIDTH/2+25,CONSOLE_HEIGHT/2+10 };
            Rect select = {CONSOLE_WIDTH/2-11, CONSOLE_HEIGHT/2-7, CONSOLE_WIDTH/2+8,CONSOLE_HEIGHT/2-7 };
            Rect opt1 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2-5, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2-5 };
            Rect opt2 = {CONSOLE_WIDTH/2-10, CONSOLE_HEIGHT/2-3, CONSOLE_WIDTH/2+10,CONSOLE_HEIGHT/2-3 };
            Rect opt3 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2-1, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2-1 };

            Rect mes1 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2+2, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2+2 };
            Rect mes2 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2+3, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2+3 };
            Rect mes3 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2+5, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2+5 };
            Rect mes4 = {CONSOLE_WIDTH/2-18, CONSOLE_HEIGHT/2+7, CONSOLE_WIDTH/2+18,CONSOLE_HEIGHT/2+7 };


            sprintf(text2,"������ �ӵ� : %2d", speedM);
            drawUI("",background,COLOR_DEFAULT);
            drawUI("���̵� �����ϱ�", select, COLOR_RED);
            drawUI("�� �ӵ� ���� �� ", opt1, COLOR_DEFAULT);
            drawUI(text2, opt2, COLOR_DEFAULT);
            drawUI("Enter Ű�� ���� ������ �����ϼ���", opt3, COLOR_DEFAULT);
            drawUI("��", mes1, COLOR_KEYBOARD);
            drawUI("���墺", mes2, COLOR_KEYBOARD);
            drawUI("# SPACE Ű�� ������ �� �� �ֽ��ϴ� #", mes3, COLOR_DEFAULT);
            drawUI("# �÷��̾ ���� �ε����� ü���� �����մϴ� #", mes4, COLOR_DEFAULT);


            while( 1 ){
                if(kbhit()){
                    char A = getch();

                    if( A==75 || A==80){ // <<
                        if( speedM >= 2)
                            speedM--;
                        sprintf(text2, "������ �ӵ� : %2d", speedM);
                        drawUI(text2, opt2, COLOR_DEFAULT);
                    }
                    else if( A==77 || A==72){
                        if( speedM < 15 )
                            speedM++;
                        sprintf(text2, "������ �ӵ� : %2d", speedM);
                        drawUI(text2, opt2, COLOR_DEFAULT);
                    }

                    else if( A=='\r'){
                        isPlaying = 1;
                        snowSpeed = speedM;
                        first_speed = speedM;
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
                        //�ʱ�ȭ�ϱ�
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

void drawMap(){ //MAP�� ������ ���� �׸���
    for( int j=0; j<CONSOLE_HEIGHT; j++){
        for( int i=0; i<CONSOLE_WIDTH; i+=1){//(blocks[map[i][j]].len>0?blocks[map[i][j]].len:1)
            if( map[i][j] == BLOCK_UI ) continue;
            drawObj( i,j, blocks[map[i][j]].color,  blocks[map[i][j]].content);
            //printf("%1d", blocks[map[i][j]].num);
        }
    }
}

void setUI( Rect rect ){ // UI�� BLANK�� ä��� BLOCK �����ϱ�
    for( int i=rect.lbx; i<=rect.rtx; i++){
        drawObj(i , rect.lby, COLOR_BGUI, " ");
        map[i][rect.lby] = BLOCK_UI;
    }
}

void drawUI( char message[30], Rect rect, int color ){ //UI �׸���
    int len = strlen(message);
    char *mes;

    drawRect(rect, BLOCK_UI);
    for( int i=rect.lbx; i<=rect.rtx; i++){
        for( int j=rect.lby; j<=rect.rty; j++){
            drawObj( i, j, COLOR_BGUI, " ");
        }
    }

    drawObj( (rect.lbx+rect.rtx)/2-len/2+len%2 , (rect.lby+rect.rty)/2, COLOR_BGUI, message);
    /*}
    else{
        for( int i=(rect.lbx+rect.rtx)/2-len/2 , c=0 ; i<(rect.lbx+rect.rtx)/2+len/2; i++, c++){
            getoxy( i , (rect.lby+rect.rty)/2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            printf("%c", message[c]);
        }
    }*/

} ////����dd
void drawObj( int x, int y, int color, char content[30]){ //�ش� ��ǥ�� �׸���
    getoxy( x , y );
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    printf("%s", content);
}

int Move(object *user, char dir){ //����� �Է� �޾Ƽ� ó��
    switch( dir ){
case 'A':case 'a':
    case 75 : //move LEFT
        user->player.content = "<";
        if(  user->x - user->player.len < 0 ) {//MAP��
            if( map[CONSOLE_WIDTH-1][user->y] == BLOCK_BLANK ){ //�浹X
                drawObj( user->x , user->y, COLOR_DEFAULT, user->player.blank);

                map[user->x][user->y]=BLOCK_BLANK;

                drawObj( user->x = CONSOLE_WIDTH-1 , user->y, blocks[BLOCK_PLAYER].color, "<");

                map[user->x][user->y]=BLOCK_PLAYER;
            }

        }
        else if( map[user->x - user->player.len][user->y] == BLOCK_BLANK ){ //�浹X
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
        if( user->x + user->player.len >= (CONSOLE_WIDTH)  ){//MAP��
            if( map[0][user->y] == BLOCK_BLANK ){ //�浹X
                drawObj( user->x , user->y, COLOR_DEFAULT, user->player.blank);

                map[user->x][user->y]=BLOCK_BLANK;

                drawObj( user->x = 0 , user->y, blocks[BLOCK_PLAYER].color, ">");

                map[user->x][user->y]=BLOCK_PLAYER;
            }
        }
        else if( map[user->x + user->player.len ][user->y] == BLOCK_BLANK ){ //�浹X

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
    case ' ': // ��������
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
                else
                    usingItems(0,user->y);
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
            else
                usingItems(user->x+1,user->y);
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
                else{
                    usingItems(CONSOLE_WIDTH-1, user->y);
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
        else
            usingItems(user->x-1, user->y);
        break;

    default:
        drawObj( user->x , user->y, blocks[BLOCK_PLAYER].color, user->player.content);
        map[user->x][user->y]=BLOCK_PLAYER;
    }

    return 0;
}

void gamePause(){ //���� �����ϱ�
    isPlaying = 0; // �Ͻ� ����
    while(1){
        if( kbhit() ){
            char A = getch();
           if( A == '\r' || A == ' ' ){ // ���ͳ� �����̽� Ű�� ���� �簳
               Sleep(STUN_DELAY);
               isPlaying = 1;
               break;
           }
        }
    }
}

void addScore(){ //���� ����
    if( score%SCORE_UP == 0 && score > 0 ){ //STAGE UP
        Rect bgUi = {CONSOLE_WIDTH/2-8, CONSOLE_HEIGHT/2-3, CONSOLE_WIDTH/2+8, CONSOLE_HEIGHT/2+3};
        Rect tmpUi = { CONSOLE_WIDTH/2-4, CONSOLE_HEIGHT/2, CONSOLE_WIDTH/2+6,CONSOLE_HEIGHT/2};
        drawUI(" ", bgUi, COLOR_BGUI );
        snowSpeed++; // �ӵ� ����
        char message[30];
        sprintf(message,"STAGE %d�ܰ�", snowSpeed-first_speed+1);
        drawUI(message,tmpUi, COLOR_UI );
        gamePause();
        clearUI(bgUi);
        clearUI(tmpUi);
    }
    score+=(int)sqrt((double)snowSpeed+1)*2;
}

void addScorebyCount( int count ) { // ���� ��� ���� ����
    int scoreB=score+(int)sqrt((double)snowSpeed+1)*2*count;
    if( scoreB/SCORE_UP > score/SCORE_UP ){
        Rect bgUi = {CONSOLE_WIDTH/2-8, CONSOLE_HEIGHT/2-3, CONSOLE_WIDTH/2+8, CONSOLE_HEIGHT/2+3};
        Rect tmpUi = { CONSOLE_WIDTH/2-3, CONSOLE_HEIGHT/2, CONSOLE_WIDTH/2+5,CONSOLE_HEIGHT/2};
        drawUI(" ", bgUi, COLOR_BGUI );
        snowSpeed+= scoreB/SCORE_UP - score/SCORE_UP; // �ӵ� ����
        char message[30];
        sprintf(message,"STAGE %d�ܰ�", snowSpeed-first_speed+1);
        drawUI(message,tmpUi, COLOR_UI );
        gamePause();
        clearUI(bgUi);
        clearUI(tmpUi);
    }
    score = scoreB;
}

void drawRect( Rect rect, const int block ){//�ʿ� ���� �׸���(MAP)
    int cnt=0;
    for( int i=rect.lbx; i<=rect.rtx; i++){
        for( int j=rect.lby; j<=rect.rty; j++ ){
            if( i > CONSOLE_WIDTH || i<0 || j<0 || j>CONSOLE_HEIGHT ) continue;
            map[i][j] = block ;
        }
    }
}
void eraseRect( Rect rect ){ //�� ���� �׸��� (MAP)
    drawRect( rect, 0 );
}
void drawRect2( Rect rect, const int block ){ //������ �� �簢�� �׸��� (MAP)
    drawRect( rect, block );
    rect.lbx +=1;
    rect.lby +=1;
    rect.rtx -=1;
    rect.rty -=1;
    eraseRect( rect );
}
void initMap(){ //Map�׸��� �� ����

    Rect rect = {0, PLAYER_USER_MIN_Y-1, CONSOLE_WIDTH-1, PLAYER_USER_MIN_Y-1};
    drawRect( rect, BLOCK_DEFAULT );
    //Rect rect2 = {10, 2, 30, 5};
    //drawUI( rect2, "HELLO");

}
void setColor( int color ){ //�� ����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int moveSnow( object *snow, int speed, object user ){ //�� �����̰� �ϱ�
    if( snow->y + speed < PLAYER_USER_MIN_Y-1 ){ //���� ��
        if( map[snow->x][snow->y] != BLOCK_UI ){
            drawObj( snow->x , snow->y, COLOR_DEFAULT, blocks[BLOCK_BLANK].content);
            map[snow->x][snow->y] = BLOCK_BLANK;
        }
        if( map[snow->x][snow->y+speed] != BLOCK_UI ){
            drawObj( snow->x , snow->y += speed , COLOR_SNOW, blocks[BLOCK_SNOW].content);
            map[snow->x][snow->y] = BLOCK_SNOW;
        }else snow->y += speed;
    }else{ //�Ʒ��� �ε���
        for( int i=CONSOLE_HEIGHT-1; i>=PLAYER_USER_MIN_Y; i-- ){ //�Ʒ����� ���� ���� ���� �״´�
            /*
            if( snow->x == user.x && i==user.y ){
                continue;
            }
            */
            if( map[snow->x][i] == BLOCK_PLAYER ) { //�÷��̾�� �ε����� ���
                /*
                HP--;
                if( HP <= 0) return -1;
                else { // ü�� ���� : �ε���
                    HPdec();
                    return 3;
                }
                */
            }


            if( map[snow->x][i] == BLOCK_BLANK ){ // �� ���̸� ä��� ���� ���� ����
                drawObj( snow->x , snow->y, COLOR_DEFAULT, blocks[BLOCK_BLANK].content);
                map[snow->x][snow->y] = BLOCK_BLANK;
                drawObj( snow->x , i, COLOR_ACTIVESNOW, blocks[BLOCK_ACTIVE_SNOW].content);
                map[snow->x][i] = BLOCK_ACTIVE_SNOW;
                snow->y = 0;
                break;
            }
            if( map[snow->x][i] == BLOCK_PERSON ){ //����� �ε����� ���
                //���� ���� �ø�
                map[snow->x][snow->y] = BLOCK_BLANK;
                drawObj(snow->x, snow->y, COLOR_DEFAULT, blocks[BLOCK_SNOW].blank); //���� �� ����
                map[snow->x][snow->y=0] = BLOCK_SNOW;
                drawObj(snow->x, snow->y, COLOR_SNOW, blocks[BLOCK_SNOW].content); //���� �� ����
                HP--;
                if( HP <= 0) return -1;
                else { // ü�� ���� : �ε���
                    HPdec();
                    return 3;
                }
            }

        }
    }
    return 0;
}

void HPdec(){ // ü�� ���� �޽���
    Rect bgUi = {CONSOLE_WIDTH/2-12, CONSOLE_HEIGHT/2-7, CONSOLE_WIDTH/2+12, CONSOLE_HEIGHT/2-3};
    Rect tmpUi = { CONSOLE_WIDTH/2-7, CONSOLE_HEIGHT/2-5, CONSOLE_WIDTH/2+7,CONSOLE_HEIGHT/2-5};
    drawUI(" ", bgUi, COLOR_BGUI );
    char message[30];
    sprintf(message,"ü�� ����: %d", HP);
    drawUI(message,tmpUi, COLOR_UI );
    Sleep(STUN_DELAY);
    clearUI(bgUi);
    clearUI(tmpUi);
}

int movePerson( object *person){ // Moving Person
    if( person->x == 0 ){ // 0�� ������ ���������� �Ѿ�� ������
        if( map[CONSOLE_WIDTH-1][person->y] == BLOCK_BLANK ){
            if( map[person->x][person->y] == BLOCK_PERSON ){
                drawObj(person->x, person->y, COLOR_DEFAULT, blocks[BLOCK_BLANK].content );
                map[person->x][person->y] = BLOCK_BLANK;
            }
            drawObj(person->x = CONSOLE_WIDTH-1, person->y, COLOR_PERSON, blocks[BLOCK_PERSON].content );
            map[person->x][person->y] = BLOCK_PERSON;
        }else if( map[CONSOLE_WIDTH-1][person->y] == BLOCK_ACTIVE_SNOW ){ // ���� �ε��� ��
            // ���� ���ְ� ü���� ���ҽ�Ų��
            map[CONSOLE_WIDTH-1][person->y] = BLOCK_BLANK;
            drawObj(CONSOLE_WIDTH-1, person->y, COLOR_DEFAULT, blocks[BLOCK_ACTIVE_SNOW].blank);
            HP--;
            if( HP>0 ){ // ü�� ���� �޽���
                HPdec();
                return 3;
            }else{
                return -1;
            }
        }
        else{ //������ ���� ���� ��� �ǳ� �ڴ�
            drawObj(person->x, person->y, COLOR_DEFAULT, blocks[BLOCK_BLANK].content );
            map[person->x][person->y] = BLOCK_BLANK;
            person->x = CONSOLE_WIDTH - 1;
        }
    }
    else if( map[person->x-1][person->y] == BLOCK_BLANK ){ // ������ �� ���̸� �̵��ϱ�
        if( map[person->x][person->y] == BLOCK_PERSON ){
            drawObj(person->x, person->y, COLOR_DEFAULT, blocks[BLOCK_BLANK].content );
            map[person->x][person->y] = BLOCK_BLANK;
        }
        drawObj(person->x -=1 , person->y, COLOR_PERSON, blocks[BLOCK_PERSON].content );
        map[person->x][person->y] = BLOCK_PERSON;
    }
    else if( map[person->x-1][person->y] == BLOCK_ACTIVE_SNOW ){ // ������ ������ ���������� ü�� ����
        map[person->x-1][person->y] = BLOCK_BLANK;
        drawObj(person->x-1, person->y, COLOR_DEFAULT, blocks[BLOCK_ACTIVE_SNOW].blank);//��ġ���
        if( map[person->x][person->y] == BLOCK_PERSON ){
            drawObj(person->x, person->y, COLOR_DEFAULT, blocks[BLOCK_BLANK].content );
            map[person->x][person->y] = BLOCK_BLANK;
        }
        drawObj(person->x -=1 , person->y, COLOR_PERSON, blocks[BLOCK_PERSON].content );
        map[person->x][person->y] = BLOCK_PERSON; //�����̱�


        HP--;
        if( HP>0 ){ // ü�� ����
            HPdec();
            return 3;
        }
        else return -1;
    }
    else{ // ������ ������ ���� ���� ��� �ǳʶ�
        if( map[person->x][person->y] == BLOCK_PERSON ){
            drawObj(person->x, person->y, COLOR_DEFAULT, blocks[BLOCK_BLANK].content );
            map[person->x][person->y] = BLOCK_BLANK;
        }
        person->x -= 1;
    }

    return 0;
}

void clearDisplay(){ //CONSOLE clear
    for( int i=0; i<CONSOLE_WIDTH; i++){
        for( int j=0; j<CONSOLE_HEIGHT; j++){
            drawObj(i,j, COLOR_DEFAULT, blocks[BLOCK_BLANK].content);
        }
    }
}

void clearMap(){ //MAP�� �ʱ�ȭ�ϱ�
    Rect eraseMap = {0, 0, CONSOLE_WIDTH-1, CONSOLE_HEIGHT-1};
    drawRect(eraseMap, BLOCK_BLANK);
}

void clearUI( Rect uir){ //Ư�� UI�� ����� ( MAP & CONSOLE )
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
    Rect ScoreUi = {CONSOLE_WIDTH/2-10, CONSOLE_HEIGHT/2-2, CONSOLE_WIDTH/2+8, CONSOLE_HEIGHT/2-2};
    Rect backgroundUi = {CONSOLE_WIDTH/2-10, CONSOLE_HEIGHT/2-10, CONSOLE_WIDTH/2+10, CONSOLE_HEIGHT/2+10};
    Rect endUi = { CONSOLE_WIDTH/2-8, CONSOLE_HEIGHT/2+1, CONSOLE_WIDTH/2+7, CONSOLE_HEIGHT/2+1};
    drawUI( " ", backgroundUi, COLOR_DEFAULT);
    sprintf(message,"����: %5d",score);
    drawUI( message, ScoreUi, COLOR_UI);
    drawUI( "GAME OVER" ,endUi, COLOR_BGUI );
    while( 1 ){
        drawUI( "" , endUi, COLOR_BGUI);
        Sleep(100);
        drawUI( "GAME OVER" , endUi, COLOR_BGUI);
        Sleep(800);
        if( kbhit() ){
            getch();
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

int AAAAx, AAAAy;

void usingItemLine( int x, int y ){
    Rect bgui = { CONSOLE_WIDTH/2-10, CONSOLE_HEIGHT/2-3, CONSOLE_WIDTH/2+10, CONSOLE_HEIGHT/2+3 };
    Rect contentui = { CONSOLE_WIDTH/2-9, CONSOLE_HEIGHT/2, CONSOLE_WIDTH/2+9, CONSOLE_HEIGHT/2 };
    drawUI("",bgui,COLOR_BGUI);
    drawUI("ITEM : Remove Line",contentui,COLOR_UI);
    Sleep(100);
    int Ck=0;
    for( int k=0; k<CONSOLE_WIDTH; k++ ){
        if( map[k][y] == BLOCK_ACTIVE_SNOW ){
            map[k][y] = BLOCK_BLANK;
            drawObj(k,y,COLOR_DEFAULT,blocks[BLOCK_ACTIVE_SNOW].blank); //���� ä���� �ִ� ��� ���ش�.
            Ck++;
            for( int j=PLAYER_USER_MIN_Y; j<=y; j++ ){
                if( map[k][j]==BLOCK_ACTIVE_SNOW ){
                    map[k][y] = BLOCK_ACTIVE_SNOW; //�Ʒ��� ������ :
                    map[k][j] = BLOCK_BLANK; // �� ���� �ִ� �� ���ּ� ����
                    drawObj(k,j,COLOR_DEFAULT,blocks[BLOCK_ACTIVE_SNOW].blank);
                    drawObj(k,y,COLOR_ACTIVESNOW,blocks[BLOCK_ACTIVE_SNOW].content);
                    break;
                }
            }
        }
    }

    while(1){
        if(kbhit()){
            char usergetch = getch();
            if( usergetch == '\r' || usergetch == ' ') {
                //������ ���ֱ�
                map[x][y] = BLOCK_BLANK;
                drawObj(x,y,COLOR_DEFAULT,blocks[BLOCK_ITEM_LINE].blank);
                item_count--;
                break;
            }
        }
    }
    clearUI(bgui);
    clearUI(contentui);
    addScorebyCount(Ck);
}
void usingItemBlock( int x, int y){
    Rect bgui = { CONSOLE_WIDTH/2-10, CONSOLE_HEIGHT/2-3, CONSOLE_WIDTH/2+10, CONSOLE_HEIGHT/2+3 };
    Rect contentui = { CONSOLE_WIDTH/2-9, CONSOLE_HEIGHT/2, CONSOLE_WIDTH/2+9, CONSOLE_HEIGHT/2 };
    drawUI("",bgui,COLOR_BGUI);
    drawUI("ITEM : Remove 7*5",contentui,COLOR_UI);
    Sleep(100);
    int Ck=0;
    for( int k=(x-3)>=0?x-3:0; k<=((x+3)<CONSOLE_WIDTH?x+3:CONSOLE_WIDTH-1); k++ ){
        for( int ck=((y-2>=PLAYER_USER_MIN_Y?y-2:PLAYER_USER_MIN_Y)); ck<=((y+2<CONSOLE_HEIGHT?y+2:CONSOLE_HEIGHT-1)); ck++){
            if( map[k][ck] == BLOCK_ACTIVE_SNOW ){
                map[k][ck] = BLOCK_BLANK;
                drawObj(k,ck,COLOR_DEFAULT,blocks[BLOCK_ACTIVE_SNOW].blank); //���� ä���� �ִ� ��� ���ش�.
                Ck++;
                for( int j=PLAYER_USER_MIN_Y; j<=y; j++ ){
                    if( map[k][j]==BLOCK_ACTIVE_SNOW ){
                        map[k][ck] = BLOCK_ACTIVE_SNOW; //�Ʒ��� ������ :
                        map[k][j] = BLOCK_BLANK; // �� ���� �ִ� �� ���ּ� ����
                        drawObj(k,j,COLOR_DEFAULT,blocks[BLOCK_ACTIVE_SNOW].blank);
                        drawObj(k,ck,COLOR_ACTIVESNOW,blocks[BLOCK_ACTIVE_SNOW].content);
                        break;
                    }
                }
            }
        }
    }

    while(1){
        if(kbhit()){
            char usergetch = getch();
            if( usergetch == '\r' || usergetch == ' ') {
                //������ ���ֱ�
                map[x][y] = BLOCK_BLANK;
                drawObj(x,y,COLOR_DEFAULT,blocks[BLOCK_ITEM_BLOCK].blank);
                item_count--;
                break;
            }
        }
    }
    clearUI(bgui);
    clearUI(contentui);
    addScorebyCount(Ck);
}
void usingItemHPup( int x, int y ){
    Rect bgui = { CONSOLE_WIDTH/2-10, CONSOLE_HEIGHT/2-3, CONSOLE_WIDTH/2+10, CONSOLE_HEIGHT/2+3 };
    Rect contentui = { CONSOLE_WIDTH/2-9, CONSOLE_HEIGHT/2, CONSOLE_WIDTH/2+9, CONSOLE_HEIGHT/2 };
    drawUI("",bgui,COLOR_BGUI);
    char text[20];
    sprintf(text, "HP UP : %d + 5",HP);
    drawUI(text,contentui,COLOR_UI);
    HP+=5;
    Sleep(100);

    while(1){
        if(kbhit()){
            char usergetch = getch();
            if( usergetch == '\r' || usergetch == ' ') {
                //������ ���ֱ�
                map[x][y] = BLOCK_BLANK;
                drawObj(x,y,COLOR_DEFAULT,blocks[BLOCK_ITEM_HEALTHUP].blank);
                item_count--;
                break;
            }
        }
    }
    clearUI(bgui);
    clearUI(contentui);
}

void usingItems(int x, int y){
    switch(map[x][y]){
    case BLOCK_ITEM_LINE:
        if(0);
        usingItemLine(x,y);
        break;
    case BLOCK_ITEM_BLOCK:
        if(0);
        usingItemBlock(x,y);
        break;
    case BLOCK_ITEM_HEALTHUP:
        if(0);
        usingItemHPup(x,y);
        break;
    }
}


int main()
{
    //Sprite ����� ���� Block ����
    Gblock player_ = {BLOCK_PLAYER,">",1," ",COLOR_PLAYER};
    Gblock snow = {BLOCK_SNOW, "*",1," ", COLOR_SNOW};
    Gblock snow_block = {BLOCK_SNOW, "*", 1, " ", COLOR_SNOW};
    Gblock person_block = {BLOCK_PERSON, "P", 1, " ", COLOR_PERSON};
    Gblock ItemLine = { BLOCK_ITEM_LINE, "Q", 1, " ", COLOR_ITEM_LINE};
    Gblock ItemDecrease = { BLOCK_ITEM_DECREASE, "-", 1, " ", COLOR_ITEM_DECREASE};
    Gblock ItemBlock = { BLOCK_ITEM_BLOCK, "X", 1, " ", COLOR_ITEM_BLOCK};
    Gblock ItemHP = { BLOCK_ITEM_LINE, "H", 1, " ", COLOR_ITEM_HEALTHUP};

    //Sprite �ʱ�ȭ
    object user={CONSOLE_WIDTH/2-1, (PLAYER_USER_MIN_Y+CONSOLE_HEIGHT)/2, player_ };
    object person = {CONSOLE_WIDTH/2-1, PLAYER_USER_MIN_Y, person_block  };
    object snows[CONSOLE_WIDTH]; //{ x, y, player: GBlock }
    object item1 = {0,0,ItemLine}; //�Ŀ� ������ ��ǥ ����, ���� ��ǥ ���� ����
    object item2 = {0,0,ItemDecrease};
    object item3 = {0,0,ItemBlock};
    object item4 = {0,0,ItemHP};

    //Gblock camera_ = {1, "", 1, "", 0x00 };
    //object camera = {CONSOLE_WIDTH/2, CONSOLE_HEIGHT/2, camera_};
    Rect bgUI = { 1, 1, 21, 4 };
    Rect XYui = { 1, 3, 21, 3};
    Rect ScoreUi = {3, 2, 16, 2};
    Rect SpeedUi = {1, 1, 21, 1};
    Rect HPUi = { 1,4, 21, 4};

    PlaySound("music.wav", NULL, SND_ASYNC | SND_LOOP);

    int c, RX, RY;
    char ch, message[30];

    srand(time(NULL));
    initalize();

    drawMap();
    drawObj( user.x , user.y, blocks[BLOCK_PLAYER].color, user.player.content);
    drawObj( person.x , person.y, blocks[BLOCK_PERSON].color, person.player.content);
    map[person.x][person.y]=BLOCK_PERSON;
    map[user.x][user.y] = BLOCK_PLAYER;

    if(1){ // UI �ʱ�ȭ�ϱ�
        drawUI(" ", bgUI, COLOR_UI);
        int time = (int)(((double)clock()/CLOCKS_PER_SEC)-time1);
        sprintf(message,"�ð�: %02d:%02d", time/60, time%60);
        drawUI( message, XYui, COLOR_UI);
        sprintf(message,"����: %d",score);
        drawUI( message, ScoreUi, COLOR_UI);
        sprintf(message,"�ӵ�: %2d",snowSpeed);
        drawUI( message, SpeedUi, COLOR_UI);
        sprintf(message,"ü��: %2d",HP);
        drawUI( message, HPUi, COLOR_UI);
    }

    for( int i=0; i<CONSOLE_WIDTH; i++ ){//INIT snow
        snows[i].x = i;
        snows[i].y = 0;
        snows[i].player = snow_block;
    }

    for( int i=0; i<CONSOLE_WIDTH; i++ ){//Swap -> Random
        int j = rand()%CONSOLE_WIDTH;
        object tmpsnow;
        tmpsnow = snows[ j ];
        snows[j] = snows[ i ];
        snows[i] = tmpsnow;
    }

    isInited=1;

    while( 1 ){
        if( isPlaying ){
            int time = (int)(((double)clock()/CLOCKS_PER_SEC)-time1);
            sprintf(message,"�ð�: %02d:%02d", time/60, time%60);
            drawUI( message, XYui, COLOR_UI);
            for( int i=0; i<snowSpeed; i++, c++){ // �� ������ �ϴ� �ڵ�
                int anff = moveSnow(&snows[c%CONSOLE_WIDTH], rand() %((int)sqrt((double)snowSpeed)+2), user);
                if( anff == 3 ){ // ü�� ���� �̺�Ʈ : PLAYER <-> �浹
                    sprintf(message,"ü��: %2d",HP);
                    drawUI( message, HPUi, COLOR_UI);
                }else if( anff == -1 ){//���ӿ���
                    closeScene();
                    return main();
                }
                Sleep(10/snowSpeed+1); //�ӵ��� ���� ������
            }

            if( kbhit() ){
                ch = getch();
                Move(&user, ch);
                if(1){ //UI ��ȭ -> �ٽ� �׸���
                    sprintf(message,"����: %d",score);
                    drawUI( message, ScoreUi, COLOR_UI);
                    sprintf(message,"�ӵ�: %2d",snowSpeed);
                    drawUI( message, SpeedUi, COLOR_UI);
                    sprintf(message,"ü��: %2d",HP);
                    drawUI( message, HPUi, COLOR_UI);
                }
            }
            if( rand() % (15/snowSpeed+3) == 0 ){ //������ Ȯ���� ����� ������
                int c=movePerson(&person);
                if( c == -1 ){ // ���� ���� : ü��->0
                    closeScene();
                    return main();
                }
                else if( c==3){ // ü�� ���� : �浹
                    sprintf(message,"ü��: %2d",HP);
                    drawUI( message, HPUi, COLOR_UI);
                }

            }
            if( rand()%1000 < ITEM_RANDOM_DROP ){// ������ Ȯ���� ������ ���
                if( item_count < ITEM_MAX_COUNT ){

                    switch( (int)(rand())%10 ){
                    case 0:case 1:case 2:case 3:
                        //BLOCK_ITEM_LINE
                        RX = rand()%CONSOLE_WIDTH;
                        RY = rand()%(CONSOLE_HEIGHT-PLAYER_USER_MIN_Y) + PLAYER_USER_MIN_Y;
                        if( map[RX][RY]==BLOCK_BLANK ){
                            map[RX][RY] = BLOCK_ITEM_LINE;
                            drawObj(RX,RY,COLOR_ITEM_LINE,blocks[BLOCK_ITEM_LINE].content);
                            item_count++;
                        }
                        break;
                    case 4: case 5: case 6: case 7:
                    //BLOCK_ITEM_BLOCK
                        RX = rand()%CONSOLE_WIDTH;
                        RY = rand()%(CONSOLE_HEIGHT-PLAYER_USER_MIN_Y) + PLAYER_USER_MIN_Y;
                        if( map[RX][RY]==BLOCK_BLANK ){
                            map[RX][RY] = BLOCK_ITEM_BLOCK;
                            drawObj(RX,RY,COLOR_ITEM_BLOCK,blocks[BLOCK_ITEM_BLOCK].content);
                            item_count++;
                        }
                        break;
                    case 9: case 8: //BLOCK_ITEM_HPUP
                        RX = rand()%CONSOLE_WIDTH;
                        RY = rand()%(CONSOLE_HEIGHT-PLAYER_USER_MIN_Y) + PLAYER_USER_MIN_Y;
                        if( map[RX][RY]==BLOCK_BLANK ){
                            map[RX][RY] = BLOCK_ITEM_HEALTHUP;
                            drawObj(RX,RY,COLOR_ITEM_HEALTHUP,blocks[BLOCK_ITEM_HEALTHUP].content);
                            item_count++;
                        }
                        break;
                    }

                }
            }
        }
    }
    getchar();
    return 0;
}
