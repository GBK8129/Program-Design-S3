#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    struct Node *l;
    struct Node *r;
    struct Node *p;
};
struct Node *CreateNode(int keys)
{
    struct Node *T;
    T=(struct Node*)malloc(sizeof(struct Node));
    T->key=keys;
    T->l=NULL;
    T->r=NULL;
    T->p=NULL;
    return T;
}
void Insert(struct Node** Tree, struct Node* T)
{
  if(*(Tree)==NULL)
  { 
     *(Tree)=T;
     return;
  }
     T->p=(*Tree);
     if (T->key < (*Tree)->key)
       { Insert(&(*Tree)->l, T); }
     else if (T->key > (*Tree)->key)
       { Insert(&(*Tree)->r, T); }
}
void Combine1(struct Node* T1, struct Node** k, struct Node* T2)
{
    T1->p=*k;
    (*k)->l=T1;
    T2->p=*(k);
    (*k)->r=T2;
    //free(T1);
    //free(T2);
}
void Inorder(struct Node* T)
{
    if(T==NULL)
     { return; }
     Inorder(T->l); 
     printf("%d ",T->key);
     Inorder(T->r);
}
struct Node* Combine2(T1,T2)
{
    struct Node* temp;
    struct Node* k;
    temp=T1;
    while(temp->r!=NULL)
    {
        temp=temp->r;
    }
    k=temp;
    temp->p=NULL;
    temp->r=NULL;
    temp->l=NULL;
    Combine(T1,&k,T2);
    return k;
}
int main()
{
    char X[10000],Y[10000];
    int A[10000],B[10000];
    int m,n;
    m=0;n=0;
    int i;
    struct Node *temp=NULL;
    struct Node *T1=NULL;
    struct Node *T2=NULL;
    struct Node *k=NULL;;
    scanf("%[^\n]%*c",X);
    scanf("%[^\n]%*c",Y);
    
    for(i=0;X[i]!='\0';i++)
    {
        if(X[i]!=' ')
        {
          A[m]=X[i]-'0';
          m++;
        }
    }
    for(i=0;Y[i]!='\0';i++)
    {
        if(Y[i]!=' ')
        {
          B[n]=Y[i]-'0';
          n++;
        }
    }
    for(i=0;i<m;i++)
    {   
        temp=CreateNode(A[i]);
        Insert(&T1,temp);
        temp=NULL;
    }
    for(i=0;i<n;i++)
    {  
        temp=CreateNode(B[i]);
        Insert(&T2,temp);
        temp=NULL;
    }
    
    while(T1->p!=NULL)
    {T1=T1->p;}
    while(T2->p!=NULL)
    {T2=T2->p;}
    k=Combine2(T1,T2);
    Inorder(k);
    return 0;
}