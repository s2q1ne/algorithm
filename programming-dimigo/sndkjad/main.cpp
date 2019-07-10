#include <stdio.h>
typedef struct people
{
 int Start;
 int End;
}People;
People people[10000];
void quick(People *arr, int n);
int main()
{
 int n;
 scanf("%d", &n);
 int i;
 for (i = 0; i < n; i++)
 {
  scanf("%d %d", &people[i].Start, &people[i].End);
 }
 quick(people, n);
 quick(people, n);
 int empty = 0;
 int maxEmpty = 0;
 int during = 0;
 int maxDuring = 0;
 int first = people[0].Start;
 int second = people[0].End;
 for (i = 1; i < n; i++)
 {
  if (second < people[i].Start)
  {
   empty = people[i].Start - second;
   first = people[i].Start;
   if(second < people[i].End)
    second=people[i].End;
   if (maxEmpty < empty)
    maxEmpty = empty;
  }
  else if (second >= people[i].Start)
  {
   during = people[i].End - first;
   if (second < people[i].End)
    second = people[i].End;
   if (maxDuring < during)
    maxDuring = during;
  }
 }
 printf("%d %d", maxDuring, maxEmpty);
}

void quick(People *arr, int n)
{
 int i, j;
 int s;
 People temp;
 if (n > 1)
 {
  i = -1;
  j = n - 1;
  s = arr[n - 1].Start;
  while (1)
  {
   while (arr[++i].Start < s);
   while (arr[--j].Start > s);

   if (i >= j)
    break;
   temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
  }
  temp = arr[i];
  arr[i] = arr[n - 1];
  arr[n - 1] = temp;

  quick(arr, i);
  quick(arr + i + 1, n - i - 1);
 }
}

