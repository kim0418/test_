#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void decoding(char*argv0, char*argv1){
	char *cur=malloc(sizeof(char));
	FILE*fp1=fopen(argv0,"rb");
	FILE*fp2=fopen(argv1,"a");
	char*str=malloc(sizeof(char));
	fread(str,sizeof(str),1,fp1);
	int a=str[0]-'0';
	for(int i=1;i<a+1;i++){
		fprintf(fp2,"FRIEND%d ID: %s\n",i,str);
		fprintf(fp2,"FRIEND%d NAME: %s\n",i,str);
		fprintf(fp2,"FRIEND%d GENDER: %s\n",i,str);
		fprintf(fp2,"FRIEND%d AGE: %s\n",i,str);
	}
}

int main(int argc, char* argv[]){

	decoding(argv[0],argv[1]);

	return 0;
}













































/*typedef struct friend{
	char a_id[255];
	char a_name[255];
	char a_gender[255];
	int a_age;
}friend;

typedef struct list{
	char ID[255];
	char NAME[255];
	char GENDER[255];
	int HP;
	int MP;
	int AGE;
	unsigned short int coin;
	int BOMB;
	int POTTION;
	int CURE;
	int BOOK;
	int count;
	struct friend fri[255];
}list;

void program(list*s,char*argv){
	FILE* q=fopen(argv,"rb");
	if(q==NULL){
		fprintf(stderr,"Bin_File is NULL");
		exit(1);
	}
	FILE* fp=fopen("new.txt","w");
	while(1){
		fread(s,sizeof(s),1,q);
		fputs(s,fp);
		if(feof(q)){
			break;
		}
		printf("*USER STATUS*\n");
		printf("ID: %s\n NAME: %s\n GENDER: %s\n HP: %d\n MP: %d\n AGE: %d\n Coin: %hu\n\n",s->ID,s->NAME,s->GENDER,s->HP,s->MP,s->AGE,s->coin);
		printf("*ITEM*\n");
		printf("BOMB: %d\n POTTON: %d\n CURE: %d\n BOOK: %d\n\n",s->BOMB,s->POTTION,s->CURE,s->BOOK);
		printf("*FRIEND LIST*\n");
		for(int i=0;i<s->count;i++){
			printf("FRIEND%d ID: %s\n FRIEND%d NAME: %s\n FRIEND%d GENDER: %s\n FRIEND%d AGE: %d\n\n",i+1,s->fri[i].a_id,i+1,s->fri[i].a_name,i+1,s->fri[i].a_gender,i+1,s->fri[i].a_age);
		}
	}
	fclose(q);
	fclose(fp);
}

int main(int argc, char *argv){

	struct list*s;
	//memset(%s,0,sizeof(s));
	program(&s,argv[1]);
	return 0;
}*/
