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

#include ".\QXMLCommentModel.h"
#include "XMLNode.h"
using namespace XMLStar;

QXMLCommentModel::QXMLCommentModel(QObject *parent)
	: QAbstractItemModel(parent)
{
	m_ptrElement = NULL;
}

QXMLCommentModel::~QXMLCommentModel()
{
	m_ptrElement = NULL;
}


void QXMLCommentModel::Set_ptrElement(XMLElement * ptrElement)
{
	Clear_ptrElement();
	//ptrElement->Set_ptrParentNode(m_ptrRootElement);
	if(ptrElement)
	{
		m_ptrElement = ptrElement;
	};
	this->reset();
};
XMLElement * QXMLCommentModel::Get_ptrElement(void)
{
	if(m_ptrElement)
	{
		return m_ptrElement;
	}else{
		return NULL;
	};
};
void QXMLCommentModel::Clear_ptrElement(void)
{

	try{
		m_ptrElement = NULL;
	}catch(...){
		//continue
	}
	this->reset();

};
QModelIndex QXMLCommentModel::index(int row, int column, const QModelIndex &parent) const
{
	//this subroutine given the row and colum, and parent index by reference returns the QModelIndex for that childNode
	try
	{
		if( !hasIndex( row, column, parent ) )
		{
			return QModelIndex();

		}else{
			if(m_ptrElement)
			{
				XMLNode *childItem = this->m_ptrElement->GetComment( row );
				if( childItem )
				{
					return createIndex( row, column, childItem );
				}else{
					return QModelIndex();
				}
			}else{
				return QModelIndex();
			};
		}
	}catch(...){
        return QModelIndex();

	}
}

QModelIndex QXMLCommentModel::parent(const QModelIndex &index) const
{
	try{   
		if( !index.isValid() )
			return QModelIndex();

			return QModelIndex();
	}catch(...){
		//badd pointer for memory
		return QModelIndex();
	}

}

int QXMLCommentModel::rowCount(const QModelIndex &parent) const
{
	int intCount = 0;
	try
	{
		if( !parent.isValid() )
		{
			if(m_ptrElement)
			{
			//we are in the root node, get the vector size
			intCount = this->m_ptrElement->CountComments();
			}else{
				intCount = 0;
			};
		}else{
			intCount = 0;
		};
		return intCount;
	}catch( ... ){
	};

    return intCount;
}

int QXMLCommentModel::columnCount(const QModelIndex & /* parent */) const
{
    return 3;
}

QVariant QXMLCommentModel::data(const QModelIndex &index, int role) const
{
	try{
		if( !index.isValid() )
			return QVariant();

		if( role != Qt::DisplayRole )
			return QVariant();

		XMLNode *item = static_cast<XMLNode*>( index.internalPointer() );

		if( index.column() == 0)
		{
			return item->Get_strName().c_str();
		}else if( index.column() == 1){
			return item->Get_strValue().c_str();
		}else{
			return QVariant();
		};

	}catch(...){
		return QVariant();
	}
}

Qt::ItemFlags QXMLCommentModel::flags( const QModelIndex &index ) const
{
    if( !index.isValid() )
        return 0;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant QXMLCommentModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        if (section == 0) {
            return tr("Comment Name");
        } else if (section == 1) {
            return tr("Value");
		}
    }
    return QVariant();
}

void QXMLCommentModel::UpdateModel(void)
{
	this->reset();
};