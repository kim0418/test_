#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

int main(void){
	
	int n=0;
	int num=0;
	int max=0;

	char **name=(char**)malloc(30*sizeof(char*));
	char **arr=(char**)malloc(30*sizeof(char*));
	for(int i=0;i<15;i++){
		name[i]=(char*)malloc(50*sizeof(char));
		arr[i]=(char*)malloc(50*sizeof(char));
	
	scanf("%d",&n);
	
	if(n<=100){
		for(int i=0;i<n;i++){
			scanf("%d",&num);
			int cost[num];
			if(num<1 || num>100){
				exit(1);
			}
			for(int j=0;j<num;j++){
				scanf("%d %s",&cost[j],name[j]);
				if(cost[j]>max){
					max=cost[j];
					strcpy(arr[j],name[j]);
				}
			}
			max=0;
		}
		for(int i=0;i<n;i++){
			printf("%s\n",arr[i]);
		}
	}
	
	for(int i=0;i<n;i++){
		free(name[i]);
		free(arr[i]);
	}
	}
	return 0;

}





