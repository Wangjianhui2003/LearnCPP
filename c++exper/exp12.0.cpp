//图_王建辉
#include<stdio.h>
#include<malloc.h>
#define INF 32767
#define MAXV 100 //max number of nodes
typedef char InfoType;

//matric
typedef struct 
{
    int no;//number
    InfoType info;//data
}VertexType;//node

//graph
typedef struct 
{
    int edges[MAXV][MAXV];
    int n,e;//node,edge
    VertexType vexs[MAXV];//
}MatGraph;



//邻接表
typedef struct ANode //边
{
    int adjvex;
    struct ANode *nextarc;
    int weight;
}ArcNode;

typedef struct Vnode//顶点 
{
    InfoType info;
    int count;//度
    ArcNode *firstarc;
}VNode;

typedef struct //邻接表
{
    VNode adjlist[MAXV];//顶点数组
    int n,e;
}AdjGraph;

void CreateMat(MatGraph &g,int A[MAXV][MAXV],int n,int e)
{
    int i,j;
    g.n = n;
    g.e = e;
    for(i = 0;i<g.n;i++)
        for(j = 0;j<g.n;j++)
            g.edges[i][j] = A[i][j];
}

void DispMat(MatGraph g)
{
    int i,j;
    for(i = 0;i<g.n;i++)
    {
        for(j = 0;j<g.n;j++)
            if(g.edges[i][j] != INF)
                printf("%4d",g.edges[i][j]);
            else
                printf("%4s","00");
        printf("\n");
    }
}

void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e)
{
    int i,j;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for(i = 0;i<n;i++)
        G->adjlist[i].firstarc = NULL;
    for(i = 0;i<n;i++)
    {
        for(j = n-1;j>=0;j--)
            if(A[i][j] != 0 && A[i][j] != INF)
            {
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p -> adjvex = j;
                p -> weight = A[i][j];
                p -> nextarc = G->adjlist[i].firstarc;
                G -> adjlist[i].firstarc = p;
            }
    }
    G -> n = n;
    G -> e = e;
}


void DispAdj(AdjGraph *G)
{
    ArcNode *p;
    for(int i = 0;i<G->n;i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%3d: ",i);
        while(p != NULL)
        {
            printf("%3d[%d]->",p->adjvex,p->weight);
            p = p->nextarc;
        }
        printf("^\n");
    }
}

void DestroyAdj(AdjGraph *&G)
{
    ArcNode *pre,*p;
    for(int i = 0;i<G->n;i++)
    {
        pre = G -> adjlist[i].firstarc;
        if(pre != NULL)
        {
            p = pre -> nextarc;
            while(p != NULL)
            {
                free(pre);
                pre = p; p = p -> nextarc;
            }
            free(pre);
        }
    }
    free(G);
}