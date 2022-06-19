#include<stdio.h>

int g_value=10;

void func1(int value){
    printf("I`m function 1\n");
    
    return 10;
}

double func2(double value){
	int value2=10;
	int*ptr=&value;
	printf("I`m function 2 %f\n",value);
}

double g_dbl_value=20;

void main(int argc, char*argv[]){
	int data1=10;
	int data2=20;
	int data=data1*data2;
	int* p=NULL;
	
	
	double dbl_data=1.1;
	
	
	func1(10);
	func2(1.1);
	
	printf("%d %ls\n",data3,dbl_data);
	
	return 0;
}
