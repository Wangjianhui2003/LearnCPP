//实现广义表_王建辉
#include<stdio.h>
#include<malloc.h>
typedef struct lnode
{
    int tag;
    union
    {
        char data;
        struct lnode *sublist;
    }val;
    struct lnode *link;
    
}GLNode;

GLNode *CreateGL(char *&s)
{
    GLNode *g;
    char ch = *s++;
    if(ch!='\0')
    {
        g = (GLNode *)malloc(sizeof(GLNode));
        if(ch == '(')
        {
            g -> tag = 1;
            g ->val.sublist = CreateGL(s);
        }
        else if(ch == ')')
            g = NULL;
        else if(ch == '#')
            g -> val.sublist = NULL;
        else
        {
            g -> tag = 0;
            g -> val.data = ch;
        }
    }
    else
        g = NULL;
    ch = *s++;
    if(g != NULL)
        if(ch == ',')
            g ->link = CreateGL(s);
        else
            g->link = NULL;
    return g;

}

int GLLength(GLNode *g)
{
    int n = 0;
    g = g -> val.sublist;
    while(g != NULL)
    {
        n++;
        g = g->link;
    }
    return n;
}

int GLDepth(GLNode *g)
{
    int max = 0,dep;
    if(g->tag == 0)return 0;
    g = g->val.sublist;
    if(g == NULL) return 1;
    while(g != NULL)
    {
        if(g ->tag == 1)
        {
            dep = GLDepth(g);
            if(dep>max)max = dep;
        }
        g = g->link;
    }
    return(max + 1);
}

void DispGL(GLNode *g)
{
    if(g != NULL)
    {
        if(g -> tag == 0)
            printf("%c",g->val.data);
        else
        {
            printf("(");
            if(g->val.sublist == NULL)
                printf("#");
            else
                DispGL(g->val.sublist);
            printf(")");
        }
    
        if(g -> link != NULL)
        {
            printf(",");
            DispGL(g->link);
        }
    }

}

char maxatom(GLNode *g)
{
    char max1,max2;
    if(g != NULL)
    {
        if(g->tag == 0)
        {
            max1 = maxatom(g->link);
            return(g->val.data>max1?g->val.data:max1);
        }
        else{
            max1 = maxatom(g->val.sublist);
            max2 = maxatom(g->link);
            return(max1>max2?max1 : max2);
        }
    }
    else
        return 0;
}

void DestroyGL(GLNode *&g)
{
    GLNode *g1, *g2;
    g1 = g->val.sublist;
    while(g1 != NULL)
    {
        if(g1 -> tag == 0)
        {
            g2 = g1 -> link;
            free(g1);
            g1 = g2;
        }
        else
        {
            g2 = g1 -> link;
            DestroyGL(g1);
            g1 = g2;
        }
    }
    free(g);
}
int main()
{
    GLNode *g;
    char *str = "(b,(b,a,(#),d),((a,b),c,((#))))";
    g = CreateGL(str);
    printf("广义表g:");DispGL(g);printf("\n");
    printf("广义表g的长度:%d\n",GLLength(g));
    printf("广义表g的深度:%d\n",GLDepth(g));
    printf("最大原子:%c\n",maxatom(g));
    DestroyGL(g);
    return 1;
}
