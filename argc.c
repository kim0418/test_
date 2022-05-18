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
    int count=0;
    char str[100];
    char cur[100];
    while(!feof(fp1)){
    	fgets(str,100,fp1);
    	char*p=strstr(str,"int ");
    	if(p){
    		strncpy(p,"double ",7);
    		count++;
    	}
    	fputs(str,fp2);
    }
    fclose(fp1);
    fclose(fp2);

    FILE*fp3=fopen("copy2.txt","r");
    while((fgets(cur,100,fp3)!=NULL)){
	printf("%s\n",cur);
    }
    fclose(fp3);
    printf("총 %d개의 int가 double로 변경되었습니다.\n",count);
}

void analysis(char* argv){
	int count1=0;
	int count2=0;
	char str[100];
	FILE*fp=fopen(argv,"r");
	while(!feof(fp)){
		fgets(str,100,fp);
		if(strstr(str,"int ")!=NULL){
			//printf("%s\n",str);
			count1++;
		}
		if(strstr(str,"double ")!=NULL){
			//printf("%s\n",str);
			count1++;
		}
		else if(strstr(str,"void")!=NULL){
			count2++;
		}
	}
	printf("본 코드에 사용된 변수 %d개\n", count1);
	printf("본 코드에 사용된 함수 %d개\n", count2);
}

void option_handler(OPTION opt, char* argv){
	     
    switch(opt){
	case LIST:
	    file_list(argv);
	    break;
	case HELP:
	    printf("file.exe -list file-name  == 파일 내용 확인하기\n");
	    printf("file.exe -listcount file-name  == 파일 총 라인갯수 확인하기 \n");
	    printf("file.exe -replace file-name int double == 파일내 int를 double로 변환 \n");
	    printf("file.exe -analysis file-name  ==  사용된 변수와 함수의 개수 출력하기\n");
	    break;
	case LISTCOUNT:
	    printf("code line is = %d\n",line_count(argv));
	    break;
	case REPLACE:
	    file_replace(argv);
	    break;
	case ANALYSIS:
	    analysis(argv);
	    break;
    }
}

int main(int argc,char * argv[]){
    

    printf("total # of arg %d\n",argc);

    for(int i=0;i<argc;i++){
	printf("ARG %d = %s\n",i,argv[i]);
    }
	printf("\n");
    if(argv[1]==NULL){
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
