#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node*next;
	struct node*prev;
}node;

node* addnode(int data){
	node*curr=(node*)malloc(sizeof(node));
	curr->data=data;
	curr->next=NULL;
	curr->prev=NULL;
	return curr;
}

void add_rear(node**head,int input){
	if(*head==NULL){
		*head=addnode(input);
	}
	else{
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			if(curr->next==NULL){
				curr->next=addnode(input);
				curr->next->prev=curr;
				break;
			}
		}
	}
}

void add_front(node**head,int data){	//good
	if(*head==NULL){
		*head=addnode(data);
	}
	else{
		node*newnode=addnode(data);
		newnode->next=*head;
		(*head)->prev=newnode;
		*head=newnode;
	}
}

void insert_before(node**head,int num, int input){
	node*curr=*head;
	for(curr=*head;curr!=NULL;curr=curr->next){
		if(curr->data==num){
			node*newnode=addnode(input);
			if(curr->prev==NULL){
				add_front(head,input);
				break;
			}
			else{
				newnode->next=curr->prev->next;
				newnode->prev=curr->prev;
				curr->prev->next=newnode;
				newnode->next->prev=newnode;
				break;
			}
		}
	}
}

void insert_after(node**head,int num, int input){
	for(node*curr=*head;curr!=NULL;curr=curr->next){
		if(curr->data==num){
			node*newnode=addnode(input);
			newnode->prev=curr;
			newnode->next=curr->next;
			curr->next=newnode;
			curr->next->next->prev=curr->next;
			break;
		}
	}
}

void delete_front(node**head){	//good
	if(*head==NULL){
		printf("EMPTY\n");
	}
	else{
		node*curr=*head;
		if(curr->next==NULL){
			*head=NULL;
			printf("EMPTY\n");
		}
		else{
			curr=(*head)->next;
			free(*head);
			*head=curr;
			(*head)->prev=NULL;
		}
	}
}

void delete_rear(node**head){
	if(*head==NULL){
		printf("EMPTY\n");
	}
	else{
		node*pre;
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			if(curr->next==NULL){
				if(curr->prev==NULL){
					*head=NULL;
					printf("EMPTY\n");
					break;
				}
				else{
					pre=curr->prev;
					free(curr);
					curr=pre;
					curr->next=NULL;
					break;
				}
			}
		}
	}
}

void delete_item(node**head,int value){
	node*remove=NULL;
	for(node*curr=*head;curr!=NULL;curr=curr->next){
		if(curr->data==value){
			remove=curr;
			break;
		}
	}
	if(remove->prev==NULL){
		remove=(*head)->next;
		free(*head);
		*head=remove;
		remove->prev=NULL;
	}
	else if(remove->next==NULL){
		remove->prev->next=remove->next;
		free(remove);
	}
	else{
		remove->next->prev=remove->prev;
		remove->prev->next=remove->next;
		if(remove==NULL);
		else{free(remove);}
	}
}

void printlist(node**head){
	for(node*curr=*head;curr!=NULL;curr=curr->next){
		printf("%d->",curr->data);
	}
	printf("\n");
}

void Queue_system(node**head){
	int num=0;
	int input=0;
	int value=0;
	printf("insert: ");
	scanf("%d",&num);
	
	switch(num){
		case 1:
			scanf("%d",&input);
			add_rear(head,input);
			break;
		case 2:
			scanf("%d",&input);
			add_front(head,input);
			break;
		case 3:
			delete_rear(head);
			break;	
		case 4:
			delete_front(head);
			break;
		case 5:
			scanf("%d",&input);
			delete_item(head,input);
			break;
		case 6:
			scanf("%d %d",&value,&input);
			insert_before(head,value,input);
			break;
		case 7:
			scanf("%d %d",&value,&input);
			insert_after(head,value,input);
			break;
		case 8:
			break;
		case 9:
			printf("BYE\n");
			exit(1);
		default:
			printf("Menu Error\n");
			exit(1);
	}
	printlist(head);
}


void menu(){
	printf("1. Add_rear\n");
	printf("2. Add_front\n");
	printf("3. Delete_rear\n");
	printf("4. Delete_front\n");
	printf("5. Delete_item\n");
	printf("6. Insert_before\n");
	printf("7. Insert_after\n");
	printf("8. Print_list\n");
	printf("9. EXIT\n");
}

int main(void){

	node*head=NULL;
	do{
		menu();
		Queue_system(&head);
		printf("\n");
	}while(1);

	return 0;
}
