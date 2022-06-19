#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MEMBERS 100

/*  ========================================================================= USER_STATUS / ITEM 함수 ====================================================================================== */

void del(char* ap_info, char* ap_ch) {                    //
    int len;                                              //길이
    char* p_pos;                                          //포인터 위치
    while (*ap_info) {                                    // ap_info ?
        if (*ap_info++ == *ap_ch) {                       // info = *FR 까지, NAME: 만나면,
            for (len = 1; *(ap_ch + len); len++) {        //찾은 위치의 포인터 값 + 1
                if (*ap_info++ != *(ap_ch + len)) break;  // ap_info 포인터 값 +1 과 ap_ch + len의 값이 같지 않을 경우 break;
            }
            if (*(ap_ch + len) == 0) {  //같을 경우
                ap_info -= len;
                for (p_pos = ap_info; *(p_pos + len); p_pos++) {
                    *p_pos = *(p_pos + len);
                }
                *p_pos = 0;
            }
        }
    }
}

int GetStrLen(const char* ap_info) {
    const char* p_start = ap_info;
    while (*ap_info) {
        ap_info++;
    }
    return ap_info - p_start;
}

int ChangeString(char* ap_info, int a_find_len, char* ap_change_info) {
    char* p_end_pos = ap_info + a_find_len;
    int replace_size = GetStrLen(ap_change_info);
    if (replace_size > a_find_len) {
        char* p_src = ap_info + GetStrLen(ap_info);
        char* p_dest = p_src + replace_size - a_find_len;
        while (p_src != (p_end_pos - 1)) *p_dest-- = *p_src--;
        while (*ap_change_info) *ap_info++ = *ap_change_info++;
    } else

        while (*ap_change_info) *ap_info++ = *ap_change_info++;
    if (a_find_len != replace_size) {
        while (*p_end_pos) *ap_info++ = *p_end_pos++;
        *ap_info = 0;
    }
    return replace_size;
}

void ReplaceString(char* ap_info, char* ap_find_info, char* ap_change_info) {
    int len;

    while (*ap_info) {
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

void STA_ITEM(char* argv_1, char* argv_2) {  // 남규님 User Status, Item
    int cnt = 0;
    char info[30];
    char ch[30];
    char find_info[30];
    char change_info[30];
        FILE* fp1;
        FILE* fp2;
        fp1 = fopen(argv_1, "r");
        fp2 = fopen(argv_2, "ab");
        while (!feof(fp1)) {
            fgets(info, 100, fp1);
            if (strstr(info, "*FR") != NULL) {
                cnt = 1;
                break;
            }
            if (cnt == 0) {
                ReplaceString(info, "*USER STATUS*", "<");
                //del(info, "*USER STATUS*");
                del(info, "NAME: ");  // txt파일에서 name부분을 삭제하고 데이터를 읽어옴
                del(info, "ID: ");
                del(info, "AGE: ");
                del(info, "GENDER: ");
                del(info, "HP: ");
                del(info, "MP: ");
                del(info, "COIN: ");

                // ReplaceString(info, "*USER STATUS*", "<");
                ReplaceString(info, "*ITEMS*", "<");
                ReplaceString(info, "BOMB: ", "#");
                ReplaceString(info, "POTION: ", "&");
                ReplaceString(info, "SHILED: ", "%");
                ReplaceString(info, "CURE: ", "$");
                ReplaceString(info, "CANNON: ", "@");
                ReplaceString(info, "BOOK: ", "!");
                int len = 0;
                int askii = 0;
                for (int i = 0; i < 50; i++) {
                    len++;
                    askii = info[i] - 0;
                    if (askii == 0)
                        break;
                }
                int blank = 0;
                blank = info[0] - 0;
                if (blank != 10)
                    fwrite(info, sizeof(char) * len - 1, 1, fp2);
            }
        }
        fclose(fp1);
        fclose(fp2);
    return;
}

/*  ========================================================================= USER_STATUS / ITEM END ====================================================================================== */

/*  ========================================================================= FRIENDS_LIST ====================================================================================== */

typedef struct LIST {
    char* ID;
    char* NAME;
    char* GENDER;
    char* AGE;
    short count;
    short endpoint;
    struct LIST* link;
} LIST;

typedef struct TEMP {
    char* ID;
    char* NAME;
    char* GENDER;
    char* AGE;
    short count;
} TEMP;

LIST* init_LIST(LIST* T_List) {
    T_List = (LIST*)malloc(sizeof(LIST));
    T_List->ID = (char*)malloc(sizeof(LIST));    // temp 동적 메모리 선언
    T_List->NAME = (char*)malloc(sizeof(LIST));  // temp 동적 메모리 선언
    T_List->GENDER = (char*)malloc(sizeof(LIST));
    T_List->AGE = (char*)malloc(sizeof(LIST));
    T_List->count = 0;
    T_List->endpoint = 0;
    return T_List;
}

LIST* insert_LIST(LIST* head, LIST* T_List) {
    if (T_List->count - 1 == 0) {
        LIST* p = (LIST*)malloc(sizeof(LIST));
        p->ID = T_List->ID;
        p->NAME = T_List->NAME;
        p->GENDER = T_List->GENDER;
        p->AGE = T_List->AGE;
        p->count = T_List->count;
        p->endpoint = 0;
        p->link = head;
        head = p;
        return head;
    } else {
        LIST* p = (LIST*)malloc(sizeof(LIST));
        p = head;
        while (p->link != NULL)
            p = p->link;
        LIST* NewNode = (LIST*)malloc(sizeof(LIST));
        p->link = NewNode;
        NewNode->ID = T_List->ID;
        NewNode->NAME = T_List->NAME;
        NewNode->GENDER = T_List->GENDER;
        NewNode->AGE = T_List->AGE;
        NewNode->count = T_List->count;
        NewNode->endpoint = 0;
        NewNode->link = NULL;
        return head;
    }
}

LIST* save_temp(FILE* pFile_t, TEMP* temp, LIST* T_List) {
    temp = (TEMP*)malloc(sizeof(TEMP));

    int i = 0;
    int len = 0;
    short count = 0;
    char buf[255];
    if (T_List->count == 0) {
        temp->ID = fgets(buf, sizeof(buf), pFile_t);
        while (strcmp(temp->ID, "*FRIENDS LIST*\n"))
            temp->ID = fgets(buf, sizeof(buf), pFile_t);
    } else {
        count = T_List->count;
        T_List = T_List->link;

        if (T_List == NULL) {
            T_List = (LIST*)malloc(sizeof(LIST));
            T_List->ID = (char*)malloc(sizeof(LIST));    // temp 동적 메모리 선언
            T_List->NAME = (char*)malloc(sizeof(LIST));  // temp 동적 메모리 선언
            T_List->GENDER = (char*)malloc(sizeof(LIST));
            T_List->AGE = (char*)malloc(sizeof(LIST));
            T_List->count = count;
            T_List->endpoint = 0;
        }
    }
    temp->ID = fgets(buf, sizeof(buf), pFile_t);
    if (strcmp(temp->ID, "*DESCRIPTION*\n") == 0) {
        T_List->endpoint = 1;
        return T_List;
    }
    while (strcmp(temp->ID, "\n") == 0)
        temp->ID = fgets(buf, sizeof(buf), pFile_t);
    char* ptr_ID = strtok(temp->ID, " ");
    while (strcmp(ptr_ID, "ID:"))
        ptr_ID = strtok(NULL, " ");
    ptr_ID = strtok(NULL, " ");
    temp->ID = ptr_ID;
    len = strlen(temp->ID);
    strncpy(T_List->ID, temp->ID, len);

    temp->NAME = fgets(buf, sizeof(buf), pFile_t);
    char* ptr_NAME = strtok(temp->NAME, " ");
    while (strcmp(ptr_NAME, "NAME:"))
        ptr_NAME = strtok(NULL, " ");
    ptr_NAME = strtok(NULL, "");
    temp->NAME = ptr_NAME;
    len = strlen(temp->NAME);
    strncpy(T_List->NAME, temp->NAME, len);

    temp->GENDER = fgets(buf, sizeof(buf), pFile_t);
    char* ptr_GENDER = strtok(temp->GENDER, " ");
    while (strcmp(ptr_GENDER, "GENDER:"))
        ptr_GENDER = strtok(NULL, " ");
    ptr_GENDER = strtok(NULL, "");
    temp->GENDER = ptr_GENDER;
    len = strlen(temp->GENDER);
    strncpy(T_List->GENDER, temp->GENDER, len);
    if (strcmp(T_List->GENDER, "MALE\n") == 0) {
        strcpy(T_List->GENDER, "M\n");
    } else if (strcmp(T_List->GENDER, "FEMALE\n") == 0) {
        strcpy(T_List->GENDER, "FM\n");
    }
    temp->AGE = fgets(buf, sizeof(buf), pFile_t);
    char* ptr_AGE = strtok(temp->AGE, " ");
    while (strcmp(ptr_AGE, "AGE:"))
        ptr_AGE = strtok(NULL, " ");
    ptr_AGE = strtok(NULL, " ");
    temp->AGE = ptr_AGE;
    len = strlen(temp->AGE);
    strncpy(T_List->AGE, temp->AGE, len);

    temp->count++;
    T_List->count++;
    T_List->link = NULL;
    temp->ID = fgets(buf, sizeof(buf), pFile_t);

    return T_List;
}

void WriteFile(char* argv_2, FILE* pFile_b, LIST* F_List) {
    pFile_b = fopen(argv_2, "ab");
    fprintf(pFile_b, "%s", "<<\n");
    while (F_List != NULL) {
        int len = 0;
        for (int j = 0; j < 30; j++) {
            len++;
            int askii = F_List->ID[j] - 0;
            if (askii == 0) {
                break;
            }
        }
        fwrite(F_List->ID, sizeof(char) * len - 1, 1, pFile_b);

        len = 0;
        for (int j = 0; j < 30; j++) {
            len++;
            int askii = F_List->NAME[j] - 0;
            if (askii == 0) {
                break;
            }
        }
        fwrite(F_List->NAME, sizeof(char) * len - 1, 1, pFile_b);

        len = 0;
        for (int j = 0; j < 30; j++) {
            len++;
            int askii = F_List->GENDER[j] - 0;
            if (askii == 0) {
                break;
            }
        }
        fwrite(F_List->GENDER, sizeof(char) * len - 1, 1, pFile_b);

        len = 0;
        for (int j = 0; j < 30; j++) {
            len++;
            int askii = F_List->AGE[j] - 0;
            if (askii == 0) {
                break;
            }
        }
        fwrite(F_List->AGE, sizeof(char) * len - 1, 1, pFile_b);

        F_List = F_List->link;
    }
    fclose(pFile_b);
    return;
}

void F_List(char* argv_1, char* argv_2) {
    FILE* pFile_t;
    FILE* pFile_b;
    LIST* head = NULL;
    LIST* p = (LIST*)malloc(sizeof(LIST));
    TEMP* temp;

    LIST* F_List = (LIST*)malloc(sizeof(LIST));

    pFile_t = fopen(argv_1, "r");
    p = init_LIST(p);

    if (pFile_t != NULL) {
        do {
            p = save_temp(pFile_t, temp, p);
            if (p->endpoint == 1)
                break;
            head = insert_LIST(head, p);
        } while (feof(pFile_t) == 0 && p != NULL);
        fclose(pFile_t);
        WriteFile(argv_2, pFile_b, head);
    }

    free(F_List);
    free(p);
}

/*  ========================================================================= FRIENDS_LIST END ====================================================================================== */

/*  ========================================================================= DESCRIPTION ====================================================================================== */

void DESCRIPTION(char* argv_1, char* argv_2) {
    int count = 0;
    int idx = 0;

    char* str;
    str = (char*)malloc(sizeof(char));
    FILE* fp7;
    fp7 = fopen(argv_1, "r");
    FILE* fp8;
    fp8 = fopen("temp.txt", "w");
    {
        while (!feof(fp7)) {
            fgets(str, 100, fp7);
            for (int i = 0; i < strlen(str); i++) {
                if (str[i] == '0')
                    fprintf(fp8, "%s", "~");
                else if (str[i] == '1')
                    fprintf(fp8, "%s", "!");
                else if (str[i] == '2')
                    fprintf(fp8, "%s", "@");
                else if (str[i] == '3')
                    fprintf(fp8, "%s", "#");
                else if (str[i] == '4')
                    fprintf(fp8, "%s", "$");
                else if (str[i] == '5')
                    fprintf(fp8, "%s", ")");
                else if (str[i] == '6')
                    fprintf(fp8, "%s", "^");
                else if (str[i] == '7')
                    fprintf(fp8, "%s", "&");
                else if (str[i] == '8')
                    fprintf(fp8, "%s", "-");
                else if (str[i] == '9')
                    fprintf(fp8, "%s", "(");
                else
                    fprintf(fp8, "%c", str[i]);
            }
        }
    }
    fclose(fp7);
    fclose(fp8);

    FILE* fp1;
    fp1 = fopen("temp.txt", "r");
    FILE* fp2;
    fp2 = fopen("temp2.txt", "w");

    while (!feof(fp1)) {
        char str[100] = "";
        char new[100] = "";
        fgets(str, 100, fp1);
        for (int i = 0; i < strlen(str); i++) {
            char temp[50] = "";
            count++;
            if ((str[i] == 'A') && (str[i + 1] == 'A') && (str[i + 2] == 'A') && (str[i + 3] == 'B') && (str[i + 4] == 'B') && (str[i + 5] == 'B') && (str[i + 6] == 'A') && (str[i + 7] == 'A') && (str[i + 8] == 'D') && (str[i + 9] == 'D') && (str[i + 10] == 'E') && (str[i + 11] == 'E') && (str[i + 12] == 'G') && (str[i + 13] == 'A') && (str[i + 14] == 'G') && (str[i + 15] == 'G')) {  // AAA BBB AA DD EE GAGG -> a
                temp[0] = 'a';
                strcat(new, temp);
                i = i + 15;
            } else if ((str[i] == 'A') && (str[i + 1] == 'A') && (str[i + 2] == 'B') && (str[i + 3] == 'B') && (str[i + 4] == 'B') && (str[i + 5] == 'A') && (str[i + 6] == 'A') && (str[i + 7] == 'D') && (str[i + 8] == 'D') && (str[i + 9] == 'E') && (str[i + 10] == 'E') && (str[i + 11] == 'G') && (str[i + 12] == 'A') && (str[i + 13] == 'G') && (str[i + 14] == 'G')) {  // AA BBB AA DD EE GAGG -> b
                temp[0] = 'b';
                strcat(new, temp);
                i = i + 14;
            } else if ((str[i] == 'A') && (str[i + 1] == 'A') && (str[i + 2] == 'A') && (str[i + 3] == 'A') && (str[i + 4] == 'B') && (str[i + 5] == 'B') && (str[i + 6] == 'C') && (str[i + 7] == 'B') && (str[i + 8] == 'B') && (str[i + 9] == 'C') && (str[i + 10] == 'B') && (str[i + 11] == 'B') && (str[i + 12] == 'C')) {  // AAAA BBC BBC BBC -> c
                temp[0] = 'c';
                strcat(new, temp);
                i = i + 12;
            } else if ((str[i] == 'Z') && (str[i + 1] == 'Z') && (str[i + 2] == 'K') && (str[i + 3] == 'K') && (str[i + 4] == 'Z') && (str[i + 5] == 'Z') && (str[i + 6] == 'K') && (str[i + 7] == 'K') && (str[i + 8] == 'K') && (str[i + 9] == 'K') && (str[i + 10] == 'K') && (str[i + 11] == 'K')) {  // ZZKK ZZKK KKKK -> d
                temp[0] = 'd';
                strcat(new, temp);
                i = i + 11;
            } else if ((str[i] == 'H') && (str[i + 1] == 'E') && (str[i + 2] == 'L') && (str[i + 3] == 'L') && (str[i + 4] == 'O')) {  // HELLO -> e
                temp[0] = 'e';
                strcat(new, temp);
                i = i + 4;
            } else if ((str[i] == 'Z') && (str[i + 1] == 'Z') && (str[i + 2] == 'K') && (str[i + 3] == 'K')) {  // ZZKK -> f
                temp[0] = 'f';
                strcat(new, temp);
                i = i + 3;
            } else if ((str[i] == 'G') && (str[i + 1] == 'A') && (str[i + 2] == 'G') && (str[i + 3] == 'G')) {  // GAGG -> g
                temp[0] = 'g';
                strcat(new, temp);
                i = i + 3;
            } else if ((str[i] == 'B') && (str[i + 1] == 'B') && (str[i + 2] == 'C')) {  // BBC -> h
                temp[0] = 'h';
                strcat(new, temp);
                i = i + 2;
            } else if ((str[i] == str[i + 12]) && (str[i + 1] == str[i + 5]) && (str[i + 2] == str[i + 6]) && (str[i + 3] == str[i + 7]) && (str[i + 8] == str[i + 12]) && (str[i + 9] == str[i + 13]) && (str[i + 10] == str[i + 14]) && (str[i + 11] == str[i + 15]) && (str[i + 12] == str[i + 16]) && (str[i + 13] == str[i + 17]) && (str[i + 14] == str[i + 18]) && (str[i + 15] == str[i + 19])) {  // ex)abcd abcd abcd abcd abcd -> 5abcd, 20
                temp[0] = '5';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = str[i + 2];
                temp[4] = str[i + 3];
                temp[5] = ',';
                strcat(new, temp);
                i = i + 19;
            } else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 3]) && (str[i + 4] == str[i + 6]) && (str[i + 5] == str[i + 7]) && (str[i + 6] == str[i + 8]) && (str[i + 7] == str[i + 9]) && (str[i + 9] == str[i + 11]) && (str[i + 10] == str[i + 12]) && (str[i + 11] == str[i + 13]) && (str[i + 12] == str[i + 14]) && (str[i + 13] == str[i + 15]) && (str[i + 14] == str[i + 16]) && (str[i + 15] == str[i + 17])) {  // EX) AB AB AB AB AB AB AB AB -> 9AB, 18
                temp[0] = '9';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = ',';
                strcat(new, temp);
                i = i + 17;
            } else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 3]) && (str[i + 4] == str[i + 6]) && (str[i + 5] == str[i + 7]) && (str[i + 6] == str[i + 8]) && (str[i + 7] == str[i + 9]) && (str[i + 9] == str[i + 11]) && (str[i + 10] == str[i + 12]) && (str[i + 11] == str[i + 13]) && (str[i + 12] == str[i + 14]) && (str[i + 13] == str[i + 15]))

            {  // EX) AB AB AB AB AB AB AB AB -> 8AB, 16
                temp[0] = '8';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = ',';
                strcat(new, temp);
                i = i + 15;
            } else if ((str[i] == str[i + 12]) && (str[i + 1] == str[i + 5]) && (str[i + 2] == str[i + 6]) && (str[i + 3] == str[i + 7]) && (str[i + 8] == str[i + 12]) && (str[i + 9] == str[i + 13]) && (str[i + 10] == str[i + 14]) && (str[i + 11] == str[i + 15])) {  // ex)abcd abcd abcd abcd -> 4abcd, 16
                temp[0] = '4';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = str[i + 2];
                temp[4] = str[i + 3];
                temp[5] = ',';
                strcat(new, temp);
                i = i + 15;
            } else if ((str[i] == str[i + 9]) && (str[i + 1] == str[i + 4]) && (str[i + 2] == str[i + 5]) && (str[i + 6] == str[i + 9]) && (str[i + 7] == str[i + 10]) && (str[i + 8] == str[i + 11]) && (str[i + 9] == str[i + 12]) && (str[i + 10] == str[i + 13]) && (str[i + 11] == str[i + 14])) {  // EX) ABC ABC ABC ABC ABC -> 5ABC, 15
                temp[0] = '5';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = str[i + 2];
                temp[4] = ',';
                strcat(new, temp);
                i = i + 14;
            } else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 3]) && (str[i + 4] == str[i + 6]) && (str[i + 5] == str[i + 7]) && (str[i + 6] == str[i + 8]) && (str[i + 7] == str[i + 9]) && (str[i + 9] == str[i + 11]) && (str[i + 10] == str[i + 12]) && (str[i + 11] == str[i + 13])) {  // EX) AB AB AB AB AB AB AB -> 7AB, 14
                temp[0] = '7';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = ',';
                strcat(new, temp);
                i = i + 13;
            } else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 3]) && (str[i + 4] == str[i + 6]) && (str[i + 5] == str[i + 7]) && (str[i + 6] == str[i + 8]) && (str[i + 7] == str[i + 9]) && (str[i + 9] == str[i + 11])) {  // EX) AB AB AB AB AB AB -> 6AB, 12
                temp[0] = '6';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = ',';
                strcat(new, temp);
                i = i + 11;
            } else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 5]) && (str[i + 2] == str[i + 6]) && (str[i + 3] == str[i + 7]) && (str[i + 4] == str[i + 8]) && (str[i + 5] == str[i + 9]) && (str[i + 6] == str[i + 10]) && (str[i + 7] == str[i + 11])) {  // ex)abcd abcd abcd -> 3abcd, 12
                temp[0] = '3';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = str[i + 2];
                temp[4] = str[i + 3];
                temp[5] = ',';
                strcat(new, temp);
                i = i + 11;
            }

            else if ((str[i] == str[i + 9]) && (str[i + 1] == str[i + 4]) && (str[i + 2] == str[i + 5]) && (str[i + 6] == str[i + 9]) && (str[i + 7] == str[i + 10]) && (str[i + 8] == str[i + 11])) {  // EX) ABC ABC ABC ABC -> 4ABC, 12
                temp[0] = '4';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = str[i + 2];
                temp[4] = ',';
                strcat(new, temp);
                i = i + 11;
            } else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 3]) && (str[i + 4] == str[i + 6]) && (str[i + 5] == str[i + 7]) && (str[i + 6] == str[i + 8]) && (str[i + 7] == str[i + 9])) {  // EX) AB AB AB AB AB-> 5AB, 10
                temp[0] = '5';

                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = ',';
                strcat(new, temp);
                i = i + 9;
            } else if ((str[i] == str[i + 3]) && (str[i + 1] == str[i + 4]) && (str[i + 2] == str[i + 5]) && (str[i] == str[i + 6]) && (str[i + 1] == str[i + 7]) && (str[i + 2] == str[i + 8])) {  // EX) ABC ABC ABC -> 3ABC, 9
                temp[0] = '3';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = str[i + 2];
                temp[4] = ',';
                strcat(new, temp);
                i = i + 8;
            } else if ((str[i] == str[i + 1]) && (str[i + 1] == str[i + 2]) && (str[i + 2] == str[i + 3]) && (str[i + 3] == str[i + 4]) && (str[i + 4] == str[i + 5]) && (str[i + 5] == str[i + 6]) && (str[i + 6] == str[i + 7])) {  // EX) AAAA AAAA -> 8A, 8

                temp[0] = '8';
                temp[1] = str[i];
                temp[2] = ',';
                strcat(new, temp);
                i = i + 7;
            } else if ((str[i] == str[i + 6]) && (str[i + 1] == str[i + 3]) && (str[i + 4] == str[i + 6]) && (str[i + 5] == str[i + 7])) {  // EX) AB AB AB AB-> 4AB, 8
                temp[0] = '4';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = ',';
                strcat(new, temp);
                i = i + 7;
            }

            else if ((str[i] == str[i + 4]) && (str[i + 1] == str[i + 5]) && (str[i + 2] == str[i + 6]) && (str[i + 3] == str[i + 7])) {  // ex)abcd abcd -> 2abcd, 8
                temp[0] = '2';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = str[i + 2];
                temp[4] = str[i + 3];
                temp[5] = ',';
                strcat(new, temp);
                i = i + 5;
            } else if ((str[i] == str[i + 2]) && (str[i + 1] == str[i + 3]) && (str[i] == str[i + 4]) && (str[i + 1] == str[i + 5])) {  // EX) AB AB AB -> 3AB, 6
                temp[0] = '3';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = ',';
                strcat(new, temp);
                i = i + 5;
            } else if ((str[i] == str[i + 3]) && (str[i + 1] == str[i + 4]) && (str[i + 2] == str[i + 5])) {  // EX) ABC ABC -> 2ABC, 6
                temp[0] = '2';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = str[i + 2];
                temp[4] = ',';
                strcat(new, temp);
                i = i + 5;
            } else if ((str[i] == str[i + 1]) && (str[i + 1] == str[i + 2]) && (str[i + 2] == str[i + 3]) && (str[i + 3] == str[i + 4])) {  // EX) AAAA A -> 5A, 5
                temp[0] = '5';
                temp[1] = str[i];
                temp[2] = ',';
                strcat(new, temp);
                i = i + 4;
            } else if ((str[i] == str[i + 1]) && (str[i + 1] == str[i + 2]) && (str[i + 2] == str[i + 3])) {  // EX) AAAA -> 4A, 4
                temp[0] = '4';
                temp[1] = str[i];
                temp[2] = ',';
                strcat(new, temp);
                i = i + 3;
            } else if ((str[i] == str[i + 2]) && (str[i + 1] == str[i + 3])) {  // EX) AB AB -> 2AB, 4
                temp[0] = '2';
                temp[1] = str[i];
                temp[2] = str[i + 1];
                temp[3] = ',';
                strcat(new, temp);
                i = i + 3;
            } else if ((str[i] == 'B') && (str[i + 1] == 'Y') && (str[i + 2] == 'E')) {  // BYE -> j
                temp[0] = 'j';
                strcat(new, temp);
                i = i + 2;
            } else if ((str[i] == 'A') && (str[i + 1] == 'B') && (str[i + 2] == 'C') && (str[i + 3] == 'D') && (str[i + 4] == 'E')) {  // ABCDE -> n
                temp[0] = 'n';
                strcat(new, temp);
                i = i + 4;
            } else if ((str[i] == 'A') && (str[i + 1] == 'B') && (str[i + 2] == 'C') && (str[i + 3] == 'D')) {  // ABCD -> k
                temp[0] = 'k';
                strcat(new, temp);
                i = i + 3;
            } else if ((str[i] == 'A') && (str[i + 1] == 'B') && (str[i + 2] == 'C')) {  // ABC -> m
                temp[0] = 'm';
                strcat(new, temp);
                i = i + 2;
            } else {
                temp[0] = str[i];
                strcat(new, temp);
            }
        }
        fprintf(fp2, "%s", new);
    }
    fclose(fp1);
    fclose(fp2);

    char arr[20];
    FILE* fp3;
    fp3 = fopen("temp2.txt", "r");
    FILE* fp5;
    fp5 = fopen("final.txt", "w");

    while (!feof(fp3)) {
        fgets(arr, sizeof(arr), fp3);
        if (strstr(arr, "*DES") != NULL && !feof(fp3)) {
            idx = 1;
            fgets(arr, sizeof(arr), fp3);
        }
        int blank = arr[0] - 0;
        if (idx == 1 && blank != 10)
            fprintf(fp5, "%s", arr);
    }

    fclose(fp3);
    fclose(fp5);

    FILE* fp4;
    fp4 = fopen(argv_2, "ab");
    FILE* fp6;
    fp6 = fopen("final.txt", "r");

    fprintf(fp4, "%s", "<<<\n");
    while (!feof(fp6)) {
        char* new_str = malloc(sizeof(char));
        fgets(new_str, 100, fp6);
        int askinum;
        int len = 0;
        for (int i = 0; i < 100; i++) {
            len++;
            askinum = new_str[i] - 0;
            if (askinum == 0)
                break;
        }
        fwrite(new_str, sizeof(char) * len - 1, 1, fp4);
    }

    fclose(fp4);
    fclose(fp6);

    char fname1[9] = "temp.txt";
    char fname2[9] = "temp2.txt";
    char fname3[9] = "final.txt";

    remove(fname1);
    remove(fname2);
    remove(fname3);
}

/*  ========================================================================= DESCRIPTION END ====================================================================================== */
void Store(char* argv_1, char* argv_2) {
    FILE* fp9;
    fp9 = fopen(argv_1, "r");
    char arr[50][50] = {
        0,
    };
    char str[30] = "";
    short wide[50][50] = {
        0,
    };  //가로마다 최대 아스키 값 저장
    short i = 0;
    short askii = 0;
    short askiisum = 0;
    int sumall = 0;
    while (!feof(fp9)) {  // 원본파일 읽어서 arr배열에 싹다 저장
        fgets(arr[i], 100, fp9);
        i++;
    }
    askii = 0;
    short len = i;
    for (i = 0; i < len; i++) {
        askiisum = 0;
        for (short j = 0; j < 50; j++) {
            askii = arr[i][j] - 0;        //각 문자 마다 아스크 값을 구함
            askiisum = askiisum + askii;  // 문자열의 합을 구함
            if (arr[i][j] == 0) {
                wide[i][0] = askiisum;  // 합을 저장
                break;
            }
        }
    }
    for (i = 0; i < len; i++) {
        sumall = sumall + wide[i][0];  //모든 줄의 아스키코드 합의 합을 저장
    }
    fclose(fp9);
    FILE* fp10;
    fp10 = fopen(argv_2, "ab");
    fprintf(fp10, "{\n");  //구분문자
    for (i = 0; i < len; i++) {
        fprintf(fp10, " %d", wide[i][0]);  //각 줄의 합을 저장
    }
    fprintf(fp10, "\n}\n%d", sumall);  //각 줄의 합의 합을 저장
    fclose(fp10);
}
/*  ========================================================================= Call Function ====================================================================================== */

void Call_Function(char* argv_1, char* argv_2) {
    F_List(argv_1, argv_2);
    STA_ITEM(argv_1, argv_2);
    DESCRIPTION(argv_1, argv_2);
    Store(argv_1, argv_2);
}

/*  ========================================================================= Call Function END====================================================================================== */

int main(int argc, char* argv[]) {
    Call_Function(argv[1], argv[2]);
    return 0;
}

