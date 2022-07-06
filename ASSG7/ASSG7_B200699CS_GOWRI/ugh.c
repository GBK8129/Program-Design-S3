a 25
a 13
a 50
a 45
a 55
a 18
c 25

 if((*Tree)==NULL)  
    {return;}
    /*int k;
    k=T->key;*/
    if(T->right==NULL && T->left==NULL)
    {
        T=T->p;
        if(T->left->key==k)
        {
            T->left=NULL;
        }
        else if(T->right->key==k)
        {
            T->right=NULL;
        }
    }
    else if(T->right==NULL)
    {        
        T->key=T->left->key;
        T->left=NULL;
    }
    else if(T->left==NULL)
    {
        T->key=T->right->key;
        T->right=NULL;
    }
    else
    {
        //struct Node *temp=T;
        int rep;
        //rep=Successor(T,k);
        //Delete(Tree,T,rep);
        
        rep=Minimum(*Tree);
       // rep=temp->key;
        
        struct Node *keep=Search(*Tree,rep);
        T->key=rep;
        Delete(Tree,keep,rep);

    }
    /*while(T->p!=NULL)
        {T=T->p;}
        (*Tree)=T; */
        return;