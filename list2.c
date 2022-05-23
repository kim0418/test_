#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int value;
    struct node* next;
}node;

void print_list(node*a){
    for(node*k=a;k!=NULL; k=k->next){
    	printf("%3d->",k->value);
    }
    printf("\b\b\b	\n");
}

node* addnode(int value){
	node*head=(node*)malloc(sizeof(node));
	head->value=value;
	head->next=NULL;
	return head;
}

void insert_last(node*head,node**last,int value){
	node*data=addnode(value);
	//head->...->NULL;
	(*last)->next=data;
	(*last)=data;
}

void insert_last2(node*head,int value){
	for(node*curr=head;curr!=NULL;curr=curr->next){
		if(curr->next==NULL){
			node*s=addnode(value);
			curr->next=s;
			break;
		}
	}
}

void insert(node* head,int value,int count){
	node*curr=head;
	int i=0;
	while(i<=count){
		curr=curr->next;
		i++;
	}
	node*data=addnode(value);
	data->next=curr->next;
	curr->next=data;
	/*node*data=(node*)malloc(sizeof(node));
	data->value=value;
	data->next=curr->next;
	curr->next=data;*/
	//return head;
}

int main(void){
	/*node*head=addnode(10);
	node*last=head;
	
	for(int i=20;i<100;i+=10){
		insert_last(head,&last,i);
	}
	print_list(head);
	printf("\n");
	insert(head,100,4);
	print_list(head);*/
	node*head=addnode(10);
	for(int i=20;i<100;i+=10){
		insert_last2(head,i);
	}
	print_list(head);
	printf("\n");
	insert(head,100,4);
	print_list(head);
	return 0;
}



/*
int main(int argc, char* argv[]){
    
    node*a=(node*)malloc(sizeof(node));
    a->value=10;
    a->next=NULL;

    node*b=(node*)malloc(sizeof(node));
    b->value=20;
    b->next=NULL;

    node*c=(node*)malloc(sizeof(node));
    c->value=30;
    c->next=NULL;

    a->next=b;
    b->next=c;

    node*d=(node*)malloc(sizeof(node));
    d->value=15;
    d->next=NULL;
    
    node*curr=a;
    d->next=curr->next;
    curr->next=d;

    print_list(a);
    
    return 0;
}
*/

