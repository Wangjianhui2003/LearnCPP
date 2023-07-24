#include "exp2.0.cpp"
int main(){
    SqList *L;
    ElemType e;
    printf("˳�����������˳������:\n");
    printf("(1)��ʼ��˳���\n");
    InitList(L);
    printf("���β���Ԫ��a,b,c,d,e");
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    printf("���˳���L:");DispList(L);
    printf("���˳�������:%d\n",ListLength(L));
    printf("˳���LΪ%s\n",(ListEmpty(L)?"��":"�ǿ�"));
    GetElem(L,3,e);
    printf("˳���L�ĵ�����Ԫ��:%c\n",e);
    printf("Ԫ��a��λ��:%d\n",LocateElem(L,'a'));
    printf("�ڵ��ĸ�Ԫ��λ���ϲ���fԪ��\n");
    ListInsert(L,4,'f');
    printf("���˳���:");DispList(L);
    printf("ɾ��L�ĵ�����Ԫ��\n");
    ListDelete(L,3,e);
    printf("���˳���L:");DispList(L);
    printf("�ͷ�˳���L\n");
    DestroyList(L);
    return 1;
}//������
