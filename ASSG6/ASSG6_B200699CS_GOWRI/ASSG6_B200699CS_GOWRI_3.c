#include<stdio.h>
#include<string.h>
#include<ctype.h>
int Order_Precedence(char val)
{
    if(val == '-' )
    {return 0;}
    else if(val == '+')
    {return 0;}
    else if(val == '*')
    {return 1;}
    else if(val == '/')
    {return 1;}
   // else if(val == '^')
   // {return 2;}
    else return -1;
}
void Push(char Stack[],char val,int top)
{
   Stack[top]=val;
}
void Pop(char Stack[],int *top)
{
    top=top-1;
}
int main()
{
    char Infix[10000];
    char Postfix[10000];
    scanf("%s",Infix);
    int top=-1;
    int n=0;
    int i;
    int exp=0;
   
    strcat(Infix,")");
    for(i=0;Infix[i]!='\0';i++)
     {n++;}
    n=n+3;
    char comp=Infix[0];
    char Stack[n];
    Stack[0]='(';
    top++;
    char initial=Infix[0];
    for(i=0;Infix[i]!='\0';i++)
    {
        if(isalpha(Infix[i]) || isdigit(Infix[i]))
        {
            //top++;
            Postfix[exp] = Infix[i];
           // printf("%c",Infix[i]);
            exp++;
        }
        else if(Infix[i] == '(')
        {
            top++;
            Push(Stack,Infix[i],top);
        }
        else if(Infix[i] == ')')
        {
            char in=Stack[top];
            top--;
            //Pop(Stack,&top);
            //in=Stack[top];
            //Pop(Stack,&top);
            //printf("%c\n",in);
            while(in != '(')
            {
                Postfix[exp]=in;
                exp++;
                //printf("%c",in);
                top--;
                //Pop(Stack,&top);
                in=Stack[top];
                //printf("%c %d\n",in,top);
            }

        }
        else if(Infix[i] == '+' || Infix[i] == '-' || Infix[i] == '*' || Infix[i] == '/' )
        {
            char in=Infix[i];
            //top--;
			//Pop(Stack,&top);
           // printf("%c %d\n",in,top);

			while((in == '+' || in == '-' || in == '*' || in == '/' ) && (Order_Precedence(Infix[i]) <= Order_Precedence(Stack[top])))
			{
				Postfix[exp] = Stack[top];                  
				exp++;
                
                top--;
                //Stack[top]=in;
                //break;
                //top--;
				//Pop(Stack,&top);
               // printf("%c",in);
            }
            //else{
            top++;
			Push(Stack,in,top);
            //}
            //top++;
           // Push(Stack,Infix[i],top);
        }
    }
    //printf("%s",Postfix);
    int a,b; a=0;b=0;
    //printf("%d",top);
    //
   
    /*for(i=0;Postfix[i]!='\0';i++)
    {
        a++;
    }
    for(i=0;Infix[i]!='\0';i++)
    {
        if(Infix[i]!='(' || Infix[i]!=')')
           {b++;}
    }*/
    //printf("%d %d\n",a,b);
    if(top<=0)
    {printf("%s",Postfix); return 0;}
    else
    {printf("%s",Postfix);
         int prin=0;
         while(Stack[prin]!='\0')
          {prin++;}
           prin--;
         while(prin!=0)
          {prin--;
            if(Stack[prin] =='+' || Stack[prin] =='-' || Stack[prin] =='*' || Stack[prin] =='/')
             {printf("%c",Stack[prin]);}}
    }
    /*if(sizeof(Postfix)==sizeof(Infix))
    {printf("Yes");return 0;}
    while(prin!=0)
    {prin--;
    if(Stack[prin] =='+' || Stack[prin] =='-' || Stack[prin] =='*' || Stack[prin] =='/')
    {printf("%c",Stack[prin]);}}
   // printf("%c%c",Stack[1],Stack[2]);*/
}