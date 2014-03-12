#ifndef IOPUT_H
#define IOPUT_H
/*
***** BEGIN LICENSE BLOCK *****
*	
*	This file (code) is part of OIput(c) software (C++ class).
*
*	The content of this code is released under
*	the (http://goo.gl/zNe9hw) MIT License, and is
*	part of the OIput source code.
*
*	Developer: Vagner Bessa (vagner.fisica@gmail.com)
*	
***** END LICENSE BLOCK *******
*/

/*
*******************************
*	IOput C++ class's
*	- Purpose: handle in/out data files in a very
*			   especific way.
*
*	- Info: This class is guaranteed by the developer to
*			work if, and only if compiled together with
*			source file (ioclass.cpp) existed in the root
*			directory of the IOclass source code, which 
*			can be found at https://github.com/vagner-fisica/ioput.git
*			Please check README to see more details.
*******************************
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <fstream>

#include <string>

#include <stdlib.h>

using std::string;
using std::ifstream;
using std::ofstream;
#define string_s std::stringstream
//#define string  std::string
//#define ifstream std::ifstream

template <class type>
class IOput{

	public:
//------------------
//Public members:

//------------------
//Public methods:
		IOput();
		IOput(const char*);
		IOput(string);
		
		string cwd();
		string full_cwd();
		void change_cwd(string);
		
		void save_x(type,
					string,
					int idx = -1,
					int nzeros = -1,
					bool append = false,
					bool new_sub_folder = false);
					
		void save_x(type *,
					int,
					string,
					string delimiter = "\n",
					int idx = -1,
					int nzeros = -1,
					bool append = false,
					bool new_sub_folder = false);
					
		void save_xy(type, type,
					string,
					string delimiter = "\t",
					int idx = -1,
					int nzeros = -1,
					bool append = false,
					bool new_sub_folder = false);
					
		void save_xy(type *, type *,
					int,
					string,
					string delimiter = "\t",
					int idx = -1,
					int nzeros = -1,
					bool append = false,
					bool new_sub_folder = false);

		void save_xyz(type, type, type,
					string,
					string delimiter = "\t",
					int idx = -1,
					int nzeros = -1,
					bool append = false,
					bool new_sub_folder = false);

		void save_xyz(type *, type *, type*,
					int,
					string,
					string delimiter = "\t",
					int idx = -1,
					int nzeros = -1,
					bool append = false,
					bool new_sub_folder = false);

		void save_matrix(type **,
					int, int,
					string,
					string delimiter = "\t",
					int idx = -1,
					int nzeros = -1,
					bool append = false,
					bool new_sub_folder = false);

		void save_matrix(type **,
					int, int,
					int, int,
					string,
					string delimiter = "\t",
					int idx = -1,
					int nzeros = -1,
					bool append = false,
					bool new_sub_folder = false);

		void save_matrix(type *,
					int, int,
					string,
					string delimiter = "\t",
					int idx = -1,
					int nzeros = -1,
					bool append = false,
					bool new_sub_folder = false);
					
		void save_matrix(type *,
					int, int,
					int, int,
					int,
					string,
					string delimiter = "\t",
					int idx = -1,
					int nzeros = -1,
					bool append = false,
					bool new_sub_folder = false);
								
												
		void format_out_data(string, int);
		
		string lzeros(int, int);
		
	private:	
//------------------
//Private members:
		string *cwd_;
		ofstream outf;
		ifstream inf;
		
		string ext;

//------------------
//Private methods:
		void mkdir(string );
		void mk_subdir(string& );
		void def_par_handler(string&, int, int, bool, bool);
};
#endif
