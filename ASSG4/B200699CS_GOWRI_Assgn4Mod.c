#include<stdio.h>
void Max_Heapify(int A[], int n, int i)
{
    int largest=i;  int temp; 
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if(l<n && A[l]>=A[largest])
       {
           largest=l; }
    if(r<n && A[r]>A[largest])
       {largest=r;}
   
    if (largest != i) 
    {   temp=A[i]; A[i]=A[largest]; A[largest]=temp;
        Max_Heapify(A,n,largest); }
}
void MAGIC(int A[],int n,int count[])
{ int i;
   Max_Heapify(A,n,0);
    count[0]+=A[0];
    for(i=0;i<n;i++)
    {printf("%d ",A[i]);}
    printf("\n");
    if(A[0]%2==0)
    {A[0]=A[0]/2;}
    else
    {A[0]=(A[0]-1)/2;}
    Max_Heapify(A,n,0);
}
void Heap_Increase(int A[],int i,int key)
{
  if(key<=A[i])
   {A[i]=key;  int temp;
  while (i>0 && A[(i-1)/2]<A[i]) 
  {temp=A[i]; A[i]=A[(i-1)/2]; A[(i-1)/2]=temp;
   i=(i-1)/2;}}
}
void MAX_HEAP_INSERT(int A[],int i)
{
   int temp; 
  A[i+1]=999000; //sentinel value
  scanf("%d",&A[i]);
  Heap_Increase(A,i,A[i]);
  
}
int main()
{
    int n,m; int A[n]; int i; int count[]={0};
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {MAX_HEAP_INSERT(A,i);}
   /* for(i=0;i<n;i++)
    {printf("%d ",A[i]);}
    printf("\n"); */
    for(i=0;i<m;i++)
    {MAGIC(A,n,count);}
    printf("%d",count[0]);
    return 0;
}