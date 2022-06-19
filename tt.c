#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*vlid file_list(char* argv){
	
	FILE* fp1=fopen(argv,"r");
	FILE* fp2=fopen("copy.bin","ab");
	char curr[100];
	char str[100];
	while(!feof(fp1)){
		fgets(curr,100,fp2);
		if(!strcmp("BOMB",curr){
			fwrite('@',fp2);
		}
		else if(!strcmp("POTTION",curr){
			fwrite('#',fp2);
		}
		else if(!strcmp("CURE",curr){
			fwrite('$',fp2);
		}
		else if(!strcmp("BOOK",curr){
			fwrite('%',fp2);
		}
		else if(strstr(curr,": "){
			str=strstr(curr,": ");
			fwrite(str,fp2);
		}
	}
}*/

int main(int argc, char*argv[]){

	FILE* fp1=fopen(argv[1],"r");
	FILE* fp2=fopen("copy.bin","ab");
	char curr[100];
	char str[100];
	while(!feof(fp1)){
		fgets(curr,100,fp2);
		if(!strcmp("BOMB",curr)){
			fwrite('@',sizeof(char),1,fp2);
		}
		else if(!strcmp("POTTION",curr)){
			fwrite('#',sizeof(char),1,fp2);
		}
		else if(!strcmp("CURE",curr)){
			fwrite('$',sizeof(char),1,fp2);
		}
		else if(!strcmp("BOOK",curr)){
			fwrite('%',sizeof(char),1,fp2);
		}
		else if(strstr(curr,": ")){
			str=strstr(curr,": ");
			fwrite(str,sizeof(str),sizeof(str)/sizeof(str[0]),fp2);
		}
	}


	return 0;
}
























/*
int main(int argc, char* argv[]){
	struct list*s;
	FILE*q=fopen(argv[1],"rb");
	if(q==NULL){
		fprintf(stderr,"error\n");
		exit(1);
	}
	FILE*fp=fopen("new.txt","w");
	while(1){
		fread(s,sizeof(s),1,q);
		
	}

	return 0;
}*/
