#include "ioput.h"
template <class T>
IOput<T>::IOput(){}

template <class T>
IOput<T>::IOput(const char* dir_name){
	cwd_ = new string(dir_name);
	string_s aux;
	aux << "mkdir -p " << *cwd_ << "/";
	system(aux.str().c_str());
}

template <class T>
IOput<T>::IOput(string dir_name){
	cwd_ = new string(dir_name);
	mkdir(*cwd_);
}

template <class T>
string IOput<T>::cwd(){
	return *cwd_;
}
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

template <class T>
void IOput<T>::change_cwd(string new_dir_name){
	*cwd_ = new_dir_name;
	mkdir(*cwd_);
}

template <class T>
void IOput<T>::mkdir(string s){
	string_s aux;
	aux << "mkdir -p " + s + "/";
	system(aux.str().c_str());	
}
template class IOput<int>;
template class IOput<float>;
template class IOput<double>;
template class IOput<string>;
template class IOput<char>;
