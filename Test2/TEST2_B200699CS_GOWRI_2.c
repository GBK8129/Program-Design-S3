#include<stdio.h>
#include<string.h>
struct student
{
char student_id[10];
int g_nbr;
struct student *next;
};
void read_student(struct student** L)
{
    char c[10]; int a; struct student *temp;
    scanf("%s",c);
    scanf("%d",&a);
     strcpy((temp)->student_id,c); (temp)->g_nbr=a;(temp)->next=NULL;
    if((*L)==NULL)
    {(*L)=temp; return;}
   
    while((*L)!=NULL)
    {
       if((*L)->g_nbr==a)
       {temp->next=(*L)->next;
           (*L)->next=temp;return;}
       if((*L)->g_nbr<a && (*L)->next->g_nbr==a)
       {
          temp->next=(*L)->next->next;
          (*L)->next->next=temp;  return;
       }
       if((*L)->next==NULL)
       {
           (*L)->next=temp; return;
       }
       (*L)=(*L)->next;

    }
}
void print_students(struct student* L)
{
    if(L==NULL)
    {printf("NULL\n"); return;}
    while(L!=NULL)
    {printf("%s ",L->student_id);
     L=L->next;}
     printf("\n");
}
void count_students(struct student* L,int k)
{int count=0;int i;
    while(L!=NULL)
    {i++;
        if(L->g_nbr==k)
       {count++;}
     L=L->next;}
     if(i==0)
     {printf("-1\n");return;}

    printf("%d\n",count);
}
void current_status(struct student* L, int k)
{
    int flag=0;int host=0; int count1=0,count2=0;
    struct student *temp=L;int i=0; int f=0;
    if((L)->next==NULL && ((L)->g_nbr==k))
    {printf("0 0\n");return;}
    if((L)->next==NULL && ((L)->g_nbr==k))
    {printf("-1\n");return;}
    while(L!=NULL)
    {
       
         if(L->g_nbr==k)
         {  f++;
             while(temp!=NULL)
             {
                 if(temp->g_nbr==flag)
                 {count1++;}
                 temp=temp->next;
                 break;
             }
         }
        L=L->next; 
         flag=L->g_nbr;
    }
     while(L!=NULL)
     {
         if(L->g_nbr==k)
         {
             host=L->g_nbr;
             while(L!=NULL)
             {if((L->g_nbr !=k )&&(i=0 || host==(L->g_nbr)))
              {
                  if(i==0)
                   {host=L->g_nbr;}
                   count2++;
              }
               L=L->next; 
             }
         }
        L=L->next; 
     }
     if(f==0)
     {printf("-1\n"); return;}
     printf("%d %d\n",count1,count2);
}
void collect_result(struct student** L)
{
    int flag=((*L)->g_nbr);
   // *L=(*L)->next;
    while((*L)!=NULL)
    {
        if((*L)->next->g_nbr==flag)
        {(*L)->next=(*L)->next->next;}
        *L=(*L)->next;
        if(flag!=(*L)->g_nbr)
        {flag=(*L)->g_nbr;}
    }
}
int main()
{
    struct student *L=NULL;
    char c;
    char space;
    int k;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'r': scanf("%c",&space);
                      read_student(&L);
                      break;
            case 'p': print_students(L);
                      break;
            case 'c': scanf("%c",&space);
                      scanf("%d",&k);
                      count_students(L, k);
                      break;
            case 's': scanf("%c",&space);
                      scanf("%d",&k);
                      current_status(L, k);
                      break;
            case 'f': collect_result(&L);
                      break;
            case 't': return 0;
        }
    }
}