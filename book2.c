#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node{
	char data[10];
	struct node*next;
}node;

node*addnode(char*arr){
	node*curr=(node*)malloc(sizeof(node));
	strcpy(curr->data,arr);
	curr->next=NULL;
	return curr;
}

node* insert_last(node*head,char *arr){
	for(node*curr=head;curr!=NULL;curr=curr->next){
		if(curr->next==NULL){
			node*s=addnode(arr);
			curr->next=s;
			break;
		}
	}
}
void print_list(node*head){
	for(node*a=head;a!=NULL;a=a->next){
		printf("%s->",a->data);
	}
}

int main(void){
	
	node* head=NULL;
	
	head=insert_last(head,"apple"); print_list(head);
	head=insert_last(head,"maam");
	
	return 0;
}




