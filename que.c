#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct que{
	int front;
	int top;
	int size;
	int *data;
}que;

void create(que*s,int n){
	s->top=-1;
	s->front=-1;
	s->size=n;
	s->data=(int*)malloc(s->size*sizeof(int));
}

int is_full(que*S){
	return s->top==s->size;
}

int is_empty(que*s){
	return s->front==s->top;
}

int enque(que*s,int n){
	if(is_full(s)){
		fprintf(stderr,"full\n");
		return;
	}
	return s->data[++(s->top)];
}

int deque(que*s){
	if(is_empty(s)){
		fprintf(stderr,"empty\n");
		return;
	}
	return s->data[++(s->front)];
}

int main(void){
	
	int item=0;
	que*S=(que*)malloc(5*sizeof(que));
	create(S,5);
	
	enque(S,10);
	enque(S,20);
	enque(S,30));
	
	
	item = deque(S); printf("%d\n",item);
	item = deque(S); printf("%d\n",item);
	item = deque(S); printf("%d\n",item);
	return 0;
}






