#include<stdio.h>
int count=0;
int B_Search(int A[],int lo,int hi,int search)
{   count++;
    int mid;
    if (lo>hi)
    {return -1;}
   
    mid=(lo + hi)/2;   
    if (search == A[mid])
    {return mid;}
 
    else if (search < A[mid]) 
    {  
       return B_Search(A, lo, mid - 1, search);
    }

    else 
    {  
       return B_Search(A, mid + 1, hi, search);
    }
  
}
int main()
{
    int n;
    scanf("%d",&n);
    int i; int A[100000];
    for(i=0;i<n;i++)
    {scanf("%d",&A[i]);}
    int search;
    scanf("%d",&search);
    int hi,lo; hi=n-1;lo=0;
    printf("%d\n",B_Search(A,lo,hi,search));
    printf("%d",count);
    return 0;
}