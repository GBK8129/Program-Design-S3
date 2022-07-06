#include<stdio.h>
void Max_Heapify(int A[], int n, int i)
{
    int largest=i;  int temp;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l<n && A[l]>A[largest])
       {largest=l; }
    if(r<n && A[r]>A[largest])
       {largest=r;}
    if (largest != i) 
    {   temp=A[i]; A[i]=A[largest]; A[largest]=temp;
        Max_Heapify(A,n,largest); }
}
 void Build_Max_Heap(int A[], int n)
{   int i;
    for(i=(n/2-1);i>=0;i--)
    { Max_Heapify(A,n,i); }
}
void Heapsort(int A[], int n)
{   Build_Max_Heap(A,n);
    int i; int temp;
    for(i=(n-1);i>=0;i--)
    {  temp=A[0]; A[0]=A[i]; A[i]=temp;
        Max_Heapify(A,i,0); }
} 
void Heap_Increase(int Q[],int i,int key)
{
  if(key<=Q[i])
   {Q[i]=key; int p=(i-1)/2; int temp;
  while (i>0 && Q[p]>Q[i]) 
  {temp=Q[i]; Q[i]=Q[p]; Q[p]=temp;
   i=p;}}
}

void Insert_Patient(int Q[], int k)
{ int temp; int n=k; 
  Q[k]=999000; //sentinel value
  scanf("%d",&Q[k]);
  Heap_Increase(Q,k,Q[k]);
}
int Get_Next_Patient(int Q[],int k)
{ if(k<0)
   {return -1;}
 return Q[0];
}
int Extract_Next_Patient(int Q[],int k)
{
  if(k<0)
    {return -1;}
  int MaxPrio = Q[0];
   Q[0]=Q[k]; 
   Q[k]=999000; // sentinel value 
   k--;
  Max_Heapify(Q,k,0);
  return MaxPrio;
}
void Change_Token_Number(int Q[], int n,int k, int x)
{ int temp; int i=0;
  while(i<n)
  {if(Q[i]==k)
       {Q[i]=x;break;}
    i++;
  }
  
  if(x>k)
  {Heap_Increase(Q,i,Q[i]);}
  else
  {Max_Heapify(Q,n,i);}
 
}
void Display_Queue(int Q[], int k)
{int i;
if(k<=0)
{printf("-1");}
else
  {for(i=0;i<k;i++)
  {printf("%d ",Q[i]);}}
  printf("\n");
}
int main()
{
  char c; int Q[1000000]; int k=0; int n; int old,new;
  while(1)
  {
      scanf("%c",&c);
      switch(c)
      {
          case 'i': k+=1;
                    Insert_Patient(Q,k-1);
                    break;
          case 'e': Heapsort(Q,k);
                    printf("%d\n",Extract_Next_Patient(Q,k-1));
                    --k;
                    break;
          case 'm': printf("%d\n",Get_Next_Patient(Q,k));
                    break;
          case 'c': scanf("%d %d",&old,&new);
                    Change_Token_Number(Q,k,old,new);
                    break;
          case 'd': Heapsort(Q,k);
                    Display_Queue(Q,k);
                    break;
          case 's': return 0;
      }
  }
}