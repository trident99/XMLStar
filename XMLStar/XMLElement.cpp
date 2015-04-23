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

#include ".\XMLElement.h"
#include ".\XMLReader.h"
#include ".\XMLWriter.h"

using namespace XMLStar;

//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
XMLElement::XMLElement(void)
: XMLNode()
,m_arrPtrAttributes()
,m_arrPtrComments()
,m_arrPtrProcesses()
,m_arrPtrSubElements()
,m_blnRootNode(false)
,m_blnNullNode(false)
,m_intCurrAttributeIndex(0)
,m_intCurrCommentIndex(0)
,m_intCurrProcessIndex(0)
,m_intCurrElementIndex(0)
{
	//XMLNode Initialization/////////////
	Set_enumNodeType(ELEMENT);
	//XMLElement Initialization//////////
	return;
};
XMLElement::XMLElement(XMLNode * ptrParentNode)
: XMLNode(ptrParentNode)
,m_arrPtrAttributes()
,m_arrPtrComments()
,m_arrPtrProcesses()
,m_arrPtrSubElements()
,m_blnRootNode(false)
,m_blnNullNode(false)
,m_intCurrAttributeIndex(0)
,m_intCurrCommentIndex(0)
,m_intCurrProcessIndex(0)
,m_intCurrElementIndex(0)
{
	//XMLNode Initialization/////////////
	Set_enumNodeType(ELEMENT);
	//XMLElement Initialization//////////

	return;
};
XMLElement::XMLElement(XMLElement & rhs)
:m_arrPtrAttributes()
,m_arrPtrComments()
,m_arrPtrProcesses()
,m_arrPtrSubElements()
,m_blnRootNode(false)
,m_blnNullNode(false)
,m_intCurrAttributeIndex(0)
,m_intCurrCommentIndex(0)
,m_intCurrProcessIndex(0)
,m_intCurrElementIndex(0)
{
	//self assignment check
	if(this == &rhs)
		return;
	//XMLNode Copy Construction
	XMLNode::operator = (rhs);
	//XMLElement Copy Construction
	m_blnRootNode = rhs.Get_blnRootNode();
	m_blnNullNode = rhs.Get_blnNullNode();
	return;
};
XMLElement::~XMLElement(void)
{
	Clear();
};

//PUBLIC OPERATOR OVERLOADS
XMLElement & XMLElement::operator = (XMLElement & rhs)
{	
	//self assignment check
	if(this == &rhs)
		return *this;
	//XMLNode Assignment Operation
	XMLNode::operator = (rhs);
	//XMLElement Assignment Operation
	m_intCurrAttributeIndex = 0;
	m_intCurrElementIndex = 0;
	m_intCurrCommentIndex = 0;
	m_intCurrProcessIndex = 0;
	m_blnRootNode = rhs.Get_blnRootNode();
	m_blnNullNode = rhs.Get_blnNullNode();
	return *this;
};


//PUBLIC MEMBER FUNCTIONS/////////////////////////////////////
void XMLElement::Clear(void)
{
	DeleteAllAttributes();
	DeleteAllSubElements();
	DeleteAllComments();
	DeleteAllProcesses();
};

//ATTRIBUTE COLLECTION ACCESSOR FUNCTIONS/////////////////////
//!Add an attribute to the element
XMLAttribute * XMLElement::AddAttribute(void)
{
	return AddNode<XMLAttribute>(m_arrPtrAttributes, this);
};

//!Add an attribute to the element
int XMLElement::AddAttribute(XMLAttribute * ptrAttrib)
{
	return AddNode<XMLAttribute>(m_arrPtrAttributes, this, ptrAttrib);
};

//!Delete an attribute from the element by its name
int XMLElement::DeleteAttribute(const std::string & strName)
{
	return DeleteNode<XMLAttribute>(m_arrPtrAttributes, strName);
};

//!Delete an attribute from the element by its index
int XMLElement::DeleteAttribute(size_t lngIndex)
{
	return DeleteNode<XMLAttribute>(m_arrPtrAttributes, lngIndex);
};

//!Delete All of the Element's Attributes
int XMLElement::DeleteAllAttributes(void)
{
	return DeleteAllNodes<XMLAttribute>(m_arrPtrAttributes);
};

//!Sort the collection of Attributes Alphabetically
int XMLElement::SortAttributes(void)
{
	return SortNodes<XMLAttribute>(m_arrPtrAttributes);
};

//!Size of the Attribute collection
long XMLElement::CountAttributes(void)
{
	return CountNodes<XMLAttribute>(m_arrPtrAttributes);
};

//!Boolean check to see if attribute collection is empty
bool XMLElement::HasAttributes(void)
{
	return HasNodes<XMLAttribute>(m_arrPtrAttributes);
};

//!Does Attribute Exist check by it's name
bool XMLElement::DoesAttributeExist(const std::string & strName)
{
	return DoesNodeExist<XMLAttribute>(m_arrPtrAttributes, strName);
};

//!Get the pointer to the first Attribute
XMLAttribute * XMLElement::FirstAttribute(void)
{
	return FirstNode<XMLAttribute>(m_arrPtrAttributes, m_intCurrAttributeIndex);
};

//!Get the pointer to the last Attribute
XMLAttribute * XMLElement::LastAttribute(void)
{
	return LastNode<XMLAttribute>(m_arrPtrAttributes, m_intCurrAttributeIndex);
};

//!Get the pointer to the next Attribute
XMLAttribute * XMLElement::NextAttribute(void)
{
	return NextNode<XMLAttribute>(m_arrPtrAttributes, m_intCurrAttributeIndex);
};

//!Get the pointer to the previous Attribute
XMLAttribute * XMLElement::PreviousAttribute(void)
{
	return PreviousNode<XMLAttribute>(m_arrPtrAttributes, m_intCurrAttributeIndex);
};

//!Get the pointer to the Attribute by it's name
XMLAttribute * XMLElement::GetAttribute(const std::string & strName)
{
	return GetNode<XMLAttribute>(m_arrPtrAttributes, strName);
};

//!Get the pointer to the Attribute by it's index
XMLAttribute * XMLElement::GetAttribute(size_t lngIndex)
{
	return GetNode<XMLAttribute>(m_arrPtrAttributes, lngIndex);
};
			
//!Get the pointer to the Attribute by it's index
XMLAttribute * XMLElement::AtAttribute(size_t lngIndex)
{
	return GetNode<XMLAttribute>(m_arrPtrAttributes, lngIndex);
};

//COMMENT COLLECTION ACCESSOR FUNCTIONS/////////////////////
//!Add an Comment to the element
XMLComment * XMLElement::AddComment(void)
{
	return AddNode<XMLComment>(m_arrPtrComments, this);
};

//!Add an Comment to the element
int XMLElement::AddComment(XMLComment * ptrAttrib)
{
	return AddNode<XMLComment>(m_arrPtrComments, this, ptrAttrib);
};

//!Delete an Comment from the element by its name
int XMLElement::DeleteComment(const std::string & strName)
{
	return DeleteNode<XMLComment>(m_arrPtrComments, strName);
};

//!Delete an Comment from the element by its index
int XMLElement::DeleteComment(size_t lngIndex)
{
	return DeleteNode<XMLComment>(m_arrPtrComments, lngIndex);
};

//!Delete All of the Element's Comments
int XMLElement::DeleteAllComments(void)
{
	return DeleteAllNodes<XMLComment>(m_arrPtrComments);
};

//!Sort the collection of Comments Alphabetically
int XMLElement::SortComments(void)
{
	return SortNodes<XMLComment>(m_arrPtrComments);
};

//!Size of the Comment collection
long XMLElement::CountComments(void)
{
	return CountNodes<XMLComment>(m_arrPtrComments);
};

//!Boolean check to see if Comment collection is empty
bool XMLElement::HasComments(void)
{
	return HasNodes<XMLComment>(m_arrPtrComments);
};

//!Does Comment Exist check by it's name
bool XMLElement::DoesCommentExist(const std::string & strName)
{
	return DoesNodeExist<XMLComment>(m_arrPtrComments, strName);
};

//!Get the pointer to the first Comment
XMLComment * XMLElement::FirstComment(void)
{
	return FirstNode<XMLComment>(m_arrPtrComments, m_intCurrCommentIndex);
};

//!Get the pointer to the last Comment
XMLComment * XMLElement::LastComment(void)
{
	return LastNode<XMLComment>(m_arrPtrComments, m_intCurrCommentIndex);
};

//!Get the pointer to the next Comment
XMLComment * XMLElement::NextComment(void)
{
	return NextNode<XMLComment>(m_arrPtrComments, m_intCurrCommentIndex);
};

//!Get the pointer to the previous Comment
XMLComment * XMLElement::PreviousComment(void)
{
	return PreviousNode<XMLComment>(m_arrPtrComments, m_intCurrCommentIndex);
};

//!Get the pointer to the Comment by it's name
XMLComment * XMLElement::GetComment(const std::string & strName)
{
	return GetNode<XMLComment>(m_arrPtrComments, strName);
};

//!Get the pointer to the Comment by it's index
XMLComment * XMLElement::GetComment(size_t lngIndex)
{
	return GetNode<XMLComment>(m_arrPtrComments, lngIndex);
};

//!Get the pointer to the Comment by it's index
XMLComment * XMLElement::AtComment(size_t lngIndex)
{
	return GetNode<XMLComment>(m_arrPtrComments, lngIndex);
};

//PROCESS COLLECTION ACCESSOR FUNCTIONS/////////////////////
//!Add an Process to the element
XMLProcess * XMLElement::AddProcess(void)
{
	return AddNode<XMLProcess>(m_arrPtrProcesses, this);
};

//!Add an Process to the element
int XMLElement::AddProcess(XMLProcess * ptrAttrib)
{
	return AddNode<XMLProcess>(m_arrPtrProcesses, this, ptrAttrib);
};

//!Delete an Process from the element by its name
int XMLElement::DeleteProcess(const std::string & strName)
{
	return DeleteNode<XMLProcess>(m_arrPtrProcesses, strName);
};

//!Delete an Process from the element by its index
int XMLElement::DeleteProcess(size_t lngIndex)
{
	return DeleteNode<XMLProcess>(m_arrPtrProcesses, lngIndex);
};

//!Delete All of the Element's Processes
int XMLElement::DeleteAllProcesses(void)
{
	return DeleteAllNodes<XMLProcess>(m_arrPtrProcesses);
};

//!Sort the collection of Processes Alphabetically
int XMLElement::SortProcesses(void)
{
	return SortNodes<XMLProcess>(m_arrPtrProcesses);
};

//!Size of the Process collection
long XMLElement::CountProcesses(void)
{
	return CountNodes<XMLProcess>(m_arrPtrProcesses);
};

//!Boolean check to see if Process collection is empty
bool XMLElement::HasProcesses(void)
{
	return HasNodes<XMLProcess>(m_arrPtrProcesses);
};

//!Does Process Exist check by it's name
bool XMLElement::DoesProcessExist(const std::string & strName)
{
	return DoesNodeExist<XMLProcess>(m_arrPtrProcesses, strName);
};

//!Get the pointer to the first Process
XMLProcess * XMLElement::FirstProcess(void)
{
	return FirstNode<XMLProcess>(m_arrPtrProcesses, m_intCurrProcessIndex);
};

//!Get the pointer to the last Process
XMLProcess * XMLElement::LastProcess(void)
{
	return LastNode<XMLProcess>(m_arrPtrProcesses, m_intCurrProcessIndex);
};

//!Get the pointer to the next Process
XMLProcess * XMLElement::NextProcess(void)
{
	return NextNode<XMLProcess>(m_arrPtrProcesses, m_intCurrProcessIndex);
};

//!Get the pointer to the previous Process
XMLProcess * XMLElement::PreviousProcess(void)
{
	return PreviousNode<XMLProcess>(m_arrPtrProcesses, m_intCurrProcessIndex);
};

//!Get the pointer to the Process by it's name
XMLProcess * XMLElement::GetProcess(const std::string & strName)
{
	return GetNode<XMLProcess>(m_arrPtrProcesses, strName);
};

//!Get the pointer to the Process by it's index
XMLProcess * XMLElement::GetProcess(size_t lngIndex)
{
	return GetNode<XMLProcess>(m_arrPtrProcesses, lngIndex);
};

//!Get the pointer to the Process by it's index
XMLProcess * XMLElement::AtProcess(size_t lngIndex)
{
	return GetNode<XMLProcess>(m_arrPtrProcesses, lngIndex);
};

//SUB - ELEMENT COLLECTION ACCESSOR FUNCTIONS//////////////////////
//!Add an attribute to the element
XMLElement * XMLElement::AddSubElement(void)
{
	return AddNode<XMLElement>(m_arrPtrSubElements, this);
};

//!Add an attribute to the element
int XMLElement::AddSubElement(XMLElement * ptrElement)
{
	return AddNode<XMLElement>(m_arrPtrSubElements, this, ptrElement);
};

//!Delete an attribute from the element by its name
int XMLElement::DeleteSubElement(const std::string & strName)
{
	return DeleteNode<XMLElement>(m_arrPtrSubElements, strName);
};

//!Delete an attribute from the element by its index
int XMLElement::DeleteSubElement(size_t lngIndex)
{
	return DeleteNode<XMLElement>(m_arrPtrSubElements, lngIndex);
};

//!Delete All of the Element's sub-Elements
int XMLElement::DeleteAllSubElements(void)
{
	return DeleteAllNodes<XMLElement>(m_arrPtrSubElements);
};

//!Sort the collection of Elements Alphabetically
int XMLElement::SortSubElements(void)
{
	return SortNodes<XMLElement>(m_arrPtrSubElements);
};

//!Size of the Element collection
long XMLElement::CountSubElements(void)
{
	return CountNodes<XMLElement>(m_arrPtrSubElements);
};

//!Boolean check to see if attribute collection is empty
bool XMLElement::HasSubElements(void)
{
	return HasNodes<XMLElement>(m_arrPtrSubElements);
};

//!Does Element Exist check by it's name
bool XMLElement::DoesSubElementExist(const std::string & strName)
{
	return DoesNodeExist<XMLElement>(m_arrPtrSubElements, strName);
};

//!Get the pointer to the first Element
XMLElement * XMLElement::FirstSubElement(void)
{
	return FirstNode<XMLElement>(m_arrPtrSubElements, m_intCurrElementIndex);
};

//!Get the pointer to the last Element
XMLElement * XMLElement::LastSubElement(void)
{
	return LastNode<XMLElement>(m_arrPtrSubElements, m_intCurrElementIndex);
};

//!Get the pointer to the next Element
XMLElement * XMLElement::NextSubElement(void)
{
	return NextNode<XMLElement>(m_arrPtrSubElements, m_intCurrElementIndex);
};

//!Get the pointer to the previous Element
XMLElement * XMLElement::PreviousSubElement(void)
{
	return PreviousNode<XMLElement>(m_arrPtrSubElements, m_intCurrElementIndex);
};

//!Get the pointer to the Element by it's name
XMLElement * XMLElement::GetSubElement(const std::string & strName)
{
	return GetNode<XMLElement>(m_arrPtrSubElements, strName);
};

//!Get the pointer to the Element by it's index
XMLElement * XMLElement::GetSubElement(size_t lngIndex)
{
	return GetNode<XMLElement>(m_arrPtrSubElements, lngIndex);
};

//!Get the pointer to the Element by it's index
XMLElement * XMLElement::AtSubElement(size_t lngIndex)
{
	return GetNode<XMLElement>(m_arrPtrSubElements, lngIndex);
};

//!Sets the root node flag
void XMLElement::Set_blnRootNode(bool blnIsRootNode)
{
	m_blnRootNode = blnIsRootNode;
	return;
};

//!Gets the root node flag value
bool XMLElement::Get_blnRootNode(void) const
{
	return m_blnRootNode;
};

//!Indicates whether or not this element is the root node
bool XMLElement::IsRootNode(void)
{
	return m_blnRootNode;
};

//!Sets the null node flag
void XMLElement::Set_blnNullNode(bool blnIsNullNode)
{
	m_blnNullNode = blnIsNullNode;
	return;
};

//!Gets the null node flag value
bool XMLElement::Get_blnNullNode(void) const
{
	return m_blnNullNode;
};

//!Indicates whether or not this element is the null node
bool XMLElement::IsNullNode(void)
{
	return m_blnNullNode;
};

//!Update the indexes
int XMLElement::UpdateIndexes(void)
{
	int i, intNumAttributes,j,intNumSubElements;
	intNumAttributes = m_arrPtrAttributes.size();
	if(m_blnRootNode)
	{
		Set_intLevel(0);
	}
	for(i = 0; i < intNumAttributes; i++)
	{
		m_arrPtrAttributes.at(i)->Set_intLevel(Get_intLevel());
		m_arrPtrAttributes.at(i)->Set_intRow(i);
	};
	intNumSubElements = m_arrPtrSubElements.size();
	for(j = 0; j < intNumSubElements;j++)
	{
		m_arrPtrSubElements.at(j)->Set_intLevel(Get_intLevel() + 1);
		m_arrPtrSubElements.at(j)->Set_intRow(j);
		m_arrPtrSubElements.at(j)->UpdateIndexes();
	};
	return 1;
};

//std::string XMLElement::Get_strValue(bool blnWithFormatting)
//{
//
//	return;
//};
