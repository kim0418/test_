#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 10

typedef struct Stack{
	int top;
	int size;
	int *data;
}Stack;

void create(Stack*s,int n){
	s->size=n;
	s->top=-1;
	s->data=(int*)malloc(s->size*sizeof(int));
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

int eval(char arr[]){
	int op1,op2,value;
	int len=strlen(arr);
	char ch;
	Stack*S=(Stack*)malloc(sizeof(Stack));
	
	create(S,len);
	for(int i=0;i<len;i++){
		ch=arr[i];
		if(ch != '+' && ch !='-' && ch !='*' && ch != '/'){
			value=ch-'0';
			push(S,value);
		}
		else{
			op2=pop(S);
			op1=pop(S);
			switch(ch){
				case '+': push(S,op1+op2); break;
				case '-': push(S,op1-op2); break;
				case '*': push(S,op1*op2); break;
				case '/': push(S,op1/op2); break;
			}
		}
	}
	return pop(S);
}


int main(void){

	int result;
	printf("afterline is 82/3-32*+\n");
	result=eval("82/3-32*+");
	printf("result = %d\n",result);
	
	return 0;
}






