#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "PES2UG20CS198_H.h"

int main()
{
    printf("THIS IS RUN BY MITHUL CHANDER PES2UG20CS198");
    int sparse[10][10] ;
    int i=0, j=0;
    int x_in, y_in, x_out, y_out;

    FILE *fp;

    fp = fopen("input.txt", "r");
    char ch;

    node* beg = NULL;

    queue* q;
    q = createQ(q);
    
    
    x_in = fgetc(fp) - '0';
    fgetc(fp);
    y_in = fgetc(fp) - '0';
    fgetc(fp);
    x_out = fgetc(fp) - '0';
    fgetc(fp);
    y_out = fgetc(fp) - '0';
    
    
    
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch != ' ' && ch != '\n')
        {   
            sparse[i][j] = ch - '0';
            j++;
            if(j==10)
            {
                i++;
                j = 0;
            }
        }
    }
    
    beg = read_Map(beg, sparse);
    q = find_Path(beg, q, sparse);
    store_Path(q);

    fclose(fp);
    return 0;
}
