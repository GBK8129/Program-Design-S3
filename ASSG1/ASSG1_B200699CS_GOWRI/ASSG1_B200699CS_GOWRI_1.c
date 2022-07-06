#include<stdio.h>
int ToDecimal( float k)
{    
    int temp,digit,oct1=0,oct2=0;
    float f;
    temp=(int) k;
    int i=0,j=1,power=1;
    while(temp!=0)
    {
       digit=temp%10;

       while(j<=i)
       {power=power*8;
        j++;}
       oct1+=digit * power;
       temp/=10;
       i++;
    }
    i=-1;
    f=k-temp; j=-1;power=1;
    while(temp!=0)
    {
        f=f*10;
        temp=(int) f;
        while(j>=i)
        {power=power/8;
        j--;}
        oct2+=temp * power;
        i--;
        f=f-temp;
    }
    return oct1+oct2;
}
int main()
{
    float n;
    scanf("%f",&n);
    printf("%d",ToDecimal(n));
    return 0;

}