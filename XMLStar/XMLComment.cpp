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

#include ".\XMLComment.h"

using namespace XMLStar;

//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
XMLComment::XMLComment(void)
: XMLNode()
{
		//XMLNode Initialization/////////////
	Set_enumNodeType(COMMENT);
	return;
};

XMLComment::XMLComment(XMLNode * ptrParentNode)
: XMLNode(ptrParentNode)
{
		//XMLNode Initialization/////////////
	Set_enumNodeType(COMMENT);
	return;
};

XMLComment::XMLComment(XMLComment & rhs)
{
	//self assignment check
	if(this == &rhs)
		return;
	//XMLNode Copy Construction
	XMLNode::XMLNode(rhs);
	//XMLComment Copy Construction

	return;
};

XMLComment::~XMLComment(void)
{

};

//PUBLIC OPERATOR OVERLOADS
XMLComment & XMLComment::operator = (XMLComment & rhs)
{	
	//self assignment check
	if(this == &rhs)
		return *this;
	//XMLNode Assignment Operation
	XMLNode::operator = (rhs);
	//XMLComment Assignment Operation

	return *this;
};
//PUBLIC MEMBER FUNCTIONS/////////////////////////////////////