#include<stdio.h>
int recursive(int x, int y)
{  
    if (y==0||x==0)
    {
        return x;
    }
    else
    {
        recursive(x,y%x);
        
    }
    
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(a!=0&&b!=0)
    {
       if(a>b)
      {
        printf("%d",recursive(a%b,b));
      }
    else
      {
        printf("%d",recursive(b%a,a));
      }
    }
    
    return 0;
}
