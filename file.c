#include<stdio.h>
#include<stdlib.h>

int main(void){

	FILE *fp=fopen("smaple.txt","a");

	if(fp==NULL){
		fprintf(stderr, "file open fail\n");
		exit(1);
	}
	
	char c;
	for(c='A';c<='Z';c++){
		fprintf(fp,"%c",c);
	}

	fclose(fp);
	return 0;
}
