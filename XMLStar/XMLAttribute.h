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
#ifndef XMLATTRIBUTE_H
#define XMLATTRIBUTE_H

#include ".\XMLNode.h"

namespace XMLStar{

	class XMLSTAR_DLLAPI XMLAttribute : 
		public XMLNode
		{
		public:

			//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
			XMLAttribute(void);
			XMLAttribute(XMLNode * ptrParentNode);
			XMLAttribute(XMLAttribute & rhs);
			virtual ~XMLAttribute(void);
			//PUBLIC OPERATOR OVERLOADS
			XMLAttribute & operator = (XMLAttribute & rhs);
			
		private:

		};//end class XMLAttribute;

};//end namespace XMLStar
#endif //XMLATTRIBUTE_H