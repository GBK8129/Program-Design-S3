#include<stdio.h>
int partition(int A[],int low, int high,int count[])
{
    int pivot=A[low]; int temp;
    int i=(low); int j=high;
    while(i<j)
    { 
        do
        {
          i++; 
        } while(A[i]<=pivot && ++count[0]);
        do
        {
            j--;;
        } while (A[j]>pivot && ++count[0]);
        
        if(i<j)
        {
            temp=A[i]; A[i]=A[j]; A[j]=temp;
            count[0]++;
        }
    }
    temp=A[low]; A[low]=A[j]; A[j]=temp; 
    return j;
}
void quicksort(int A[], int low,int high,int count[])
{
    int p;
    if(low<high)
    {p=partition(A,low,high,count);
    quicksort(A,low,p,count);
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
    int lo,hi; lo=0, hi=n;
    quicksort(A,lo,hi,count);
    print(A,n);
    printf("%d",count[0]);
    return 0;
}