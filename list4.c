#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node*next;
	struct node*prev;
}node;

node* addnode(char data){
	node*curr=(node*)malloc(sizeof(node));
	curr->data=data;
	curr->next=NULL;
	curr->prev=NULL;
	return curr;
}

void insert(node*head,char data){
	node*k=addnode(data);
	k->next=head->next;
	head->next=k;
	k->prev=head->next->next->prev;
	head->next->next->prev=k;
}

void insertlast(node**head,char data){
	if(*head==NULL){
		*head=addnode(data);
	}
	
	else{
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			if(curr->next==NULL){
				curr->next=addnode(data);
				curr->next->prev=curr;
				//node*s=addnode(data);
				//curr->next=s;
				//curr->next->prev=curr;
				break;
			}
		}
	}
}

void insertfirst(node**head,char data){
	node*newnode=addnode(data);
	newnode->next=*head;
	(*head)->prev=newnode;
	*head=newnode;
}

void printlist(node*head){
	for(node*curr=head;curr!=NULL;curr=curr->next){
		printf("%c->",curr->data);
	}
	printf("NULL\n");
}

void printinvertlist(node*head){
	node*curr=NULL;
	for(curr=head;curr->next!=NULL;curr=curr->next);
	
	node*last=curr;
	for(curr=last;curr!=NULL;curr=curr->prev){
		printf("%c-> ",curr->data);
	}
	printf("head\n");
}

void deletenext(node*head,char value){
	node*remove;
	node*pre;
	for(node*curr=head;curr!=NULL;curr=curr->next){
		if(curr->next->data==value){
			pre=curr;
			break;
		}
	}
	remove=pre->next;
	pre->next=remove->next;
	pre->next->prev=remove->prev;
	free(remove);
}

void deletenow(node*head,char value){
	node*curr=head;
	for(curr=head;curr->data==value;curr=curr->next);
	node*remove=curr;
	curr->prev->next=curr->next;
	curr->next->prev=curr->prev;
	free(remove);
}


int main(int argc, char*argv[]){
    node*head=NULL;
    printlist(head);
    insertlast(&head,'A'); printlist(head);
    insertlast(&head,'B'); printlist(head);
    insertlast(&head,'C'); printlist(head);
    insert(head,'K'); printlist(head);
    deletenext(head,'B'); printlist(head);
    //deletenow(head,'B'); printlist(head);
    insertfirst(&head,'3'); printlist(head);
    insertfirst(&head,'2'); printlist(head);
    insertfirst(&head,'1'); printlist(head);
    printinvertlist(head);
    
    return 0;
}
