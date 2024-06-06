#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define V 4
void print(int t[V][V], int INF);
void print(int t[V][V], int INF){
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (t[i][j] == INF)
                printf("%s ", "INF");
                
            else
                printf("%d ", t[i][j]);
        }
        printf("\n");
    }

}
void floyd(int t[V][V]);
void floyd(int t[V][V]){
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (t[i][k] + t[k][j] < t[i][j])
                    t[i][j] = t[i][k] + t[k][j];
            }
        }
    }

}

int main()
{
    int INF = 9999;
    int table[V][V] = {
                        { 0, 2, INF, 4 },
                        { INF, 0, 3, INF },
                        { 10, INF, 0, 2 },
                        { INF, 11, 9, 0 } 

                        };
    //print the original table
    printf("The original table: \n");
    print(table, INF);
    floyd(table);
    //print the table after finding the shortest paths
    printf("The table with the shortest paths: \n");
    print(table, INF);

    return 0;
}