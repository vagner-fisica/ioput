#include "ioput.h"

using namespace std;

template <class T> 
void print(T data, bool endline = true){
	if (endline){
		cout << data << endl;
	}
	else{
		cout << data;
	}
}

int main(){

	IOput<double> a("TESTING");

	double x = 0.03;
	a.save_x(x,"test",-1,-1,false,true);


//	double x[5] = {0.1,0.2,0.3,0.4,0.5};
//	double y[5] = {0.01,0.02,0.03,0.04,0.05};
//	double z[5] = {1.0,2.0,3.0,4.0,5.0};
//	string fname("filexy");
//	a.save_xy(x,y,5,fname);
//	fname = "filexyz";
//	a.format_out_data("fixed",3);
//	a.save_xyz(x,y,z,5,fname);

//	double x[5] = {0.1,0.2,0.3,0.4,0.5};
//	string fname("file");	
//	a.save_x(x,5,fname,"\t",-1,-1,false,false);
	
//	double x = 1.0e-3;
//	string fname("file");
//	a.format_out_data("scientific", 7);
//	a.save_x(x,fname,1,1,true,true);
//	a.format_out_data("fixed", 7);
//	a.save_x(x,fname+"2",1,4,true,true);

//	print("This is my test folder: ");
//	print(a.cwd(),true);

//	a.change_cwd("TESTING02");
//	print("This is my NEW test folder: ",false);
//	print(a.cwd());
	
//	print(a.lzeros(4,1));
	
}
