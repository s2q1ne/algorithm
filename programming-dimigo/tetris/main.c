#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

#define MAX_X 50
#define MAX_Y 24
#define MOVE_RIGHT 77
#define MOVE_LEFT 75
#define STAR_NUM 70
#define SPEED_RANGE 10

#define MAIN_X 11
#define MAIN_Y 23

#define WALL 1
#define BLANK 0
#define ACTIVE_BLOCK 2
#define INACTIVE_BLOCK 3

#define MARGIN_X 2
#define MARGIN_Y 2

#pragma comment(lib, "winmm.lib")



void gotoxy(int x, int y)
{
   COORD pos = { x,y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void initCursor()
{
   CONSOLE_CURSOR_INFO cursorInfo = { 0, };
   cursorInfo.dwSize = 1;
   cursorInfo.bVisible = FALSE;
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void resizeConsole()
{
   char chTemp[50];
   sprintf(chTemp, "Mode con cols=%d lines=%d", MAX_X, MAX_Y);
   system(chTemp);
}


void displayStartScreen()
{
   int x, y;
   for (y = 0; y < MAX_Y; y++)
   {
      for (x = 0; x < MAX_X; x += 2)
      {
         if (y <0)
            printf("  ");
         else if (y == 0|| y == MAX_Y - 1 || x == 0 || x == MAX_X - 2)
            printf("¡Ú");
         else
            printf("  ");
      }
   }

   char ch;
   while (1)
   {
      gotoxy(MAX_X / 2 - 15, MAX_Y / 2);
      printf("TETRIS");
      Sleep(300);
      if (_kbhit())
      {
         ch = _getch();
         break;
      }
      gotoxy(MAX_X / 2 - 18, MAX_Y / 2);
      printf("          ");
      Sleep(300);
      if (_kbhit())
      {
         ch = _getch();
         break;
      }
   }
   system("cls");

}

int main()
{
    const int blocks[7][4][4][4] = {
   { { 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },
   { 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 } },
   { { 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 },
   { 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 } },
   { { 0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0 },
   { 0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0 } },
   { { 0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0 },{ 0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0 },
   { 0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0 },{ 0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0 } },
   { { 0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0 },
   { 0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0 } },
   { { 0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0 },
   { 0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0 },{ 0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0 } },
   { { 0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0 },
   { 0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0 },{ 0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0 } }
};
   initCursor();
   resizeConsole();
   PlaySound(TEXT("Tetris_start.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
   displayStartScreen();
   PlaySound(TEXT("Tetris_game.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
   getchar();


}
