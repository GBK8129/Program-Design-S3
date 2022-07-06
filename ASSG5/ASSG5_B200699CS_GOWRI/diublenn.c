#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *createNode(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = ptr->prev = NULL;
    return ptr;
}

Node *listSearch(Node *L, int k)
{
    Node *ptr = L;
    while (ptr != NULL)
    {
        if (ptr->data == k)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

Node *insertFront(Node *L, int x)
{
    Node *ptr = createNode(x);
    if (L == NULL)
    {
        L = ptr;
    }
    else
    {
        ptr->next = L;
        L->prev = ptr;
        L = ptr;
    }
    return L;
}

Node *insertEnd(Node *L, int x)
{
    Node *ptr = createNode(x);
    if (L == NULL)
    {
        L = ptr;
    }
    else
    {
        Node *temp = L;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
    return L;
}

Node *insertAfter(Node *L, int x, int y)
{
    Node *ptr = createNode(x);
    Node *temp = listSearch(L, y);
    if (temp != NULL)
    {
        temp->next->prev = ptr;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
    }
    else
    {
        printf("Not Found\n");
    }
    return L;
}

Node *insertBefore(Node *L, int x, int y)
{
    Node *ptr = createNode(x);
    Node *temp = listSearch(L, y);
    if (temp != NULL)
    {
        temp->prev->next = ptr;
        ptr->prev = temp->prev;
        ptr->next = temp;
        temp->prev = ptr;
    }
    else
    {
        printf("Not Found\n");
    }
    return L;
}

Node *listDelete(Node *L, int x)
{
    Node *ptr = listSearch(L, x);
    if (ptr == NULL)
    {
        printf("Not Found\n");
        return NULL;
    }
    if (ptr->next != NULL)
    {
        printf("%d\n", ptr->data);
    }
    else
    {
        printf("NULL\n");
    }
    if (ptr == L)
    {
        ptr->next->prev = NULL;
        L = ptr->next;
    }
    else
    {
        Node *prePtr = ptr->prev;
        if (ptr->next != NULL)
        {
            ptr->next->prev = prePtr;
        }
        prePtr->next = ptr->next;
        free(ptr);
    }
    return L;
}

Node *deteteFront(Node *L)
{
    if (L == NULL)
    {
        printf("NULL\n");
        return NULL;
    }
    printf("%d\n", L->data);
    if (L->next == NULL)
    {
        return NULL;
    }
    else
    {
        L->next->prev = NULL;
        L = L->next;
        return L;
    }
}

Node *deleteLast(Node *L)
{
    if (L == NULL)
    {
        printf("NULL\n");
        return NULL;
    }
    if (L->next == NULL)
    {
        printf("%d\n", L->data);
        return NULL;
    }
    else
    {
        Node *ptr;
        ptr = L;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
        ptr->next = NULL;
    }
    return L;
}

void printReverse(Node *L, int x)
{
    Node *ptr = listSearch(L, x);
    if(ptr==NULL){
        printf("Not found\n");
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

void print(Node *L)
{
    Node *ptr = L;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    char ch;
    int x, y;
    while (1)
    {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'f':
            scanf("%d", &x);
            head = insertFront(head, x);
            break;
        case 't':
            scanf("%d", &x);
            head = insertEnd(head, x);
            break;
        case 'a':
            scanf("%d %d", &x, &y);
            head = insertAfter(head, x, y);
            break;
        case 'b':
            scanf("%d %d", &x, &y);
            head = insertBefore(head, x, y);
            break;
        case 'd':
            scanf("%d", &x);
            head = listDelete(head, x);
            break;
        case 'i':
            head = deteteFront(head);
            break;
        case 'l':
            head = deleteLast(head);
            break;
        case 'r':
            scanf("%d", &x);
            printReverse(head, x);
            break;
        case 'e':
            exit(0);
        }
    }
    return 0;
}