typedef struct node
{
    int x;
    int y;
    int val;
    struct node* right;
    struct node* down;

}node;

typedef struct queue
{
    int x;
    int y;
    struct node *front, *end;   
}queue;

queue* createQ();
void make_N_R(node**, int, int, int);
void join_N_D(node* );
node* read_Map(node*, int[][10]);
queue* find_Path(node*, queue*, int[][10]);
void store_Path(queue*);