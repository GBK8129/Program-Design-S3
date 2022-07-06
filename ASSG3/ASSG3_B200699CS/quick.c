#include<stdio.h>
int partition(int A[],int low, int high,int count[])
{
    int pivot=A[high]; int temp;
    int i=(low-1); int j;
    for(j=low;j<=high;j++)
    {
        if(A[i]<pivot)
        {
            i++;
            temp=A[i]; A[i]=A[j]; A[j]=temp;
            count[0]++;
        }
    }
    temp=A[i+1]; A[i+1]=A[high]; A[high]=temp;
    return (i+1);
}
void quicksort(int A[], int low,int high,int count[])
{
    int p;
    if(low<high)
    {p=partition(A,low,high,count);
    quicksort(A,low,p-1,count);
    quicksort(A,p+1,high,count);}
}
void print(int A[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {printf("%d ",A[i]);}
    printf("\n");
}
int main()
{
    int n; scanf("%d",&n);
    int A[n]; int i;
    int count[]={0};
    for(i=0;i<n;i++)
    {scanf("%d",&A[i]);}
    int lo,hi; lo=0, hi=n-1;
    quicksort(A,lo,hi,count);
    print(A,n);
    printf("%d",count[0]);
    return 0;
}