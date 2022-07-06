#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct S
{  int Student_id; char *Student_name; int Rank; };
void Max_Heapify(struct S *x, int n, int i)
{   struct S temp; char p,q; int largest,l,r; 
    
     largest=i;  
     l = 2 * i + 1;
     r = 2 * i + 2;
    if (l<n && x[l].Rank<x[largest].Rank)
       {largest=l; }
    if(r<n && x[r].Rank<x[largest].Rank)
       {largest=r;}
        if (largest != i) 
    {   temp=x[i]; x[i]=x[largest]; x[largest]=temp;
        Max_Heapify(x,n,largest); }
}
void Build_Max_Heap(struct S *x, int n)
{   int i;
for(i=(n/2-1);i>=0;i--)
    { Max_Heapify(x,n,i); }
}
void Heapsort(struct S *x, int n)
{   Build_Max_Heap(x,n);
   int i; struct S temp;
     for(i=(n-1);i>=0;i--)
    {  temp=x[0]; x[0]=x[i]; x[i]=temp;
        Max_Heapify(x,n,i); }

   }
void Heap_Increase(struct S *x,int i,struct S H)
{  int p; struct S temp;
   if(H.Rank<=x[i].Rank)
   {x[i]=H; int p=(i-1)/2; 
  while (i>0 && x[p].Rank<x[i].Rank) 
  {temp=x[i]; x[i]=x[p]; x[p]=temp;
   i=p;}}
}
void Enter(struct S *x, int i)
{  int j; 
   x[i].Student_name=malloc(21);
   scanf("%d",&x[i].Student_id);
   scanf("%s",x[i].Student_name);
   scanf("%d",&x[i].Rank);  
  
    if(i>0)
    { 
       Heap_Increase(x,i,x[i]);
        }
  Max_Heapify(x,i,0);
 }
void Interview(struct S *x, int k)
{
    if(k<0)
    { printf("-1\n");}
    else
    { struct S Next;
      Next = x[0];
      x[0]=x[k]; 
      x[k].Rank=999000; x[k].Student_id=999000; x[k].Student_name='\0';
      k--;
      printf("%d %s\n",Next.Student_id,Next.Student_name); }
      Max_Heapify(x,0,k);
         
}
void List(struct S *X, int n)
{   int i;
    if(n<=0)
    {printf("-1\n");}
    else
    {
      for(i=0;i<n;i++)
        {printf("%d ",X[i].Student_id);}
        printf("\n");
    }
}
int main()
{   
    struct S *X; struct S *temp; int i=0; int n; 
    n=100000;
    X=(struct S*)malloc(n*sizeof(struct S));
    temp=(struct S*)malloc(n*sizeof(struct S));
    char m; 
    while(1)
    {
        scanf("%c",&m);
        switch(m)
        {
            case 'e': Enter(X,i);
                      i++;
                      break;
            case 'i': Interview(X,i-1);
                      --i;
                      Heapsort(X,i);
                      break;
            case 'l': Heapsort(X,i);
                      List(X,i);
                      break;
            case 't': return 0;
        }
    }
}