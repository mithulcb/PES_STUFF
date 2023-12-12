#include "PES2UG20CS198_H.h"

void cord(coord *c, FILE *fp)
{
    fscanf(fp, "%d %d\n", &c->x, &c->y);
}

void read_map(FILE *fp, point_node *adj_list)
{
    int point = 1;
    int row = 0;
    int col = 0;
    char ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        switch (ch)
        {
        case '0':
            adj_list[point].next = NULL;
            adj_list[point].vid = point;
            adj_list[point].loc.x = row;
            adj_list[point].loc.y = col;

            point++;
            col++;
            break;

        case '1':
            col++;
            break;

        case '\n':
            col = 0;
            row++;
            break;

        default:
            break;
        }
    }

    create(adj_list, point);
}

int num_v(FILE *fp)
{
    int vertices = 0;
    long int initial = ftell(fp);
    char ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '0')
            vertices++;
    }
    fseek(fp, initial, SEEK_SET);
    return vertices;
}

void insert(point_node *adj_list, int src, int dest)
{
    point_node *temp = (point_node *)malloc(sizeof(point_node));
    temp->loc = adj_list[dest].loc;
    temp->vid = adj_list[dest].vid;

    temp->next = adj_list[src].next;
    adj_list[src].next = temp;
}

void create(point_node *adj_list, int vertices)
{
    coord curr, temp;
    for (int i = 1; i <= vertices; i++)
    {
        curr.x = adj_list[i].loc.x;
        curr.y = adj_list[i].loc.y;
        for (int j = i + 1; (j <= vertices) && (adj_list[j].loc.x < curr.x + 2); j++)
        {
            temp.x = adj_list[j].loc.x;
            temp.y = adj_list[j].loc.y;

            if ((temp.x == curr.x && temp.y == curr.y + 1)
                || (temp.y == curr.y && temp.x == curr.x + 1))
            {
                insert_vnode(adj_list, i, j);
            }
        }
    }
}


int find_point(point_node *adj_list, coord *loc, int vertices)
{
    for (int i = 1; i <= vertices; i++)
    {
        if (adj_list[i].loc.x == loc->x && adj_list[i].loc.y == loc->y)
            return adj_list[i].vid;
    }
    return -1;
}

void find_path(point_node *adj_list, int start_point, int end_point, int vertices, int *dfs_result, int *bfs_result, int *d_path, int *b_path)
{
    if (end_point == -1)
    {
        printf("\nDestination point Not Found.");
    }
    else if (start_point != -1)
    {
        // DFS
        int length = 0;
        int *vis = (int *)calloc(vertices + 1, sizeof(int));
        *dfs_result = dfs(adj_list, start_point, end_point, vis, length, d_path);

        // BFS
        vis = (int *)calloc(vertices + 1, sizeof(int));
        int *prev = (int *)calloc(vertices + 1, sizeof(int));
        bfs(adj_list, start_point, end_point, vis, vertices, prev);
        *bfs_result = reconstruct_from_bfs(adj_list, start_point, end_point, b_path, prev);

        free(vis);
    }
    else
        printf("\nSource point Not Found");
}

int DFS(point_node *adj_list, int s, int d, int *vis, int length, int *path)
{
    int t;
    point_node *p;
    vis[s] = 1;
    path[length] = s;

    for (p = adj_list[s].next; p != NULL; p = p->next)
    {
        t = p->vid;
        if (vis[t] == 0)
        {
            length++;
            path[length] = t;
            if ((t == d) || dfs(adj_list, t, d, vis, length, path))
            {
                return 1;
            }
        }
    }
    length--;
    return 0;
}

void BFS(point_node *adj_list, int s, int d, int *vis, int vertices, int *prev)
{
    int front, rear;
    int a, b;
    point_node *p;
    int *queue = (int *)calloc(vertices, sizeof(int));

    front = rear = -1;
    vis[s] = 1;
    qinsert(queue, &front, &rear, s);

    while (!qisempty(&front))
    {
        a = qdelete(queue, &front, &rear);

        for (p = adj_list[a].next; p != NULL; p = p->next)
        {
            b = p->vid;
            if (vis[b] == 0)
            {
                vis[b] = 1;
                prev[b] = a;
                qinsert(queue, &front, &rear, b);
            }
        }
    }

    free(queue);
}

int reconstruct(point_node *adj_list, int start_point, int end_point, int *b_path, int *prev)
{
    int index = 0;
    int length, temp;
    for (int v = end_point; v != 0; v = prev[v])
    {
        b_path[index] = v;
        index++;
    }

    length = index - 1;

    for (int i = 0; i <= (index / 2); i++, length--)
    {
        temp = b_path[length];
        b_path[length] = b_path[i];
        b_path[i] = temp;
    }

    if (b_path[0] != start_point)
        return 0;
    return 1;
}

void insert_q(int *q, int *front, int *rear, int k)
{
    ++*rear;
    q[*rear] = k;

    if (*front == -1)
        *front = 0;
}

int delete_q(int *q, int *front, int *rear)
{
    int t;
    t = q[*front];

    if (*front == *rear)
        *front = *rear = -1;
    else
        ++*front;
    return t;
}

int isempty_q(int *front)
{
    if (*front == -1)
        return 1;
    return 0;
}

void store_path(point_node *adj_list, int start_point, int end_point, int vertices, int dfs_result, int bfs_result, int *d_path, int *b_path)
{
    int temp = -1;
    FILE *fpout_dfs = fopen("outdfs.txt", "w+");
    FILE *fpout_bfs = fopen("outbfs.txt", "w+");

    if (dfs_result)
    {
        printf("\nPATH HAS BEEN FOUND VIA DFS\n");
        for (int i = 0; temp != end_point; i++)
        {
            temp = d_path[i];
            if (temp != 0)
            {
                fprintf(fpout_dfs, "%d -> (%d, %d)\n", adj_list[temp].vid, adj_list[temp].loc.x, adj_list[temp].loc.y);
            }
        }
    }
    else
    {
        printf("\nPATH CANNOT BE FOUND FOR DFS\n");
        fprintf(fpout_dfs, "%d\n", -1);
    }

    temp = -1;
    if (bfs_result)
    {
        printf("\nPATH HAS BEEN FOUND VIA BFS\n");
        for (int i = 0; temp != end_point; i++)
        {
            temp = b_path[i];
            if (temp != 0)
            {
                fprintf(fpout_bfs, "%d -> (%d, %d)\n", adj_list[temp].vid, adj_list[temp].loc.x, adj_list[temp].loc.y);
            }
        }
    }
    else
    {
        printf("\nPATH CANNOT BE FOUND FOR BFS\n");
        fprintf(fpout_bfs, "%d\n", -1);
    }

    printf("\nOutput Files Created");

    free(d_path);
    free(b_path);
}