#include<iostream>
#include<queue>

using namespace std;

int main(int argc, char* argv[]){

    queue<int> s;

    for(int i=0;i<10;i++){
	s.push(i);
    }
    for(int i=0;i<10;i++){
	cout << s.front() << " ";
	s.pop();
    }
    printf("\n");

    return 0;
}
