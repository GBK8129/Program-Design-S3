#include<stdio.h>
#include<string.h>
#include<ctype.h>
void EvaluatePostfix(char e[],int Stack[], int top)
{
    int i=0;
    int x,y;
    int sol;
    int val;
    //for(i=0;e[i]!='\0';i++)
    while(e[i]!='\0')
    {//printf("In\n");
        if(isdigit(e[i]))
        {
          //  Stack[top]=e[i];
          //  top++;9 
          val=e[i]-'0';
            i++;
            while(isdigit(e[i]))
            {
               val=(val*10)+e[i]-'0';
               i++;
            }
             Stack[top]=val;
             
             //printf("Stack:%d Val:%d\n",Stack[top],val);
             top++;
        }
        else if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/' )
        {
            top--;
            x=Stack[top];
            top--;
            y=Stack[top];
            //top--;
            //x=x-'0';
            //y=y-'0';
           // printf("%d %c %d\n",x,e[i],y);
            
           if(e[i]=='+')
            {sol=x+y;}
           else if(e[i]=='-')
            {
             // if(x>y)
            //  {
                  sol=y-x;
              //    }
             // else
             // {sol=y-x;}
            }
           else if(e[i]=='*')
            {sol=x*y;}
           else if(e[i]=='/')
            {
              if(x>y)
              {sol=x/y;}
              else
              {sol=y/x;}
            }
            Stack[top]=sol;
           // printf("%d\n",sol);
            top++;
            i++;
        }
        else
        {i++;}

    }
   // for(i=0;i<top;i++)
   // {printf("%d\n",Stack[i]);}
    printf("%d\n",Stack[0]);
}
int main()
{
    char e[10000];
    int Stack[10000];
    int top=0;
    scanf("%[^\n]%*c", e);
    //scanf("%[^\n]s",e);
    //scanf("%s",e);
    
    //printf("%s",e);
    //printf("INITIAL EXPRESSION\n");
    EvaluatePostfix(e,Stack,top);
}