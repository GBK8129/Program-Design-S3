#include<stdio.h>
int main()
{
    int n,num,temp,digit;
    scanf("%d",&n);
    num=n;
    temp=0;
    do
    {
       digit = num % 10;
       temp = (temp * 10) + digit;
       num /= 10; 
    } while (num!=0);
   if (temp == n)
   { printf("YES");
   }
   else
   { printf("NO");
   } 
   return 0;
} 