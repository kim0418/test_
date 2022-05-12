#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 10

typedef struct Stack{
	int top;
	int size;
	int data[MAX];
}Stack;

void create(Stack*s,int n){
	s->size=n;
	s->top=-1;
}

int is_empty(Stack*s){
	return s->top==-1;
}

int is_full(Stack*s){
	return s->top==s->size;
}

void push(Stack*s, int n){
	if(is_full(s)){
		fprintf(stderr,"PUSH ERROR\n");
		return;
	}
	s->top++;
	s->data[s->top]=n;
}

int pop(Stack*s){
	if(is_empty(s)){
		fprintf(stderr,"POP ERROR\n");
		exit(1);
	}
	return s->data[(s->top)--];
}

int peek(Stack*s){
	if(is)empty(s)){
		fprintf(stderr,"EMPTY ERROR\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main(void){

	Stack*S=(Stack*)malloc(sizeof(Stack));
	
	create(S,4);
	push(S,10);
	push(S,20);
	push(S,30);
	push(S,40);
	
	for(int i=0;i<4;i++){
		printf("%d\n",pop(S));
	}
	
	free(S);
	
	return 0;
}



