#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char*data;
	struct node* next;
}node;

node* addnode(char*arr){
	node*curr=(node*)malloc(sizeof(node));
	strcpy(curr->data,arr);
	curr->next=NULL;
	return curr;
}

void insertlast(node*head,char *arr){
	for(node*curr=head;curr!=NULL;curr=curr->next){
		if(curr->next==NULL){
			node*s=addnode(arr);
			curr->next=s;
			break;
		}
	}
}

void printlist(node*head){
	for(node*k=head;k!=NULL;k=k->next){
		printf("%s -",k->data);
	}
}

/*void insertafter(node*head,char *arr,char *arr2){
	node*curr=head;
	while(curr->data!=arr){
		curr=curr->next;
	}
	node*p=addnode(arr2);
	p->next=curr->next;
	curr->next=p;
}*/

void freelist(node*head){
	node*curr=head;
	while(curr!=NULL){
		curr=head->next;
		free(head);
		head=curr;
	}
}

int main(void){

	node*head=NULL;

	insertlast(head,"Apple"); printlist(head);
	insertlast(head,"Durian"); printlist(head);
	//insertafter(head,"Apple","Banana");
	//insertafter(head,"Tomato","Grape");
	//insertafter(head,"Banana","Carrot");
	
	freelist(head);
	
	return 0;
}


