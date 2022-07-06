#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct W
{ char* Amoeba_Name; int Amoeba_Size;};
int Compare(struct W a, struct W b)
{
	char p,q; 
	for(int i=0;a.Amoeba_Name[i]!='\0' && b.Amoeba_Name[i]!='\0';i++)
	{p=a.Amoeba_Name[i]; q=b.Amoeba_Name[i];
	 if(tolower(p)<tolower(q))
	 {return 1;}
	 else if(tolower(p)>tolower(q))
	 {return 0;}
	}
}
int Heap(struct W *x,int l)
{ struct W temp;
   while(l>0 && x[(l-1)/2].Amoeba_Size>=x[l].Amoeba_Size)
   {if(Compare(x[(l-1)/2],x[l])==0)
      {temp=x[(l-1)/2]; x[(l-1)/2]=x[l]; x[l]=temp;}
	  l=(l-1)/2;
   }
}
void Max_Heapify(struct W *x, int n, int i)
{
    int largest=i;  struct W temp; int k;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l<n && x[l].Amoeba_Size>x[largest].Amoeba_Size)
       {largest=l; }
     else if(x[l].Amoeba_Size==x[largest].Amoeba_Size)
      { k=Compare(x[l],x[largest]);
	     if(k==1)
           {largest=l;}} 
    if(r<n && x[r].Amoeba_Size>x[largest].Amoeba_Size)
       {largest=r;}
    else if(x[r].Amoeba_Size==x[largest].Amoeba_Size)
      {k=Compare(x[r],x[largest]);
	     if(k==0)
           {largest=r;}} 
    if (largest != i) 
    {   temp=x[i]; x[i]=x[largest]; x[largest]=temp;
        Max_Heapify(x,n,largest); }
}
void Build_Max_Heap(struct W *x, int n)
{   int i;
    for(i=(n/2-1);i>=0;i--)
    { Max_Heapify(x,n,i); }
}
void Heapsort(struct W *x, int n)
{   Build_Max_Heap(x,n);
    int i; struct W temp;
    for(i=(n-1);i>=0;i--)
    {  temp=x[0]; x[0]=x[i]; x[i]=temp;
        Max_Heapify(x,i,0); }}
void Heap_Increase(struct W *x,int i,struct W H)
{ char r,q; int j; int p; struct W temp;
  if(H.Amoeba_Size<=x[i].Amoeba_Size)
   {x[i]=H; p=(i-1)/2; 
  while (i>0 && (x[p].Amoeba_Size>x[i].Amoeba_Size ))
  {
  temp=x[i]; x[i]=x[p]; x[p]=temp; i=p; }
   }
}
void READ(struct W *x, int n)
{ int i;
for(i=0;i<n;i++)
{ x[i].Amoeba_Name = malloc(21); 
  scanf("%s",x[i].Amoeba_Name);
  scanf("%d",&x[i].Amoeba_Size);  
}
}
void INSERT( struct W *H, int k, struct W X,int i)
{ 
  int temp; int n=k; 
  H[k].Amoeba_Size=999000; //sentinel value
  H[k].Amoeba_Name='\0';
   Heap_Increase(H,i,X); 
}
void Remove(struct W *x, int n)
{
	x[0]=x[n-1];
	x[n-1].Amoeba_Size=9999000;
	x[n-1].Amoeba_Name='\0';
	Heapsort(x,n);
}
void COMBINE(struct W *x, int n)
{ int i; char p,q;   int j; char m[21]; int a; int l=0; struct W temp; temp=x[0]; int k;
 // for(j=0;j<n;j++)
   if(l==0) 
   {  printf("%s %s",x[0].Amoeba_Name,x[1].Amoeba_Name);
        a=x[l].Amoeba_Size+x[l+1].Amoeba_Size;
        printf(" %d\n",a); 
        l=2; 
    Remove(x,n);
	n-n-1;}
  // else if(l<n && l>1)
  // {
//	   Heapsort(x,n);
  // }
   COMBINE(x,n);
   /* { if(a<x[l].Amoeba_Size)
        { printf("%s %s",temp.Amoeba_Name,x[l].Amoeba_Name); a+=temp.Amoeba_Size; } 
      else if(a>x[l].Amoeba_Size)

     { printf("%s %s",x[l].Amoeba_Name,temp.Amoeba_Name);a+=x[l].Amoeba_Size;temp=x[l];}
      else 
      { k=Compare(temp,x[l]);
	      if (k==0)
           { printf("%s %s",temp.Amoeba_Name,x[l].Amoeba_Name);a+=temp.Amoeba_Size;}
           else if(k==1)
            {printf("%s %s",x[l].Amoeba_Name,temp.Amoeba_Name); 
            a+=x[l].Amoeba_Size; temp=x[l];}}
        printf(" %d\n",a); 
        l++;
    }} */
	if(l==n)
   printf("%s %d",temp.Amoeba_Name,a);
   // return a; 
}

int main()
{
    int n; scanf("%d",&n);
    struct W *a; struct W *H; 
    a=(struct W*)malloc(n*sizeof(struct W));
    H=(struct W*)malloc(n*sizeof(struct W));
    int i; 
    READ(a,n); 
    for(i=0;i<n;i++)
    {H[i]=a[i];}
    for(i=0;i<n;i++)
    {INSERT(H,n,H[i],i);}
    Heapsort(H,n);
    for(i=0;i<n;i++)
    {printf("%s %d || %s %d\n",a[i].Amoeba_Name,a[i].Amoeba_Size,H[i].Amoeba_Name,H[i].Amoeba_Size);}
    
    COMBINE(H,n);
    return 0;
}