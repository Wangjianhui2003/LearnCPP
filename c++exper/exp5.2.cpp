// 将算术表达式转化为后缀表达式
#include "exp5.0.cpp"
void trans(char *exp, char postexp[])
{
    char e;
    SqStack *Optr;
    InitStack(Optr);
    int i = 0;
    while (*exp != '\0')
    {
        switch (*exp)
        {
        case '(':
            Push(Optr, '(');
            exp++;
            break;
        case ')':           
            Pop(Optr, e);   
            while (e != '(') 
            {
                postexp[i++] = e; 
                Pop(Optr, e);     
            }
            exp++; 
            break;
        case '+': 
        case '-':
            while (!StackEmpty(Optr)) // ջ����ѭ��
            {
                GetTop(Optr, e); // ȡջ��Ԫ��e
                if (e != '(')    // e����'('
                {
                    postexp[i++] = e; // ��e��ŵ�postexp��
                    Pop(Optr, e);     // ��ջԪ��e
                }
                else // e��'(ʱ�˳�ѭ��
                    break;
            }
            Push(Optr, *exp); // ��'+'��'-'��ջ
            exp++;            // ����ɨ�������ַ�
            break;
        case '*': // �ж�Ϊ'*'��'/'��
        case '/':
            while (!StackEmpty(Optr)) // ջ����ѭ��
            {
                GetTop(Optr, e); // ȡջ��Ԫ��e
                if (e == '*' || e == '/')
                {
                    postexp[i++] = e; // ��e��ŵ�postexp��
                    Pop(Optr, e);     // ��ջԪ��e
                }
                else // eΪ��'*'��'/'�����ʱ�˳�ѭ��
                    break;
            }
            Push(Optr, *exp); // ��'*'��'/'��ջ
            exp++;            // ����ɨ�������ַ�
            break;
        default:                               // ���������ַ�
            while (*exp >= '0' && *exp <= '9') // �ж�Ϊ�����ַ�
            {
                postexp[i++] = *exp;
                exp++;
            }
            postexp[i++] = '#'; // ��#��ʶһ����ֵ������
        }
    }
    while (!StackEmpty(Optr)) // ��ʱexpɨ�����,ջ����ʱѭ��
    {
        Pop(Optr, e);     // ��ջԪ��e
        postexp[i++] = e; // ��e��ŵ�postexp��
    }
    postexp[i] = '\0';  // ��postexp����ʽ���ӽ�����ʶ
    DestroyStack(Optr); // ����ջ
}

double compvalue(char *postexp)
{
    double d, a, b, c, e;
    SqStack1 *Opnd;          // ���������ջ
    InitStack1(Opnd);        // ��ʼ��������ջ
    while (*postexp != '\0') // postexp�ַ���δɨ����ʱѭ��
    {
        switch (*postexp)
        {
        case '+':           // �ж�Ϊ'+'��
            Pop1(Opnd, a);  // ��ջԪ��a
            Pop1(Opnd, b);  // ��ջԪ��b
            c = b + a;      // ����c
            Push1(Opnd, c); // ��������c��ջ
            break;
        case '-':           // �ж�Ϊ'-'��
            Pop1(Opnd, a);  // ��ջԪ��a
            Pop1(Opnd, b);  // ��ջԪ��b
            c = b - a;      // ����c
            Push1(Opnd, c); // ��������c��ջ
            break;
        case '*':           // �ж�Ϊ'*'��
            Pop1(Opnd, a);  // ��ջԪ��a
            Pop1(Opnd, b);  // ��ջԪ��b
            c = b * a;      // ����c
            Push1(Opnd, c); // ��������c��ջ
            break;
        case '/':          // �ж�Ϊ'/'��
            Pop1(Opnd, a); // ��ջԪ��a
            Pop1(Opnd, b); // ��ջԪ��b
            if (a != 0)
            {
                c = b / a;      // ����c
                Push1(Opnd, c); // ��������c��ջ
                break;
            }
            else
            {
                printf("\n\t�������!\n");
                // �쳣�˳�
            }
            break;
        default:   // ���������ַ�
            d = 0; // ת���ɶ�Ӧ����ֵ��ŵ�d��
            while (*postexp >= '0' && *postexp <= '9')
            {
                d = 10 * d + *postexp - '0';
                postexp++;
            }
            Push1(Opnd, d); // ����ֵd��ջ
            break;
        }
        postexp++; // �������������ַ�
    }

    GetTop1(Opnd, e);    // ȡջ��Ԫ��e
    DestroyStack1(Opnd); // ����ջ
    return e;            // ����e
}

int main()
{ // �ɽ�exp��Ϊ��������
    char exp[] = "(56-20)/(4+2)";
    char postexp[MaxSize];
    trans(exp, postexp);
    printf("��׺����ʽ:%s\n", exp);
    printf("��׺����ʽ:%s\n", postexp);
    printf("����ʽ��ֵ:%g\n", compvalue(postexp));
    return 0;
}
