#include "exp2.1.cpp"
#include <string.h>
//������
void Split1(LinkNode *&L){
    LinkNode *pre,*p,*q;
    if(L->next == NULL || L->next->next == NULL) return;
    int x = L->next ->data;
    pre = L->next;
    p = pre->next;
    while(p!=NULL){
        if(p->data<x){
            pre -> next = p -> next;
            p -> next = L -> next;
            L -> next = p;
            p = pre ->next;
        }
        else{
            pre = p;
            p = pre -> next;
        }
    }
}

void Spilt2(LinkNode *&L){
    LinkNode *p  = L-> next,*r,*L1,*r1;
    if(L->next == NULL || L->next->next == NULL) return;
    int x = L->next->data;
    r = L;
    while(p!= NULL){
        if(p->data<x){
            r ->next = p;r=p;
            p = p->next;
        }
        else{
            r1->next = p;r1 = p;
            p = p->next;
        }
    }
    r1 -> next = NULL;
    r -> next = L1 -> next;
    free(L1);
}
int main()
{
    LinkNode *L;
    ElemType a[]="daxgdchaeb";
    int n = strlen(a);
    printf("�ⷨ 1\n");
    CreateListR(L,a,n);
    printf("L:");DispList(L);
    printf("���׽����л���\n");
    Split1(L);
    printf("L:");DispList(L);
    DestroyList(L);
    printf("�ⷨ2\n");
    CreateListF(L,a,n);
    printf("L:");DispList(L);
    printf("���׽��ֵ���л���\n");
    Spilt2(L);
    printf("L:");DispList;
    DestroyList(L);
    return 1;


}