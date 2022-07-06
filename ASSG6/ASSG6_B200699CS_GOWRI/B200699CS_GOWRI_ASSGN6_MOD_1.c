#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct Tree
{
    char Data;
    struct Tree *Left;
    struct Tree *Right;
};
void Push(struct Tree* St, struct Tree* Stk[], int *top)
{
    top++;
    int a=(*top);
    Stk[a]=St;
}
struct Tree* Pop(struct Tree* Stk[], int *top)
{
    struct Tree* ret;
    int a=(*top);
    ret=Stk[a];
    top--;
    return ret;
}
struct Tree* CreateAssignmentTree(char S[])
{
    struct Tree* Stk[5000];
    //(struct Tree*)malloc(sizeof(struct Tree));
    int top=-1;
    int i=0;
    while(S[i]!='\0' || S[i]!=';')
    {
        if(isalpha(S[i]))
          {
              struct Tree* New=(struct Tree*)malloc(sizeof(struct Tree));
              New->Data=S[i];
              New->Left=NULL;
              New->Right=NULL;
              Push(New,Stk,&top);
          }
        else if(S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/' || S[i] == '^')
          {
              struct Tree* a;
              struct Tree* b;
              a=Pop(Stk,&top);
              b=Pop(Stk,&top);
              struct Tree* New;
              New->Data=S[i];
              New->Right=a;
              New->Left=b;
              Push(New,Stk,&top);
          }
    }

}
void PostOrder(struct Tree *Node)
{
    if(Node!=NULL)
    {
        PostOrder(Node->Left);
        PostOrder(Node->Right);
        printf("%c",Node->Data);
    }
}
int main()
{
    struct Tree *Node=NULL;
    struct Tree *R=NULL;
    struct Tree *L=NULL;
    char S[5000];
    char Var[5000];
    char Exp[5000];
    scanf("%s",S);
    int i,j,k;
    i=0;j=0;k=0;
    int count=0;
    /*while(S[k]!='\0')
    {
        if(S[k]==';')
        {count++;}
    }
    if(count==0)
    {
        strcat(S,';');
    }*/
    k=0;
    while(S[i]!='=')
    {
       Var[i]=S[i];
       i++;
    }
    //strcat(Var,';');
    i+=1;
    while(S[i]!=';')
    {
       Exp[k]=S[i];
       i++;k++;
    }
    Node->Data='=';
    R=CreateAssignmentTree(Var);
    L=CreateAssignmentTree(Exp);
    Node->Right=R;
    Node->Left=L;
    PostOrder(Node);
}