#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct que{
	int front;
	int rear;
	int size;
	char **data;
}que;

void create(que*s,int n){
	s->front = 0;
	s-> rear =0;
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

void que_view(que*s){
	   if(!is_empty(s)){
	   int i=s->front;
	   	do{
	   		(s->front)=((s->front)+1)%s->size;
	   		printf("%2s|",s->data[s->front]);
	   		if(s->front == s->rear){
	   			break;
	   		}
	   	}while(i!=s->front);
	   }
	   printf("\n");
}

void add_rear(que*s, char*item){
	if(is_full(s)){
		fprintf(stderr,"queue is full\n");
	}
	s->rear=((s->rear)+1)%s->size;
	strcpy(s->data[s->rear],item);
}

char* del_rear(que*s){
	if(is_empty(s)){
		fprintf(stderr,"queue is empty\n");
		return 0;
	}
	return s->data[((s->rear-1)+(s->size))%(s->size)];
}

char* peek_rear(que*s){
	if(is_empty(s)){
		fprintf(stderr,"queue is empty\n");
		return 0;
	}
	return s->data[s->rear];
}

void add_front(que*s, char*item){
	if(is_full(s)){
		fprintf(stderr,"queue is full\n");
	}
	s->rear=((s->rear)+1)%s->size;
	strcpy(s->data[s->front],item);
}

char* del_front(que*s){
	if(is_empty(s)){
		fprintf(stderr,"queue is empty\n");
		return 0;
	}
	return s->data[((s->front)+1)%s->size];
}

char* peek_front(que*s){
	if(is_empty(s)){
		fprintf(stderr,"queue is empty\n");
		return 0;
	}
	return s->data[s->front];
}

int main(void){

	que*S=(que*)malloc(sizeof(que));
	
	char **input;
	for(int i=0;i<5;i++){
		input[i]=(char*)malloc(20*sizeof(char));
	}
	create(S,3);
	
	for(int i=0;i<5;i++){
		fgets(input[i],10,stdin);
		add_front(S,input[i]);
		que_view(S);
	}
	for(int i=0;i<5;i++){
		del_front(S);
	}
	
	for(int i=0;i<5;i++){
		free(S->data[i]);
	}

	return 0;
}




