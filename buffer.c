#include<stdio.h>
#include<stdlib.h>

void write_test(const char* filename){
	int buffer[5]={1,1,1,2,2};
	FILE *fp=fopen(filename,"wb");
	if(fp==NULL){exit(1);}
	int count = sizeof(buffer)/sizeof(buffer[0]);
	int size=sizeof(buffer[0]);
	int written_cnt = fwrite(buffer,size,count,fp);
	fclose(fp);
}
void read_test(const char* filename){
	int buffer[5]={10,20,30,40,50};
	FILE *fp=fopen(filename,"rb");
	if(fp==NULL){exit(1);}
	int count = sizeof(buffer)/sizeof(buffer[0]);
	int size=sizeof(buffer[0]);
	int read_cnt = fread(buffer,size,count,fp);
	for(int i=0;i<count;i++){
		printf("%d ",buffer[i]);
	}
	printf("\n");
	fclose(fp);
}

int main(int argc, char*argv[]){
	write_test("binary.bin");
	read_test("binary.bin");
	return 0;
}
