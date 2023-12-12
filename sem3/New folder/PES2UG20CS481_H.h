#define SIZE 10

typedef struct COL {
    int col;
    int data;
    struct COL *next_col;
} COL;

typedef struct ROW {
    int row;
    struct COL *next_col;
    struct ROW *next_row;
} ROW;

typedef struct node
{
    int rown,coln;
    struct node *link;
}node;

typedef struct queue
{
    node *front,*rear;
}queue;

ROW *multilist(int [][SIZE], int, int);
ROW *insert(int, ROW *, int, int);
ROW *create_row(int);
COL *create_col(int, int);
void readmatrix(int,int,int (*)[]);
node *createnode(int,int);
queue *enqueue(queue *,int,int);
queue *initialise();
queue *findpath(ROW *,queue *);
void write(queue *);