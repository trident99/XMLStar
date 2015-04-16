/*
**	This file is part of the XMLStar.
**	This software was developed by:
**	
**  Anthony Daniels, Mi Yan
**	The University of Michigan
**	Department of Naval Architecture & Marine Engineering
**	Department of Computer Science
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

#include ".\QXMLElementModel.h"
#include "XMLNode.h"
using namespace XMLStar;

QXMLElementModel::QXMLElementModel(QObject *parent)
	: QAbstractItemModel(parent)
{
	m_ptrRootElement = new XMLElement();
	std::string strTemp = "ROOT";
	m_ptrRootElement->Set_strName(strTemp);
}

QXMLElementModel::~QXMLElementModel()
{
	delete m_ptrRootElement;
	m_ptrRootElement = NULL;
}


void QXMLElementModel::Set_ptrModelElement(XMLElement * ptrElement)
{
	Clear_ptrModelElement();
	ptrElement->Set_ptrParentNode(m_ptrRootElement);
	this->m_ptrRootElement->AddSubElement(ptrElement);
	this->m_ptrRootElement->UpdateIndexes();
	this->reset();
};
XMLElement * QXMLElementModel::Get_ptrModelElement(void)
{
	if(m_ptrRootElement)
	{
		if(m_ptrRootElement->CountSubElements() > 0)
		{
			return m_ptrRootElement->GetSubElement(0);
		}else{
			NULL;
		};
	}else{
		return NULL;
	};
};
void QXMLElementModel::Clear_ptrModelElement(void)
{

	try{
		this->m_ptrRootElement->Clear();
	}catch(...){
		//continue
	}
	this->reset();

};

QVariant QXMLElementModel::data(const QModelIndex &index, int role) const
{
	try{
		if( !index.isValid() )
			return QVariant();

		if( role != Qt::DisplayRole )
			return QVariant();

		XMLElement *item = static_cast<XMLElement*>( index.internalPointer() );

		if(item)
		{
			if( index.column() == 0)
			{
				return item->Get_strName().c_str();
			}else if( index.column() == 1){
				return item->Get_strValue().c_str();
			}else if( index.column() == 2){
				XMLNodeType objType;
				objType = item->Get_enumNodeType();
				return XMLNodeType_ToString(objType).c_str();
			}else{
				return QVariant();
			};
		}else{
			return QVariant();
		}
	}catch(...){
		return QVariant();
	}
}

Qt::ItemFlags QXMLElementModel::flags( const QModelIndex &index ) const
{
    if( !index.isValid() )
        return 0;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant QXMLElementModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        if (section == 0) {
            return tr("Node Name");
		} else if (section == 1) {
			return tr("Value");
		} else if (section == 2) {
			return tr("Node Type");
		};
    }
    return QVariant();
}

QModelIndex QXMLElementModel::index(int row, int column, const QModelIndex &parent) const
{
	//this subroutine given the row and colum, and parent index by reference returns the QModelIndex for that childNode
	try
	{		
		XMLElement *parentItem = NULL;
		XMLElement *childItem = NULL;
	
		//OLD CODE FOR TESTING OUT TREEVIEW
		if( !hasIndex( row, column, parent ) )
			return QModelIndex();

		if( !parent.isValid() )
		{
			parentItem = m_ptrRootElement;
		}else{
			parentItem = static_cast<XMLElement*>( parent.internalPointer() );
		};

		childItem = parentItem->GetSubElement( row );

		if( childItem )
		{
			return createIndex( row, column, childItem );
		}else{
			return QModelIndex();
		};
	}catch(...){
        return QModelIndex();

	}
};

QModelIndex QXMLElementModel::parent(const QModelIndex &index) const
{
	try{   
		if( !index.isValid() )
			return QModelIndex();
		XMLElement *childItem = NULL;
		XMLElement *parentItem = NULL;
		childItem = static_cast<XMLElement*>( index.internalPointer() );
		if(childItem)
		{
			parentItem = (XMLElement*)childItem->Get_ptrParentNode();
		}else{
			return QModelIndex();
		};

		if((!parentItem)||(parentItem == m_ptrRootElement))
		{
			return QModelIndex();
		}else{
			//then valid parent item
			int intRowRequested = parentItem->Get_objIndex().m_intRow;
			int intLevel = parentItem->Get_objIndex().m_intLevel;
			return createIndex( intRowRequested, 0, parentItem );
		};
	}catch(...){
		//badd pointer for memory
		return QModelIndex();
	}

};

int QXMLElementModel::rowCount(const QModelIndex &parent) const
{
	int intCount = 0;
	try
	{
		XMLElement *parentItem = 0;
		if( parent.column() > 0 )
			return 0;

		if( !parent.isValid() )
		{
			parentItem = m_ptrRootElement;
		}else{
			parentItem = static_cast<XMLElement*>( parent.internalPointer() );
		}

		if(parentItem)
		{	//then valid node get the child count
			intCount = parentItem->CountSubElements();
			return intCount;
		}else{
			return 0;
		}
	}
	catch( ... )
	{
	}

    return intCount;
}

int QXMLElementModel::columnCount(const QModelIndex & parent) const
{
	return 2;
}

void QXMLElementModel::UpdateModel(void)
{
	//this->beginResetModel();
	this->m_ptrRootElement->UpdateIndexes();
	this->reset();
	//this->endResetModel();
};