#include<stdio.h>
int IntersecPoint(int B[],int lo,int hi,int common)
{   
    int mid;
    if (lo > hi)
    {return 9900;}
   
    mid=(lo + hi)/2;   
    if (common == B[mid])
    {return B[mid];}
 
    else if (common < B[mid]) 
    {return IntersecPoint(B, lo, mid - 1, common);}

    else 
    {return IntersecPoint(B, mid + 1, hi, common);}
  
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int i; int A[m],B[n],C[m],D[n];
    for(i=0;i<m;i++)
    {scanf("%d",&A[i]);}
    for(i=0;i<n;i++)
    {scanf("%d",&B[i]);}
    int hi,lo;
    int count=0;
    for(i=0;i<n;i++)
    {if(B[i]>B[i+1])
    {count++;}}
    if(count!=0)
    {for(i=0;i<n;i++)
    {D[i]=B[n-1-i];}}
    else if(count==0)
    {for(i=0;i<n;i++)
    {D[i]=B[i];}}
    for(i=0;i<m;i++)
    {    hi=n-1;lo=0; 
        C[i]=IntersecPoint(D,lo,hi,A[i]);
    }
    int j;
    for(j=0;j<m;j++)
    {for(i=j+1;i<m;i++)
     {if(C[j]==C[i])
     {C[i]=9900;}}}
    
    for(i=0;i<m;i++)
    {   if(C[i]!=9900)     
     {printf("%d ",C[i]);}
    }
    return 0;
}