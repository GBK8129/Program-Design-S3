#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node 
{
    char emp_id[11];
    float yoe;
    struct Node* l;
    struct Node* r;
    struct Node* p;
};
struct Node *CreateNode(char e[],float y)
{
    struct Node *T;
    T=(struct Node*)malloc(sizeof(struct Node));
    T->yoe=y;
    strcpy(T->emp_id,e);
    T->l=NULL;
    T->r=NULL;
    T->p=NULL;
    return T;
}
int farthest_distance(struct Node* T,int c)
{
    int f;
    if(T==NULL)
    {return -1;}
    if(T->r==NULL && T->l==NULL)
    {return 0;}
    if(T->r==NULL || T->l==NULL)
    {return 1;}
    if(T->l->r== NULL)
    {c++; f=farthest_distance(T->r,0);}
    else if(T->l->l== NULL)
    {c++; f=farthest_distance(T->r,0);}
    else if(T->r->r== NULL)
    {c++; f=farthest_distance(T->l,0);}
    else if(T->r->l== NULL)
    {c++; f=farthest_distance(T->l,0);}
    else
    {return c;}
}
void InsertT2(struct Node** T2, struct Node* T)
{
    if(*(T2)==NULL)
    { 
     *(T2)=T;
     return;
    }
     T->p=(*T2);
     if (T->yoe < (*T2)->yoe)
       { InsertT2(&(*T2)->l, T); }
     else if (T->yoe > (*T2)->yoe)
       { InsertT2(&(*T2)->r, T); }
}
void Insert_employee(struct Node** T1, struct Node** T2,struct Node* T)
{
    if(*(T1)==NULL)
    { 
     *(T1)=T;
     return;
    }
     T->p=(*T1);
     if (T->yoe < (*T1)->yoe)
       { Insert_employee(&(*T1)->l,T2, T); }
     else if (T->yoe > (*T1)->yoe)
       { Insert_employee(&(*T1)->r, T2, T); }
    int i,j;
    i=farthest_distance((*T1)->r,0);
    j=farthest_distance((*T1)->l,0);
    int k=j-1;
    if(k==-1 || k==0 || k==1)
    {
        return;
    }
    InsertT2(T2,T->p);
    if(T->p->l==NULL)
      {T->p=T->p->r;}
    else if(T->p->r==NULL)
      {T->p=T->p->l;}
    else
      {T->p=T;}

}
void Print_tree(struct Node* T)
{
    if(T==NULL)
    {return;}
    puts(T->emp_id);
    Print_tree(T->l);
    Print_tree(T->r);
}

int main()
{
    char e[11];
    float y;
    char c;
    int k;
    int i;
    int j=0;
    char space;
    struct Node* T1=NULL;
    struct Node* T2=NULL;
    struct Node* T=NULL;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
           case 'i': scanf("%c",&space);
                     scanf("%s",e);
                     scanf("%c",&space);
                     scanf("%f",&y);
                     T=CreateNode(e,y);
                     Insert_employee(&T1,&T2,T);
                     break;
           case 'f': scanf("%d",&k);
                     if(k==1)
                     {j=0;
                         i=farthest_distance(T1,j);}
                     else
                     {j=0;
                         i=farthest_distance(T2,j);}
                     printf("%d\n",i);
                     break;
           case 'p': scanf("%d",&k);
                     if(k==1)
                     {Print_tree(T1);}
                     else
                     {Print_tree(T2);}
                     break;
           case 't': return 0;
        }
    }
}