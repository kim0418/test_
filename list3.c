#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node{
   element value;
   struct Node* next;
}Node;

Node* addnode(element value_){
   Node* newnode = (Node*)malloc(sizeof(Node));
   newnode->value = value_;
   newnode->next = NULL;
   return newnode;
}

Node* lastnode(Node* head)
{
   if (head == NULL) return head;
   Node* curr = head;
   while (curr->next != NULL) curr = curr->next;
   return curr;
}

Node* insert_last(Node* head, element value)
{
   if (head == NULL)
   {
      head = addnode(value);
      return head;
   }
   Node* last = lastnode(head);
   last->next = addnode(value);
   return head;
}

void print_node(Node* head)
{
   for (Node* curr = head; curr != NULL; curr = curr->next)
   {
      printf("%d\t", curr->value);
   }
}

void remove_all(Node* head)
{
   Node* curr = head;
   while (curr != NULL)
   {
      curr = head->next;
      free(head);
      head = curr;
   }
}

int main(void)
{
   Node* head = NULL;

   for(int i=0;i<5;i++){
   	head=insert_last(head,i);
   }

   print_node(head);

   remove_all(head);

   return 0;
}



