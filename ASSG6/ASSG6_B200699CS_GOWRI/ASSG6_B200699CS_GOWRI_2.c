#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int Data; 
    struct Queue *Next;
   // struct Queue *Front;
   // struct Queue *Rear;
};
void Enqueue(struct Queue** Q, struct Queue* temp, struct Queue** Front, struct Queue** Rear)
{
    if((*Rear)==NULL)
    {
        //temp->Front=temp;
       // temp->Rear=temp;
        (*Q)=temp;
        (*Front)=temp;
        (*Rear) =temp;
        return;
    }
   // struct Queue *New=(*Q);
        (*Rear)->Next=temp;
        (*Rear)=temp;
         struct Queue (*New)=(*Q);
   /* while((New)!=NULL)
    {  //  printf("Yes:%d\n",(New)->Data);
     //   (*Q)->Rear=temp;
        if((New)->Next==NULL)
        {
          (New)->Next=temp; 
          //temp->Rear=temp;
          return; 
        }
        (New)=(New)->Next;
    }*/

}
void Dequeue(struct Queue** Q,struct Queue** Front, struct Queue** Rear)
{
    if((*Rear)==NULL)
    {printf("-1\n");return;}
    printf("%d\n",(*Q)->Data);
    struct Queue *temp;
    if((*Q)->Next==NULL)
    {(*Q)=NULL; (*Rear)=NULL; (*Front)=NULL; return;}
    temp=(*Q)->Next;
    (*Rear)=temp;
    struct Queue *New;
    (*Q)=temp;
 /*   while((*Q)!=NULL)
    {
        (*Q)->Front=temp;
        (*Q)=(*Q)->Next;
    } */

}
void QueueEmpty(struct Queue* Rear)
{
    if(Rear==NULL)
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
   //temp->Rear = temp;
   (*x)=temp;
}
/*void print(struct Queue *Q)
{
  while(Q!=NULL)
  {
    printf("%d\n",Q->Data);
    Q=Q->Next;
  }
}*/
int main()
{
    char c; 
    char space;
    struct Queue *Q=NULL;
    struct Queue *temp=NULL;
    struct Queue *Front=NULL;
    struct Queue *Rear=NULL;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
          case 'i': scanf("%c",&space);
                    Create_Node(&temp);
                    Enqueue(&Q,temp,&Front,&Rear);
                    //print(Q);
                    break;
          case 'd': Dequeue(&Q,&Front,&Rear);
                    break;
          case 'e': QueueEmpty(Q);
                    break;
          case 't': return 0;
        }
    }
}