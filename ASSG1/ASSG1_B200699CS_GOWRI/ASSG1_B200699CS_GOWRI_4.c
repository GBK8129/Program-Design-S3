#include <stdio.h>
int CONVERT(int x)
{
    int b=0,digit,i,rev;
    i=0;rev=0;
    do
    {
        digit=x%2;
        b=(b*10)+digit;
        x/=2;i++;
        }while(x!=0);
   
    int num,temp;
    num=b;
    do
    {
        temp=num%10;
        rev=(rev*10)+temp;
        num/=10;
        i--;
    }while(i!=0);
    printf("%016d\n",rev);
    return rev;
}
int main()
{
    int n,k;
    int i=0; int rev; int A[16],B[16];int digit;
    scanf("%d %d",&n,&k);
     rev=CONVERT(n);
    while(rev!=0)
    {digit=rev%10;
        A[i]=digit;
        rev/=10;i++;
    }
    int j;
    for(j=0;j<16-i;j++)
    {B[j]=0;} int x,y; y=i-1;
    for(x=j;x<16;x++)
    {B[x]=A[y];
        y--;
    }
 
   
    for(j=k;j<16;j++)
    {printf("%d",B[j]);}
    for(j=0;j<k;j++)
    {printf("%d",B[j]);}
    printf("\n");
    for(j=16-k;j<16;j++)
    {printf("%d",B[j]);}
    for(j=0;j<16-k;j++)
    {printf("%d",B[j]);}
return 0;
}

