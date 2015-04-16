/*
**	This file is part of the XMLStar.
**	This software was developed by:
**	
**  Anthony Daniels
**	Ann Arbor, Michigan, USA
**
**  XMLStar is free software: you can redistribute it and/or modify
**  it under the terms of the GNU Lesser General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  The United States of America Department of Defense has unlimited 
**	usage, redistribution, and modification rights to XMLStar.
**
**  XMLStar is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU Lesser General Public License for more details.
**
**  You should have received a copy of the GNU Lesser General Public License
**  along with XMLStar.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#pragma warning (disable: 4251)
#pragma warning (disable: 4005)//macro redefinition warning 

/*
#ifdef _DEBUG
	#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK ,__FILE__,__LINE__)
#else
	#define DEBUG_NEW new
#endif
*/



//Standard Template library includes
#ifndef STD_LIB_INCLUDES
	#define STD_LIB_INCLUDES
	#define _USE_MATH_DEFINES

	#include <cstdlib>
	#include <stdlib.h>
	#include <malloc.h>
	#include <memory.h>
	#include <tchar.h>
	//containers
	#include <string>
	#include <vector>
	#include <list>
	#include <map>
	//algorithms
	#include <algorithm>
	#include <utility>
	#include <numeric>
	#include <time.h>
	#include <math.h>
	#include <cmath>
	//streaming input / output
	#include <conio.h>
	#include <istream>
	#include <ostream>
	#include <iostream>
	#include <sstream>
	#include <fstream>
	#include <stdio.h>
#endif
//custom macros

// MODIFIED 8.7.12 WAL to correct DLL declarations
#ifdef XMLSTAR_DLLEXPORT
#define XMLSTAR_DLLAPI __declspec(dllexport)
#else
#define XMLSTAR_DLLAPI __declspec(dllimport)
#endif

//COMMONLY USED TYPEDEFS
#ifndef XMLSTAR_TYPEDEFS
#define XMLSTAR_TYPEDEFS
typedef unsigned short ushort;
typedef unsigned short UShort;

typedef unsigned int uint;
typedef unsigned int UInt;

typedef unsigned long ulng;
typedef unsigned long ULong;

typedef unsigned char uchr;
typedef unsigned char uchar;
typedef unsigned char UChr;
typedef unsigned char UChar;
#endif

#ifndef XMLStar_STRINGMETHODS
#define XMLStar_STRINGMETHODS
namespace XMLStar
{
	//commonly used string functions
	//Tokenizes or splits a string based on a delimiter 
	XMLSTAR_DLLAPI void StringTokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ");
	//extracts a class name from a typeid().name() string
	XMLSTAR_DLLAPI std::string ExtractTypeName(std::string strTypeIDName);
};//end namespace
#endif//XMLStar_STRINGMETHODS