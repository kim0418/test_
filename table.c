#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int element;
typedef struct que{
	int front;
	int rear;
	int size;
	element *data;
}que;

void error(char *arr){
	fprintf(stderr,"%s\n",arr);
	exit(1);
}

void create(que*s,int n){
	s->front=-1;
	s->rear=-1;
	s->size=2*n;
	s->data=(element*)malloc(n*sizeof(element));
}

int is_full(que*s){
	return ((s->rear)==(s->size));
}

int is_empty(que*s){
	return s->front == s->rear;
}

void enque(que*s, int item){
	
	s->data[(++(s->rear))%(s->size)]=item;
}

int deque(que*s,int b){
	
	for(int i=0;i<(b-1);i++){
		s->front = ((s->front)+1)%s->size;
		enque(s,s->data[s->front]);
	}
	s->front = ((s->front)+1)%(s->size);
	return s->data[(s->front)];
}

int main(void){
	
	int table,b=0;
	que*S=(que*)malloc(sizeof(que));
	
	scanf("%d %d",&table, &b);
	create(S,table*10);
	
	for(int i=1;i<=table;i++){
		enque(S,i);
	}
	
	for(int i=0;i<table;i++){
		printf("%d ",deque(S,b));
	}
	
	free(S);
	
	return 0;
}






/*
typedef int element;
typedef struct que{
	element* data;
	int front;
	int rear;
	int size;
}que;

void create(que*s,int n){
	s->size=n;
	s->front=0;
	s->rear=0;
	s->data=(element*)malloc((s->size)*sizeof(element));
}


int is_full(que*s){
	return ((s->rear)+1)%(s->size)==s->front;
}

int is_empty(que*s){
	return s->front == s->rear;
}

void enque(que*s,int n){
	if(is_full(s)){
		fprintf(stderr, "queue is full\n");
	}
	s->rear=(((s->rear)+1)%(s->size));
	s->data[s->rear]=n;
}

element deque(que*s,int item){
	if(is_empty(s)){
		fprintf(stderr, "queue is empty\n");
		exit(1);
	}
	s->front=(((s->front)+item)%s->size);
	if(s->front==0){
		return s->data[++(s->front)];
	}
	return s->data[(s->front)];
}

element peek(que*s){
	if(is_empty(s)){
		fprintf(stderr, "queue is empty\n");
		exit(1);
	}
	return s->data[(s->front)];
}


int main(void){

	int table,item;
	
	que*S=(que*)malloc(sizeof(que));
	
	scanf("%d %d",&table,&item);
	
	create(S,table+1);
	
	for(int i=0;i<table;i++){
		enque(S,i+1);
	}
	while(!is_empty(S)){
		printf("%d ",deque(S,item));
	}
	
	free(S);
	return 0;
}
*/






