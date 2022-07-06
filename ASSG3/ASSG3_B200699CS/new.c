#include<stdio.h>
void gift(int t,int a[],int m,int n, int s,int count[],int k[],int sp[])
{
 printf("%d ",t);
 int i; 
for(i=m;i<=n;i++)
{count[0]++;
    if(a[i]==s)
{ sp[k[0]]=t; k[0]++;}
    printf("%d ",a[i]);} 
printf("\n");
if(m<n)
{int mid=(m+n)/2;
gift(2*t,a,m,mid,s,count,k,sp);
gift((2*t)+1,a,mid+1,n,s,count,k,sp);}
}
int main()
{
int n; scanf("%d",&n);
int a[n]; int sp,i;
for(i=0;i<n;i++)
{scanf("%d",&a[i]);}
scanf("%d",&sp); 
int s[n];
int lo=0;
int count[]={0}; int k[]={0}; int t=1; int c;
gift(t,a,lo,n-1,sp,count,k,s);
c=k[0];
for(i=0;i<c;i++)
{printf("%d ",s[i]);}
printf("%d",count[0]+c);
return 0;
}