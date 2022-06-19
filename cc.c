#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetStrLen(const char *ap_info)

{
    const char *p_start = ap_info;
    while (*ap_info) {
        ap_info++;
    }
    return ap_info - p_start;
}

int ChangeString(char *ap_info, int a_find_len, char *ap_change_info) {
    char *p_end_pos = ap_info + a_find_len;
    int replace_size = GetStrLen(ap_change_info);
    if (replace_size > a_find_len) {
        char *p_src = ap_info + GetStrLen(ap_info);
        char *p_dest = p_src + replace_size - a_find_len;
        while (p_src != (p_end_pos - 1)) *p_dest-- = *p_src--;
        while (*ap_change_info) *ap_info++ = *ap_change_info++;
    } else {
        while (*ap_change_info) *ap_info++ = *ap_change_info++;
        if (a_find_len != replace_size) {
            while (*p_end_pos) *ap_info++ = *p_end_pos++;
            *ap_info = 0;
        }
    }
    return replace_size;
}

void ReplaceString(char *ap_info, char *ap_find_info, char *ap_change_info) {
    int len;
    while (*ap_info)

    {
        if (*ap_info == *ap_find_info) {
            for (len = 1; *(ap_find_info + len); len++) {
                if (*(ap_info + len) != *(ap_find_info + len)) break;
            }
            if (*(ap_find_info + len) == 0) {
                ap_info = ap_info + ChangeString(ap_info, len, ap_change_info);
            } else
                ap_info++;
        } else
            ap_info++;
    }
}

void File_Read(char *argv1, char *argv2) {
    FILE *fp = fopen(argv1, "rb");
    if (fp == NULL) {
        printf("FILE OPEN FAIL...\n");
        exit(0);
    }
    char *info = (char *)malloc(sizeof(char));
    FILE *fp1 = fopen("com.txt", "w");

    while (1) {
        fgets(info, sizeof(info), fp);
        if (feof(fp)) {
            break;
        }
        fprintf(fp1, "%s", info);
    }

    fclose(fp1);
    fclose(fp);
}

void status_read(char *argv1, char *argv2) {
    int count = 0;
    FILE *fp0 = fopen(argv2, "a");
    FILE *fp2 = fopen("com.txt", "r");

    char *info1 = (char *)malloc(sizeof(char));

    while (!feof(fp2)) {
        fgets(info1, 2 * sizeof(info1), fp2);
        char *ptr2 = strstr(info1, "<<");
        char *ptr1 = strstr(info1, "<");
        if (strstr(info1, "<<")) {
            break;
        } else if (strstr(info1, "<")) {
            ReplaceString(info1, "<", "*ITEMS*");
        }

        ReplaceString(info1, "#", "BOMB: ");
        ReplaceString(info1, "&", "POTION: ");
        ReplaceString(info1, "%", "SHIELD: ");
        ReplaceString(info1, "$", "CURE: ");
        ReplaceString(info1, "!", "BOOK: ");
        ReplaceString(info1, "@", "CANNON: ");

        if (count == 0) {
            fputs("*USER STATUS*\n", fp0);
            count++;
        }
        if (count == 1)
            fprintf(fp0, "ID : %s", info1);

        if (count == 2)
            fprintf(fp0, "NAME : %s", info1);

        if (count == 3)
            fprintf(fp0, "GENDER : %s", info1);

        if (count == 4)
            fprintf(fp0, "AGE: %s", info1);

        if (count == 5)
            fprintf(fp0, "HP: %s", info1);

        if (count == 6)
            fprintf(fp0, "MP: %s", info1);

        if (count == 7)
            fprintf(fp0, "Coin: %s\n", info1);

        else if (count < 1 || count > 7)
            fprintf(fp0, "%s", info1);
        count++;
    }
    fprintf(fp0, "%s", "\n");
    fclose(fp0);
    fclose(fp2);
}

void decoding(char *argv1) {
    int count = 0;
    int num = 0;
    char *str = (char *)malloc(sizeof(char));
    char *temp = (char *)malloc(sizeof(char));
    char *ptr = (char *)malloc(sizeof(char));
    FILE *fp3 = fopen("com.txt", "r");
    while (!feof(fp3)) {
        fgets(str, sizeof(str), fp3);
        if (strstr(str, "<<") != NULL) {
            num = 1;
        }
        if (num == 1) {
            while (fgets(str, sizeof(str), fp3) != NULL) {
                if (strstr(str, "<<<")) {
                    break;
                } else {
                    count++;
                }
            }
        }
    }
    count = count / 4;
    fclose(fp3);
    int i = 0;
    int num1 = 0;
    FILE *fp2 = fopen(argv1, "a");
    FILE *fp4 = fopen("com.txt", "r");
    while (1) {
        fgets(temp, count * sizeof(temp), fp4);
        if (strstr(temp, "<<<")) {
            break;
        }
        if (strstr(temp, "<<") != NULL) {
            num1 = 1;
        }
        if (num1 == 2) {
            fprintf(fp2, "FRIEND%d ID: %s", i + 1, temp);
            fgets(temp, count * sizeof(temp), fp4);
            fprintf(fp2, "FRIEND%d NAME: %s", i + 1, temp);
            fgets(temp, count * sizeof(temp), fp4);
            char *p = strstr(temp, "FM");
            char *k = strstr(temp, "M");
            if (k) {
                strcpy(temp, "MALE\n");
            }
            if (p) {
                strcpy(temp, "FEMALE\n");
            }
            fprintf(fp2, "FRIEND%d GENDER: %s", i + 1, temp);
            fgets(temp, count * sizeof(temp), fp4);
            fprintf(fp2, "FRIEND%d AGE: %s\n", i + 1, temp);
            i++;
        }
        if (num1 == 1) {
            fprintf(fp2, "%s\n", "*FRIENDS LIST*");
            fgets(temp, count * sizeof(temp), fp4);
            fprintf(fp2, "FRIEND%d ID: %s", i + 1, temp);
            fgets(temp, count * sizeof(temp), fp4);
            fprintf(fp2, "FRIEND%d NAME: %s", i + 1, temp);
            fgets(temp, count * sizeof(temp), fp4);
            char *p = strstr(temp, "FM");
            char *k = strstr(temp, "M");
            if (k) {
                strcpy(temp, "MALE\n");
            }
            if (p) {
                strcpy(temp, "FEMALE\n");
            }
            fprintf(fp2, "FRIEND%d GENDER: %s", i + 1, temp);
            fgets(temp, count * sizeof(temp), fp4);
            fprintf(fp2, "FRIEND%d AGE: %s\n", i + 1, temp);
            i++;
            num1++;
        }
        if (i == count) {
            break;
        }
    }
    fclose(fp2);
    fclose(fp4);
}

void des(char *argv1, char *argv2) {
    int num = 0;
    FILE *fp6 = fopen(argv2,"a");
    //FILE *fp1 = fopen("2022 Computer Engineering/2-1/컴퓨터공학창의설계/Final_Project/exam/MERGE.bin", "rb");
    //??????FILE*fp2 = fopen("dec.txt","wt");
    FILE* fp4 = fopen("recover.txt", "wt");
    /*while(!feof(fp1)){
      char arr0[30] = "";
      fread(arr0,sizeof(arr0),1,fp1);
      fprintf(fp2,"%s",arr0);
    }*/
//    fclose(fp1);
    // fclose(fp2);
    // FILE* fp3 = fopen("dec.txt","rt");
    FILE *fp3 = fopen("com.txt", "r");
    char *arr = (char *)malloc(sizeof(char));
    while (!feof(fp3)) {
        fgets(arr, sizeof(arr), fp3);
        if (strstr(arr, "<<<") != NULL) {
            fprintf(fp6,"%s\n","*DESCRPTION*");
	  	num=1;
  		fgets(arr,sizeof(arr),fp3);
        } else if (strstr(arr, "{")) {
            break;
        }
        if (num == 1) {
            //fgets(arr, sizeof(arr), fp3);
            char *new_arr = (char *)malloc(sizeof(char));
            for (int i = 0; i < strlen(arr); i++) {
                char re[50] = "";
                char temp[50] = "";
                char one_temp[50] = "";
                if (arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' || arr[i] == '6' || arr[i] == '7' || arr[i] == '8' || arr[i] == '9') {
                    int k = arr[i] - 48;
                    i++;
                    while (arr[i] != ',') {
                        int j = 0;
                        re[j] = arr[i];
                        strcat(temp, re);
                        i++;
                    }

                    for (int j = 0; j < k; j++) {
                        strcat(new_arr, temp);
                    }
                } else {
                    one_temp[0] = arr[i];
                    strcat(new_arr, one_temp);
                }
            }

            for (int i = 0; i < strlen(new_arr); i++) {
                if (new_arr[i] == '~')
                    new_arr[i] = '0';
                if (new_arr[i] == '!')
                    new_arr[i] = '1';
                if (new_arr[i] == '@')
                    new_arr[i] = '2';
                if (new_arr[i] == '#')
                    new_arr[i] = '3';
                if (new_arr[i] == '$')
                    new_arr[i] = '4';
                if (new_arr[i] == ')')
                    new_arr[i] = '5';
                if (new_arr[i] == '^')
                    new_arr[i] = '6';
                if (new_arr[i] == '&')
                    new_arr[i] = '7';
                if (new_arr[i] == '-')
                    new_arr[i] = '8';
                if (new_arr[i] == '(')
                    new_arr[i] = '9';
            }

            fputs(new_arr, fp4);
        }
    }
    fclose(fp4);
    fclose(fp3);

    FILE *fp5 = fopen("recover.txt", "rt");
    //FILE *fp6 = fopen(argv2, "a");

    while (!feof(fp5)) {
        char qwer[50] = "";
        char new_str[50] = "";

        fgets(new_str, sizeof(new_str), fp5);
        for (int i = 0; i < strlen(new_str); i++) {
            char nnew_str[50] = "";

            if (new_str[i] == 'a') {
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

                strcat(qwer, nnew_str);
            } else if (new_str[i] == 'b') {
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

                strcat(qwer, nnew_str);
            } else if (new_str[i] == 'c') {
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

                strcat(qwer, nnew_str);
            } else if (new_str[i] == 'd') {
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

                strcat(qwer, nnew_str);
            } else if (new_str[i] == 'e') {
                nnew_str[0] = 'H';
                nnew_str[1] = 'E';
                nnew_str[2] = 'L';
                nnew_str[3] = 'L';
                nnew_str[4] = 'O';

                strcat(qwer, nnew_str);
            } else if (new_str[i] == 'f') {
                nnew_str[0] = 'Z';
                nnew_str[1] = 'Z';
                nnew_str[2] = 'K';
                nnew_str[3] = 'K';

                strcat(qwer, nnew_str);
            } else if (new_str[i] == 'g') {
                nnew_str[0] = 'G';
                nnew_str[1] = 'A';
                nnew_str[2] = 'G';
                nnew_str[3] = 'G';

                strcat(qwer, nnew_str);
            } else if (new_str[i] == 'h') {
                nnew_str[0] = 'B';
                nnew_str[1] = 'B';
                nnew_str[2] = 'C';

                strcat(qwer, nnew_str);
                //printf("%s", qwer);
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
            else {
                nnew_str[0] = new_str[i];
                strcat(qwer, nnew_str);
            }
        }
        fprintf(fp6, "%s", qwer);
    }
    // char fname[10] = "dec.txt";
    // remove(fname);

    fclose(fp5);
    fclose(fp6);
}

void revise(char *argv_1, char *argv_2) {
    FILE *fp1 = fopen(argv_1, "r");        //아스키코드 가로 합
    FILE *fp2 = fopen("a1.txt", "wt");  // 위의 저장파일
    FILE *fp4 = fopen(argv_2, "r");       //텍스트파일 입력받는것
    FILE *fp99 = fopen("a2.txt", "wt");
    int count = 0;
    while (!feof(fp1)) {
        char *str = (char *)malloc(sizeof(char) * 200);
        fread(str, sizeof(char) * 4, 1, fp1);
        if (strstr(str, "{") != NULL) {
            count++;
            fread(str, sizeof(str), 1, fp1);
        }
        if (strstr(str, "}") != NULL) {
            count++;
            fread(str, sizeof(str), 1, fp1);
        }
        if (count == 1) {
            fprintf(fp2, "%s", str);
        }
    }  // 기존 바이너리파일에서(descrption 뒷부분 과 아스키코드 합의 전까지만  텍스트파일에 저장시킴)
    fclose(fp1);
    fclose(fp2);
    FILE *fp55 = fopen(argv_1, "r");        //아스키의 모든합
    FILE *fp56 = fopen("a2.txt", "wt");  //위의 저장파일
    count = 0;
    while (!feof(fp55)) {
        char *str = (char *)malloc(sizeof(char));
        str = (char *)calloc(30, sizeof(char));
        fread(str, sizeof(char), 1, fp55);
        if (strstr(str, "}") != NULL) {
            count++;
            fread(str, sizeof(char), 1, fp55);
            fread(str, sizeof(char), 1, fp55);
        }
        if (count == 1) {
            fprintf(fp56, "%s", str);
        }

    }  // 기존 바이너리파일에서 내가
    fclose(fp55);
    fclose(fp56);
    FILE *fp57 = fopen("a2.txt", "r");  //최대값 꺼내오기
    int binsum[50][50] = {
        0,
    };
    fscanf(fp57, "%d", binsum[0]);      //최댓값꺼냄
    FILE *fp3 = fopen("a1.txt", "rt");  //저장시킨 부분을 바이너리
    int arr[50][50] = {
        0,
    };  // 기존 바이너리 파일에 있는 아스키코드의 합을 배열로 저장
    int i = 0;
    while (!feof(fp3)) {
        fscanf(fp3, "%d", arr[i]);
        i++;
    }  // 저장되어있던 값을 배열에 넣음
    int comfirm[50][50] = {
        0,
    };  //아스키값 가로 합친거 변조있는지 확인
    int len = i;
    for (int i = 0; i < len; i++) {
        comfirm[0][0] = comfirm[0][0] + arr[i][0];  //아스키의 값을 합침
    }
    fclose(fp3);
    int wide[50][50] = {
        0,
    };  //새로 만든 가로 아스키값의 합 배열로 저장
    int askii = 0;
    int askiisum = 0;
    char new_arr[50][50] = {
        0,
    };
    i = 0;
    while (!feof(fp4)) {
        fgets(new_arr[i], 100, fp4);
        i++;
    }  //변조처리된 파일을 저장
    fclose(fp4);
    for (i = 0; i < len; i++) {
        askiisum = 0;
        for (int j = 0; j < 50; j++) {
            askii = new_arr[i][j] - 0;
            askiisum = askiisum + askii;
            if (new_arr[i][j] == 0) {
                wide[i][0] = askiisum;
                break;
            }
        }
    }                     // 변조처리된 값의 아스키코드의 합을 구함
    int error_count = 0;  //에러 개수
    int first = 0;
    int second = 0;
    for (i = 0; i < len; i++) {
        if (arr[i][0] != wide[i][0]) {
            if (error_count == 0) {
                first = i + 1;
                error_count++;
            }
            if (error_count == 1)
                second = i + 1;
        }
    }
    printf("\n");
    FILE *fp88 = fopen(argv_2, "r");
    char findstr[50] = "";
    int loc_item = 0;
    int loc_friend = 0;
    int loc_des = 0;
    int index = 1;
    if (binsum[0][0] != comfirm[0][0])  //아스키값이 변조 되어있는지 확인
        printf("변조를 확인하는 값이 변조되었습니다");
    else if(first != 0 && second != 0){  //변조확인값이 변조되지 않으면 작동
        while (!feof(fp88)) {
            fgets(findstr, sizeof(findstr), fp88);
            if (strstr(findstr, "*ITE") != NULL) {
                loc_item = index;  // 각 아이템의 위치를 알아냄
            }
            if (strstr(findstr, "*FRI") != NULL) {
                loc_friend = index;
            }
            if (strstr(findstr, "*DES") != NULL) {
                loc_des = index;
            }
            index++;
        }
        fclose(fp88);
        if (first != 0) {  //위에서 알아낸 위치로 섹션 구분
            if (first == 1) {
                printf("USER STATUS 오류");
            } else if (first < loc_item) {
                printf("USER STATUS 에서 에러 발생");
            } else if (first == loc_item) {
                printf("ITEMS 오류");
            } else if (first < loc_friend) {
                printf("ITEMS 에서 에러 발생");
            } else if (first == loc_friend) {
                printf("FRIEND LIST 오류");
            } else if (first < loc_des) {
                printf("FRIEND LIST에서 에러 밸생");
            } else if (first == loc_des) {
                printf("DESCRIPTION 오류");
            } else if (first > loc_item) {
                printf("DESCRIPTION 에서 에러 발생");
            }
            FILE *fp77 = fopen(argv_2, "r");
            char find_index[50] = "";
            int find_num = 1;
            char find_section[50] = "";
            while (!feof(fp77)) {  //파일을 열어서 그 위치의 값의 앞부분을 잘라냄
                fgets(find_index, sizeof(find_index), fp77);
                find_num++;
                if (find_num == first + 1) {
                    strcpy(find_section, find_index);
                }
            }
            char *first_index;
            char *second_index;
            first_index = strtok(find_section, " ");  //찾아낸 값을 공백기준으로 자르면 한단어만 나옴
            if (strstr(first_index, "FRIEN")) {       //프렌드 리스트면 한번 더 출력
                second_index = first_index;
                first_index = strtok(NULL, " ");
                printf("%s 필드의 %s에서 에러 발생", second_index, first_index);
            } else {
                printf("%s필드 에서 오류 발생", first_index);
            }

            fclose(fp77);
            printf("\n");
        }
        if (second != 0)  //위와 같은 방식으로 한번더 수행
        {
            if (second == 1) {
                printf("USER STATUS 오류");
            } else if (second < loc_item) {
                printf("USER STATUS 에서 에러 발생");
            } else if (second == loc_item) {
                printf("ITEMS 오류");
            } else if (second < loc_friend) {
                printf("ITEMS 에서 에러 발생");
            } else if (second == loc_friend) {
                printf("FRIEND LIST 오류");
            } else if (second < loc_des) {
                printf("FRIEND LIST에서 에러 밸생");
            } else if (second == loc_des) {
                printf("DESCRIPTION 오류");
            } else if (second > loc_item) {
                printf("DESCRIPTION 에서 에러 발생");
            }
            FILE *fp66 = fopen(argv_2, "r");
            char find_index2[50] = "";
            int find_num2 = 1;
            char find_section2[50] = "";
            while (!feof(fp66)) {
                fgets(find_index2, sizeof(find_index2), fp66);
                find_num2++;
                if (find_num2 == second + 1) {
                    strcpy(find_section2, find_index2);
                }
            }
            char *first_index2;
            char *second_index2;
            first_index2 = strtok(find_section2, " ");
            if (strstr(first_index2, "FRIEN")) {
                second_index2 = first_index2;
                first_index2 = strtok(NULL, " ");
                printf("%s 필드의 %s에서 에러 발생", second_index2, first_index2);
            } else {
                printf("%s필드 에서 오류 발생", first_index2);
            }

            fclose(fp66);
        }
    }
}


int main(int argc, char *argv[]) {
    File_Read(argv[1],argv[2]);
    status_read(argv[1], argv[2]);
    decoding(argv[2]);
    des(argv[1],argv[2]);
    revise(argv[1],argv[2]);
    return 0;
}
