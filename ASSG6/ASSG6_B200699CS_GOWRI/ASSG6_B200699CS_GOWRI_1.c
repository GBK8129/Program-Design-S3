#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int Data; 
    struct Stack *Next;
};
void Push(struct Stack **S,struct Stack *temp)
{
  if((*S)==NULL)
  {(*S)=temp;return;}
  temp->Next=(*S);
  (*S)=temp;
}
void Pop(struct Stack **S)
{
  if((*S)==NULL)
  {printf("-1\n"); return;}
  struct Stack *Empty;
  Empty=(*S);
  int del=Empty->Data;
  printf("%d\n",del);
  (*S)=Empty->Next;
}
void Stack_Empty(struct Stack *S)
{
    if(S==NULL)
    {printf("-1\n"); return;}
     printf("1\n"); return;
}
void Create_Node(struct Stack **x)
{  
   int in;
   scanf("%d",&in);
   struct Stack *temp;
   temp=(struct Stack*)malloc(sizeof(struct Stack));
   temp->Data = in; temp->Next = NULL;
   (*x)=temp;
}
/*void print(struct Stack *S)
{
  while(S!=NULL)
  {
    printf("%d\n",S->Data);
    S=S->Next;
  }
}*/
int main()
{
    char c; 
    char space;
    struct Stack *S=NULL;
    struct Stack *temp;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
          case 'i': scanf("%c",&space);
                    Create_Node(&temp);
                    Push(&S,temp);
                    //print(S);
                    break;
          case 'd': Pop(&S);
                    break;
          case 'e': Stack_Empty(S);
                    break;
          case 't': return 0;
        }
    }
}