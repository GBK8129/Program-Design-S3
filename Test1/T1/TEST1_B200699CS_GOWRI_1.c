#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void read_students(char A[], int n)
{
    int i;
    for(i=0;i<=n;i++)
    {scanf("%c ",&A[i]);}
    
}
void print_students(char A[],int n)
{
     int i;
    for(i=0;i<=n;i++)
    {if(!isspace(A[i]))
        printf("%c ",A[i]);}
}
void arrange_students(char A[],int n)
{
    int i,j; char temp;
    for(i=1;i<n;i++)
    {   
        temp=A[i]; j=i-1;

        while(j>=0 && A[j]>temp)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
    char B[n];
    for(i=0;i<n;i++)
    {B[i]=A[n-i-1];}
    for(i=0;i<n;i++)
    {A[i]=B[i];}

}
void list_students(char A[],int n,int rval)
{
     int i,count=0; int k;
    for(i=0;i<=n;i++)
    {if(A[i]==rval)
    {count++;printf("%d ",i); continue;}
    }
    if(count==0)
    {printf("-1");}

}
int main()
{
    int n; char c;
     int rval;
    char A[100000];
    while(1)
     {
         scanf("%c",&c);
         switch(c)
         {
             case 'r': scanf("%d",&n);
                       read_students(A, n);
                       break;
             case 'p': print_students(A, n);
                       break;
             case 'a': arrange_students(A, n);
                       break;
             case 'l': scanf("%d",&rval);
                       list_students(A, n, rval);
                       break;
             case 't': return 0;
         }
     }
}