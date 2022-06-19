#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct friend{
       char a[255];
}friend;

typedef struct list {
       char ID[255];
       int age;
       unsigned short int HP;
       double x, y;
       int a_num;
       struct friend f[255];
    
}list;

 void new_program() {
       FILE * fp;
       struct list p;
       char ch;
       fp = fopen("my.bin", "ab");
       if (fp == NULL) {
             fprintf(stderr, "파일 my.bin 열 수 없습니다.\n");
             exit(1);
        
    }
       printf("ID 를 입력하세요:");
       scanf(" %[^\n]s", p.ID);
       printf("나이를 입력하세요:");
       scanf(" %d", &p.age);
       printf("HP 를 입력하세요:");
       scanf(" %hu", &p.HP);
       printf("X 좌표를 입력하세요:");
       scanf(" %lf", &p.x);
       printf("Y 좌표를 입력하세요:");
       scanf(" %lf", &p.y);
    
           int count = 0;
               do {
               printf("동맹 ID를 입력하세요:");
               scanf(" %s", p.f[count].a);
        
                   printf("동맹을 계속 추가할까요?");
               scanf(" %c", &ch);
               fgetc(stdin);
                   if (ch == 'Y') {
                     count++;
                     p.a_num = count;
            
        }
    } while (ch != 'N');
                   fseek(fp, 0L, SEEK_END);
               fwrite(&p, sizeof(struct list), 1, fp);
                   printf("완료되었습니다.\n");
               printf("\n");
        
                   fclose(fp);
}

 void print_list() {
       struct list p;
       FILE * fp;
           if ((fp = fopen("my.bin", "rb")) == NULL) {
             fprintf(stderr, "my.bin 파일이 열리지 않습니다.\n");
             exit(1);
        
    }
       while (1) {
                 fread(&p, sizeof(p), 1, fp);
             if (feof(fp))
                   break;
        
                 printf("ID: %s / 나이: %d / HP: %hu/ 좌표: %.3lf,%.3lf\n", p.ID, p.age, p.HP, p.x, p.y);
           printf("등록된 동맹 수: %d명\n", p.a_num + 1);
             for (int i = 0; i < p.a_num; i++)
                   printf("%s /", p.f[i].a);
             printf("%s\n", p.f[p.a_num].a);
             printf("\n");
    }
        printf("\n");
        printf("완료되었습니다.\n");
        printf("\n");
        fclose(fp);
    
}

 void print_menu(void) {
       printf("1. 플레이어 정보 기록\n");
       printf("2. 플레이어 정보 확인\n");
       printf("3. 종료\n");
    
}

 void input_num(struct list* p) {
       int n = 0;
       printf("입력하세요>");
       scanf("%d", &n);
    
           switch (n) {
           case 1:new_program(p); break;
           case 2:print_list(p); break;
           case 3:printf("종료되었습니다.\n"); exit(1);
           default: printf("system error\n"); exit(1);
    }
    
}

int main(int argc, char* argv[]) {
    struct list p; 
    
    do {
        print_menu();
        input_num(&p);
        
    } while (1);
        
    return 0;
}
