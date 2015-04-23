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


#ifndef QXMLCOMMENTMODEL_H
#define QXMLCOMMENTMODEL_H

#include <QAbstractItemModel>
#include ".\modLibraryRefs.h"
using namespace XMLStar;

class QXMLCommentModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	QXMLCommentModel(QObject * parent);
	~QXMLCommentModel();

	void Set_ptrElement(XMLElement * ptrElement);
	XMLElement * Get_ptrElement(void);
	void Clear_ptrElement(void);

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

	XMLElement * m_ptrElement;
};//end class definition QXMLElementModel

#endif // QXMLCommentModel_H
