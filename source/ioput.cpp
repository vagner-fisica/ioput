#include "ioput.h"
//Default constructor
template <class T>
IOput<T>::IOput(){
//Default file extension
ext = ".dat";
}
//Construtors that create a
//working-directory (cwd_)
template <class T>
IOput<T>::IOput(const char* dir_name){
//	Default file extension
	ext = ".dat";
	cwd_ = new string(dir_name);
	string_s aux;
	aux << "mkdir -p " << *cwd_ << "/";
	system(aux.str().c_str());
}
template <class T>
IOput<T>::IOput(string dir_name){
//	Default file extension
	ext = ".dat";
	cwd_ = new string(dir_name);
	mkdir(*cwd_);
}
//Return current working directory (cwd_)
template <class T>
string IOput<T>::cwd(){
	return *cwd_;
}
//Return the full path of th
//current working directory (cwd_)
template <class T>
string IOput<T>::full_cwd(){
	system("echo $PWD > .temp_full_cwd_path");
	ifstream in(".temp_full_cwd_path");
	string aux;
	getline(in,aux);
	aux += string("/") + *cwd_;
	in.close();
	system("rm .temp_full_cwd_path");
	return aux;
}
//Create 'new_dir_name' directory
//and change the current working directory (cwd_)
//to 'new_dir_name'
template <class T>
void IOput<T>::change_cwd(string new_dir_name){
	*cwd_ = new_dir_name;
	mkdir(*cwd_);
}
//Creates a new folder at the root
//directory
template <class T>
void IOput<T>::mkdir(string s){
	string_s aux;
	aux << "mkdir -p " + s + "/";
	system(aux.str().c_str());	
}
//Store a simple data
template <class T>
void IOput<T>::save_x(T x,
					  string fname,
					  int idx,
					  int nzeros,
					  bool append,
					  bool new_sub_folder){
//	If data is to be store in a 
//	new folder at the root directory				  
	if(new_sub_folder){
		string new_folder = *cwd_ + "/" + fname + "/";
		mkdir(new_folder);
		fname = new_folder + fname;
	}
//	If file has to de indexed with a 
//	ending integer 'idx'
	if(idx >= 0){
//		If the ending integer should be
//		followed by leading zeros		
		if(nzeros >= 0){
			fname += "_" + lzeros(nzeros,idx);
		}
		else{
			fname += "_" + idx;
		}
	}
	fname += ext;
//	If new data should be appended to the file	
	if(append){
		outf.open(fname.c_str(), std::ios::out | std::ios::app);
	}
	else{
		outf.open(fname.c_str(), std::ios::out);
	}
	if(outf.good()){
//		Data has '\n' at the end
		outf << x << std::endl;
	}
	else{
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();
}
//Store a simple array of data, which
//has 'xrange' elements
template <class T>
void IOput<T>::save_x(T *x,
					  int xrange,
					  string fname,
					  string delimiter,
					  int idx,
					  int nzeros,
					  bool append,
					  bool new_sub_folder){
					  
	if(new_sub_folder){
		string new_folder = *cwd_ + "/" + fname + "/";
		mkdir(new_folder);
		fname = new_folder + fname;
	}
	if(idx >= 0){
		if(nzeros >= 0){
			fname += "_" + lzeros(nzeros,idx);
		}
		else{
			fname += "_" + idx;
		}
	}
	fname += ext;
	if(append){
		outf.open(fname.c_str(), std::ios::out | std::ios::app);
	}
	else{
		outf.open(fname.c_str(), std::ios::out);
	}
	if(outf.good()){
		for (unsigned int i = 1; i <= xrange; i++){
			if(i < xrange)outf << *x << delimiter;
			else outf << *x;
			x++;
		}
		
	}
	else{
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();
}

//Store a simple data of the type (x,y)
template <class T>
void IOput<T>::save_xy(T x, T y,
					  string fname,
					  string delimiter,
					  int idx ,
					  int nzeros,
					  bool append,
					  bool new_sub_folder){
//	If data is to be store in a 
//	new folder at the root directory				  
	if(new_sub_folder){
		string new_folder = *cwd_ + "/" + fname + "/";
		mkdir(new_folder);
		fname = new_folder + fname;
	}
//	If file has to de indexed with a 
//	ending integer 'idx'
	if(idx >= 0){
//		If the ending integer should be
//		followed by leading zeros		
		if(nzeros >= 0){
			fname += "_" + lzeros(nzeros,idx);
		}
		else{
			fname += "_" + idx;
		}
	}
	fname += ext;
//	If new data should be appended to the file	
	if(append){
		outf.open(fname.c_str(), std::ios::out | std::ios::app);
	}
	else{
		outf.open(fname.c_str(), std::ios::out);
	}
	if(outf.good()){
//		Data has '\n' at the end
		outf << x << delimiter << y << std::endl;
	}
	else{
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();
}
//Store two simple arrays of data of the
//type (x,y). Both arrays has to have the 
//same number of elements ('xrange')
template <class T>
void IOput<T>::save_xy(T *x, T *y,
					  int xrange,
					  string fname,
					  string delimiter,
					  int idx,
					  int nzeros,
					  bool append,
					  bool new_sub_folder){
					  
	if(new_sub_folder){
		string new_folder = *cwd_ + "/" + fname + "/";
		mkdir(new_folder);
		fname = new_folder + fname;
	}
	if(idx >= 0){
		if(nzeros >= 0){
			fname += "_" + lzeros(nzeros,idx);
		}
		else{
			fname += "_" + idx;
		}
	}
	fname += ext;
	if(append){
		outf.open(fname.c_str(), std::ios::out | std::ios::app);
	}
	else{
		outf.open(fname.c_str(), std::ios::out);
	}
	if(outf.good()){
		for (unsigned int i = 1; i <= xrange; i++){
			outf << *x << delimiter << *y << std::endl;
			x++;
			y++;
		}
		
	}
	else{
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();
}

template <class T>
void IOput<T>::format_out_data(string floatfield, int precision = 0){
	if(precision > 0){
		outf.precision(precision);
	}
	if(!floatfield.compare("scientific")){
		outf << std::scientific;
	}
	if(!floatfield.compare("fixed")){
		outf << std::fixed;
	}
}

template <class T>
string IOput<T>::lzeros(int nzeros, int n){
	string_s aux;
	string str;
	aux << std::setw(nzeros) << std::setfill('0') << n;
	aux >> str;
	return str; 
}
template class IOput<int>;
template class IOput<float>;
template class IOput<double>;
template class IOput<string>;
template class IOput<char>;
