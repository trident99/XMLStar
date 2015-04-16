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
#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include ".\XMLNode.h"
#include ".\XMLAttribute.h"
#include ".\XMLComment.h"
#include ".\XMLProcess.h"

namespace XMLStar{

	class XMLSTAR_DLLAPI XMLElement : 
		public XMLNode
		{
		public:

			//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
			XMLElement(void);
			XMLElement(XMLNode * ptrParentNode);
			XMLElement(XMLElement & rhs);
			virtual ~XMLElement(void);
			//PUBLIC OPERATOR OVERLOADS///////////////////////////////////
			XMLElement & operator = (XMLElement & rhs);

			void Clear(void);
			//ATTRIBUTE COLLECTION ACCESSOR FUNCTIONS/////////////////////
			//!Add an attribute to the element
			XMLAttribute * AddAttribute(void);
			//!Add an attribute to the element
			int AddAttribute(XMLAttribute * ptrAttrib);
			//!Delete an attribute from the element by its name
			int DeleteAttribute(const std::string & strName);
			//!Delete an attribute from the element by its index
			int DeleteAttribute(size_t lngIndex);
			//!Delete All of the Element's Attributes
			int DeleteAllAttributes(void);
			//!Sort the collection of Attributes Alphabetically
			int SortAttributes(void);
			//!Size of the Attribute collection
			long CountAttributes(void);
			//!Boolean check to see if attribute collection is empty
			bool HasAttributes(void);
			//!Does Attribute Exist check by it's name
			bool DoesAttributeExist(const std::string & strName);
			//!Get the pointer to the first Attribute
			XMLAttribute * FirstAttribute(void);
			//!Get the pointer to the last Attribute
			XMLAttribute * LastAttribute(void);
			//!Get the pointer to the next Attribute
			XMLAttribute * NextAttribute(void);
			//!Get the pointer to the previous Attribute
			XMLAttribute * PreviousAttribute(void);
			//!Get the pointer to the Attribute by it's name
			XMLAttribute * GetAttribute(const std::string & strName);
			//!Get the pointer to the Attribute by it's index
			XMLAttribute * GetAttribute(size_t lngIndex);
			//!Get the pointer to the Attribute by it's index
			XMLAttribute * AtAttribute(size_t lngIndex);

			//COMMENT COLLECTION ACCESSOR FUNCTIONS/////////////////////
			//!Add an Comment to the element
			XMLComment * AddComment(void);
			//!Add an Comment to the element
			int AddComment(XMLComment * ptrAttrib);
			//!Delete an Comment from the element by its name
			int DeleteComment(const std::string & strName);
			//!Delete an Comment from the element by its index
			int DeleteComment(size_t lngIndex);
			//!Delete All of the Element's Comments
			int DeleteAllComments(void);
			//!Sort the collection of Comments Alphabetically
			int SortComments(void);
			//!Size of the Comment collection
			long CountComments(void);
			//!Boolean check to see if Comment collection is empty
			bool HasComments(void);
			//!Does Comment Exist check by it's name
			bool DoesCommentExist(const std::string & strName);
			//!Get the pointer to the first Comment
			XMLComment * FirstComment(void);
			//!Get the pointer to the last Comment
			XMLComment * LastComment(void);
			//!Get the pointer to the next Comment
			XMLComment * NextComment(void);
			//!Get the pointer to the previous Comment
			XMLComment * PreviousComment(void);
			//!Get the pointer to the Comment by it's name
			XMLComment * GetComment(const std::string & strName);
			//!Get the pointer to the Comment by it's index
			XMLComment * GetComment(size_t lngIndex);
			//!Get the pointer to the Comment by it's index
			XMLComment * AtComment(size_t lngIndex);

			//COMMENT COLLECTION ACCESSOR FUNCTIONS/////////////////////
			//!Add an Process to the element
			XMLProcess * AddProcess(void);
			//!Add an Process to the element
			int AddProcess(XMLProcess * ptrAttrib);
			//!Delete an Process from the element by its name
			int DeleteProcess(const std::string & strName);
			//!Delete an Process from the element by its index
			int DeleteProcess(size_t lngIndex);
			//!Delete All of the Element's Processs
			int DeleteAllProcesses(void);
			//!Sort the collection of Processs Alphabetically
			int SortProcesses(void);
			//!Size of the Process collection
			long CountProcesses(void);
			//!Boolean check to see if Process collection is empty
			bool HasProcesses(void);
			//!Does Process Exist check by it's name
			bool DoesProcessExist(const std::string & strName);
			//!Get the pointer to the first Process
			XMLProcess * FirstProcess(void);
			//!Get the pointer to the last Process
			XMLProcess * LastProcess(void);
			//!Get the pointer to the next Process
			XMLProcess * NextProcess(void);
			//!Get the pointer to the previous Process
			XMLProcess * PreviousProcess(void);
			//!Get the pointer to the Process by it's name
			XMLProcess * GetProcess(const std::string & strName);
			//!Get the pointer to the Process by it's index
			XMLProcess * GetProcess(size_t lngIndex);
			//!Get the pointer to the Process by it's index
			XMLProcess * AtProcess(size_t lngIndex);

			//SUB-ELEMENT COLLECTION ACCESSOR FUNCTIONS//////////////////////
			//!Add an attribute to the element
			XMLElement *  AddSubElement(void);
			//!Add an attribute to the element
			int AddSubElement(XMLElement * ptrAttrib);
			//!Delete an attribute from the element by its name
			int DeleteSubElement(const std::string & strName);
			//!Delete an attribute from the element by its index
			int DeleteSubElement(size_t lngIndex);
			//!Delete All of the Element's sub-Elements
			int DeleteAllSubElements(void);
			//!Sort the collection of Elements Alphabetically
			int SortSubElements(void);
			//!Size of the Element collection
			long CountSubElements(void);
			//!Boolean check to see if attribute collection is empty
			bool HasSubElements(void);
			//!Does Element Exist check by it's name
			bool DoesSubElementExist(const std::string & strName);
			//!Get the pointer to the first Element
			XMLElement * FirstSubElement(void);
			//!Get the pointer to the last Element
			XMLElement * LastSubElement(void);
			//!Get the pointer to the next Element
			XMLElement * NextSubElement(void);
			//!Get the pointer to the previous Element
			XMLElement * PreviousSubElement(void);
			//!Get the pointer to the Element by it's name
			XMLElement * GetSubElement(const std::string & strName);
			//!Get the pointer to the Element by it's index
			XMLElement * GetSubElement(size_t lngIndex);
			//!Get the pointer to the Element by it's index
			XMLElement * AtSubElement(size_t lngIndex);


			//!Sets the root node flag
			void Set_blnRootNode(bool blnIsRootNode);
			//!Gets the root node flag value
			bool Get_blnRootNode(void) const;
			//!Indicates whether or not this element is the root node
			bool IsRootNode(void);

			//!Sets the null node flag
			void Set_blnNullNode(bool blnIsNullNode);
			//!Gets the null node flag value
			bool Get_blnNullNode(void) const;
			//!Indicates whether or not this element is the null node
			bool IsNullNode(void);

			//!Update the indexes
			int UpdateIndexes(void);
			//virtual std::string Get_strValue(bool blnWithFormatting);

		protected:
			//!The vector collection of the attributes for this element
			std::vector<XMLAttribute* > m_arrPtrAttributes;
			//!The vector collection of the comments for this element
			std::vector<XMLComment* > m_arrPtrComments;
			//!The vector collection of the attributes for this element
			std::vector<XMLProcess* > m_arrPtrProcesses;
			//!The vector collection of sub elements for this element
			std::vector<XMLElement* > m_arrPtrSubElements;

			//!boolean flag for indicating that this element is the root node element, used for auto indexing
			bool m_blnRootNode;
			//!boolean flag for indicating if it a null node
			bool m_blnNullNode;

			private:
			//pointer to the currently selected Attribute
			size_t m_intCurrAttributeIndex;
			//pointer to the currently selected Comment
			size_t m_intCurrCommentIndex;
			//pointer to the currently selected Process
			size_t m_intCurrProcessIndex;
			//pointer to the currently selected element
			size_t m_intCurrElementIndex;

		};//end class XMLElement;

		//TEMPLATE FUNCTION DEFINITIONS







};//end namespace XMLStar
#endif