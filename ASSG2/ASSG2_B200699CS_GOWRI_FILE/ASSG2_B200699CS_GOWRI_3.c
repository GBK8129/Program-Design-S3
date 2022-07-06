#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
   char str[1000];
   char comp[1000];
   char out[1000];
   char pos[1000];
   char mark;
   scanf("%999[^\n]%*c",str);
   scanf("%999[^\n]%*c",comp);
   int i,j,k=0;
   int flag;
  
   for(i=0;str[i]!='\0';i++)
   {
     
       for(j=0;(comp[j]!='\0')&&(comp[j+1]!='\0');j++)
       {if(j==0)
        {if(str[i]==comp[j] && str[i+1]==comp[j+1])
        { 
           pos[k]=i;
           k++;
           pos[k]=i+1;
           k++;
        }}
         else if(j>0)
         {
             if(str[i]==comp[j] && str[i+1]==comp[j+1] && pos[k-1]==i)
             {pos[k]=i+1;
             k++;
             }
         }
           
        }
     
    
   }

        for(i=0;str[i]!='\0';i++)
       { 
        for(j=0;j<k;j++)
        { if(i==pos[j])
        {
           str[i]='9';
        }}
       }
       j=0;
       for(i=0;str[i]!='\0';i++)
       { 
        if(str[i]!='9')
        {
            out[j]=str[i];
            j++;
        }
       }
     
   
   for(i=0;out[i]!='\0';i++)
   { 
      printf("%c",out[i]);}
 return 0;
}