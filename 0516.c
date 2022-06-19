#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


typedef struct que{
	int front;
	int rear;
	int size;
	char **data;
}que;

void create(que*s,int n){
	s->front = 0;
	s-> rear =0;
	s->size=n+1;
	s->data = (char **)malloc(s->size * sizeof(char *));
	for(int i=0;i<(s->size);i++){
		s->data[i]=(char*)malloc(n*sizeof(char));
	}
}

int is_empty(que*s){
	return s->front == s->rear;
}

int is_full(que*s){
	return ((s->rear)+1)%(s->size)==s->front;
}

void enque(que*s, char*item){
	if(is_full(s)){
		fprintf(stderr,"enqueue error\n");
		return;
	}
	s->rear=((s->rear)+1)%s->size;
	strcpy(s->data[s->rear],item);
}

char* deque(que*s){
	if(is_empty(s)){
		fprintf(stderr,"dequeue error\n");
		return 0;
	}
	s->front=((s->front)+1)%s->size;
	return s->data[s->front];
}

int main(void){

	que*S=(que*)malloc(sizeof(que));
	
	create(S,3);
	
	enque(S,"Good");
	enque(S,"World");
	enque(S,"Hello");
	enque(S,"Hi");

	while(!is_empty(S)){
		printf("%s\n",deque(S));
	}
	deque(S);
	for(int i=0;i<5;i++){
		free(S->data[i]);
	}
	return 0;
}







/*
typedef struct que{
	int front;
	int rear;
	int size;
	char **data;
}que;

void create(que*s,int n){
	s->front=0;
	s->rear=0;
	s->size=n;
	for(int i=0;i<(s->size);i++){
		s->data[i]=(char*)malloc(10*sizeof(char));
	}
}

int is_empty(que*s){
	return s->front == s->rear;
}

int is_full(que*s){
	return ((s->rear)+1)%(s->size)==s->front;
}

void enque(que*s, char*item){
	if(is_full(s)){
		fprintf(stderr,"enqueue error\n");
		return;
	}
	s->rear=((s->rear)+1)%s->size;
	strcpy(s->data[s->front],item);
}

char* deque(que*s){
	if(is_empty(s)){
		fprintf(stderr,"dequeue error\n");
		return 0;
	}
	return s->data[((s->front)+1)%s->size];
}

int main(int argc, char* argv[]){

	que*S=(que*)malloc(sizeof(que));
	
	create(S,3);
	
	enque(S,"Good");
	enque(S,"world");
	enque(S,"Hello");
	enque(S,"Hi");

	while(!is_empty(S)){
		printf("%s\n",deque(S));
	}

	deque(S);
	free(S);
	return 0;
}*/
