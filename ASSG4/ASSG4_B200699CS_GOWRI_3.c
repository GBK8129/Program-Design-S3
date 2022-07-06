#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct W
{ char* Amoeba_Name; int Amoeba_Size;};
void Max_Heapify(struct W *x, int n, int i)
{
    int largest=i;  struct W temp; char p,q;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l<n && x[l].Amoeba_Size>x[largest].Amoeba_Size)
       {largest=l; }
    /* else if(x[l].Amoeba_Size==x[largest].Amoeba_Size)
      {for(i=0;x[l].Amoeba_Name[i]!='\0'&& x[largest].Amoeba_Name[i]!='\0';i++)
         {p=x[l].Amoeba_Name[i]; q=x[largest].Amoeba_Name[i];
           if(tolower(p)<tolower(q))
           {largest=l;break;}}} */
    if(r<n && x[r].Amoeba_Size>x[largest].Amoeba_Size)
       {largest=r;}
    /* else if(x[r].Amoeba_Size==x[largest].Amoeba_Size)
      {for(i=0;x[r].Amoeba_Name[i]!='\0'&& x[largest].Amoeba_Name[i]!='\0';i++)
         {p=x[r].Amoeba_Name[i]; q=x[largest].Amoeba_Name[i];
           if(tolower(p)>tolower(q))
           {largest=r;printf("UFFFFFFFFFF\n"); break;}}} */
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
int COMBINE(struct W *x, int n)
{ int i; char p,q;   int j; char m[21]; int a; int l=0;
  for(j=0;j<n;j++)
   {if(l==0)
    {printf("%s %s",x[l].Amoeba_Name,x[l+1].Amoeba_Name);
        a=x[l].Amoeba_Size+x[l+1].Amoeba_Size;
        printf(" %d\n",a); 
        strcpy(m,x[l].Amoeba_Name); i=x[l].Amoeba_Size;
        l=2;
       } 

    else if(l<n)
    { if(a>x[l].Amoeba_Size)
        { printf("%s %s",x[l].Amoeba_Name,m); 
                strcpy(m,x[l].Amoeba_Name); }    
      else if(a<x[l].Amoeba_Size)
      { printf("%s %s",m,x[l].Amoeba_Name);}
      else 
      { for(i=0;x[l].Amoeba_Name[i]!='\0'&& m[i]!='\0';i++)
         {p=x[l].Amoeba_Name[i]; q=m[i];
           if(tolower(p)<tolower(q))
            { printf("%s %s",x[l].Amoeba_Name,m);  
                strcpy(m,x[l].Amoeba_Name);break;}
           else if(tolower(p)>tolower(q))
            {printf("%s %s",m,x[l].Amoeba_Name); break;}}}
            a+=x[l].Amoeba_Size;
            printf(" %d\n",a); 
        l++;
    }}
   printf("%s",m);
    return a; 
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
    
    printf(" %d",COMBINE(H,n));
    return 0;
}