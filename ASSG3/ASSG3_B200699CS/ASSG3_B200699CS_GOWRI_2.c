#include<stdio.h>
int count=0;
int B_Search_Mod(int A[],int lo,int hi,int search)
{  
    count++;
    int mid;
    if (lo == hi)
    {if(search==A[lo])
    {return A[lo];}
    else
    { return -1;}}
    if(lo>hi)
    {return -1;}
  
    mid=(lo + hi)/2;   
    if(search==A[mid] && A[mid]==A[mid-1])
    {return B_Search_Mod(A, lo, mid-1, search); }
    
    
    else if (search == A[mid])
    {  return mid;}
 
    else if (search < A[mid]) 
    {  return B_Search_Mod(A, lo, mid - 1, search); }

    else 
    {  return B_Search_Mod(A, mid + 1, hi, search); }
  
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
    printf("%d\n",B_Search_Mod(A,lo,hi,search));
    printf("%d",count);
    return 0;
}