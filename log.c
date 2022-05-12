#include<stdio.h>


#define DEBUG
<log.h>----------file
#ifndef __log.h
#define __log.h
#ifdef DEBUG
#define LOG(X) printf("Line : %d Func : %s" __ LINE__, __func__); printf(X)
#define LOG2(X1,X2) printf("Line : %d Func : %s" __ LINE__, __func__); printf(X)
#define LOG(...) do{printf("Line : %d Func : %s" __ LINE__, __func__); printf(__VA_ARGS__);}while(0)
#else
#define LOG(X) 
#endif

#endif

#include "log.h"

{
#ifdef DEBUG

#else
}



void func1(){
	log("func\n");
}

void func2(){

}

int main(int argc, char* argv[]){
	func1();
	LOG("func1 called\n");
	func2();
	LOG("func2 called");
}
