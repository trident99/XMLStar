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

#include ".\XMLProcess.h"

using namespace XMLStar;

//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
XMLProcess::XMLProcess(void)
: XMLNode()
,m_intCurrAttributeIndex(0)
{
		//XMLNode Initialization/////////////
	Set_enumNodeType(PROCESS);
	return;
};

XMLProcess::XMLProcess(XMLNode * ptrParentNode)
: XMLNode(ptrParentNode)
,m_intCurrAttributeIndex(0)
{
		//XMLNode Initialization/////////////
	Set_enumNodeType(PROCESS);
	return;
};

XMLProcess::XMLProcess(XMLProcess & rhs)
: m_intCurrAttributeIndex(0)
{
	//self assignment check
	if(this == &rhs)
		return;
	//XMLNode Copy Construction
	XMLNode::operator = (rhs);
	//XMLProcess Copy Construction
		m_intCurrAttributeIndex = 0;

	return;
};

XMLProcess::~XMLProcess(void)
{
	Clear();
};

//PUBLIC OPERATOR OVERLOADS
XMLProcess & XMLProcess::operator = (XMLProcess & rhs)
{	
	//self assignment check
	if(this == &rhs)
		return *this;
	//XMLNode Assignment Operation
	XMLNode::operator = (rhs);
	//XMLProcess Assignment Operation
	m_intCurrAttributeIndex = 0;
	return *this;
};

//PUBLIC MEMBER FUNCTIONS/////////////////////////////////////
void XMLProcess::Clear(void)
{
	DeleteAllAttributes();
};

//ATTRIBUTE COLLECTION ACCESSOR FUNCTIONS/////////////////////
//!Add an attribute to the element
XMLAttribute * XMLProcess::AddAttribute(void)
{
	return AddNode<XMLAttribute>(m_arrPtrAttributes, this);
};

//!Add an attribute to the element
int XMLProcess::AddAttribute(XMLAttribute * ptrAttrib)
{
	return AddNode<XMLAttribute>(m_arrPtrAttributes, this, ptrAttrib);
};

//!Delete an attribute from the element by its name
int XMLProcess::DeleteAttribute(std::string strName)
{
	return DeleteNode<XMLAttribute>(m_arrPtrAttributes, strName);
};

//!Delete an attribute from the element by its index
int XMLProcess::DeleteAttribute(size_t lngIndex)
{
	return DeleteNode<XMLAttribute>(m_arrPtrAttributes, lngIndex);
};

//!Delete All of the Element's Attributes
int XMLProcess::DeleteAllAttributes(void)
{
	return DeleteAllNodes<XMLAttribute>(m_arrPtrAttributes);
};

//!Sort the collection of Attributes Alphabetically
int XMLProcess::SortAttributes(void)
{
	return SortNodes<XMLAttribute>(m_arrPtrAttributes);
};

//!Size of the Attribute collection
long XMLProcess::CountAttributes(void)
{
	return CountNodes<XMLAttribute>(m_arrPtrAttributes);
};

//!Boolean check to see if attribute collection is empty
bool XMLProcess::HasAttributes(void)
{
	return HasNodes<XMLAttribute>(m_arrPtrAttributes);
};

//!Does Attribute Exist check by it's name
bool XMLProcess::DoesAttributeExist(std::string strName)
{
	return DoesNodeExist<XMLAttribute>(m_arrPtrAttributes, strName);
};

//!Get the pointer to the first Attribute
XMLAttribute * XMLProcess::FirstAttribute(void)
{
	return FirstNode<XMLAttribute>(m_arrPtrAttributes, m_intCurrAttributeIndex);
};

//!Get the pointer to the last Attribute
XMLAttribute * XMLProcess::LastAttribute(void)
{
	return LastNode<XMLAttribute>(m_arrPtrAttributes, m_intCurrAttributeIndex);
};

//!Get the pointer to the next Attribute
XMLAttribute * XMLProcess::NextAttribute(void)
{
	return NextNode<XMLAttribute>(m_arrPtrAttributes, m_intCurrAttributeIndex);
};

//!Get the pointer to the previous Attribute
XMLAttribute * XMLProcess::PreviousAttribute(void)
{
	return PreviousNode<XMLAttribute>(m_arrPtrAttributes, m_intCurrAttributeIndex);
};

//!Get the pointer to the Attribute by it's name
XMLAttribute * XMLProcess::GetAttribute(std::string strName)
{
	return GetNode<XMLAttribute>(m_arrPtrAttributes, strName);
};

//!Get the pointer to the Attribute by it's index
XMLAttribute * XMLProcess::GetAttribute(size_t lngIndex)
{
	return GetNode<XMLAttribute>(m_arrPtrAttributes, lngIndex);
};
