
#include<stdio.h>
#include<limits.h>
void store_details(int n,int A[],int B[])
{int junk=INT_MAX; 
 int s; s=A[0]; int pos[s]; int temp; 
int i,p,m,r,j; j=0;
for(i=0;i<n;i++)
{A[i]=junk; B[i]=junk;}
printf("%d",s);
for(i=0;i<s;i++)
{
    scanf("%d %d",&r,&m);
 p=(m+10)%n;

while(1)
 {if(A[p]==junk)
   {A[p]=r;B[p]=m; pos[i]=p;
      break;}
   else
   {if(m<B[p])
    {temp=m;
    m=B[p]; B[p]=temp;
     temp=r;
    r=A[p]; A[p]=temp;
    p++;}
     else
     {p++;}
   }
 }
}
for(i=0;i<s;i++)
{printf("%d\n",pos[i]);}
}
void display_marks(int A[],int B[],int n)
{   
    int i; int junk=INT_MAX; 
    for(i=0;i<n;i++)
    {if(A[i]!=junk)
    {printf("%d %d\n",A[i],B[i]);}
    }   
}
 int main()
 { int n,s;
 scanf("%d",&n);
 scanf("%d",&s);
 if(s>n)
 {n=s;}
 int A[1000],B[1000];
 A[0]=s;
 store_details(n, A, B);
 display_marks(A, B, n); 
 return 0;}