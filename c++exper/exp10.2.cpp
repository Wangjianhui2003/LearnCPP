#include "exp10.0.cpp"
#define MaxWidth 40
//pre-in-order
BTNode *CreateBT1(char *pre,char *in,int n)
{
    BTNode *b;
    char *p;
    int k;

    if(n <= 0) return NULL;
    b = (BTNode *)malloc(sizeof(BTNode));
    b->data = *pre;
    for(p = in;p<in + n; p++)
        if(*p == *pre)
            break;
    k = p - in;
    b -> lchild = CreateBT1(pre + 1,in,k);
    b -> rchild = CreateBT1(pre + k + 1,p + 1,n - k -1);
    return b;

}
//post-in-order
BTNode *CreateBT2(char *post,char *in,int n)
{
    BTNode *b;
    char r,*p;
    int k;

    if(n<=0) return NULL;
    r = *(post + n - 1);
    b = (BTNode *)malloc(sizeof(BTNode));
    b->data = r;
    for(p = in;p < in+n;p++)
        if(*p == r) break;
    k = p - in;
    k = p - in;
    b -> lchild = CreateBT2(post,in,k);
    b -> rchild = CreateBT2(post + k,p + 1,n - k - 1);
    return b;
}

void DispBTree1(BTNode *b)
{
    BTNode *St[MaxSize],*p;
    int level[MaxSize][2],top = -1,n,i,width = 4;
    char type;
    if(b != NULL)
    {
        top++;
        St[top] = b;
        level[top][0] = width;
        level[top][1] = 2;
        while(top > -1)
        {
            p = St[top];
            n = level[top][0];
            switch(level[top][1])
            {
                case 0:type = 'L';break;
                case 1:type = 'R';break;
                case 2:type = 'B';break;
            }
            for(i = 1;i <= n;i++)
                printf(" ");
            printf("%c(%c)",p -> data,type);
            for(i = n+1;i <= MaxWidth;i += 2)
                printf("--");
            printf("\n");
            top--;
            if(p->rchild != NULL)
            {
                top++;
                St[top] = p -> rchild;
                level[top][0] = n + width;
                level[top][1] = 1;
            }
            if(p -> lchild != NULL)
            {
                top++;
                St[top] = p -> lchild;
                level[top][0] = n + width;
                level[top][1] = 0;
            }
        }
    }
}

int main()
{
    BTNode *b;
    ElemType pre[] = "ABDEHJKLMNCFGI";
    ElemType in[] = "DBJHLKMNEAFCGI";
    ElemType post[] = "DJLNMKHEBFIGCA";
    int n = 14;
    b = CreateBT1(pre,in,n);
    printf("preorder sequence:%s\n",pre);
    printf("inorder:%s\n",in);
    DispBTree(b);printf("\n");
    DispBTree1(b);printf("\n\n");
    printf("inorder:%s\n",in);
    printf("postorder:%s\n",post);
    b = CreateBT2(post,in,n);
    DispBTree(b);printf("\n");
    DispBTree1(b);printf("\n");
    DestroyBTree(b);
    return 1;
}