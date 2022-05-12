#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>


typedef struct Stack{
	int size;
	int top;
	int **prize;
	char **player;
}Stack;

void create(Stack*s,int n){
	s->size=n;
	s->top=-1;
	for(int i=0;i<n;i++){
		s->player[i]=(char**)malloc(s->size*sizeof(char*));
		s->prize[i]=(int**)malloc(s->size*sizeof(int*));
	}
}

int is_empty(Stack*s){
	return s->top==-1;
}

int is_full(Stack*s){
	return s->top==s->size;
}

void push(Stack* s, char *a, int n){
	if(is_full(s)){
		fprintf(stderr, "PUSH ERROR\n");
		return;
	}
	else{
		(s->top)++;
		strcpy(s->data[s->top],a);
		s->prize[s->top]=n;
	}
}

int pop_2(Stack*s){
	if(is_empty(s)){
		fprintf(stderr,"POP ERROR\n");
		exit(1);
	}
	return s->prize[(s->top)--];
}

char* pop(Stack* s){
	if(is_empty(s)){
		fprintf(stderr,"POP ERROR\n");
		exit(1);
	}
	return s->player[(s->top)--];
}

void is_big(Stack*s){
	int big=0;
	int tmp=0;
	for(int i=0;i<s->size-1;i++){
		if(s->prize[s->top]<s->prize[++(s->top)]){
			big=s->prize[++(s->top)];
			tmp=s->top;
		}
		else{
			big = s->prize[s->top];
			tmp=s->top;
		}
	}
	printf("%d %s\n",big,s->player[tmp]);
}

int main(void){
	
	int **rise;
	char **play;
	int num=0;
	scnaf("%d",&num);
	
	Stack* S=(Stack*)malloc(sizeof(Stack));
	create(S,num);
	
	for(int i=0;i<n;i++){
		play[i]=(char**)malloc(s->size*sizeof(char*));
		rise[i]=(int**)malloc(s->size*sizeof(int*));
	}
	
	for(int i=0;i<num;i++){
		scanf("%d",play[i]);
		for(int j=0;j<rise;j++){
			scanf("%d",rise[j]);
			scnaf("%s",play[j]);
			push(S,rise,play[i]);
		}
		
	}
	

	return 0;
}






/*10798
int main(){

	char **arrs=(char**)malloc(7*sizeof(char*));
	for(int i=0;i<5;i++){
		arrs[i]=(char*)malloc(7*sizeof(char));
		scanf("%s",arrs[i]);
	}
	for(int i=0;i<15;i++){
		for(int j=0;j<6;j++){
			if(arr[j][i] != \0){
				printf("%c",arr[j][i]);
			}
		}
	}
	return 0;
}*/



/*10987
int main(void){
	
	char *arr=(char*)malloc(sizeof(char));
	int count=0;
	
	scanf("%s",arr);
	
	for(int i=0;i<strlen(arr);i++){	
		if(arr[i] =='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u'){
			count++;
		}
	}
	printf("%d\n",count);

	return 0;
}
*/




