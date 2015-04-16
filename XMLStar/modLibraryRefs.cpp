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
#pragma warning(push)
#pragma warning (disable : 4005 ) /* macro redefinition */
#define XMLSTAR_DLLEXPORT
#pragma warning(pop)

#include ".\modLibraryRefs.h"
using namespace std;
using namespace XMLStar;

void XMLStar::StringTokenize(const std::string& str,std::vector<std::string>& tokens, const std::string& delimiters)
{
	// Skip delimiters at beginning.
	tokens.clear();

	string::size_type lastPos = str.find_first_not_of(delimiters, 0); 
	// Find first "non-delimiter".
	string::size_type pos     = str.find_first_of(delimiters, lastPos); 
	while (string::npos != pos || string::npos != lastPos) 
	{        
		// Found a token, add it to the vector. 
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of" 
		lastPos = str.find_first_not_of(delimiters, pos); 
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos); 
	};
};

std::string XMLStar::ExtractTypeName(std::string strTypeIDName)
{
	int intNumStrings;
	std::string strTemp, strTrimmed;
	std::vector<string> arrStrNames;
	//ORSDBObject Initialization Section

	//split the typeid name on namespace delimiters first if there are any
	StringTokenize(strTypeIDName,arrStrNames,"::");
	intNumStrings = arrStrNames.size();
	if(intNumStrings < 0)
	{
		//do nothing
		return strTemp;
	}else if(intNumStrings == 1){
		//no name space, redo the split on spaces
		arrStrNames.clear();
		StringTokenize(strTypeIDName,arrStrNames," ");
		return arrStrNames.back();
	}else{
		//delimiters found on name spaces return the last entry,
		//it will be the class name
		return arrStrNames.back();
	};
};