//binary treaversal 王建辉
#include "exp10.0.cpp"

void PreOrder(BTNode *b)
{
    if(b != NULL)
    {
        printf("%c",b->data);
        PreOrder(b -> lchild);
        PreOrder(b -> rchild);
    }
}
//non recursive
void PreOrder1(BTNode *b)
{
    BTNode *St[MaxSize], *p;
    int top = -1;
    if(b != NULL)
    {
        top++;
        St[top] = b;
        while(top > -1)
        {
            p = St[top];
            top--;
            printf("%c",p->data);
            if(p -> rchild != NULL)
            {
                top++;
                St[top] = p->rchild;
            }
            if(p -> lchild = NULL)
            {
                top++;
                St[top] = p->lchild;
            }
        }
        printf("\n");
    }
}

void InOrder(BTNode *b)
{
    if(b != NULL)
    {
        InOrder(b -> lchild);
        printf("%c",b->data);
        InOrder(b->rchild);
    }
}

void InOrder1(BTNode *b)
{
    BTNode *St[MaxSize],*p;
    int top = -1;
    if(b != NULL)
    {
        p = b;
        while(top > -1 || p != NULL)
        {
            while(p != NULL)
            {
                top++;
                St[top] = p;
                p = p -> lchild;
            }
            if(top > -1)
            {
                p = St[top];
                top--;
                printf("%c ",p -> data);
                p = p->rchild;
            }
        }
        printf("\n");
    }
}

void PostOrder(BTNode *b)
{
    if(b != NULL)
    {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c",b->data);
    }
}

void PostOrder1(BTNode *b)
{
    BTNode *St[MaxSize];
    BTNode *p;
    int top = -1;
    bool flag;
    if(b != NULL)
    {
        do
        {
            while(b != NULL)
            {
                top++;
                St[top] = b;
                b = b->lchild;
            }
            p = NULL;
            flag = true;
            while(top != -1 && flag)
            {
                b = St[top];
                if(b -> rchild == p)
                {
                    printf("%c ",b -> data);
                    top--;
                    p = b;
                }
                else
                {
                    b = b->rchild;
                    flag = false;
                }
            }
        }while(top != -1);
        printf("\n");
    }
}

void TravLevel(BTNode *b)
{
    BTNode *Qu[MaxSize];
    int front,rear;
    front = rear = 0;
    if(b != NULL) printf("%c ",b->data);
    rear++;
    Qu[rear] = b;
    while(rear != front)
    {
        front = (front + 1)%MaxSize;
        b = Qu[front];//dequeue and check child node
        if(b -> lchild != NULL)
        {
            printf("%c ",b->lchild -> data);
            rear = (rear + 1)%MaxSize;
            Qu[rear] = b -> lchild; //enqueue
        }
        if(b -> rchild != NULL)
        {
            printf("%c ",b -> rchild -> data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b -> rchild;//enqueue
        }
    }
    printf("\n");
    
}

int main()
{
    BTNode *b;
    CreateBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    TravLevel(b);printf("\n");
    PreOrder(b);printf("\n");
    InOrder(b);printf("\n");
    PostOrder(b);printf("\n");
    DestroyBTree(b);
    return 1;

}