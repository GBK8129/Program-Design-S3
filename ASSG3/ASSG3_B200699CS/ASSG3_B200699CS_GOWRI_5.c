#include<stdio.h>
void InversionTracker(int DUP[], int n, int inversion[])
{
   int i,j;
   for(i=0;i<n;i++)
   {
      for(j=i+1;j<n;j++)
      {
         if(DUP[i]>DUP[j])
         {inversion[0]++;}
      }
   }
}
void Merge(int A[], int p, int q, int r,int count[])
{    
    int i,j,k,n1,n2;
    int inversion=0;
    n1=q-p+1;  n2=r-q;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
       { L[i] = A[p+i]; }
    for (j = 0; j < n2; j++)
       { R[j] = A[q+j+1]; }
    L[n1]=999000; R[n2]=999000; 
    i = 0; j = 0;  
    
    
    for(k=p;k<=r;k++)
    {   count[0]++; 
       if (L[i] <= R[j]) 
       {A[k] = L[i]; i+=1; }
       else 
       {A[k] = R[j]; j+=1; }
    }
}
void Merge_Sort(int A[], int p, int q,int count[])
{   if (p < q) 
    { int mid;
        mid=(q+p)/2;
       
        Merge_Sort(A,p, mid,count);
        Merge_Sort(A,mid+1,q,count);
        Merge(A,p,mid,q,count);    
    }
}
int main()
{  
   int n;
   scanf("%d",&n);
   int A[n],i;
   for(i=0;i<n;i++)
   {scanf("%d",&A[i]);}
   int p,q; p=0; q=n-1;
   int count[]={0}; 
   int DUP[n];
   int inversion[]={0};
   for(i=0;i<n;i++)
   {DUP[i]=A[i];}
   InversionTracker(DUP,n,inversion);
   printf("%d\n",inversion[0]);
   Merge_Sort(A, p, q,count);
   printf("%d",count[0]);
   return 0;
}