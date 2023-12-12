#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coord
{
    int x;
    int y;
} coord;

typedef struct vertex
{
    int vid;
    coord loc;
    struct vertex *next;
} vertex_node;


void cord(coord *c, FILE *fp);
int num_v(FILE *fp);
void read_map(FILE *fp, vertex_node *adj_list);
void create(vertex_node *adj_list, int vertices);
void insert(vertex_node *adj_list, int src, int dest);




int find_vertex(vertex_node *adj_list, coord *loc, int vertices);
void find_path(vertex_node *adj_list, int start_point, int end_point, int vertices, int *dfs_result, int *bfs_result, int *d_path, int *b_path);
int DFS(vertex_node *adj_list, int s, int d, int *vis, int length, int *path);
void BFS(vertex_node *adj_list, int s, int d, int *vis, int vertices, int *prev);
int reconstruct(vertex_node *adj_list, int start_point, int end_point, int *b_path, int *prev);
void store_path(vertex_node *adj_list, int start_point, int end_point, int vertices, int dfs_result, int bfs_result, int *d_path, int *b_path);

void insert_q(int *q, int *front, int *rear, int k);
int delete_q(int *q, int *front, int *rear);
int isempty_q(int *front);