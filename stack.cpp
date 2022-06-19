#include<iostream>
#include<stack>

using namespace std;

int main(int argc, char* argv[]){

	stack<int> s;
	
	for(int i=0;i<10;i++){
		s.push(i);
	}
	while(!s.empty()){
	    cout << s.top()  << " ";
	    s.pop();
	}

	printf("\n");

	return 0;
}
