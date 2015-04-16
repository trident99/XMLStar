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

#ifndef XMLStar_H
#define XMLStar_H
//This is an amalgamation includes file. 
//#include ".\XMLStar.h" will include the entire library

//sub class 0
#include ".\XMLStructsEnums.h"
#include ".\XMLReader.h"
#include ".\XMLWriter.h"
//sub class tier 1
#include ".\XMLNode.h"
//sub class tier 2
#include ".\XMLElement.h"
//sub class tier 3
#include ".\XMLAttribute.h"
#include ".\XMLComment.h"
#include ".\XMLProcess.h"
#include ".\XMLDocument.h"

namespace XMLStar{


};

#endif