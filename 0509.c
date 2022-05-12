#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define MAX 50

typedef struct Stack{
	int size;
	int top;
	char *data;
}Stack;

void create(Stack*s,int n){
	s->size=n;
	s->top=-1;
	s->data=(char*)malloc(s->size*sizeof(char));
}

int is_full(Stack*s){
	return s->top==s->size;
}

int is_empty(Stack*s){
	return s->top==-1;
}

void push(Stack*s, char a){
	if(is_full(s)){
		fprintf(stderr,"PUSH ERROR\n");
		return ;
	}
	s->top++;
	s->data[s->top]=a;
}

char pop(Stack*s){
	if(is_empty(s)){
		fprintf(stderr,"POP ERROR\n");
		exit(1);
	}
	return s->data[(s->top)--];
}

char peek(Stack*s){
	if(is_empty(s)){
		fprintf(stderr,"empty error\n");
		exit(1);
	}
	return s->data[s->top];
}

int prec(char op){
	switch(op){
		case '(': case ')': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
	}
	return -1;
}

int eval(char arr[]){
	int op1,op2,value;
	int len=strlen(arr);
	char ch;
	
	Stack*S=(Stack*)malloc(len*sizeof(Stack));
	create(S,len);
	
	for(int i=0;i<len;i++){
		ch=arr[i];
		if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){
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
				case '/': 
					if(op2==0){
						fprintf(stderr,"you can't Divide with Zero\n");
						exit(1);
					}
					else{
						push(S,op1/op2); break;
					}
			}
		}
	}
	return pop(S);
}

char* to_postfix(char *arr){
	char ch,top_op;
	int idx=0;
	int len=strlen(arr);
	
	Stack*S=(Stack*)malloc(len*sizeof(Stack));
	create(S,len);
	char *post_arr=(char*)malloc(len*sizeof(char));
	
	for(int i=0;i<len;i++){
		ch=arr[i];
		switch (ch){
			case '+': case '-' : case '*': case '/':
				while(!is_empty(S) && (prec(ch) <= prec(peek(S)))){
					post_arr[idx++]=peek(S);
					pop(S);
				}
				push(S,ch);
				break;
			case '(':
				push(S,ch);
				break;
			case ')':
				top_op=pop(S);
				while(top_op !='('){
					post_arr[idx++]=top_op;
					top_op=pop(S);
				}
				break;
			default:
				post_arr[idx++]=ch;
				break;
		}
	}
	while(!is_empty(S)){
		top_op=peek(S);
		pop(S);
		post_arr[idx++]=top_op;
	}
	post_arr[idx]='\0';
	return post_arr;
}

int main(void){

	int result;
	char *tes = (char*)malloc(MAX*sizeof(char));
	printf("infix : ");
	scanf("%s",tes);
	
	printf("postfix = %s\n",to_postfix(tes));
	result = eval(to_postfix(tes));
	printf("infix to postfix result = %d\n",result);

	free(tes);	
	return 0;
}




