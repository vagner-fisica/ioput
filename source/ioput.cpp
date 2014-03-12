#include "ioput.h"
/*Default constructor*/
template <class T>
IOput<T>::IOput(){
//Default file extension
ext = ".dat";
}
/*Construtors that create a
/working-directory (cwd_)*/
template <class T>
IOput<T>::IOput(const char* dir_name){
//	Default file extension
	ext = ".dat";
	cwd_ = new string(dir_name);
	mkdir(*cwd_);
}
template <class T>
IOput<T>::IOput(string dir_name){
//	Default file extension
	ext = ".dat";
	cwd_ = new string(dir_name);
	mkdir(*cwd_);
}
/*Return current working directory (cwd_)*/
template <class T>
string IOput<T>::cwd(){
	return *cwd_;
}
/*Return the full path of th
current working directory (cwd_)*/
template <class T>
string IOput<T>::full_cwd(){
	system("echo $PWD > .temp_full_cwd_path");
	inf.open(".temp_full_cwd_path");
	string aux;
	getline(inf,aux);
	aux += string("/") + *cwd_;
	inf.close();
	system("rm .temp_full_cwd_path");
	return aux;
}
/*Create 'new_dir_name' directory
and change the current working directory (cwd_)
to 'new_dir_name'*/
template <class T>
void IOput<T>::change_cwd(string new_dir_name){
	*cwd_ = new_dir_name;
	mkdir(*cwd_);
}

/*Store a simple data*/
template <class T>
void IOput<T>::save_x(T x,
					  string fname,
					  int idx,
					  int nzeros,
					  bool append,
					  bool new_sub_folder){

	def_par_handler(fname,idx,nzeros,append,new_sub_folder);
	
	if (outf.good()) {
		outf << x << std::endl;
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();
}
/*Store a simple array of data, which
has 'xrange' elements*/
template <class T>
void IOput<T>::save_x(T *x,
					  int xrange,
					  string fname,
					  string delimiter,
					  int idx,
					  int nzeros,
					  bool append,
					  bool new_sub_folder){
					  
	def_par_handler(fname,idx,nzeros,append,new_sub_folder);
	
	if (outf.good()) {
		for (unsigned int i = 1; i <= xrange; i++){
			if (i < xrange) {
				outf << *x << delimiter;
			} else {
				outf << *x;
			}
			x++;
		}
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();
}

/*Store a simple data of the type (x,y)*/
template <class T>
void IOput<T>::save_xy(T x, T y,
					  string fname,
					  string delimiter,
					  int idx ,
					  int nzeros,
					  bool append,
					  bool new_sub_folder){

	def_par_handler(fname,idx,nzeros,append,new_sub_folder);

	if (outf.good()) {
		outf << x << delimiter << y << std::endl;
	} else {
		std::cout << "ERROR: could not write into file "\
		 		  << fname << "." << std::endl;
	}
	outf.close();
}
/*Store two simple arrays of data of the
type (x,y). Both arrays has to have the 
same number of elements ('xrange')*/
template <class T>
void IOput<T>::save_xy(T *x, T *y,
					  int xrange,
					  string fname,
					  string delimiter,
					  int idx,
					  int nzeros,
					  bool append,
					  bool new_sub_folder){
					  
	def_par_handler(fname,idx,nzeros,append,new_sub_folder);

	if (outf.good()) {
		for (unsigned int i = 1; i <= xrange; i++){
			outf << *x << delimiter << *y << std::endl;
			x++;
			y++;
		}
		
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();
}
/*Store a simple data of the type (x,y,z)*/
template <class T>
void IOput<T>::save_xyz(T x, T y, T z,
					  string fname,
					  string delimiter,
					  int idx ,
					  int nzeros,
					  bool append,
					  bool new_sub_folder){

	def_par_handler(fname,idx,nzeros,append,new_sub_folder);

	if (outf.good()) {
		outf << x << delimiter << y << delimiter << z << std::endl;
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();
}
/*Store two simple arrays of data of the
type (x,y,z). Both arrays has to have the 
same number of elements ('xrange')*/
template <class T>
void IOput<T>::save_xyz(T *x, T *y, T *z,
					  int xrange,
					  string fname,
					  string delimiter,
					  int idx,
					  int nzeros,
					  bool append,
					  bool new_sub_folder){
					  
	def_par_handler(fname,idx,nzeros,append,new_sub_folder);
	
	if (outf.good()) {
		for (unsigned int i = 1; i <= xrange; i++){
			outf << *x << delimiter << *y << delimiter << *z << std::endl;
			x++;
			y++;
			z++;
		}
		
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();
}

/*Store a matrix of data of the
type Amn, with m = nrow (number of rows)
and n = ncol (number of columns).
A must be a pointer to pointer type, dunamically
allocated*/
template <class T>
void IOput<T>::save_matrix(T **A,
					int nrow,
					int ncol,
					string fname,
					string delimiter,
					int idx,
					int nzeros,
					bool append,
					bool new_sub_folder){
					
	def_par_handler(fname,idx,nzeros,append,new_sub_folder);
						
	if (outf.good()) {
		for (unsigned int i = 0; i < nrow; i++){
			for (unsigned int j = 0; j < ncol; j++){
				if (j < ncol - 1) {
					outf << A[i][j] << delimiter;
				} else {
					outf << A[i][j] << std::endl;
				}

			}
		}
		
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();					
}

/*Store a sub-matrix data from
a matrix of the type Amn, starting
from element (row_ini,col_ini) up to
element (row_fin - 1,col_fin - 1).
A must be a pointer to pointer type, dunamically
allocated.
*/
template <class T>
void IOput<T>::save_matrix(T **A,
					int row_ini,
					int row_fin,
					int col_ini,
					int col_fin,
					string fname,
					string delimiter,
					int idx,
					int nzeros,
					bool append,
					bool new_sub_folder){
					
	def_par_handler(fname,idx,nzeros,append,new_sub_folder);
						
	if (outf.good()) {
		for (unsigned int i = row_ini; i < row_fin; i++){
			for (unsigned int j = col_ini; j < col_fin; j++){
				if (j < col_fin - 1) {
					outf << A[i][j] << delimiter;
				} else {
					outf << A[i][j] << std::endl;
				}

			}
		}
		
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();					
}

/*
Store a matrix of data of the
type Amn, with m = nrow (number of rows)
and n = ncol (number of columns), mapped
into a linear array with nrow*ncol
elements.
*/
template <class T>
void IOput<T>::save_matrix(T *A,
					int nrow,
					int ncol,
					string fname,
					string delimiter,
					int idx,
					int nzeros,
					bool append,
					bool new_sub_folder){
					
	def_par_handler(fname,idx,nzeros,append,new_sub_folder);
						
	if (outf.good()) {
		for (unsigned int i = 0; i < nrow; i++){
			for (unsigned int j = 0; j < ncol; j++){
				if (j < ncol - 1) {
					outf << A[i*ncol + j] << delimiter;
				} else {
					outf << A[i*ncol + j] << std::endl;
				}

			}
		}
		
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();					
}
/*
Store a sub-matrix data from
a matrix of the type Amn, starting
from element (row_ini,col_ini) up to
element (row_fin - 1,col_fin - 1).
Recall that the number of columns (ncol)
must be supplied and Amn is mapped
into a linear array with ncol colummns
*/
template <class T>
void IOput<T>::save_matrix(T *A,
					int row_ini,
					int row_fin,
					int col_ini,
					int col_fin,
					int ncol,
					string fname,
					string delimiter,
					int idx,
					int nzeros,
					bool append,
					bool new_sub_folder){
					
	def_par_handler(fname,idx,nzeros,append,new_sub_folder);
						
	if (outf.good()) {
		for (unsigned int i = row_ini; i < row_fin; i++){
			for (unsigned int j = col_ini; j < col_fin; j++){
				if (j < col_fin - 1) {
					outf << A[i*ncol + j] << delimiter;
				} else {
					outf << A[i*ncol + j] << std::endl;
				}

			}
		}
		
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();					
}

/*
Store a vector data in format:
x1 y1 Vx1 Vy1
x2 y2 Vx2 Vy1
...
Where x is a array containing
the position in x, y directions
with dimension of at least
of max(nrow,ncol)
and Vi is the vetor's component
in that direction.
It will only be stored
vector which magnitude is higer
than maximum maginitude times
lower_bound.
Vx and Vy must be a pointer to
pointer type, dunamically allocated
having nrow rows and ncol colummns.
*/
template <class T>
void IOput<T>::save_vector(T *x,
			T **Vx, T **Vy,
			int nrow, int ncol,
			T lower_bound,
			string fname,
			string delimiter,
			int idx,
			int nzeros,
			bool append,
			bool new_sub_folder){

	def_par_handler(fname,idx,nzeros,append,new_sub_folder);
	
	T cut_off = 0, mag;

	if (outf.good()) {
		for (unsigned int i = 0; i < nrow; i++){
			for (unsigned int j = 0; j < ncol; j++){
				cut_off = max ((double)cut_off,
							   (double)sqrt(Vx[i][j]*Vx[i][j]\
							   	  		  + Vy[i][j]*Vy[i][j]));
			}
		}
		for (unsigned int i = 0; i < nrow; i++){
			for (unsigned int j = 0; j < ncol; j++){
				mag = sqrt(Vx[i][j]*Vx[i][j] + Vy[i][j]*Vy[i][j]);
				if (mag >= cut_off*lower_bound) {
					outf << x[j] << delimiter << x[i] << delimiter\
						 << Vx[i][j] << delimiter << Vy[i][j] << std::endl;
				}
			}
		}
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();				
		
}

/*
Store a vector data in format:
x1 y1 Vx1 Vy1
x2 y2 Vx2 Vy1
...
starting from element
(row_ini,col_ini) up to
element (row_fin - 1,col_fin - 1).
Where x is a array containing
the position in x, y directions
with dimension of at least
of max(row_fin, col_fin)
and Vi is the vetor's component
in that direction.
It will only be stored
vector which magnitude is higer
than maximum maginitude times
lower_bound.
Vx and Vy must be a pointer to
pointer type, dunamically allocated
having nrow rows and ncol colummns.
*/
template <class T>
void IOput<T>::save_vector(T *x,
			T **Vx, T **Vy,
			int row_ini, int row_fin,
			int col_ini, int col_fin,
			T lower_bound,
			string fname,
			string delimiter,
			int idx,
			int nzeros,
			bool append,
			bool new_sub_folder){

	def_par_handler(fname,idx,nzeros,append,new_sub_folder);
	
	T cut_off = 0, mag;

	if (outf.good()) {
		for (unsigned int i = row_ini; i < row_fin; i++){
			for (unsigned int j = col_ini; j < col_fin; j++){
				cut_off = max ((double)cut_off,
							   (double)sqrt(Vx[i][j]*Vx[i][j]\
							   	  		  + Vy[i][j]*Vy[i][j]));
			}
		}
		for (unsigned int i = row_ini; i < row_fin; i++){
			for (unsigned int j = col_ini; j < col_fin; j++){
				mag = sqrt(Vx[i][j]*Vx[i][j] + Vy[i][j]*Vy[i][j]);
				if (mag >= cut_off*lower_bound) {
					outf << x[j] << delimiter << x[i] << delimiter\
						 << Vx[i][j] << delimiter << Vy[i][j] << std::endl;
				}
			}
		}
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();				
		
}

/*
Store a vector data in format:
x1 y1 Vx1 Vy1
x2 y2 Vx2 Vy1
...
starting from element
(row_ini,col_ini) up to
element (row_fin - 1,col_fin - 1).
Where x is a array containing
the position in x, y directions
with dimension of ncol
and Vi is the vetor's component
in that direction.
It will only be stored
vector which magnitude is higer
than maximum maginitude times
lower_bound.
Vx and Vy must be mapped into
linear arrays with ncols.
*/
template <class T>
void IOput<T>::save_vector(T *x,
			T *Vx, T *Vy,
			int nrow, int ncol,
			T lower_bound,
			string fname,
			string delimiter,
			int idx,
			int nzeros,
			bool append,
			bool new_sub_folder){
			
	def_par_handler(fname,idx,nzeros,append,new_sub_folder);

	T cut_off = 0, mag;

	if (outf.good()) {
		for (unsigned int i = 0; i < nrow; i++){
			for (unsigned int j = 0; j < ncol; j++){
				cut_off = max ((double)cut_off,
							   (double)sqrt(Vx[i*ncol + j]*Vx[i*ncol + j]\
							   	 		  + Vy[i*ncol + j]*Vy[i*ncol + j]));
			}
		}
		for (unsigned int i = 0; i < nrow; i++){
			for (unsigned int j = 0; j < ncol; j++){
				mag = sqrt(Vx[i*ncol + j]*Vx[i*ncol + j]\
						 + Vy[i*ncol + j]*Vy[i*ncol + j]);
				if (mag >= cut_off*lower_bound) {
					outf << x[j] << delimiter << x[i] << delimiter\
						 << Vx[i*ncol + j] << delimiter << Vy[i*ncol + j]\
						 << std::endl;
				}
			}
		}
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();
			
}

/*
Store a vector data in format:
x1 y1 Vx1 Vy1
x2 y2 Vx2 Vy1
...
starting from element
(row_ini,col_ini) up to
element (row_fin - 1,col_fin - 1).
Where x is a array containing
the position in x, y directions
with dimension of ncol
and Vi is the vetor's component
in that direction.
It will only be stored
vector which magnitude is higer
than maximum maginitude times
lower_bound.
Vx and Vy must be mapped into
linear arrays with ncols.
*/
template <class T>
void IOput<T>::save_vector(T *x,
			T *Vx, T *Vy,
			int row_ini, int row_fin,
			int col_ini, int col_fin,
			int ncol,
			T lower_bound,
			string fname,
			string delimiter,
			int idx,
			int nzeros,
			bool append,
			bool new_sub_folder){
			
	def_par_handler(fname,idx,nzeros,append,new_sub_folder);

	T cut_off = 0, mag;

	if (outf.good()) {
		for (unsigned int i = row_ini; i < row_fin; i++){
			for (unsigned int j = col_ini; j < col_fin; j++){
				cut_off = max ((double)cut_off,
							   (double)sqrt(Vx[i*ncol + j]*Vx[i*ncol + j]\
							   	 		  + Vy[i*ncol + j]*Vy[i*ncol + j]));
			}
		}
		for (unsigned int i = row_ini; i < row_fin; i++){
			for (unsigned int j = col_ini; j < col_fin; j++){
				mag = sqrt(Vx[i*ncol + j]*Vx[i*ncol + j]\
						 + Vy[i*ncol + j]*Vy[i*ncol + j]);
				if (mag >= cut_off*lower_bound) {
					outf << x[j] << delimiter << x[i] << delimiter\
						 << Vx[i*ncol + j] << delimiter << Vy[i*ncol + j]\
						 << std::endl;
				}
			}
		}
	} else {
		std::cout << "ERROR: could not write into file "\
				  << fname << "." << std::endl;
	}
	outf.close();
			
}
/*
Set the output format to be
either scientific or fixed, and
the precision.
*/
template <class T>
void IOput<T>::format_out_data(string floatfield, int precision = 0){
	if (precision > 0) {
		outf.precision(precision);
	}
	
	if (!floatfield.compare("scientific")) {
		outf << std::scientific;
	} else if (!floatfield.compare("fixed")) {
		outf << std::fixed;
	} else {
		std::cout << "ERROR: Unkown format type. Use either \'scientific\'\
					  or \'fixed\'. using \'default\' instead." << std::endl;
	}
	
}
/*
Return a integer n in string
type with nzeros leading zeros.
*/
template <class T>
string IOput<T>::lzeros(int nzeros, int n){
	string_s aux;
	string str;
	aux << std::setw(nzeros) << std::setfill('0') << n;
	aux >> str;
	return str; 
}

/*
Creates a new folder at the root
directory
*/
template <class T>
void IOput<T>::mkdir(string s){
	string_s aux;
	aux << "mkdir -p " + s + "/";
	system(aux.str().c_str());	
}

/*
Creates a new sub-folder in the
cwd directory
*/
template <class T>
void IOput<T>::mk_subdir(string &fname){
	string new_folder = *cwd_ + "/" + fname + "/";
	mkdir(new_folder);
	fname = new_folder + fname;
}


/*
Handles default parameters of
save_ functions.
*/
template <class T>
void IOput<T>::def_par_handler(string &fname,
							   int idx,
							   int nzeros,
							   bool append,
							   bool new_sub_folder){
//	If data is to be store in a 
//	new folder at the root directory				  
	if (new_sub_folder) {
		mk_subdir(fname);
	}
//	If file has to de indexed with a 
//	ending integer 'idx'
	if (idx >= 0) {
//		If the ending integer should be
//		followed by leading zeros		
		if (nzeros >= 0) {
			fname += "_" + lzeros(nzeros,idx);
		} else {
			fname += "_" + idx;
		}
	}
	fname += ext;
//	If new data should be appended to the file	
	if (append) {
		outf.open(fname.c_str(), std::ios::app);
	} else {
		outf.open(fname.c_str());
	}
}

template class IOput<int>;
template class IOput<float>;
template class IOput<double>;
