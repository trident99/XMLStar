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

#include ".\XMLNode.h"

using namespace XMLStar;

//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
XMLNode::XMLNode(void)
{	
	m_enumValueType = XML_STRING;
	m_ptrParentNode = NULL;
	m_objIndex.Zero();
	return;
};
XMLNode::XMLNode(XMLNode * ptrParentNode)
{
	m_enumValueType = XML_STRING;
	if(ptrParentNode)
	{
		m_ptrParentNode = ptrParentNode;
		Set_intLevel(ptrParentNode->Get_intLevel() + 1);
	}else{
		m_ptrParentNode = NULL;
		m_objIndex.Zero();
	}

	return;
};
XMLNode::XMLNode(XMLNode & rhs)
{
	//self assignment check
	if(this == &rhs)
		return;
	//perform the copy construction
	m_ptrParentNode = rhs.Get_ptrParentNode();
	m_objIndex = rhs.Get_objIndex();
	m_strName = rhs.Get_strName();
	m_strValue = rhs.Get_strValue();
	m_enumValueType = rhs.Get_enumValueType();
	return;
};
XMLNode::~XMLNode(void)
{
	m_ptrParentNode = NULL;
	m_strName.clear();
	m_strValue.clear();
};
//PUBLIC OPERATOR OVERLOADS
XMLNode & XMLNode::operator = (XMLNode & rhs)
{	
	//self assignment check
	if(this == &rhs)
		return *this;
	//do the copy assignment
	m_ptrParentNode = rhs.Get_ptrParentNode();
	m_objIndex = rhs.Get_objIndex();

	m_strName = rhs.Get_strName();
	m_strValue = rhs.Get_strValue();
	m_enumValueType = rhs.Get_enumValueType();
	return *this;
};


//PUBLIC MEMBER FUNCTIONS/////////////////////////////////////
//!Set and Get for Node Type
void XMLNode::Set_enumNodeType(XMLNodeType objNodeType)
{
	m_enumNodeType = objNodeType;
};
XMLNodeType XMLNode::Get_enumNodeType(void) const
{
	return m_enumNodeType;
};

//!Set and Get for Parent Node
void XMLNode::Set_ptrParentNode(XMLNode * ptrParent)
{
	if(ptrParent)
	{
		m_ptrParentNode = ptrParent;
	};
};
XMLNode * XMLNode::Get_ptrParentNode(void) const
{
	if(m_ptrParentNode)
	{
		return m_ptrParentNode;
	}else{
		return NULL;
	};
};

//!Set and Get for Parent Node
void XMLNode::Set_objIndex(XMLNodeIndex objIndex)
{
	m_objIndex = objIndex;
};
void XMLNode::Set_objIndex(int intLevel, int intRow, int intColumn)
{
	m_objIndex.Set(intLevel,intRow,intColumn);
};
XMLNodeIndex XMLNode::Get_objIndex(void) const
{
	return m_objIndex;
};

//!Set and Get for Level
void XMLNode::Set_intLevel(int intLevel)
{
	if(intLevel >= 0)
	{
		//valid index
		m_objIndex.m_intLevel = intLevel;
	}else{
		//set to invalid index
		m_objIndex.m_intLevel = -1;
	}
	return;
};
int XMLNode::Get_intLevel(void) const
{
	return m_objIndex.m_intLevel;
};

//!Set and Get for Row 
void XMLNode::Set_intRow(int intRow)
{
	if(intRow >= 0)
	{
		//valid index
		m_objIndex.m_intRow = intRow;
	}else{
		//set to invalid index
		m_objIndex.m_intRow = -1;
	}
	return;
};
int XMLNode::Get_intRow(void) const
{
	return m_objIndex.m_intRow;
};

//!Set and Get for Column
void XMLNode::Set_intColumn(int intCol)
{
	if(intCol >= 0)
	{
		//valid index
		m_objIndex.m_intColumn = intCol;
	}else{
		//set to invalid index
		m_objIndex.m_intColumn = -1;
	}
	return;
};
int XMLNode::Get_intColumn(void) const
{
	return m_objIndex.m_intColumn;
};

//!Set and Get for Node Name string
void XMLNode::Set_strName(const std::string & strName)
{
	m_strName = strName;
	EncodeSpecialChars(m_strName);
};
void XMLNode::Set_strName(const char * ptrCharString)
{
	m_strName = ptrCharString;
	EncodeSpecialChars(m_strName);
};

std::string XMLNode::Get_strName(void) const
{
	std::string strTemp = m_strName;
	return strTemp;
};
//bool XMLNode::IsNameEqual(const std::string & strNameTest)
//{	size_t i,intLHS,intRHS;
//	intLHS = m_strName.size();
//	intRHS = strNameTest.size();
//	if(intLHS != intRHS){return false;};
//	if(intLHS < intRHS)
//	{
//		for(i = 0; i < intLHS; i++)
//		{
//			if(m_strName[i] != strNameTest[i]){return false;};
//		};
//	}else{
//		for(i = 0; i < intRHS; i++)
//		{
//			if(m_strName[i] != strNameTest[i]){return false;};
//		};
//	};
//	//found a match
//	return true;
//	//return (m_strName == strNameTest);
//};

void XMLNode::Set_enumValueType(XMLValueType enumType)
{
	m_enumValueType = enumType;
};

XMLValueType XMLNode::Get_enumValueType(void) const
{
	return m_enumValueType;
};
//!Set and Get for Node Value
void XMLNode::Set_strValue(const std::string & strValue)
{
	m_strValue = strValue;
	EncodeSpecialChars(m_strValue);
	m_enumValueType = XML_STRING;
};

void XMLNode::Set_strValue(const char * ptrCharString)
{
	m_strValue = ptrCharString;
	EncodeSpecialChars(m_strValue);
	m_enumValueType = XML_STRING;
};

void XMLNode::Set_strValue(bool blnVal)
{
	if(blnVal)
	{
		m_strValue = '1';
	}else{
		m_strValue = '0';
	};
	m_enumValueType = XML_BOOL;
};

void XMLNode::Set_strValue(short shrtVal)
{
	try{
		char chrBuf[256];
		sprintf(chrBuf,"%d",shrtVal);
		m_strValue = chrBuf;
		m_enumValueType = XML_SHORT;
	}catch(...){
		return;
	}
};

void XMLNode::Set_strValue(unsigned short ushrtVal)
{
	try{
		char chrBuf[256];
		sprintf(chrBuf,"%u",ushrtVal);
		m_strValue = chrBuf;
		m_enumValueType = XML_USHORT;
	}catch(...){
		return;
	}
};

void XMLNode::Set_strValue(int intVal)
{
	try{
		char chrBuf[256];
		sprintf(chrBuf,"%d",intVal);
		m_strValue = chrBuf;
		m_enumValueType = XML_INT;
	}catch(...){
		return;
	}
};

void XMLNode::Set_strValue(unsigned int uint)
{
	try{
		char chrBuf[256];
		sprintf(chrBuf,"%u",uint);
		m_strValue = chrBuf;
		m_enumValueType = XML_UINT;
	}catch(...){
		return;
	}
};

void XMLNode::Set_strValue(long lngVal)
{
	try{
		char chrBuf[256];
		sprintf(chrBuf,"%ld",lngVal);
		m_strValue = chrBuf;
		m_enumValueType = XML_LONG;
	}catch(...){
		return;
	}
};

void XMLNode::Set_strValue(unsigned long ulngVal)
{
	try{
		char chrBuf[256];
		sprintf(chrBuf,"%lu",ulngVal);
		m_strValue = chrBuf;
		m_enumValueType = XML_ULONG;
	}catch(...){
		return;
	}
};

void XMLNode::Set_strValue(float sngVal)
{
	try{
		char chrBuf[256];
		sprintf(chrBuf,"%f",sngVal);
		m_strValue = chrBuf;
		m_enumValueType = XML_FLOAT;
	}catch(...){
		return;
	}
};

void XMLNode::Set_strValue(double dblVal)
{
	try{
		char chrBuf[256];
		sprintf(chrBuf,"%lf",dblVal);
		m_strValue = chrBuf;
		m_enumValueType = XML_DOUBLE;
	}catch(...){
		return;
	}
};

void XMLNode::Set_strValue(char chrVal)
{
	try{
		char chrBuf[256];
		sprintf(chrBuf,"%s",chrVal);
		m_strValue = chrBuf;
		EncodeSpecialChars(m_strValue);
		m_enumValueType = XML_CHAR;
	}catch(...){
		return;
	}
};

void XMLNode::Set_strValue(unsigned char uchrVal)
{
	try{
		char chrBuf[256];
		sprintf(chrBuf,"%s",uchrVal);
		m_strValue = chrBuf;
		EncodeSpecialChars(m_strValue);
		m_enumValueType = XML_UCHAR;
	}catch(...){
		return;
	}
};


std::string XMLNode::Get_strValue(void)
{
	return m_strValue;
};

void XMLNode::Get_strValue(bool & blnValReturn)
{
	if((m_enumValueType == XML_BOOL)||(m_enumValueType == XML_STRING))
	{
		if(m_strValue == "1")
		{
			//return true
			blnValReturn = true;
		}else{
			//return false
			blnValReturn = false;
		};
	}else{
		//not a boolean attribute type
		//return default value
		blnValReturn = false;
	};
	return;
};

void XMLNode::Get_strValue(short & shrtValReturn)
{		
	short shrtTemp;
	const char * chrBuffer;
	if((m_enumValueType == XML_SHORT)||(m_enumValueType == XML_STRING))
	{
		chrBuffer = m_strValue.c_str();
		sscanf(m_strValue.c_str(),"%d",&shrtTemp);
		shrtValReturn = shrtTemp;
	}else{
		//not a boolean attribute type
		//return default value
		shrtValReturn = 0;
	};
	return;
};

void XMLNode::Get_strValue(unsigned short & ushrtValReturn)
{		
	unsigned short ushrtTemp;
	const char * chrBuffer;
	if((m_enumValueType == XML_USHORT)||(m_enumValueType == XML_STRING))
	{
		chrBuffer = m_strValue.c_str();
		sscanf(chrBuffer,"%u",&ushrtTemp);
		ushrtValReturn = ushrtTemp;
	}else{
		//not a boolean attribute type
		//return default value
		ushrtValReturn = 0;
	};
	return;
};

void XMLNode::Get_strValue(int & intValReturn)
{		
	int intTemp;
	const char * chrBuffer;
	if((m_enumValueType == XML_INT)||(m_enumValueType == XML_STRING))
	{
		chrBuffer = m_strValue.c_str();
		sscanf(chrBuffer,"%d",&intTemp);
		intValReturn = intTemp;
	}else{
		//not a boolean attribute type
		//return default value
		intValReturn = 0;
	};
	return;
};

void XMLNode::Get_strValue(unsigned int & uintValReturn)
{		
	unsigned int uintTemp;
	const char * chrBuffer;
	if((m_enumValueType == XML_UINT)||(m_enumValueType == XML_STRING))
	{
		chrBuffer = m_strValue.c_str();
		sscanf(chrBuffer,"%u",&uintTemp);
		uintValReturn = uintTemp;
	}else{
		//not a boolean attribute type
		//return default value
		uintValReturn = 0;
	};
	return;
};

void XMLNode::Get_strValue(long & lngValReturn)
{		
	long lngTemp;
	const char * chrBuffer;
	if((m_enumValueType == XML_LONG)||(m_enumValueType == XML_STRING))
	{
		chrBuffer = m_strValue.c_str();
		sscanf(chrBuffer,"%ld",&lngTemp);
		lngValReturn = lngTemp;
	}else{
		//not a boolean attribute type
		//return default value
		lngValReturn = 0;
	};
	return;
};

void XMLNode::Get_strValue(unsigned long & ulngValReturn)
{
	unsigned long ulngTemp;
	const char * chrBuffer;
	if((m_enumValueType == XML_ULONG)||(m_enumValueType == XML_STRING))
	{
		chrBuffer = m_strValue.c_str();
		sscanf(chrBuffer,"%lu",&ulngTemp);
		ulngValReturn = ulngTemp;
	}else{
		//not a boolean attribute type
		//return default value
		ulngValReturn = 0;
	};
	return;
};

void XMLNode::Get_strValue(float & sngValReturn)
{
	float sngTemp;
	const char * chrBuffer;
	if((m_enumValueType == XML_FLOAT)||(m_enumValueType == XML_STRING))
	{

		chrBuffer = m_strValue.c_str();
		sscanf(chrBuffer,"%f",&sngTemp);
		sngValReturn = sngTemp;
	}else{
		//not a boolean attribute type
		//return default value
		sngValReturn = 0.0f;
	};
	return;
};

void XMLNode::Get_strValue(double & dblValReturn)
{
	double dblTemp;
	const char * chrBuffer;
	if((m_enumValueType == XML_DOUBLE)||(m_enumValueType == XML_STRING))
	{
		chrBuffer = m_strValue.c_str();
		sscanf(chrBuffer,"%lf",&dblTemp);
		dblValReturn = dblTemp;
	}else{
		//not a boolean attribute type
		//return default value
		dblValReturn = 0.0f;
	};
	return;
};

void XMLNode::Get_strValue(char & chrValReturn)
{	
	char chrTemp;
	const char * chrBuffer;
	if((m_enumValueType == XML_CHAR)||(m_enumValueType == XML_STRING))
	{
		std::string strTemp = m_strValue;
		DecodeSpecialChars(strTemp);

		chrBuffer = m_strValue.c_str();
		sscanf(chrBuffer,"%c",&chrTemp);
		chrValReturn = chrTemp;
	}else{
		//not a boolean attribute type
		//return default value
		chrValReturn = NULL;
	};
	return;
};

void XMLNode::Get_strValue(unsigned char & uchrValReturn)
{	
	unsigned char uchrTemp;
	const char * chrBuffer;
	if((m_enumValueType == XML_UCHAR)||(m_enumValueType == XML_STRING))
	{		
		std::string strTemp = m_strValue;
		DecodeSpecialChars(strTemp);

		chrBuffer = m_strValue.c_str();
		sscanf(chrBuffer,"%c",&uchrTemp);
		uchrValReturn = uchrTemp;
	}else{
		//not a boolean attribute type
		//return default value
		uchrValReturn = NULL;
	};
	return;
};

void XMLNode::Get_strValue(std::string & strValReturn)
{	
	strValReturn = m_strValue;
};

void XMLNode::Get_strValueDecode(std::string & strValReturn)
{
	strValReturn = m_strValue;
	DecodeSpecialChars(strValReturn);
};



//!Encoding special characters to XML compatible format
void XMLNode::EncodeSpecialChars(std::string & strToEncode)
{	
	size_t intPos;
	if(strToEncode.size() <= 0)
	{
		return;
	};
	//CHECK FOR '&' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToEncode.size())
	{
		intPos = strToEncode.find('&',intPos);
		if((intPos >= 0) && (intPos < strToEncode.size()) )
		{
			bool blnAlreadyEncoded = false;
			//check to see if already encoded
			if(strToEncode.substr(intPos,5) == "&amp;"){blnAlreadyEncoded = true;};
			if(strToEncode.substr(intPos,4) == "&lt;"){blnAlreadyEncoded = true;};
			if(strToEncode.substr(intPos,4) == "&gt;"){blnAlreadyEncoded = true;};
			if(strToEncode.substr(intPos,6) == "&quot;"){blnAlreadyEncoded = true;};
			if(strToEncode.substr(intPos,6) == "&apos;"){blnAlreadyEncoded = true;};
			if(strToEncode.substr(intPos,4) == "&eq;"){blnAlreadyEncoded = true;};

			if(!blnAlreadyEncoded)
			{
				//then match found, AND NOT ENCODED make the substitution
				strToEncode.replace(intPos,1,"&amp;");
			};
			//increment so don't double count
			++intPos;

		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToEncode.size() + 1;
		};
	};

	//CHECK FOR '<' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToEncode.size())
	{
		intPos = strToEncode.find('<');
		if((intPos >= 0) && (intPos < strToEncode.size()) )
		{
			//then match found, make the substitution
			strToEncode.replace(intPos,1,"&lt;");
			//increment so don't double count
			++intPos;
		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToEncode.size() + 1;
		};
	}
	//CHECK FOR '>' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToEncode.size())
	{
		intPos = strToEncode.find('>');
		if((intPos >= 0) && (intPos < strToEncode.size()) )
		{
			//then match found, make the substitution
			strToEncode.replace(intPos,1,"&gt;");
			//increment so don't double count
			++intPos;
		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToEncode.size() + 1;
		};
	};
	//CHECK FOR '"' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToEncode.size())
	{
		intPos = strToEncode.find('\"');
		if((intPos >= 0) && (intPos < strToEncode.size()) )
		{
			//then match found, make the substitution
			strToEncode.replace(intPos,1,"&quot;");
			//increment so don't double count
			++intPos;
		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToEncode.size() + 1;
		};
	};
	//CHECK FOR ''' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToEncode.size())
	{
		intPos = strToEncode.find('\'',intPos);
		if((intPos >= 0) && (intPos < strToEncode.size()) )
		{
			//then match found, make the substitution
			strToEncode.replace(intPos,1,"&apos;");
			//increment so don't double count
			++intPos;
		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToEncode.size() + 1;
		};
	};

	//CHECK FOR '=' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToEncode.size())
	{
		intPos = strToEncode.find('=',intPos);
		if((intPos >= 0) && (intPos < strToEncode.size()) )
		{
			//then match found, make the substitution
			strToEncode.replace(intPos,1,"&eq;");
			//increment so don't double count
			++intPos;
		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToEncode.size() + 1;
		};
	};
	return;
};
//!Decode special characters from XML compatible format;
void XMLNode::DecodeSpecialChars(std::string & strToDecode)
{
	size_t intPos;
	if(strToDecode.size() <= 0)
	{
		return;
	};
	//CHECK FOR '<' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToDecode.size())
	{
		intPos = strToDecode.find("&lt;",intPos);
		if((intPos >= 0) && (intPos < strToDecode.size()) )
		{
			//then match found, make the substitution
			strToDecode.replace(intPos,4,"<");//char(60) is <
		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToDecode.size() + 1;
		};
	}
	//CHECK FOR '>' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToDecode.size())
	{
		intPos = strToDecode.find("&gt;",intPos);
		if((intPos >= 0) && (intPos < strToDecode.size()) )
		{
			//then match found, make the substitution
			strToDecode.replace(intPos,4,">");//char(62) is >
		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToDecode.size() + 1;
		};
	};
	//CHECK FOR '"' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToDecode.size())
	{
		intPos = strToDecode.find("&quot;",intPos);
		if((intPos >= 0) && (intPos < strToDecode.size()) )
		{
			//then match found, make the substitution
			strToDecode.replace(intPos,6,"\"");//char(38) is "
		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToDecode.size() + 1;
		};
	};
	//CHECK FOR ''' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToDecode.size())
	{
		intPos = strToDecode.find("&apos;",intPos);
		if((intPos >= 0) && (intPos < strToDecode.size()) )
		{
			//then match found, make the substitution
			strToDecode.replace(intPos,6,"\'");//char(39) is '
		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToDecode.size() + 1;
		};
	};
	//CHECK FOR '&' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToDecode.size())
	{
		intPos = strToDecode.find("&amp;",intPos);
		if((intPos >= 0) && (intPos < strToDecode.size()) )
		{
			//then match found, make the substitution
			strToDecode.replace(intPos,5,"&");//char(38) is &
		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToDecode.size() + 1;
		};
	};
	//CHECK FOR '=' CHARACTER IN STRING///////////////////////
	intPos = 0;
	while(intPos < strToDecode.size())
	{
		intPos = strToDecode.find("&eq;",intPos);
		if((intPos >= 0) && (intPos < strToDecode.size()) )
		{
			//then match found, make the substitution
			strToDecode.replace(intPos,4,"=");//char(38) is =
		}else{
			//not found set to end of string to kick out of while loop
			intPos = strToDecode.size() + 1;
		};
	};
	return;
};