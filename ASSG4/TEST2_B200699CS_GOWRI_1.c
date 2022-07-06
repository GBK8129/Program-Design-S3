#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char message[10000];
struct PACKET
{
char letter;
int code;
};
void Insert_Queue(struct PACKET *Q,struct PACKET *P,int n)
{int i; struct PACKET *temp;
   struct PACKET *k;
   k=Q;
   if(Q==NULL)
   {Q=P;}
    do
    {Q=Q+1;}while(Q!=NULL);
    if(P->code<=Q->code)
    {Q->code=P->code; Q->letter=P->letter;     
    }
    
    while(i>0 && (Q+(i/2))<Q+i)
    {
        temp=Q+i;
        *(Q+i)=*(Q+(i/2));
        *(Q+(i/2))=*temp;
        i=i/2;
    }
   
}
void Extract_Heap(struct PACKET *Q,int n)
{int i;
     for(i=0;i<n;i++)
     {printf("%c",Q->letter);}
}

void print_word(struct PACKET *Q,int n)
{int i=0;
    if(Q==NULL)
    {printf("*"); 
      char c='*';
      do
      {i++;}while(message[i]!='\0');
      message[i]=c;
      return;
    }
    Extract_Heap(Q,n);
    i=0;
    do
      {i++;}while(message[i]!='\0');
      message[i]=' ';

}
int main()
{
    char in;
    int x;
    char c;
    struct PACKET *P=NULL;
    int i;int n=0;
    char space;
    struct PACKET *Q=NULL;
    while(1)
    {
        scanf("%c",&in);
        switch(in)
         {
             case 'r': scanf("%c",&space);
                       scanf("%c",&c);
                       scanf("%c",&space);
                       scanf("%d",&i);
                       (*P).letter=c;
                       (*P).code=i;
                       Insert_Queue(Q,P,n);
                       n++;
                       break;
             case 's': print_word(Q,n);
                       free(Q);
                       break;
             case 'd': for(x=0;message[x]!='\0';x++)
                         {printf("%c",message[x]);}
                         printf("\n");
                       break;
             case 't': return 0;
         }
    }
}