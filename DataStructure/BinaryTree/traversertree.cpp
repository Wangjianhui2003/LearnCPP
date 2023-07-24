#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
typedef char ElemType;
struct BTNode
{
    ElemType data;
    BTNode *right;
    BTNode *left;

};
//递归
vector<ElemType> PreOrder(BTNode *B,vector<ElemType> Vec)
{
    if(B != nullptr)
    {
        Vec.push_back(B->data);
        PreOrder(B->left,Vec);
        PreOrder(B->right,Vec);
    }
    return Vec;  
}
//非递归
vector<ElemType> PreOrder1(BTNode *B,vector<ElemType> Vec)
{
    stack<BTNode*> Stack;
    BTNode *Node = B;
    if(B != nullptr) Stack.push(Node);
    
    while(!Stack.empty())
    {
        B = Stack.top();Stack.pop();
        Vec.push_back(B->data);
        if(B->right) Stack.push(B->right);
        if(B->left) Stack.push(B->left);
    }
    return Vec;
}
//非递归中序遍历
vector<ElemType> InOrder1(BTNode *B,vector<ElemType> Vec)
{
    stack<BTNode*> Stack;
    BTNode *cur = B;
    if(cur == nullptr) return;
    while(cur != nullptr || !Stack.empty())
    {
        if(cur != nullptr)
        {
            Stack.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = Stack.top();
            Stack.pop();
            Vec.push_back(cur->data);
            cur = cur->right;
        }
    }
    return Vec;
}

//非递归后续遍历
vector<ElemType> PostOrder1(BTNode *B,vector<ElemType> Vec)
{
    stack<BTNode*> Stack;
    BTNode *cur = B;
    if(cur != nullptr) Stack.push(cur);
    while(!Stack.empty())
    {
        cur = Stack.top();
        Stack.pop();
        Vec.push_back(cur->data);
        if(cur->left) Stack.push(cur->left);
        if(cur->right) Stack.push(cur->right);
    }
    reverse(Vec.begin(),Vec.end());
    return Vec;
}

//层次遍历
vector<vector<ElemType>> LevelOrder(BTNode *B)
{
    queue<BTNode*> Queue;
    if(B != nullptr) Queue.push(B);
    vector<vector<ElemType>> Vec;
    while(!Queue.empty())
    {
        int size = Queue.size();
        vector<ElemType> SubVec;
        B = Queue.front();
        Queue.pop();
        for(int j = 0;j < size;j++)
        {
            B = Queue.front();
            Queue.pop();
            SubVec.push_back(B->data);
            if(B->left) Queue.push(B->left);
            if(B->right) Queue.push(B->right);
        }
        Vec.push_back(SubVec);
    }
    return Vec;
}

//翻转树前序递归
BTNode* InvertTree(BTNode *root)
{
    if(root != nullptr)
    {
        swap(root->left,root->right);
        InvertTree(root->left);
        InvertTree(root->right);
    }
    return root;
}
//翻转树中序递归
BTNode* InInvertTree(BTNode *root)
{
    if(root != nullptr)
    {
        InInvertTree(root->left);
        swap(root->left,root->right);
        InInvertTree(root->left);//依然传左子树，不然有些结点会翻转两次
    }
    return root;
}

//递归判断对称树
//子函数
bool compare(BTNode *Left,BTNode *Right)
{
    if(!Left && !Right) return true;
    if(!Left || !Right) return false;
    if(Left->data != Right->data) return false;//排除nullptr

    bool outside = compare(Left->left,Right->right);//out
    bool inside = compare(Left->right,Right->left);
    bool result = outside && inside;
    return result;

}

bool IsSymmertric(BTNode *root)
{
    if(root == nullptr) return true;
    compare(root->left,root->right);
}

//迭代判断对称树-队列
bool IsSymmertric1(BTNode *root)
{
    if(root == nullptr) return true;
    queue<BTNode*> Queue;
    Queue.push(root->left);
    Queue.push(root->right); //压入右左节点

    while(!Queue.empty()) //开始队列循环检查
    {
        BTNode *Left = Queue.front();Queue.pop();
        BTNode *Right = Queue.front();Queue.pop();
        
        if(Left == nullptr && Right == nullptr) continue;
        if(Left == nullptr || Right == nullptr) return false;
        if(Left->data != Right->data) return false;
        //略写数值相同的情况
        Queue.push(Left->left);
        Queue.push(Right->right);
        Queue.push(Left->right);
        Queue.push(Right->left);
    }
    return true;
}

//求节点高度
int getheight(BTNode *node)
{
    if(node == nullptr) return 0;
    int left = getdepth(node->left);
    int right = getdepth(node->right);
    int depth = 1 + max(left,right);
    return depth;
}

//求二叉树最大深度-层序遍历
int getdepth(BTNode *root)
{
    int depth = 0;
    queue<BTNode*> Queue;
    if(root == nullptr) return 0;
    Queue.push(root);
    
    while(!Queue.empty())
    {
        int size = Queue.size();
        depth++;
        for(int i = 0;i<size;i++)
        {
            BTNode *node = Queue.front();Queue.pop();
            if(node->left) Queue.push(node->left);
            if(node->right) Queue.push(node->right);
        }
    }
    return depth;
}


//统计树的节点数-层序遍历-easy
int countnode(BTNode *root)
{
    queue<BTNode*> Queue;
    int result;
    if(root != nullptr) Queue.push(root);

    while(!Queue.empty())
    {
        BTNode *node = Queue.front();Queue.pop();
        result++;
        if(node->left) Queue.push(node->left);
        if(node->right) Queue.push(node->right);
    }
    return result;
}

//统计树的节点-递归-后序
int countnode1(BTNode *root)
{
    if(root == nullptr) return 0;
    int getleft = countnode1(root->left);
    int getright = countnode1(root->right);
    int result = 1 + getleft + getright;
    return result;
}



