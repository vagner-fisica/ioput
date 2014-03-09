#include "ioput.h"

using namespace std;

template <class T> 
void print(T data, bool endline = false){
	if (endline){
		cout << data << endl;
	}
	else{
		cout << data;
	}
}

int main(){

	IOput<int> a("TESTING");
	print("This is my test folder: ");
	print(a.cwd(),true);

	a.change_cwd("TESTING02");
	print("This is my NEW test folder: ");
	print(a.cwd(),true);
	
}
