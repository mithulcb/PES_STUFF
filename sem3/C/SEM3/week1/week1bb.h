typedef struct matchruns{
    int played;
    int runs;
}mr;

typedef struct player{
    char name[20];
    char Tname[20];
    mr stats[14];
}Player;

void read(Player *p,int n);
void maxRuns(Player *p,int n,int matchNO);
void matchNumber(Player *p,int n);