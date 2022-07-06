#include<stdio.h>
void Max_Heapify(int A[], int n, int i,int count[])
{
    int largest=i;  int temp;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l<n)
    {count[0]++;
    if (l<n && A[l]>A[largest])
       {largest=l; }}
    if(r<n)
    {count [0]++;
    if (r<n && A[r]>A[largest])
       {largest=r;}}
    if (largest != i) 
    {   temp=A[i]; A[i]=A[largest]; A[largest]=temp;
        Max_Heapify(A,n,largest,count); }
}
void Build_Max_Heap(int A[], int n,int count[])
{   int i;
    for(i=(n/2-1);i>=0;i--)
    { Max_Heapify(A,n,i,count); }
}
void Heapsort(int A[], int n,int count[])
{   Build_Max_Heap(A,n,count);
    int i; int temp;
    for(i=(n-1);i>=0;i--)
    {  temp=A[0]; A[0]=A[i]; A[i]=temp;
        Max_Heapify(A,i,0,count); }
}
int main()
{   
    int n; scanf("%d",&n);
    int A[n]; int count[]={0}; int i;
    for(i=0;i<n;i++)
    {scanf("%d",&A[i]);}
    Heapsort(A,n,count);
    for(i=0;i<n;i++)
    {printf("%d ",A[i]);}
    printf("\n%d",count[0]);
    return 0;
}