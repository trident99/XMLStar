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
#ifndef XMLNODE_H
#define XMLNODE_H

#include ".\XMLStructsEnums.h"


namespace XMLStar{

	class XMLSTAR_DLLAPI XMLNode
	{
	public:

		//PUBLIC CONSTRUCTORS & DESTRUCTOR/////////////////////////////
		XMLNode(void);
		XMLNode(XMLNode * ptrParentNode);
		XMLNode(XMLNode & rhs);
		virtual ~XMLNode(void);
		//PUBLIC OPERATOR OVERLOADS
		XMLNode & operator = (XMLNode & rhs);


		//PUBLIC MEMBER FUNCTIONS/////////////////////////////////////
		//!Set and Get for Node Type
		void Set_enumNodeType(XMLNodeType objNodeType);
		XMLNodeType Get_enumNodeType(void) const;

		//!Set and Get for Parent Node
		void Set_ptrParentNode(XMLNode * ptrParent);
		XMLNode *  Get_ptrParentNode(void) const;

		//!Set and Get for Parent Node
		void Set_objIndex(XMLNodeIndex objIndex);
		void Set_objIndex(int intLevel, int intRow, int intColumn);
		XMLNodeIndex Get_objIndex(void) const;

		//!Set and Get for Level
		void Set_intLevel(int intLevel);
		int Get_intLevel(void) const;

		//!Set and Get for Row 
		void Set_intRow(int intRow);
		int Get_intRow(void) const;

		//!Set and Get for Column
		void Set_intColumn(int intCol);
		int Get_intColumn(void) const;

		//!Set and Get for Node Name string
		void Set_strName(const std::string & strName);
		void Set_strName(const char * ptrCharString);
		std::string Get_strName(void) const;
		//string name equality testing function
		inline bool IsNameEqual(const std::string & strNameTest)
		{	
			size_t i,intLHS,intRHS;
			intLHS = m_strName.size();
			intRHS = strNameTest.size();
			if(intLHS != intRHS){return false;};//different number of characters
			if(intLHS < intRHS)
			{
				for(i = 0; i < intLHS; i++)
				{
					if(m_strName[i] != strNameTest[i]){return false;};
				};
			}else{
				for(i = 0; i < intRHS; i++)
				{
					if(m_strName[i] != strNameTest[i]){return false;};
				};
			};
			//made it all the way through found a match
			return true;
			//return (m_strName == strNameTest);
		};

		//While the base storage is a string (m_strValue)
		//The following conveinience Functions are added to facilitate base type inputs
		//From a best practice standpoint it is not recommended to store vectors as attributes.
		//Store Vectors, and Arrays as collections of elements

		void Set_enumValueType(XMLValueType enumType);
		XMLValueType Get_enumValueType(void) const;

		//!Set and Get for Node Value
		void Set_strValue(const std::string & strValue);
		void Set_strValue(const char * ptrCharString);
		void Set_strValue(bool blnVal);
		void Set_strValue(short shrtVal);
		void Set_strValue(unsigned short ushrtVal);
		void Set_strValue(int intVal);
		void Set_strValue(unsigned int uint);
		void Set_strValue(long lngVal);
		void Set_strValue(unsigned long ulngVal);
		void Set_strValue(float sngVal);
		void Set_strValue(double dblVal);
		void Set_strValue(char chrVal);
		void Set_strValue(unsigned char uchrVal);


		std::string Get_strValue(void);
		void Get_strValue(bool & blnValReturn);
		void Get_strValue(short & shrtValReturn);
		void Get_strValue(unsigned short & ushrtValReturn);
		void Get_strValue(int & intValReturn);
		void Get_strValue(unsigned int & uintValReturn);
		void Get_strValue(long & lngValReturn);
		void Get_strValue(unsigned long & ulngValReturn);
		void Get_strValue(float & sngValReturn);
		void Get_strValue(double & dblValReturn);
		void Get_strValue(char & chrValReturn);
		void Get_strValue(unsigned char & uchrValReturn);
		void Get_strValue(std::string & strValReturn);
		void Get_strValueDecode(std::string & strValReturn);

		//virtual std::string Get_strValue(bool blnWithFormatting){std::string strOut; return strOut;};
	protected:
		//!Encoding special characters to XML compatible format
		void EncodeSpecialChars(std::string & strToEncode);
		//!Decode special characters from XML compatible format;
		void DecodeSpecialChars(std::string & strToDecode);



		//!String value of the node(temporary storage only) Methods usually used for retrieval of value
		std::string m_strValue;
	private:
		//PRIVATE MEMBER VARIABLES///////////////////////////////////
		//!String representation of the node name
		std::string m_strName;
		//!enumerated node type used for recognition purposes
		XMLNodeType m_enumNodeType;
		//!enumerated value type for base element values
		XMLValueType m_enumValueType;
		//! pointer to the parent node
		XMLNode * m_ptrParentNode;
		//!index of the node
		XMLNodeIndex m_objIndex;

	};//end class XMLNode description


	//NODE COLLECTION ACCESSOR TEMPLATE FUNCTIONS//////////////////////
	//!Add an attribute to the element
	template<typename T /*= XMLNode*/>
	T * AddNode(std::vector<T*> & arrPtrNodeCollection, XMLNode * ptrParent)
	{
		try{
			T* ptrNewNode = new T(ptrParent);
			arrPtrNodeCollection.push_back(ptrNewNode);
			return ptrNewNode;
		}catch(...){
			return NULL;
		};
	};
	//!Add an attribute to the element
	template<typename T /*= XMLNode*/>
	int AddNode(std::vector<T*> & arrPtrNodeCollection, XMLNode * ptrParent, T * ptrObject)
	{
		try{
			if(ptrObject)
			{
				ptrObject->Set_ptrParentNode(ptrParent);
				arrPtrNodeCollection.push_back(ptrObject);
				return 1;
			}else{
				return 0;
			}
		}catch(...){
			return 0;
		};
	};
	//!Delete an attribute from the element by its name
	template<typename T /*= XMLNode*/>
	int DeleteNode(std::vector<T*> & arrPtrNodeCollection, const std::string & strName)
	{
		size_t i, intNumNodes;
		intNumNodes = arrPtrNodeCollection.size();
		if(intNumNodes <= 0)
		{//no attributes to search
			return 0;
		}
		try{
			for(i = 0; i < intNumNodes; i++)
			{
				if(arrPtrNodeCollection.at(i)->IsNameEqual(strName))
				{//then match found, delete it
					delete arrPtrNodeCollection.at(i);
					arrPtrNodeCollection.erase(arrPtrNodeCollection.begin() + i);
					//successful deletion
					return 1;
				};
			};//end for loop through attributes
			//no match found return NULL
			return 0;
		}catch(...){
			return -1;
		};
	};
	//!Delete an attribute from the element by its index
	template<typename T /*= XMLNode*/>
	int DeleteNode(std::vector<T*> & arrPtrNodeCollection, size_t lngIndex)
	{
		size_t intNumNodes;
		std::string strCurrTagName;
		intNumNodes = arrPtrNodeCollection.size();
		if(intNumNodes <= 0)
		{//no attributes to search
			return 0;
		};
		try{
			if((lngIndex >= 0)&&(lngIndex < intNumNodes))
			{
				delete arrPtrNodeCollection.at(lngIndex);
				arrPtrNodeCollection.erase(arrPtrNodeCollection.begin() + lngIndex);
				//successful deletion
				return 1;
			};
			//nothing done
			return 0;
		}catch(...){
			return -1;
		};
	};
	//!Delete All of the Element's sub-Elements
	template<typename T /*= XMLNode*/>
	int DeleteAllNodes(std::vector<T*> & arrPtrNodeCollection)
	{
		size_t i, intNumNodes;
		std::string strCurrTagName;
		intNumNodes = arrPtrNodeCollection.size();
		if(intNumNodes <= 0)
		{//no attributes to search
			return 0;
		}
		try{
			for(i = 0; i < intNumNodes; i++)
			{
				delete arrPtrNodeCollection.at(i);
			};//end for loop through attributes	
			arrPtrNodeCollection.clear();
			//successful deletion of all elements
			return 1;
		}catch(...){
			return -1;
		};
	};
	//!Sort the collection of Elements Alphabetically
	//Need this sort function isolated with precompiler #ifndef statement so it only gets referenced once
	template<typename T /*= XMLNode*/>
	bool SortNodesAscending(T * ptrA,T * ptrB)
	{
		//T HAS TO INHERIT OR BE A XMLNode!!!!!!!!!!!!!!!!!!!!!!!
		std::string strNameA, strNameB;
		std::string::iterator iterA, iterB;
		strNameA = ptrA->Get_strName();
		strNameB = ptrB->Get_strName();
		//scan through the two strings and sort them alphabetically characterwise
		for( iterA = strNameA.begin(), iterB = strNameB.begin();( (iterA != strNameA.end()) && (iterB != strNameB.end()) ); ++iterA, ++iterB )
		{
			if( tolower( *iterA ) < tolower( *iterB ) )
				return true;
			else if( tolower( *iterA ) > tolower( *iterB ) )
				return false;
		};
		if( strNameA.size() < strNameB.size() )
		{
			return true;
		}else{
			return false;
		};
	};

	template<typename T /*= XMLNode*/>
	int SortNodes(std::vector<T*> & arrPtrNodeCollection)
	{
		try{
			std::sort(arrPtrNodeCollection.begin(),arrPtrNodeCollection.end(),SortNodesAscending<T>);
			return 1;
		}catch(...){
			return -1;
		};
	};
	//!Size of the Element collection
	template<class T /*= XMLNode*/>
	long CountNodes(std::vector<T*> & arrPtrNodeCollection)
	{
		return arrPtrNodeCollection.size();
	};
	//!Boolean check to see if attribute collection is empty
	template<typename T /*= XMLNode*/>
	bool HasNodes(std::vector<T*> & arrPtrNodeCollection)
	{
		size_t intNumNodes;
		std::string strCurrTagName;
		intNumNodes = arrPtrNodeCollection.size();
		if(intNumNodes > 0)
		{
			//has attributes
			return true;
		}else{
			//does not have attributes
			return false;
		};
	};
	//!Does Element Exist check by it's name
	template<typename T /*= XMLNode*/>
	bool DoesNodeExist(std::vector<T*> & arrPtrNodeCollection,const std::string & strName)
	{
		size_t i, intNumNodes;
		intNumNodes = arrPtrNodeCollection.size();
		if(intNumNodes <= 0)
		{//no attributes to search
			return false;
		}
		try{
			for(i = 0; i < intNumNodes; i++)
			{
				if(arrPtrNodeCollection.at(i)->IsNameEqual(strName))
				{//then match found, delete it
					return true;
				};
			};//end for loop through attributes
			//no match found return NULL
			return false;
		}catch(...){
			return false;
		};
	};
	//!Get the pointer to the first Element
	template<typename T /*= XMLNode*/>
	T * FirstNode(std::vector<T*> & arrPtrNodeCollection, size_t & lngCurrIndex)
	{
		size_t intNumNodes;
		std::string strCurrTagName;
		intNumNodes = arrPtrNodeCollection.size();
		if(intNumNodes <= 0)
		{//no attributes to search
			lngCurrIndex = -1;
			return NULL;
		};
		//has attributes return the first one
		lngCurrIndex = 0;
		return arrPtrNodeCollection.front();
	};
	//!Get the pointer to the last Element
	template<typename T /*= XMLNode*/>
	T * LastNode(std::vector<T*> & arrPtrNodeCollection, size_t & lngCurrIndex)
	{
		size_t intNumNodes;
		std::string strCurrTagName;
		intNumNodes = arrPtrNodeCollection.size();
		if(intNumNodes <= 0)
		{//no attributes to search
			lngCurrIndex = -1;
			return NULL;
		};
		//has attributes return the first one
		lngCurrIndex = arrPtrNodeCollection.size() - 1;
		return arrPtrNodeCollection.back();
	};
	//!Get the pointer to the next Element
	template<typename T /*= XMLNode*/>
	T * NextNode(std::vector<T*> & arrPtrNodeCollection, size_t & lngCurrIndex)
	{
		size_t intNumNodes;
		std::string strCurrTagName;
		intNumNodes = arrPtrNodeCollection.size();
		if(intNumNodes <= 0)
		{//no attributes to search
			return false;
		};
		//if the current attribute has not been set yet go the first,
		//otherwise go to the next,
		//if end of vector reached return NULL
		try{
			if(lngCurrIndex < 0)
			{
				//then hasn't been set wyet
				lngCurrIndex = 0;
				return arrPtrNodeCollection.front();
			}else if(lngCurrIndex >= intNumNodes){
				//then at the end of the vector, there is no next, reset to zero and return NULL
				lngCurrIndex = 0;
				return NULL;
			}else{
				//legal index in vector increment it
				++lngCurrIndex;
				//check for legal new index
				if((lngCurrIndex >= 0)&&(lngCurrIndex<intNumNodes))
				{
					return arrPtrNodeCollection.at(lngCurrIndex);
				}else{
					//not a legal index quit gracefully;
					lngCurrIndex = 0;
					return NULL;
				};
			};
		}catch(...){
			return NULL;
		};

	};
	//!Get the pointer to the previous Element
	template<typename T /*= XMLNode*/>
	T * PreviousNode(std::vector<T*> & arrPtrNodeCollection, size_t & lngCurrIndex)
	{
		size_t intNumNodes;
		std::string strCurrTagName;
		intNumNodes = arrPtrNodeCollection.size();
		if(intNumNodes <= 0)
		{//no attributes to search
			return false;
		};
		//if the current attribute has not been set yet go the first,
		//otherwise go to the next,
		//if end of vector reached return NULL
		try{
			if(lngCurrIndex < 0)
			{
				//then hasn't been set wyet
				lngCurrIndex = 0;
				return arrPtrNodeCollection.front();
			}else if(lngCurrIndex >= intNumNodes){
				//then at the end of the vector, there is no next, reset to zero and return NULL
				lngCurrIndex = 0;
				return NULL;
			}else{
				//legal index in vector increment it
				--lngCurrIndex;
				//check for legal new index
				if((lngCurrIndex >= 0)&&(lngCurrIndex<intNumNodes))
				{
					return arrPtrNodeCollection.at(lngCurrIndex);
				}else{
					//not a legal index quit gracefully;
					lngCurrIndex = 0;
					return NULL;
				};
			};
		}catch(...){
			return NULL;
		};
	};
	//!Get the pointer to the Element by it's name
	template<typename T /*= XMLNode*/>
	T * GetNode(std::vector<T*> & arrPtrNodeCollection, const std::string & strName)
	{
		size_t i, intNumNodes;

		intNumNodes = arrPtrNodeCollection.size();
		if(intNumNodes <= 0)
		{//no attributes to search
			return NULL;
		}
		try{
			for(i = 0; i < intNumNodes; i++)
			{
				if(arrPtrNodeCollection.at(i)->IsNameEqual(strName))
				{//then match found, delete it
					return arrPtrNodeCollection.at(i);
				};
			};//end for loop through attributes
			//no match found return NULL
			return NULL;
		}catch(...){
			return NULL;
		};
	};
	//!Get the pointer to the Element by it's index
	template<typename T /*= XMLNode*/>
	T * GetNode(std::vector<T*> & arrPtrNodeCollection, size_t lngIndex)
	{
		size_t intNumNodes;
		std::string strCurrTagName;
		intNumNodes = arrPtrNodeCollection.size();
		if(intNumNodes <= 0)
		{//no attributes to search
			return 0;
		};
		try{
			if((lngIndex >= 0)&&(lngIndex < intNumNodes))
			{
				//valid index
				return arrPtrNodeCollection.at(lngIndex);
			};
			//nothing done
			return NULL;
		}catch(...){
			return NULL;
		};
	};



};//end namespace XMLLite
#endif
