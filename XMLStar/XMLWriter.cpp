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

#include ".\XMLWriter.h"
#include ".\XMLElement.h"
#include ".\XMLAttribute.h"
#include ".\XMLComment.h"
#include ".\XMLProcess.h"

using namespace XMLStar;

//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
XMLWriter::XMLWriter(void)
{
	m_intNumIndentSpaces = 3;
	return;
};

XMLWriter::~XMLWriter(void)
{
	return;
};


//Set pointer to the element
void XMLWriter::Set_ptrElement(XMLElement * ptrElement)
{
	if(ptrElement)
	{
		m_ptrElement = ptrElement;
	}else{
		m_ptrElement = NULL;
	};
};
//Get the pointer to the element
XMLElement * XMLWriter::Get_ptrElement(void)
{
	return m_ptrElement;
};

//!Sets the number of indent spaces per level
void XMLWriter::Set_intNumIndentSpaces(unsigned int intNumIndentSpaces)
{
	if(intNumIndentSpaces > 10)
	{
		//maximum of 10 space indent
		m_intNumIndentSpaces = 10;
	}else{
		m_intNumIndentSpaces = intNumIndentSpaces;
	};
	return;
};
//!Gets the number of indent spaces per level
unsigned int XMLWriter::Get_intNumIndentSpaces(void)
{
	return m_intNumIndentSpaces;
};

//!Update the indexes
int XMLWriter::UpdateIndexes(XMLElement * ptrCurrTop)
{
	int i, intNumAttributes,j,intNumSubElements;
	intNumAttributes = ptrCurrTop->CountAttributes();

	ptrCurrTop->Set_intLevel(0);

	for(i = 0; i < intNumAttributes; i++)
	{
		ptrCurrTop->GetAttribute(i)->Set_intLevel(ptrCurrTop->Get_intLevel());
		ptrCurrTop->GetAttribute(i)->Set_intRow(i);
	};
	intNumSubElements = ptrCurrTop->CountSubElements();
	for(j = 0; j < intNumSubElements;j++)
	{
		ptrCurrTop->GetSubElement(j)->Set_intLevel(ptrCurrTop->Get_intLevel() + 1);
		ptrCurrTop->GetSubElement(j)->Set_intRow(j);
		ptrCurrTop->GetSubElement(j)->UpdateIndexes();
	};
	return 1;
};

int XMLWriter::SaveXMLTree(XMLElement * ptrCurrTop,std::string & strOutput,bool blnWithFormatting)
{
	int intReturn = 0;
	//hand it off to the XMLWriter
	this->UpdateIndexes(ptrCurrTop);
	intReturn = this->SaveXMLElement(ptrCurrTop, strOutput, blnWithFormatting);
	return intReturn;
};

int XMLWriter::SaveXMLTree(XMLElement * ptrCurrTop, std::ostream & strStreamOut,bool blnWithFormatting)
{
	int intReturn = 0;
	//hand it off to the XMLWriter
	std::string strFileOutPut;

	intReturn = SaveXMLTree(ptrCurrTop, strFileOutPut, blnWithFormatting);
	strStreamOut << strFileOutPut;
	return NULL;
};

int XMLWriter::SaveXMLTree(XMLElement * ptrCurrTop, std::ofstream & strStreamOut,bool blnWithFormatting)
{
	int intReturn = 0;
	//hand it off to the XMLWriter
	std::string strFileOutPut;

	intReturn = SaveXMLTree(ptrCurrTop, strFileOutPut, blnWithFormatting);
	strStreamOut << strFileOutPut;
	return NULL;
};


//!Save the XML Element based with or without formatting
int XMLWriter::SaveXMLElement(XMLElement * ptrElement, std::string & strOutput, bool blnWithFormatting)
{	
	/*
	//SAVE ELEMENT
	START THE OPENTAG
	SERIALIZE THE ATTRIBUTES INTO THE OPEN TAG
	CLOSE THE OPEN TAG
	WRITE THE VALUE
	WRITE THE COMMENTS
	WRITE THE PROCESSES
	WRITE THE SUB ELEMENTS
	WRITE THE CLOSE TAG
	*/
	int i,intNumAttributes,intNumComments,intNumProcesses,intNumSubElements;
	int intTemp, intReturn;
	bool blnNullNode = false;
	bool blnRootNode = false;
	bool blnInline = false;
	intReturn = 1;
	blnRootNode = ptrElement->IsRootNode();
	blnNullNode = ptrElement->IsNullNode();
	intNumAttributes = ptrElement->CountAttributes();
	intNumComments = ptrElement->CountComments();
	intNumProcesses = ptrElement->CountProcesses();
	intNumSubElements = ptrElement->CountSubElements();
	if((intNumComments <= 0)&&(intNumProcesses <= 0)&&(intNumSubElements <= 0))
	{
		//then treat as an inline XMLElement
		blnInline = true;
	};
	//if the element is the root node, and an xml processing statement is present, then write that first.
	if((ptrElement->Get_blnRootNode() == true)&&(intNumProcesses > 0))
	{
		//write a carriage return if necessary for formatting
		for(i = 0; i < intNumProcesses;i++)
		{
			intTemp = WriteProcess(ptrElement->GetProcess(i),strOutput,blnWithFormatting);
			if(intTemp < 0){intReturn = -1;};
		};
		//write a carriage return if necessary for formatting
		if(blnWithFormatting){strOutput += '\n';};
	};

	//START THE OPENTAG///////////////////////////////////////////////
	intTemp = WriteOpenTag(ptrElement,strOutput,blnWithFormatting);
	if(intTemp < 0){intReturn = -1;};

	if(blnNullNode)
	{
		return 1;
	};

	if(blnInline)
	{
		//then treat as an inline XML Element
		intTemp = WriteValue(ptrElement,strOutput,false);
		if(intTemp < 0){intReturn = -1;};
		//write the close tag inline
		intTemp = WriteCloseTag(ptrElement,strOutput,false);
		if(intTemp < 0){intReturn = -1;};
		return intReturn;
	}else{
		//WRITE THE VALUE////////////////////////////////////////////////
		intTemp = WriteValue(ptrElement,strOutput,blnWithFormatting);
		if(intTemp < 0){intReturn = -1;};
		//WRITE THE PROCESSES/////////////////////////////////////////////
		if((ptrElement->Get_blnRootNode() == false)&&(intNumProcesses > 0))
		{
			//write a carriage return if necessary for formatting
			for(i = 0; i < intNumProcesses;i++)
			{
				intTemp = WriteProcess(ptrElement->GetProcess(i),strOutput,blnWithFormatting);
				if(intTemp < 0){intReturn = -1;};
			};
		};
		//WRITE THE COMMENTS/////////////////////////////////////////////
		if(intNumComments > 0)
		{
			//write a carriage return if necessary for formatting
			for(i = 0; i < intNumComments;i++)
			{
				intTemp = WriteComment(ptrElement->GetComment(i),strOutput,blnWithFormatting);
				if(intTemp < 0){intReturn = -1;};
			};
		};
		//WRITE THE SUB ELEMENTS/////////////////////////////////////////////
		if(intNumSubElements > 0)
		{
			//write a carriage return if necessary for formatting
			for(i = 0; i < intNumSubElements;i++)
			{
				intTemp = SaveXMLElement(ptrElement->GetSubElement(i),strOutput, blnWithFormatting);
				if(intTemp < 0){intReturn = -1;};
			};
		};
		//WRITE THE CLOSE TAG 
		intTemp = WriteCloseTag(ptrElement,strOutput,blnWithFormatting);
		if(intTemp < 0){intReturn = -1;};
		return intReturn;
	};//end simple inline element check
	return intReturn;
};

void XMLWriter::WriteIndent(std::string & strOutput, unsigned int intLevel)
{
	unsigned int i, j;
	for(i = 0; i < intLevel;i++)
	{
		for(j = 0; j < m_intNumIndentSpaces; j++)
		{
			strOutput.append(" ");
		};
	};
	return;
};


//write the open tag including all attributes
int XMLWriter::WriteOpenTag(XMLElement * ptrElement, std::string & strOutput, bool blnWithFormatting)
{
	int i,intNumAttributes;
	bool blnNullNode = false;
	bool blnRootNode = false;
	blnRootNode = ptrElement->IsRootNode();
	blnNullNode = ptrElement->IsNullNode();
	intNumAttributes = ptrElement->CountAttributes();

	//if not the root node add a carriage return before starting the tag
	if((blnRootNode == false)&&(blnWithFormatting)){strOutput += '\n';};
	//write the open tag indent
	if(blnWithFormatting){WriteIndent(strOutput,ptrElement->Get_intLevel());};
	//write the open tag
	strOutput += '<';
	strOutput += ptrElement->Get_strName();
	//append the attributes
	if(intNumAttributes > 0)
	{
		for(i = 0; i < intNumAttributes;i++)
		{
			//write that attribute
			strOutput += ' ';
			strOutput += ptrElement->GetAttribute(i)->Get_strName();
			strOutput += " = ";
			strOutput += '\"';
			strOutput += ptrElement->GetAttribute(i)->Get_strValue();
			strOutput += '\"';
		};
	};
	if(blnNullNode){strOutput += '/';};
	//write the end open tag
	strOutput += '>';
	return 1;
};
//write the value for the element
int XMLWriter::WriteValue(XMLElement * ptrElement, std::string & strOutput, bool blnWithFormatting)
{
	std::string strTemp, strDecodedValue;
	strTemp = ptrElement->Get_strValue();
	bool blnIsAllWhiteSpace = IsAllWhiteSpace(strTemp);
	if( (blnIsAllWhiteSpace == false) && (strTemp.size() > 0) )
	{
		//write a carriage return if necessary for formatting
		if(blnWithFormatting){strOutput += '\n';};
		//write the open tag indent
		if(blnWithFormatting){WriteIndent(strOutput,ptrElement->Get_intLevel());};
		strOutput +=  ptrElement->Get_strValue();
	};
	return 1;
};
//write an individual comment
int XMLWriter::WriteComment(XMLComment * ptrComment, std::string & strOutput, bool blnWithFormatting)
{
	//write a carriage return if necessary for formatting
	std::string strValue;
	if(blnWithFormatting){strOutput += '\n';};
	//write the open tag indent
	if(blnWithFormatting){WriteIndent(strOutput,ptrComment->Get_intLevel());};
	strOutput += "<!--";
	strOutput += ptrComment->Get_strValue();
	strOutput += "-->";
	return 1;
};
//write an individual process
int XMLWriter::WriteProcess(XMLProcess * ptrProcess, std::string & strOutput, bool blnWithFormatting)
{
	//write a carriage return if necessary for formatting
	int i,intNumAttributes;
	std::string strDecodedValue;
	if(blnWithFormatting){strOutput += '\n';};

	intNumAttributes = ptrProcess->CountAttributes();
	//write the open tag indent
	if(blnWithFormatting){WriteIndent(strOutput,ptrProcess->Get_intLevel());};
	//write the open tag
	strOutput += "<?";
	strOutput += ptrProcess->Get_strName();
	//append the attributes
	if(intNumAttributes > 0)
	{
		for(i = 0; i < intNumAttributes;i++)
		{
			//write that attribute
			strOutput += " ";
			strOutput += ptrProcess->GetAttribute(i)->Get_strName();
			strOutput += " = ";
			strOutput += "\"";
			strOutput += ptrProcess->GetAttribute(i)->Get_strValue();
			strOutput += "\" ";
		};
		//now write the value
		std::string strTemp, strDecodedValue;
		strTemp = ptrProcess->Get_strValue();
		bool blnIsAllWhiteSpace = IsAllWhiteSpace(strTemp);
		if( (blnIsAllWhiteSpace == false) && (strTemp.size() > 0) )
		{
			//write a carriage return if necessary for formatting
			if(blnWithFormatting){strOutput += '\n';};
			//write the open tag indent
			if(blnWithFormatting){WriteIndent(strOutput,ptrProcess->Get_intLevel());};
			strOutput +=  ptrProcess->Get_strValue();
		};
	};
	//write the end open tag
	strOutput += "?>";
	return 1;
};
//write the node close tag
int XMLWriter::WriteCloseTag(XMLElement * ptrElement, std::string & strOutput, bool blnWithFormatting)
{
	//write a carriage return if necessary for formatting
	if(blnWithFormatting){strOutput += '\n';};
	//write the open tag indent
	if(blnWithFormatting){WriteIndent(strOutput,ptrElement->Get_intLevel());};
	//write the open tag
	strOutput += "</";
	strOutput += ptrElement->Get_strName();
	strOutput += '>';
	return 1;
};

//!checks to see if the string is all whitespace
bool XMLWriter::IsAllWhiteSpace(const std::string & strInput)
{
	bool blnNotWhiteSpace = false;
	size_t i, intNumChars;
	intNumChars = strInput.size();
	if(intNumChars > 0)
	{
		for(i = 0; i < intNumChars; i++)
		{
			if( (int)(strInput[i]) > 32)
			{
				//32 or less is the white space characters of ASCII
				return false;
			};
		};
		//made it all the way through with white space characters only
		return true;
	}else{
		//nothing in string, return as if whitespace
		return true;
	};
}; 
