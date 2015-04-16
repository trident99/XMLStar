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
#ifndef XMLREADER_H
#define XMLREADER_H

#include ".\XMLStructsEnums.h"

using namespace std;
namespace XMLStar{

	class XMLElement;
	class XMLAttribute;
	class XMLComment;
	class XMLProcess;

	class XMLSTAR_DLLAPI XMLReader : 
		public string
	{
	public:

		//!PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
		XMLReader(void);
		virtual ~XMLReader(void);
		//!PUBLIC OPERATOR OVERLOADS

		//XML SERIALIZATION AND DE-SERIALIZATION METHODS///////////
		//!Expand the XML string value of the element
		virtual int LoadXMLTree(XMLElement * ptrCurrTop, const std::string & strInput, XMLElementIndex & objCurrElementIndex);
		virtual int LoadXMLTree(XMLElement * ptrCurrTop, std::istream & strStreamInput);
		virtual int LoadXMLTree(XMLElement * ptrCurrTop, std::ifstream & strStreamInput);


		//!Load the XML Element based on the current starting location of the index
		int LoadXMLElement(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex);

	protected:
		//!Load the Tag to the Element Name
		int LoadOpenTag(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex, bool & blnNullElementReturn);
		//!Load the Tag to the Element Name
		int LoadCloseTag(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex);
		//!Load the Attributes into the Element
		int	LoadAttributes(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex);
		//!Load the Value into the Element
		int	LoadValue(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex);

		//!Load the Comments, Processes, and Sub Elements
		int	LoadSubNodes(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex);
		//!Load a Sub Element
		int	LoadSubElement(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex);

		//!Load the Comments into the Element
		int	LoadComment(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex);

		//!Load the Comments into the Element
		int	LoadProcess(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex);
		//!Load the Tag to the Element Name
		int LoadProcessOpenTag(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex);
		//!Load the Attributes into the Element
		int	LoadProcessAttributes(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex);
		//!Load the Value into the Element
		int	LoadProcessValue(XMLElement * ptrElement, const std::string & strInput, XMLElementIndex & objCurrElementIndex);
		
		//!Find Next < character indicating a start tag
		long FindNextTagStart(const std::string & strInput,size_t intStartPos, bool & blnCloseTag);
		//!Find Next Non-White Space Legal Character
		long FindNextNWSLChar(const std::string & strInput,size_t intStartPos); 
		//!Find Next Non-White Space Character
		long FindNextNWSChar(const std::string & strInput,size_t intStartPos);
		//!Find Next White Space Character
		long FindNextWSChar(const std::string & strInput,size_t intStartPos);
		//!Find Next Quotation " or '
		long FindNextQuote(const std::string & strInput,size_t intStartPos);
		//!Find Next Character
		long FindNextChar(const std::string & strInput,size_t intStartPos, char chrFind);

		bool IsNodeComment(const std::string & strInput,size_t intStartPos);
		bool IsNodeProcess(const std::string & strInput,size_t intStartPos);
		bool IsNodeElement(const std::string & strInput,size_t intStartPos);
		//!This Node removes the trailing whitespace and a rogue equal sign incase of error
		void CleanNameString(std::string & strName);

	private:		
	size_t m_intStringSize;
	
	XMLComment * m_ptrCurrComment;
	XMLProcess * m_ptrCurrProcess;
	};//end XMLWriter class definition

};//end namespace XMLStar
#endif