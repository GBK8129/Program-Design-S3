#include <stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int A[n],b,c,j,i,l;
  int temp,rev,digit,junk=9900;
  for(i=0;i<n;i++)
  {scanf("%d",&A[i]); }
  for(i=0;i<n;i++)
   {  j=0;l=8600;
   if(A[i]<0)
   {A[i]*=-1; l=i;}
       rev=A[i];
    do    
    {   digit=rev%10;
       rev/=10;
       j=(j*10)+digit; 
    }while(rev!=0);
    
    temp=j;
    while(temp!=0)
      { 
          b=temp%10;
          temp/=10;
          if(b<=(temp%10))
          {if(temp/10==0)
           {break;}
           else
             { continue;}}
          else
          { A[i]=junk;junk++;break; }
      }
      if(A[i]<9900 && l!=8600)
      {A[i]*=-1;}
  }
  j=0;
  for(i=0;i<n;i++)
  {if(A[i]<9900)
      {printf("%d ",A[i]);j++;}
  }
  if(j==0)
  {printf("-1");}
  return 0;
}