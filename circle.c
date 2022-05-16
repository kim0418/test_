#include<stdio.h>
#include<string.h>
#include<stdlib.h>


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

void enque(que*s,element data){
	if(is_full(s)){
		fprintf(stderr, "queue is full\n");
	}
	s->rear=(((s->rear)+1)%(s->size));
	s->data[s->rear]=data;
}

element deque(que*s){
	if(is_empty(s)){
		fprintf(stderr, "queue si empty\n");
		exit(1);
	}
	(s->front=((s->front)+1)%s->size);
	return s->data[(s->front)];
}

element peek(que*s){
	if(is_empty(s)){
		fprintf(stderr, "queue si empty\n");
		exit(1);
	}
	return s->data[(s->front)];
}

element que_print(que*s){
	printf("front=%d  rear=%d\n",s->front,s->rear);
	if(!is_empty(s)){
		int i=s->front;
		do{
			i=(i+1)%s->size;
			printf("%d | ",s->data[i]);
			if(i==s->rear){
				break;
			}
		}while(i != s->front);
	}
	printf("\n");
}

int main(void){

	int item;
	que*S=(que*)malloc(sizeof(que));
	
	create(S,5);
	
	printf("----push queue----\n");
	while(!is_full(S)){
		printf("number: ");
		scanf("%d",&item);
		enque(S,item);
		que_print(S);
	}
	printf("====queue is full====\n");
	
	printf("----pop queue----\n");
	while(!is_empty(S)){
		printf("output : %d\n",deque(S));
		que_print(S);
	}
	printf("====queue is empty====\n");
	free(S);
	return 0;
}
































/*
typedef struct que{
    char *data;
    int front;
    int rear;
    int size;
}que;

void error(char*a){
    fprintf(stderr, "%s\n",a);
    exit(1);
}

void create(que*s,int n){
    s->size=n;
    s->front=-1;
    s->rear=-1;
    s->data=(char*)malloc((s->size)*sizeof(char));
}

int is_full(que*s){
    return ((s->rear)+1)%s->size == s->front;
}

int is_empty(que*s){
    return s->front == s->rear;
}

void enque(que*s, char*a){
    if(is_full(s)){
	error("queue is full\n");
    }
    s->rear=((s->rear)+1)%s->size;
    s->data= a;
}

char* deque(que*s){
    if(is_empty(s)){
	error("queue is free\n");
    }
    s->front=((s->front)+1)%s->size;
    return s->data;
}

char* peek(que*s){
    if(is_empty(s)){
	error("queue is empty\n");
    }
    return s->data;
}

void print_que(que*s){
    printf("QUEUE(front-%d rear=%d) = ",s->front,s->rear);
    if(!is_empty(s)){
	int i=s->front;
	do{
	    i=(i+1)%(s->size);
	    printf("%s | ",s->data);
	    if(i==s->rear){
		break;
	    }
	}while(i != s->front);
    }
    printf("\n");
}

int main(void){

    char*input=(char*)malloc(5*sizeof(char));

    que*S=(que*)malloc(sizeof(que));
    create(S,5);

    while(!is_full(S)){
	printf("Write the String : \n");
	scanf("%s",input);
	enque(S,input);
	print_que(S);
    }

    printf("QUEUE is full\n\n");

    printf("QUEUE is full\n");

    while(!is_empty(S)){
	printf("output is : %s",deque(S));
	print_que(S);
    }

    printf("QUEUE si empty\n");
    
    free(S);
    return 0;
}
*/


