#include<stdio.h>
#include<stdlib.h>

int main(void){

	FILE *fp=fopen("smaple.txt","w");

	if(fp==NULL){
		fprintf(stderr, "file open fail\n");
		exit(1);
	}
	
	char c;
	fprintf(fp,"/");
	for(c='A';c<='k';c++){
		fprintf(fp,"%c",c);
	}

	fclose(fp);
	return 0;
}
