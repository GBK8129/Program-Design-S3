#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Compare(char P[],char Q[])
{int i,j=0,k=0,l,m,count=0; char str[100];
    for(i=0;P[i]!='\0';i++)
    {j++;}
    for(i=0;Q[i]!='\0';i++)
    {k++;}
    if(j==k)
    {for(i=0;i<j;i++)
    {if (P[i]>Q[i])
      { count++;
          for(l=0;l<j;l++)
       {str[l]=Q[l];} str[j]=' '; return 1; }
       if(count!=0)
       {break;} 
      else if(P[i]<Q[i])
       { count++;
          for(l=0;l<j;l++)
       {str[l]=P[l];} str[j]=' ';return 0;  }
       if(count!=0)
       {break;} 
      
      else if(P[i]==Q[i])
      {continue;}
    
    }}
    else if(j>k)
    {for(i=0;i<k;i++)
    {if(P[i]>Q[i])
      { count++;
          for(l=0;l<k;l++)
       {str[l]=Q[l];}  str[k]=' ';return 1; }
       if(count!=0)
       {break;} 
        
      else if(P[i]<Q[i])
       { count++;
          for(l=0;l<j;l++)
       {str[l]=P[l];}  str[j]=' ';return 0; }
       if(count!=0)
       {break;} 
      
      else if(P[i]==Q[i])
      {continue;}}}
    
    else if(j<k)
     {for(i=0;i<j;i++)
    {if(P[i]>Q[i])
      { count++;
          for(l=0;l<k;l++)
       {str[l]=Q[l];} str[k]=' '; return 1; break;}
        
      else if(P[i]<Q[i])
       { count++;
          for(l=0;l<j;l++)
       {str[l]=P[l];}  str[j]=' ';return 0; break;}
      
      else if(P[i]==Q[i])
      {continue;}}}
    if(count==0)
    {if(j>k)
     {
          for(l=0;l<k;l++)
       {str[l]=Q[l];} str[k]=' ';return 1;  }
       else if(j<k)
        {
          for(l=0;l<j;l++)
       {str[l]=P[l];} str[j]=' '; return 0;  }
       else if(j==k)
       {
            for(l=0;l<j;l++)
       {str[l]=P[l];} str[j]=' ';
       for(l=j+1;l<(2*k);l++)
       {str[l]=P[count];count++;} str[j]=' '; return 2; }
       }

        
     for(i=0;str[i]!='\0';i++)
     {printf("%c",str[i]);}
    

}
int main()
{
    int N;
    scanf("%d",&N);
    char initial[500];
  
    scanf("%[^\n]s",initial);
      int i,j=0,r;
    char Pi[100];
    char Pj[100];
    char Pk[100];
    char Pl[100]; 
    
    for(i=0;initial[j]!=' ';i++)
       {
           Pi[i]=initial[i];j++;
       }
       j=j+1;
    for(i=0;initial[j]!=' ';i++)
     {
         Pj[i]=initial[j];j++;
     }
     j=j+1;
     for(i=0;i<100;i++)
     {Pk[i]='\0';Pl[i]='\0';}
    
     r=Compare(Pi,Pj); //1st
     for(i=1;i<=N;i++)
     {
         for(i=0;i<100;i++)
     {Pk[i]='\0';Pl[i]='\0';}
     
     if(r==1)
     {       
       for(i=0;initial[j]!=' ';i++)
       {
           Pk[i]=initial[j];j++;
       }
       j=j+1;
        for(i=0;Pi[i]!='\0';i++)
     {
         Pl[i]=Pi[i];
     }
     r=Compare(Pk,Pl); continue;
     }
     else if(r==0)
     {
     for(i=0;initial[j]!=' ';i++)
       {
           Pk[i]=initial[j];j++;
       }
       j=j+1;
        for(i=0;Pj[i]!='\0';i++)
     {
         Pl[i]=Pj[i];
     }
     r=Compare(Pk,Pl);continue;
     }
   
     else if(r==2)
     {
     for(i=0;initial[j]!=' ';i++)
       {
           Pk[i]=initial[j];j++;
       }
       j=j+1;
        for(i=0;Pj[i]!='\0';i++)
     {
         Pl[i]=initial[j];j++;
     }
     j=j+1;
     r=Compare(Pk,Pl);
     }}
     if(i==N+1)
     {if(r==1)
     {
       for(i=0;Pk[i]!='\0';i++)
       {printf("%c",Pk[i]);}
       
     }
     else if(r==0)
     {
       for(i=0;Pl[i]!='\0';i++)
       {printf("%c",Pl[i]);}
       
     }
     }
     
return 0;

}