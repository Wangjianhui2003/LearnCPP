#include "exp12.1.cpp"
int main()
{
    AdjGraph *G;
    int A[MAXV][MAXV] = {
        {0,5,INF,7,INF,INF},{INF,0,4,INF,INF,INF},
        {8,INF,0,INF,INF,9},{INF,INF,5,0,INF,6},
        {INF,INF,INF,5,0,INF},{3,INF,INF,INF,1,0}
    };
    int n = 6,e = 10;
    CreateAdj(G,A,n,e);
    printf("G:Adjgraph:\n");DispAdj(G);
    printf("DFS:\n");
    DFS(G,0);printf("\n");
    printf("DFS nonrecursion:\n");
    DFS1(G,0);
    printf("BFS:\n");
    BFS(G,0);
    DestroyAdj(G);
    return 1;
}