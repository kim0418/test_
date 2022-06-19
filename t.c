 #include <stdio.h>

  2 #include <stdlib.h>

  3 #include <string.h>

  4 #pragma pack(push, 1) //1바이트 크기로 정렬

  5 typedef struct {

  6   char id[255];

  7   int age;

  8   int hp;

  9   double x;

 10   double y;

 11   char friend[255];

 12   int count; //동맹 수를 세는 변수

 13 }list; //플레이어의 정보를 구조체에 저장

 14 #pragma pack(pop) // 정렬 해제

 15 int main(){

 16   char ans[10]; //Yes,No 담음

 17   int num; //실행 할 숫자를 담는 변수

 18   int i = 0;

 19   do //종료할때까지 반복

 20   {

 21   printf("1. 신규  플레이어 정보 기록\n2. 기록된 모든  플레이어 정보 확인\n3. 플레이어 삭제\n4. 종료\n입력하세요 > ");

 22   scanf("%d",&num);

 23   switch (num) { // 숫자에 따라 기능 수행

 24     case 1 :

 25       {

 26         list p;

 27         memset(&p, 0, sizeof(p)); //구조체 변수 내용 0으로 초기화

 28         FILE* fp;

 29         FILE* personal; //개인파일에 저장하기 위함

 30         fp = fopen("ID_List","ab+"); // 쓰고 다시 쓸때 계속하여 저장하기 위해 a+모드 이용

 31         char name[100]; //동맹 이름을 담는 변수

 32         printf("ID 를 입력하세요  : ");

 33         scanf("%s",p.id);

 34         printf("나이 를 입력하세요 : ");

 35         scanf("%d",&p.age);

 36         printf("HP를 입력하세요  : ");

 37         scanf("%d",&p.hp);

 38         printf("X 좌표를 입력하세요 : ");

 39         scanf("%lf",&p.x);

 40         printf("Y 좌표를 입력하세요 : ");

 41         scanf("%lf",&p.y);

 42         p.count = 0; //동맹 수를 0으로 초기화

 43         do

 44         {

 45           printf("동맹 ID를 입력하세요 : ");

 46           scanf(" %s",name);

 47           printf("동맹을 계속 추가할까요?");

 48           scanf("%s",ans);

 49           p.count++; // 반복되는 만큼 동맹 수 증가

 50           strcat(p.friend , name); // 동맹의 이름을 p.friend의 뒤에 붙여넣음

 51           strcat(p.friend , "/"); // 이름을 구분하기 위해 / 추가

 52         }while(*ans == 'Y'); //Y일때까지 반복

 53         fwrite(p.id,sizeof(p.id),1,fp); // 구조체 p 중 ID정보만 fp에 저장

 54         personal = fopen(p.id,"w"); // ID를 파일이름으로 하여 개인별로 데이터 저장

 55         fwrite(&p,sizeof(p),1,personal); // 구조체 p를 fp에 저장

 56         printf("완료되었습니다\n");

 57         fclose(fp);

 58         fclose(personal);

 59         break;

 60         }

 61     case 2 :

 62       {

 63         list p;

 64         memset(&p, 0, sizeof(p)); //구조체 변수 0으로 초기화

 65         int k;

 66         char ID[10];

 67         FILE* fp1; //ID_List 파일을 열어 사람 수를 구함

 68         FILE* fp2; //ID_List 파일을 다시 열어 아이디를 가져옴

 69         FILE* fp3; //위에서 가져온 아이디로 파일을 열어 정보를 가져옴

 70         int player_count = 0; //총 플레이어수 구하는 변수

 71         fp1 = fopen("ID_List","rb"); // 파일을 읽기모드로 염

 72         while (1 == fread(ID,sizeof(p.id),1,fp1)){ //다 가져올때까지 플레이어 수 증가

 73           player_count++;

 74         }

 75         printf("총 %d명의 플레이어가 기록되어 있습니다.\n",player_count);

 76         fclose(fp1);

 77         int player_num = 1; //플레이어 순서 변수

 78         fp2 = fopen("ID_List","rb"); //파일을 읽기모드로 염

 79         fseek(fp2,0L,SEEK_SET); // 파일포인터 위치를 맨 앞으로 변경

 80         while(1 == fread(ID,sizeof(p.id),1,fp2)){ //다 읽을때까지 저장된 ID를 가져옴

 81           fp3 = fopen(ID,"rb"); //가져온 아이디를 통해 개인 파일을 염

 82             while(1 == fread(&p,sizeof(p),1,fp3)){ // 개인 파일을 열어 데이터 출력

 83               printf("[플레이어%d]\nID : %s / 나이 : %d / 좌표 : %.3lf , %.3lf \n등록된 동맹 수: %d 명\n%s \n",player_num,p.id,p.age,p.x,p.y,p.count,p.friend);

 84               player_num++; //플레이어 순서 증가

 85             }

 86         }

 87         printf("완료되었습니다\n");

 88         fclose(fp2);

 89         break;

 90       }

 91     case 3 :

 92       {

 93         list p;

 94         memset(&p, 0, sizeof(p)); //구조체 변수 0으로 초기화

 95         char del_name[20];

 96         char ID[255];

 97         int find = 0;

 98         printf("삭제할 ID를 입력하세요");

 99         scanf("%s",del_name);

100         FILE* fp1;

101         FILE* fp2;

102         FILE* personal;

103         fp1 = fopen("ID_List","rb");

104         fp2 = fopen("temp_List","wb"); //임시 저장 파일

105         while(1 == fread(ID,sizeof(p.id),1,fp1)){

106             if(strcmp(del_name,ID) == 0){ //지울 이름과 id의 정보가 같다면

107               remove(ID); // 개인 저장파일을 지움

108               find++; // 찾았기 때문에 증가

109             }

110             else

111               fwrite(ID,sizeof(p.id),1,fp2); //지울이름과 id가 같지 않다면 저장

112         }

113         if(find != 0) //지울이름을 찾았더라면 find의 값은 0이 아님

114           printf("%s 삭제완료\n",del_name);

115         if(find == 0) //지울이름을 찾지 못했더라면 find 값은 0임

116           printf("해당 데이터는 존재하지 않습니다.\n");

117         fclose(fp1);

118         fclose(fp2);

119         remove("ID_List"); //기존 파일을 지움

120         rename("temp_List","ID_List"); // 임시 저장 파일의 이름을 기존 파일의 이름으로 변경

121         break;

122       }

123     case 4 :

124       {

125         printf("종료합니다\n");

126         exit(0); //종료

127       }

128   }

129   } while(i=1);

130

131 }
