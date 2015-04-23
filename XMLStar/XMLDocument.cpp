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

#include ".\XMLDocument.h"

using namespace XMLStar;

//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
XMLDocument::XMLDocument(void)
: XMLElement()
,m_blnIncludePrologue(true)
,m_strVersion()
,m_strEncoding()
,m_strStandalone()
,m_blnIncludeDocType()
,m_strDocType()
{
	//XMLNode Initialization/////////////
	Set_enumNodeType(DOCUMENT);
	//XMLElement Initialization//////////
	//NONE
	//XMLDocuement Initialization////////
	//!XML Document Prolog Properties included in output
	m_blnIncludePrologue = true;
	//!XML Prolog string version number for the 
	m_strVersion = "1.0";
	//!XML Prolog string encoding format for the 
	m_strEncoding = "UTF-8";
	//!XML Prolog standalone mode
	m_strStandalone = "yes";
	//!XML Document Type Format Tag included in output
	m_blnIncludeDocType = true;
	//!XML Document Type Format Tag 
	m_strDocType.clear();

	return;
};
XMLDocument::XMLDocument(XMLNode * ptrParentNode)
: XMLElement(ptrParentNode)
,m_blnIncludePrologue(true)
,m_strVersion()
,m_strEncoding()
,m_strStandalone()
,m_blnIncludeDocType()
,m_strDocType()
{
	//XMLNode Initialization/////////////
	Set_enumNodeType(DOCUMENT);
	//XMLElement Initialization//////////
	//NONE
	//XMLDocuement Initialization////////
	//!XML Document Prolog Properties included in output
	m_blnIncludePrologue = true;
	//!XML Prolog string version number for the 
	m_strVersion = "1.0";
	//!XML Prolog string encoding format for the 
	m_strEncoding = "UTF-8";
	//!XML Prolog standalone mode
	m_strStandalone = "yes";
	//!XML Document Type Format Tag included in output
	m_blnIncludeDocType = true;
	//!XML Document Type Format Tag 
	m_strDocType.clear();
	return;
};
XMLDocument::XMLDocument(XMLDocument & rhs)
: m_blnIncludePrologue(true)
,m_strVersion()
,m_strEncoding()
,m_strStandalone()
,m_blnIncludeDocType()
,m_strDocType()
{
	//self assignment check
	if(this == &rhs)
		return;
	//XMLNode Copy Construction

	//XMLAttribute Copy Construction

	return;
};
XMLDocument::~XMLDocument(void)
{

};
//PUBLIC OPERATOR OVERLOADS
XMLDocument & XMLDocument::operator = (XMLDocument & rhs)
{	
	//self assignment check
	if(this == &rhs)
		return *this;
	//XMLNode Assignment Operation

	//XMLAttribute Assignment Operation


	return *this;
};


//Set and Get for Include Prologue
void XMLDocument::Set_blnIncludePrologue(bool blnIncludePrologue)
{
	m_blnIncludePrologue = blnIncludePrologue;
};

bool XMLDocument::Get_blnIncludePrologue(void) const
{
	return m_blnIncludePrologue;
};

//Set and Get for Document XML Version Number
void XMLDocument::Set_strVersion(std::string strVersion)
{
	m_strVersion = strVersion;
};

std::string XMLDocument::Get_strVersion(void) const
{
	return m_strVersion;
};

//Set and Get for Document Encoding 
void XMLDocument::Set_strEncoding(std::string strEncoding)
{
	m_strEncoding = strEncoding;
};

std::string XMLDocument::Get_strEncoding(void) const
{
	return m_strEncoding;
};

//Set and Get for Include Standalone
void XMLDocument::Set_blnStandalone(bool blnStandalone)
{
	if(blnStandalone)
	{
		m_strStandalone = "yes";
	}else{
		m_strStandalone = "no";
	};
	return;
};

bool XMLDocument::Get_blnStandalone(void) const
{
	if(m_strStandalone == "yes")
	{
		return true;
	}else{
		return false;
	};
};

//Set and Get for Include Document Type Statement
void XMLDocument::Set_blnIncludeDocType(bool m_blnIncludeDocType)
{
	m_blnIncludeDocType = m_blnIncludeDocType;
};

bool XMLDocument::Get_blnIncludeDocType(void) const
{
	return m_blnIncludeDocType;
};

//Set and Get for Document Type Statement 
void XMLDocument::Set_strDocType(std::string strDocType)
{
	m_strDocType = strDocType;
};

std::string XMLDocument::Get_strDocType(void) const
{
	return m_strDocType;
};

//std::string XMLDocument::Get_strValue(bool blnWithFormatting)
//{
//	std::string strOutput;
//	return strOutput;
//};
