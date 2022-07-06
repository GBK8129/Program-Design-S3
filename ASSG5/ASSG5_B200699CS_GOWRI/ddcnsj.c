#include <stdio.h>
#include <stdlib.h>
struct Node {
char data;
struct Node* next;
};
struct Node* createNode(int k)
{
struct Node* new_node
= (struct Node*)malloc(sizeof(struct Node));
new_node->data = k;
new_node->next = NULL;
return new_node;
}
struct Node* listSearch(struct Node**L, char k){ struct Node *temp = (*L);
while(temp != NULL){
if(temp->data == k){
return temp;
}
temp = temp->next;
}
return temp;
}
void listInsertFront(struct Node** L, struct Node* new_node)
{
new_node->next = (*L);
(*L) = new_node;
}
void listInsertTail(struct Node** L, struct Node* new_node)
{
struct Node *p = (*L) ;
while(p->next != NULL){
p = p->next;
}
p->next = new_node;
}
void listInsertAfter(struct Node** L, struct Node *new_node, int y)
{
struct Node *p = listSearch(L, y);
new_node->next = p->next;
p->next = new_node;
}
void listInsertBefore(struct Node** L, struct Node* new_node, int y)
{
struct Node *p = (*L);
while(p->next->next != NULL){
if(p->next->data == y)
break;
p = p->next;
}
new_node->next = p->next;
p->next = new_node;
}
void deleteNode(struct Node** L, char key)
{
struct Node *temp = *L, *prev;
if(*L == NULL){
printf("Empty List\n");
return;
}
// If head node itself holds the key to be deleted
if (temp != NULL && temp->data == key) {
*L = temp->next; // Changed head
free(temp); // free old head
return;
}
while(temp->next != NULL){
if(temp->data == key)
break;
prev = temp;
temp = temp->next;
}
if (temp == NULL)
return;
prev->next = temp->next;
temp->next = NULL;
free(temp); // Free memory
}
void deleteFirst(struct Node** L)
{
if(*L == NULL){
printf("Empty List\n");
return;
}
struct Node *temp = *L;
(*L) = temp->next;
temp->next = NULL;
printf("deleted node key : %c\n", temp->data);
free(temp); // Free memory
}
void deleteLast(struct Node** L)
{
if(*L == NULL){
printf("Empty List\n");
return;
}
struct Node *temp = *L;
while(temp->next->next != NULL){
temp = temp->next;
}
struct Node *p = temp->next;
printf("deleted node key : %c\n", p->data);
temp->next = NULL;
p = NULL;
free(p); // Free memory
}
void printList(struct Node* node)
{
printf("List : ");
while (node != NULL) {
printf("%c->", node->data);
node = node->next;
}
printf("\n");
}
int main()
{ struct Node* L = NULL;
 char c[3];
 struct Node *x;
printf("Enter character without spaces\n");
while(1){
scanf("%s", c);
switch (c[0])
{case 'f':x = createNode(c[1]);
          listInsertFront(&L, x);
          break;
case 't': x = createNode(c[1]);
          listInsertTail(&L, x);
          break;
case 'a': x = createNode(c[1]);
          listInsertAfter(&L, x, c[2]);
          break;
case 'b': x = createNode(c[1]);
          listInsertBefore(&L, x, c[2]);
          break;
case 'd': deleteNode(&L, c[1]);
          break;
case 'i': deleteFirst(&L);
          break;
case 'l': deleteLast(&L);
          break;
case 'p': printList(L);
          break;
case 'e': return 0;
default: break;
}}
return 0;
}