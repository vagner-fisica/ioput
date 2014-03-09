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
*			source file (ioclass.cpp) existing in the 'source'
*			directory of the IOclass source code, which 
*			can be found at https://github.com/vagner-fisica/ioclass.git
*			Please check README to see more details
*******************************
*/

#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>

#include <string>

#include <stdlib.h>

#define string_s std::stringstream
#define string  std::string
#define ifstream std::ifstream

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
		
//------------------
//Private members:
	private:
		string *cwd_;

//------------------
//Private methods:		
		void mkdir(string s);
};
#endif
