#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

  FILE *fp1;
  FILE *fp2;
  FILE *fp3;
  FILE *fp4;
  fp1 = fopen("result.bin","rb");
  fp2 = fopen("dec.txt","wt");
  fp4 = fopen("recover.txt","wt");
  while(!feof(fp1)){
    char arr0[30] = "";
    fread(arr0,sizeof(arr0),1,fp1);
    fprintf(fp2,"%s",arr0);
  }
  fclose(fp1);
  fclose(fp2);
  fp3 = fopen("dec.txt","rt");
  while(!feof(fp3)){
    char arr[50] = "";
    fgets(arr,sizeof(arr),fp3);
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
fclose(fp4);
  FILE *fp5 = fopen("recover.txt","rt");
  FILE *fp6 = fopen("last.txt","wt");

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
      printf("%s",qwer);
      }
  else
{
  nnew_str[0] = new_str[i];
  strcat(qwer,nnew_str);
}
}
    fprintf(fp6,"%s",qwer);

}

  char fname[10] = "dec.txt";
  remove(fname);

fclose(fp5);
fclose(fp6);

return 0;
}
