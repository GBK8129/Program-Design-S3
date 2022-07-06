#include<stdio.h>
 #include<ctype.h>
 #include<string.h>
 void  *Toggle_Move(char *str)
 {
    int i;
    for(i=0;str[i]!='\0';i++)
   {if(isupper(str[i]))
  {
     str[i]=tolower(str[i]);
     
  }
  else if (islower(str[i]))
  {
    str[i]=toupper(str[i]);
      
  }
  else 
  {
     continue;
  }
 }
 }

 void Merger_Reverse_String(char str1[], char str2[])
 {
 char rev[1000];
 char mer[10000];
 int i,j=0,k=0;
 for(i=0;str1[i]!='\0';i++)
 {
     rev[i]=str1[i];j++;
 }
 k=j;
 for(i=j;str2[i]!='\0';i++)
 {rev[i]=str2[i];k++;}
 
 for(i=0;i<k;i++)
 {mer[i]=rev[k-i];}
 for(i=k-j;i<k;i++)
 {printf("%s",mer[i]);}
 printf("\n");
 for(i=0;i<k-j-1;i++)
 {printf("%s",mer[i]);}
 }

int main()
{int n,i;
 char str1[1000];
 char str2[1000];
 scanf("%d",&n);
 
for(i=0;i<n;i++)
{
    
    fgets(str1,1000,stdin);
    fgets(str2,1000,stdin);
    Toggle_Move(str1);
    Toggle_Move(str2);
    Merger_Reverse_String(str1, str2);


}
return 0;
}