#include "ioput.h"
template <class T>
IOput<T>::IOput(){}

template <class T>
IOput<T>::IOput(const char* dir_name){
	cwd_ = new ss(dir_name);
	sst aux;
	aux << "mkdir -p " << *cwd_ << "/";
	system(aux.str().c_str());
}

template <class T>
IOput<T>::IOput(ss dir_name){
	cwd_ = new ss(dir_name);
	mkdir(*cwd_);
}

template <class T>
ss IOput<T>::cwd(){
	return *cwd_;
}
template <class T>
ss IOput<T>::full_cwd(){
	system("echo $PWD > .temp_full_cwd_path");
	ifstream in(".temp_full_cwd_path");
	ss aux;
	getline(in,aux);
	aux += ss("/") + *cwd_;
	in.close();
	system("rm .temp_full_cwd_path");
	return aux;
}

template <class T>
void IOput<T>::change_cwd(ss new_dir_name){
	*cwd_ = new_dir_name;
	mkdir(*cwd_);
}

template <class T>
void IOput<T>::mkdir(ss s){
	sst aux;
	aux << "mkdir -p " + s + "/";
	system(aux.str().c_str());	
}
template class IOput<int>;
template class IOput<float>;
template class IOput<double>;
template class IOput<ss>;
template class IOput<char>;
