#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int Data; 
    struct Queue *Next;
    struct Queue *Front;
    struct Queue *Rear;
};
void Enqueue(struct Queue** Q, struct Queue* temp)
{
    if((*Q)==NULL)
    {
        temp->Front=temp;
       // temp->Rear=temp;
        (*Q)=temp;
        return;
    }
   // struct Queue *New=(*Q);
    while((*Q)!=NULL)
    {
        (*Q)->Rear=temp;
        if((*Q)->Next==NULL)
        {
          (*Q)->Next=temp; 
          //temp->Rear=temp;
          return; 
        }
        (*Q)=(*Q)->Next;
    }

}
void Dequeue(struct Queue** Q)
{
    if((*Q)->Rear==NULL)
    {printf("-1\n");return;}
    printf("%d\n",(*Q)->Data);
    struct Queue *temp;
    if((*Q)->Next==NULL)
    {(*Q)=NULL; return;}
    temp=(*Q)->Next;
    struct Queue *New;
    (*Q)=temp;
    while((*Q)!=NULL)
    {
        (*Q)->Front=temp;
        (*Q)=(*Q)->Next;
    }
}
void QueueEmpty(struct Queue* Q)
{
    if(Q->Rear==NULL)
    {printf("-1\n");return;}
    printf("1\n");
}
void Create_Node(struct Queue **x)
{  
   int in;
   scanf("%d",&in);
   struct Queue *temp;
   temp=(struct Queue*)malloc(sizeof(struct Queue));
   temp->Data = in; 
   temp->Next = NULL;
   temp->Rear = temp;
   (*x)=temp;
}
void print(struct Queue *Q)
{
  while(Q!=NULL)
  {
    printf("%d\n",Q->Data);
    Q=Q->Next;
  }
}
int main()
{
    char c; 
    char space;
    struct Queue *Q=NULL;
    struct Queue *temp=NULL;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
          case 'i': scanf("%c",&space);
                    Create_Node(&temp);
                    Enqueue(&Q,temp);
                    print(Q);
                    break;
          case 'd': Dequeue(&Q);
                    break;
          case 'e': QueueEmpty(Q);
                    break;
          case 't': return 0;
        }
    }
}