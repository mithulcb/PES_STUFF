#include <stdio.h>
#include <string.h>
struct cricket
{
char Player[50];
char Team[50];
float avg;
} ;
int n = 5;
void r(struct cricket ary[])
{
int i;
printf("Enter the data of 5 players\n");
for (i = 0; i < n; i++)
{
printf("Enter Playername Teamname Batting avg for player -%d\n", i + 1);
printf("Enter Player Name : ");
scanf( "%s", ary[i].Player);
printf("Enter Team Name : ");
scanf(" %s", ary[i].Team);
printf("Enter Average : ");
scanf(" %f", &ary[i].avg);

}
}
void show(struct cricket ary[])
{
for (int i = 0; i < n; i++)
{
printf("%s %s %.2f\n", ary[i].Player, ary[i].Team, ary[i].avg);
}
}
void sort(struct cricket ary[])
{
struct cricket temp;
for (int i = 1; i < n; i++)
for (int j = 0; j < n - i; j++)
{
if (strcmp(ary[j].Team, ary[j + 1].Team) > 0)
{
temp = ary[j];
ary[j] = ary[j + 1];
ary[j + 1] = temp;
}
}
show(ary);
}
int main()
{
struct cricket c[5];
r(c);
sort(c);
}
