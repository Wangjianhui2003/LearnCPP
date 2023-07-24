#include "exp5.0.cpp"
int main(){//王建辉
    ElemType e;
    SqStack *s;
    printf("顺序栈s的基本运算如下:\n");
    printf("初始化栈s\n");
    InitStack(s);
    printf("栈为%s\n",(StackEmpty(s)?"空":"非空"));
    printf("依次进栈元素a,b,c,d,e\n");
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    printf("栈为%s\n",(StackEmpty(s)?"空":"非空"));
    while(!StackEmpty(s)){
        Pop(s,e);
        printf("%c",e);
    }
    printf("\n");
    printf("栈为%s\n",(StackEmpty(s)?"空":"非空"));
    printf("释放");
    DestroyStack(s);
    return 1;
}