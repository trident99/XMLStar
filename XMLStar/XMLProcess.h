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
#ifndef XMLPROCESS_H
#define XMLPROCESS_H

#include ".\XMLNode.h"
#include ".\XMLAttribute.h"

namespace XMLStar{

	class XMLSTAR_DLLAPI XMLProcess : 
		public XMLNode
		{
		public:

			//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
			XMLProcess(void);
			XMLProcess(XMLNode * ptrParentNode);
			XMLProcess(XMLProcess & rhs);
			virtual ~XMLProcess(void);
			//PUBLIC OPERATOR OVERLOADS
			XMLProcess & operator = (XMLProcess & rhs);

			void Clear(void);
			//ATTRIBUTE COLLECTION ACCESSOR FUNCTIONS/////////////////////
			//!Add an attribute to the element
			XMLAttribute * AddAttribute(void);
			//!Add an attribute to the element
			int AddAttribute(XMLAttribute * ptrAttrib);
			//!Delete an attribute from the element by its name
			int DeleteAttribute(std::string strName);
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
			bool DoesAttributeExist(std::string strName);
			//!Get the pointer to the first Attribute
			XMLAttribute * FirstAttribute(void);
			//!Get the pointer to the last Attribute
			XMLAttribute * LastAttribute(void);
			//!Get the pointer to the next Attribute
			XMLAttribute * NextAttribute(void);
			//!Get the pointer to the previous Attribute
			XMLAttribute * PreviousAttribute(void);
			//!Get the pointer to the Attribute by it's name
			XMLAttribute * GetAttribute(std::string strName);
			//!Get the pointer to the Attribute by it's index
			XMLAttribute * GetAttribute(size_t lngIndex);		
		protected:
			//!The vector collection of the attributes for this element
			std::vector<XMLAttribute* > m_arrPtrAttributes;
			//pointer to the currently selected Attribute
			size_t m_intCurrAttributeIndex;
		};//end class XMLProcess;

};//end namespace XMLStar
#endif //XMLPROCESS_H