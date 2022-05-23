#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct node{
    char value[10];
    struct node* next;
}node;

void print_list(node*a){
    for(node*k=a;k!=NULL; k=k->next){
    	printf("%s->",k->value);
    }
    printf("\n");
}

void freelist(node*head){
	node*curr=head;
	while(curr!=NULL){
		printf("%s freed\n",curr->value);
		curr=head->next;
		free(head);
		head=curr;
	}
}

int main(int argc, char* argv[]){
    
    node*a=(node*)malloc(sizeof(node));
    strcpy(a->value,"apple");
    a->next=NULL;

    node*b=(node*)malloc(sizeof(node));
    strcpy(b->value,"banana");
    b->next=NULL;

    node*c=(node*)malloc(sizeof(node));
    strcpy(c->value,"carrot");
    c->next=NULL;

    node*d=(node*)malloc(sizeof(node));
    strcpy(d->value,"durian");
    d->next=NULL;

    a->next=b;
    b->next=c;
    c->next=d;
    
    
    print_list(a);
    freelist(a);
    
    return 0;
}
