#include<stdio.h>
#include<string.h>
int c(char p, char q)
{
    int i,j,m=0,n=0,count=0;
    for(i=0;p[i]!='\0';i++)
     {m++;}
     for(i=0;q[i]!='\0';i++)
     {n++;}

    if(strcmp(p,q)==1)
    { 
        for (i=0;p[i]!='\0';i++)
        {printf("%s",p[i]);} printf(" ");
        for (i=0;q[i]!='\0';i++)
        {printf("%s",q[i]);} printf(" ");
        
        return 2;
    }
    else
    {if(n==m)
    {for(i=0;1;i++)
     {  if(p[i]>q[i])
          {for(j=0;j<m;j++)
          {printf("%s",q[i]);} printf(" ");
          return 1; break;}
        else if (p[i]<q[i])
          {for(j=0;j<m;j++)
          {printf("%s",p[i]);} printf(" ");
          return 0; break;}
     }}
    else if(n<m)
    {for(i=0;i<n;i++)
     {  if(p[i]>q[i])
          {for(j=0;j<m;j++)
          {printf("%s",q[i]); count++;} printf(" ");
          return 1; break;}
        else if (p[i]<q[i])
         { for(j=0;j<n;j++)
          {printf("%s",p[i]);count++;} printf(" ");
          return 0;break;}
    }}
     else if(n>m)
    {for(i=0;i<n;i++)
     {  if(p[i]>q[i])
          {for(j=0;j<m;j++)
          {printf("%s",q[i]); count++;} printf(" ");
          return 1; break;}
        else if (p[i]<q[i])
         { for(j=0;j<n;j++)
          {printf("%s",p[i]);count++;} printf(" ");
          return 0;break;}
      
     }}
     if(count==0)
     {if(n>m)
       {for(j=0;j<m;j++)
          {printf("%s",q[i]);} printf(" ");
          return 1; break;}
      else if(n<m)
      {
          for(j=0;j<n;j++)
          {printf("%s",p[i]);} printf(" ");
          return 0; break;
      }
       }
     
     
     
     }

5
10
180010 50
180011 34
180012 25
180013 59
180014 12
180015 29
180016 40
180017 24
180018 56
180019 47

}
int main()
{
    int n; scanf("%d",&n);
    int str[n][10]; int i,j=0;
    
    for(i=0;i<n;i++)
    {scanf("%[^\n]s",str[i]);}
    int val;
    val=c(str[0],str[1]);
    i=2,j=3;
    if(val==2)
    {val=c(str[i],str[j]);}
    else if(val==)
    i++;j++;

     
    
}