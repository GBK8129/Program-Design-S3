#include<stdio.h>
#include<stdlib.h>
struct Node
{char info; struct Node *Next;};
struct Node* List_Search(struct Node** L, struct Node *x)
{  //struct Node *k;
   char k=x->info;
   x=*L;
   while(x!=NULL)
    {
        if(x->info==k)
          { return x; }
        x=x->Next;
    }
    return NULL;
}
void List_Insert_Front(struct Node** L, struct Node* x)
{
    x->Next=*L; *L=x;
}
void List_Insert_Tail(struct Node** L, struct Node *x)
{ 
    struct Node *i;
    i=*L;
    while (i->Next != NULL)  
        { i=i->Next; }  
        i->Next = x;  x->Next = NULL;
}
void List_Insert_After(struct Node** L, struct Node *x, char y)
{
    struct Node *temp;
    temp->info=y; struct Node *ret;
    ret=List_Search(L,temp);
  //  x->Next=ret->Next;
   // ret->Next=x;
  /*  struct Node* j; 
    struct Node* i; 
   // i=ret->Next; */
    while((*L)!=NULL)
    {printf("IN\n");
        if((*L)->info==y)
          { break; }
          (*L)=(*L)->Next;
    }
    temp=(*L)->Next;
    (*L)->Next=x; x->Next=temp;
     //x->Next=ret; 
   // x->Next=ret->Next->Next;
  /*   j->Next=x;
     x->Next=i;
     printf("SEG\n");
    // i->Next = x;  
    *L=j;
    //return i;
      while (*L!=NULL) 
    {
         printf("%c ",(*L)->info); (*L)=(*L)->Next;
    } */
        
}
void List_Insert_Before(struct Node** L, struct Node *x, char y)
{
    struct Node *temp;
    temp->info=y; struct Node *ret; struct Node *i;
    i=*L;
    ret=List_Search(L,temp);
    while((*L)!=NULL)
    {   
        if((*L)->Next->info==ret->info)
          { break; }
          *L=(*L)->Next;
    }
    (*L)->Next=x;
     x->Next=ret;
    //ret=ret->Next;
   // i->Next=x;
   // x->Next=ret;
   // return i;
    //*L=i;
    //x->Next = ret->Next; ret->Next = x;
    
}
void List_Delete(struct Node** L, struct Node *x)
{
    if(*L==NULL)
    {printf("-1\n"); return;}
    char y; 
    scanf("%c",&y);
    x->info=y;x->Next=NULL;
    struct Node *ret;
    struct Node *temp;
    struct Node *k;
   // struct Node *temp = *head_ref, *prev;
    
    ret=List_Search(L,x);
    if((*L)->info==y)
    {k=*L;
    (*L) = k->Next;
    k->Next = NULL;  return;}
    k=*L;
    if (k!=NULL && k->info == ret->info && k->info==y) 
    {  (*L) = k->Next; free(k); return; }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (k!=NULL)
    {if (k->info!=ret->info && k->info!=y) 
    {   temp=k;k=k->Next; }}
 
    // If key was not present in linked list
    if (temp != NULL)
        {temp->Next=k->Next;free(temp);}
    else {return;}
    // Unlink the node from linked list
    
 
    
    /*
    int flag=0;
    if((*L)->info==y)
    {k=*L;
    (*L) = k->Next;
    k->Next = NULL; return;}
    
    printf("ERROr\n");
    temp=ret->Next;
    while(*L!=NULL)
    {   
        if((*L)->Next->info==ret->info)
        {break;}
        *L=(*L)->Next;
    }
    (*L)->Next=temp; */
  //  struct Node *i;
   // i=*L;
    //if(ret->Next->Next==NULL)
    //{ret=NULL;}
    //else
    //{
   /* if(i->info==y)
    {   temp=i->Next;
        free(i);
        //i=NULL; 
        i=temp;} */
  //  else{
  /*  while(*L!=NULL)
    {
        if((*L)->Next->info==y)
          { (*L)->Next=temp;
              break; }
          (*L)=(*L)->Next;
    }*/
  //  ret->Next=temp;;
   // i=ret;
 //   }   
  // *L=i; 
}
void List_Delete_First(struct Node** L)
{
    if(*L==NULL)
    {printf("-1\n"); return;}
    struct Node *k;
    printf("%c\n",(*L)->info);
    k=*L;
    (*L) = k->Next;
    k->Next = NULL;
}
void List_Delete_Last(struct Node** L)
{
    if(*L==NULL)
    {printf("-1\n"); return;
    }
    struct Node *k; 
    struct Node *j; 
    char temp;
  //  printf("ERROR\n");
   //k = *L;
    //struct Node *x; x=*L; *L=NULL;
   // x=k->Next->Next;
   /*while((*L)!= NULL)
     {  
         if((*L)->Next==NULL)
           {(*L)=NULL;break;}
        *L=(*L)->Next; */
          /*if((k)->Next->Next==NULL)
         {(k)->Next=NULL; break;}
         (k)=k->Next; */
     //}  
        // free(*L);
   // (*L)->Next=NULL;
    //return *L;
  /*  while((*L)->Next->Next != NULL)
    {k=*L; (*L)=(*L)->Next;k=k->Next;}
    k->info=(*L)->info;
    k->Next=NULL;*/
      if((*L)->Next == NULL)
      { k=*L; *L=NULL; printf("%c\n",k->info); free(k); }
      else
      { j=*L; k=(*L)->Next;
    	while(k->Next != NULL)
    	 { j=k; k=k->Next; }
    	j->Next=NULL; printf("%c\n",k->info); free(k);
      }
    	
    
  
}
void Print_List(struct Node* L)
{
    while (L!=NULL) 
    {
         printf("%c ",L->info); L=L->Next;
    }
}
void Create_Node(struct Node** x,char in)
{  //char in;   
   //x=(struct Node*)malloc(sizeof(struct Node));
   struct Node *temp;
   temp=(struct Node*)malloc(sizeof(struct Node));
   temp->info = in; temp->Next = NULL;
   *x=temp;
}
int main()
{
    char c; 
    struct Node *L; 
    struct Node *New;
    L=NULL; char in;
    char space;
    char Aft,Bef;
    while(1)
    {   
        scanf("%c",&c);
        switch(c)
          {
              case 'f': scanf("%c",&space);
                        scanf("%c",&in);
                        Create_Node(&New,in);
                        List_Insert_Front(&L, New);
                        break;
              case 't': scanf("%c",&space);
                        scanf("%c",&in);
                        Create_Node(&New,in);
                        List_Insert_Tail(&L, New);
                        break;
              case 'a': //struct Node *Aft;
                        //char Aft;
                        scanf("%c",&space);
                        scanf("%c",&in);
                        Create_Node(&New,in);
                        scanf("%c",&space);
                        scanf("%c",&Aft);
                        List_Insert_After(&L, New, Aft);
                        break;
              case 'b': //struct Node *Bef;
                        //char Bef;
                        scanf("%c",&space);
                        scanf("%c",&in);
                        Create_Node(&New,in);
                        scanf("%c",&space);
                        scanf("%c",&Bef);
                        List_Insert_Before(&L, New, Bef);
                        break;
              case 'd': scanf("%c",&space);
                        List_Delete(&L, New);
                        break;
              case 'i': List_Delete_First(&L);
                        break;
              case 'l': List_Delete_Last(&L);
                        break;
              case 'p': Print_List(L);
                        printf("\n");
                        break;
              case 'e': return 0; //exit
          }

    }
  
}