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
int partition(char A[],int hi, int rval)
{
    char pivot; char temp;
    pivot=rval+64;
    char B[100000];
    int i=0; int j=hi; int count;
    while(i<j)
    {  count=0;
        if(islower(A[i]))
        {toupper(A[i]);count=1;}
        if(islower(A[j]))
        {toupper(A[j]);count=2;}
        do
        {
          i++; 
        } while(A[i]<=pivot);
        do
        {
            j--;;
        } while (A[j]>pivot);
        if(count==1)
        {tolower(A[i]);}
         if(count==2)
        {tolower(A[j]);}
        
        if(i<j)
        {
            temp=A[i]; A[i]=A[j]; A[j]=temp;
            
        }

    }
    temp=A[0]; A[0]=A[j]; A[j]=temp; 
    int n=hi;
    for(i=0;i<n;i++)
    {B[i]=A[n-i-1];}
    for(i=0;i<n;i++)
    {A[i]=B[i];}
    return j;
}

int divide_students(char A[],int n,int rval)
{
     int p; int i;
    p=partition(A,n,rval);
    return p;
    

}
void arrange_students(char A[],int n,int pos)
{   
    int i,j; char temp; char B[n]; int k=0;
    for(i=0,j=pos;i<pos,j<n;i++)
    {   
        B[k]=A[i]; k++;
        B[k]=A[j]; k++;
    }
   
    for(i=0;i<n;i++)
    {A[i]=B[i];}

}
void list_students(char A[],int n,int rval)
{
     int i,count=0; int k;
    for(i=0;i<=n;i++)
    {  
        if(A[i]==rval)
    {count++;printf("%d ",i); continue;}
    }
    if(count==0)
    {printf("-1");}

}
int main()
{
    int n; char c;
     int rval; int pos;
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
             case 'a': arrange_students(A, n, pos );
                       break;
             case 'l': list_students(A, n, rval);
                       break;
             case 'd': scanf("%d",&rval);
                       pos=divide_students(A, n, rval);
                       break;
             case 't': return 0;
         }
     }
}