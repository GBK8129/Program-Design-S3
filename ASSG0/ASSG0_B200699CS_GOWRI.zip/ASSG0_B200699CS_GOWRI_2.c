#include<stdio.h>
int PALINDROM(int x)
{ int num,digit,temp=0;
   num=x;
   do
   {
      digit=num%10;
      temp=(temp*10)+digit;
      num/=10;
   } while (num!=0);
    if (x==temp)
        return 1;
    else 
      {return 0;}
   }
int main()
{
    int n,a[10000],sum,count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    { scanf("%d",&a[i]);
    sum=PALINDROM(a[i]);
    count+=sum;}
    printf("%d",count);
    return 0;
}