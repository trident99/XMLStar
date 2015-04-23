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

#ifndef XMLSTRUCTSENUMS_H
#define XMLSTRUCTSENUMS_H

#include ".\modLibraryRefs.h"


namespace XMLStar{

	//!Enumerated Node Type Listing
	enum XMLSTAR_DLLAPI XMLNodeType
	{	
		NODE,
		DOCUMENT,
		ELEMENT,
		ATTRIBUTE,
		COMMENT,
		PROCESS
	};

	XMLSTAR_DLLAPI std::string XMLNodeType_ToString(XMLNodeType objInput);
	XMLSTAR_DLLAPI XMLNodeType XMLNodeType_FromString(std::string strInput);

	//!Base Value Type Listing 
	enum XMLSTAR_DLLAPI XMLValueType
	{		
		XML_UNKNOWN_TYPE,
		XML_NUMERIC,
		XML_ALPHANUMERIC,
		XML_BOOL,
		XML_SHORT,
		XML_USHORT,
		XML_INT,
		XML_UINT,
		XML_LONG,
		XML_ULONG,
		XML_FLOAT,
		XML_DOUBLE,
		XML_CHAR,
		XML_UCHAR,
		XML_STRING,
		XML_GUID,
		XML_OBJECT,
		XML_OBJECT_PTR,
		XML_CONTAINER,
		XML_CONTAINER_PTR
	};

	XMLSTAR_DLLAPI std::string XMLValueType_ToString(XMLValueType objInput);
	XMLSTAR_DLLAPI XMLValueType XMLValueType_FromString(std::string strInput);

	//!structured variable for enumerated types
	struct XMLSTAR_DLLAPI XMLNodeIndex
	{
	public:

		XMLNodeIndex()
		: m_intLevel(0)
		,m_intRow(0)
		,m_intColumn(0)
		{
			//initialize the values to an invalid index
			Reset();
		};

		inline bool IsValid(void)
		{
			if((m_intLevel == -1) ||(m_intRow == -1) ||(m_intColumn == -1))
			{//then invalid index
				return false;
			}else{
				return true;
			};	
		};

		inline void Reset(void){
			m_intLevel = -1;
			m_intRow = -1;
			m_intColumn = -1;
		};

		inline void Zero(void){
			m_intLevel = 0;
			m_intRow = 0;
			m_intColumn = 0;
		};

		inline void Set(int intLevel, int intRow,int intCol){
			m_intLevel = intLevel;
			m_intRow = intRow;
			m_intColumn = intCol;
		};
	public:
		int m_intLevel;
		int m_intRow;
		int m_intColumn;
	};

	struct XMLSTAR_DLLAPI XMLElementIndex
	{
	public:

		XMLElementIndex()
		: m_intOpenTagStartPos(0)
		, m_intTagLength(0)
		, m_intOpenTagEndPos(0)
		, m_intSubElementStartPos(0)
		, m_intCloseTagStartPos(0)
		, m_intCloseTagEndPos(0)
		{
			//initialize the values to an invalid index
			Reset();
		};

		inline void Reset(void){
			m_intOpenTagStartPos = 0;
			m_intTagLength = 0;
			m_intOpenTagEndPos = 0;
			m_intSubElementStartPos = 0;
			m_intCloseTagStartPos = 0;
			m_intCloseTagEndPos = 0;
		};

		size_t m_intOpenTagStartPos;
		size_t m_intTagLength;
		size_t m_intOpenTagEndPos;
		size_t m_intSubElementStartPos;
		size_t m_intCloseTagStartPos;
		size_t m_intCloseTagEndPos;
	};

	typedef std::pair<std::string,std::string> XMLNameValuePair;

};

#endif // XMLSTRUCTSENUMS_H
