#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int count=0;

int f_count=0;

typedef struct list{
	char** name;
	int **age;
	char** mail;
}list;

void file_open(list *s,listmanager* control){
	
	s->name=(list**)malloc(30*sizeof(list*));
	
	FILE *fp;
	fp=fopen("test.txt","r");
	if(fp==NULL){
		fprintf(stderr,"file is not open\n");
		exit(1);
	}
	
	s->count=0;
	do{
		fscanf(fp,"%[^/]s",s->name[count]);
		fscanf(fp,"%[^/]d",s->age[count]);
		fscanf(fp,"%[^/]s",s->mail[i]);
		
		count++;
	}while(!feof(fp));
	fclose(fp);
}

void insert(list*s){
	char p; 
	int rutin=1;
	do{
	if(count<255){
		printf("이름: ");;
		scanf("%[^/]s/",s->name[count]);
		printf("나이: ");
		scanf("%[^/]d/",s->age[count]);
		printf("이메일: "); ");
		scanf("%[^/]s",s->mail[count]);
		count++;
	}
		printf("계속 입력할까요?(Y/N) : ");
		scanf("%c",&p);
		if(ch=='y' || ch=='Y'){
			rutin=1;
			printf("\n");
		}
		else if(ch=='n' || ch=='N'){
			printf("입력이 완료되었습니다.\n\n");
			retin =0;
		}
	}while(rutin);
}

void recover(list* s){
	int num=0;
	char*chack=(char*)malloc(50*sizeof(char));
	printf("수정할 사람 이름을 입력해주세요:");
	scanf(" %[^\ns",chack);
	
	do{
		if(strcmp(s->name)
		printf("사용자 %s을 수정합니다.\n",rc_name); //출력

		printf("이름:");
		scanf(" %[^\n]s",p[i].name);

		printf("나이:");
		scanf(" %d",&p[i].age);

		printf("이메일:");
		scanf(" %s",p[i].email);
		num-1;
		
	}while(num);
	
}

int menu(){
	int num;
	printf("1. insert \n"); printf("2. recover \n"); printf("3. delete \n"); printf("4. List_view \n"); printf("5. EXIT \n");
	printf("chose the menu : ");
	scanf("%d",&num);
	return num;
}

int input(list*s){
	int num=0;
	printf("choose nunmer : ");
	scanf("%d", &num);
	
	switch(num){
		case 1: insert(s); break;
		case 2: recover(S); break;
		case 3: delete(S); break;
		case 4: printf_list(S); break;
		case 5: printf("EXIT\n"); exit(1);
		default: printf("please insert 1~5");
	}
}

int main(void){
	
	list*S=(list*)malloc(sizeof(list));
	list* head;
	list* last;
	list* node;
	
	
	file_open(S);
	do{
		munu();
		input(S);
	}while(1);

	return 0;
}



