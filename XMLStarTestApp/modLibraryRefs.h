/*
**	This file is part of the XMLStar.
**	This software was developed by:
**	
**  Anthony Daniels, Mi Yan
**	The University of Michigan
**	Department of Naval Architecture & Marine Engineering
**	Department of Computer Science
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

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifdef _DEBUG
	#include <crtdbg.h>
	#define DEBUG_NEW new(_NORMAL_BLOCK ,__FILE__,__LINE__)
#else
	#define DEBUG_NEW new
#endif
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

//COMMONLY USED TYPEDEFS

typedef unsigned int uint, UINT;
typedef unsigned long ulng, ULNG;
typedef unsigned char uchr,uchar,UCHR,UCHAR;
typedef unsigned short ushort,USHORT;

//XMLStar INCLUDES
#ifndef XMLStar_INCLUDES
#define XMLStar_INCLUDES
#include "modXMLStar.h"

#endif