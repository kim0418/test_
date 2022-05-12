#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAX 30

typedef struct Stack{
	int top;
	int size;
	char *data[MAX];
}Stack;

void create(Stack*s, int n){

	s->top=-1;
	s->size=n;
	for(int i=0;i<(s->size);i++){
		s->data[i]=(char*)malloc((s->size)*sizeof(char));
	}
}

int is_full(Stack*s){
	return s->top==s->size-1;
}

int is_empty(Stack*s){
	return s->top==-1;
}

void push(Stack*s, char*a){
	if(is_full(s)){
		fprintf(stderr,"PUSH ERROR\n");
		return;
	}
	s->top++;
	strcpy(s->data[s->top],a);
}

char* pop(Stack*s){
	if(is_empty(s)){
		fprintf(stderr,"POP ERROR\n");
		exit(1);
	}
	return s->data[(s->top)--];
}

int main(void){

	Stack* S=(Stack*)malloc(sizeof(Stack));
	
	create(S,3);
	
	push(S,"hello");
	push(S,"world");
	push(S,"hi");
	push(S,"open");

	while(!is_empty(S)){
		printf("%s\n",pop(S));
	}
	pop(S);
	free(S);
	return 0;
}









