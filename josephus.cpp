#include<iostream>
using namespace std;

//enum bool{true,false};
typedef struct node
{
    int data;
    struct node *link;
}circleNode,*circleList;

void josephus(circleList &L,int n,int s,int m)
{
    circleNode *p,*q=L;
    //新建循环表，存储桌子上人及其座位号
    for(int i=0;i<n;i++)
    {
        p=new circleNode;
        p->data=i+1;
        p->link=L;
        q->link=p;
        q=p;
    }
    //使p指向第s个人
    p=L;
    for(int i=0;i<s;i++)
    {
        p=p->link;
        if(p==L)
            p=p->link;    
    }
    //每数m个人，即每隔m-1个人删除第m个人
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            q=p;
            p=p->link;
            if(p==L)    //跳过头结点
            {
                q=p;
                p=p->link;
            }
        }
        q->link=p->link;
        cout<<p->data<<endl;    //删除节点
        delete p;
        p=q->link;
    }

    cout<<"处理完毕，所有人离开桌子"<<endl;
}

int main()
{
    circleList L=new circleNode;
    josephus(L,9,1,5);

    return 0;
}