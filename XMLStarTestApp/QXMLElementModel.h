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


#ifndef QXMLELEMENTMODEL_H
#define QXMLELEMENTMODEL_H

#include <QAbstractItemModel>
#include ".\modLibraryRefs.h"
#include "XMLNode.h"
#include "XMLAttribute.h"
#include "XMLElement.h"
using namespace XMLStar;

class QXMLElementModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	QXMLElementModel(QObject * parent);
	~QXMLElementModel();

	void Set_ptrModelElement(XMLElement * ptrElement);
	XMLElement * Get_ptrModelElement(void);
	void Clear_ptrModelElement(void);

	//QT REQUIRED FUNCTIONS
	QVariant data( const QModelIndex &index, int role ) const;
	Qt::ItemFlags flags( const QModelIndex &index ) const;
	QVariant headerData( int section, Qt::Orientation orientation,
		int role = Qt::DisplayRole ) const;
	QModelIndex index( int row, int column,
		const QModelIndex &parent = QModelIndex() ) const;
	QModelIndex parent( const QModelIndex &index ) const;
	int rowCount( const QModelIndex &parent = QModelIndex() ) const;
	int columnCount( const QModelIndex &parent = QModelIndex() ) const;

	void UpdateModel(void);

signals:
	void XMLModelModified(void);

private:

	XMLElement * m_ptrRootElement;
	XMLElement * m_ptrModelElement;
};//end class definition QXMLElementModel

#endif // QXMLElementModel_H
