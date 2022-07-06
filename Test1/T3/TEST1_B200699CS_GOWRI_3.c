#include<stdio.h>
#include<stdlib.h>
void read_details(struct student A[], int n)
{
  int i;
  for(i=0;i<n;i++)
  {fgets(A[i].reg_no,11,stdin);
   scanf("%d",&A[i].ad_no);
   scanf("%d",&A[i].time_req);}
   
}
void print_students(struct student A[], int n)
{int i;
  for(i=0;i<n;i++)
  {printf("%s",A[i].reg_no);
   printf(" %d",A[i].ad_no);
   printf(" %d",A[i].ime_req);}
   
}
void allocate_CCC(struct student A[], int n, int tslot) 
{

}

int main()
{
    struct student 
    {
        char reg_no[11];
        int time_req;
        int ad_no;
    };
    char c; int n; struct student A[100001];
    int tslot; int i;
    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {  case 'r': scanf("%d %d",&n,&tslot);
                    read_details(&A, n);
                    break;
           case 'p': 
                    print_students(A, n);
                    break;   
           case 'a': allocate_CCC(A, n, tslot); 
                    break;
           case 't': return 0;
        }
    }
}