#include "exp5.0.cpp"
int main(){//������
    ElemType e;
    SqStack *s;
    printf("˳��ջs�Ļ�����������:\n");
    printf("��ʼ��ջs\n");
    InitStack(s);
    printf("ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
    printf("���ν�ջԪ��a,b,c,d,e\n");
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    printf("ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
    while(!StackEmpty(s)){
        Pop(s,e);
        printf("%c",e);
    }
    printf("\n");
    printf("ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
    printf("�ͷ�");
    DestroyStack(s);
    return 1;
}