#include<stdio.h>
int main()
{
    int m,n,A[10000],B[10000];
    int D[10000],E[10000];
    int i,j,k,flag=0;int junk=9800;
   
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {scanf("%d",&A[i]);}
    for(i=0;i<n;i++)
    {scanf("%d",&B[i]);}
    k=m;
    for(i=0;i<n;i++)
    {A[k]=B[i];
    k++;}
    k=(m+n);
    for(i=0;i<k;i++)
    {D[i]=A[i];}
       
    for(i=0;i<k;i++)
     {for(j=i+1;j<k;j++)
 
      {if(D[i]==A[j])
        { if(flag==0)
          {E[flag]=D[i];E[flag+1]=D[i];
           flag+=2;A[j]=junk;junk++;}
          else if(E[flag-1]!=D[i])
           {E[flag]=D[i];E[flag+1]=D[i];
            flag+=2;A[j]=junk;junk++;}
          else if(E[flag-1]==D[i])
            {E[flag]=D[i];
              flag++;
             A[j]=junk;junk++;}
     }
      else{continue;}
    }
    }
     

    for(i=0;i<flag;i++)
{
    int l=0;
    if(E[i]==E[i+1])
        { 
            i++;l++;
        }
    if((l==1)||(l==0))
    {for(j=0;j<k;j++)
    {
        if(E[i]==D[j])
        {D[j]=junk;junk++;}
        
    }}
}
    for(i=0;i<flag;i++)
    {printf("%d ",E[i]);}
    for(i=0;i<k;i++)
    {if(D[i]<9800)
       {printf("%d ",D[i]); }}
    
return 0;
}