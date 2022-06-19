#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void decoding(char*argv0, char*argv1){
	int count=0;
	FILE* fp1 = fopen(argv0, "rb");
	FILE* fp2 = fopen(argv1, "a");
	FILE* fp3 = fopen("copy.txt","w");
	char *str=(char*)malloc(sizeof(char));
	char*temp=(char*)malloc(sizeof(char));
	char*ptr=(char*)malloc(sizeof(char));
	while(!feof(fp1)){
		fread(str,2*sizeof(char),1,fp1);
		fprintf(fp3,"%s",str);
		if(strchr(str,'\n')){
			count++;
		}
	}
	count=count/4;
	fclose(fp1);
	fclose(fp3);
	int i=0;
	FILE*fp4=fopen("copy.txt","r");
	fprintf(fp2,"%s\n","*FRIEND LIST*");
	while(!feof(fp4)){
		fgets(temp,count*sizeof(temp),fp4);
		fprintf(fp2,"FRIEND%d ID: %s",i+1,temp);
		fgets(temp,count*sizeof(temp),fp4);
		fprintf(fp2,"FRIEND%d NAME: %s",i+1,temp);
		fgets(temp,count*sizeof(temp),fp4);
		char*p=strstr(temp,"FM");
		char*k=strstr(temp,"M");
		if(p){
			strcpy(temp,"FEMALE\n");
		}
		else if(k){
			strcpy(temp,"MALE\n");
		}
		fprintf(fp2,"FRIEND%d GENDER: %s",i+1,temp);
		fgets(temp,count*sizeof(temp),fp4);
		fprintf(fp2,"FRIEND%d AGE: %s\n",i+1,temp);
		i++;
		if(i==count){
			exit(1);
		}
	}
	fclose(fp2);
	fclose(fp4);

}

int main(int argc, char* argv[]) {

	decoding(argv[1],argv[2]);
	
	return 0;
}
