#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *p;
};
struct Node *CreateNode(int keys)
{
    struct Node *T;
    T=(struct Node*)malloc(sizeof(struct Node));
    T->key=keys;
    T->left=NULL;
    T->right=NULL;
    T->p=NULL;
    return T;
}
struct Node *Search(struct Node* T, int k)
{
   if (T == NULL)
       {return NULL;}
   if  (T->key == k)
       {return T;}
    if (T->key < k)
       {return Search(T->right, k);}
    if (T->key > k)    
       {return Search(T->left, k);}
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
       { Insert(&(*Tree)->left, T); }
     else if (T->key > (*Tree)->key)
       { Insert(&(*Tree)->right, T); }
}
int Successor(struct Node* T, int a)
{
    if(T==NULL)
     { return -1; }
    struct Node* temp;
    temp=Search(T,a);
    
    if (temp->right != NULL)
     {   
         temp = temp->right;
         while (temp->left!=NULL)
          {temp = temp->left;}
         if(temp!=NULL)
         {
             printf("%d\n",temp->key);
             return temp->key;
         }
     }
    else
    { 
    struct Node *exc;
    exc=temp->p;
    //struct Node *r=exc->right;
    while(exc!=NULL &&  temp==exc->right)
    {
        temp=exc;
        exc=exc->p;
        if(exc->p!=NULL)
         exc=exc->p;
        else
        {printf("-1\n"); return -1;}
    }
    printf("%d\n",exc->key);
    return exc->key;}
    printf("-1\n");
    return -1;
}
void Predecessor(struct Node* T, int a)
{
    if(T==NULL)
     { return; }
    struct Node* temp;
    temp=Search(T,a);
    
    if (temp->left != NULL)
     { printf("IN\n");  
         temp = temp->left;
         while (temp->right!=NULL)
          {temp = temp->right;}
          if(temp!=NULL)
           {
               printf("%d\n",temp->key);
               return;
           }
     }
    else 
    {
     struct Node *exc=NULL;
     
    exc=temp->p;
   
    while(exc!=NULL && temp==(exc)->left)
    {
        temp=exc;
        if(exc->p!=NULL)
         exc=exc->p;
        else
        {printf("-1\n"); return;}
        
    }
    printf("%d\n",exc->key);
    return;
    }
    printf("-1\n");
    
}
int Minimum(struct Node* T)
{
   while(T->right!=NULL)
   {T=T->right;}
   return T->key;
}
void Delete(struct Node** Tree, struct Node *T,int k)
{
    if((*Tree)==NULL)  
    {return;}
    /*int k;
    k=T->key;*/
    if(T->right==NULL && T->left==NULL)
    {
        T=T->p;
        if(T->left->key==k)
        {
            T->left=NULL;
        }
        else if(T->right->key==k)
        {
            T->right=NULL;
        }
    }
    else if(T->right==NULL)
    {        
        T->key=T->left->key;
        T->left=NULL;
    }
    else if(T->left==NULL)
    {
        T->key=T->right->key;
        T->right=NULL;
    }
    else
    {
        //struct Node *temp=T;
        int rep;
        //rep=Successor(T,k);
        //Delete(Tree,T,rep);
        
        rep=Minimum(*Tree);
       // rep=temp->key;
        
        struct Node *keep=Search(*Tree,rep);
        T->key=rep;
        Delete(Tree,keep,rep);

    }
    /*while(T->p!=NULL)
        {T=T->p;}
        (*Tree)=T; */
        return;
}

void Inorder(struct Node* T)
{
    if(T==NULL)
     { return; }
     Inorder(T->left); 
     printf("%d ",T->key);
     Inorder(T->right);
}
void Preorder(struct Node* T)
{
    if(T==NULL)
     { return; }
     printf("%d ",T->key);
     Preorder(T->left); 
     Preorder(T->right);
}
void Postorder(struct Node* T)
{
    if(T==NULL)
     { return; }
     Postorder(T->left); 
     Postorder(T->right);
     printf("%d ",T->key);
}
int main()
{
    char c;
    struct Node *Tree=NULL;
    struct Node *T=NULL;
    struct Node *temp;
    int a;
    int junk;
    char space;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'a': scanf("%c",&space);
                      scanf("%d",&a);
                      T=CreateNode(a);
                      Insert(&Tree,T);
                      break;
            case 'd': scanf("%c",&space);
                      scanf("%d",&a);
                      temp=Search(Tree,a);
                      if(temp==NULL)
                      {printf("-1\n");}
                      else
                      {
                        printf("%d\n",temp->key);
                        Delete(&Tree,temp,a);
                      }
                      break;             
            case 's': scanf("%c",&space);
                      scanf("%d",&a);
                      temp=Search(Tree,a);
                      if(temp==NULL)
                      {printf("-1\n");}
                      else
                      {printf("1\n");}
                      break;
            case 'c': scanf("%c",&space);
                      scanf("%d",&a);
                      junk=Successor(Tree,a);
                      break;
            case 'r': scanf("%c",&space);
                      scanf("%d",&a);
                      Predecessor(Tree,a);
                      break;
            case 'i': Inorder(Tree);
                      printf("\n");
                      break;
            case 'p': Preorder(Tree);
                      printf("\n");
                      break;
            case 't': Postorder(Tree);
                      printf("\n");
                      break;
            case 'e': return 0;
        }
    }
}