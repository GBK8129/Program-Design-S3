#include <stdio.h>
int Hex(int x)
{int h=0;
    while(x!=0)
    {h+=x%16;
        x=x/16;
        }
       return h;
}
int HCF(int x,int y)
{
    if(x>=y)
    {if(x%y==0)
    {return y;}
    else
    {HCF(x%y,y);}}
    else if(x<y)
    {if(y%x==0)
    {return x;}
    else
    {HCF(y%x,y);}
    }
}
int main()
{
  int n; int x; int c;
  scanf("%d",&n); int temp;
  int l[n],r[n]; int count[n];
  int i,j;
  for(i=0;i<n;i++)
  {scanf("%d %d",&l[i],&r[i]); 
   count[i]=0;}
   for(i=0;i<n;i++)
   {
       if(l[i]>r[i])
       {temp=l[i]; l[i]=r[i]; r[i]=temp;}
   }
  for(i=0;i<n;i++)
  {
      for(j=l[i];j<=r[i];j++)
      {
        x=Hex(j);
        c=HCF(j,x);
        if(c>1)
        {count[i]++;}
      }
  }
  for(i=0;i<n;i++)
  {printf("%d\n",count[i]);}
      return 0;
}