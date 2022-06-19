#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetStrLen(const char *ap_info)

{
     const char *p_start = ap_info;
     while(*ap_info)
     {
         ap_info++;
     }
     return ap_info - p_start;
}

int ChangeString(char *ap_info, int a_find_len, char *ap_change_info)
{
     char *p_end_pos = ap_info + a_find_len;
     int replace_size = GetStrLen(ap_change_info);
     if(replace_size > a_find_len)
     {
         char *p_src = ap_info + GetStrLen(ap_info);
         char *p_dest = p_src + replace_size - a_find_len;
         while(p_src != (p_end_pos -1)) *p_dest-- = *p_src--;
         while(*ap_change_info) *ap_info++ = *ap_change_info++;
     }
     else
     {
         while(*ap_change_info) *ap_info++ =*ap_change_info++;
         if(a_find_len != replace_size)
         {
             while(*p_end_pos) *ap_info++ = *p_end_pos++;
             *ap_info = 0;
         }
     }
     return replace_size;
}

void ReplaceString(char *ap_info, char *ap_find_info, char *ap_change_info)
{

    int len;
    while(*ap_info)

    {
        if(*ap_info == *ap_find_info)
        {
            for(len = 1; *(ap_find_info + len); len++)
            {

                if(*(ap_info + len) != *(ap_find_info + len))break;
            }
            if(*(ap_find_info + len)==0)
            {
                ap_info = ap_info + ChangeString(ap_info, len, ap_change_info);
            }else ap_info++;
        }else ap_info++;
    }
}

void status_read(char*argv1,char*argv2) {
    
        FILE* fp = fopen(argv1, "rb");
            if(fp == NULL) {
                        printf("FILE OPEN FAIL...\n");
                        exit(0);
            }
            int count = 0;
		char*info=(char*)malloc(sizeof(char));
            FILE* fp1 = fopen("com.txt","w");

            while(1) {
                        fgets(info, sizeof(info), fp);
                        if(feof(fp)){break;}
                        if(!strcmp(info,"<<")){
                        	break;
                        }
                        fprintf(fp1, "%s", info);
            }

            fclose(fp1);
            fclose(fp);
            
            FILE* fp0 = fopen(argv2, "w");
            FILE* fp2 = fopen("com.txt","r");

            char* info1=(char*)malloc(sizeof(char));

            while(!feof(fp2)) {
                        fgets(info1, 2*sizeof(info1), fp2);
                        char*ptr2=strstr(info1,"<<");
                        char* ptr1 = strstr(info1, "<");
                        if(strstr(info1,"<<")){
                        	break;
                        }
                        else if(strstr(info1,"<")) {
                                    ReplaceString(info1, "<", "*ITEMS*");
                        }

                        ReplaceString(info1, "#", "BOOM: ");
                        ReplaceString(info1, "&", "POTION: ");
                        ReplaceString(info1, "%", "SHIELD: ");
                        ReplaceString(info1, "$", "CURE: ");
                        ReplaceString(info1, "!", "BOOK: ");
                        ReplaceString(info1, "@", "CANNON: ");
         
           if(count == 0) {
                        fputs("*USER STATUS*\n", fp0);
                        count++;
            }
            if(count == 1)
                        fprintf(fp0, "ID : %s", info1);

            if(count == 2)
                        fprintf(fp0, "NAME : %s", info1);

            if(count == 3)
                        fprintf(fp0, "GENDER : %s", info1);

            if(count == 4)
                        fprintf(fp0, "AGE: %s", info1);

            if(count == 5)
                        fprintf(fp0, "HP: %s", info1);

            if(count == 6)
                        fprintf(fp0, "MP: %s", info1);

            if(count == 7)
                        fprintf(fp0, "Coin: %s\n", info1);
            
            else if(count < 1 || count > 7)
                        fprintf(fp0, "%s", info1);
            count++;
            }
            fprintf(fp0,"%s","\n");
            fclose(fp0);
           fclose(fp2);
           
}

void decoding(char*argv1){
	int count=0;
	int num=0;
	char *str=(char*)malloc(sizeof(char));
	char*temp=(char*)malloc(sizeof(char));
	char*ptr=(char*)malloc(sizeof(char));
	FILE*fp3=fopen("com.txt","r");
	while(!feof(fp3)){
		fgets(str,sizeof(str),fp3);
		if(strstr(str,"<<")!=NULL){
			num=1;
		}
		if(num==1){
			while(fgets(str,sizeof(str),fp3)!=NULL){
				if(strstr(str,"<<<")){
					break;
				}
				else{
					count++;
				}
			}
		}
	}
	count=count/4;
	fclose(fp3);
	int i=0;
	int num1=0;
	FILE* fp2 = fopen(argv1, "a");
	FILE*fp4=fopen("com.txt","r");
	while(1){
		fgets(temp,count*sizeof(temp),fp4);
		if(strstr(temp,"<<<")){break;}
		if(strstr(temp,"<<")!=NULL){
			num1=1;
		}
		if(num1==2){
			fprintf(fp2,"FRIEND%d ID: %s",i+1,temp);
			fgets(temp,count*sizeof(temp),fp4);
			fprintf(fp2,"FRIEND%d NAME: %s",i+1,temp);
			fgets(temp,count*sizeof(temp),fp4);
			char*p=strstr(temp,"FM");
			char*k=strstr(temp,"M");
			if(k){
				strcpy(temp,"MALE\n");
			}
			if(p){
				strcpy(temp,"FEMALE\n");
			}
			fprintf(fp2,"FRIEND%d GENDER: %s",i+1,temp);
			fgets(temp,count*sizeof(temp),fp4);
			fprintf(fp2,"FRIEND%d AGE: %s\n",i+1,temp);
			i++;
		}
		if(num1==1){
			fprintf(fp2,"%s\n","*FRIEND LIST*");
			fgets(temp,count*sizeof(temp),fp4);
			fprintf(fp2,"FRIEND%d ID: %s",i+1,temp);
			fgets(temp,count*sizeof(temp),fp4);
			fprintf(fp2,"FRIEND%d NAME: %s",i+1,temp);
			fgets(temp,count*sizeof(temp),fp4);
			char*p=strstr(temp,"FM");
			char*k=strstr(temp,"M");
			if(k){
				strcpy(temp,"MALE\n");
			}
			if(p){
				strcpy(temp,"FEMALE\n");
			}
			fprintf(fp2,"FRIEND%d GENDER: %s",i+1,temp);
			fgets(temp,count*sizeof(temp),fp4);
			fprintf(fp2,"FRIEND%d AGE: %s\n",i+1,temp);
			i++;
			num1++;
		}
		if(i==count){
			break;
		}
	}
	fclose(fp2);
	fclose(fp4);

}

void des(char*argv1,char*argv2){
 int num=0;
 FILE *fp6 = fopen(argv2,"a");
  //FILE* fp1 = fopen(argv1,"rb");
  //??????FILE*fp2 = fopen("dec.txt","wt");
  FILE* fp4 = fopen("recover.txt","wt");
  /*while(!feof(fp1)){
    char arr0[30] = "";
    fread(arr0,sizeof(arr0),1,fp1);
    fprintf(fp2,"%s",arr0);
  }*/
  //fclose(fp1);
  //fclose(fp2);
  //FILE* fp3 = fopen("dec.txt","rt");
   FILE* fp3=fopen("com.txt","r");
   char arr[30] = "";
  while(!feof(fp3)){
  fgets(arr,sizeof(arr),fp3);
  if(strstr(arr,"<<<")!=NULL){
	fprintf(fp6,"%s\n","*DESCRPTION*");
  	num=1;
  	fgets(arr,sizeof(arr),fp3);
  }
  if(num==1){
    //fgets(arr,sizeof(arr),fp3);
    if(strstr(arr,"{")){break;}
    char new_arr[50] = "";
    for (int i = 0; i < strlen(arr); i++)
    {
      char re[50] = "";
      char temp[50] = "";
      char one_temp[50] = "";
      if (arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' || arr[i] == '6' || arr[i] == '7' || arr[i] == '8' || arr[i] == '9')
      {
        int k = arr[i] - 48;
        i++;
        while (arr[i] != ',')
        {
          int j = 0;
          re[j] = arr[i];
          strcat(temp, re);
          i++;
        }

        for (int j = 0; j < k; j++) {
          strcat(new_arr, temp);
        }
      }else
 {
        one_temp[0] = arr[i];
        strcat(new_arr, one_temp);
      }
    }

  for(int i =0; i<strlen(new_arr); i++)
  {
      if(new_arr[i] == '~')
         new_arr[i] = '0';
      if(new_arr[i] == '!')
         new_arr[i] = '1';
      if(new_arr[i] == '@')
         new_arr[i] = '2';
      if(new_arr[i] == '#')
         new_arr[i] = '3';
      if(new_arr[i] == '$')
         new_arr[i] = '4';
      if(new_arr[i] == ')')
         new_arr[i] = '5';
      if(new_arr[i] == '^')
         new_arr[i] = '6';
      if(new_arr[i] == '&')
         new_arr[i] = '7';
      if(new_arr[i] == '-')
         new_arr[i] = '8';
      if(new_arr[i] == '(')
        new_arr[i] = '9';
}

    fputs(new_arr,fp4);
    }
 }
fclose(fp3);
fclose(fp4);
  FILE *fp5 = fopen("recover.txt","rt");
  //FILE *fp6 = fopen(argv2,"a");
  //fprintf(fp6,"%s","*DESCRTIPTION*\n");

  while(!feof(fp5))
{
  char qwer[50] = "";
  char new_str[50] = "";


  fgets(new_str,sizeof(new_str),fp5);
  for(int i = 0; i<strlen(new_str); i++)
  {
 char nnew_str[50] = "";

  if(new_str[i] == 'a')
      {
        nnew_str[0] = 'A';
        nnew_str[1] = 'A';
        nnew_str[2] = 'A';
        nnew_str[3] = 'B';
        nnew_str[4] = 'B';
        nnew_str[5] = 'B';
        nnew_str[6] = 'A';
        nnew_str[7] = 'A';
        nnew_str[8] = 'D';
        nnew_str[9] = 'D';
        nnew_str[10] = 'E';
        nnew_str[11] = 'E';
        nnew_str[12] = 'G';
        nnew_str[13] = 'A';
        nnew_str[14] = 'G';
        nnew_str[15] = 'G';

  strcat(qwer,nnew_str);
}
  else if(new_str[i] == 'b')
    {
      nnew_str[0] = 'A';
      nnew_str[1] = 'A';
      nnew_str[2] = 'B';
      nnew_str[3] = 'B';
      nnew_str[4] = 'B';
      nnew_str[5] = 'A';
      nnew_str[6] = 'A';
      nnew_str[7] = 'D';
      nnew_str[8] = 'D';
      nnew_str[9] = 'E';
      nnew_str[10] = 'E';
      nnew_str[11] = 'G';
      nnew_str[12] = 'A';
      nnew_str[13] = 'G';
      nnew_str[14] = 'G';

      strcat(qwer,nnew_str);
    }
  else if(new_str[i] == 'c')
{
      nnew_str[0] = 'A';
      nnew_str[1] = 'A';
      nnew_str[2] = 'A';
      nnew_str[3] = 'A';
      nnew_str[4] = 'B';
      nnew_str[5] = 'B';
      nnew_str[6] = 'C';
      nnew_str[7] = 'B';
      nnew_str[8] = 'B';
      nnew_str[9] = 'C';
      nnew_str[10] = 'B';
      nnew_str[11] = 'B';
      nnew_str[12] = 'C';

    strcat(qwer,nnew_str);
}
  else if(new_str[i] == 'd')
{
      nnew_str[0] = 'Z';
      nnew_str[1] = 'Z';
      nnew_str[2] = 'K';
      nnew_str[3] = 'K';
      nnew_str[4] = 'Z';
      nnew_str[5] = 'Z';
      nnew_str[6] = 'K';
      nnew_str[7] = 'K';
      nnew_str[8] = 'Z';
      nnew_str[9] = 'Z';
      nnew_str[10] = 'K';
      nnew_str[11] = 'K';

    strcat(qwer,nnew_str);
}
  else if(new_str[i] == 'e')
{
      nnew_str[0] = 'H';
      nnew_str[1] = 'E';
      nnew_str[2] = 'L';
      nnew_str[3] = 'L';
      nnew_str[4] = 'O';

  strcat(qwer,nnew_str);
}
  else if(new_str[i] == 'f')
{
      nnew_str[0] = 'Z';
      nnew_str[1] = 'Z';
      nnew_str[2] = 'K';
      nnew_str[3] = 'K';

      strcat(qwer,nnew_str);
}
  else if(new_str[i] == 'g')
{
      nnew_str[0] = 'G';
      nnew_str[1] = 'A';
      nnew_str[2] = 'G';
      nnew_str[3] = 'G';

      strcat(qwer,nnew_str);
}
  else if(new_str[i] == 'h')
{
      nnew_str[0] = 'B';
      nnew_str[1] = 'B';
      nnew_str[2] = 'C';

      strcat(qwer,nnew_str);
      //printf("%s",qwer);
      }
      else if(new_str[i] == 'n')
 {
       nnew_str[0] = 'A';
       nnew_str[1] = 'B';
       nnew_str[2] = 'C';
       nnew_str[3] = 'D';
       nnew_str[4] = 'E';

       strcat(qwer,nnew_str);
 }
else if(new_str[i] == 'k')
 {
       nnew_str[0] = 'A';
       nnew_str[1] = 'B';
       nnew_str[2] = 'C';
       nnew_str[3] = 'D';

       strcat(qwer,nnew_str);
 }
else if(new_str[i] == 'm')
 {
       nnew_str[0] = 'A';
       nnew_str[1] = 'B';
       nnew_str[2] = 'C';

       strcat(qwer,nnew_str);
 }
 else if(new_str[i] == 'j')
 {
       nnew_str[0] = 'B';
       nnew_str[1] = 'Y';
       nnew_str[2] = 'E';

       strcat(qwer,nnew_str);
 }    
  else
{
  nnew_str[0] = new_str[i];
  strcat(qwer,nnew_str);
}
}
    fprintf(fp6,"%s",qwer);

}
  //char fname[10] = "dec.txt";
  //remove(fname);

fclose(fp5);
fclose(fp6);
}

void revise(char*argv1,char*argv2){
  FILE*fp1=fopen(argv1,"rb");
  FILE*fp4=fopen(argv2,"r");
  FILE *fp2 = fopen("a1.txt","wt");
  FILE *fp99 = fopen("a2.txt","wt");
  int count = 0;
  while(!feof(fp1)){
    char *str = (char*)malloc(200*sizeof(char));
    fread(str,4*sizeof(str),1,fp1);
    if(strstr(str,"{")!= NULL){
      count = 1;
      fread(str,sizeof(str),1,fp1);

      }
    if(strstr(str,"}")!= NULL){
      count = 2;
      fread(str,sizeof(str),1,fp1);
      }
    if(count == 1){
      fprintf(fp2,"%s",str);
    }
  }
  fclose(fp1);
  fclose(fp2);
  //fclose(fp99);
  FILE *fp3 = fopen("a1.txt","rt");
  int arr[50][50] = {0,}; 
  int i = 0;
  while(!feof(fp3)){
    fscanf(fp3,"%d",arr[i]);
    i++;
  }
  int len = i;
  fclose(fp3);
  int wide[50][50] = {0,};
  int askii = 0;
  int askiisum = 0;
  char new_arr[50][50]= {0,};
  i = 0;
  while(!feof(fp4)){
    fgets(new_arr[i],100,fp4);
    i++;
  }
  fclose(fp4);
  for(i = 0; i < len; i++){
    askiisum = 0;
    for(int j = 0; j < 50; j++){
      askii = new_arr[i][j] - 0;
      askiisum = askiisum + askii;
      if(new_arr[i][j] == 0){
        wide[i][0] = askiisum;
        break;
      }
    }
  }
for(i = 0; i < len; i++){
  if(arr[i][0] != wide[i][0]){
    printf("LINE NUMBER: %d ERROR",i+1);
  }
  }
}

int main(int argc, char*argv[]){

	status_read(argv[1],argv[2]);
	decoding(argv[2]);
	des(argv[1],argv[2]);
	//revise(argv[1],argv[2]);
	return 0;
}
