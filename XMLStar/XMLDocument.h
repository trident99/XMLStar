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
#ifndef XMLDOCUMENT_H
#define XMLDOCUMENT_H

#include ".\XMLElement.h"

namespace XMLStar{

	class XMLSTAR_DLLAPI XMLDocument : 
		public XMLElement
		{
		public:

			//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
			XMLDocument(void);
			XMLDocument(XMLNode * ptrParentNode);
			XMLDocument(XMLDocument & rhs);
			virtual ~XMLDocument(void);
			//PUBLIC OPERATOR OVERLOADS
			XMLDocument & operator = (XMLDocument & rhs);

			//Set and Get for Include Prologue
			void Set_blnIncludePrologue(bool blnIncludePrologue);
			bool Get_blnIncludePrologue(void) const;
			//Set and Get for Document XML Version Number
			void Set_strVersion(std::string strVersion);
			std::string Get_strVersion(void) const;
			//Set and Get for Document Encoding 
			void Set_strEncoding(std::string strEncoding);
			std::string Get_strEncoding(void) const;
			//Set and Get for Include Standalone
			void Set_blnStandalone(bool blnStandalone);
			bool Get_blnStandalone(void) const;
			//Set and Get for Include Document Type Statement
			void Set_blnIncludeDocType(bool m_blnIncludeDocType);
			bool Get_blnIncludeDocType(void) const;
			//Set and Get for Document Type Statement 
			void Set_strDocType(std::string strDocType);
			std::string Get_strDocType(void) const;

		private:
			//!XML Document Prolog Properties included in output
			bool m_blnIncludePrologue;
			//!XML Prolog string version number for the 
			std::string m_strVersion;
			//!XML Prolog string encoding format for the 
			std::string m_strEncoding;
			//!XML Prolog standalone mode
			std::string m_strStandalone;
			//!XML Document Type Format Tag included in output
			bool m_blnIncludeDocType;
			//!XML Document Type Format Tag 
			std::string m_strDocType;

		};//end XMLDocument class definition

};//end XMLStar Namespace
#endif