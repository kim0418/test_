#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int value;
	struct node* next;
}node;

void add_list(node*head){
	
}

void print_list(node*head){
	for(node*curr=head; curr!=NULL; curr=curr->next){
		printf("%d", curr->value);
	}
	printf("\n");
}

void free_list(node*head){
	for(node*curr=head; curr!=NULL; curr=curr->next){
		free(curr->next);
		curr->next=NULL;
	}
}

int main(int argc, char* argv[]){
	//head->next=(node*)malloc(sizeof(node));
	
	node* head=(node*)malloc(sizeof(node));
	head->next=NULL;
	head->value=100;
	
	node* node2=(node*)malloc(sizeof(node));
	node2->value=200;
	node2->next=NULL;
	head->next=node2;
	
	node* node3=(node*)malloc(sizeof(node));
	node3->value=300;
	node3->next=NULL;
	node2->next=node3;
	
	print_list(head);	

	free_list(head);
	return 0;
}
