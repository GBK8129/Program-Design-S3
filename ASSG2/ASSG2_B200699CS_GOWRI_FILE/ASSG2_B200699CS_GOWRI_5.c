#include<stdio.h>
int MaxSubset(int A[], int s, int n)
{  
     int i, t, k;
     
  for (i = 1; i < n; i++)
    {
      t = A[i];
      k = i - 1;
      while (t < A[k] && k >= 0)
	{
	  A[k + 1] = A[k];
	  k--;
	}
      A[k + 1] = t;

    }
    int max=0;
    for(i=0;i<s;i++)
    {max+=A[n-1-i];}
    return max;
}
int MinSubset(int A[], int s, int n)
{   

  int i, t, k;
     
  for (i = 1; i < n; i++)
    {
      t = A[i];
      k = i - 1;
      while (t < A[k] && k >= 0)
	{
	  A[k + 1] = A[k];
	  k--;
	}
      A[k + 1] = t;

    }
    int min=0;
    for(i=0;i<s;i++)
    {min+=A[i];}
    return min;
}

int main()
{
    int n,m; int s;
    scanf("%d %d",&n,&m);
    s=n-m;
    int A[n]; int i; int max[1000],min[1000];
    for(i=0;i<n;i++)
    {scanf("%d",&A[i]);}
    
     int maxout, minout;
   
        maxout=MaxSubset(A,s,n);
        minout=MinSubset(A,s,n);
    printf("%d",(maxout-minout));
    return 0;
    
}