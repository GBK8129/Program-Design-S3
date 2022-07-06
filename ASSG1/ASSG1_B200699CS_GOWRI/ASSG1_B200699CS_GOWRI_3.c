#include<stdio.h>
#include<ctype.h>
#include<string.h>
char Toggle(char X)
{
  if(isupper(X))
  {
     X=tolower(X);
     return X;
  }
  else if (islower(X))
  {
      X=toupper(X);
      return X;
  }
  else 
  {
      return X;
  }
  
}
int main()
{
    int i;
    char Str[10000];
    scanf("%[^\n]s",Str);
    for(i=0;Str[i]!='\0';i++)
    {
        Str[i]=Toggle(Str[i]);
    }
    printf("%s",Str);
    return 0;
}
