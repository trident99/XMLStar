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

#include ".\XMLStructsEnums.h"
using namespace XMLStar;

std::string XMLStar::XMLNodeType_ToString(XMLNodeType objInput)
{
	switch(objInput)
	{
	case NODE:{return "NODE";};
	case DOCUMENT:{return "DOCUMENT";};
	case ELEMENT:{return "ELEMENT";};
	case ATTRIBUTE:{return "ATTRIBUTE";};
	case COMMENT:{return "COMMENT";};
	case PROCESS:{return "PROCESS";};
	default:{return "NODE";};
	};

	//default value
	{return "NODE";};
};

XMLNodeType XMLStar::XMLNodeType_FromString(std::string strInput)
{
	if(strInput == "NODE"){return NODE;}
	else if(strInput == "DOCUMENT"){return DOCUMENT;}
	else if(strInput == "ELEMENT"){return ELEMENT;}
	else if(strInput == "ATTRIBUTE"){return ATTRIBUTE;}
	else if(strInput == "COMMENT"){return COMMENT;}
	else if(strInput == "PROCESS"){return PROCESS;}
	else{
		return NODE;
	};
};

std::string XMLStar::XMLValueType_ToString(XMLValueType objInput)
{
	switch(objInput)
	{
	case XML_UNKNOWN_TYPE:{return "XML_UNKNOWN_TYPE";};
	case XML_NUMERIC:{return "XML_NUMERIC";};
	case XML_ALPHANUMERIC:{return "XML_ALPHANUMERIC";};
	case XML_BOOL:{return "XML_BOOL";};
	case XML_SHORT:{return "XML_SHORT";};
	case XML_USHORT:{return "XML_USHORT";};
	case XML_INT:{return "XML_INT";};
	case XML_UINT:{return "XML_UINT";};
	case XML_LONG:{return "XML_LONG";};
	case XML_ULONG:{return "XML_ULONG";};
	case XML_FLOAT:{return "XML_FLOAT";};
	case XML_DOUBLE:{return "XML_DOUBLE";};
	case XML_CHAR:{return "XML_CHAR";};
	case XML_UCHAR:{return "XML_UCHAR";};
	case XML_STRING:{return "XML_STRING";};
	case XML_GUID:{return "XML_GUID";};
	default:{return "XML_UNKNOWN_TYPE";};
	};

	//default value
	{return "NODE";};
};

XMLValueType XMLStar::XMLValueType_FromString(std::string strInput)
{
	if(strInput == "XML_UNKNOWN_TYPE"){return XML_UNKNOWN_TYPE;}
	else if(strInput == "XML_NUMERIC"){return XML_NUMERIC;}
	else if(strInput == "XML_ALPHANUMERIC"){return XML_ALPHANUMERIC;}
	else if(strInput == "XML_BOOL"){return XML_BOOL;}
	else if(strInput == "XML_SHORT"){return XML_SHORT;}
	else if(strInput == "XML_USHORT"){return XML_USHORT;}
	else if(strInput == "XML_INT"){return XML_INT;}
	else if(strInput == "XML_UINT"){return XML_UINT;}
	else if(strInput == "XML_LONG"){return XML_LONG;}
	else if(strInput == "XML_ULONG"){return XML_ULONG;}
	else if(strInput == "XML_FLOAT"){return XML_FLOAT;}
	else if(strInput == "XML_DOUBLE"){return XML_DOUBLE;}
	else if(strInput == "XML_CHAR"){return XML_CHAR;}
	else if(strInput == "XML_UCHAR"){return XML_UCHAR;}
	else if(strInput == "XML_STRING"){return XML_STRING;}
	else if(strInput == "XML_GUID"){return XML_GUID;}
	else{
		return XML_UNKNOWN_TYPE;
	};
};