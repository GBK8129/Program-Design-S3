#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef struct{
    char Amoeba_Name[20];
    int Amoeba_Size;
}amoeba;
int parent(int i){
    return i/2;
}
void swap( amoeba *a, amoeba *b){
    amoeba temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
bool lex(char* c,char* p){
    int i=0;
    for(;c[i]==p[i];i++){;}
    if (c[i] < p[i])
        return true;
    else
        return false;
}
void INSERT(amoeba *W,int i){

        while((i>0)&&((W[parent(i)].Amoeba_Size>W[i].Amoeba_Size)||(W[parent(i)].Amoeba_Size==W[i].Amoeba_Size&&lex(W[i].Amoeba_Name,W[parent(i)].Amoeba_Name)))){
            swap(&W[parent(i)],&W[i]);
            i=parent(i);
        }
}
void READ(amoeba *W,int n,int i){
    while(i<n){
        scanf("%s %d",W[i].Amoeba_Name,&W[i].Amoeba_Size);
        INSERT(W,i);
        i++;
    }
}
void heapify(amoeba *W,int n,int i){
    int smallest=i;
    if(i==0){
        if(((W[i].Amoeba_Size>W[1].Amoeba_Size)||(W[i].Amoeba_Size==W[1].Amoeba_Size&&lex(W[1].Amoeba_Name,W[0].Amoeba_Name)))){
            swap(&W[0],&W[1]);
            heapify(W,n,1);
        }
        else
        smallest++;
    }
	int l = 2*i+1;
	int r = 2*i+2;
	if((l<n)&&((W[i].Amoeba_Size>W[l].Amoeba_Size)||(W[l].Amoeba_Size==W[i].Amoeba_Size&&lex(W[l].Amoeba_Name,W[i].Amoeba_Name)))){
        smallest=l;
    }
    if((r<n)&&((W[i].Amoeba_Size>W[1].Amoeba_Size)||(W[i].Amoeba_Size==W[1].Amoeba_Size&&lex(W[1].Amoeba_Name,W[0].Amoeba_Name)))){
        smallest=r;
    }
	if(smallest != i){
		swap(&W[i],&W[smallest]);
		heapify(W,n,smallest);
	}
}
void COMBINE(amoeba *W,int n){
    printf("%s %s %d\n",W[0].Amoeba_Name,W[1].Amoeba_Name,W[0].Amoeba_Size+W[1].Amoeba_Size);
    W[0].Amoeba_Size=W[0].Amoeba_Size+W[1].Amoeba_Size;
    amoeba temp=W[1];
    W[1]=W[n-1];
    n--;
    if(n==1){
        printf("%s %d",W[0].Amoeba_Name, W[0].Amoeba_Size);
    }
    if(n>1){
        for(int i=1;i<n;i++){
            INSERT(W,i);
        }
        
        COMBINE(W,n); 
    }
}
int main(){
    int n;
    scanf("%d",&n);
    amoeba W[n];
    int i=0;
    READ(W,n,i);
    COMBINE(W,n);
    return 0;
}