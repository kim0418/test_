 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define MAX 555 //최대크기 555를 MAX로 정의함.

 int count =0; //입력받은 회원정보를 나타내는 정수 변수 생성 및 초기화
 int f_count=0; //파일로부터 입력받은 회원정보를 나타내는 정수 변수 생성 및 초기화

 typedef struct list{ //회원 리스트 구조체
   char name[255]; //이름
   int age; //나이
   char email[255]; //이메일
 }list; 
 //파일 오픈 함수
 void file_open(list *p){

   FILE *fp; //파일 포인터 생성
   fp=fopen("main.txt","r"); //main.txt 파일을 읽기 모드로 오픈함수
   if(fp==NULL){ //파일이 열리지 않는 다면
     fprintf(stderr,"파일 main.txt를 열 수 없습니다..\n");
     exit(1); //종료
   }

   while (!feof(fp)){ //파일 끝에 도달할 때까지 계속 반복
     fscanf(fp, " %[^\n]s",p[count].name);
     fscanf(fp, " %d", &p[count].age);
     fscanf(fp, " %s", p[count].email);
     count++; //회원 정보 증가
     f_count++; //파일 회원 정보 증가
   }
   
   fclose(fp); //닫기
 }
 //신규 회원 저장 함수
 void insert(list* p){
   int f=1; 
   char ch; //문자형 ch 변수 생성
   do{
     if(count<MAX){ //회원정보 수가 최대 크기 555보다 작다면

       printf("이름:"); //이름 입출력
       scanf(" %[^\n]s",p[count].name);

       printf("나이:"); //나이 입출력
       scanf(" %d", &p[count].age);

       printf("이메일:"); //이메일 입출력
       scanf(" %s",p[count].email);

       count++; //회원 정보 증가

     }

   printf("계속 입력할까요?(Y/N)") ; //출력
   scanf(" %c",&ch); //Y와 N을 눌렀을 때 입력
   if(ch=='Y'){ //Y라면
     f=1; //1로 반환
     printf("\n");
   }
   else if(ch=='N'){ //N라면 
     f=0; //0으로 반환
     printf("입력이 완료되었습니다.\n\n"); //출력 및 종료
     }
   }while(f); //f로 계속 반복

 }
 //회원 정보 수정
 void recover(list* p){

   char rc_name[255]={0}; //수정할 이름 초기화 및 변수 생성
   printf("수정할 사람 이름을 입력해주세요:"); //수정할 이름 입출력
   scanf(" %[^\n]s",rc_name);

   int i,k=0;
   for(i=0;i<MAX;i++){ //555까지 반복
     if(strcmp(p[i].name,rc_name)==0){ //strcmp 함수를 써서 이름을 수정한다면
         printf("사용자 %s을 수정합니다.\n",rc_name); //출력

         printf("이름:");
         scanf(" %[^\n]s",p[i].name);

         printf("나이:");
         scanf(" %d",&p[i].age);

         printf("이메일:");
         scanf(" %s",p[i].email);

         k=1; //위 과정을 k=1로 설정

         }
       }
       if(k==1){ //k가 1이면
         printf("수정 완료되었습니다.\n"); //수정을 하고 완료 표시 출력
         printf("\n");
       }
       if(k==0){ //k가 0이면
       printf("사용자 %s은 없습니다.\n",rc_name); //수정할 사람 없음 출력
       printf("\n\n");
       }
     }
 void delete(list*p){ //회원 삭제 함수
   char dl_name[255]={0}; //삭제할 이름 생성 및 초기화
   printf("삭제할 사람 이름을 입력해주세요:"); //삭제할 이름 입출력
   scanf(" %[^\n]s",dl_name);

   int i,j,k=0;
   for(i=0;i<MAX;i++){ //555까지 반복
    if(strcmp(p[i].name,dl_name)==0){ //strcmp 함수를 써서 이름을 삭제한다면
       printf("사용자 %s을 삭제합니다.\n",dl_name); //출력

       for(j=i;j<count;j++){ //회원정보 반복
         strcpy(p[j].name,p[j+1].name); //문자형 함수로 사용해서 회원 이름 정보
         p[j].age=p[j+1].age; //회원 나이 정보
         strcpy(p[j].email,p[j+1].email); //문자형 함수로 사용해서 회원 이메일 정보
       }

       count--; //삭제하므로 회원정보 감소(삭제) 
       k=1; //1로 반환
     }

   }
   if(k==1){ //k가 1이면
     printf("삭제 완료 되었습니다.\n\n"); //위 과정과 출력
  }
   if(k==0){ //k가 0이면 사용자 없음을 출력
     printf("사용자 %s은 없습니다.\n\n",dl_name);
   }
 }
 //모든 회원 리스트 함수
 void print_list(list*p){
   FILE *fp; //파일 포인터 생성
   int i,j;

   fp=fopen("main.txt","a"); //main.txt를 추가모드로 오픈함수
   if(fp==NULL){ //파일이 열리지 않는다면
     fprintf(stderr,"파일 main.txt 열리지 않습니다.\n");
     exit(1); //종료
   }
   for(i=f_count;i<count;i++){ //파일 회원 정보와 회원 정보 불러오기
     fprintf(fp,"%s\n",p[i].name); 
     fprintf(fp," %d\n",p[i].age);
     fprintf(fp," %s\n",p[i].email);
   }
   fclose(fp); //닫기

   list t; //리스트를 t로 표현
   for(i=0;i<count;i++){
     for(j=0;j<i;j++){
       if(p[i].age<p[j].age){ //나이가 적은 순으로 모든 회원 정보 리스트 출력
         t=p[i];
         p[i]=p[j];
         p[j]=t;
       }
     }
   }

   for(i=0;i<count;i++){ 
     printf("%s / %d / %s\n",p[i].name, p[i].age, p[i].email);
   } //‘/’로 회원 리스트 표시

  printf("\n");
 }
 //메뉴얼 함수
 void print_menu(void){
   printf("1. 신규회원 저장\n");
   printf("2. 회원정보 수정\n");
   printf("3. 회원 삭제\n");
   printf("4. 모든 회원 리스트\n");
   printf("5. 종료\n");
 }
 //메뉴얼에 따른 숫자 입력 함수
 void input_number(list *p){
   int num=0;
   printf("입력하세요>");
   scanf("%d",&num);

   switch (num){
     case 1: insert(p);break; //1을 입력 시 신규회원 저장함수로 이동
     case 2: recover(p); break; //2를 입력 시 회원정보 수정함수로 이동
     case 3: delete(p); break; //3을 입력 시 회원 삭제함수로 이동
     case 4: print_list(p);break; //4을 입력 시 모든 회원 리스트함수로 이동
     case 5: printf("\n"); printf("종료합니다\n"); //5를 입력 시 종료출력 
             exit(1); //종료
     default: printf("1~5 사이의 숫자를 입력.");
   }
 }
 //메인 함수
 int main(int argc, char*argv[]){
   list* p =(list*)malloc(sizeof(list)*MAX); //리스트 p를 동적 메모리 할당

   file_open(p); //오픈함수 
   do{
     print_menu(); //메뉴얼
     input_number(p); //숫자 입력 함수 반복
   }while(1);

   return 0; //반환
}                 
