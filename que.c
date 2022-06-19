#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


typedef char element;
typedef struct que{
	int front;
	int rear;
	int size;
	element **data;
}que;

void error(char *arr){
	fprintf(stderr,"%s\n",arr);
	exit(1);
}

void create(que*s,int n){
	s->front=-1;
	s->rear=-1;
	s->size=n;
	s->data = (char **)malloc(s->size * sizeof(char *));
	for(int i=0;i<s->size;i++){
		s->data[i]=(element*)malloc(n*sizeof(element));
	}
}

void que_print(que*s){
	printf("\n");
	for(int i=0;i<(s->size);i++){
		if(i<=s->front || i>s->rear){
			printf("|");
		}
		else{
			printf("%s| ",s->data[i]);
		}
	}
	printf("\n");
}

int is_full(que*s){
	return ((s->rear)==(s->size)-1);
}

int is_empty(que*s){
	return s->front == s->rear;
}

void enque(que*s, char* item){
	if(is_full(s)){
		error("queue is full\n");
		return;
	}
	strcpy(s->data[++(s->rear)],item);
}

char* deque(que*s){
	if(is_empty(s)){
		error("queue is empty\n");
		exit(1);
	}
	return s->data[++(s->front)];
}

int main(void){
	
	char put[5];
	char *item=(char*)malloc(30*sizeof(char));
	
	que*S=(que*)malloc(sizeof(que));
	create(S,5);
	
	for(int i=0;i<5;i++){
		fgets(item,30,stdin);
		item[strlen(item)-1]='\0';
		enque(S,item);
		que_print(S);
	}
	
	for(int i=0;i<5;i++){
		strcpy(put,deque(S)); que_print(S);
	}
	
	free(S);
	
	return 0;
}









/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;
typedef struct {
	element* data;
	int front;
	int rear;
	int size;
}Queue;

void InitQueue(Queue* q, int size) {
	q->data = (element*)malloc(sizeof(element) * size);
	if (q->data == NULL) return;
	q->front = 0;
	q->rear = 0;
	q->size = size;
}
bool is_full(Queue* q) {
	if ((q->rear + 1) % q->size == q->front) return true; //(rear + 1) % size == front
	else return false;
}
bool is_empty(Queue* q) {
	if (q->front == q->rear) return true;
	else return false;
}
void printQueue(Queue* q) {
	for (int i = (q->front + 1) % q->size; i != (q->rear + 1) % q->size; i = (i + 1) % q->size) {
		printf("%d ", *(q->data + i));
	}
	printf("\n");
}
void enqueue(Queue* q, element data) {
	if (is_full(q)) {
		printf("Queue is full.\n");
		return;
	}
	else {
		q->rear = (q->rear + 1) % q->size;
		*(q->data + q->rear) = data;
	}
}
element dequeue(Queue* q) {
	if (is_empty(q)) {
		printf("Queue is empty.\n");
		return -1;
	}
	else {
		q->front = q->front + 1 % q->size;
		return *(q->data + q->front);
	}
}
int main(void) {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL) return -1;

	InitQueue(q, 8);

	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);

	printQueue(q);

	dequeue(q);
	dequeue(q);

	printQueue(q);

	dequeue(q);
	dequeue(q);

	printQueue(q);

	free(q->data);
	free(q);

	return 0;
}
*/




