#include "exp10.0.cpp"
int Nodes(BTNode *b)
{
    int num1,num2;
    if(b == NULL)
        return 0;
    else if(b->lchild == NULL && b -> rchild == NULL)
        return 1;
    else
    {
        num1 = Nodes(b -> lchild);
        num2 = Nodes(b -> rchild);
        return (num1 + num2 + 1);
    }
}

int LeafNodes(BTNode *b)
{
    int num1,num2;
    if(b == NULL)
        return 0;
    else if(b -> lchild == NULL && b->rchild == NULL)
        return 1;
    else
    {
        num1 = LeafNodes(b ->lchild);
        num2 = LeafNodes(b ->rchild);
        return(num1 + num2);
    }
}

int Level(BTNode *b,ElemType x,int h)
{
    int l;
    if(b == NULL)
        return(0);
    else if(b -> data == x)
        return(h);
    else
    {
        l = Level(b -> lchild,x,h+1);
        if(l != 0)return(1);
        else return(Level(b->rchild,x,h+1));
    }
}

int BTWidth(BTNode *b)
{
    struct
    {
        int lno;
        BTNode *p;
    }Qu[MaxSize];

    int front,rear;
    int lnum,max,i,n;
    front = rear = 0;

    if(b != NULL)
    {
        rear++;Qu[rear].p = b;
        Qu[rear].lno = 1;
        while(rear != front)
        {
            front++;
            b = Qu[front].p;
            lnum = Qu[front].lno;
            if(b -> lchild != NULL)
            {
                rear++;Qu[rear].p = b -> lchild;
                Qu[rear].lno = lnum + 1;
            }
            if(b -> rchild != NULL)
            {
                rear++;Qu[rear].p = b->rchild;
                Qu[rear].lno = lnum + 1;
            }
        }
        max = 0;lnum = 1;i = 1;
        while(i <= rear)
        {
            n = 0;
            while(i <= rear && Qu[i].lno == lnum)
            {
                n++;
                i++;
            }
            lnum = Qu[i].lno;
            if(n>max)max = n;
        }
        return max;
    }
}
int main()
{
    ElemType x = 'K';
    BTNode *b,*p,*lp,*rp;
    CreateBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("output bt:");DispBTree(b);printf("\n");
    printf("number of nodes:%d\n",Nodes(b));
    printf("leaf number of bt:%d\n",LeafNodes(b));
    printf("mid number of bt%c,level of node:%d\n",x,Level(b,x,1));
    printf("width of bt:%d\n",BTWidth(b));
    DestroyBTree(b);
    return 1;

}