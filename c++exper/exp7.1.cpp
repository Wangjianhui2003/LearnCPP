//各种字符匹配算法_王建辉
//简单匹配
#include "exp7.0.cpp"
int Index(SqString s,SqString t)
{
    int i = 0,j = 0;
    while(i < s.length && j < t.length)
    {
        if(s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j +1;
            j = 0;
        }
    }
    if(j >= t.length)
        return(i-t.length);
    else
        return -1;
}
//求next
void GetNext(SqString t,int next[])
{
    int j,k;
    j = 0;k = -1;next[0] = -1;
    while(j<t.length-1)
    {
        if(k == -1 || t.data[j] == t.data[k])
        {
            j++;k++;
            next[j] = k;
        }
        else k = next[k];
    }
}


//KMP
int KMPIndex(SqString s,SqString t)
{
    int next[MaxSize],i = 0,j = 0;
    GetNext(t,next);
    while(i<s.length && j<t.length)
    {
        if(j == -1 || s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else j = next[j];
    }
    if(j >= t.length)
        return(i-t.length);
    else
        return(-1);
}

//
void GetNextval(SqString t,int nextval[])
{
    int j = 0,k = -1;
    nextval[0] = -1;
    while(j<t.length)
    {
        if(k == -1 || t.data[j] == t.data[k])
        {
            j++;k++;
            if(t.data[j] != t.data[k])
                nextval[j] = k;
            else
                nextval[j] = nextval[k];
        }
        else
            k = nextval[k];
    }
}
//


int KMPIndex1(SqString s,SqString t)
{
    int nextval[MaxSize],i = 0,j = 0;
    GetNextval(t,nextval);
    while(i<s.length && j<t.length)
    {
        if(j == -1 || s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else
            j = nextval[j];
    }
    if(j >= t.length)
        return(i-t.length);
    else
        return(-1);
}
int main()
{
    int j;
    int next[MaxSize],nextval[MaxSize];
    SqString s,t;
    StrAssign(s,"abcabcdabcdeabcdefabcdefg");
    StrAssign(t,"abcdeabedefab");
    DispStr(s);
    DispStr(t);
    Index(s,t);
    GetNext(t,next);
    GetNextval(t,nextval);
}
