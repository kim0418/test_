#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum OPTION{
    LIST,
    HELP,
    ANALYSIS,
    LISTCOUNT,
    REPLACE,
}OPTION;

void file_list(char *argv){
	FILE *fp1,*fp2;
	fp1=fopen(argv,"r");
	fp2=fopen("copy.txt","w"); 
	char curr[100];
	char str[100];
	while(fgets(curr,100,fp1)){
		fputs(curr,fp2);
		
	}
	fclose(fp1);
	fclose(fp2);
	FILE*fp3=fopen("copy.txt","r");
	while((fgets(str,100,fp3)!=NULL)){
		printf("%s\n",str);
	}
	fclose(fp3);
}

int line_count(char *argv){
	FILE *fp;
	char ch;
	int count=0;
	fp=fopen(argv,"r");
	while(fscanf(fp,"%c",&ch)!=EOF){
		if(ch=='\n'){
			count++;
		}
	}
	fclose(fp);
	return count;
}
void file_replace(char* argv){
    FILE *fp1=fopen(argv,"r");
    FILE *fp2=fopen("copy2.txt","a");
    int count;
    int find;
    char str[100];
    char*p;
    
    
    printf("총 %d개의 int가 double로 변경되었습니다.\n",count);
}

void option_handler(OPTION opt, char* argv){
	     
    switch(opt){
	case LIST:
	    file_list(argv);
	    break;
	case HELP:
	    printf("file.exe -list file-name  ==  \n");
	    printf("file.exe -listcount file-name  == file linecount \n");
	    printf("file.exe -replace file-name int double == change int->double \n");
	    printf("file.exe -analysis file-name  ==  \n");
	    break;
	case LISTCOUNT:
	    printf("code line is = %d\n",line_count(argv));
	    break;
	case REPLACE:
	    file_replace(argv);
	    break;
	case ANALYSIS:
	    break;
    }
}

int main(int argc,char * argv[]){
    

    printf("total # of arg %d\n",argc);

    for(int i=0;i<argc;i++){
	printf("ARG %d = %s\n",i,argv[i]);
    }
	printf("\n");
    if(argc==1){
    	printf("insert option\n");
    }
    if(strcmp(argv[1],"-list") == 0){
	option_handler(LIST,argv[2]);
    }
    if(strcmp(argv[1],"-help") == 0){
	option_handler(HELP,argv[2]);
    }
    if(strcmp(argv[1],"-analysis") == 0){
	option_handler(ANALYSIS,argv[2]);
    }
    if(strcmp(argv[1],"-listcount") == 0){
	option_handler(LISTCOUNT,argv[2]);
    }
    if(strcmp(argv[1],"-replace") == 0){
	option_handler(REPLACE,argv[2]);
    }

    return 0;

}
