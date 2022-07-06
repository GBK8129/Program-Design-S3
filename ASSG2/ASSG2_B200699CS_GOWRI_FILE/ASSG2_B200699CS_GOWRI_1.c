#include<stdio.h>
int Subset(int A[], int F, int x, int n, int *l)
{  
     int i,j,k; int sum,max;
    max=F; 
    for(i=x+1;i<n;i=j)
    {  
         j=i+1; 
        if(max<A[i])
        { max+=A[i];(*l)++; }
        
        while(j<n)
        {
            k=max+A[j];
            if(max<k)
            {max=k;(*l)++;}
            j++;
        }
       return max;
    }
}
int main()
{  
     int n;
     scanf("%d",&n);
     int A[n],max[n],l[n];
     int i;
    
    for(i=0;i<n;i++)
    {scanf("%d",&A[i]);}

    for(i=0;i<n;i++)
    {l[i]=1;}
    
    for(i=0;i<n;i++)
    {max[i]=Subset(A,A[i],i,n,&l[i]);}
     
     max[n-1]=A[n-1];
    
     int out,pos=l[0]; out=max[0];
    
    for(i=1;i<n;i++)
       {   if(out<max[i])
             {out=max[i];pos=l[i];}
           else if (out==max[i])
             {out=max[i];
              if(pos<l[i])
              {pos=l[i];}
              }
       }
    
    printf("%d %d",out,pos);

   return 0;
}