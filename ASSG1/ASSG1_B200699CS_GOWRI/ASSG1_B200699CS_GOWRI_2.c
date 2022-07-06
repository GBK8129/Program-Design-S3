#include <stdio.h>

int main()
{
   int A[10000],n;
   scanf("%d",&n);
   int l=0,flag=0;
   int i,count; int junk=99000;
   for(i=0;i<n;i++)
   {
       scanf("%d",&A[i]);
   }
   int k;
   for(i=0;i<n;i++)
   {   count=1;k=0;
       for(int j=i+1;j<n;j++)
       {
           if(A[i]==A[j])
           { 
            if(l!=0)
            {printf("\n");}
            if(k==0)
             {printf("%d %d ",A[i],i);k++;
                 
             }
            count++;
            A[j]=junk; junk++;
            printf("%d ",j);
            
           }
           else
           {continue;}
           
        
           
       }
      if(count!=1)
      {  printf("%d",count);
       l++;}
   }
   if(l==0)
   {printf("-1");}
   return 0;
}
