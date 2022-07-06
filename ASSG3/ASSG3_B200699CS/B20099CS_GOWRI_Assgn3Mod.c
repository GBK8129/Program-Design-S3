#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void GAME(int A[], int n, int s)
{ int j; int C[n]; int k=0; int m; m=n; int i=1,t; int B[n]; int l=0;
    while(i<=n)
    {
        printf("%d ",i);
        for(j=0;j<m;j++)
        {printf("%d ",A[j]); l++;
        if(A[j]==s)
         {B[k]=i; k++;} } printf("\n");
         
          if (m%2==0)
            {m/=2;}
          else
            {m=(m/2)+1;}
        i*=2;
        if (m==1)
          { printf("%d ",i); l++;
           printf("%d " ,A[m-1]); C[l]=i;l++; printf("\n");
           if (A[m]==s)
            {B[k]=i;
            k++;}
           printf("%d ",++i); l++;
           printf("%d ", A[m]); printf("\n");
            if (A[m+1]==s)
            {B[k]=i;
            k++;} }}
        m=n/2; i=3;
        while(i<n)
        { printf("%d ",i);
        for(j=m;j<n;j++)
        {printf("%d ",A[j]); l++;
        if(A[j]==s)
         {B[k]=i; k++;} } printf("\n");
         
          if (m%2==0)
            {n=(n-m)/2;}
          else
            {n=((n-m)/2)+1;}
        i+=2;
        if (m==n)
          { printf("%d ",i); l++;
           printf("%d " ,A[m+1]); C[l]=i;l++; printf("\n");
           if (A[m]==s)
            {B[k]=i;
            k++;}
           printf("%d ",++i); l++;
           printf("%d ", A[m]); printf("\n");
            if (A[m+1]==s)
            {B[k]=i;
            k++;} }}
      
        printf("%d",l);
        
    }

 

int main()
{
    int n; scanf("%d",&n);
    int A[n]; int i; 
    for(i=0;i<n;i++)
    {scanf("%d",&A[i]);}
    int s; scanf("%d",&s);
    GAME(A,n,s);
    return 0;
}