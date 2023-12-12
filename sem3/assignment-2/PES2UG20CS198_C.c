#include "PES2UG20CS198_H.h"

int main()
{
    int points;
    int op_dfs = 0;
    int op_bfs = 0;
    int begg_point, fin_point;
    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("\nInput file does not exist.");
        exit(0);
    }

    printf("\nReading from input file.\n");
    coord begg, fin;
    cord(&begg, fp);
    cord(&fin, fp);

    printf("\nStart: (%d, %d)\nEnd: (%d, %d)\n", begg.x, begg.y, fin.x, fin.y);

    points = num_v(fp);
    vertex_node *list = (vertex_node *)malloc((points + 1) * sizeof(vertex_node));

    read_map(fp, list);


    printf("\n\nFinding path:\n");
    int *d_path = (int *)calloc(points, sizeof(int));
    int *b_path = (int *)calloc(points, sizeof(int));

    begg_point = find_vertex(list, &begg, points);
    fin_point = find_vertex(list, &fin, points);

    find_path(list, begg_point, fin_point, points, &op_dfs, &op_bfs, d_path, b_path);
    store_path(list, begg_point, fin_point, points, op_dfs, op_bfs, d_path, b_path);

    free(list);
    return 0;
}