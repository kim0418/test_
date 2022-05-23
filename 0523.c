#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char data[10];
	struct node* next;
}node;

node* addnode(char*arr){
	node*curr=(node*)malloc(sizeof(node));
	strcpy(curr->data,arr);
	curr->next=NULL;
	return curr;
}

void insertlast(node**head,char *arr){
	if(*head==NULL){
		*head=addnode(arr);
	}
	else{
	for(node*curr=*head;curr!=NULL;curr=curr->next){
		if(curr->next==NULL){
			node*s=addnode(arr);
			curr->next=s;
			break;
		}
	}
	}
}

void printlist(node*head){
	for(node*k=head;k!=NULL;k=k->next){
		printf("%s -",k->data);
	}
	printf("\n");
}

void insertafter(node**head,char *arr,char *arr2){
	int count=0;
	node*curr=*head;
	while(curr!=NULL){
		if(!strcmp(curr->data,arr)){
		//strcmp is return 0
			node*p=addnode(arr2);
			p->next=curr->next;
			curr->next=p;
			count++;
		}
		curr=curr->next;
	}
	if(count==0){
		printf("Insert failed(%s is not exist)\n",arr);
	}
}

void freelist(node*head){
	node*curr=head;
	while(curr!=NULL){
		printf("%s freed\n",curr->data);
		curr=head->next;
		free(head);
		head=curr;
	}
}

int main(void){

	node*head=NULL;

	insertlast(&head,"Apple"); printlist(head);
	insertlast(&head,"Durian"); printlist(head);
	insertafter(&head,"Apple","Banana"); printlist(head);
	insertafter(&head,"Tomato","Grape"); printlist(head);
	insertafter(&head,"Banana","Carrot"); printlist(head);
	
	freelist(head);
	
	return 0;
}


