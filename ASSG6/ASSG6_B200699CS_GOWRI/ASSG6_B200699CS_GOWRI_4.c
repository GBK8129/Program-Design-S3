#include<stdio.h>
struct ExpTree
{
   char Data;
   struct ExpTree *Left;
   struct ExpTree *Right;
};
void InOrder(struct ExpTree* T) 
{ 
    if(T!=NULL) 
    { 
        InOrder(T->Left);  printf("%c ", T->Data);   InOrder(T->Right); 
    } 
}
void PostOrder(struct ExpTree* T)
{
    if(T!=NULL)
    {
       PostOrder(T->Left); PostOrder(T->Right); printf("%c",T->Data);
    }
}
void PreOrder(struct ExpTree* T)
{
    if(T!=NULL)
    {
       printf("%c",T->Data); PreOrder(T->Left); PreOrder(T->Right); 
    }
}
struct ExpTree* Construct_Tree(struct ExpTee* T)
{

}
int main()
{
    char E[100000];
    char c;
    char space;
    struct ExpTree *T;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'e': scanf("%c",&space);
                      Construct_Tree(T);
                      break;
            case 'i': InOrder(T);
                      break;
            case 'p': PreOrder(T);
                      break;
            case 's': PostOrder(T);
                      break;
            case 't': return 0;
        }
    }

}