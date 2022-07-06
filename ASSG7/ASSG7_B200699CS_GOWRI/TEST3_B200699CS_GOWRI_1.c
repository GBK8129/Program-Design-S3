#include<stdio.h>
#include<stdlib.h>
struct Stack
{
   int fval;
   int fpos;
   int nval;
   struct Stack* Next;
};
void Push(struct Stack** S,struct Stack** top,int fv,int fp,int nv)
{
    struct Stack *temp;
    // printf("SEGFAULT\n"); to trace error
    temp=(struct Stack*)malloc(sizeof(struct Stack));
    temp->fval=fv;
    temp->fpos=fp;
    temp->nval=nv;
    temp->Next=NULL;
   // printf("SEGFAULT\n"); to trace error
    if((*top)==NULL && (*S)==NULL)
    {
        *(S)=temp;
        *(top)=temp;
        return;
    }
    // printf("SEGFAULT\n"); to trace error
    while((*S)->Next!=NULL)
    {
       (*S)=(*S)->Next;
    }
    // printf("SEGFAULT\n"); to trace error
    (*S)->Next=temp;
    *(top)=temp;
}
void allocate_student(int A[],int rollno,int room,int n,struct Stack** S,struct Stack** top)
{ 
    int fv,fp,nv;
  if(room<=n)
  {
      fv=A[room-1];
      fp=room-1;
      nv=rollno;
      A[room-1]=rollno;
      // printf("SEGFAULT\n"); to trace error
      Push(S,top,fv,fp,nv);
  }
}
void remove_student(int A[],int room,int n,struct Stack** S,struct Stack** top)
{//(*S)=NULL;
   int i;
   int fv,fp,nv;
   fv=A[room-1];
   fp=room-1;
   nv=-1;
   A[room-1]=-1;
   // printf("SEGFAULT\n"); to trace error
   Push(S,top,fv,fp,nv);
}
void print(int A[],int n)
{//(*S)=NULL;
    int i;
    for(i=0;i<n;i++)
    {printf("%d ",A[i]);}
    // printf("SEGFAULT\n"); to trace error
    printf("\n");
}
void undo(int A[],struct Stack** S,struct Stack** top)
{
    struct Stack *T;
    T=*(S);
    if(*(top)==NULL)
    {return;}
    int i;
    // printf("SEGFAULT\n"); to trace error
    i=((*top)->fpos);
    A[i]=(*top)->fval;
    // printf("SEGFAULT\n"); to trace error
    while((T)->Next!=NULL)
    {
       (*top)=(T);
       (T)=(T)->Next;
       if((T)->Next==NULL)
       {
           T=NULL;break;
       }
    }
    //(*S)=NULL;
    // printf("SEGFAULT\n"); to trace error
}
int main()
{
    int n;
    int i;
    int rollno;
    int room;
    char space;
    struct Stack *S=NULL;
    struct Stack *top=NULL;
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++)
    {
        A[i]=-1;
    }
    char c;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
           case 'i': scanf("%c",&space);
                     scanf("%d",&rollno);
                     scanf("%c",&space);
                     scanf("%d",&room);
                     allocate_student(A,rollno,room,n,&S,&top);
                     break;
           case 'd': scanf("%c",&space);
                     scanf("%d",&room);
                     remove_student(A,room,n,&S,&top);
                     break;
           case 'p': print(A,n);
                     break;
           case 'u': undo(A,&S,&top);
                     break;
           case 't': return 0;
        }
    }
}