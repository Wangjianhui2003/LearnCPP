#include "exp10.0.cpp"
int main()
{
    BTNode *b,*p,*lp,*rp;
    printf("binary tree basic algorithm:\n");
    printf("1.create binary tree");
    CreateBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("2.display binary tree");DispBTree(b);printf("\n");
    printf("3.H node:");
    p = FindNode(b,'H');
    if(p != NULL)
    {
        lp = LchildNode(p);
        if(lp != NULL) printf("left child is %c ",lp -> data);
        else printf("no leftchild");
        rp = RchildNode(p);
        if(rp != NULL) printf("right child is %c",rp ->data);
        else printf("no right child");
    }
    printf("\n");
    printf("hight:%d\n",BTHeight(b));
    printf("5.free Binary tree b\n");
    DestroyBTree(b);
    return 1;


}