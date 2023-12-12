typedef struct node{
	int row;
	int col;
	struct node *last;
	struct node *next;
	struct node *right;
	struct node *prev;
	struct node *down;
	struct node *left;
	struct node *up;
	
}NODE;

void getNeighbours(NODE *root);
void findPath(NODE *root,int ex,int ey);
void printPath(NODE *root,int ex,int ey);
