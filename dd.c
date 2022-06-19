#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void revise(char*argv1,char*argv2){
  FILE*fp1=fopen(argv1,"rb");
  FILE*fp4=fopen(argv2,"r");
  FILE *fp2 = fopen("a1.txt","wt");
  FILE *fp99 = fopen("a2.txt","wt");
  int count = 0;
  while(!feof(fp1)){
    char *str = (char*)malloc(sizeof(char));
    str = (char*)calloc(30,sizeof(char));
    fread(str,sizeof(str),1,fp1);
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
    if(count == 1){
      fprintf(fp99,"%s",str);
    }

  }  // 기존 바이너리파일에서  내가 필요한 부분(descrption 뒷부분만 텍스트파일에 저장시킴)
  fclose(fp1);
  fclose(fp2);
  FILE *fp3 = fopen("a1.txt","rt"); //저장시킨 부분을 바이너리
  int arr[50][50] = {0,}; // 기존 바이너리 파일에 있는 아스키코드의 합을 배열로 저장
  int i = 0;
  while(!feof(fp3)){
    fscanf(fp3,"%d",arr[i]);
    i++;
  } // 저장되어있던 값을 배열에 넣음
  int len = i;
  fclose(fp3);
  int wide[50][50] = {0,}; //새로 만든 가로 아스키값의 합 배열로 저장
  int askii = 0;
  int askiisum = 0;
  char new_arr[50][50]= {0,};
  i = 0;
  while(!feof(fp4)){
    fgets(new_arr[i],100,fp4);
    i++;
  } //변조처리된 파일을 저장
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
  } // 변조처리된 값의 아스키코드의 합을 구함
for(i = 0; i < len; i++){
    printf("%d, %d ",arr[i][0],wide[i][0]);
  if(arr[i][0] != wide[i][0]){
    printf("%d 줄에서 오류 발생",i+1);
  }
  }
}
int main(int argc ,char* argv[]){
  FILE *fp9;
  FILE *fp10;
  fp9 = fopen(argv[1],"rb");
  fp10 = fopen(argv[2],"r");
  revise(fp9,fp10);
}
