#include<stdio.h>
#include<stdlib.h>
struct Node 
{int info; struct Node *Pre; struct Node *Next;};
struct Node* Create_Node(int in)
{  
   //x=(struct Node*)malloc(sizeof(struct Node));
   struct Node *temp;
   temp=(struct Node*)malloc(sizeof(struct Node));
   temp->info = in; temp->Next = NULL; temp->Pre=NULL;
   return temp;
   //printf("%d\n",in);
}
struct Node *List_Insert_Front(struct Node *L,int y)
{
     struct Node *x;
     x=Create_Node(y);
     if(L!=NULL)
     {x->Next=L;
     L->Pre=x;}
     L=x;
     printf("%d\n",L->info);
     return L;
}
void Print_List(struct Node *L)
{
    while (L!=NULL) 
    {
         printf("%d ",(L)->info); (L)=(L)->Next;
    }
    printf("\n");
}
int main()
{struct Node *L=NULL;
int in;
printf("Insert");
scanf("%d",&in);
L=List_Insert_Front(L,in); 
printf("%d",L->info);
Print_List(L);
return 0;}